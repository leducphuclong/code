# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
# Nhập mảng a
a = list(map(int, input().split()))
n = len(a) # là độ dài của mảng

# Xây dựng mảng b
b = []
for i in range(n):
    if i % 2 == 0:
        b.append(a[i]+1)
    else:
        b.append(a[i])

# Đếm số lượng phần phần tử chẵn của 2 mảng
p, q = 0, 0
for i in range(n):
    if a[i] % 2 == 0:
        p += 1
    if b[i] % 2 == 0:
        q += 1

# In ra kết quả
if p < q:
    print("a it hon")
else:
    if p > q:
        print("b it hon")
    else:
        print("Bang nhau")
