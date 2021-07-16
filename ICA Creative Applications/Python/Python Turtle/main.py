import turtle
import math

'''
  void drawLine(int x, int y):

  draws a single line
'''
def drawLine(x, y):
  turtle.penup()
  turtle.setposition(x, y)
  turtle.pendown()
  turtle.forward(math.sqrt(50**2+50**2))

'''
  void drawSquare(int x, int y, int d):
  
  draws a square
'''
def drawSquare(x, y, d):
  turtle.setposition(x, y)
  turtle.pendown()

  for i in range(4):
    turtle.forward(d)
    turtle.right(90)
  
  turtle.penup()

## FIRST, THE LETTER

print(turtle.heading())

turtle.color("#FF0000")
turtle.speed(0)

turtle.circle(100, 180)
turtle.left(90)
turtle.forward(200)

turtle.penup()
turtle.setposition(15, 20)
turtle.left(90)
turtle.pendown()

turtle.circle(80, 180)
turtle.left(90)
turtle.forward(160)
##
turtle.penup()
turtle.setposition(-50, -50)
turtle.left(90)
turtle.pendown()

turtle.circle(100, 180)
turtle.left(90)
turtle.forward(200)

turtle.penup()
turtle.setposition(-35, -30)
turtle.left(90)
turtle.pendown()

turtle.circle(80, 180)
turtle.left(90)
turtle.forward(160)
##
turtle.left(135)
turtle.forward(math.sqrt(50**2+50**2))

drawLine(-50, -50)
drawLine(-50, 150)
drawLine(-35, 130)
drawLine(50, 50)
drawLine(20, -20)
drawLine(20, 120)

turtle.penup()

## NEXT, THE CUBE

turtle.setposition(0)
turtle.seth(270)

print(turtle.heading())

drawSquare(-50, -50, 50)
drawSquare(0, 0, 50)

turtle.speed(5)

turtle.setposition(-50, -100)
turtle.pendown()
turtle.left(135)
turtle.forward(math.sqrt(50**2+50**2))
turtle.penup()
'''
turtle.setposition(-50, -50)
turtle.pendown()
turtle.forward(math.sqrt(50**2+50**2))
turtle.penup()
'''
turtle.setposition(-100, -50)
turtle.pendown()
turtle.forward(math.sqrt(50**2+50**2))
turtle.penup()

turtle.setposition(-100, -100)
turtle.pendown()
turtle.forward(math.sqrt(50**2+50**2))
turtle.penup()