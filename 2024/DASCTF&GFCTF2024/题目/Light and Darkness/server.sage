import random
import string
import sys
from Crypto.Math.Numbers import Integer
from hashlib import sha256
from Crypto.Util.number import bytes_to_long, long_to_bytes
import signal

signal.alarm(120)
flag = os.getenv("DASFLAG", "flag for gfctf2024, the problem comes from atcry242")

def proof_of_work():
    t = ''.join(random.sample(string.ascii_letters + string.digits, 3))
    print(f"your username is {t}")
    try:
        s = int(input("input your work proof:"), 16)
        assert s < 2^32
        random.seed(s)
        y = ''.join([chr(x) for x in random.randbytes(3)])
        assert y == t
    except:
        print("you proof nothing...")
        sys.exit()
    print(f"Hello {t}, Let's tangle together in light and darkness.")

def check(x):
    if Integer(int(x)).is_perfect_square():
        return False
    m, a = x - 1, 0
    while m & 1 == 0:
        m >>= 1
        a += 1
    for i in range(20):
        b = 1
        while b in (1, x - 1):
            b = Integer.random_range(min_inclusive=int(2), max_inclusive=int(x-2), randfunc=random.randbytes)
        z = pow(int(b), m, x)
        if z in (1, x - 1):
            continue
        for j in range(1, a):
            z = pow(z, 2, x)
            if z == x - 1:
                break
            if z == 1:
                return False
        else:
            return False
    return True

def param(init, r, s=2, l=688, u=1688):
    p = init - 3
    while not check(p):
        p = random.randint(l, u) if r else p + s
    return p

class Sign:
    def __init__(self):
        q = param(2^22, False)
        b = param(2^14, False)
        n = param(2^10-1, True) // 2
        w = param(2^3, True, l=2^2, u=2^4)
        F.<x> = PolynomialRing(GF(q))
        F.<x> = F.quotient(x^n-1)
        rp = lambda m: sum(randint(-m, m) * x**i for i in range(n))
        ph = lambda p, m: sha256(b''.join(long_to_bytes(int(p[i]), 3) for i in range(n)) + m).digest()
        hp = lambda h: sum(((1 << i) & bytes_to_long(h) != 0) * x**i for i in range(n))
        ep = lambda p : b''.join(long_to_bytes(int(p[i]), 3) for i in range(n)).hex()
        dp = lambda p : sum(bytes_to_long(p[i: i+3]) * x ** (i // 3) for i in range(0, 3*n, 3))
        a = rp(q // 2)
        s, e = rp(1), rp(1)
        t = a * s + e
        self.pri = (s, e)
        self.pub = (a, t, n, q, b, w)
        self.fcn = (rp, ph, hp, ep, dp)
        print(ep(a)+ep(t))

    def verify(self, m, sig):
        a, t, n, q, b, w = self.pub
        _, ph, hp, _, dp = self.fcn
        z1, z2, c = [dp(bytes.fromhex(i)) for i in sig]
        for i in range(n):
            if min(z1[i], q - z1[i]) > b - w:
                return False
            if min(z2[i], q - z2[i]) > b - w:
                return False
        return hp(ph(a * z1 + z2 - t * c, m)) == c

def main():
    print("There is light even in the darkest places.")
    proof_of_work()
    try:
        light, dark = Sign(), Sign()
        ls, ds = input("light = ").split('-'), input("dark = ").split('-')
        m1 = b'ATCRY242: Light and Darkness'
        m2 = m1 + b' Darkness cannot drive out darkness, only light can do that. ' + m1[::-1]
        assert light.verify(m1, ls) and dark.verify(m2, ds)
        print(flag)
    except Exception as e:
        print("something bad!")

main()
