import sys

# sys.stdin = open("in.txt", "r")

tc = int(input())

for _ in range(tc):
    x, y, n = map(int, input().split())
    arr = [y]
    add = 1
    n -= 2
    for i in range(n):
        arr.append(arr[-1]-add)
        add += 1
    if (x+add > arr[-1]):
        print(-1)
        continue
    arr.append(x)
    arr = arr[::-1]
    print(*arr)
    
    
        
    