import os
from Crypto.Util.number import *
from Crypto.Math.Numbers import Integer
import random
import hashlib
import signal

H = lambda om: int(hashlib.sha256(om).hexdigest(), 16)
flag = os.getenv("DASFLAG", "flag for gfctf2024, the problem comes from atcry241")
signal.alarm(60)

tm = b'ATCRY241: Freedom and Captivity'
black_list = [H(tm)]

class Sign:
    @staticmethod
    def check(x, l, u):
        x = Integer(x)
        if x.size_in_bits() < l or x.size_in_bits() > u or x.is_even() or x.is_perfect_square():
            return False

        nd = lambda y: -y - 2 if y > 0 else -y + 2
        d = 5
        while True:
            if x == d or x == -d:
                d = nd(d)
                continue
            js = Integer.jacobi_symbol(d, x)
            if js == 0:
                return False
            if js == -1:
                break
            d = nd(d)

        x = int(x)
        k = x + 1
        ui, vi, ut, vt = 1, 1, 0, 0
        for i in range(k.bit_length() - 2, -1, -1):
            ut = ui * vi % x
            vt = (((vi ** 2 + (ui ** 2 * d)) * k) >> 1) % x
            if (k >> i) & 1:
                ui = (((ut + vt) * k) >> 1) % x
                vi = (((vt + ut * d) * k) >> 1) % x
            else:
                ui, vi = ut, vt
        return ui == 0

    def checkall(self):
        check = self.check
        e, d, h, p, z, s, _ = self.key
        assert check(p, 2 ** 11, 2 ** 12) and check(z, 11, 56)
        assert check(d, int(3.78**3.78), int(3.87**3.87)) and check(e, 1022, 1152)
        assert (e - 1) % d == 0 and pow(h, d, e) == 1
        assert h.bit_length() >= 1022 and h < e

    def __init__(self):
        p, e, d, h, z = [int(i, 16) for i in input("param:").split('-')]
        s = random.randint(1, d // z**2) * z**2
        f = pow(h, s, e)
        self.key = [e, d, h, p, z, s, f]
        self.checkall()
        print(f)

    def sign(self):
        e, d, h, p, z, s, _ = self.key
        ml = H(input("m:").encode())
        global black_list
        assert ml not in black_list
        black_list += [ml]
        r = random.randint(1, d - 1)
        return pow(h, r, e) % d, pow(inverse(r, d) * (ml + s * pow(h, r, e) % d) % d, z, p)

    def verify(self):
        e, h = [int(i, 16) for i in input("param:").split('-')]
        d = self.key[1] + 2
        while not self.check(d, int(3.78**3.78), int(3.87**3.87)):
            d += 2
        f = pow(h, random.randint(1, d - 1), e)
        self.key[:3] = e, d, h
        self.checkall()
        sig1, sig2 = [int(i, 16) for i in input("sig:").split('-')]
        assert sig1 * sig2 > 0
        assert (pow(h, H(tm) * inverse(sig2, d) % d, e) * pow(f, sig1 * inverse(sig2, d) % d, e) % e) % d == sig1
        print(flag)


def menu():
    print("[1] Gain freedom")
    print("[2] Free the captivity")
    cc = int(input("which: "))
    return cc


def main():
    print("Freedom is the wings of the soul, and captivity is the grave of hope.")
    s = Sign()
    while True:
        print(s.sign() if menu() == 1 else s.verify())


main()
try:
    main()
except:
    print("something bad!")
