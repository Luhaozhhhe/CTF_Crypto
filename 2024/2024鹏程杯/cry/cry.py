from Crypto.Util.number import *
from Crypto.Cipher import AES
from hashlib import *
import random
import gmpy2
from secrets import iv, KEY


# I think you will definitely be interested in the content in PNG!
def banner():
    print(
        """
=======================================================================================
     _      _   _                 _           ____                                _   
    / \    | | (_)   ___    ___  ( )  ___    / ___|    ___    ___   _ __    ___  | |_ 
   / _ \   | | | |  / __|  / _ \ |/  / __|   \___ \   / _ \  / __| | '__|  / _ \ | __|
  / ___ \  | | | | | (__  |  __/     \__ \    ___) | |  __/ | (__  | |    |  __/ | |_ 
 /_/   \_\ |_| |_|  \___|  \___|     |___/   |____/   \___|  \___| |_|     \___|  \__|
                                                                                      
=======================================================================================
"""
    )


def pad(m):
    return m + (16 - (len(m) % 16)) * b"\x00"


def get_pngdata():
    with open("picture.png", "rb") as f:
        png_data = f.read()
    return pad(png_data)


def get_Key(bits):
    p = getPrime(bits)
    g = getPrime(bits // 2)
    d = random.randint(1, p - 2)
    y = pow(g, d, p)
    public, private = (p, g, y), d
    return public, private


def Signature(m, public, private):
    m = bytes_to_long(m)
    p, g, _ = public
    d = private
    while True:
        k = random.randint(1, p - 1)
        if gmpy2.gcd(k, p - 1) == 1:
            break
    r = pow(g, k, p)
    s = ((m - d * r) * inverse(k, p - 1)) % (p - 1)
    return (r, s)


def Verity(m, sign, public):
    m = bytes_to_long(m)
    p, g, y = public
    r, s = sign
    if pow(g, m, p) == (pow(y, r, p) * pow(r, s, p)) % p:
        return True
    else:
        return False


def chall():
    banner()

    pub, pri = get_Key(512)
    png_data = get_pngdata()
    print(
        "Hello! I'm Alice. To ensure that you are truly Bob, I need to verify your identity first!"
    )
    print("Can I help you sign once? Is there anything you need to sign?")
    print(f"Here are your public key:{pub}")
    message = long_to_bytes(int(input("Give me what you need to sign:")))
    if message == b"Bob":
        print("No, it's not possible!!!")
        exit(1)
    print("Here are your sign:")
    r, s = Signature(message, pub, pri)
    print(f"r = {r}")
    print(f"s = {s}")

    print("Tell me your signature so that I know you are truly Bob.")
    r = int(input("r = "))
    s = int(input("s = "))

    if Verity(b"Bob", (r, s), pub):
        print(
            "I have a great photo that I would like to share with you. Let's send it to you in our old way! Hope you still keep our IV!"
        )
        aes = AES.new(KEY, AES.MODE_CBC, iv)
        enc_data = hex(bytes_to_long(aes.encrypt(png_data)))[2:]
        print(f"Here is my encoded data:{enc_data}")
        print(f"Here is my key:{KEY.decode()}")
        print("In summary, I wish you a wonderful day!")
    else:
        print("Alright, you're not Bob, I don't have anything to chat with anymore.")
        exit(1)


if __name__ == "__main__":
    try:
        chall()
    except:
        exit(1)
