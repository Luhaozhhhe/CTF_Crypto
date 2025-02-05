from Crypto.Util.number import *
import random
from secrets import flag


class LCG:
    def __init__(self, seed, a, b, p):
        self.seed = seed
        self.a = a
        self.b = b
        self.p = p

    def next(self):
        self.seed = (self.seed * self.a + self.b) % self.p
        return self.seed >> (self.p.bit_length() - 8)


m = bytes_to_long(flag)
p = getPrime(128)
a = random.randint(1, p)
b = random.randint(1, p)
seed = random.randint(1, p)
out = []
lcg = LCG(seed, a, b, p)
for i in range(30):
    out.append(lcg.next())
key = ""
while 1:
    key += str(lcg.next())
    if int(key) >= m:
        break

with open("out.txt", "w") as f:
    f.write(f"p={p}\n")
    f.write(f"a={a}\n")
    f.write(f"b={b}\n")
    f.write(f"out={out}\n")
    f.write(f"c={int(key)^m}")
