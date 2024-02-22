# Copyright (c) 2023, Le Duc Phuc Long
 
# If you don't think twice, you have to code twice.
 
# Import session
import sys
import random 
from collections import defaultdict
from math import *
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
def is_prime(n):
	if (n <=1):
		return False
	if (n <= 3):
		return True 
	if n % 2 == 0 or n % 3 == 0:
		return False
	i = 5 
	while i * i <= n:
		if n % i == 0 or n % (i + 2) == 0:
			return False
		i += 6
	return True

def power(x, y, p):
     
    # Initialize result
    res = 1; 
     
    # Update x if it is more than or
    # equal to p
    x = x % p; 
    while (y > 0):
         
        # If y is odd, multiply
        # x with result
        if (y & 1):
            res = (res * x) % p;
 
        # y must be even now
        y = y>>1; # y = y/2
        x = (x * x) % p;
     
    return res;

def miillerTest(d, n):
     
    # Pick a random number in [2..n-2]
    # Corner cases make sure that n > 4
    a = dice.randrange(2, n-1)
 
    # Compute a^d % n
    x = power(a, d, n);
 
    if (x == 1 or x == n - 1):
        return True;
 
    # Keep squaring x while one 
    # of the following doesn't 
    # happen
    # (i) d does not reach n-1
    # (ii) (x^2) % n is not 1
    # (iii) (x^2) % n is not n-1
    while (d != n - 1):
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1):
            return False;
        if (x == n - 1):
            return True;
 
    # Return composite
    return False;

def isPrime(n, k):
     
    # Corner cases
    if (n <= 1 or n == 4):
        return False;
    if (n <= 3):
        return True;
 
    # Find r such that n = 
    # 2^d * r + 1 for some r >= 1
    d = n - 1;
    while (d % 2 == 0):
        d //= 2;
 
    # Iterate given number of 'k' times
    for i in range(k):
        if (miillerTest(d, n) == False):
            return False;
 
    return True;

# Precompute

# IO
input = sys.stdin.readline
#sys.stdin = open('in', 'r')
#sys.stdout = open('out', 'w')

# Main function
n, m = map(int, input().split())

max_half = int(1e4)
palin = []

for i in range(0, max_half+1):
	for j in range(0, 10):
		if (i != 0):
			palin.append(int(str(i) + str(j) + str(i)[::-1]))
		else:
			palin.append(int(str(j)))

# print(len(palin))
palin_prime = []
for v in palin:
	if isPrime(v, 10):
		palin_prime.append(v)

palin_prime.append(11)
ans = []
palin_prime.sort()
for v in palin_prime:
	if n <= v <= m:
		ans.append(v)

if (len(ans) == 0):
	print(0)
else:
	for i in range(len(ans)):
		print(ans[i])
