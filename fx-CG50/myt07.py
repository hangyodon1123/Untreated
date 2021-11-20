from math import *
from turtle import *

def dragon(n,length=300):
  dcr(n,length)

def dcr(n,length):
  length /= 1.414
  if n <= 0:
    forward(length)
    return
  right(45)
  dcr(n-1,length)
  left(90)
  dcl(n-1,length)
  right(45)
  
def dcl(n,length):
  length /= 1.414
  if n <= 0:
    forward(length)
    return
  left(45)
  dcr(n-1,length)
  right(90)
  dcl(n-1,length)
  left(45)

def myturtle7():
  reset()
  hideturtle()
  speed(10)
  penup()
  goto(-88,35)
  pendown()
  dragon(11)
  penup()
  hideturtle()
  goto(-150,-100)
  write("END")
myturtle7()