from math import *
from turtle import *
def myturtle():
  L=70
  reset()
  hideturtle()
  speed(10)
  penup()
  goto(0-L,0+L/2)
  pendown()
  for i in range(36):
    forward(140)
    right(360/3+10)
  penup()
  hideturtle()
  goto(-100,-100)
  write("END")
myturtle()