from math import sqrt

def isSquare(n):
    return sqrt(n) == int(sqrt(n))

def bruteforce(n):
    cnt = 0
    for i in range(1, n**2+1):
        if isSquare(n**2 + i**2) == True:
            x = i; y = int(sqrt(n**2 + i**2))
            # print(y-x, y+x)
            cnt += 1
    return cnt

n = int(input())

dvs = set()
for i in range(1, int(sqrt(n))+1):
    if n % i == 0:
        dvs.add(i)
        dvs.add(n//i)

cnt = 0
for d in dvs:
    s = n//d; S = n*d 
    if (S+s) % 2 == 0 and S != s:
        cnt += 1

# print(cnt)
print(bruteforce(n))
    