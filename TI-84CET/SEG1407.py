from ti_graphics import setColor,fillRect,sleep
from ti_system import disp_wait

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
#  u=["d12345678901234"]*44
  u=[0b111111111111111]*44
  u[0]=0b111001100110011 #0
  u[1]=0b100000100000010 #1
  u[2]=0b110000111100001 #2
  u[3]=0b110000111000011 #3
  u[4]=0b101000111000010 #4
  u[5]=0b110100001000011 #5
  u[6]=0b111000011100011 #6
  u[7]=0b111000100000010 #7
  u[8]=0b111000111100011 #8
  u[9]=0b111000111000011 #9
  u[10]=0b100000000000000 #spc
  u[11]=0b111111111111111 #full
  u[12]=0b100111011011100 #*
  u[13]=0b100010011001000 #+
  u[14]=0b100000011000000 #-
  u[15]=0b100001000010000 #/
  u[16]=0b100000011000001 #=
  u[17]=0b111000101001000 #question
  u[18]=0b111000111100010 #A
  u[19]=0b110010101001011 #B
  u[20]=0b111000000100001 #C
  u[21]=0b110010100001011 #D
  u[22]=0b111000011100001 #E
  u[23]=0b111000011100000 #F
  u[24]=0b111000001100011 #G
  u[25]=0b101000111100010 #H
  u[26]=0b110010000001001 #I
  u[27]=0b100000100100011 #J
  u[28]=0b101001010100100 #K
  u[29]=0b101000000100001 #L
  u[30]=0b101101100100010 #M
  u[31]=0b101100100100110 #N
  u[32]=0b111000100100011 #O
  u[33]=0b111000111100000 #P
  u[34]=0b111000100100111 #Q
  u[35]=0b111000111100100 #R
  u[36]=0b111000011000011 #S
  u[37]=0b110010000001000 #T
  u[38]=0b101000100100011 #U
  u[39]=0b101001000110000 #V
  u[40]=0b101000100110110 #W
  u[41]=0b100101000010100 #X
  u[42]=0b100101000001000 #Y
  u[43]=0b110001000010001 #Z
  return u

def disp3(x,y,v,u,z):
  j=0
  fill_rect(0,0,320,222,v[2])
  i=0
  k=0
  m=44
  while True:
    xx=x+(k*21*z)
    yy=y+(j*27*z)
    if yy>(222-z*27*1):
      break
    u1=bin(u[i])
    u2=u1[3:17]
    seg_disp(xx,yy,z,v,u2)
    i=i+1
    if i==m:
      i=0
    k=k+1
    if xx>(320-z*21*2):
      k=0
      j=j+1

def seg_14():
  u=seg_i()
  x=4
  y=4
  

  v=[(176,240,200),(0,0,0),(224,240,200)]
  for i in range(1,9):
    z=9-i
    disp3(x,y,v,u,z)
    sleep(2)

def fill_rect(x,y,w,h,c):
  setColor(c)
  fillRect(x,y+30,w,h)

seg_14()
disp_wait()