#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()  
{
  // Open serial communications with computer and wait for port to open:
  Serial.begin(115200);

  // Print a message to the computer through the USB
  Serial.println("Hello Computer!");

  // Open serial communications with the other Arduino board
  mySerial.begin(9600);

  // Send a message to the other Arduino board
  mySerial.print("Hello Mother Mega");

}

void loop() // run over and over
{
// If something is typed into the Serial Monitor, do this:
if (Serial.available()) {
// Read it and send it to the other Arduino
mySerial.println(Serial.readStringUntil('\n'));
}

// If something is sent from the other Arduino
if (mySerial.available()) {
  // Read it and display it on the Serial monitor
  Serial.println(mySerial.readStringUntil('\n'));

}

}
