'''
Bước 1: Phân tích đề
Mỗi ô tô có một mã số.
Camera lưu lại tất cả mã số của các ô tô đã đi qua.
Dựa vào dữ liệu trong camera, đếm xem có bao nhiêu ô tô đã đi qua.

Bước 2: Kiểm tra lại test mẫu
2 4 2 5 4 5 2 5 4 5 5 -> 3
Bởi vì số lượng số khác nhau của mảng là 3

Bước 3: Xây dựng thuật toán
Để biết số lượng số khác nhau của mảng, ta sẽ dùng 
defaultdict để ta đếm.

Bước 4: Kiểm tra
'''


from collections import defaultdict
from sys import stdin

input = stdin.readline

oto = list(map(int, input().split()))

oto = set(oto)
# oto bây giờ chỉ chứa các ô tô khác nhau

print(oto)
print(len(oto))

'''
Cách 2:
- Nhiệm vụ cuối cùng của ta cũng chỉ là tìm số lượng 
số khác nhau trong một mảng thôi.
- Loại bỏ đi các số trùng nhau.
	--> Sử dụng hàm set()
Ví dụ: để loại bỏ các số khác nhau trong mảng arr:
	--> arr = set(arr)
	arr = {1, 2, 2, 3, 3}
	Sau khi arr = set(arr)
	arr = {1, 2, 3}
'''


exit()

'''
Cách 1
Thuật toán chi tiết:
Ta duyệt lại từng chiếc ô tô:
- Nếu nó chưa có trong defaultdict:
	Tăng số lượng lần mà ô tô này xuất hiện.
	Tăng số ô tô khác nhau.
- Nếu đã có trong defaultdict:
	Kệ nó
'''

d = 0
for car in oto:
	if cnt[car] == 0:
		cnt[car] += 1
		d += 1

print(d)


