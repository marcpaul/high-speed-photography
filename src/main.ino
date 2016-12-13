/**
 * to use this code without changes you must use atom + platformIO package
 *
 * if you use energia ide just delete both includes
 *
 * if you use the energia toolchain with another ide you can use the makefile in the lib-dir
 * and delete only the first include
 * read the makefile to set correct environment variables
 */

#include <Arduino.h>
#include <Energia.h>

/**
 * setting up our environment
 * @method setup
 */
void setup() {
	// reading sensor signal
	pinMode(A1, INPUT);

	// switch on sensor
	pinMode(P1_7, OUTPUT);
	digitalWrite(P1_7, HIGH);

	// activate flash unit
	pinMode(P1_3, OUTPUT);
	digitalWrite(P1_3, LOW);

	// set delay after hitting laser to 50ms
	pinMode(P1_6, INPUT);

	// set delay to 100ms
	pinMode(P2_5, INPUT);

	// set delay to 150ms
	pinMode(P2_4, INPUT);

	// laser - sensor calibration on/off
	pinMode(P2_3, INPUT);

	// calibration led
	pinMode(P2_6, OUTPUT);
	digitalWrite(P2_6, LOW);
}

/**
 * the main loop
 * @method loop
 */
void loop() {
	// read the photosensor
	int photo = analogRead(A1);
	// delay(50); // if the timing is off you can add delay here
	// perhaps higher sensor value like 600-700
	// if sensor is low and calibration mode is off
	if (photo < 850 && digitalRead(P2_3) == LOW) {
		// if switch one is on
		if (digitalRead(P1_6) == HIGH) {
			delay(50);
		}
		// if switch two is on
		if (digitalRead(P2_5) == HIGH) {
			delay(100);
		}
		// if switch three is on
		if (digitalRead(P2_4) == HIGH) {
			delay(150);
		}
		// flash
		digitalWrite(P1_3, HIGH);
	} else {
		digitalWrite(P1_3, LOW);
	}

	// calibration mode switch is on
	if (digitalRead(P2_3) == HIGH) {
		// if sensor is low switch on led
		// used to aim the laser
		if (photo < 850) {
			digitalWrite(P2_6, HIGH);
		} else if (photo > 850) {
			digitalWrite(P2_6, LOW);
		}
	}
}
