#include <SH1106.h>
#include <SH1106_BBSPI.h>

SH1106_BBSPI tft(2, 3, 4, 5, 6); //SCK, MOSI, CS, DC, RES

void setup() {
    tft.initializeDevice();
    tft.setBacklight(255);
    tft.setDisplayOffset(2, 0);
    tft.fillScreen(Color::Black);
    tft.drawRectangle(0, 0, 127, 63, Color::White);
}

void loop() {
    tft.setCursor(10, 10);
    tft.print(millis());
}
