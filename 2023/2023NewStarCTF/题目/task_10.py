from secret import flag
from os import urandom
from pwn import xor
from Cryptodome.Util.number import *
k1 = getPrime(64)
k2 = getPrime(64)
ROUND = 12
ciphertext = xor(flag, long_to_bytes(k1))
def round_rotate_left(num, step):
    return ((num) << step | num >> (64-step)) & 0xffffffffffffffff
def encrypt_key(key):
    
    for _ in range(ROUND):
        key = round_rotate_left(key, 3) ^ k2
    
    return key
print('ciphertext =', ciphertext)
print('enc_k1 =', encrypt_key(k1))
print('k2 =', k2)

# ciphertext = b'\x8dSyy\xd2\xce\xe2\xd2\x98\x0fth\x9a\xc6\x8e\xbc\xde`zl\xc0\x85\xe0\xe4\xdfQlc'
# enc_k1 = 7318833940520128665
# k2 = 9982833494309156947