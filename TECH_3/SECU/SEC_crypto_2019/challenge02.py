#!/usr/bin/python3

import sys

if len(sys.argv) != 2:
    exit(84)
try:
    with open(sys.argv[1]) as f:
        lines = f.read().splitlines()
    if not lines:
        exit(84)
    lines[0].rstrip()
    lines[1].rstrip()
    pr = hex(int(lines[0], 16) ^ int(lines[1], 16))
    print("{}".format(hex(int(pr, 16))[2:].upper()))
except:
    exit(84)