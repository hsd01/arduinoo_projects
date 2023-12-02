import bluetooth as ble
import sys
import smbus
import time
import pyttsx3
from datetime import datetime
import random

eng = pyttsx3.init()
eng.setProperty('voice', 'en-us')
eng.setProperty('pitch', 0.8)
voices = eng.getProperty('voices')
eng.setProperty('voice', voices[1].id)

bus = smbus.SMBus(1)
i2c_address = 0x08 # Arduino I2C Address
def ConvertStringsToBytes(src):
    converted = []
    for b in src:
        converted.append(ord(b))
    return converted
# 30:BB:7D:4C:97:E0
print("BLE terminal with voice:")

server_soc = ble.BluetoothSocket(ble.RFCOMM)

port = ble.PORT_ANY
server_soc.bind(("/dev/ttyS0",port))
server_soc.listen(1)

def greet():
    hello = ["hello", "hey", "namastay", "hi"]
    tim = datetime.now()
    current_time = tim.strftime('%H:%M:%S')
    print('Current Time is:', current_time)
    cu_time = current_time.split(":")
    time_now = cu_time[0]
    rand = random.randint(1,(len(hello)-1))
    if int(time_now) >=0 and int(time_now) < 12:
        eng.say(hello[rand]+" Good morning")
        eng.runAndWait()
    elif int(time_now) >=12 and int(time_now) < 22:
        eng.say(hello[rand]+" good afternoon ")
        eng.runAndWait()
    else:
        eng.say(hello[rand]+"its already bead time good night")
        eng.runAndWait()
#eng.say("Hello My name is Zenny")
#eng.runAndWait()
#client_soc, address = server_soc.accept()
#greet()
#print("Accepted connection from {} ".format(address))

def main():
    while True:
        data = client_soc.recv(1024)
        print("Recieved data {}".format(data))
        client_soc.send(data)
        dis = bus.read_byte(i2c_address)
        if data == b"exit":
            client_soc.send("Stoping by android app:")
            eng.say("stoped from mobile app exiting")
            eng.runAndWait()
            print("Exit:")
            break
        elif data == b"move forward" or data == b"forward":
            print("Forward march")
            eng.say("Moving forward")
            eng.runAndWait()
            bus.write_byte(i2c_address,1)
        elif data == b"move backward" or data == b"backward":
            print("Reverse")
            eng.say("Moving reverse")
            eng.runAndWait()
            bus.write_byte(i2c_address,2)
        elif data == b"turn left" or data == b"left":
            print("left")
            eng.say("Moving left")
            eng.runAndWait()
            bus.write_byte(i2c_address,3)
        elif data == b"turn right" or data == b"right":
            print("turn right")
            eng.say("Moving right")
            eng.runAndWait()
            bus.write_byte(i2c_address,4)
        elif data == b"stop" or data == b"halt":
            print("stop")
            eng.say("stoping")
            eng.runAndWait()
            bus.write_byte(i2c_address,5)
        if dis <=10 :
            print("stop")
            bus.write_byte(i2c_address,5)
    client_soc.close()
    server_soc.close()
    
eng.say("Hello My name is Zenny")
eng.runAndWait()
client_soc, address = server_soc.accept()
greet()
print("Accepted connection from {} ".format(address))
main()
