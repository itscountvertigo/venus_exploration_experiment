const int leftPin = 8;
const int rightPin = 7;

const float nrSpokes = 32;
const float revUpdate = 0.5 / nrSpokes;

bool leftStat = 0;
bool rightStat = 0;
bool leftStatPrev = 0;
bool rightStatPrev = 0;
float leftRevs = 0;
float rightRevs = 0;

void printStatus(float lStat, float rStat) {
  Serial.print("Left rev count = ");
  Serial.print(lStat);
  Serial.print(", Right rev count = ");
  Serial.println(rStat);
  return(0);
}

void setup() {
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  leftStat = digitalRead(leftPin);
  rightStat = digitalRead(rightPin);

  if (leftStat != leftStatPrev) {
    leftRevs = leftRevs + revUpdate;
  }
  if (rightStat != rightStatPrev) {
    rightRevs = rightRevs + revUpdate;
  }
  printStatus(leftRevs, rightRevs);
  
  leftStatPrev = leftStat;
  rightStatPrev = rightStat;
  delay(10);
}
