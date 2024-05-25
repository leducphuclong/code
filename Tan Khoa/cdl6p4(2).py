
'''
Trước hết, phân tích yêu cầu đề

Kiểm tra lại các test mẫu 

Xây dựng thuật toán

Kiểm tra kết 
'''

from sys import stdin

input = stdin.readline

n, m = map(int, input().split())
A = list(map(str, input().split()))
B = list(map(str, input().split()))

C = A + B

C.sort()

print(*C)
