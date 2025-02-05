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