/*
 * Author: Benjamin Low
 * Last updated: 5 Oct 2015
 * Description: A single cap touch sensor using the AT42QT1010 IC. Connect to
 * any electrode. An LED lights up if touch is detected. Do a Google image
 * search for AT42QT1010 wiring and logic diagrams.
 */

int ledPin = 4;
int sensePin = 8;
boolean is_turned_on;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensePin, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(sensePin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (!is_turned_on) {
      is_turned_on = true;
      Serial.println("captouch_on");
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (is_turned_on) {
      is_turned_on = false;
      Serial.println("captouch_off");
    }
  }
}
