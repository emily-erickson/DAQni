/****************************
MEGA CODE
 ****************************/

bool electromagnetOn = false;
 

void setup()
{
  

  Serial.begin(9600);
  Serial3.begin(9600);

}

void loop()
{
  // Read received command from buffer
  if(Serial3.available()){
    char receivedCommand = Serial3.read();
    Serial.println(receivedCommand);
    }
  
  // Translate receivedCommand to robot action
    switch (command) {
    case 'f':
      RunForwardDemo();
    break;
    // Drive backward
    case 'b':
      RunBackwardDemo();
    break;
    // Turn left
    case 'l':
      LeftTurnDemo();
    break;
    // Turn right
    case 'r':
      RightTurnDemo();
    break;
    // Turn base
    case 't':
      TurnBaseDemo();
    break;
    // Adjust arm bottom link
    case '3':
      AdjustBottomLinkDemo();
    break;
    // Adjust arm middle link
    case '2':
      AdjustMiddleLinkDemo();
    break;
    // Adjust arm magnet link
    case '1':
      ToggleArmMagnetDemo();
    break;
    default:
      Serial.println("Received command didn't match any of the cases");
}
  // md.enableDrivers();
  // delay(1); // wait for drivers to be enabled so fault pins are no longer low
  }

  void RunForwardDemo(){

  }

  void RunBackwardDemo(){

  }

  void LeftTurnDemo(){

  }

  void RightTurnDemo(){

  }

  void TurnBaseDemo(){

  }

  void AdjustBottomLinkDemo(){
    
  }

  void AdjustMiddleLinkDemo(){

  }

  void ToggleArmMagnetDemo(){
    // If electromagnet not on, turn it on. If it is on, turn it off.
    // if(!electromagnetOn){
    //   digitalWrite(em,HIGH); 
    // }
    // else{
    //   digitalWrite(em,LOW); 
    // }

  }




  


