#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <Arduino.h>

#include "typewriter.h"

#define BAUD_PRESCALE(fcpu,br) ((fcpu / 16 / br) - 1)

#define LIMIT 64
#define LIMIT_LOW 8

/* 75 ms = 1172 * 64 us */
#define DELAY 1172
#define LONGDELAY (10 * DELAY)

typedef struct {
    uint8_t buff[256];
    uint8_t volatile head;
    uint8_t volatile tail;
} buffer;

buffer receive = {{0}, 0, 0};

uint8_t volatile is_on = 0;

void usart_init(uint32_t baudRate)
{
    UBRR0L = BAUD_PRESCALE(F_CPU, baudRate) & 0xFF;
    UBRR0H = BAUD_PRESCALE(F_CPU, baudRate) >> 8;
    UCSR0B = _BV(TXEN0) | _BV(RXEN0) | _BV(RXCIE0);
    UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

void send_byte(uint8_t ch)
{
    while (!(UCSR0A & _BV(UDRE0)));
    UDR0 = ch;
}

void xon()
{
    // send XON
    if (!is_on) {
        send_byte(0x11);
    }
    is_on = 1;
}

void xoff()
{
    // send XOFF
    if (is_on) {
        send_byte(0x13);
    }
    is_on = 0;
}

static void timer_stop()
{
    TCCR1B = 0x00;         /* stop timer clock */
    clr_bit(TIMSK1, TOIE1);     /* disable interrupt */
    set_bit(TIFR1, TOV1);       /* clear interrupt flag */
}

/* at 16MHz, 1 tick = 1s / fcpu * div = 1000000 / 16000000 * 1024 = 64 ms */
/* INTR in value * 64 ms */
static void timer_start(int value)
{
    cli(); /* no interrupt because TCNT1 is 16 bits = 2 cycles to write */
    clr_bit(TCCR1A, WGM10);
    clr_bit(TCCR1A, WGM11);
    set_bit(TIFR1, TOV1);
    TCNT1 =  0xFFFF - (value & 0xFFFF);    /* overflow in value * 64 us*/
    TIMSK1 = 0x01;         /* set the Timer Overflow Interrupt Enable bit */
    TCCR1B = 0x05;         /* prescaler: 1024 */
    sei();
}

ISR(TIMER1_OVF_vect)
{
    cli();
    timer_stop();
    Combi combi = SPACE;
    // if received since last call
    if (receive.head != receive.tail) {
        // get received char
        uint8_t ch = receive.buff[receive.tail++];
        // how many chars in buffer ?
        uint8_t delta = receive.head - receive.tail;
        // if low, send xon
        if (delta < LIMIT_LOW) {
            xon();
        }
        combi = mapping[ch];
        // send combi if mapped
        if (combi.input != -1) {
            key(combi);
        }
        // set delay for next call
        if (combi.mod & MOD_DELAY) {
            timer_start(LONGDELAY);
        } else {
            timer_start(DELAY);
        }
    }
    sei();
}

ISR(USART_RX_vect)
{
    cli();
    uint8_t ch = UDR0;
    receive.buff[receive.head++] = ch;
    uint8_t delta = receive.head - receive.tail;
    if (delta > LIMIT) {
        xoff();
    }
    sei();
}

void activate(Combi combi)
{
    int8_t readPin = input_pin[combi.input];
    int8_t writePin = output_pin[combi.output];

    /* wait LOW state */
    while (!(digitalRead(readPin) == LOW));

    digitalWrite(writePin, LOW);

    if (combi.mod & MOD_SHIFT && combi.input == SHIFT.input) {
        digitalWrite(shiftWritePin, LOW);
    }

    /* wait HIGH state */
    while (!(digitalRead(readPin) == HIGH));

    digitalWrite(writePin, HIGH);

    if (combi.mod & MOD_SHIFT && combi.input == SHIFT.input) {
        digitalWrite(shiftWritePin, HIGH);
    }
}

void key(Combi combi)
{
    if (combi.mod & MOD_ACUTE) {
        key(ACUTE);
    }
    if (combi.mod & MOD_AGRAVE) {
        key(AGRAVE);
    }
    if (combi.mod & MOD_CEDILLE) {
        key(CEDILLE);
        key(BACKSPACE);
    }
    if (combi.mod & MOD_ACIRC) {
        key(ACUTE);
        key(SPACE);
        key(BACKSPACE);
        key(AGRAVE);
    }
    if (combi.mod & MOD_KBD2) {
        key(KBD2);
    }

    for (int i = 0; i < 2; i++) {
        if (combi.mod & MOD_SHIFT) {
            activate(SHIFT);
        }
        if (combi.mod & MOD_CODE) {
            activate(CODE);
        }
        activate(combi);
    }

    if (combi.mod & MOD_KBD2) {
        key(KBD1);
    }
}

int main(void)
{
    usart_init(9600);

    for (int8_t i = 0; i < INPUT_NUM; i++) {
        pinMode(input_pin[i], INPUT_PULLUP);
    }
    for (int8_t i = 0; i < OUTPUT_NUM; i++) {
        pinMode(output_pin[i], OUTPUT);
    }

    pinMode(GROUND_PIN, OUTPUT);
    digitalWrite(GROUND_PIN, LOW);

    sei();
    timer_start(DELAY);
    xon();

    while(1) {
        sleep_mode();
    }
    return 0;
}
