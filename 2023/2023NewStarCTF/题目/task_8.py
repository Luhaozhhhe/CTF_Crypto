from Crypto.Util.number import *
from secret import flag
p = getPrime(64)
q = getPrime(64)
assert p % 4 == 3
assert q % 4 == 3

n = p * q

e = 2
m = bytes_to_long(flag)

c = pow(m,e,n)

print('n =', n)
print('c =', c)

# n = 201354090531918389422241515534761536573
# c = 20442989381348880630046435751193745753