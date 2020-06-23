
#ifndef _IDISPLAY_H_
#define _IDISPLAY_H_

#include <stdint.h>

enum class DisplayMode
{
    Graphics1Bit,
    Graphics2Bit,
    TextTiles
};

class IDisplay
{
public:
    virtual void SetMode(DisplayMode mode) = 0;
    virtual DisplayMode GetMode() = 0;
    virtual void SetPixel(uint8_t x, uint8_t y, uint8_t c) = 0;
    virtual void Present() = 0;
};

#endif
