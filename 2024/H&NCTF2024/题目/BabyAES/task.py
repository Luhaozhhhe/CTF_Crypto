from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from secret import flag
import time
import random

flag = pad(flag,16)
assert b"H&NCTF" in flag

seed = int(time.time())
random.seed(seed)
key = random.randbytes(16)
iv = random.randbytes(16)
aes = AES.new(key,AES.MODE_CBC,iv)
cipher = aes.encrypt(flag)

print(f"cipher = {cipher}")

"""
cipher = b'\x96H_hz\xe7)\x0c\x15\x91c\x9bt\xa4\xe5\xacwch\x92e\xd1\x0c\x9f\x8fH\x05\x9f\x1d\x92\x81\xcc\xe0\x98\x8b\xda\x89\xcf\x92\x01a\xe1B\xfb\x97\xdc\x0cG'
"""