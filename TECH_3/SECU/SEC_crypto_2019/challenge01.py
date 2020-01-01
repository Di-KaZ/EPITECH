#!/usr/bin/python3

import sys
import binascii
import base64
import codecs

if len(sys.argv) != 2:
    exit(84)
try:
    with open(sys.argv[1], "r") as file:
        str = file.read()
        if not str:
            print("lol")
            exit(84)
        str = str.replace('\n', '')
        print(codecs.encode(codecs.decode(str, 'hex'), 'base64').decode().replace('\n', ''))
except:
    exit(84)