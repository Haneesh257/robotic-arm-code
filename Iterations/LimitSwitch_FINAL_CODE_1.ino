#include <ezButton.h>

// Panel 1 and 2
ezButton limitSwitch1(4); // Define ezButton Object as LimitSwitch
ezButton limitSwitch2(5);
ezButton limitSwitch3(6);
ezButton limitSwitch4(7);

// Home Limit Switch
ezButton limitSwitch_HOME(8);


#define motorpin1 12 // Forward
#define motorpin2 13 // Backward

void setup() {

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);

  Serial.begin(9600);
  limitSwitch1.setDebounceTime(50); // Set limitSwitch Object to debounce at 50 ms
  limitSwitch2.setDebounceTime(50); // Set limitSwitch Object to debounce at 50 ms
  limitSwitch3.setDebounceTime(50); // Set limitSwitch Object to debounce at 50 ms
  limitSwitch4.setDebounceTime(50); // Set limitSwitch Object to debounce at 50 ms

}

void loop() {

  // First Define everything to do with the limit switch and then define the other functions inside of it

  limitSwitch1.loop(); // Must be included before all of the code for the limitSwitch, to make sure that the code will keep on looping
  limitSwitch2.loop();
  limitSwitch3.loop();
  limitSwitch4.loop();
  limitSwitch_HOME.loop();

// FOR Limit Switch 1

  if(limitSwitch1.isPressed()) {
    Serial.println("The limit switch1: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch1.isReleased()) {
    Serial.println("The limit switch1: TOUCHED -> UNTOUCHED");
  }

// FOR Limit Switch 2

  if(limitSwitch2.isPressed()) {
    Serial.println("The limit switch2: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch2.isReleased()) {
    Serial.println("The limit switch2: TOUCHED -> UNTOUCHED");
  }

// FOR Limit Switch 3

  if(limitSwitch3.isPressed()) {
    Serial.println("The limit switch3: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch3.isReleased()) {
    Serial.println("The limit switch3: TOUCHED -> UNTOUCHED");
  }

// FOR Limit Switch 4

  if(limitSwitch4.isPressed()) {
    Serial.println("The limit switch4: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch4.isReleased()) {
    Serial.println("The limit switch4: TOUCHED -> UNTOUCHED");
  }


// FOR Limit Switch HOME

  if(limitSwitch_HOME.isPressed()) {
    Serial.println("The limit switch_HOME: UNTOUCHED -> TOUCHED");
  }

  if(limitSwitch_HOME.isReleased()) {
    Serial.println("The limit switch_HOME: TOUCHED -> UNTOUCHED");
  }



  int state1 = limitSwitch1.getState();
  int state2 = limitSwitch2.getState();
  int state3 = limitSwitch3.getState();
  int state4 = limitSwitch4.getState();
  int state_HOME = limitSwitch_HOME.getState();



/////////////////////////////////////////////////////////////////////////////////

// PANEL 1 //

/////////////////////////////////////////////////////////////////////////////////
// PANEL 1, FRONT -> GO TO 

  if (state1==HIGH) { // Limit Switch is Untouched and Motor Runs
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  else if (state1==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// Execute Gripper
// Retract Gripper

// PANEL 1, FRONT -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  else if (state2==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// PANEL 1, BACK -> GO TO

  if (state2==HIGH) {
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state2==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// Execute Gripper
// Retract Gripper

// PANEL 1, BACK -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state2==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }
/////////////////////////////////////////////////////////////////////////////////

// PANEL 2 //

/////////////////////////////////////////////////////////////////////////////////
// PANEL 2, FRONT -> GO TO 

  if (state3==HIGH) { // Limit Switch is Untouched and Motor Runs
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state3==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// Execute Gripper
// Retract Gripper

// PANEL 2, FRONT -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state3==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// PANEL 2, BACK -> GO TO

  if (state4==HIGH) {
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state4==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }

// Execute Gripper
// Retract Gripper

// PANEL 2, BACK -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state4==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
    delay(50);
  }



/*
/////////////////////////////////////////////////////////////////////////////////

// PANEL 3 //

/////////////////////////////////////////////////////////////////////////////////
// PANEL 3, FRONT -> GO TO 

  if (state==HIGH) { // Limit Switch is Untouched and Motor Runs
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state5==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// Execute Gripper
// Retract Gripper

// PANEL 3, FRONT -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state5==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// PANEL 3, BACK -> GO TO

  if (state6==HIGH) {
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state6==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// Execute Gripper
// Retract Gripper

// PANEL 3, BACK -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state6==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }
/////////////////////////////////////////////////////////////////////////////////

// PANEL 4 //

/////////////////////////////////////////////////////////////////////////////////
// PANEL 4, FRONT -> GO TO 

  if (state7==HIGH) { // Limit Switch is Untouched and Motor Runs
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state7==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// Execute Gripper
// Retract Gripper
// PANEL 4, FRONT -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state7==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// PANEL 4, BACK -> GO TO

  if (state8==HIGH) {
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }

  if (state8==LOW && state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }

// Execute Gripper
// Retract Gripper

// PANEL 4, BACK -> GO BACK

  if (state_HOME==HIGH) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
  }

  if (state8==HIGH && state_HOME==LOW) {
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }
/////////////////////////////////////////////////////////////////////////////////

*/

}
