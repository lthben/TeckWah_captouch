/*
 * Author: Benjamin Low
 *
 * Description: A single cap touch sensor using the AT42QT1010 IC. Connect to
 * any electrode. An LED lights up if touch is detected. Do a Google image
 * search for AT42QT1010 wiring and logic diagrams.
 *
 *
 * Last updated: 23 Jan 2016
 */

//USER DEFINED SETTINGS
//time in ms for holding the finger onto the button before it is activated to prevent accidental triggering
bool DEBUG = false;
const int thisCapTouchBoxNum = 2; //1 is for the drawer, 2 is for the live product display
const int holdTime = 1000; //time needed to hold the button to activate

int ledPin = 4;
int sensePin = 8;

boolean isActivated, isTriggered;
long triggerTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensePin, INPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(sensePin) == HIGH) {

    digitalWrite(ledPin, HIGH);

    if (!isTriggered) {

      triggerTime = millis();
      isTriggered = true;
      if (thisCapTouchBoxNum == 1) Serial.println("touch1_detected");
      else if (thisCapTouchBoxNum == 2) Serial.println("touch2_detected");

    } else {

      if (millis() - triggerTime > holdTime && !isActivated) {

        isActivated = true;
        if (thisCapTouchBoxNum == 1) Serial.println("touch1_activated");
        else if (thisCapTouchBoxNum == 2) Serial.println("touch2_activated");
      }
    }
  } else {

    digitalWrite(ledPin, LOW);

    if (isTriggered) {

      isTriggered = false;
      if (thisCapTouchBoxNum == 1) Serial.println("touch1_released");
      else if (thisCapTouchBoxNum == 2) Serial.println("touch2_released");
    }
    if (isActivated) {

      isActivated = false;
      if (DEBUG) Serial.println("deactivated");
    }
  }
}
