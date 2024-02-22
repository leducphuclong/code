import sys

# Fast I/O
input = sys.stdin.readline
print = sys.stdout.write

N = int(1e6) + 5

no_dvs = [2 for i in range(N)]
def eratosthenes_sieve():
    no_dvs[1] = 1
    i = 2
    while i*i < N:
        j = i*i
        no_dvs[j] += 1
        while j + i < N:
            j += i
            no_dvs[j] += 2
        i += 1

eratosthenes_sieve()

for _ in range(int(input())):
    n = int(input())
    print(str(no_dvs[n]) + '\n')
        
    
