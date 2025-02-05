from secret import flag
from Cryptodome.Util.number import *

menu = '''
Welcome to RSA Broadcasting system

please select your option:

1. brocast the flag
2. exit
'''
e = 17
def broadcast_the_flag():
    p = getPrime(256)
    q = getPrime(256)
    n=p*q
    m = bytes_to_long(flag)
    c = pow(m,e,n)
    print('n =', n)
    print('c =', c)
    print('e =', e)
while True:
    print(menu)
    opt = input('> ')
    try:
        opt = int(opt)
        if opt == 1:
            broadcast_the_flag()
        elif opt == 2:
            break
        else:
            print('invalid option')
    except:
        print('oh no, something wrong!')
        