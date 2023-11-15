from math import *

n = int(input())
arr = list(map(int, input().split()))

g = 0 # UCLN của mảng arr
# chạy từng phần tử trong arr
    # gán g = gcd(g, v) ( v là phần tử của arr)

# khởi tạo d = -1 # ước nhỏ nhất của g
# Tìm ước nhỏ nhất của g
# chạy i từ 2 đến g(+1)
    # nếu i là ước của g
        # đặt d = i
        # dừng lại bằng lệnh break để lấy giá trị nhỏ nhất

print(d)


