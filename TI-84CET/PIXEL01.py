from ce_turtl import *
turtle.clear()
turtle.penup()
turtle.right(90)
for i in range(301):
  turtle.goto(i-150,0+100)
  turtle.pendown()
  turtle.forward(190)
  turtle.penup()
turtle.show()