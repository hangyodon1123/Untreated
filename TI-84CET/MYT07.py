from ce_turtl import *

def dragon(n,length=300):
  dcr(n,length)

def dcr(n,length):
  length/=1.414
  if n<=0:
    turtle.forward(length)
    return 
  turtle.right(45)
  dcr(n-1,length)
  turtle.left(90)
  dcl(n-1,length)
  turtle.right(45)

def dcl(n,length):
  length/=1.414
  if n<=0:
    turtle.forward(length)
    return 
  turtle.left(45)
  dcr(n-1,length)
  turtle.right(90)
  dcl(n-1,length)
  turtle.left(45)

def myt07():
  turtle.home()
  turtle.clear()
  turtle.speed(10)
  turtle.penup()
  turtle.goto(-88,35)
  turtle.pendown()
  dragon(11)
  turtle.penup()
  turtle.goto(-150,-100)
  turtle.show()
myt07()