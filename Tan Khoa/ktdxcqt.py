n = int(input())
arr = input().split()

check = True
for i in range(n/2):
    if arr[i] != arr[n-1-i]:
        check = False

if check:
    print("TRUE")
else:
    print("FALSE")
