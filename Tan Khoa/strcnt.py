from collections import defaultdict

t = int(input()) # số lượng cases 

for _ in range(t):
  s = input()
  k = int(input())

  # Đếm xem bao nhiêu xâu con của s có các kí tự xuất hiện
  # không quá k lần.

  # khởi tạo defaultdict
  cnt = defaultdict(lambda:0)
  # cnt[v] sẽ là số lần xuất hiện của v

  n = len(s)


  left = 0; right = 0; ans = 0;
  while left <= right and right < n:
    # Kiểm tra xem có thêm được s[right]
    if cnt[s[right]] < k:
      # tăng số lần xuất hiện s[right]
      cnt[s[right]] += 1
      # công số lượng xâu con thõa mãn từ l->r vào ans 
      ans += right - left + 1
      # tăng biến right để thêm s[right]
      right += 1
    else:
      # giảm số lần xuất hiện của s[left]
      cnt[s[left]] -= 1
      # tăng biến left để loại bỏ s[left]
      left += 1

  # In kết quả ra
  print(ans)
