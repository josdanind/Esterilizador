import serial, time

arduino= serial.Serial('/dev/ttyUSB0', 9600)


while True:

    time.sleep(2)
    Tem = arduino.readline()
    print(Tem)

arduino.close()
