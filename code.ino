const int redLight = 13;
const int yellowLight = 12;
const int greenLight = 8;
const int buttonPin = 2;

bool buttonPressed = false;
unsigned long previousMillis = 0;
const long interval = 5000;

enum LightState { GREEN, YELLOW, RED };
LightState currentState = GREEN;

void setup() {
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(greenLight, HIGH);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = true;
  }

  if (buttonPressed) {
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);
    delay(5000);
    digitalWrite(redLight, LOW);
    digitalWrite(greenLight, HIGH);

    buttonPressed = false;
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    switch (currentState) {
      case GREEN:
        digitalWrite(greenLight, LOW);
        digitalWrite(yellowLight, HIGH);
        currentState = YELLOW;
        break;

      case YELLOW:
        digitalWrite(yellowLight, LOW);
        digitalWrite(redLight, HIGH);
        currentState = RED;
        break;

      case RED:
        digitalWrite(redLight, LOW);
        digitalWrite(greenLight, HIGH);
        currentState = GREEN;
        break;
    }
  }
}
