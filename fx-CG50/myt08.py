from math import *
from turtle import *

def hilbert(n,length):
  lhlb(n,length)

def lhlb(n,length):
  if n <= 0:
    return
  right(90)
  rhlb(n-1,length)
  forward(length)
  left(90)
  lhlb(n-1,length)
  forward(length)
  lhlb(n-1,length)
  left(90)
  forward(length)
  rhlb(n-1,length)
  right(90)

def rhlb(n,length):
  if n <= 0:
    return
  left(90)
  lhlb(n-1,length)
  forward(length)
  right(90)
  rhlb(n-1,length)
  forward(length)
  rhlb(n-1,length)
  right(90)
  forward(length)
  lhlb(n-1,length)
  left(90)

def myturtle8():
  reset()
  hideturtle()
  speed(10)
  penup()
  goto(-110,110)
  pendown()
  hilbert(5,7)
  hideturtle()
  penup()
  goto(-150,-100)
  write("END")
myturtle8()