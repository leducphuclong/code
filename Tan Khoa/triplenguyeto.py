N = int(1e6) + 2

is_prime = [True for i in range(N)]

def sieve():
    is_prime[0] = is_prime[1] = False
    i = 2
    while i*i < N:
        if is_prime[i] == True:
            j = i*i
            while j < N:
                is_prime[j] = False
                j += i
        i += 1


sieve()
n = int(input())
res = []
for i in range(n-1):
    if is_prime[i] == True and is_prime[i+2] == True:
        res.append([2, i])

print(len(res))
for p in res:
    print(*p)
        
