from turtle import *
from time import sleep

def da_giac(d, n):
	for i in range(n):
		fd(d)
		lt(360/n)

speed(10)
da_giac(100, 4)

for i in range(2):
	for j in range(4):
		da_giac(100, 4)
		lt(90)
	lt(45)

sleep(10)
