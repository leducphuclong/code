from turtle import *
from time import sleep

def da_giac(d, n):
	for i in range(n):
		fd(d)
		lt(360/n)

speed(10)

bk(200)
for i in range(4):
	da_giac(100, 4)
	fd(100)
	
sleep(1.5)