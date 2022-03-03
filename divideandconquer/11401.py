Mod = 1000000007

n, k = map(int, input().split())

def fact(a):
    res = 1
    while a >= 1:
        res *= a
        a -= 1
        res %= Mod

    return res

def dcpow(a, p):
    res = 1
    while p:
        if p & 1:
            res *= a
            res %= Mod
        a *= a
        a %= Mod
        p >>= 1

    return res

print((fact(n)*dcpow(fact(k), Mod-2)*dcpow(fact(n-k), Mod-2))%Mod)