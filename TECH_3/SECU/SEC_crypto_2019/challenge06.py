#!/usr/bin/python3
import binascii
import sys
import base64

# def padd_string(str, padding):
#     padding = padding - (len(str) % padding)
#     i = 0
#     while i < padding:
#         str += '\x03'
#         i += 1
#     return str

# def hamming_dist(s1, s2):
#     s1 = bin(int(binascii.hexlify(bytearray(s1, encoding="utf-8")),16))[2:]
#     s2 = bin(int(binascii.hexlify(bytearray(s2, encoding="utf-8")),16))[2:]
#     assert len(s1) == len(s2)
#     return sum(c1 != c2 for c1, c2 in zip(s1, s2))

# with open(sys.argv[1], "r") as file:
#     hex_string = padd_string(file.read(), 2)

# avg_dist = []

# for ksize in range(5, 41):
#     ham_dists = []
#     substrings = [hex_string[i:i+ksize] for i in range(0, len(hex_string), ksize)]
#     while True:
#         try:
#             ham_dists.append(hamming_dist(substrings[0], substrings[1]) / ksize)
#             del substrings[0]
#             del substrings[1]
#         except:
#             break
#     final = {'key' : ksize, 'dist' : sum(ham_dists) / len(ham_dists)}
#     avg_dist.append(final)
# for key, dist in avg_dist:
#     print("key : %s | dist : %d\n" %(key, dist))

exit(84)