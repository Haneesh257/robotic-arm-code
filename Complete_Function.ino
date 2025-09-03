#include <ezButton.h>

// Panel 1 and 2
ezButton limitSwitch1(4);  // Define ezButton Object as LimitSwitch
ezButton limitSwitch2(5);
ezButton limitSwitch3(6);
ezButton limitSwitch4(7);

// Home Limit Switch
ezButton limitSwitch_HOME(8);


#define scissor_motor_pin1 2  // Forward
#define scissor_motor_pin2 3  // Backward


//////////////////////////////////////////////////////////////////////////////////////////////////


// Turning Motor
#define arm_motor_pin1 9
#define arm_motor_pin2 10

//Actuating Motor
#define arm_actuator_pin3 11
#define arm_actuator_pin4 12

// Button Extensions (Placeholder)
#define func1_LEFT 2
#define func1_RIGHT 3
#define func2_LEFT 14
#define func2_RIGHT 15


void setup() {

  pinMode(arm_motor_pin1, OUTPUT);
  pinMode(arm_motor_pin2, OUTPUT);
  pinMode(arm_actuator_pin3, OUTPUT);
  pinMode(arm_actuator_pin4, OUTPUT);
  pinMode(10, OUTPUT); // ENA Speed Control Pin

  pinMode(func1_RIGHT, INPUT_PULLUP);
  pinMode(func1_LEFT, INPUT_PULLUP);
  pinMode(func2_RIGHT, INPUT_PULLUP);
  pinMode(func2_LEFT, INPUT_PULLUP);




  pinMode(scissor_motor_pin1, OUTPUT);
  pinMode(scissor_motor_pin2, OUTPUT);

  Serial.begin(9600);
  limitSwitch1.setDebounceTime(50);  // Set limitSwitch Object to debounce at 50 ms
  limitSwitch2.setDebounceTime(50);  // Set limitSwitch Object to debounce at 50 ms
  limitSwitch3.setDebounceTime(50);  // Set limitSwitch Object to debounce at 50 ms
  limitSwitch4.setDebounceTime(50);  // Set limitSwitch Object to debounce at 50 ms
  limitSwitch_HOME.setDebounceTime(50);
}

void loop() {

  // First Define everything to do with the limit switch and then define the other functions inside of it

  limitSwitch1.loop();  // Must be included before all of the code for the limitSwitch, to make sure that the code will keep on looping
  limitSwitch2.loop();
  limitSwitch3.loop();
  limitSwitch4.loop();
  limitSwitch_HOME.loop();

  // FOR Limit Switch 1

  if (limitSwitch1.isPressed()) {
    Serial.println("The limit switch1: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch1.isReleased()) {
    Serial.println("The limit switch1: TOUCHED -> UNTOUCHED");
  }

  // FOR Limit Switch 2

  if (limitSwitch2.isPressed()) {
    Serial.println("The limit switch2: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch2.isReleased()) {
    Serial.println("The limit switch2: TOUCHED -> UNTOUCHED");
  }

  // FOR Limit Switch 3

  if (limitSwitch3.isPressed()) {
    Serial.println("The limit switch3: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch3.isReleased()) {
    Serial.println("The limit switch3: TOUCHED -> UNTOUCHED");
  }

  // FOR Limit Switch 4

  if (limitSwitch4.isPressed()) {
    Serial.println("The limit switch4: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch4.isReleased()) {
    Serial.println("The limit switch4: TOUCHED -> UNTOUCHED");
  }


  // FOR Limit Switch HOME

  if (limitSwitch_HOME.isPressed()) {
    Serial.println("The limit switch_HOME: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch_HOME.isReleased()) {
    Serial.println("The limit switch_HOME: TOUCHED -> UNTOUCHED");
  }



  int state1 = limitSwitch1.getState();
  int state2 = limitSwitch2.getState();
  int state3 = limitSwitch3.getState();
  int state4 = limitSwitch4.getState();
  int state_HOME = limitSwitch_HOME.getState();





//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



//
// Function 1 (Extend to the LEFT) -> PANEL 1 FRONTSIDE
//
  if (!digitalRead(func1_LEFT)) {
    

    ///////////////////////////////////////////////////////////////////////////
    // Move to Front of Panel 1
    Panel_1_Front(); 
    ///////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000); 
    ///////////////////////////////////////////////////////////////////////////



    // MOVE UP to POS1
    /* PLEASE FILL IN */



    ///////////////////////////////////////////////////////////////////////////
    // Start Arm + Gripper Code

    // 0º -> -90º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    delay(5000);

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();
    
    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE THE GRIPPER KEEPS GRIPPING)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // -90º -> 0º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE PANEL GOES TO DROP THE MUSHROOM)

    // 0º -> -90º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE GRIPPER UNGRIPS AND RETURNS TO ORIGINAL STATE)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // -90º -> 0º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000);
    ///////////////////////////////////////////////////////////////////////////

    Panel_Home();
    // END FUNCTION //
    

  }





//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




//
// Function 1 (Extend to the RIGHT) -> PANEL 1 FRONTSIDE
//
  if(!digitalRead(func1_RIGHT)) {

      

    ///////////////////////////////////////////////////////////////////////////
    // Move to Front of Panel 1
    Panel_1_Front(); 
    ///////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000); 
    ///////////////////////////////////////////////////////////////////////////



    // MOVE UP to POS1
    /* PLEASE FILL IN */



    ///////////////////////////////////////////////////////////////////////////
    // Start Arm + Gripper Code

    // 0º -> 90º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    delay(5000);

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();
    
    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE THE GRIPPER KEEPS GRIPPING)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // 90º -> 0º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE PANEL GOES TO DROP THE MUSHROOM)

    // 0º -> 90º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE GRIPPER UNGRIPS AND RETURNS TO ORIGINAL STATE)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // 90º -> 0º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000);
    ///////////////////////////////////////////////////////////////////////////

    Panel_Home();
    // END FUNCTION //
  }



//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



//
// Function 2 (Extend to the LEFT) -> PANEL 1 BACKSIDE
//
  if (!digitalRead(func2_LEFT)) {
    

    ///////////////////////////////////////////////////////////////////////////
    // Move to BACK of Panel 1
    Panel_2_Front(); 
    ///////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000); 
    ///////////////////////////////////////////////////////////////////////////



    // MOVE UP to POS1
    /* PLEASE FILL IN */



    ///////////////////////////////////////////////////////////////////////////
    // Start Arm + Gripper Code

    // 0º -> -90º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    delay(5000);

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();
    
    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE THE GRIPPER KEEPS GRIPPING)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // -90º -> 0º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE PANEL GOES TO DROP THE MUSHROOM)

    // 0º -> -90º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE GRIPPER UNGRIPS AND RETURNS TO ORIGINAL STATE)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // -90º -> 0º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000);
    ///////////////////////////////////////////////////////////////////////////

    Panel_Home();
    // END FUNCTION //
    

  }





//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////




//
// Function 2 (Extend to the RIGHT) -> PANEL 1 BACKSIDE
//
  if(!digitalRead(func2_RIGHT)) {

      

    ///////////////////////////////////////////////////////////////////////////
    // Move to BACK of Panel 1
    Panel_2_Front(); 
    ///////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000); 
    ///////////////////////////////////////////////////////////////////////////



    // MOVE UP to POS1
    /* PLEASE FILL IN */



    ///////////////////////////////////////////////////////////////////////////
    // Start Arm + Gripper Code

    // 0º -> 90º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    delay(5000);

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();
    
    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE THE GRIPPER KEEPS GRIPPING)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // 90º -> 0º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE PANEL GOES TO DROP THE MUSHROOM)

    // 0º -> 90º -> STOP
    rotate_backward();
    delay(3500);
    stop_rotate();

    // Extend in 6s -> STOP
    actuate_forward();
    delay(6000);
    stop_actuate();

    delay(5000); // PLACEHOLDER ==> CHANGE LATER (MAKE SURE GRIPPER UNGRIPS AND RETURNS TO ORIGINAL STATE)

    // Gripper Gripping -> Actuator Retract in 6s
    actuate_backward();
    delay(6000);
    stop_actuate();

    // 90º -> 0º -> STOP
    rotate_forward();
    delay(3500);
    stop_rotate();
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    // Delay just to be Safe
    delay(3000);
    ///////////////////////////////////////////////////////////////////////////

    Panel_Home();
    // END FUNCTION //
  }



}












// Encapsulated Helper Functions


///////////////////////////////////////////////////////////////////////////////////
// MOTOR FUNCTIONS //
///////////////////////////////////////////////////////////////////////////////////

void rotate_forward() {
  digitalWrite(arm_motor_pin1, HIGH);
  digitalWrite(arm_motor_pin2, LOW);
}

void rotate_backward() {
  digitalWrite(arm_motor_pin1, LOW);
  digitalWrite(arm_motor_pin2, HIGH);
}

void stop_rotate() {
  digitalWrite(arm_motor_pin1, LOW);
  digitalWrite(arm_motor_pin2, LOW);
}


// Actuator Functions
void actuate_forward() {
  digitalWrite(arm_actuator_pin3, HIGH);
  digitalWrite(arm_actuator_pin4, LOW);
}

void actuate_backward() {
  digitalWrite(arm_actuator_pin3, LOW);
  digitalWrite(arm_actuator_pin4, HIGH);
}

void stop_actuate() {
  digitalWrite(arm_actuator_pin3, LOW);
  digitalWrite(arm_actuator_pin4, LOW);
}

///////////////////////////////////////////////////////////////////////////////////
// LIMIT SWITCHES //
///////////////////////////////////////////////////////////////////////////////////


// PANEL 1 FRONT SIDE 
void Panel_1_Front() {

  limitSwitch1.loop();

  if (limitSwitch1.isPressed()) {
    Serial.println("The limit switch1: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch1.isReleased()) {
    Serial.println("The limit switch1: TOUCHED -> UNTOUCHED");
  }

  int state1 = limitSwitch1.getState();

  if (state1 == HIGH) {
    forward();
    delay(100);
  } else if (state1 == LOW) {
    stop();
    delay(100);
  }
}





//PANEL 2 FRONT SIDE
void Panel_2_Front() {

  limitSwitch2.loop();

  if (limitSwitch2.isPressed()) {
    Serial.println("The limit switch2: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch2.isReleased()) {
    Serial.println("The limit switch2: TOUCHED -> UNTOUCHED");
  }

  int state2 = limitSwitch2.getState();



  if (state2 == HIGH) {
    forward();
    delay(100);
  } else if (state2 == LOW) {
    stop();
    delay(100);
  }
}





//PANEL 3 FRONT SIDE
void Panel_3_Front() {
  limitSwitch3.loop();

  if (limitSwitch3.isPressed()) {
    Serial.println("The limit switch3: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch3.isReleased()) {
    Serial.println("The limit switch3: TOUCHED -> UNTOUCHED");
  }

  int state3 = limitSwitch3.getState();

  if (state3 == HIGH) {
    forward();
    delay(100);
  }

  else if (state3 == LOW) {
    stop();
    delay(100);
  }

}




// PANEL 4 FRONT SIDE
void Panel_4_Front() {
  limitSwitch4.loop();

  if(limitSwitch4.isPressed()) {
    Serial.println("The limit switch4: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch4.isReleased()) {
    Serial.println("The limit switch4: TOUCHED -> UNTOUCHED");
  }

  int state4 = limitSwitch4.getState();

  if (state4==HIGH) {
    forward();
    delay(100);
  }

  if(state4==LOW) {
    stop();
    delay(100);
  }

}




//PANEL HOME (RETURNING FUNCTION);
void Panel_Home() {
  limitSwitch_HOME.loop();

  if (limitSwitch_HOME.isPressed()) {
    Serial.println("The limit switch_HOME: UNTOUCHED -> TOUCHED");
  }

  if (limitSwitch_HOME.isReleased()) {
    Serial.println("The limit switch_HOME: TOUCHED -> UNTOUCHED");
  }

  int state_HOME = limitSwitch_HOME.getState();

  if (state_HOME==HIGH) {
    backward();
    delay(100);
  }

  if(state_HOME==LOW) {
    stop();
    delay(100);
  }
}


///////////////////////////////////////////////////////////////////////////////////
// LIMIT SWITCH HELPERS
///////////////////////////////////////////////////////////////////////////////////

void forward() {
  digitalWrite(scissor_motor_pin1, HIGH);
  digitalWrite(scissor_motor_pin2, LOW);
}

void backward() {
  digitalWrite(scissor_motor_pin1, LOW);
  digitalWrite(scissor_motor_pin2, HIGH);
}

void stop() {
  digitalWrite(scissor_motor_pin1, LOW);
  digitalWrite(scissor_motor_pin2, LOW);
}


