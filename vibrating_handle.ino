const int trigPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int motorct = 4;
const int distance = 10;
//#include<SoftwareSerial.h>
//SoftwareSerial BTSerial(10,11); // Pin 10 is Tx and Pin 11 is Rx

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   //Serial2.begin(9600); //starting serial comm for tx and rx 1 
   //Serial1.begin(9600);
   
   //BTSerial.begin(38400); 
  // Serial.begin(38400);
   
  delay(10000);
  
}

void loop() {
  /* 
   if(BTSerial.Availabe()){
    Serial.write((BTSerial.read())); //Display the response from BT module
  }
  if(Serial.availabe()){
    BTSerial.write((Serial.read())); //Display AT commands sent
  }*/
   
   
   long duration, cm, meters;
   int inches;
   pinMode(motorct, OUTPUT);
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   meters = (cm/100);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();

   delay(100);

       if(inches <= distance){
    digitalWrite(motorct, HIGH);
    }
   else digitalWrite(motorct, LOW);
     
     
   
  if (Serial.available()) {
    Serial.write(inches);
    Serial.print("sent info:");
    Serial.println(inches);
  }

  

  

}




long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
