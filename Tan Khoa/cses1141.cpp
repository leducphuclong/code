from collections import defaultdict

n = int(input())
arr = list(map(int, input().split()))

cnt = defaultdict(lambda: 0)

# Khởi tạo 2 con trỏ left, right và biến kết quả
left=0; right=0; max_len = 0

# Sử dụng câu while để thực hai con trỏ với điều kiện 
# phù hợp 
while left<= right < n:
  # Kiểm tra xem có thêm được arr[right] không?
  if cnt[arr[right]] < 1:
    # --> Nếu thêm được

    # tăng số lần xuất hiện của arr[right]
    cnt[arr[right]] += 1 

    # Cập nhật đồ dài của dãy thõa mãn dài nhất
    cur_len = right - left + 1
    if cur_len > max_len:
      max_len = cur_len

    # thêm arr[right] vào xâu L->R bằng cách tăng right 
    right += 1 
  # Ngược lại
  else:
    # --> Nếu không thêm được
    # giảm số lần xuất hiện của phần arr[left]
    cnt[arr[left]] -= 1
    # loại bỏ phần arr[left] ra khỏi đoạn L-R
    left += 1

# In ra kết quả
print(max_len)
