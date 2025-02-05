from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
import os

flag = open("flag.txt", "rb").read()
key = os.urandom(16)
iv = os.urandom(16)
flag = pad(flag, 16)


def aes_encrypt(key, plaintext):
    cipher = AES.new(key, AES.MODE_ECB)
    return cipher.encrypt(plaintext)


def encrypt(key, plaintext, iv):
    ciphertext = b""
    for i in range(0, len(plaintext), AES.block_size):
        key_block = aes_encrypt(key, iv)
        ciphertext_block = bytes([plaintext[i + j] ^ key_block[j] for j in range(AES.block_size)])
        ciphertext += ciphertext_block
        iv = key_block
    return ciphertext


while 1:
    try:
        print("1.print\n2.input\n3.exit")
        a = input("> ")
        if a == "1":
            print((iv + encrypt(key, flag, iv)).hex())
        elif a == "2":
            ivs = bytes.fromhex(input("iv: "))
            inputs = bytes.fromhex(input("message: "))
            print(encrypt(key, inputs, ivs).hex())
        elif a == "3":
            exit(0)
        else:
            print("You need input 1,2,3")
    except:exit(0)