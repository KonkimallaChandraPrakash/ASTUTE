# You can use Jinja2 over this

import webiopi
import time

GPIO = webiopi.GPIO

light1 = 17
light2 = 22

GPIO.setmode(GPIO.BCM)

def setup() :
	GPIO.setmode(light1,GPIO.IN)
	GPIO.setmode(light2,GPIO.IN)
	counter = 0	
	
def loop() :
	
	if( (GPIO.input(17)==1) and (GPIO.input(22)==1) and ( not (counter == 1 )) ):
		# Washer Mode
		counter = 1

	if( ( not (GPIO.input(17)==1)) and (GPIO.input(22)==1) and ( not (counter == 2 ))):
		# Drier Mode
		counter = 2
		
		
	if( (GPIO.input(17)==1) and ( not (GPIO.input(22)==1)) and ( not (counter == 3 ))):
		# Water In or Out Mode
		counter = 3
		
		
	if( ( not (GPIO.input(17)==1)) and ( not (GPIO.input(22)==1)) and ( not (counter == 4 ))):
		# Standby Mode
		counter = 4
		
	webiopi.cleanup	
	webiopi.sleep(0.025)
