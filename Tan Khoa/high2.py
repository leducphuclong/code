import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
boys = list(map(int, input().split()))
girls = list(map(int, input().split()))

boys.sort()
girls.sort()

# Khởi tạo 2 con trỏ
# Một con chạy trên mảng boys (i)
i = 0
# Một con chạy trên mảng girls (j)
j = 0

# tạo biến đếm số cặp
cnt = 0

while i < len(boys) and j < len(girls):
  if abs(boys[i] - girls[j]) <= k:
    cnt += 1
    i += 1; j += 1
  else: # abs(boys[i] - girls[j]) > k
    if boys[i] > girls[j]:
      j += 1
    else:
      i += 1

print(cnt)
