n = int(input())
a = []
for i in range(n):
    x = int(input())
    if (x > 0):
        a.append(x)
print(len(a), sum(a))
