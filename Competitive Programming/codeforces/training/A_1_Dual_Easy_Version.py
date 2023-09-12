tc = int(input())

for _ in range(tc):
    n = int(input())
    arr = list(map(int, input().split()))
    mav = -9999999999999
    loc = -1
    for i in range(n):
        if arr[i] > mav:
            mav = arr[i]
            loc = i
            
    opr = []
    if mav <= 0:
        for i in range(n-2, -1, -1):
            opr.append([i, i+1])
    else:
        for i in range(5):
            opr.append([loc, loc])
        for i in range(n):
            if i != loc:
                opr.append([i, loc])
        for i in range(1, n):
            opr.append([i, i-1])
    print(len(opr))
    for v in opr:
        print(v[0]+1, v[1]+1)
