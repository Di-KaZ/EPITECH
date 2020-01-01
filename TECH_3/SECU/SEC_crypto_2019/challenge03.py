#!/usr/bin/python3

import sys
import binascii
import codecs

char_freq = {
    'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
    'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
    'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
    'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
    'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
    'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
    'y': .01974, 'z': .00074
}

def print_most_prob_str(strs):
    best_freq = .0
    final = 0
    ident = 0
    for stri in strs:
        temp_freq = .0
        for byte in stri.lower():
            temp_freq += char_freq.get(byte, 0)
        if  temp_freq > best_freq:
            best_freq = temp_freq
            final = ident
        ident += 1
    print(hex(final)[2:].upper())

with open(sys.argv[1], "r") as file:
    hex_string = file.read()
if not hex_string:
    exit(84)
hex_string = hex_string.rstrip()
hex_string = binascii.unhexlify(hex_string)
results = []
for i in range(256):
    result = ''
    for byte in hex_string:
        result += chr(byte ^ i)
    results.append(result)
print_most_prob_str(results)