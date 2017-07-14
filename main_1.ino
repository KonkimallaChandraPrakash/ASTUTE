/*
We had written the code in two forms that is in relative form and other in absolute form
that is in relative form a particular value is taken in the start when the system is in
stand by mode and others are written in according to the value of the measured

You can continue in ABSOLUTE FORM by uncommenting the commented part
and manipulating accordingly
*/

float a,b,avg;
int c=0;
int counter1;
int counter2;
float b_before=0;
const int ledpin1=9;
const int ledpin2=11;
float k,k1;
int k2;
int n=1;
// configuration of modes
// min,max,mode


void setup(){
  Serial.begin(115200);
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
}

void loop(){
  a=0;
  b=0;
  avg=0;
  
 /*if(n==1){
    for(int calib=0;calib<15000;calib++){
     int k2=analogRead(A0);
    k1=((511-k2)*27.03/1023);
    if((k1)>0){
      k=k1;
    }
    
    delay(1.23);
    }
    Serial.print(k1);
    Serial.print(k);
    n=396693;
  }
  */
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
  if(n==1){
    k=b;
    n=9;
}
  /*
  Serial.print("avg=");
  Serial.print(avg);
  Serial.print("b=");
  */
  Serial.print(b);
  Serial.print('\n');
  
  /*
  Serial.print("b_before=");
  
  Serial.print(b_before);
  Serial.print('\n');
  */
  
  /*if( ( ( b>=0.12 && b<0.17 ) && (c!=2) && ( b_before>=0.07 && b_before<0.25))){
    Serial.print("Water in or out");
    Serial.print('\n');
    digitalWrite(ledpin1,LOW); //sending sms function is also written here
    digitalWrite(ledpin2,HIGH);
    c=2;
    
  }
  
  if( (b<0.12) && (c!=1)){
    Serial.print("Off or Stand By Mode");
    Serial.print('\n');
    digitalWrite(ledpin1,LOW); //sending sms function is also written here
    digitalWrite(ledpin2,LOW);
    c=1;
  }
  
  if( ( b>=0.7 && b<1.2 ) && (c!=3)){
    Serial.print("Drier Mode");
    Serial.print('\n');
    c=3;
    digitalWrite(ledpin1,HIGH); //sending sms function is also written here
    digitalWrite(ledpin2,LOW);
  }
  
  if( ( b>=1.8 ) && ( c!=4 ) ){
    Serial.print("Washing Mode");
    Serial.print('\n');
    c=4;
    digitalWrite(ledpin1,HIGH); //sending sms function is also written here
    digitalWrite(ledpin2,HIGH);
  }
  */
  if( ( ( b>=(k+0.02) && b<(k+0.25) ) && (c!=2) && ( b_before>=(0.02+k) && b_before<(k+0.25)))){
    Serial.print("Water in or out");
    Serial.print('\n');
    digitalWrite(ledpin1,LOW); //sending sms function is also written here
    digitalWrite(ledpin2,HIGH);
    c=2;
    
  }
  
  if( ((b<(0.02+k)) && (c!=1)) && ((b_before<(0.02+k)) && (c!=1)) ) {
    Serial.print("Off or Stand By Mode");
    Serial.print('\n');
    digitalWrite(ledpin1,LOW); //sending sms function is also written here
    digitalWrite(ledpin2,LOW);
    c=1;
  }
  
  if( ( b>=(k+1.295) && b<(k+2.3) ) && (c!=3)){
    Serial.print("Drier Mode");
    Serial.print('\n');
    c=3;
    digitalWrite(ledpin1,HIGH); //sending sms function is also written here
    digitalWrite(ledpin2,LOW);
  }
  
  if( ( b>=(k+2.5) ) && ( c!=4 ) ){
    Serial.print("Washing Mode");
    Serial.print('\n');
    c=4;
    digitalWrite(ledpin1,HIGH); //sending sms function is also written here
    digitalWrite(ledpin2,HIGH);
  }
  
  b_before=b;
}
