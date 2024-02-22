from turtle import *
from time import sleep

def da_giac(d, n):
	for _ in range(n):
		fd(d)
		lt(360/n)

speed(1000)

for i in range(3, 8):
	da_giac(100, i)

sleep(

