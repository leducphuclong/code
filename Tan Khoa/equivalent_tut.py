# Ví dụ có 2 xâu:
# (1) aaabbccc
# (2) baacccc

# Ta sẽ sử dụng hàm count để đếm số lần xuất hiện của các
# kí tự trong cả 2 xâu
# Lưu ý: là mỗi kí tự chỉ đếm 1 lần


s1 = input()
s2 = input()

s = str(set(s2)) # lệnh sẽ xóa đi các phần tử trùng nhau
# Lưu ý: set có thể không dùng for được
ans = 0
for c in s:
    if ...: # dùng hàm count đếm số lượng kí tự c
            # trong cả 2 xâu
    # Nếu bên nào ít kí tự c hơn thì đó là số lượng kí tự
    # c giống nhau, ta cộng nó vào ans
        

