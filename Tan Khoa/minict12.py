from collections import defaultdict
import sys

def doDai(L, R):
	value = (R - L)//1 + 1
	return value

# input faster
input = sys.stdin.readline

n, k = map(int, input().split())
arr = list(map(int, input().split()))

cnt = defaultdict(lambda : 0)
# cnt để đếm số lần xuất hiện của một tử từ L -> R
# cnt[v] là số lần xuất hiện trong đoạn từ L -> R của v

L = 0; R = 0 # 2 biến đều chạy từ trái sang phải
# L và R biểu thị cho đoạn ta đang xét 
# Ta sẽ khiến cho đoạn này là |một đoạn dài nhất| có thể và là đoạn
# |hoàn hảo|

# biến R sẽ thực hiện nhiệm làm cho đoạn này dài hơn
# biến L sẽ giữ cho đoạn là một đoạn hoàn hảo 

# Khởi tạo biến số lượng số khác nhau hiện tại trong đoạn từ L -> R
diff = 0
resL = 0; resR = 0

while L <= R and R < len(arr):
	# phần tử tiếp theo đã xuất hiện trong đoạn rồi thì ta có thể
	# an tâm thêm nó vào đoạn từ L -> R
	if cnt[arr[R]] != 0 or diff < k:
		# Kiểm tra nếu phần tử thêm vào chưa xuất hiện lần nào
		if cnt[arr[R]] == 0:
			diff += 1
		cnt[arr[R]] += 1

		if doDai(resL, resR) < doDai(L, R):
			resL, resR = L, R

		R += 1 # thêm phần tử này vào đoạn L->R
	else:
		# Vứt bớt các phần tử bên trái để có thể tiếp tục
		# thêm vào các phần tử bên phải
		if cnt[arr[L]] == 1:
			diff -= 1
		cnt[arr[L]] -= 1
		L += 1

print(resL+1, resR+1)



