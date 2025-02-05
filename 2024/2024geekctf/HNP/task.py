from Crypto.Util.number import *
from hashlib import sha256
from random import seed, choice
from secret import flag
from signal import signal, alarm, SIGALRM
from string import ascii_letters, digits

def handler(signum, frame):
    print('Time out!')
    raise exit()

def proof_of_work():
    seed(getRandomRange(1, 2**128))
    proof = ''.join([choice(ascii_letters + digits) for _ in range(20)])
    digest = sha256(proof.encode('latin-1')).hexdigest()
    print('sha256(XXXX + {}) == {}'.format(proof[4: ], digest))
    print('Give me XXXX:')
    x = input()
    if x != proof[: 4]:
        return False
    return True

n = 8
A = 2048
B = A // n
MASK1 = 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
MASK2 = 0x1fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000000000000000000000000000000000000000000000000000000000000000000000000000000000007ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffc0000000000000000000000000000000000000000000000000000000000000000000000000000000000001fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff

def challenge():
    N = getPrime(A)
    X = getRandomRange(1, N)
    Y = [getRandomRange(1, N) for _ in range(n)]
    Z = [X * Y[_] % N for _ in range(n)]
    print(N)
    for _ in range(n):
        X_ = Z[_]
        Y_ = [(Y[_] >> (__ * B)) & MASK1 for __ in range(n)]
        Z_ = [(X_ * Y_[__] % N) & MASK2 for __ in range(n)]
        print(Z_)
    alarm(5)
    G = int(input('X:'))
    alarm(30)
    if G == X:
        return 1
    else:
        return 0


signal(SIGALRM, handler)
alarm(60)

if not proof_of_work():
    exit()

for _ in range(3):
    if not challenge():
        print('Wrong!')
        exit()
    else:
        print('Good!')

print(flag)
