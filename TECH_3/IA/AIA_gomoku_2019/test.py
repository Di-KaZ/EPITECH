#!/usr/bin/python

def five_horizontal(line, index, char):
        count = 0
        while index < len(line) - 1 and line[index] == char:
            count += 1
            index += 1
        if count >= 5:
            return True
        else:
            return False

line = [0, 0, 1, 1, 1, 1, 2]

print(five_horizontal(line, 1, 1))