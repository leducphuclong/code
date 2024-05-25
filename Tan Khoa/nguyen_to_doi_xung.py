# Copyright (c) 2023, Le Duc Phuc Long
 
# If you don't think twice, you have to code twice.
 
# Import session
import sys
from collections import defaultdict
import random
dice = random.SystemRandom() # A single dice
 
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
def multi(a, b, p):
    a %= p
    res = 0
    while b:
        if b & 1:
            res += a; res %= p
        a <<= 1; a %= p
        b >>= 1
    return res

def power(a, n, m):
    a %= m
    res = 1
    while n > 0:
        if n & 1:
            res = multi(res, a, m)
        n >>= 1
        a = multi(a, a, m)
    return (res + m) % m

def single_test(a, n):
    exp = n-1
    while not exp & 1:
        exp >>= 1
    tmp = power(a, exp, n)
    if tmp == 1:    
        return True
    while exp != n-1:
        if tmp == n-1:
            return True
        exp <<= 1
        tmp *= tmp; tmp %= n
    return False

def miller_rabin(n, t):
    # Corner cases
    if n <= 1 or n == 4:
        return False
    if n <= 3:
        return True;
    if n % 2 == 0:
        return False
    
    # if n < 2 or (n != 2 and n % 2 == 0):
    #   return False
    # if n == 2:
    #   return True
    for _ in range(t):
        a = dice.randrange(2, n-1)
        if not single_test(a, n):
            return False
    return True

# Precompute
LIM = int(1e3)+1
palin = []
for i in range(LIM):
    for j in range(10):
        if i != 0:
            palin.append(int(str(i) + str(j) + str(i)[::-1]))
        else:
            palin.append(int(j))
            
palin.append(11)
palin.sort()
palin_prime = []
for v in palin:
    if miller_rabin(v, 15):
        palin_prime.append(v) 
# IO
input = sys.stdin.readline
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

# Main function
n, m = invr()
ans = False
for v in palin_prime:
    if n <= v <= m:
        print(v)
        ans = True

if not ans:
    print(0)