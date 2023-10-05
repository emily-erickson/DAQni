/**
UNO CODE
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()  
{
  // Open serial communications with computer and wait for port to open:
  Serial.begin(9600);
  // Open serial communications with the other Arduino board
  mySerial.begin(9600);

}

void loop() // run over and over
{
// If something is typed into the Serial Monitor, do this:
 if (Serial.available()) {
  String input = Serial.readStringUntil('\n');
  mySerial.print(input);
  Serial.print(input);n(Serial.readStringUntil('\n'));
}
}

