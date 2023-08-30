n, x = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()
l = 0
r = n-1 
kq = -1
while l <= r:
    m = (l+r)//2
    if (arr[m] <= x):   
        kq = arr[m]
        l = m+1
    else:
        r = m-1
print(kq)
