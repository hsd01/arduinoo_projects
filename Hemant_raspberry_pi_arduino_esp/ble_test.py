import sys
import smbus
import time
bus = smbus.SMBus(1)
address = 0x08 # Arduino I2C Address
def ConvertStringsToBytes(src):
    converted = []
    for b in src:
        converted.append(ord(b))
    return converted

def main():
    i2cData = 0
    while 1:
        # send data
        if (bus.read_byte(address)>15):
            #i2cData = not i2cData
            bus.write_byte(address,1)     
        # request data
        print ("Arduino answer to RPi:", bus.read_byte(address))
        time.sleep(1)
        BytesToSend = ConvertStringsToBytes('hello')
        print("Sent " + str(address) + " the " + str('hello') + " command.")
        print(BytesToSend )
        bus.write_i2c_block_data(address, 0x08, BytesToSend)
        time.sleep(0.5)
        print("write data to arduino:")
if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        gpio.cleanup()
        sys.exit(0)

