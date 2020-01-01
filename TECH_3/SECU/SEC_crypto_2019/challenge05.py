#!/usr/bin/python3

import sys
import binascii
import codecs

with open(sys.argv[1], "r") as file:
    hex_strings = file.readline().splitlines()
    str = codecs.decode(file.read().replace('\n', ''), "hex")

if not hex_strings or not str:
    exit(84)

key = codecs.decode(hex_strings[0], "hex")

result = b''
index = 0
for byte in str:
    result += bytes([byte ^ key[index]])
    if ((index + 1) == len(key)):
        index = 0
    else:
        index += 1
print(result.hex().upper())