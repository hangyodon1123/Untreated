from math import *
from turtle import *

def fractal(size,depth=0):
  if depth <= 0:
    forward(size)
  else:
    fractal(size/3,depth-1);left(60)
    fractal(size/3,depth-1);left(-120)
    fractal(size/3,depth-1);left(60)
    fractal(size/3,depth-1)

def myturtle3():
  for j in range(3):
    reset()
    hideturtle()
    speed(10)
    penup()
    goto(-60,-108)
    pendown()
    for i in "12345":
      fractal(140,j+1)
      left(360/5)
    hideturtle()
    penup()
  goto(-150,-100)
  write("END")
myturtle3()  