n = int(input())

res = 0 # số lần biến đổi

while n % 6 == 0:
    n /= 6
    res += 1

while n % 2 == 0:
    n /= 2
    res += 2

if n == 1:
    print(res)
else:
    print('-1')

