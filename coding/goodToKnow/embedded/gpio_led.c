#include <stdio.h>
#include <gpio.h>

// Define the GPIO pin for the LED
#define LED_PIN 13

// Function to turn the LED on
void led_on() {
  // Set the LED pin high (on)
  GPIO_Set(LED_PIN, 1);
}

// Function to turn the LED off
void led_off() {
  // Set the LED pin low (off)
  GPIO_Set(LED_PIN, 0);
}

int main() {
  // Initialize the LED pin
  GPIO_Init(LED_PIN);

  // Loop forever
  while (1) {
    // Turn the LED on
    led_on();
    // Wait for a short time
    delay(1000);
    // Turn the LED off
    led_off();
    // Wait for a short time
    delay(1000);
  }

  return 0;
}