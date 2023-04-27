import serial
import time

ser = serial.Serial('COM8', 9600)
f = open("trace.txt", "r")
for l in f:
    h = l.split(' ')[1]
    # t = '0'*(8-len(h))
    # h = t+h
    h = h.strip()
    h = h[::-1]
    if (len(h) == 3):
        h = h+'00000'
    elif (len(h) == 2):
        h = h+'000000'
    elif (len(h) == 1):
        h = h+'0000000'
    elif (len(h) == 4):
        h = h+'0000'
    elif (len(h) == 5):
        h = h+'000'
    elif (len(h) == 6):
        h = h+'00'
    h = h[::-1]
    print(h)
    ser.write(bytearray.fromhex(h[0:2]))
    ser.write(bytearray.fromhex(h[2:4]))
    ser.write(bytearray.fromhex(h[4:6]))
    ser.write(bytearray.fromhex(h[6:]))
    time.sleep(0.01)
    #ser.write(bytearray.fromhex(h[6:]))