from math import sqrt, gcd

n, m = map(int,input().split())
# yêu cầu: đếm số lượng ước chung của n và m
# TÌm ước chung lớn nhất của n và m
# Ta nhận thấy: ước của ước chung lớn nhất cũng sẽ là
# ước của n và m.

# g là ước chung lớn nhất của n và m
g = gcd(n,m)

# đếm số lượng ước của g
cnt = 0 for i in range(1, int(sqrt(g)) + 1): if g % i == 0: d1 = i; d2 = g//i
if d1 == d2: cnt += 1 else: cnt += 2

print(cnt)
  



