tc = int(input())
for _ in range(tc):
    n, h, c = map(int, input().split())
    print(min((h+c)*2+1, n*2-1))

