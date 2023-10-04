//Team DAQni
//Benson Pulver, Bronson Wright, Emily Ericson, Maggie Scott
//Mechatronics
//Fall 2023 

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

#define m1int 18         // Motor 1 interrupt
#define m2int 19         // Motor 2 interrupt
#define m3int 20         // Motor 3 interrupt
#define led_r 22         // LED Red
#define led_g 24         // LED Green
#define led_b 26         // LED Blue
#define em 53            // Electromagnet enable
#define m1enc 30         // Motor 1 encoder direction
#define m2enc 32         // Motor 2 encoder direction
#define m3enc 34         // Motor 3 encoder direction
#define block_sw 36      // Block sensing switch for the bottom of the collection tray
#define ref1 23          // Reflectance channel 1
#define ref2 37          // Reflectance channel 2
#define ref3 25          // Reflectance channel 3
#define ref4 39          // Reflectance channel 4
#define ref5 27          // Reflectance channel 5
#define ref6 41          // Reflectance channel 6
#define ref7 29          // Reflectance channel 7
#define ref8 43          // Reflectance channel 8 
#define ref9 31          // Reflectance channel 9
#define ref10 45         // Reflectance channel 10
#define ref11 33         // Reflectance channel 11
#define ref12 47         // Reflectance channel 12
#define ref13 35         // Reflectance channel 13
#define photo A2         // Photoresistor measurement
#define hall A3          // Hall effect sensor measurement
#define dist1 A4         // Front distance sensor measurement
#define dist2 A5         // Rear distance sensor measurement

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

  bottomServo.attach(5);           //Attaches bottom servo to pin 5
  midServo.attach(3);              //Attaches middle servo to pin 3
  magnetServo.attach(48);          //Attaches magnet servo to pin 48

  pinMode(m1int,INPUT);
  pinMode(m2int,INPUT);
  pinMode(m3int,INPUT);
  pinMode(led_r,OUTPUT);
  pinMode(led_g,OUTPUT);
  pinMode(led_b,OUTPUT);
  pinMode(em,OUTPUT);
  pinMode(m1enc,INPUT);
  pinMode(m2enc,INPUT);
  pinMode(m3enc,INPUT);
  pinMode(block_sw,INPUT_PULLUP);
  pinMode(gearMotorClock, OUTPUT);
  pinMode(gearMotorCounter, OUTPUT);
  pinMode(gearMotorSpeed, OUTPUT);
  pinMode(ref1,INPUT);
  pinMode(ref2,INPUT);
  pinMode(ref3,INPUT);
  pinMode(ref4,INPUT);
  pinMode(ref5,INPUT);
  pinMode(ref6,INPUT);
  pinMode(ref7,INPUT);
  pinMode(ref8,INPUT);
  pinMode(ref9,INPUT);
  pinMode(ref10,INPUT);
  pinMode(ref11,INPUT);
  pinMode(ref12,INPUT);
  pinMode(ref13,INPUT);
  pinMode(photo,INPUT);
  pinMode(hall,INPUT);
  pinMode(dist1,INPUT);
  pinMode(dist2,INPUT);

  // Uncomment to flip a motor's direction:
  //md.flipM1(true);
  md.flipM2(true);

 // ************ SERIAL COMMUNICATION ************* 
    Serial.begin (115200);

    // Print a message to the computer through the USB
  Serial.println("Hello Computer!");

  // Open serial communications with the other Arduino board
  Serial1.begin(9600);

  // Send a message to the other Arduino board
  Serial1.print("Hello My Child Uno. Mama's Here.");

}

void loop()
{
 
  // If something is typed into the Serial Monitor, do this:
  if (Serial.available()) {
  // Read it and send it to the other Arduino
  mySerial.println(Serial.readStringUntil('\n'));
  }

  // // If a command is sent from the other Arduino
  //   if (mySerial.available() = drive ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   // Drive forward
  //   DriveForward();
  // }

  // if (mySerial.available() = right ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   TurnRight();
  // }
  
  // if (mySerial.available() = left ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   TurnLeft();
  // }

  // if (mySerial.available() = base ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   RotateArmBase();
  // }

  // if (mySerial.available() = mid ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   MoveMidServo();
  // } 

  // if (mySerial.available() = bottom ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   MoveBottomServo();
  // }

  // if (mySerial.available() = magnet ) {
  //   // Read it and display it on the Serial monitor
  //   Serial.println(mySerial.readStringUntil('\n'));
  //   MoveMagnetServo();
  // }

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

 void MoveBottomServo (int bottomServoAngle) {
  bottomServo.write(bottomServoAngle);
 }

void MoveMidServo (int midServoAngle) {
  midServo.write(midServoAngle);
 }

void MoveMagnetServo (int magnetServoAngle) {
  magnetServo.write(magnetServoAngle);
 }
