import bluetooth as ble
import sys
import smbus
import time
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

client_soc, address = server_soc.accept()
print("Accepted connection from {} ".format(address))
def greet():
    
def main():
    while True:
        data = client_soc.recv(1024)
        print("Recieved data {}".format(data))
        client_soc.send(data)
        dis = bus.read_byte(i2c_address)
        if data == b"exit":
            client_soc.send("Stoping by android app:")
            print("Exit:")
            break
        elif data == b"move forward" or data == b"forward":
            print("Forward march")
            bus.write_byte(i2c_address,1)
        elif data == b"move backward" or data == b"backward":
            print("Reverse")
            bus.write_byte(i2c_address,2)
        elif data == b"turn left" or data == b"left":
            print("left")
            bus.write_byte(i2c_address,3)
        elif data == b"turn right" or data == b"right":
            print("turn right")
            bus.write_byte(i2c_address,4)
        elif data == b"stop" or data == b"halt":
            print("stop")
            bus.write_byte(i2c_address,5)
        if dis <=10 :
            print("stop")
            bus.write_byte(i2c_address,5)
    client_soc.close()
    server_soc.close()
