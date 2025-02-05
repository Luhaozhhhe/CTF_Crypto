from sage.all import *
from secret import flag
import random
data = [ord(x) for x in flag]

mod = 0x42
n = 200
p = 5
q = 2**20

def E():
  return vector(ZZ, [1 - random.randint(0,p) for _ in range(n)])

def creatematrix():
  return matrix(ZZ, [[q//2 - random.randint(0,q) for _ in range(n)] for _ in range(mod)])

A, B, C= creatematrix(), creatematrix(), creatematrix()
x = vector(ZZ, data[0:mod])
y = vector(ZZ, data[mod:2*mod])
z = vector(ZZ, data[2*mod:3*mod])
e = E()
b = x*B+y*A+z*C + e
res = ""
res += "A=" + str(A) +'\n'
res += "B=" + str(B) +'\n'
res += "C=" + str(C) +'\n'
res += "b=" + str(b) +'\n'

with open("enc.out","w") as f:
  f.write(res)