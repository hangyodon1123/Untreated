import turtle

def sierp(n, l):
  a, r = 60, 1
  if n <= 0:
    for i in range (3):
      turtle.fd(l)
      turtle.left(a * 2)
  else:
    l /= 2
    n -= 1
    sierp(n, l)
    turtle.fd(l)
    sierp(n, l)
    turtle.bk(l)
    turtle.left(a)
    turtle.fd(l)
    turtle.right(a)
    r += 3 * sierp(n, l)
    turtle.left(a)
    turtle.bk(l)
    turtle.right(a)
  return r

def rotsierp(l, m):
  r = 0
  turtle.penup()
  turtle.left(90)
  turtle.fd(m - 1)
  turtle.right(90)
  for k in range(6):
    turtle.pendown()
    t = sierp(k,l)
    turtle.penup()
    turtle.right(90)
    turtle.fd(m)
    turtle.left(30)
    r += t
    print("+ " + str(t) + " triangle" + ((t > 1) and "s" or ""))
  return r

def sirp6():
  turtle.hideturtle()
  #turtle.shape("turtle")
  turtle.speed(10)
  t = rotsierp(123, 3)
  #print("= " + str(t) + " triangles")
  return
  