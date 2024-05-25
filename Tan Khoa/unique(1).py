'''
Hướng làm bài:
Bước 1: Phân tích đề
Cho dãy số nguyên a. Tìm phần tử xuất hiện 1 lần.

Bước 2: Kiểm tra test mẫu
7
1 2 1 5 3 3 5
-> Vì sao ra 2
Vì trong mảng trên, chỉ có số 2 xuất hiện 1 lần.

Bước 3: Xây dựng thuật toán:
- Nhập mảng A
- Đếm số lần xuất hiện của các phần tử trong mảng A
	- Dùng defaultdict
- Duyệt từng trong mảng A:
	- Kiểm tra xem số lần xuất hiện của phần tử đó bằng 1 không.
		- Nếu có thì in ra.
		- Ngược lại, duyệt số tiếp theo

Bước 4: Kiểm tra kết quả (Tự làm sau đó)
'''