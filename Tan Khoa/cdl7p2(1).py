'''
Hướng làm bài:
Bước 1: Phân tích đề
Xây dựng mảng B từ mảng A (nhập vào). Theo quy tắc:
i = 0 -> len(A)-1
Nếu i chẵn --> B[i] = A[i] + 1
Nếu i lẻ   --> B[i] = A[i]

Bước 2: Kiểm tra test mẫu
A: 5 3 2 2 1 2 
Sau khi xây dựng, ta có:
B: 6 3 3 2 2 2

Mảng A có bao nhiêu số chẵn: 3
Mảng B có bao nhiêu số chẵn: 4

Vậy mảng A có ít số chẵn hơn mảng B
--> In ra "A ít hơn" (Như vậy test đúng theo yêu cầu đề)

Bước 3: Xây dựng thuật toán:
- Nhập mảng A
- Xây dựng mảng B, theo quy tắc của đề.
- Đếm số lượng số chẵn của mảng A và mảng B.
- So sánh số lượng lượng chẵn của mảng A và B. 
- In ra kết quả.

Bước 4: Kiểm tra kết quả (Tự làm sau đó)
'''

A = list(map(int, input().split()))



