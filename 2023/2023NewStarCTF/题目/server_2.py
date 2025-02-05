from secret import flag
import string
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
from os import urandom
import re

key = urandom(16)

menu = '''
[+] WatchDog Security System
[+] Copyright (c) 1010 by School of Natural Philosophy 

please select your option:
1. Unlock Secret Entry
2. Help
3. Exit
'''

valid_code = [1033,3329,4431,5052]

auth_context_pattern = re.compile(r'^SoNP#[0-9]{4}$')

def auth_context_checker(ctx : bytes):
    for c in ctx:
        if chr(c) not in string.printable:
            return False
    if auth_context_pattern.match(ctx.decode()) : return True

    return False

def unlock():
    token = bytes.fromhex(input('Enter your token > '))
    auth_code = bytes.fromhex(input('Enter your authentication code > '))

    cipher = AES.new(key, AES.MODE_CBC,token)
    
    check = cipher.decrypt(auth_code)
    try:
        
        msg = unpad(check, 16)
        if auth_context_checker(msg) and int(msg[5:].decode()) in valid_code:
            print('door unlocked, here is your reward')
            print(flag)
        else:
            print('get out')

    except Exception as e:
        print('oops, something wrong')
        print(e)
def help():
    print('To unlock the door, please enter your token and authentication code.')
while True:
    print(menu)
    opt = input('> ')
    try:
        opt = int(opt)
        if opt == 1:
            unlock()
        elif opt == 2:
            help()
        elif opt == 3:
            break
        else:
            print('invalid option')
    except:
        print('oh no, something wrong!')
        