# Sau khi sắp xếp mảng tăng dần

# Mảng có dạng:
# số nhỏ nhất, số nhỏ nhì, ..., số lớn nhì, số lớn nhất

# Nếu lấy số: (lớn nhất - nhỏ nhất)*(lớn nhì - nhỏ nhì)
# Thì ta thấy hiệu thứ nhất lớn, nhưng mà hiệu thứ 2 sẽ nhỏ
# Nên lấy số: (lớn nhất - nhỏ nhì)*(lớn nhì - nhỏ nhất)

# Sau khi sắp xếp mảng a tăng dần:
# số nhỏ nhất: a[0]
# số nhỏ nhì: a[1]
# số lớn nhì: a[len(a)-2] hoặc a[-2]
# số lớn nhất: a[-1]
arr.sort()
print((lớn nhất - nhỏ nhì)*(lớn nhì - nhỏ nhất))


