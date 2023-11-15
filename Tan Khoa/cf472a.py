N = int(1e6) + 5

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

        i += 2

n = int(input())
sieve()
for i in range(1, n):
    if is_prime[i] == False and is_prime[n-i] == False:
        print(i, n-i)
        break
