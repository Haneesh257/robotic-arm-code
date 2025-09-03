#include <ezButton.h> 
#include <Servo.h>

// Define Test Case (Button)
#define test1 14

// Define Servos (Gripper)
Servo servo1; // 150° servo
Servo servo2; // 270° servo

// Limit Switches
ezButton limitSwitch1(47);
ezButton limitSwitch2(45);
ezButton limitSwitch3(40);
ezButton limitSwitch4(10);
ezButton limitSwitch_HOME(11);


//Scissor Mechanism - High Torque Motor
#define scissor_in1 33   // scissor INA
#define scissor_in2 32   // scissor INB


// UP DOWN Motor Pins
#define dirPinA 5
#define stepPinA 4

// Variables for UP DOWN
#define stepsPerRevolutionA 5 // NOT PINS
#define stepsPerRevolutionB 10 // NOT PINS (Can be changed)
bool motorA_running = false;
bool motorA_dir = HIGH;

// Arm Extension
#define motorpin1 38   // angle IN1
#define motorpin2 39   // angle IN2
#define motorpin3 40   // rod   IN3
#define motorpin4 41   // rod   IN4

// Timing
#define ANGLE_MS 3000
#define ROD_MS   5000
#define GAP_MS   2000



void setup() {

  // Test Case (Button)
  pinMode(test1, INPUT_PULLUP);

  // Servo Motor
  servo1.attach(2, 500, 2500);  // []pin 2, min/max pulse for 150°
  servo2.attach(3, 500, 2500);  // pin 3, min/max pulse for 270°

  // Limit Switchs
  limitSwitch1.setDebounceTime(50);
  limitSwitch2.setDebounceTime(50);
  limitSwitch3.setDebounceTime(50);
  limitSwitch4.setDebounceTime(50);
  limitSwitch_HOME.setDebounceTime(50);
  Serial.begin(9600);


  // Scissor
  pinMode(scissor_in1, OUTPUT);
  pinMode(scissor_in2, OUTPUT);
  digitalWrite(scissor_in1, LOW);
  digitalWrite(scissor_in2, LOW);

  // UP DOWN Motor
  pinMode(dirPinA, OUTPUT);
  pinMode(stepPinA, OUTPUT);
  Serial.begin(9600);

  // Arm Extension
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(motorpin3, OUTPUT);
  pinMode(motorpin4, OUTPUT);

}

//Placeholder for door

//Placeholder for self defined functions

void loop() {

  if(!digitalRead(test1)) {

    func_main();

    // Random Stuff to test if it works
    Serial.println("Pressed");


    limitSwitch4.loop();
    limitSwitch_HOME.loop();
  
    // Limit Switch 4
    if (limitSwitch4.isPressed()) {
      Serial.println("LimitSwitch4: UNTOUCHED -> TOUCHED");
      }
    if (limitSwitch4.isReleased()) {
    Serial.println("LimitSwitch4: TOUCHED -> UNTOUCHED");
      }

    // Limit Switch HOME
    if (limitSwitch_HOME.isPressed()) {
      Serial.println("LimitSwitch_HOME: UNTOUCHED -> TOUCHED");
      }
    if(limitSwitch_HOME.isReleased()) {
      Serial.println("LimitSwitch_HOME: TOUCHED -> UNTOUCHED"); }
      }


}










// PRIMARY FUNCTIONS

///////////////////////////////////////
// FUNCTION 1 //
///////////////////////////////////////
void func1() {

  limitSwitch1.loop();
  
  if (limitSwitch1.isPressed()) {
    Serial.println("LimitSwitch1: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch1.isReleased()) {
    Serial.println("LimitSwitch2: UNTOUCHED -> TOUCHED");
  }

  int state1 = limitSwitch1.getState();

  if (state1==HIGH) {
    // Move Scissor Forward)
    scissor_forward();
    delay(80);
  }
  
  if (state1==LOW) {
    scissor_stop();
    delay(50); // For Debounce time
    delay(1000); // Delay for safety

    // MOVE UP AN DOWN
    digitalWrite(dirPinA, HIGH);
    spinMotor(stepPinA, stepsPerRevolutionA * 20);

    // Halt all Motor Pins for Arm
    rotate_stop();
    act_stop();

    delay(5000);

    // Rotate 90º and Stop
    rotate_1();
    delay(ANGLE_MS);
    rotate_stop();

    delay(GAP_MS);

    // Open Gripper
    servo1.write(150);

    // Extend Forward
    act_1();
    delay(ROD_MS);
    act_stop();

    // Gripper
    servo1.write(0);
    servo2.write(0);

    delay(30000); // Placeholder
      
    // Retract Backward
    act_2();
    delay(ROD_MS);
    act_stop();

    delay(GAP_MS);
    
    // Rotate to 0º and Stop
    rotate_2();
    delay(ANGLE_MS);
    rotate_stop();



    // DELAY TO SHOW THE OPPOSITE SIDE
    delay(10000);
    // DELAY TO SHOW THE OPPOSITE SIDE



    // Rotate -90º and Stop
    rotate_2();
    delay(ANGLE_MS);
    rotate_stop();

    delay(GAP_MS);

    // Open Gripper
    servo1.write(150);

    // Extend Forward
    act_1();
    delay(ROD_MS);
    act_stop();

    // Gripper
    servo1.write(0);
    servo2.write(0);

    delay(30000); // Placeholder

    // Retract Backward
    act_2();
    delay(ROD_MS);
    act_stop();

    // Rotate to 0º and Stop
    rotate_1();
    delay(ANGLE_MS);
    rotate_stop();


    // MOVE UP AND DOWN
    digitalWrite(dirPinA, LOW);
    spinMotor(stepPinA, stepsPerRevolutionA * 20);

    delay(45000);
  }
}






///////////////////////////////////////
// FUNCTION 2 //
///////////////////////////////////////
void func_main() {

  limitSwitch4.loop();
  limitSwitch_HOME.loop();
  
  // Limit Switch 4
  if (limitSwitch4.isPressed()) {
    Serial.println("LimitSwitch1: UNTOUCHED -> TOUCHED");
  }
  if (limitSwitch4.isReleased()) {
    Serial.println("LimitSwitch2: UNTOUCHED -> TOUCHED");
  }

  // Limit Switch HOME
  if (limitSwitch_HOME.isPressed()) {
    Serial.println("LimitSwitch_HOME: UNTOUCHED -> TOUCHED");
  }
  if(limitSwitch_HOME.isReleased()) {
    Serial.println("LimitSwitch_HOME: TOUCHED -> UNTOUCHED");
  }

  int state4 = limitSwitch4.getState();
  int state_HOME = limitSwitch_HOME.getState();

  if (state4==HIGH) {
    // Move Scissor Forward)
    scissor_forward();
    delay(80);
  }
  
  if (state4==LOW) {
    scissor_stop();
    delay(50);
    delay(1000);

    // MOVE UP AN DOWN
    digitalWrite(dirPinA, HIGH);
    spinMotor(stepPinA, stepsPerRevolutionA * 20);

    // Halt all Motor Pins for Arm
    rotate_stop();
    act_stop();

    delay(5000);

    // Rotate 90º and Stop
    rotate_1();
    delay(ANGLE_MS);
    rotate_stop();

    delay(GAP_MS);

    // Open Gripper
    servo1.write(150);

    // Extend Forward
    act_1();
    delay(ROD_MS);
    act_stop();

    // Gripper
    servo1.write(0);
    servo2.write(0);

    delay(30000); // Placeholder
      
    // Retract Backward
    act_2();
    delay(ROD_MS);
    act_stop();

    delay(GAP_MS);
    
    // Rotate to 0º and Stop
    rotate_2();
    delay(ANGLE_MS);
    rotate_stop();



    // DELAY TO SHOW THE OPPOSITE SIDE
    delay(10000);
    // DELAY TO SHOW THE OPPOSITE SIDE



    // Rotate -90º and Stop
    rotate_2();
    delay(ANGLE_MS);
    rotate_stop();

    delay(GAP_MS);

    // Open Gripper
    servo1.write(150);

    // Extend Forward
    act_1();
    delay(ROD_MS);
    act_stop();

    // Gripper
    servo1.write(0);
    servo2.write(0);

    delay(30000); // Placeholder

    // Retract Backward
    act_2();
    delay(ROD_MS);
    act_stop();

    // Rotate to 0º and Stop
    rotate_1();
    delay(ANGLE_MS);
    rotate_stop();


    // MOVE UP AND DOWN
    digitalWrite(dirPinA, LOW);
    spinMotor(stepPinA, stepsPerRevolutionA * 20);

    delay(45000);

    if(state_HOME==HIGH) {
      scissor_backward();
      delay(50);
    }

    if(state_HOME==LOW) {
      scissor_stop();
      delay(50);
    }

  }
}










//////////////////////////////////////////////////////////////////////
// Encapsulation Functions
//////////////////////////////////////////////////////////////////////


// SpinMotor Function

void spinMotor(int stepPin, int stepCount) {
  for (int i = 0; i < stepCount; i++) {
    digitalWrite(stepPinA, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinA, LOW);
    delayMicroseconds(500);

  }

  Serial.println("Done Spinning");
}



// Scissor Mechanism

void scissor_forward() {
  digitalWrite(scissor_in1, HIGH);
  digitalWrite(scissor_in2, LOW);
}

void scissor_backward() {
  digitalWrite(scissor_in1, LOW);
  digitalWrite(scissor_in2, HIGH);
}

void scissor_stop() {
  digitalWrite(scissor_in1, LOW);
  digitalWrite(scissor_in2, LOW);
}



// Arm Mechanism

/* Rotation */
void rotate_1() {
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
}

void rotate_2() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
}

void rotate_stop() {
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);
}


/* Actuation */
void act_1() {
  digitalWrite(motorpin3, HIGH);
  digitalWrite(motorpin4, LOW);
}

void act_2() {
  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, HIGH);
}

void act_stop() {
  digitalWrite(motorpin3, LOW);
  digitalWrite(motorpin4, LOW);
}