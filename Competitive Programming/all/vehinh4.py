from turtle import *
from time import sleep

def da_giac(d, n):
	for i in range(n):
		fd(d)
		lt(360/n)

speed(10)

pencolor("blue")

for i in range(11):
	da_giac(100, 3)
	lt(360/11)

sleep(10)