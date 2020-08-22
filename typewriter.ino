#include "typewriter.h"

void activate(Combi combi)
{
    char readPin = get_pin_input(combi.input);
    char writePin = get_pin_output(combi.output);

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
    if (combi.mod & MOD_DELAY) {
        /* let it breathe */
        delay(1000);
    } else {
        delay(75);
    }
}

void write_character(unsigned char c)
{
    /* We assume the character is latin-1 encoded */
    unsigned char i;
    /* loop until sentinel */
    for (i = 0; mapping[i].latin1; i++) {
        if (mapping[i].latin1 == c) {
            break;
        }
    }
    if (mapping[i].latin1) {
        key(mapping[i].combi);
    } else {
        /* Default to space */
        key(SPACE);
    }
}

void setup()
{
    //Start serial connection
    Serial.begin(9600);

    //Configure pins
    for (char i = 0; i < 10; i++) {
        pinMode(get_pin_input(i), INPUT_PULLUP);
    }
    for (char i = 0; i < 10; i++) {
        if (i == 4 || i == 5) {
            continue;
        }
        pinMode(get_pin_output(i), OUTPUT);
        digitalWrite(get_pin_output(i), HIGH);
    }
    // Row 4 is GND
    pinMode(get_pin_output(4), OUTPUT);
    digitalWrite(get_pin_output(4), LOW);
}

bool run_once = true;

void loop() {
    if (run_once) {
        for (char i = 0; i < 10; i++) {
            for (char j = 0; j < 10; j++) {
                write_character('0' + i);
                write_character(' ');
                write_character('0' + j);
                write_character(' ');
                Combi combi;
                combi.input = i;
                combi.output = j;
                combi.mod =MOD_NO;
                activate(combi);
                write_character('\n');
            }
        }
    }
    run_once = false;
}

