#include <Arduino.h>

#include <Energia.h>

void setup() {

	// reading sensor signal
	pinMode(A1, INPUT);

	// switch on sensor
	pinMode(P1_7, OUTPUT);
	digitalWrite(P1_7, HIGH);

	// shoot
	pinMode(P1_3, OUTPUT);
	digitalWrite(P1_3, LOW);

	pinMode(P1_6, INPUT);
	pinMode(P2_5, INPUT);
	pinMode(P2_4, INPUT);
	pinMode(P2_3, INPUT);

	pinMode(P2_6, OUTPUT);
	digitalWrite(P2_6, LOW);

//	Serial.begin(9600);

}

void loop() {

	int photo = analogRead(A1);
	//delay(50);
	// perhaps higher sensor value like 600-700
	if (photo < 850 && digitalRead(P2_3) == LOW) {

		if (digitalRead(P1_6) == HIGH) {
//			delay(50);
		}

		if (digitalRead(P2_5) == HIGH) {
			delay(50);
		}

		if (digitalRead(P2_4) == HIGH) {
			delay(100);
		}

		digitalWrite(P1_3, HIGH);
	} else {
		digitalWrite(P1_3, LOW);
	}

	if (digitalRead(P2_3) == HIGH) {

		if (photo < 850) {
			digitalWrite(P2_6, HIGH);
		} else if (photo > 850) {
			digitalWrite(P2_6, LOW);
		}

	}

//	Serial.println(photo);

}
