# The code is compressed by an algorithm
import hashlib

'''
I have a quantum computer and I use it to solve some of the problems in my work. The following is part of my work.
In order to protect the privacy of my work, all variable names have been replaced with simple letters. 
I believe you have also a quantum computer. Now please prove to me that you have a quantum computer.
'''

n = lambda q, r: q % r
x = lambda y, z: y**z
i = lambda j, k: j if not k else i(k, n(j, k))
l = lambda m: 1 if not m else m * l(m-1)
o = lambda p: x(2, p)
op = lambda p: o(p)+1
os = lambda p: o(p)-1
oh = lambda p: p*o(-1)
xp = lambda y, z: x(y, z)+1
xs = lambda y, z: x(y, z)-1
xt = lambda y: x(y, 2)


a1 = o(17*o(9))
a2 = os(a1)
b1 = o(17)
b2 = os(b1)
b3 = b1-1+o(10)-o(5)+17
b4 = os(b3-1)
c1 = o(o(13))
c2 = os(c1)
d = i(a2, c2)
e = i(b2, c2)
f1 = i(d+2, e+2)
f2 = xt(l(os(b3-2)))
f3 = xt(n(f2, b4))
f4 = 2*n(f3, b4)
f = f4*op(a2+f1+f4)
g = i(xp(f, a1), xs(f, c1))
h = x(x(xt(f1)*g, oh(f)*f4), b2)
flag = hashlib.md5(str(h)[1-b1:].encode()).hexdigest()
print(flag)
