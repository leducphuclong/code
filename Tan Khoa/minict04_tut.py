                # Hướng dẫn bài minict04
                
# Phân tích một N thành tổng các số nguyên tố
# Sao cho số lượng số phân tích ra là nhiều nhất

# Số càng nhỏ phân tích được càng nhiều:
# Ví dụ: 8 = 3 + 5 = 2 + 2 + 2 + 2

# Ta sẽ hướng tới phân tích thành các số 2 và số 3.
# Vì 2 là số nguyên tố nhỏ nhất, sau đó đến 3

# Nếu n là số chẵn, thì ta in ra n//2 số 2
# Nếu n là số lẻ, thì ta in ra n//2-1 số 2 và 1 số 3
n = int(input())
print(n // 2)
if n % 2 == 0:
    print("2 " * (n//2))
else:
    print("2 " * (n//2 - 1) +  str(3))
    
