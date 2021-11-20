#from kandinsky import *
#from time import *
#from casioplot import *
from m5stack import lcd
import time

def sleep(t):
  time.sleep(t)
  return

def fill_rect(x,y,w,h,c):
  lcd.rect(x,y,w,h,color=c,fillcolor=c)
  return

def show_screen():
  return

def seg_disp(x,y,z,vv,u):
  v=vv[int(u[0])]
  fill_rect(x+1*z,y+0*z,17*z,z,v)
  fill_rect(x+2*z,y+1*z,15*z,z,v)
  fill_rect(x+4*z,y+2*z,11*z,z,v)
  v=vv[int(u[1])]
  fill_rect(x+0*z,y+1*z,z,11*z,v)
  fill_rect(x+1*z,y+2*z,z,9*z,v)
  fill_rect(x+2*z,y+4*z,z,5*z,v)
  v=vv[int(u[2])]
  fill_rect(x+4*z,y+4*z,z,3*z,v)
  fill_rect(x+5*z,y+5*z,z,3*z,v)
  fill_rect(x+6*z,y+6*z,z,4*z,v)
  v=vv[int(u[3])]
  fill_rect(x+8*z,y+4*z,z,6*z,v)
  fill_rect(x+9*z,y+4*z,z,8*z,v)
  fill_rect(x+10*z,y+4*z,z,6*z,v)
  v=vv[int(u[4])]
  fill_rect(x+14*z,y+4*z,z,3*z,v)
  fill_rect(x+13*z,y+5*z,z,3*z,v)
  fill_rect(x+12*z,y+6*z,z,4*z,v)
  v=vv[int(u[5])]
  fill_rect(x+18*z,y+1*z,z,11*z,v)
  fill_rect(x+17*z,y+2*z,z,9*z,v)
  fill_rect(x+16*z,y+4*z,z,5*z,v)
  v=vv[int(u[6])]
  fill_rect(x+3*z,y+11*z,4*z,z,v)
  fill_rect(x+1*z,y+12*z,8*z,z,v)
  fill_rect(x+3*z,y+13*z,4*z,z,v)
  v=vv[int(u[7])]
  fill_rect(x+12*z,y+11*z,4*z,z,v)
  fill_rect(x+10*z,y+12*z,8*z,z,v)
  fill_rect(x+12*z,y+13*z,4*z,z,v)
  v=vv[int(u[8])]
  fill_rect(x+0*z,y+13*z,z,11*z,v)
  fill_rect(x+1*z,y+14*z,z,9*z,v)
  fill_rect(x+2*z,y+16*z,z,5*z,v)
  v=vv[int(u[9])]
  fill_rect(x+4*z,y+18*z,z,3*z,v)
  fill_rect(x+5*z,y+17*z,z,3*z,v)
  fill_rect(x+6*z,y+15*z,z,4*z,v)
  v=vv[int(u[10])]
  fill_rect(x+8*z,y+15*z,z,6*z,v)
  fill_rect(x+9*z,y+13*z,z,8*z,v)
  fill_rect(x+10*z,y+15*z,z,6*z,v)
  v=vv[int(u[11])]
  fill_rect(x+14*z,y+18*z,z,3*z,v)
  fill_rect(x+13*z,y+17*z,z,3*z,v)
  fill_rect(x+12*z,y+15*z,z,4*z,v)
  v=vv[int(u[12])]
  fill_rect(x+18*z,y+13*z,z,11*z,v)
  fill_rect(x+17*z,y+14*z,z,9*z,v)
  fill_rect(x+16*z,y+16*z,z,5*z,v)
  v=vv[int(u[13])]
  fill_rect(x+1*z,y+24*z,17*z,z,v)
  fill_rect(x+2*z,y+23*z,15*z,z,v)
  fill_rect(x+4*z,y+22*z,11*z,z,v)

def seg_i():
  u=["12345678901234"]*44
  u[0]="11001100110011" #0
  u[1]="00000100000010" #1
  u[2]="10000111100001" #2
  u[3]="10000111000011" #3
  u[4]="01000111000010" #4
  u[5]="10100001000011" #5
  u[6]="11000011100011" #6
  u[7]="11000100000010" #7
  u[8]="11000111100011" #8
  u[9]="11000111000011" #9
  u[10]="00000000000000" #spc
  u[11]="11111111111111" #full
  u[12]="00111011011100" #*
  u[13]="00010011001000" #+
  u[14]="00000011000000" #-
  u[15]="00001000010000" #/
  u[16]="00000011000001" #=
  u[17]="11000101001000" #question
  u[18]="11000111100010" #A
  u[19]="10010101001011" #B
  u[20]="11000000100001" #C
  u[21]="10010100001011" #D
  u[22]="11000011100001" #E
  u[23]="11000011100000" #F
  u[24]="11000001100011" #G
  u[25]="01000111100010" #H
  u[26]="10010000001001" #I
  u[27]="00000100100011" #J
  u[28]="01001010100100" #K
  u[29]="01000000100001" #L
  u[30]="01101100100010" #M
  u[31]="01100100100110" #N
  u[32]="11000100100011" #O
  u[33]="11000111100000" #P
  u[34]="11000100100111" #Q
  u[35]="11000111100100" #R
  u[36]="11000011000011" #S
  u[37]="10010000001000" #T
  u[38]="01000100100011" #U
  u[39]="01001000110000" #V
  u[40]="01000100110110" #W
  u[41]="00101000010100" #X
  u[42]="00101000001000" #Y
  u[43]="10001000010001" #Z
  return u

def disp1(x,y,v,u):
  for z in range(1,9):
#    fill_rect(0,0,320,222,v[2])
    clear_screen()
    for j in range(8):
      for i in range(12):
        xx=x+(i*21*z)
        yy=y+(j*27*z)
        seg_disp(xx,yy,z,v,u[i])
    sleep(2)

def disp2(x,y,v,u):
  for i in range(44):
    for z in range(1,4):
#      fill_rect(0,0,320,222,v[2])
      clear_screen()
      for j in range(8):
        for k in range(15):
          xx=x+(k*21*z)
          yy=y+(j*27*z)
          seg_disp(xx,yy,z,v,u[i])
#      sleep(0.5)
#    sleep(1.5)

def disp3(x,y,v,u,z):
  j=0
  fill_rect(0,0,320,222,v[2])
#  clear_screen()
  i=0
  k=0
  while True:
    xx=x+(k*21*z)
    yy=y+(j*27*z)
    if yy>(222-z*27*1):
      break
    seg_disp(xx,yy,z,v,u[i])
    show_screen()
    i=i+1
    if i==44:
      i=0
    k=k+1
    if xx>(320-z*21*2):
      k=0
      j=j+1

def seg_14():
  u=seg_i()
  x=4
  y=4
  
#  v=['white','black','white']
#  disp1(x,y,v,u)

  v=[(176,240,200),(0,0,0),(224,240,200)]
  v=[lcd.LIGHTGREY,lcd.BLACK,lcd.WHITE]

#  disp1(x,y,v,u)
#  disp2(x,y,v,u)
  for i in range(1,9):
    z=9-i
    disp3(x,y,v,u,z)
    sleep(2)

#def fill_rect(x,y,w,h,c):
#  for i in range(w+1):
#    for j in range(h+1):
#      set_pixel(x+i,y+j,c)

#clear_screen()
#seg_14()