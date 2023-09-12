# Copyright (c) 2023, Le Duc Phuc Long

# If you don't think twice, you have to code twice.

# Import session
import sys
from collections import defaultdict

############ ---- Input Functions ---- ############
def inp():
    return int(input())

def inlt():
    return list(map(int, input().split()))

def instr():
    return list(input().strip())

def invr():
    return map(int, input().split())

############ ---- Other Functions ---- ############
# Precompute
    
# Main function
# sys.stdin = open('in.txt', 'r')
for _ in range(inp()):
    # Input
    n = inp()
    a = inlt()
    b = inlt()
    # Count number of animals afraid of the animal a[i]
    cnt_afraid = [0]*n
    for i in range(n):
        a[i] -= 1
        cnt_afraid[a[i]] += 1
    # Put all animals don't afraid anyone into a list
    shelf = []
    for i in range(n):
        if not cnt_afraid[i]:
            shelf.append(i)
    # Sell all of those animals
    ans = [] # This list contains the order to sellings animals
    while shelf:
        sell_animal = shelf.pop()
        ans.append(sell_animal)
        cnt_afraid[a[sell_animal]] -= 1
        if cnt_afraid[a[sell_animal]] == 0:
            shelf.append(a[sell_animal])
    # Now we will iterate over all the cycles to add them to the ans list
    for u in range(n):
        if cnt_afraid[u]:
            # Find the cycle
            cycle = []
            v = a[u]
            while v != u:
                cycle.append([b[v], v])
                v = a[v]
            cycle.append([b[u], u])
            # Add it to ans optimally
            fin = min(cycle)[1]
            sta = a[fin]
            while sta != fin:
                ans.append(sta)
                cnt_afraid[sta] = 0
                sta = a[sta]
            ans.append(fin)
            cnt_afraid[fin] = 0
    print(*map(lambda x: x + 1, ans))
            
            
            
        
    
    