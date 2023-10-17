'''
Đề bài: 
-   Cho 3 số L, R, M
-   Tìm số dư d nhỏ nhất, trong đó d là số dư của tích 2 số 
bất kì trong đoạn các số liên tiếp từ L -> R sau khi chia cho M
-   Tìm d nhỏ nhất sao cho:
    i*j % M == d (L <= i, j <= R)

Hướng dẫn giải:
-   Ta đã biết răng, khi chia lấy dư cho M thì kết quả trả về
nằm trong đoạn [0, M-1].
-   Buổi trước ta cũng đã chứng minh được rằng, trong một
đoạn gồm M số liên tiếp (hoặc hơn M số liên tiếp) thì sẽ luôn
có một số chia hết cho M, tức là kết quả phép dư = 0.
    -> Dựa vào điều này, ta kiểm tra nếu đoạn L->R chứa M số
trở lên, ta in ra 0. (0 là giá trị nhỏ nhất của một phép chia
lấy dư)

- Ngược lại, tức đoạn L->R chứa ít hơn M số thì sao, ta chú
ý vào ràng buộc của bài. (M <= 2000)
    => Đoạn từ L tới R chứa ít hơn 2000 số
    => Với ít hơn 2000 số, ta dễ dàng tính được bằng cách
    dùng 2 vòng for lồng nhau tương tự phiên bản dễ của bài.
'''

L, R, M = map(int, input().split())

SSH = R-L+1
if SSH >= M:
    print(0)
else:
    mn = 99999999999
    for i in range(L, R+1):
        for j in range(L, R+1):
            if i < j:
                du = i*j % M
                mn = min(du, mn)
    print(mn)
