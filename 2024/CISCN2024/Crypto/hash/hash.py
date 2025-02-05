#!/usr/bin/python2
# Python 2.7 (64-bit version)
from secret import flag
import os, binascii, hashlib
key = os.urandom(7)
print hash(key)
print int(hashlib.sha384(binascii.hexlify(key)).hexdigest(), 16) ^ int(binascii.hexlify(flag), 16)
