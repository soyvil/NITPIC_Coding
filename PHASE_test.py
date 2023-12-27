#! /usr/bin/python

import time
import spidev
import RPi.GPIO as GPIO

GPIO.setwarnings(False)

# This section is to configure pins
GPIO.setmode(GPIO.BCM)
GPIO.setup(25, GPIO.OUT) #This is pin 22 on the RPI for Latch Enable
GPIO.setup(24, GPIO.OUT) #This is pin 18 on the RPI for S/PBAR
GPIO.setup(26, GPIO.OUT) #This is pin 37 on the RPI for A3
GPIO.setup(19, GPIO.OUT) #This is pin 35 on the PI for A2
GPIO.setup(13, GPIO.OUT) #This is pin 33 on the PI for A1
GPIO.setup(6, GPIO.OUT) #This the pin 31 on the PI for A0

#Setting the Address
GPIO.output(6, GPIO.LOW)
GPIO.output(13, GPIO.LOW)
GPIO.output(19, GPIO.LOW)
GPIO.output(26, GPIO.LOW)

#This code is for S/PBAR to stay logic HIGH
GPIO.output(24, GPIO.HIGH)

bus = 0
device = 1
spi = spidev.SpiDev()
spi.open(bus, device)

#Setting the SPI speed and mode
spi.max_speed_hz = 10000000
spi.mode = 2

#Init to 0 degrees
GPIO.output(25, GPIO.HIGH)
GPIO.output(25, GPIO.LOW)
msg = [0x000]
spi.xfer2(msg)
GPIO.output(25, GPIO.HIGH)
#GPIO.output(25, GPIO.LOW)

while True:

	i = input("Please enter phase value number: ")
	print ("You have enterted: ", i)
	GPIO.output(25, GPIO.HIGH)

# 0 degrees
	if (i == "0"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0000000000000]
		spi.xfer2(msg)
		time.sleep(0.000001)
		GPIO.output(25, GPIO.HIGH)
		time.sleep(1)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 0 degrees")

# 180 degrees
	elif (i == "1"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0000000100000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 180 degrees")
		print (msg)

# 90 degrees
	elif (i == "2"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0000001000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 90 degrees")
		print (msg)

# 45 degrees
	elif (i == "3"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0000010000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 45 degrees")
		print (msg)


# 22.5 degrees
	elif (i == "4"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0000100000000]
		spi.xfer2(msg)
		msg = [0b0000100000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		time.sleep(1)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 22.5 degrees")

# 11.2 degrees
	elif (i == "5"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0001000000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 11.2 degrees")
		print (msg)

# 5.6 degrees
	elif (i == "6"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0010000000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 5.6 degrees")
		print (msg)

# 2.8 degrees
	elif (i == "7"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b0100000000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 2.8 degrees")
		print (msg)

# 1.4 degrees
	elif (i == "8"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b1000000000000]
		spi.xfer2(msg)
		time.sleep(1)
		GPIO.output(25, GPIO.HIGH)
		#GPIO.output(25, GPIO.LOW)
		print ("You have set to 1.4 degrees")
		print (msg)

########################
# These are test values
########################
	elif (i == "9"):
		GPIO.output(25, GPIO.LOW)
		msg = [0b111111110000]
		spi.writebytes(msg)
		time.sleep(0.000001)
		GPIO.output(25, GPIO.HIGH)
		time.sleep(0.000030)
		GPIO.output(25, GPIO.LOW)

# this is an error catch
	else:
		print ("Invalid input")
