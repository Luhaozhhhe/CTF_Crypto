import os
from Crypto.Util.number import long_to_bytes,bytes_to_long
p = 74952228632990620596507331669961128827748980750844890766694540917154772000787
a = 7527668573755289684436690520541820188297794210531835381305219764577170135028
b = 23620438740221081546022174030845858657033205037887915215836562897142269481377
F_p = GF(p)
F_p2 = GF(p^2)
a,b = F_p2(a),F_p2(b)
E=EllipticCurve(F_p2,[a,b])
g=E.random_element()
sk=F_p.random_element()
pk=g*sk


def load_element(x1,x2):
    is_positive=(x1<p)
    x = F_p2([x1,x2])
    y2 = x^3+a*x+b
    if y2^((p^2-1)//2)==F_p2(-1):
        return None
    else :
        tmp = y2.square_root()
        #print((int(tmp)>(p-1)//2),is_positive)
        if (int(tmp[0])>(p-1)//2) ^^ is_positive : return E(x,tmp)
        else: return E(x,-tmp)

def compress_element(P):
    x,y=P.xy()
    return (int(x[0]),int(x[1])) if int(y[0])<=(p-1)//2 else (int(x[0])+p,int(x[1]))

def int_to32(x,l=17):
    b32dict="0123456789abcdefghijklmnopqrstuv"
    ret = ""
    while x>0:
        ret = b32dict[x%32]+ret
        x=x//32
    return "0"*max(0,l-len(ret))+ret

def enc_element(P):
    r = F_p.random_element()
    c2 = g*r
    c1 = pk*r+P
    ce1,ce2 = compress_element(c1),compress_element(c2)
    return "%065x%065x%065x%065x\n"%(*compress_element(c1),*compress_element(c2))
    #return int_to32(ce1[0])+int_to32(ce1[1])+int_to32(ce2[0])+int_to32(ce2[1])

def enc_str(s):
    enc_map,ret = {},""
    for c in s :
        if c in enc_map:
            cF_p2=enc_map[c]
        else :
            prefix = os.urandom(29)+bytes(c,encoding='ascii')
            x1 = int(F_p.random_element())
            for i in range(256):
                cF_p2 = load_element(x1,bytes_to_long(prefix+bytes([i])))
                if cF_p2!=None:
                    enc_map[c]=cF_p2
                    break
        ret = ret+enc_element(cF_p2)
    return ret

def dec_element(ct):
    c11,c12,c21,c22=[ct[i*65:i*65+65] for i in range(4)]
    C1,C2=load_element(int("0x"+c11,16),int("0x"+c12,16)),load_element(int("0x"+c21,16),int("0x"+c22,16))
    P=C1-C2*sk
    return (compress_element(P)[1]&0xffff)>>8

print("g = load_element(*"+str(compress_element(g))+")")
print("pk = load_element(*"+str(compress_element(pk))+")")
#g = load_element(*(29278822809335293856257839032454656006652898948724335358857767737708161772420, 4396426956433009559948787995869502944693089612343852188342374458334039665950))
#pk = load_element(*(148673571405127568767045322546948264768210305253661849398897382818523458361167, 23902769016595610010920651447268476259469689719718232568266731055385481225779))


with open("test_passage.txt","r") as f:
    s = f.readline().strip()


with open("ciphertext",'w') as f:
    f.write(enc_str(s))


