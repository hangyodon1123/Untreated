from ce_turtl import *

def sierp(n,l):
  a,r=60,1
  if n<=0:
    for i in range(3):
      turtle.forward(l)
      turtle.left(a*2)
  else:
    l /= 2
    n -= 1
    sierp(n,l)
    turtle.forward(l)
    sierp(n,l)
    turtle.backward(l)
    turtle.left(a)
    turtle.forward(l)
    turtle.right(a)
    r += 3 * sierp(n,l)
    turtle.left(a)
    turtle.backward(l)
    turtle.right(a)
  return r

def rotsierp(l,m):
  r=0
  turtle.penup()
  turtle.left(90)
  turtle.forward(m-1)
  turtle.right(90)
  for k in range(6):
    turtle.pendown()
    t=sierp(k,l)
    turtle.penup()
    turtle.right(90)
    turtle.forward(m)
    turtle.left(30)
    r += t
  return r

turtle.home()
turtle.clear()
turtle.speed(10)
t=rotsierp(110,3)
turtle.show()