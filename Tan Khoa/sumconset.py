import sys

# faster
input = sys.stdin.readline

def doDai(L, R):
	value = R-L + 1
	return value

n, t = map(int, input().split())
arr = list(map(int, input().split()))

L, R = 0, 0 # đoạn ta đang xét

cur_t = 0 # tổng hiện tại của đoạn L->R
len_max = 0 # độ dài của đoạn dài nhất thõa mãn 

while R < len(arr):
	if cur_t + arr[R] <= t:
		cur_t += arr[R]
		if doDai(L, R) > len_max:
			len_max = doDai(L, R)
		R += 1
	else:
		cur_t -= arr[L]
		L += 1

print(len_max)