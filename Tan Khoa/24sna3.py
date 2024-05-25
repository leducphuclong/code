import sys

def fastpow(a, b, m):
    if b == 0:
        return 1
    tmp = fastpow(a, b // 2, m)
    tmp = (tmp * tmp) % m
    if b % 2 == 1:
        tmp = (tmp * a) % m
    return tmp

def L(n, m):
    if n == 0:
        return 0
    return ((fastpow(2, n - 1, m) * 14) + fastpow(2, n, m) - 2) % m

m = 1000

cycle = [14]
for i in range(2, 1000):
    if (L(i, m)) == 14:
        break
    cycle.append(L(i, m))

def S(n):
    res = 0
    for i in range(n % len(cycle)):
        res += L(i+1, m)
    return sum(cycle)*(n//len(cycle)) + res

a, b = map(int, input().split())
print(S(b) - S(a-1))


        