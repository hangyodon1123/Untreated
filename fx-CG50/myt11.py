from math import *
from turtle import *

def square():
  for i in range(4):
    forward(65)
    right(90)

def myturtle11():
  hideturtle()
  speed(10)
  for j in range(72):
    square()
    right(5)
  hideturtle()
  penup()
  goto(-150,-100)
  write("END")
myturtle11()