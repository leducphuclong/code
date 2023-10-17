def ktNT(n):
  if n < 2: # Số nhỏ hơn 2 thì không phải số NT
    return False # Vì vậy ta trả về giá trị False
  
  # Ta tìm ước của n trong khoảng từ 2 -> n-1
  
  # Ta không tìm từ 1, vì n luôn chia hết cho 1
  # Ta không tìm từ n, vì n luôn chia hết cho n
  
  # Trong khoảng từ 2 -> n-1, nếu tồn tại một
  # số i là ước của n, tức n % i == 0
  
  # Thì ta biết n không phải số NT, bởi vì n có 3
  # ước là 1, n, và i (Số NT thì chỉ có 2 ước)
  
  # Vì vậy ta sẽ trả về False
  for i in range(2, n):
    if n % i == 0:
      return False
  
  # Lệnh return sẽ làm chương trình thoát ra
  # khỏi hàm khi được thực hiện.
  # Nên nếu chương trình chạy tới được đây
  # chứng tỏ chưa được return lần nào và
  # cũng không có i nào là ước thứ 3 của n 
  # Vì vậy n chỉ có 2 ước là 1 và n 
  # Suy ra n là sô Nguyên tố, ta return True
  return True

# Lưu ý cách làm này sẽ gặp lỗi TLE
# Nhưng với trình độ tiểu học, chỉ 
# dừng lượng kiến thức ngang đây
n = int(input())
if ktNT(n) == True:
  print("YES")
else:
  print("NO")
  
