from math import sqrt

n = int(input())

dem = 0
tong = 0

for i in range(1, int(sqrt(n))+1):
    if n % i == 0:
        # thì mình sẽ có 2 ước là i và n//i
        dem += 2
        tong += i + n//i

if (float(sqrt(n)) == int(sqrt(n))):
    dem -= 1
    tong -= int(sqrt(n))

print(dem, tong)
    
