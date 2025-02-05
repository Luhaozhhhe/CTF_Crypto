def f(a, b, p):
    t = 0
    for i in range(len(b)):
        t += pow(a, i, p) * b[i] % p
    return t % p

p = 1041231053

a = open("flag.png", "rb").read()
b = open("enc.txt", "w")
for i in range(len(a)):
    b.write(str(i) + str(f(i, a, p)) + "\n")
