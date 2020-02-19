const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int motorct = 4;
const int distance = 10;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   //Serial2.begin(9600); //starting serial comm for tx and rx 1 
   //Serial1.begin(9600);
  delay(10000);
  
}

void loop() {
   long duration, cm, meters;
   int inches;
   pinMode(motorct, OUTPUT);
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
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
     
     
   
  if (Serial1.available()) {
    Serial1.write(inches);
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
