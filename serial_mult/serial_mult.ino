// Example 2 - Receive with an end-marker

const byte numChars = 70;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.print('.');
}

void recv() {
    static byte ndx = 0;
    char rc;
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
        if (rc == '\r' || rc == '\n') {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        } else {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                // Serial.println("OVF");
                ndx = numChars - 1;
            }
        }
    }
}

void cmd() {
    if (newData) {
        char signal[8];
        delay(1000);
        sprintf(signal, ".%d", strlen(receivedChars));
        Serial.print(signal);
        newData = false;
    }
}

void loop() {
    recv();
    cmd();
}

