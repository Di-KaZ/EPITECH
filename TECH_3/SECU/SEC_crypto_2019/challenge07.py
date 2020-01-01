#!/usr/bin/python3

# import codecs
# import sys
# import base64
# from Crypto.Cipher import AES

# def padd_string(stri, padding):
#     i = 0
#     while i < padding:
#         stri += bytes("\x03", encoding='utf-8')
#         i += 1
#     return stri


# def unpad_string(stri, padding):
#     return stri[:-ord(stri[len(stri)-1:])]

# with open(sys.argv[1], "r") as file:
#     key = file.readline().splitlines()
#     msg = file.read().replace('\n', '')

# msg = base64.b64decode(msg)
# padding = (len(msg) % 256)
# msg = padd_string(msg, padding)
# key = codecs.decode(key[0], "hex")

# cipher = AES.new(key, AES.MODE_ECB)
# msg = cipher.decrypt(msg)
# msg = unpad_string(msg, padding)
# print(base64.b64encode(msg).decode())
exit(84)