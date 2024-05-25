s = input()
l = int(input())
r = int(input())
a = s + s[:: -1]
t = list(map(int, list(a)))
t = sum(t)
n = l - 1
tong = 0
if n < len(a):
  for i in range(0, n):tong += int(a[i])
else:
  l = n // len(a)
  tong += l * t
  m = n % len(a)
  for i in range(0, m):
    tong += int(a[i])
n = r
t1 = tong

print(t1)
tong = 0
if n < len(a):
  for i in range(0, n):tong += int(a[i])
else:
  print("hi")
  l = n // len(a)
  tong += l * t
  m = n % len(a)
  for i in range(0, m):
    tong += int(a[i])
print(tong - t1)