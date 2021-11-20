from math import *
from turtle import *

def draw(l):
  if (l<10):
    return
  else:
    forward(l)
    left(30)
    draw(3*l/4)
    right(60)
    draw(3*l/4)
    left(30)
    backward(l)

def myturtle4():
  reset()
  hideturtle()
  speed(10)
  penup()
  goto(0,-105)
  left(90)
  pendown()
  draw(65)
  penup()
  hideturtle()
  goto(-150,-100)
  write("END")
myturtle4()