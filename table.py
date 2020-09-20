#!/usr/bin/env python3
import re
#     {24, {9, 0, MOD_CODE | MOD_DELAY}}, /* Code-= CTRL-X kbd2 */

m = re.compile(r'{(\d+), {(\d+), (\d+), (.*)}}')
with open("table.txt") as f:
    t = [None] * 256
    for l in f:
        l = l.strip()
        match = m.search(l)
        if match:
            #print(match.groups())
            t[int(match.group(1))] = match.groups()
            #print(l)
for i, item in enumerate(t):
    if item is not None:
        input = int(item[2])
        if input > 6:
            input = input -1
        output = int(item[1])
        if output > 3:
            output = output - 2
        if i >= 32:
            print(f"{{ {input}, {output}, {item[3]} }},    // char {i} : {bytes([i]).decode('latin1')}")
        else:
            print(f"{{ {input}, {output}, {item[3]} }},    // char {i}")
    else:
        print(f"{{-1, -1, MOD_NO}},    // char {i} unmapped")

if __name__ == '__main__':
    pass

