from turtle import *

def tshape01():
  penup()
  goto(0,0)

  shape("classic")
  showturtle()
  pendown()
  for i in range(4):
    if i==1:
      write("classic")
    forward(m)
    left(90)
  hideturtle()
  penup()
  goto(0,0)
  left(180)

  shape("turtle")
  showturtle()
  pendown()
  for i in range(4):
    if i==1:
      write("turtle")
    forward(m)
    left(90)
  hideturtle()

reset()
m=80
hideturtle()
speed(1)
for i in range(2):
  tshape01()
  right(180)
penup()
goto(-m-50,-m)
write("END")