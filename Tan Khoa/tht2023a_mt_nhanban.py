from sys import stdin
input = stdin.readline

# Read the string of digits and convert to a list of integers
s = []
num = int(input())
while num > 0:
	s.append(num%10)
	num //= 10

s.reverse()



# Prepend '0' to the list to match the original algorithm's index system

# Calculate the length of the list
n = len(s) 

# Read the left and right bounds
l = int(input())
r = int(input())

# Function to sum the digits up to a given index
sumDigits = [0]
for i in range(1, n+1):
	sumDigits.append(sumDigits[i-1] + int(s[i-1]))

# Function to calculate the cumulative sum up to x using the doubling technique
def f(x):
    ans = 0
    while x > 0:
        if x <= n:
            ans += sumDigits[x]
            break

        idx = n
        tol = sumDigits[n]
        while idx * 2 < x:
            idx *= 2
            tol *= 2

        ans += tol
        x -= idx

    return ans

# Calculate and print the result
if (l > r):
	print(0)
else:
	print(f(r) - f(l - 1))
