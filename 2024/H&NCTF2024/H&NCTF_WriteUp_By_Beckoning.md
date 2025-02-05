# <center>H&NCTF WriteUp By Beckoning</center>



# Crypto

## ==BabyPQ==

进入端口，得到我们的$n$和$phi$

我们已知$n=p\times q,phi=(p-1)\times (q-1)$​

```python
n= 49591977487629594945496373438511006111775528534545574233225149697175329748553605568368963756920661135425024807876418929312382617151908592963419269275343863166615811689723484880951512308750038206562522283030655840533891416358727464163458870504250389804872146353448401968369599477838528162180039236966333218441 
phi=49591977487629594945496373438511006111775528534545574233225149697175329748553605568368963756920661135425024807876418929312382617151908592963419269275343849077869099594315012439173163522525652948396478054170312697035143915818749650675143752409819847997605469066583155373813828741099849410231696320264247769492

from sympy import *
x,y= symbols('x,y')
print(solve([x*y-n,(x-1)*(y-1)-phi],[x,y]))
```

通过解方程，我们就可以得到我们的$p$和$q$

然后输入我们的$p$就可以了，得到$flag$

![屏幕截图 2024-05-12 094824](E:\学学学\竞赛\CTF（寒假学密码方向）\比赛\H&NCTF2024\H&NCTF_WriteUp_By_Beckoning.assets\屏幕截图 2024-05-12 094824.png)

$flag$的值为：`H&NCTF{af7051cd-2cd6-424e-8413-a65926c77e5c}`



## f=(?*?)

```
ve9MPTSrRrq89z+I5EMXZg1uBvHoFWBGuzxhSpIwu9XMxE4H2f2O3l+VBt4wR+MmPJlS9axvH9dCn1KqFUgOIzf4gbMq0MPtRRp+PvfUZWGrJLpxcTjsdml2SS5+My4NIY/VbvqgeH2qVA==
```

先看我们的第一个文件，应该是某种加密方式，最后的hint提示我们e=65537，那么这应该是一个RSA的题

我们先拿两个文件进行p和q的恢复，然后再用base64解码我们的c，然后用rsa就可以了

```python
from Crypto.Util.number import *
import base64
c = bytes_to_long(base64.b64decode('ve9MPTSrRrq89z+I5EMXZg1uBvHoFWBGuzxhSpIwu9XMxE4H2f2O3l+VBt4wR+MmPJlS9axvH9dCn1KqFUgOIzf4gbMq0MPtRRp+PvfUZWGrJLpxcTjsdml2SS5+My4NIY/VbvqgeH2qVA=='))
print(c)

#c=1392517954149210143046166598536580473709804889004367750224799583342366746945269042563810317766379927582147833579154433523418182045532213536601363507250880824145219423178104814092814668934984639409837696728581442174824753521241162591905087892716583873522260

p = int(''.join(['1' if i[0]=='3' else '0' for i in open('file1.txt','r').read().split('\n') ]),2)
q = int(''.join(['1' if i[0]=='6' else '0' for i in open('file2.txt','r').read().split('\n') ]),2)

#p=57357445697656305449852658985072306792176526325401427689338172257827853689473430283849367024117704513636066741450894144354439223 
#q=89992838080292432041749786501934273286234288253944531238372481458518903256335509625431026718322552331965908097158513049639942869

p=57357445697656305449852658985072306792176526325401427689338172257827853689473430283849367024117704513636066741450894144354439223 
q=89992838080292432041749786501934273286234288253944531238372481458518903256335509625431026718322552331965908097158513049639942869
c=1392517954149210143046166598536580473709804889004367750224799583342366746945269042563810317766379927582147833579154433523418182045532213536601363507250880824145219423178104814092814668934984639409837696728581442174824753521241162591905087892716583873522260
phi=(p-1)*(q-1)
n=p*q
e=65537
from gmpy2 import *
from Crypto.Util.number import *
d=invert(e,phi)
print(long_to_bytes(pow(c,d,n)))

#b'H&NCTF{Y0u_s@cce3d3d_in_finding_the_meaning_0f_these_d0cuments}'
```

得到我们的flag：

```
H&NCTF{Y0u_s@cce3d3d_in_finding_the_meaning_0f_these_d0cuments}
```



## Is this ISO

```python
from Crypto.Util.number import *
from random import *
from secret import flag

def nextPrime(p):
    while(not isPrime(p)):
        p += 1
    return p


#part1 gen Fp and init supersingular curve
while(1):
    p = 2^randint(150,200)*3^randint(100,150)*5^randint(50,100)-1
    if(isPrime(p)):
        break

F.<i> = GF(p^2, modulus = x^2 + 1)
E = EllipticCurve(j=F(1728))
assert E.is_supersingular()


#part2 find a random supersingular E
ways = [2,3,5]
for i in range(20):
    P = E(0).division_points(choice(ways))[1:]
    shuffle(P)
    phi = E.isogeny(P[0])
    E = phi.codomain()


#part3 gen E1 E2 E3
E1 = E

deg1 = 2
P = E1(0).division_points(deg1)[1:]
shuffle(P)
phi1 = E1.isogeny(P[0])
E2 = phi1.codomain()

deg2 = choice(ways)
P = E2(0).division_points(deg2)[1:]
shuffle(P)
phi2 = E2.isogeny(P[0])
E3 = phi2.codomain()


#part4 leak
j1 = E1.j_invariant()
j2 = E2.j_invariant()
j3 = E3.j_invariant()

m = bytes_to_long(flag)
n = getPrime(int(j3[0]).bit_length())*nextPrime(int(j3[0]))

print("p =",p)
print("deg1 =",deg1)
print("deg2 =",deg2)
print("leak1 =",j1[0] >> 400 << 400)
print("leak2 =",j1[1] >> 5 << 5)
print("leak3 =",j2[0] >> 5 << 5)
print("leak4 =",j2[1] >> 400 << 400)
print("n =",n)
print("cipher =",pow(m,65537,n))
```

output:

```python
p = 680201537161531317827869565786140240595567913096417274637134403255116055511280864892266374758399999999999999999999999999999999999999999999999999999999999999999999999
deg1 = 2
deg2 = 5
leak1 = 84624382514957324426794167416980084161297449460045164807842311763375830274875400809588635343195174135691613055453493035516696630357254763624394674275492513550696448
leak2 = 569334021319485756763137861791243638993859221789562816154577308542976649646202822945301844698450579193326962681107954744030417590603938838204734858601313640848501344
leak3 = 325720000771917646719671745106544502680895911477018701616420509369836768451047103170212051953041518446572892754419417720965474892312189833039602545011787135282170400
leak4 = 607188653779811312711900086497209011406043384341389739547214249680956969386970129072753246609362372591781044704784040165947962309186896993435085198595013761765998592
n = 336631348442872227475735277623305104458216242371136122513108670525622121689052346348620824105820633714562546800934735845952338946486424402720093748392510487705996344393513464710255615634248631016778273746776059762111364616763243266453211367983670687473800622632626192654424964609849049774336197739675356042226277067017714668077407
cipher = 98106149415612242984147419198102021164901863054603625014502538888604192644391041028562541950192883864954991703087157292974235031070431515337932833347213492206351147110891983722997746801220179144171968380355798405953558533823282395282563952623698461579297014597381904081095895011393305504119244812232164909852287688815879984263470
```



## EZmath

```python
#sage9.3
from Crypto.Util.number import *
flag = b'Kicky_Mu{KFC_v_me_50!!!}'
p = getPrime(256)
q = getPrime(256)
n = p*q^3
e = # what is usually used ?
N = pow(p, 2) + pow(q, 2)
m = bytes_to_long(flag)
c = pow(m,e,n)

print(c)
print(N)

# c = 34992437145329058006346797890363070594973075282993832268508442432592383794878795192132088668900695623924153165395583430068203662437982480669703879475321408183026259569199414707773374072930515794134567251046302713509056391105776219609788157691337060835717732824405538669820477381441348146561989805141829340641
# N = 14131431108308143454435007577716000559419205062698618708133959457011972529354493686093109431184291126255192573090925119389094648901918393503865225710648658
```

我们直接用sage分解我们的p和q，然后做正常的RSA attack就可以了

```python
p=82560919832754349126354116140838623696638559109075709234619471489244325313113
q=85528507672457684655471526239900307861713918212607409966382024323034858694833
phi=(p-1)*(q-1)*q**2
from gmpy2 import *
e=65537
n=p*q**3
d=invert(e,phi)
from Crypto.Util.number import *
c=34992437145329058006346797890363070594973075282993832268508442432592383794878795192132088668900695623924153165395583430068203662437982480669703879475321408183026259569199414707773374072930515794134567251046302713509056391105776219609788157691337060835717732824405538669820477381441348146561989805141829340641
m=pow(c,d,n)
print(long_to_bytes(m))
#b'H&NCTF{D0_Y0u_know_Complex_n3mbers?hahaha}'
```

得到我们最后的flag

```
H&NCTF{D0_Y0u_know_Complex_n3mbers?hahaha}
```



## BabyAES

```python
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from secret import flag
import time
import random

flag = pad(flag,16)
assert b"H&NCTF" in flag

seed = int(time.time())
random.seed(seed)
key = random.randbytes(16)
iv = random.randbytes(16)
aes = AES.new(key,AES.MODE_CBC,iv)
cipher = aes.encrypt(flag)

print(f"cipher = {cipher}")

"""
cipher = b'\x96H_hz\xe7)\x0c\x15\x91c\x9bt\xa4\xe5\xacwch\x92e\xd1\x0c\x9f\x8fH\x05\x9f\x1d\x92\x81\xcc\xe0\x98\x8b\xda\x89\xcf\x92\x01a\xe1B\xfb\x97\xdc\x0cG'
"""
```



## ez_Classic

```python
𠣔𠧆𣣠𥪕鶪𢻠𥮚𤪍𥮱𤮵𤶋𦚤𡲪𢫐𢷊𡧕𢛠𦒌蒗𣯠𦖎骩𢻠𥮫𤪍𥢦𤮰𤲋𦚽𠚠𡓝𢷊𦙭𡎸𣛒𣋑𠻔𢛠𤺀𦚽𡾤𢳠𤪐𥪦𦚂𡮨𡻉𣃒𤃈𢻠𦖪𦂟𥢳蒿𣫠𦖢骩𣃠𥮣𤪍𥢱𦚰𡮨𠣉𣃠𥚖𥚤𦖏𥖟𥮀蒴𣫠𦚖𡆤𦙴𢂤𢇆𠛏𢋊𢻠𤲢𥢽𦚫𣂼𢗊𠣊𡟎𣛒𢻠𦚝𡮲𢟠𤾊𤲄𥮸𦂑𥂹𤾜𥮪𥢏𤺪𦚻𡖨𢗟𣧚𠟔𦙏𡲴𣃠骔𣻆𦙯𢚡𢋊𠧆𣫠𥢢𦚭𣾶
```

先用我们的base65536解密

```
ԂƃಕԪhਚՍıյŋǤખФʧՓࠌޗOൎߩeਫՍĦҰŋƽࠀݎʧmญҰѬԈࠀȽङঐĦԂਕɘҪȺਪߟڳҿOഢߩeણՍıҰਕɂખФЏߟπմOഖऋtचƛπʜਢƽҫ༪ʟʂΑҰਝಕࡊɄƸՑڹʜɪՏҪȻਏߟڳԁOഖઔeƸoࡠʜƃഢҭඹ
```

得到：

```
GAC & GCT CTA GTC CTT { CTA AGT AAA CAG CAG AGA AAG & AGT _ AAG CAC CGA ATT CAT TTC _ AGT CAG _ CAG TTC _ AGA ATC CAT TCG CAC ACA CAG CAT @ ATC ACG }
```

这就很像我们最后的flag了，我们再用我们的DNA解密

```python
c ="GAC & GCT CTA GTC CTT { CTA AGT AAA CAG CAG AGA AAG & AGT _ AAG CAC CGA ATT CAT TTC _ AGT CAG _ CAG TTC _ AGA ATC CAT TCG CAC ACA CAG CAT @ ATC ACG }"
dic = 'ACGT'
d = ''
for i in c.split():
    if len(i)==3:
        v = dic.index(i[0])*16 + dic.index(i[1])*4 + dic.index(i[2])
        if v<26:
            d += chr(0x61 + v)
        elif v<52:
            d += chr(0x41 + v-26)
        else:
            d += chr(0x30 + v-52)
    else:
        d += i 
    print(d)          
```

得到：

```
H&NCTF{Classic&l_crypt9_ls_s9_int2rest@ng}
```



## Is this ISO2

```python
from Crypto.Util.number import *
from random import *
from secret import flag

def nextPrime(p):
    while(not isPrime(p)):
        p += 1
    return p


#part1 gen Fp and init supersingular curve
while(1):
    p = 2^randint(250,300)*3^randint(200,250)*5^randint(150,200)-1
    if(isPrime(p)):
        break

F.<i> = GF(p^2, modulus = x^2 + 1)
E = EllipticCurve(j=F(1728))
assert E.is_supersingular()


#part2 find a random supersingular E
ways = [2,3,5]
for i in range(20):
    P = E(0).division_points(choice(ways))[1:]
    shuffle(P)
    phi = E.isogeny(P[0])
    E = phi.codomain()


#part3 gen E1 E2 E3
E1 = E

deg1 = 2
P = E1(0).division_points(deg1)[1:]
shuffle(P)
phi1 = E1.isogeny(P[0])
E2 = phi1.codomain()

deg2 = 5
P = E2(0).division_points(deg2)[1:]
shuffle(P)
phi2 = E2.isogeny(P[0])
E3 = phi2.codomain()


#part4 leak
unknown = 48
j1 = E1.j_invariant()
j2 = E2.j_invariant()
j3 = E3.j_invariant()

m = bytes_to_long(flag)
n = getPrime(int(j3[0]).bit_length())*nextPrime(int(j3[0]))

print("p =",p)
print("leak1 =",j1[0] >> unknown << unknown)
print("leak2 =",j1[1] >> unknown << unknown)
print("leak3 =",j2[0] >> unknown << unknown)
print("leak4 =",j2[1] >> unknown << unknown)
print("n =",n)
print("cipher =",pow(m,65537,n))
```



## ==MatrixRSA==

```python
from Crypto.Util.number import *
import os

flag = b"H&NCTF{??????????????}" + os.urandom(73)

p = getPrime(56)
q = getPrime(56)
n = p * q

part = [bytes_to_long(flag[13*i:13*(i+1)]) for i in range(9)]

M = Matrix(Zmod(n),[
    [part[3*i+j] for j in range(3)] for i in range(3)
])

e = 65537
C = M ** e
print(f"n = {n}")
print(f"C = {list(C)}")

"""
n = 3923490775575970082729688460890203
C = [(1419745904325460721019899475870191, 2134514837568225691829001907289833, 3332081654357483038861367332497335), (3254631729141395759002362491926143, 3250208857960841513899196820302274, 1434051158630647158098636495711534), (2819200914668344580736577444355697, 2521674659019518795372093086263363, 2850623959410175705367927817534010)]
"""
```

文献题，查阅关键词Matrix和RSA就可以找到对应的论文

我们只需要将我们的欧拉函数进行替换就可以了

exp：

```python
from gmpy2 import *
from Crypto.Util.number import *
import numpy
p=56891773340056609
q=68964114585148667
n=p*q
e=65537
phi=(p**2-1)*(p**2-p)*(q**2-1)*(q**2-q)
d=invert(e,phi)
C = [(1419745904325460721019899475870191, 2134514837568225691829001907289833, 3332081654357483038861367332497335), (3254631729141395759002362491926143, 3250208857960841513899196820302274, 1434051158630647158098636495711534), (2819200914668344580736577444355697, 2521674659019518795372093086263363, 2850623959410175705367927817534010)]
#C = Matrix(Zmod(n),[
 #   [(1419745904325460721019899475870191, 2134514837568225691829001907289833, 3332081654357483038861367332497335), (3254631729141395759002362491926143, 3250208857960841513899196820302274, 1434051158630647158098636495711534), (2819200914668344580736577444355697, 2521674659019518795372093086263363, 2850623959410175705367927817534010)]
#])
#print(numpy.linalg.matrix_power(C, d) )

print(d)
```

```python
import numpy as np
def mod_matrix_multiply(A, B, n):
    # 在模 n 的有限域上计算矩阵乘法
    C = np.dot(A, B) % n
    return C

def mod_matrix_power(A, power, n):
    # 计算矩阵 A 的幂
    result = np.eye(len(A), dtype=int)  # 创建单位矩阵
    while power > 0:
        if power % 2 == 1:
            result = mod_matrix_multiply(result, A, n)
        A = mod_matrix_multiply(A, A, n)
        power //= 2
    return result

C = [(1419745904325460721019899475870191, 2134514837568225691829001907289833, 3332081654357483038861367332497335), (3254631729141395759002362491926143, 3250208857960841513899196820302274, 1434051158630647158098636495711534), (2819200914668344580736577444355697, 2521674659019518795372093086263363, 2850623959410175705367927817534010)]
n=3923490775575970082729688460890203
d=62943786360045783729872631416452305443726414552945421595258301764271056603535020810729178005843237877043494288357220800501261583450113
print(mod_matrix_power(C,d,n))
```

这样我们就可以求出原来的矩阵了，然后我们进行字符转化就可以得到我们的flag了

```
H&NCTF{58bff5c1-4d5f-4010-a84c-8fbe0c0f50e8}
```



## HappyDance

```python
#!/usr/bin/env python3
from chacha20 import *
from Crypto.Util.number import long_to_bytes, bytes_to_long
from secret import flag, mykey, mynonce

def chacha_init(key, nonce, counter):
    assert len(key) == 32
    assert len(nonce) == 8

    state = [0 for _ in range(16)]
    state[0] = bytes_to_long(b"expa"[::-1])
    state[1] = bytes_to_long(b"nd 3"[::-1])
    state[2] = bytes_to_long(b"2-by"[::-1])
    state[3] = bytes_to_long(b"te k"[::-1])

    key = bytes_to_long(key)
    nonce = bytes_to_long(nonce)
    
    for i in range(8):  
        state[i+4] = key & 0xffffffff
        key >>= 32

    state[12] = (counter >> 32) & 0xffffffff
    state[13] = counter & 0xffffffff
    state[14] = (nonce >> 32) & 0xffffffff
    state[15] = nonce & 0xffffffff

    return state


def encrypt(data):
    global state
    state = chacha_block(state)
    buffer = b"".join(long_to_bytes(x).rjust(4, b"\x00") for x in state)
    output = []
    for b in data:
        output.append(b ^ buffer[0])
        buffer = buffer[1:]

    return bytes(output)

FLAG = b"H&NCTF{****FAKE****}"
MYNONCE =b"sdf*h*o*"
assert len(flag) == 64
assert len(mynonce) == 8

if __name__ == "__main__":
    while True:
        print("""================================
Enjoy the happiness of dancing
1. Dance on My Stage
2. Dance on Your Stage
3. Encrypt flag
""")
        choice = input("> ")

        if choice == '1':
            state = chacha_init(mykey, mynonce, 0)
            print(encrypt(input("input what you want to dance on my stage > ").encode()).hex()) 

        elif choice == '2':
            yournonce = input("build your own stage > ")
            assert len(yournonce) == 8
            state = chacha_init(mykey, yournonce.encode(), 0)
            yourIn = bytes.fromhex(input("then, have a hex dance > "))
            print(encrypt(yourIn).hex())
            
        elif choice == '3':
            state = chacha_init(mykey, mynonce[::-1], 0)  
            print(encrypt(flag).hex())

        else:
            print("Let's dance together next time~")
            exit()
```



# Misc

## 签到

直接发送公众号，获得我们的第一个$flag$

$flag$=`H&NCTF{W3lc0me_4o_H&NCTF2024!}`

