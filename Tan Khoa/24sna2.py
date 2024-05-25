x01, v1, x02, v2, t = map(int, input().split())

'''
x1 = x01 + t*v1
x2 = x02 + t*v2

distance = x1 - x2
'''

print(abs(x01 + t*v1 - x02 - t*v2))