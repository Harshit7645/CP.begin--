import serial
import time


# Replace 'COM1' with the appropriate serial port and 115200 with the appropriate baud rate
ser = serial.Serial('COM8', 9600)
f = open("dram_tracefile.txt", "r")

for line in f:
    x = line
    ser.write(bytearray.fromhex(x[2:4]))
    ser.write(bytearray.fromhex(x[0:2]))
    ser.write(bytearray.fromhex("00"))
    ser.write(bytearray.fromhex("00"))
    time.sleep(0.000001)

f.close()