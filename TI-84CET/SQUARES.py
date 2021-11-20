from math import *
from ce_turtl import *
def squares(angle=0.5):
  turtle.clear()
  turtle.home()
  L=330
  turtle.speed(10)
  turtle.penup()
  turtle.goto(-L/2,-L/2)
  turtle.pendown()
  for i in range(660):
    turtle.forward(L)
    turtle.left(90+angle)
    L=L-L*sin(angle*pi/180)
  turtle.show()
squares()