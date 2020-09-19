#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include "binary.h"
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

void send_str(uint8_t str[])
{
    for (uint8_t* c = str; *c; c++) {
        send_byte(*c);
    }
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
    TCCR1B = B00000000;         /* stop timer clock */
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
    TIMSK1 = B00000001;         /* set the Timer Overflow Interrupt Enable bit */
    TCCR1B = B00000101;         /* prescaler: 1024 */
    sei();
}

ISR(TIMER1_OVF_vect)
{
    cli();
    timer_stop();
    Combi combi = SPACE;
    if (receive.head != receive.tail) {
        uint8_t ch = receive.buff[receive.tail++];
        uint8_t delta = receive.head - receive.tail;
        if (delta < LIMIT_LOW) {
            xon();
        }
        combi = mapping[ch];
        if (combi.input != -1) {
            key(combi);
        }
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
    int8_t readPin = get_pin_input(combi.input);
    int8_t writePin = get_pin_output(combi.output);

//    /* wait LOW state */
//    while (!(digitalRead(readPin) == LOW));
//
//    digitalWrite(writePin, LOW);
//
//    if (combi.mod & MOD_SHIFT && combi.input == SHIFT.input) {
//        digitalWrite(shiftWritePin, LOW);
//    }
//
//    /* wait HIGH state */
//    while (!(digitalRead(readPin) == HIGH));
//
//    digitalWrite(writePin, HIGH);
//
//    if (combi.mod & MOD_SHIFT && combi.input == SHIFT.input) {
//        digitalWrite(shiftWritePin, HIGH);
//    }
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
    if (combi.mod & MOD_DELAY) {
        /* let it breathe */
//        delay(1000);
    } else {
//        delay(75);
    }
}

void write_char(uint8_t c)
{
    // if c is mapped,V call key
    if (mapping[c].input != -1)
        key(mapping[c]);
}

//void setup()
//{
//    //Start serial connection
//    Serial.begin(9600);
//
//    //Configure pins
//    for (int8_t i = 0; i < 10; i++) {
//        pinMode(get_pin_input(i), INPUT_PULLUP);
//    }
//    for (int8_t i = 0; i < 10; i++) {
//        if (i == 4 || i == 5) {
//            continue;
//        }
//        pinMode(get_pin_output(i), OUTPUT);
//        digitalWrite(get_pin_output(i), HIGH);
//    }
//    // Row 4 is GND
//    pinMode(get_pin_output(4), OUTPUT);
//    digitalWrite(get_pin_output(4), LOW);
//
//    Serial.print('.');
//}
//
//// line buffer
//const unsigned int8_t numChars = 72;
//unsigned int8_t receivedChars[numChars + 1];
//unsigned int8_t ndx = 0;
//
//void loop()
//{
//    unsigned int8_t rc;
//    if(Serial.available()) {
//        rc = Serial.read();
//        // line feed received : send the line to typewriter
//        if (rc == '\r' || rc == '\n') {
//            receivedChars[ndx] = '\0';  // terminate the string
//            // send the line character by character
//            for (unsigned int8_t *p = receivedChars; *p != 0; p++) {
//                write_character(*p);
//            }
//            // carriage return
//            write_character('\r');
//            // allow client to send next line
//            Serial.print('.');
//            // reinit buffer index
//            ndx = 0;
//        } else {
//            // chars after numChars are lost
//            if (ndx < numChars) {
//                receivedChars[ndx] = rc;
//                ndx++;
//            }
//        }
//    }
//}

int main(void)
{
    usart_init(9600);
    timer_start(DELAY);

    /* set pin 5 low to turn led off */
    DDRB |= _BV(DDB5);
    PORTB &= ~_BV(PORTB5);

    sei();
    xon();

    while(1) {
        sleep_mode();
    }
    return 0;
}
