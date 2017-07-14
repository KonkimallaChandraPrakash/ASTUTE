/*
PLACE THE CURRENT SENSOR INSIDE THE SPIKE (IN ONE PORT OF THE 
SPIKE THROUGH THE RED WIRE OF THAT PORT LINK TO RELATE YOU THROUGH THIS
https://www.youtube.com/watch?v=UF5jrnXvTlM
) TO DECREASE NOISE WHICH IS MAIN PART.

A0-ANALOG INPUT OF THE SENSOR VALUE

NOTE ::: If the values between the water in or out and the off mode are overlapping 
then it might be due to noise in the current sensor then go through 
the link below in which tells about how to decrease the noise in the current sensor
https://www.youtube.com/watch?v=etsIFUUhO6I

RUN THIS PROGRAM UNTIL THE COMPLETE WASHING MACHINE CYCLE ENDS

*/

float a,b,avg;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int x=0;x<15000;x++){
    int sensorvalue=analogRead(A0);
    a=((513-sensorvalue)*50.000/1023);//if using 20 amp current sensor
    //a=((511-sensorvalue)*k/1023);
    //for the value of k check the datasheet of the current sensor and go throuch the tutorial link below
    //https://www.youtube.com/watch?v=lisprJs5sNU
    if(a>0){
      if(a>b){
        b=a;
      }
      avg=(((avg)*x+a)/(x+1));
    }
    else{
      if(((-1)*a)>b){
        b=(-1)*a;
      }
      avg=(((avg)*x-a)/(x+1));
    }
    delay(1.23);
    
  }
  Serial.print("avg=");
  Serial.print(avg);
  Serial.print("b=");
  Serial.print(b);
  Serial.print('\n');
}
