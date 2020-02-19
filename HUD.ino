#include <WiseChipHUD.h>

WiseChipHUD myHUD;
long meters;
int inches = 0;

void setup() {

  myHUD.begin();
    // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  Serial2.begin(9000);
   myHUD.clearAll(); // Clears all of the segments
 
}


void loop() {

  

  // read from port 1
  if (Serial2.available()>0 ) {
    inches = Serial2.read();
    inches = inches & B01111111;
    Serial.print("distance = ");
    Serial.println(inches, BIN);
  }
 
  Serial.println("_________");
  

  /************************* Compass Group *************************/
  //myHUD.compassCircle(9); // 0 = All Off; 1-8 = All Off Except Selected; 9 = All On; 10-17 = All On Except Selected
  //myHUD.compassArrows(9); // 0 = All Off; 1-8 = All Off Except Selected; 9 = All On; 10-17 = All On Except Selected
  //myHUD.setHeading(188);  // Max 199

  /************************* Radar Detector Group *************************/
  myHUD.radarDetector(8); // 0 = No Radar Gun Icon; 1 = Radar Gun Only; 2-8 = meters Meter
  myHUD.setRadarDistance(inches,1); // Max 999    
  myHUD.radarDistanceUnits(0); // 0 = Blank; 1 = "m" 

  /************************* Destination/Waypoint Group *************************/
 //myHUD.flag(1); // 0 = Blank; 1 = flag icon 
 //myHUD.setDestinationmeters(888,2); // Max 999
  //myHUD.destinationmetersUnits(3); // 0 = Blank; 1 = "h"; 2 = "m"; 3 = "km"
  //myHUD.H01(1); // 0 = Blank; 1 = "h"

  /************************* Exit Group *************************/
  //myHUD.leftTunnel(1); // 0 = Blank; 1 = Tunnel; Also try leftRoad();
  //myHUD.middleTunnel(1); // 0 = Blank; 1 = Tunnel; Also try middleRoad();
  //myHUD.rightTunnel(1); // 0 = Blank; 1 = Tunnel; Also try rightRoad();

  /************************* Navigation Group *************************/
  //myHUD.nav_Group(1); // 0 = Entire Nav Group Off; 1 = Entire Nav Group On
  //myHUD.setTurnmeters(888,1); // Max 999
  //myHUD.turnmetersUnits(2); // 0 = Blank; 1 = "m"; 2 = "km"
  // Turn Groups:
//   nav_KeepLeft(1);
  // nav_TurnLeft(1);
   //nav_HardLeft(1);
   //nav_UTurnLeft(1);
  // nav_ContinueStraight(1);
  // nav_KeepRight(1);
   //nav_TurnRight(1);
   //nav_HardRight(1);
   //nav_UTurnRight(1);

  /************************* Call Group *************************/
 // myHUD.setCallIcon(3); // 0 = Blank; 1 = Outline; 2 = Outline + Phone Icon; 3 = All Segments

  /************************* TPMS Group *************************/
  //myHUD.tirePressureAlert(3); // 0 = Blank; 1 = "TPMS"; 2 = "TIRE"; 3 = All Segments
  //myHUD.setTirePressure(88,1); // Max 99

  /************************* Speedometer Group *************************/
  //myHUD.setSpeedometer(188); // Max 199
  //myHUD.speedometerUnits(1); // 0 = Blank; 1 = "km/h"

  //delay(100);

  //myHUD.clearAll(); // Clears all of the segments

//while(1){};

}
