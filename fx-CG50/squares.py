from math import *
from turtle import *
def squares(angle=0.5):
  reset()
  hideturtle()
  L=330
  penup()
  goto(-L/2,-L/2)
  pendown()
  for i in range(660):
    forward(L)
    left(90+angle)
    L=L-L*sin(angle*pi/180)
  hideturtle()
squares()  