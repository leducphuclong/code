import sys
input=sys.stdin.readline
print=sys.stdout.write

N = int(1e6) + 5

is_prime = [True for i in range(N)]

def sieve_of_eratosthenes():
    is_prime[0] = is_prime[1] = False
    i = 2
    while i*i < N:
        if is_prime[i] == True:
            j = i*i
            while j < N:
                is_prime[j] = False
                j += i
        i += 1    
        

sieve_of_eratosthenes();

n = int(input())
ans = -1
for m in range(1, 1000+1):
    if is_prime[n*m+1] == False:
        ans = m

print(ans)
    

