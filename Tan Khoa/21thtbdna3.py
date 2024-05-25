# 2x + y == n
# x < y  -> x < n/3
# 2x > y -> x > n/4

n = int(input())
print((n- (n%3 == 0))//3 - n//4)