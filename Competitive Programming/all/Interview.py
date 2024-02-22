from sys import stdout

T = int(input())
while T > 0:
    T -= 1
    n = int(input())
    arr = list(map(int, input().split()))
    pfs = [0]*1
    for x in arr:
        pfs.append(pfs[-1]+x)
    l, r = 1, n
    while l < r:
        m = (l+r) // 2
        qrr = [x for x in range(l, m+1)]
        qrr.insert(0, m-l+1)
        print("?", *qrr)
        rps = int(input())
        if rps == pfs[m] - pfs[l-1]:
            l = m+1
        else:
            r = m
    print("!", l)
