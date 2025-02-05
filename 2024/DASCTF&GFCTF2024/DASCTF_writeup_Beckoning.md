# <center>DASCTF writeup by Beckoning</center>



# Crypto

## Freedom and Captivity

```python
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
```



## Light and Darkness

```python
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
```



## Sign-in by quantum computer

```python
# The code is compressed by an algorithm
import hashlib

'''
I have a quantum computer and I use it to solve some of the problems in my work. The following is part of my work.
In order to protect the privacy of my work, all variable names have been replaced with simple letters. 
I believe you have also a quantum computer. Now please prove to me that you have a quantum computer.
'''

n = lambda q, r: q % r
x = lambda y, z: y**z
i = lambda j, k: j if not k else i(k, n(j, k))
l = lambda m: 1 if not m else m * l(m-1)
o = lambda p: x(2, p)
op = lambda p: o(p)+1
os = lambda p: o(p)-1
oh = lambda p: p*o(-1)
xp = lambda y, z: x(y, z)+1
xs = lambda y, z: x(y, z)-1
xt = lambda y: x(y, 2)


a1 = o(17*o(9))
a2 = os(a1)
b1 = o(17)
b2 = os(b1)
b3 = b1-1+o(10)-o(5)+17
b4 = os(b3-1)
c1 = o(o(13))
c2 = os(c1)
d = i(a2, c2)
e = i(b2, c2)
f1 = i(d+2, e+2)
f2 = xt(l(os(b3-2)))
f3 = xt(n(f2, b4))
f4 = 2*n(f3, b4)
f = f4*op(a2+f1+f4)
g = i(xp(f, a1), xs(f, c1))
h = x(x(xt(f1)*g, oh(f)*f4), b2)
flag = hashlib.md5(str(h)[1-b1:].encode()).hexdigest()
print(flag)
```



## The_Mystery_of_Math

```python
from Crypto.Util.number import bytes_to_long, getPrime
from sympy import nextprime, gcd
from random import randint
from CustomNiBoLan import get_pDNF, get_pCNF
from secret import flag, random_proposition
import sys


class Godel:
    def __init__(self):
        self.table = ['﹁', '∨', '∧', '→', '↔', 's', '(', ')', 'p', 'q', 'r', 't']
        self.dict = self.generate_dict()

    def generate_dict(self, max_value=30):
        res = {}
        used = set()

        for k in self.table:
            while True:
                r = randint(1, max_value)
                if r not in used:
                    res[k] = r
                    used.add(r)
                    break

        return res

    def generate_primes(self, count, start=2):
        primes = []
        tmp = start

        while len(primes) < count:
            primes.append(tmp)
            tmp = nextprime(tmp)
        
        return primes

    def translate(self, seq):
        p = self.generate_primes(len(seq))
        gn = 1
        for c, prime in zip(seq, p):
            gn *= prime ** self.dict[c]
        return gn


def encrypt(para):
    p = nextprime(para)
    q = getPrime(512)
    e = 65537
    n = p * q
    m = bytes_to_long(flag)
    c = pow(m, e, n)
    return c, n


if __name__ == '__main__':
    g = Godel()

    plaint = input("请输入命题，例p∧q（最多四个变量）：")

    conj = get_pCNF(plaint)
    disj = get_pDNF(plaint)
    reslist = [g.translate(conj), g.translate(disj)]

    p = g.translate(random_proposition)
    c, n = encrypt(p)
    print(random_proposition)
    print(f'c: {c}')
    print(f'n: {n}')
    print(f'tip: {gcd(*reslist)}')
```



# Misc

## badmes

> 垃圾信息侵扰已久，为了维护数字空间的清洁，我们需要你的帮助来识别并过滤这些不受欢迎的信息。你的任务是构建一个机器学习模型，准确识别垃圾短信。这里有一个数据集，请先训练你的模型再判断随机发送的短信是否为垃圾短信哦，答对积一分，答错不积分，一共300条信息，总分在240分即可获得flag

直接用之前训练的模型代入，超过240分就可以获得flag了

<img src="C:\Users\Lenovo\AppData\Roaming\Typora\typora-user-images\image-20240420122635311.png" alt="image-20240420122635311" style="zoom: 67%;" />

flag的值是：

```
DASCTF{OB0b73eC3VVpvbadnne3}
```



## parser

> 警告！有大黑阔入侵我们的某台服务器！” leader：小小混淆，一看就刚学不久，交给你了



## tele

> 这是我们抓到的一个犯醉团伙的通话流量，请找到发起者的IP地址！



## twice

> http://4.216.93.105:8079/



