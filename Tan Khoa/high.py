n, m, k = map(int, input().split())

boys = list(map(int, input().split()))
girls = list(map(int, input().split()))

boys.sort()
girls.sort()
  
iboy, igirl = 0, 0
ans = 0

while iboy < n and igirl < m:
    if abs(boys[iboy] - girls[igirl]) <= k:
        ans += 1
        iboy += 1; igirl += 1
    else: # abs(boys[iboy] - girls[igirl]) > k
        if boys[iboy] - girls[igirl] > k:
            igirl += 1
        else: # girls[igirl] - boys[iboy] > k
            iboy += 1

print(ans)
            
