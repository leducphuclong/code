import math
n = int(input())
res = []
for i in range(1, int(math.sqrt(n))+1):
    if (n % i == 0):
        res.append(i)
        if (i*i != n):
            res.append(int(n/i))
res.sort()
print(" ".join(map(str, res)))  

