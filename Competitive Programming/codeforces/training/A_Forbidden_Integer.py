# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def insr():
    s = input()
    return list(s[:len(s) - 1])

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Main function
for _ in range(inp()):
    n, k, x = invr()
    if x != 1:
        print("YES")
        print(n)
        for i in range(n):
            print(1, end = ' ')
        print()
        continue
    # x == 1
    if k == 1:
        print("NO")
        continue
    # x == 1 and k > 1
    if (k == 2):
        if n % 2 == 1:
            print("NO")
        else:
            print("YES")
            print(n // 2)
            for i in range(n//2):
                print(2, end = ' ')
            print()
        continue
    # x == 1 and k > 2 (n >= 3)
    ans = []
    while n > 0:
        if n % 2 == 1:
            n -= 3
            ans.append(3)
        else:
            n -= 2
            ans.append(2)
    print("YES")
    print(len(ans))
    print(*ans)
    