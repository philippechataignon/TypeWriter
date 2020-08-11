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
        if read in (b""):
             break


def main():
    parser = argparse.ArgumentParser(description="Print on Panasonic R191")
    parser.add_argument("--port", metavar="port", type=str, help="COM port", default="/dev/ttyACM0")
    args = parser.parse_args()

    with serial.Serial(args.port, 9600) as ser:
        ser.timeout = 1
        for line in sys.stdin:
            wait_ready(ser)
            line = unicodedata.normalize("NFC", line).encode("latin1", "ignore")
            ser.write(line)
            print(len(line)-1, line)

if __name__ == "__main__":
    main()
