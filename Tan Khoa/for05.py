# Nhập n
n = int(input())

# Khác với bài trước vì ta kiểm tra số NT nên chỉ duyệt 
# từ 2 -> n-1, nhưng nếu làm như vậy với bài này ta sẽ 
# bị mất đi 2 ước là 1 và n
# Vì tìm tất cả ước của n nên ta duyệt từ 1 -> n

t = 0
for i in range(1, n+1):
    if n % i == 0:
        t += i

# Lưu ý cách làm này sẽ gặp lỗi TLE
# Nhưng với trình độ tiểu học, chỉ 
# dừng lượng kiến thức ngang đây

if t == 2*n: # Tổng các ước của n bằng 2 lần n
    print("YES") # Thì n là số hoàn hảo
else:
    print("NO") # Nếu không, n không phải là số hoàn hảo
