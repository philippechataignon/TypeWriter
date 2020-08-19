#include "typewriter.h"

void activate(char row, char col, bool shift_same_col)
{
    char readPin = get_pin_col(col);
    char writePin = get_pin_row(row);

    /* wait LOW state */
    while (!(digitalRead(readPin) == LOW));

    digitalWrite(writePin, LOW);

    if (shift_same_col) {
        digitalWrite(shiftWritePin, LOW);
    }

    /* wait HIGH state */
    while (!(digitalRead(readPin) == HIGH));

    digitalWrite(writePin, HIGH);

    if (shift_same_col) {
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
            activate(SHIFT.row, SHIFT.col, false);
        }
        if (combi.mod & MOD_CODE) {
            activate(CODE.row, CODE.col, false);
        }
        activate(combi.row, combi.col, (combi.mod & MOD_SHIFT)
                 && combi.col == SHIFT.col);
    }
    if (combi.mod & MOD_KBD2) {
        key(KBD1);
    }
    if (combi.mod & MOD_DELAY) {
        /* let it breathe */
        delay(500);
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
        pinMode(get_pin_col(i), INPUT_PULLUP);
    }
    for (char i = 0; i < 10; i++) {
        if (i == 4 || i == 5) {
            continue;
        }
        pinMode(get_pin_row(i), OUTPUT);
        digitalWrite(get_pin_row(i), HIGH);
    }
    // Row 4 is GND
    pinMode(get_pin_row(4), OUTPUT);
    digitalWrite(get_pin_row(4), LOW);

    Serial.print('.');
}

void loop()
{
    // line buffer
    const unsigned char numChars = 72;
    unsigned char receivedChars[numChars + 1];
    unsigned char ndx = 0;
    boolean newData = false;

    unsigned char rc;
    while (Serial.available() > 0 && !newData) {
        rc = Serial.read();
        if (rc == '\r' || rc == '\n' || ndx >= numChars) {
            receivedChars[ndx] = '\0';  // terminate the string
            ndx = 0;
            newData = true;
        } else {
            receivedChars[ndx] = rc;
            ndx++;
        }
    }
    if (newData) {
        for (unsigned char *p = receivedChars; *p != 0; p++) {
            write_character(*p);
        }
        write_character('\r');
        Serial.print('.');
        newData = false;
    }
}
