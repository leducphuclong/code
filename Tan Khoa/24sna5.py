import sys

input = sys.stdin.readline

MOD = (int(1e9) + 7)

def sumSequence(first, last, step):
	return (first+last)%MOD*((last-first)//step + 1) // 2 % MOD

def squarePyramidalNumbers(n):
	return n*(n+1)*(2*n+1)//6%MOD


def findArea(n):
	l = 1; r = int(1e18)
	ans = -1
	while l <= r:
		guess = (l+r)//2
		if sumSequence(1, guess, 1) < n:
			ans = guess
			l = guess + 1
		else:
			r = guess - 1
	return ans+1


def S(n): # sum of the elements have index from 1 to n
	area = findArea(n)
	res = squarePyramidalNumbers(area-1)
	indexInArea = n - sumSequence(1, area-1, 1)
	res += indexInArea*area
	return res

a, b = map(int, input().split())
print(S(b) - S(a-1))



