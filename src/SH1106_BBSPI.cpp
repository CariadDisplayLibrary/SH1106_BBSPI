#include <SH1106_BBSPI.h>

void SH1106_BBSPI::initializeDevice() {
    pinMode(_sck, OUTPUT);
    pinMode(_mosi, OUTPUT);
    pinMode(_cs, OUTPUT);
    digitalWrite(_cs, HIGH);
    pinMode(_dc, OUTPUT);
    digitalWrite(_dc, HIGH);
    if (_res != 255) {
        pinMode(_res, OUTPUT);
        digitalWrite(_res, HIGH);
        delay(10);
        digitalWrite(_res, LOW);
        delay(10);
        digitalWrite(_res, HIGH);
        delay(10);
    }
    initDevice();
}

void SH1106_BBSPI::command(uint8_t c) {
    digitalWrite(_dc, LOW);
    digitalWrite(_cs, LOW);
    shiftOut(_mosi, _sck, MSBFIRST, c);
    digitalWrite(_cs, HIGH);
    delay(1);
}

void SH1106_BBSPI::command(uint8_t c, uint8_t p) {
    digitalWrite(_dc, LOW);
    digitalWrite(_cs, LOW);
    shiftOut(_mosi, _sck, MSBFIRST, c);
    shiftOut(_mosi, _sck, MSBFIRST, p);
    digitalWrite(_cs, HIGH);
    delay(1);
}

void SH1106_BBSPI::data(uint8_t d) {
    digitalWrite(_dc, HIGH);
    digitalWrite(_cs, LOW);
    shiftOut(_mosi, _sck, MSBFIRST, d);
    digitalWrite(_cs, HIGH);
    delay(1);
}

void SH1106_BBSPI::data(uint8_t *d, uint32_t l) {
    digitalWrite(_dc, HIGH);
    digitalWrite(_cs, LOW);
    for (uint32_t i = 0; i < l; i++) {
        shiftOut(_mosi, _sck, MSBFIRST, d[i]);
    }
    digitalWrite(_cs, HIGH);
    delay(1);
}


