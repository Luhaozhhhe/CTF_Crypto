from Crypto.Util.number import *
from hashlib import sha256
from secret import flag, secret,SECRET

assert flag[6:-1] == sha256(long_to_bytes(secret)).hexdigest().encode()


class ECC_easy:
    def __init__(self):
        self.a = 1365855822212045061018261334821659180641576788523935479
        self.b = 17329427219955161804703200105884322768704934833367341
        self.p = 1365855822212045061018261334821659180641576788523935481

    def add(self, P, Q):
        mul_inv = lambda x: pow(x, -1, self.p)
        x1, y1 = P
        x2, y2 = Q
        if P!=Q:
            l=(y2-y1)*inverse(x2-x1,self.p)%self.p
        else:l=(3*x1**2+2*self.a*x1+1)*inverse(2*self.b*y1,self.p)%self.p
        temp1 = (self.b*l**2-self.a-x1-x2)%self.p
        temp2 = ((2*x1+x2+self.a)*l-self.b*l**3-y1)%self.p
        x3 = temp1
        y3 = temp2
        return x3, y3

    def mul(self, x, P):
        Q = SECRET
        x = x % self.p
        while x > 0:
            if x & 1:
                Q = self.add(Q, P)
            P = self.add(P, P)
            x >>= 1
        return Q

    def ispoint(self, x, y):
        return (self.a * x ** 2 + x ** 3+x) % self.p == (self.b * y ** 2) % self.p


ecc = ECC_easy()
LLLL = (1060114032187482137663886206406014543797784561116139791,752764811411303365258802649951280929945966659818544966)
assert ecc.ispoint(LLLL[0], LLLL[1])
END = ecc.mul(secret, LLLL)
print(END)

# (695174082657148306737473938393010922439779304870471540,414626357054958506867453055549756701310099524292082869)