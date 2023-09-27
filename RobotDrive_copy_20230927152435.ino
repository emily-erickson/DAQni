#include "DualTB9051FTGMotorShield.h"

DualTB9051FTGMotorShield md;

void setup()
{
  Serial.begin(115200);
  Serial.println("Dual TB9051FTG Motor Shield");
  md.init();

  // M1 is right motor
  // M2 is left motor

  // Uncomment to flip a motor's direction:
  //md.flipM1(true);
  //md.flipM2(true);
}

void loop()
{
  md.enableDrivers();
  delay(1); // wait for drivers to be enabled so fault pins are no longer low

  // DRIVE FORWARD
    md.setM1Speed(400);
    md.setM2Speed(400);
    stopIfFault();

    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }

    delay(2);
  }

  // TURN RIGHT

    md.setM1Speed(0);
    md.setM2Speed(400);
    stopIfFault();

    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }

    delay(2);
  }
  
  // TURN LEFT

    md.setM1Speed(400);
    md.setM2Speed(0);
    stopIfFault();

    if (abs(i)%200 == 100)
    {
      Serial.print("M1 current: ");
      Serial.println(md.getM1CurrentMilliamps());
      Serial.print("M2 current: ");
      Serial.println(md.getM2CurrentMilliamps());
    }

    delay(2);
  }
  

// ************ USER DEFINED FUNCTIONS *******************

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
