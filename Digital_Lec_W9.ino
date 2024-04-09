#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(2, 32, NEO_RGB);
int tempo = 65;
int onOffButton = 35;
int lastButtonChannelState = LOW;
int ButtonChannelState = LOW;
int channelButtonOn = LOW;
void setup() {
  neopixel.begin();
  neopixel.clear();
  neopixel.show();
  pinMode(onOffButton, INPUT);
}


void loop() {
  int red1 = random(150);
  int green1 = random(150);
  int blue1 = random(150);
  int red2 = random(150);
  int green2 = random(150);
  int blue2 = random(150);
  lastButtonChannelState = ButtonChannelState;
  ButtonChannelState = digitalRead(onOffButton);
  if (lastButtonChannelState == LOW and ButtonChannelState == HIGH) {
    channelButtonOn = !channelButtonOn;
    for (int i = 0; i < 4; i++) {
      neopixel.setPixelColor(0, red1, green1, blue1);
      neopixel.setPixelColor(1, red2, green2, blue2);
      neopixel.show();
      delay(tempo);
    }
  }
}
