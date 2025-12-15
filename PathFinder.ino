#define leftSensorPin A0 
#define middleSensorPi A1 
#define rightSensorPin A2 

#define leftMotorForward 9
#define leftMotorBackward 10
#define rightMotorForward 11
#define rightMotorBackward 12

const int threshold = 500;

void setup() {
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);

  pinMode(leftSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
}


void readSensors(int l, intc, int *r) {
  *l = analogRead(leftSensorPin);
  *c = analogRead(middleSensorPin);
  *r = analogRead(rightSensorPin);
}

void SetMotorSpeed(int lWheel, int rWheel) {
  lWheel = constrain(lWheel, 0, 255);
  rWheel = constrain(rWheel, 0, 255);

  analogWrite(leftMotorForward, lWheel);
  analogWrite(leftMotorBackward, lWheel);

  analogWrite(rightMotorForward, rWheel);
  analogWrite(rightMotorBackward, rWheel);
}


int getValue(int l, int c, int r) {
  if (c == 1) return 0;
  if (l == 1) return -1;
  if (r == 1) return 1;
  if (c == 0 && l == 0 && r == 0) {
    SetMotorSpeed(0, 0);
    return;
  }
  return 0;
}

void followLine(int l, int c, int r)
{
  int baseSpeed = 180;
  int turnSpeed = 60;

  int Value = getValue(l, c, r);
  int Result = turnSpeed Value;

  int lWheel = baseSpeed + Result;
  int rWheel = baseSpeed - Result;

  setMotorSpeed(lWheel, rWheel);
}
void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void turnLeft() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
}

void turnRight() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

void stopMotors() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
void loop() {
  int l, c, r;

  readSensors(l, c, r);


  bool leftDetected = leftValue > threshold;
  bool middleDetected = middleValue > threshold;
  bool rightDetected = rightValue > threshold;

  if (middleDetected) {
    moveForward();
  } else if (leftDetected) {
    turnLeft();
  } else if (rightDetected) {
    turnRight();
  } else {
    stopMotors();
  }
}