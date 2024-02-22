n = int(input())

# 1 phut = 60 s
# 1 gio = 60 phut = 60*60 = 3600s

h = n // 3600
n %= 3600
p = n // 60
n %= 60
g = n

print(":".join([str(h).rjust(2, "0"), str(p).rjust(2, "0"), str(g).rjust(2, "0")]))