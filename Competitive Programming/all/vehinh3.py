from turtle import *
from time import sleep

def da_giac(d, n):
	for i in range(n):
		fd(d)
		lt(360/n)

speed(10)

n = int(input())

pu()
bk(40*n/2)
goto(int(xcor()), int(ycor())+40*n/2)
pd()

for j  in range(5):
	for i in range(5):
		da_giac(40, 4)
		fd(40)
	if j < 4:
		bk(200)
		goto(int(xcor()), int(ycor())-40)
	

	
sleep(1.5)