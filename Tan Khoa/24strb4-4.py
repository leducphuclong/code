n = int(input())
tmp = n
if n % 2 == 1:
    s, i = 1, 2
    while n > 1 and i*i <= tmp:
        if n % i == 0:
            p = 0
            while n % i == 0:
                n //= i
                p += 1
            s *= (p*2+1)
        i += 1
    if n > 1:
        s *= 2
    print(s//2)
else:
    s, i, p = 1, 2, 0
    while n % i == 0:
        n //= i
        p += 1
    s *= (p*2 - 1)
    i += 1
    while n > 1:
        if n % i == 0:
            p = 0
            while n % i == 0:
                n //= i
                p += 1
            s *= p*2+1
        i += 1
    print(s//2)
