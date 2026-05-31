#include <EEPROM.h>

// The code for Haris Kadayan's Catfinder project, created for Hack Club's Stasis Program. :)
// Two modes, Simon Says and button press = LED lights, switch between modes by pressing all buttons for 5 seconds.

int buttons[] = { D0, D1, D2, D3 };
int leds[] = { D4, D5, D6, D7 };

int sequence[50];
int level = 1;

bool testMode = false;
unsigned long allPressedStart = 0;
bool alreadySwitched = false;

int saveAddress = 0;

void setup() {
  EEPROM.begin(16);

  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }

  int savedMode = EEPROM.read(saveAddress);
  testMode = savedMode == 1;

  randomSeed(analogRead(A0));

  if (!testMode) {
    newGame();
  }
}

void loop() {
  checkModeSwitch();

  if (testMode) {
    buttonLedMode();
  } else {
    simonMode();
  }
}

void checkModeSwitch() {
  bool allPressed =
    digitalRead(buttons[0]) == LOW &&
    digitalRead(buttons[1]) == LOW &&
    digitalRead(buttons[2]) == LOW &&
    digitalRead(buttons[3]) == LOW;

  if (allPressed) {
    if (allPressedStart == 0) {
      allPressedStart = millis();
    }

    if (millis() - allPressedStart >= 5000 && !alreadySwitched) {
      testMode = !testMode;
      alreadySwitched = true;

      EEPROM.write(saveAddress, testMode ? 1 : 0);
      EEPROM.commit();

      modeFlash();

      if (!testMode) {
        newGame();
      }
    }
  } else {
    allPressedStart = 0;
    alreadySwitched = false;
  }
}

void buttonLedMode() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], digitalRead(buttons[i]) == LOW ? HIGH : LOW);
  }
}

void simonMode() {
  showSequence();

  for (int i = 0; i < level; i++) {
    int pressed = waitForButton();

    flashLed(pressed, 200);

    if (pressed != sequence[i]) {
      loseAnimation();
      newGame();
      return;
    }
  }

  winStepAnimation();

  level++;

  if (level > 50) {
    level = 50;
  }

  sequence[level - 1] = random(0, 4);

  delay(500);
}

void newGame() {
  level = 1;

  for (int i = 0; i < 50; i++) {
    sequence[i] = random(0, 4);
  }

  startAnimation();
}

void showSequence() {
  delay(500);

  for (int i = 0; i < level; i++) {
    flashLed(sequence[i], 350);
    delay(200);
  }
}

int waitForButton() {
  while (true) {
    checkModeSwitch();

    for (int i = 0; i < 4; i++) {
      if (digitalRead(buttons[i]) == LOW) {
        delay(30);

        while (digitalRead(buttons[i]) == LOW) {
          checkModeSwitch();
        }

        delay(30);
        return i;
      }
    }
  }
}

void flashLed(int ledNumber, int timeOn) {
  digitalWrite(leds[ledNumber], HIGH);
  delay(timeOn);
  digitalWrite(leds[ledNumber], LOW);
}

void startAnimation() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
    delay(120);
    digitalWrite(leds[i], LOW);
  }
}

void winStepAnimation() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], HIGH);
  }

  delay(150);

  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loseAnimation() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], HIGH);
    }

    delay(200);

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    delay(200);
  }
}

void modeFlash() {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], HIGH);
    }

    delay(150);

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    delay(150);
  }
}