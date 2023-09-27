#include <List.hpp>
#include <string>

void setup() {
  // put your setup code here, to run once:
  

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Start by telling it what block is on chasis and where, give start command
// Follow line to chassis
// Press button, get block, update inventory
// Go to chassis
// Place all blocks

// Claw, inventory, body
class Robot{
  public:
    Robot(string startBlockColor, int startBlockPosition) {
      Inventory inventory(startBlockColor startBlockPosition);
      Arm arm;
      List<string> buildTarget;

      // this->startBlockColor = startBlockColor;
      // this->startBlockPosition = startBlockPosition;
      
      // this->pin = pin;
      // init();
    }

    /* This method sets the build target member variable. */
    void setBuildTarget(){
      this.buildTarget = inventory.decideBestVehicle(); // This might be the wrong use of "this."
    }
    // Should have method that removes a block from list of blocks that are necessary for part
  

    /* This method moves the robot to the dispensor.*/
    void collectBlock() {
      // Move arm to pick up block
      // Sense the color
      // Add block to inventory
    }

    void 

    /* This method examines what block are on top of the stacks and what blocks are needed for the vehicle.*/
    void determineNextBlockToPlace() {

    }

}

class Inventory{
  public:
    Inventory() {
      List<string> stack1(true);
      List<string> stack2(true);
      List<string> stack3(true);
      List<string> stack4(true);
      List<string> stack5(true);
      List<string> stack6(true);

      int redBlockCount = 0;
      int blueBlockCount = 0;
      int yellowBlockCount = 0;
      
      // Need to consider color and position of initial block. Increment blockCount and inform best vehicle strategy accordingly!!
      
      // this->startBlockColor = startBlockColor;
      // this->startBlockPosition = startBlockPosition;
      
    }


    /* This method takes in a block's color and places it at the top of the stack specified by the user.*/
    void addBlock(string color, int stackNum) {
      
    }

    /* This method removes the top block */
    void removeBlock(int stackNum) {

    }

    /* This method considers the blocks currently in inventory and determines what the highest point vehicle that can be built is. Returns a list of the blocks in the vehicle.*/
    List<string> decideBestVehicle(string startBlockColor, int startBlockPosition) {

    }

    /* This method checks if the next necessary block color is on top of any of the stacks. Returns the stack number if it is, otherwise returns -1.*/
    int isBlockAccessible(string color){

    }
}

class Arm{
  public:
    Arm() {
      DCMOTOR base;
      SERVO lowerJoint;
      SERVO upperJoint;
      SERVO endJoint;
      EMAG magnet;

      // Initialize the position of each motor/do other configuration
      
    }

    /* This method turns the electromagnet on.*/
    void engageMagnet(string color, int stackNum) {
      
    }

    /* This method turns the electromagnet off.*/
    void disengageMagnet(string color, int stackNum) {
      
    }

    /* This method rotates the base of the arm to a specified angle. */
    void rotateBase(int angle) {

    }

    /* This method sets the angle of the lower servo on the arm.*/
    void setLowerJointPosition(int angle) {

    }

    /* This method sets the angle of the upper servo on the arm.*/
    void setUpperJointPosition(int angle) {

    }

    /* This method sets the angle of the servo controlling the end joint on the arm.*/
    void setEndJointPosition(int angle) {

    }

    /* This method moves fuses a block to a given position on the chassis.*/
    void fuseBlock(int chassisPosition) {

    }

    /* This method computes the arm angles necessary to achieve a given arm position*/
    void computeArmAngles(int chassisPosition)
}