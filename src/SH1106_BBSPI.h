#ifndef _SH1106_BBSPI_H
#define _SH1106_BBSPI_H

#include <SH1106.h>

class SH1106_BBSPI : public SH1106 {
    private:
        uint8_t _sck;
        uint8_t _mosi;
        uint8_t _cs;
        uint8_t _dc;
        uint8_t _res;

    public:
        SH1106_BBSPI(uint8_t sck, uint8_t mosi, uint8_t cs, uint8_t dc, uint8_t res = 255) :
            _sck(sck), _mosi(mosi), _cs(cs), _dc(dc), _res(res), SH1106() {}

        void command(uint8_t c);
        void command(uint8_t c, uint8_t p);
        void data(uint8_t d);
        void data(uint8_t *d, uint32_t l);

        void initializeDevice();

};
#endif
