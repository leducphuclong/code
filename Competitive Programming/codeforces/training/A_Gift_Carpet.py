tc = int(input())
for _ in range(tc):
    # Input
    n, m = map(int, input().split())
    arr = []
    for i in range(n):
        s = input()
        arr.append(s)
    # Solve
    name = ""
    for i in range(m):
        added = False
        for j in range(n):
            if arr[j][i] == 'v' and len(name) == 0:
                name += arr[j][i]
                added = True
            elif added == False and len(name) != 0 and arr[j][i] == 'i' and name[-1] == 'v':
                name += arr[j][i]
                added = True
            elif added == False and len(name) != 0 and arr[j][i] == 'k' and name[-1] == 'i':
                name += arr[j][i]
                added = True
            elif added == False and len(name) != 0 and arr[j][i] == 'a' and name[-1] == 'k':
                name += arr[j][i]
                added = True
    # Output
    if (name == "vika"):
        print("YES")
    else:
        print("NO")
            