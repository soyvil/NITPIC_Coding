#! /usr/bin/python

import time
import spidev
import RPi.GPIO as GPIO

# This section is to configure a pin as HIGH
GPIO.setmode(GPIO.BCM)
GPIO.setup(25, GPIO.OUT) #This is pin 22 on the RPI
GPIO.setup(24, GPIO.OUT) #This is pin 18 on the RPI

#This code is for S/PBAR to stay logic HIGH
GPIO.output(24, GPIO.HIGH)

bus = 0
device = 1
spi = spidev.SpiDev()
spi.open(bus, device)

#Setting the SPI speed and mode
spi.max_speed_hz = 1000000
spi.mode = 0

#Init to 0 dB
GPIO.output(25, GPIO.HIGH)
GPIO.output(25, GPIO.LOW)
msg = [0x00]
spi.xfer2(msg)
GPIO.output(25, GPIO.HIGH)
GPIO.output(25, GPIO.LOW)

while True:

	i = input("Please enter attenuator value number: ")
	print (i)

# 0 dB
	if (i == "0"):
		msg = [0x00]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 0 dB")

# 16 dB
	elif (i == "1"):
		msg = [0x02]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 16 dB")

# 8 dB
	elif (i == "2"):
		msg = [0x04]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 8 dB")

# 4 dB
	elif (i == "3"):
		msg = [0x08]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 4 dB")

# 2 dB
	elif (i == "4"):
		msg = [0x10]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 2 dB")

# 1 dB
	elif (i == "5"):
		msg = [0x20]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 1 dB")

# 0.5 dB
	elif (i == "6"):
		msg = [0x40]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("you have set to 0.5 dB")

# 0.25 dB
	elif (i == "7"):
		msg = [0x80]
		spi.xfer2(msg)
		GPIO.output(25, GPIO.HIGH)
		GPIO.output(25, GPIO.LOW)
		print ("You have set to 0.25 dB")

# this is an error catch
	else:
		print ("Invalid input")
