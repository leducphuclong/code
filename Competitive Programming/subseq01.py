testcase = int(input())
for i in range(testcase):
    n = int(input())
    arr = list(map(int, input().split()))
    
    pfs = [0]
    s = 0
    for value in arr:
        pfs.append(pfs[-1] + value)
        if value > 0:
            s += value
    
    pfsmin = [99999999999]
    for value in pfs:
        pfsmin.append(min(pfsmin[-1], value))
    
    
    mav = -999999999999;
    for i in range(1, n+1):
        if (pfs[i] - pfsmin[i] > mav):
            mav = pfs[i] - pfsmin[i]
    
    print(s, mav)