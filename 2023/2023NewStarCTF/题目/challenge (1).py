import os
def xor(a:bytes,b:bytes):
    assert len(a) == len(b)
    return bytes([i ^ j for i,j in zip(a,b)])

class PRP():
    def __init__(self, n):
        self.domain_cache = {}
        self.range_cache = {}
        self.n = n

    def tran(self, m, inverse = False):
        if not inverse:
            x = m
            if x in self.domain_cache:
                return self.domain_cache[x]
            while True:
                y = os.urandom(self.n)
                if y in self.range_cache:continue
                self.domain_cache[x] = y
                self.range_cache[y] = x    
                return y
        else:
            y = m
            if y in self.range_cache:
                return self.range_cache[y]
            while True:
                x = os.urandom(self.n)
                if x in self.domain_cache:continue
                self.domain_cache[x] = y
                self.range_cache[y] = x    
                return x

class PRF():
    def __init__(self, n):
        self.domain_cache = {}
        self.range_cache = {}
        self.n = n 

    def tran(self, x):
        if x not in self.domain_cache:
            self.domain_cache[x] = os.urandom(self.n)
        return self.domain_cache[x]

class Challenge1:
    def __init__(self):
        self.coin = os.urandom(1)[0] & 1
        self.block_size = 8
        self.input_size = 2 * self.block_size
        self.RO1 = PRF(self.block_size)
        self.RO2 = PRF(self.input_size)

    def function1(self, M):
        L, R = M[:self.block_size], M[self.block_size:]
        L, R = R, xor(L, self.RO1.tran(R))
        return L+R

    def function2(self, M):
        return self.RO2.tran(M)

    def roll(self, M, inverse):
        assert inverse == False, "In Challenge1, inverse is not allowed"
        return [self.function1,self.function2][self.coin](M)

class Challenge2:
    def __init__(self):
        self.coin = os.urandom(1)[0] & 1
        self.block_size = 8
        self.input_size = 2 * self.block_size
        self.RO1 = PRF(self.block_size)
        self.RO2 = PRF(self.input_size)

    def function1(self, M):
        L, R = M[:self.block_size], M[self.block_size:]
        L, R = R, xor(L, self.RO1.tran(R))
        L, R = R, xor(L, self.RO1.tran(R))
        return L+R

    def function2(self, M):
        return self.RO2.tran(M)

    def roll(self, M, inverse):
        assert inverse == False, "In Challenge2, inverse is not allowed"
        return [self.function1,self.function2][self.coin](M)

class Challenge3:
    def __init__(self):
        self.coin = os.urandom(1)[0] & 1
        self.block_size = 8
        self.input_size = 2 * self.block_size
        self.RO1 = PRF(self.block_size)
        self.RO2 = PRF(self.input_size)

    def function1(self, M, inverse):
        if not inverse:
            L, R = M[:self.block_size], M[self.block_size:]
            L, R = R, xor(L, self.RO1.tran(R))
            L, R = R, xor(L, self.RO1.tran(R))
            L, R = R, xor(L, self.RO1.tran(R))
        else:
            L, R = M[:self.block_size], M[self.block_size:]
            L, R = xor(R, self.RO1.tran(L)), L
            L, R = xor(R, self.RO1.tran(L)), L
            L, R = xor(R, self.RO1.tran(L)), L
        return L+R

    def function2(self, M, inverse):
        if inverse or not inverse:        
            return self.RO2.tran(M)

    def roll(self, M, inverse):
        return [self.function1,self.function2][self.coin](M,inverse)

class Challenge4:
    def __init__(self):
        self.coin = os.urandom(1)[0] & 1
        self.block_size = 8
        self.input_size = 2 * self.block_size
        self.PRP1 = PRP(self.block_size)
        self.PRP2 = PRP(self.input_size)

    def function1(self, M, inverse):
        X, T = M[:self.block_size], M[self.block_size:]
        X = xor(X, T)
        for _ in range(2):
            X = xor(self.PRP1.tran(X, inverse),T)
        return X

    def function2(self, M, inverse):
        return self.PRP2.tran(M, inverse)[:self.block_size]

    def roll(self, M, inverse):
        return [self.function1,self.function2][self.coin](M,inverse)

class Challenge5:
    def __init__(self):
        self.coin = os.urandom(1)[0] & 1
        self.block_size = 1
        self.input_size = self.block_size
        self.PRP = PRP(self.block_size)
        self.PRF = PRF(self.input_size)

    def function1(self, M):
        return xor(bytes(1),self.PRP.tran(M))

    def function2(self, M):
        return xor(self.PRF.tran(M),bytes(1))

    def roll(self, M, inverse):
        assert inverse == False, "In Challenge 5, inverse is not allowed"
        return [self.function1,self.function2][self.coin](M)