// ---------------- PIN SETUP ----------------
const int redLED    = 12;
const int greenLED  = 11;
const int blueLED   = 10;
const int yellowLED = 9;

const int redBtn    = 5;
const int greenBtn  = 4;
const int blueBtn   = 3;
const int yellowBtn = 2;

// ---------------- GAME VARIABLES ----------------
int sequence[50];     // max sequence length
int level = 0;

// ---------------- SETUP ----------------
void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  pinMode(redBtn, INPUT_PULLUP);
  pinMode(greenBtn, INPUT_PULLUP);
  pinMode(blueBtn, INPUT_PULLUP);
  pinMode(yellowBtn, INPUT_PULLUP);

  randomSeed(analogRead(0));
}

// ---------------- HELPER FUNCTIONS ----------------
void flashLED(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(150);
}

int readButton() {
  if (!digitalRead(redBtn))    return 0;
  if (!digitalRead(greenBtn))  return 1;
  if (!digitalRead(blueBtn))   return 2;
  if (!digitalRead(yellowBtn)) return 3;
  return -1;
}

void showSequence() {
  for (int i = 0; i < level; i++) {
    int color = sequence[i];
    switch (color) {
      case 0: flashLED(redLED); break;
      case 1: flashLED(greenLED); break;
      case 2: flashLED(blueLED); break;
      case 3: flashLED(yellowLED); break;
    }
  }
}

// ---------------- MAIN LOOP ----------------
void loop() {
  // Add a new random step to the sequence
  sequence[level] = random(0, 4);
  level++;

  delay(500);
  showSequence();

  // Player repeats the sequence
  for (int i = 0; i < level; i++) {
    int pressed = -1;

    // Wait for a button press
    while (pressed == -1) {
      pressed = readButton();
    }

    // Flash the LED of the pressed button
    switch (pressed) {
      case 0: flashLED(redLED); break;
      case 1: flashLED(greenLED); break;
      case 2: flashLED(blueLED); break;
      case 3: flashLED(yellowLED); break;
    }

    // Check if correct
    if (pressed != sequence[i]) {
      // Wrong — flash all LEDs and restart
      for (int j = 0; j < 3; j++) {
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, HIGH);
        digitalWrite(yellowLED, HIGH);
        delay(200);
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        digitalWrite(yellowLED, LOW);
        delay(200);
      }

      level = 0; // restart game
      delay(1000);
      break;
    }

    // Wait for button release
    while (readButton() != -1);
    delay(100);
  }

  delay(500);
}
// const int redLED    = 12;
// const int greenLED  = 11;
// const int blueLED   = 10;
// const int yellowLED = 9;

// void setup() {
//   pinMode(redLED, OUTPUT);
//   pinMode(greenLED, OUTPUT);
//   pinMode(blueLED, OUTPUT);
//   pinMode(yellowLED, OUTPUT);
// }

// void loop() {
//   digitalWrite(redLED, HIGH); delay(500);
//   digitalWrite(redLED, LOW);  delay(200);

//   digitalWrite(greenLED, HIGH); delay(500);
//   digitalWrite(greenLED, LOW);  delay(200);

//   digitalWrite(blueLED, HIGH); delay(500);
//   digitalWrite(blueLED, LOW);  delay(200);

//   digitalWrite(yellowLED, HIGH); delay(500);
//   digitalWrite(yellowLED, LOW);  delay(200);
// }