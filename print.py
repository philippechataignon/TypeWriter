#! /usr/bin/env python3
import argparse
import serial
import sys
import time
import unicodedata

def wait_ready(ser):
    while True:
        read = ser.read()
        print(read)
        if read == b".":
             break

def main():
    parser = argparse.ArgumentParser(description="Print on Panasonic R191")
    parser.add_argument("--port", metavar="port", type=str, help="COM port", default="/dev/ttyACM0")
    args = parser.parse_args()
    with serial.Serial(args.port, 9600) as ser:
        ser.timeout = 10
        for line in sys.stdin:
            line = unicodedata.normalize("NFC", line).encode("latin1", "ignore")
            print(line)
            ser.write(line)
            wait_ready(ser)

if __name__ == "__main__":
    main()
