from turtle import *
from time import sleep

def da_giac(d, n):
	for i in range(n):
		fd(d)
		lt(360/n)

speed(10)
pencolor("blue")

for j in range(8):
	da_giac(100, 5)
	lt(360/8)


sleep(10)
