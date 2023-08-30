n=int(input())
a=list(map(int, input().split()))
b=[0]
c=[0]
d=-9999999999999999
for i in range(0,n):
  b.append(b[-1]+a[i])
for i in range(0,n):
  c.append(min(c[-1],b[i]))
for i in range(0,n+1):
  d=max(d,b[i]-c[i])

print(b)
print(c)
print(d)
