#!/usr/bin/env python3
from chacha20 import *
from Crypto.Util.number import long_to_bytes, bytes_to_long
from secret import flag, mykey, mynonce

def chacha_init(key, nonce, counter):
    assert len(key) == 32
    assert len(nonce) == 8

    state = [0 for _ in range(16)]
    state[0] = bytes_to_long(b"expa"[::-1])
    state[1] = bytes_to_long(b"nd 3"[::-1])
    state[2] = bytes_to_long(b"2-by"[::-1])
    state[3] = bytes_to_long(b"te k"[::-1])

    key = bytes_to_long(key)
    nonce = bytes_to_long(nonce)
    
    for i in range(8):  
        state[i+4] = key & 0xffffffff
        key >>= 32

    state[12] = (counter >> 32) & 0xffffffff
    state[13] = counter & 0xffffffff
    state[14] = (nonce >> 32) & 0xffffffff
    state[15] = nonce & 0xffffffff

    return state


def encrypt(data):
    global state
    state = chacha_block(state)
    buffer = b"".join(long_to_bytes(x).rjust(4, b"\x00") for x in state)
    output = []
    for b in data:
        output.append(b ^ buffer[0])
        buffer = buffer[1:]

    return bytes(output)

FLAG = b"H&NCTF{****FAKE****}"
MYNONCE =b"sdf*h*o*"
assert len(flag) == 64
assert len(mynonce) == 8

if __name__ == "__main__":
    while True:
        print("""================================
Enjoy the happiness of dancing
1. Dance on My Stage
2. Dance on Your Stage
3. Encrypt flag
""")
        choice = input("> ")

        if choice == '1':
            state = chacha_init(mykey, mynonce, 0)
            print(encrypt(input("input what you want to dance on my stage > ").encode()).hex()) 

        elif choice == '2':
            yournonce = input("build your own stage > ")
            assert len(yournonce) == 8
            state = chacha_init(mykey, yournonce.encode(), 0)
            yourIn = bytes.fromhex(input("then, have a hex dance > "))
            print(encrypt(yourIn).hex())
            
        elif choice == '3':
            state = chacha_init(mykey, mynonce[::-1], 0)  
            print(encrypt(flag).hex())

        else:
            print("Let's dance together next time~")
            exit()