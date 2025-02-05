from Crypto.Util.number import *

flag = b'XYCTF{******}'
n = ZZ(bytes_to_long(flag))
p = getPrime(int(320))
print(p)

G = Zmod(p)

def function(X, Y, Z):
    def part(a, b, c):
        return vector([9 * a - 36 * c, 6 * a - 27 * c, b])
    def parts(n):
        Gx.<a, b, c> = G[]
        if n == 0: return vector([a, b, c])
        mid = parts(n // 2)
        result = mid(*mid)
        if n % 2 == 0: return result
        else: return part(*result)
    return parts(n)(X, Y, Z)

print(function(69, 48, 52))


#1849790472911267366045392456893126092698743308291512220657006129900961168811898822553602045875909
#(1431995965813617415860695748430644570118959991271395110995534704629241309597572003500157255135707, 1011565891130611736600822618382801465506651972373410962205810570075870804325974377971089090196019, 784497518859893244278116222363814433595961164446277297084989532659832474887622082585456138030246)
