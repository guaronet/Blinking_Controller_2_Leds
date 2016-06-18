
/* Blinking controller for two leds at different velocities
 * created on 18 June 2016
 * by Leonardo Tolosa <http://www.guaronet.com> 
 * 
 */


//Variables declarations ##############

int redLed = 13;      //Pin in the Arduino board
int blueLed = 12;     //Pin in the Arduino board
int redTime;          //timer
int blueTime;         //timer
int redSwitchTime;    //Time to when red led switches status
int blueSwitchTime;   //Time to when blue led switches status
boolean redStatus;    //Led Status
boolean blueStatus;   //Led Status

const int redLedOnTime = 500;   // Set the On Time
const int redLedOffTime = 500;  // Set the Off time
const int blueLedOnTime = 1000; // Set the On Time
const int blueLedOffTime = 500; // Set the Off time


//Setting up variables ##############

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  blueTime = millis();
  redTime = millis();
  redSwitchTime = millis();
  blueSwitchTime = millis();
  digitalWrite(redLed, HIGH);
  digitalWrite(blueLed, HIGH);
  redStatus = HIGH;
  blueStatus = HIGH;
  Serial.begin(9600);

}

//Main Function ##############

void loop() {
  // put your main code here, to run repeatedly:
  ((redTime > redLedOnTime)&&(redStatus==HIGH)) ? redLedOff() : redLedOn();
   redTime = millis() - redSwitchTime;
  ((blueTime > blueLedOnTime)&&(blueStatus==HIGH)) ? blueLedOff() : blueLedOn();
   blueTime = millis() - blueSwitchTime;
}

//Functions declarations ##############

void redLedOff() {
  digitalWrite(redLed, LOW);
  redStatus = !redStatus; 
  redSwitchTime = millis();
}

void redLedOn() {
  if (redTime >= redLedOffTime && redStatus == LOW) {
    digitalWrite(redLed, HIGH);
    redStatus = !redStatus;
    redSwitchTime = millis();
   }
}


void blueLedOff() {
  digitalWrite(blueLed, LOW);
  blueStatus = !blueStatus; 
  blueSwitchTime = millis();
}

void blueLedOn() {
  if (blueTime >= blueLedOffTime && blueStatus == LOW) {
    digitalWrite(blueLed, HIGH);
    blueStatus = !blueStatus;
    blueSwitchTime = millis();
   }
}
