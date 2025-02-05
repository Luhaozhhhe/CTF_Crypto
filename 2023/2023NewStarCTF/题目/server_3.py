#!/usr/bin/python3
from secret import flag
from Crypto.Util.number import *
from random import randrange

p = 64999433139797068147576269731948390094958654326970231465808792590598519729077

a = randrange(2, p)
b = randrange(2, p)
x = bytes_to_long(flag)
menu = '''

Random as a Service with LCG backend

Enter your option
1. Reset
2. Get
3. Exit
'''

def GetRandom():
    global x
    nx = (a*x + b) % p
    print(nx)
    x = nx
    
while True:
    print(menu)
    opt = input('> ')
    try:
        opt = int(opt)
        if opt == 1:
            x = bytes_to_long(flag)
        elif opt == 2:
            GetRandom()
        elif opt == 3:
            break
        else:
            print('invalid option')
    except Exception as e:
        print('oh no, something wrong!')
        print(e)
        