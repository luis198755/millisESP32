#include <esp_timer.h>

// Returns the number of milliseconds passed since the ESP32 chip was powered on or reset
unsigned long long millisESP32 () {
  return (unsigned long long) (esp_timer_get_time () / 1000ULL);
}

#define LED_PIN 13 // The pin number of the LED

void setup () {
  Serial.begin(115200);
  pinMode (LED_PIN, OUTPUT); // Set the LED pin as output
}

void loop () {
  static unsigned long long previousMillis = 0; // Store the last time the LED was toggled
  const unsigned long interval = 500; // The interval between LED toggles in milliseconds

  unsigned long long currentMillis = millisESP32 (); // Get the current time in milliseconds

  // Check if enough time has passed since the last toggle
  if (currentMillis - previousMillis >= interval) {
    // Save the current time as the last toggle time
    previousMillis = currentMillis;
    // Toggle the LED state
    digitalWrite (LED_PIN, !digitalRead (LED_PIN));
    //Serial.print("hola");
  }
}