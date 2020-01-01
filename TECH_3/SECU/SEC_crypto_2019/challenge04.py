#!/usr/bin/python3

import sys
import binascii
import codecs
import os

char_freq = {
    'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
    'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
    'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
    'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
    'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
    'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
    'y': .01974, 'z': .00074, ' ': .13000
}

class Message:
    def __init__(self, index, str):
        self.index  = index
        self.str = str
        self.prob = 0
        self.key = 0

    def getMaxProbAndKey(self):
        if not self.str:
            exit(84)
        unhex_str = binascii.unhexlify(self.str)
        results = []
        best_freq = .0
        for i in range(256):
            result = ''
            for byte in unhex_str:
                result += chr(byte ^ i)
            results.append(result)
        numb = 0
        for stri in results:
            temp_freq = .0
            for byte in stri.lower():
                temp_freq += char_freq.get(byte, 0)
            if  temp_freq > best_freq:
                best_freq = temp_freq
                self.key = numb
                self.prob = best_freq
            numb = numb + 1

    def printInfo(self):
        print("%d %s" %(self.index, hex(self.key)[2:].upper()))

messages = []
index = 0

# read all file
with open(sys.argv[1], "r") as file:
    hex_strings = file.read().splitlines()

if not hex_strings:
    exit(84)

# create all message and find their most promising key accordin to the most probable result
for index, hex_string in enumerate(hex_strings, 1):
    temp_msg = Message(index, hex_strings[index - 1])
    temp_msg.getMaxProbAndKey()
    messages.append(temp_msg)

# get the most promising message
best_message = messages[0]
for message in messages:
    if message.prob > best_message.prob:
        best_message = message

# display message info
best_message.printInfo()