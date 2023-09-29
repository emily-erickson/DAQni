/****************************
 ** #defines and #includes **
 ****************************/

#include <Servo.h>
#include "DualTB9051FTGMotorShield.h"
#include <SoftwareSerial.h>
#include <PWMServo.h>

DualTB9051FTGMotorShield md;
SoftwareSerial mySerial(10, 11); // RX, TX

/***********************
 ** Global Variables ***
 ***********************/

// *** Declare & Initialize Pins ***
const int gearMotorClock = 42;
const int gearMotorCounter = 44;
const int gearMotorSpeed = 46;
const int bottomServoPin = 
const int midServoPin = 
const int magnetServoPin = 

// *** Create Servo Objects ***
Servo bottomServo;
Servo midServo;
Servo magnetServo;

// *** Declare & Initialize Global Program Variables ***
char drive = 'd';
char right = 'r';
char left = 'l';
char base = 'b';
char bottom = 't';
char mid = 'm';
char magnet = 'a';

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while (1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while (1);
  }
}

  // M1 is left motor (from above)
  // M2 is right motor (from above)

void setup()
{
  Serial.begin(115200);
  Serial.println("Dual TB9051FTG Motor Shield");
  md.init();

  pinMode(gearMotorClock, OUTPUT);
  pinMode(gearMotorCounter, OUTPUT);
  pinMode(gearMotorSpeed, OUTPUT);

  bottomServo.attach(bottomServoPin);
  midServo.attach(midServoPin);
  magnetServo.attach(magnetServopin);

  // Uncomment to flip a motor's direction:
  //md.flipM1(true);
  md.flipM2(true);

 // ************ SERIAL COMMUNICATION ************* 
  // Serial1.begin (9600);

    // Print a message to the computer through the USB
  Serial.println("Hello Computer!");

  // Open serial communications with the other Arduino board
  mySerial.begin(9600);

  // Send a message to the other Arduino board
  mySerial.print("Hello My Child (Uno). Mama's Here.");

}

void loop()
{
 
  // If something is typed into the Serial Monitor, do this:
  if (Serial.available()) {
  // Read it and send it to the other Arduino
  mySerial.println(Serial.readStringUntil('\n'));
  }

  // If a command is sent from the other Arduino
    if (mySerial.available() = drive ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    // Drive forward
    DriveForward();
  }

  if (mySerial.available() = right ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    TurnRight();
  }
  
  if (mySerial.available() = left ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    TurnLeft();
  }

  if (mySerial.available() = base ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    RotateArmBase();
  }

  if (mySerial.available() = mid ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    MoveMidServo();
  } 

  if (mySerial.available() = bottom ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    MoveBottomServo();
  }

  if (mySerial.available() = magnet ) {
    // Read it and display it on the Serial monitor
    Serial.println(mySerial.readStringUntil('\n'));
    MoveMagnetServo();
  }

  md.enableDrivers();
  delay(1); // wait for drivers to be enabled so fault pins are no longer low

}

// **************************************************************************
// ********************** USER DEFINED FUNCTIONS ****************************
// **************************************************************************

 void DriveForward(void) {
    // DRIVE FORWARD
    // Accelerate for two seconds
   for (int i = 0; i <= 400; i++)
    {
    md.setM1Speed(i);
    md.setM2Speed(i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());

    }
      delay(5);
    }
 
    // Deccelerate for two seconds
    for (int i = 400; i >= 0; i--)
   {
    md.setM1Speed(i);
    md.setM2Speed(i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());

    }
    delay(2);
   }
 }

void TurnRight (void) { 
  // TURN RIGHT
   for (int i = 0; i <= 400; i++)
  {
    md.setM1Speed(i);
    md.setM2Speed(-i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }

  // Deccelerate for two seconds
    for (int i = 400; i >= 0; i--)
  {
    md.setM1Speed(i);
    md.setM2Speed(-i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
  }
}

void TurnLeft (void) {
    // TURN LEFT
     for (int i = 0; i <= 400; i++)
   {
    md.setM2Speed(i);
    md.setM1Speed(-i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
   }

   // Deccelerate for two seconds
    for (int i = 400; i >= 0; i--)
   {
    md.setM2Speed(i);
    md.setM1Speed(-i);
    stopIfFault();
    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM1CurrentMilliamps());
    }
    delay(2);
   }
}

void RotateArmBase(int turnTime) {

 digitalWrite(gearMotorClock, HIGH);
 digitalWrite(gearMotorCounter, LOW);
 for (int j = 0; j <= 255; j++)
  {
    analogWrite(gearMotorSpeed, j);
  }
 delay(3000);


   for (int j = 255; j <= 0; j--)
  {
    analogWrite(gearMotorSpeed, j);
  }
 delay(3000);


  digitalWrite(gearMotorClock, LOW);
  digitalWrite(gearMotorCounter, HIGH);
  for (int j = 0; j <= 255; j++)
   {
    analogWrite(gearMotorSpeed, j);
   }
  delay(3000);


     for (int j = 255; j <= 0; j--)
    {
      analogWrite(gearMotorSpeed, j);
    }
   delay(3000);
  }
}

 void MoveBottomServo (int bottomServoAngle) {
  bottomServo.write(bottomServoAngle);
 }

void MoveMidServo (int midServoAngle) {
  midServo.write(midServoAngle);
 }

void MoveMagnetServo (int magnetServoAngle) {
  magnetServo.write(magnetServoAngle);
 }
