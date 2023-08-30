# Copyright (c) 2023, Le Duc Phuc Long
"""
If you don't think twice, you have to code twice.
"""
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)

tong_am = 0
so_luong_am = 0
for v in arr:
    if v < 0:
        tong_am += v
        so_luong_am += 1


if so_luong_am != 0:
    trung_binh_cong = tong_am/so_luong_am
    print(format(trung_binh_cong, ".2f"))
else:
    print(-1)

