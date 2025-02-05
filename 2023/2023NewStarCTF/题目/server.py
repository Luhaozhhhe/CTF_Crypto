import secrets
from secret import flag
import zlib

ROUND = 100

LENGTH = 20

print('Extreme hard CRC32 challenge')
print('ARE YOU READY')

for i in range(ROUND):
    print('ROUND', i, '!'*int(i/75 + 1))

    target = secrets.randbits(32)

    print('Here is my CRC32 value: ', hex(target))

    dat = input('Show me some data > ')
    raw = bytes.fromhex(dat)
    
    if zlib.crc32(raw) == target and len(raw) == LENGTH:
        print("GREAT")
    else:
        print("OH NO")
        exit()

print("Congratulation! Here is your flag")
print(flag)

