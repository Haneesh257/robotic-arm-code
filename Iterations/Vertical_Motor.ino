#define dirPinA 5
#define stepPinA 4

#define stepsPerRevolutionA 5
#define stepsPerRevolutionB 10  // you can change this to anything you like

bool motorA_running = false;
bool motorA_dir = HIGH;

void setup() {    
  pinMode(stepPinA, OUTPUT);
  pinMode(dirPinA, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter command:");
  Serial.println("'w' = motor A forward once");
  Serial.println("'s' = motor A backward once");
  Serial.println("'q' = motor A continuous forward");
  Serial.println("'z' = motor A continuous backward");
  Serial.println("'a' = stop motor A");

}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    switch (input) {
      // Motor A commands
      case 'w':
        digitalWrite(dirPinA, HIGH);
        spinMotor(stepPinA, stepsPerRevolutionA * 5);  // motor A runs 100 steps
        break;
      case 's':
        digitalWrite(dirPinA, LOW);
        spinMotor(stepPinA, stepsPerRevolutionA * 5);
        break;
      case 'q':
        digitalWrite(dirPinA, HIGH);
        motorA_dir = HIGH;
        motorA_running = true;
        Serial.println("Motor A continuous forward");
        break;
      case 'z':
        digitalWrite(dirPinA, LOW);
        motorA_dir = LOW;
        motorA_running = true;
        Serial.println("Motor A continuous backward");
        break;
      case 'a':
        motorA_running = false;
        Serial.println("Motor A stopped");
        break;
    }
  }

  // Continuous motion
  if (motorA_running) {
    digitalWrite(dirPinA, motorA_dir);
    digitalWrite(stepPinA, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinA, LOW);
    delayMicroseconds(500);
  }   
}

// updated to accept step count
void spinMotor(int stepPin, int stepCount) {
  for (int i = 0; i < stepCount; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  Serial.println("Done spinning.");
}
