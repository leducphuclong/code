from sys import stdout

L, R = 1, int(1e1)

while L < R:
    M = (L+R)//2
    if (L+R) % 2 == 1:
        M += 1;
    print(M)
    stdout.flush()
    rps = input()
    if (rps == ">="):
        L = M
    else:
        R = M-1

print("!", L)