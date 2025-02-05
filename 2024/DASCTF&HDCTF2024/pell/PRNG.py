from Crypto.Util.number import *


def Legendre(n, p):
    return pow(n, (p - 1) // 2, p)


def Tonelli_Shanks(n, p):
    assert Legendre(n, p) == 1
    if p % 4 == 3:
        return pow(n, (p + 1) // 4, p)
    q = p - 1
    s = 0
    while q % 2 == 0:
        q = q // 2
        s += 1
    for z in range(2, p):
        if Legendre(z, p) == p - 1:
            c = pow(z, q, p)
            break
    r = pow(n, (q + 1) // 2, p)
    t = pow(n, q, p)
    m = s
    if t % p == 1:
        return r
    else:
        i = 0
        while t % p != 1:
            temp = pow(t, 2 ** (i + 1), p)
            i += 1
            if temp % p == 1:
                b = pow(c, 2 ** (m - i - 1), p)
                r = r * b % p
                c = b * b % p
                t = t * c % p
                m = i
                i = 0
        return r


class Curve:
    def __init__(self):
        self.N = 9909641861967580472493256614158113105414778684219844785944662774988084232380069009372420371597872375863508561123648164278317871844235719752735021659264009

    def __repr__(self) -> str:
        return f"Curve defined by y^2 = x^3 over Finite Field of size {self.N}"

    def is_on_point(self, point):
        if point is None:
            return True
        x, y = point
        return y**2 % self.N == x**3 % self.N

    def add(self, P, Q):
        if P is None:
            return Q
        if Q is None:
            return P
        xp, yp = P
        xq, yq = Q
        if P != Q:
            k = (yp - yq) * inverse(xp - xq, self.N) % self.N
        else:
            k = 3 * xp**2 * inverse(2 * yp, self.N) % self.N
        xr = (k**2 - xp - xq) % self.N
        yr = (k * (xp - xr) - yp) % self.N
        return (int(xr), int(yr))

    def mul(self, P, x):
        Q = None
        x = x % self.N
        while x > 0:
            if x & 1:
                Q = self.add(Q, P)
            P = self.add(P, P)
            x >>= 1
        return Q

    def random_point(self):
        while 1:
            x = getRandomRange(1, self.N)
            y_2 = x**3 % self.N
            if Legendre(y_2, self.N) == 1:
                y = Tonelli_Shanks(y_2, self.N)
                if Curve.is_on_point(self, (x, y)):
                    return (x, y)


class LCG:
    def __init__(self, E, Q=None):
        self.E = E
        self.P = self.E.random_point()
        if Q == None:
            self.Q = self.E.random_point()
        else:
            self.Q = Q

    def next(self):
        self.Q = self.E.add(self.P, self.Q)
        return self.Q[0]

    def get_prime(self):
        i = 1
        p = int(LCG.next(self))
        while 1:
            if isPrime(p):
                self.P = self.E.mul(self.P, i)
                return p
            else:
                i += 1
                p = int(LCG.next(self))