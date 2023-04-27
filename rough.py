import serial
import time

ser = serial.Serial('COM6', 9600)

f = open("tracefile.txt", "r")

for l in f:
    h = l.split(' ')[1]
    # t = '0'*(8-len(h))
    # h = t+h
    h = h[::-1]
    h = h+'0000'
    h = h[::-1]
    print(h)
    ser.write(bytearray.fromhex(h[0:2]))
    ser.write(bytearray.fromhex(h[2:4]))                        
    ser.write(bytearray.fromhex(h[4:6]))
    ser.write(bytearray.fromhex(h[6:]))
    time.sleep(0.1)
    ser.write(bytearray.fromhex(h[6:]))