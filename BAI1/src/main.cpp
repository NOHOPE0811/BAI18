#include <Arduino.h>

const int buttonPin = 0;  // Chân nút nhấn kết nối với chân GPIO 2
const int ledPin = 23;    // Chân đèn LED kết nối với chân GPIO 13

volatile bool buttonPressed = false;

void IRAM_ATTR handleInterrupt() {
  buttonPressed = true;
}

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
}

void loop() {
  if (buttonPressed) {
    digitalWrite(ledPin, !digitalRead(ledPin));  // Đảo trạng thái đèn LED
    buttonPressed = false;
  }
  // Thêm các tác vụ khác trong vòng lặp chính nếu cần
}

