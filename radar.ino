#include <Servo.h>.

const int trigpin=2;
const int echopin=3;

long duration;
int distance;
Servo myServo;

void setup() {
pinMode(trigpin,OUTPUT);
pinMode (echopin,INPUT);
Serial.begin (9600);
myServo. attach (9);

}

void loop() { 
  
for (int i=15;i<165;i++){
  myServo.write (i);
  delay (30);
  distance = calculateDistance (); 
  
  Serial.print(i);
  Serial.print(",");
  Serial.print (distance);
  Serial.print (",");
  
}
for (int i=165;i>15;i--){
  myServo.write(i);
  delay(30);
  distance=calculateDistance ();
  Serial.print(i);
  Serial.print(",");
  Serial.print (distance);
  Serial.print (",");
  
}
}

int calculateDistance (){
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds (2);

  digitalWrite (trigpin,HIGH);
  duration =pulseIn (echopin, HIGH);
  distance=duration*0.034/2;
  return distance ;
}




  
