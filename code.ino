char t;
const int buzzerPin = 7;
const int flamePin = 5;
int Flame = HIGH;

void setup() {
  pinMode(13, OUTPUT);  // left motors forward
  pinMode(12, OUTPUT);  // left motors reverse
  pinMode(11, OUTPUT);  // right motors forward
  pinMode(10, OUTPUT);  // right motors reverse
  pinMode(7, INPUT);    // buzzer sensor
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {  // move forward (all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  } else if (t == 'B') {  // move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  } else if (t == 'L') {  // turn right (left side motors rotate in forward direction, right side motors don't rotate)
    digitalWrite(11, HIGH);
  } else if (t == 'R') {  // turn left (right side motors rotate in forward direction, left side motors don't rotate)
    digitalWrite(13, HIGH);
  } else if (t == 'S') {  // STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  
  delay(100);
  Flame = digitalRead(flamePin);
  if (Flame == LOW) {
    Serial.println("Fire!!!");
    digitalWrite(buzzerPin, HIGH);
  } else {
    Serial.println("No worries");
    digitalWrite(buzzerPin, LOW);
  }
}
