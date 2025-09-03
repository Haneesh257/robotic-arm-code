#define motorpin1 2
#define motorpin2 3

#define act_ext 4
#define act_ret 5

#define but_ext_90 6
#define but_ret_90 7
#define but_ext_m90 8
#define but_ret_m90 9


void setup() {

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(10, OUTPUT); // ENA Speed Control Pin

  pinMode(act_ext, OUTPUT);
  pinMode(act_ret, OUTPUT);

  pinMode(but_ext_90, INPUT_PULLUP);
  pinMode(but_ret_90, INPUT_PULLUP);

  pinMode(but_ext_m90, INPUT_PULLUP);
  pinMode(but_ret_m90, INPUT_PULLUP);

}

void loop() {

  analogWrite(10, 100); // Max = 250





//
// Function 1 (Extend to the Right)
//
  if(!digitalRead(but_ext_90)) {
    // Turn Motor 90º in 5 seconds and then stop it
    digitalWrite(motorpin1, HIGH); 
    digitalWrite(motorpin2, LOW);

    delay(5000);

    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);

    // Extend Actuator
    digitalWrite(act_ext, HIGH);
    digitalWrite(act_ret, LOW);
    delay(15600);

    // Input Gripper Mechanism Function (Gripping)

  }





//
// Function 2 (Retract from the Right)
//
  if (!digitalRead(but_ret_90)) {

    // Input Gripper Mechanism Function (Release)

    // Retract Actuator
    digitalWrite(act_ext, LOW);
    digitalWrite(act_ret, HIGH);
    delay(15600);

    // Turn Motor 0º in 5 seconds and then stop it
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);
    
    delay(5000);

    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);


  }





//
// Function 3 (Extend to the Left)
//
  if(!digitalRead(but_ext_m90)) {
    // Turn Motor -90º in 5 seconds and then stop it
    digitalWrite(motorpin1, LOW); 
    digitalWrite(motorpin2, HIGH);

    delay(5000);

    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);

    // Extend Actuator
    digitalWrite(act_ext, HIGH);
    digitalWrite(act_ret, LOW);
    delay(15600);

    // Input Gripper Mechanism Function (Gripping)

  }





//
// Function 4 (Retract from the Left)
//
  if (!digitalRead(but_ret_m90)) {

    // Input Gripper Mechanism Function (Release)

    // Retract Actuator
    digitalWrite(act_ext, LOW);
    digitalWrite(act_ret, HIGH);
    delay(15600);

    // Turn Motor 0º in 5 seconds and then stop it
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
    
    delay(5000);

    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, HIGH);


  }
}


