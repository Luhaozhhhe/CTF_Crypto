from Crypto.Util.number import *
import gmpy2
from flag import flag
import os
from hashlib import md5

def gen_prime(number):
    p = getPrime(number // 2)
    q = gmpy2.next_prime(p)
    return p * q

def md5_hash(m):
    return md5(m.encode()).hexdigest()
e = 65537
n = gen_prime(1024)
m1 = bytes_to_long(flag[:len(flag) // 2].encode() + os.urandom(8))
c1 = pow(m1, e, n)
m2 = flag[len(flag) // 2:]
with open("out.txt","w") as f:
    f.write(str(n) + '\n')
    f.write(str(c1) + '\n')
    for t in m2:
        f.write(str(md5_hash(t))+'\n')

