#include <Arduino.h>
#include <Servo.h>

/**
 * @file main.cpp
 * @brief Embedded Servo Motor Control using MG995
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program controls a Servo Motor (MG995).
 * The servo rotates between 0° and 180°,
 * demonstrating angle control using PWM signals.
 */

// Define servo signal pin
#define SERVO_PIN 9

// Create servo object
Servo myServo;

// Variable to store angle
int angle;

/**
 * @brief Initializes serial communication and attaches servo.
 */
void setup() {

    Serial.begin(9600);

    // Attach servo to defined pin
    myServo.attach(SERVO_PIN);

    Serial.println("Servo Motor Control System Initialized");
}

/**
 * @brief Rotates servo between 0° and 180°.
 */
void loop() {

    // Rotate from 0° to 180°
    for (angle = 0; angle <= 180; angle += 10) {
        myServo.write(angle);
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(500);
    }

    // Rotate back from 180° to 0°
    for (angle = 180; angle >= 0; angle -= 10) {
        myServo.write(angle);
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(500);
    }
}
