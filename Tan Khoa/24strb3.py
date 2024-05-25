n = int(input())
price = list(map(int, input().split()))

price.sort(reverse = True)

max_revenue, min_price = 0, int(1e9)
for i in range(n):
	if price[i]*(i+1) >= max_revenue:
		max_revenue = price[i]*(i+1)
		min_price = price[i]

print(max_revenue, min_price)
