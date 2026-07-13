#ifndef ST7735_DISPLAY_H_INCLUDED
#define ST7735_DISPLAY_H_INCLUDED

#include "IDisplay.h"

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

class ST7735_Display : public IDisplay
{
public:
    ST7735_Display();

    ST7735_Display(const ST7735_Display&) = delete;
    ST7735_Display& operator=(const ST7735_Display&) = delete;
    ST7735_Display(ST7735_Display&&) = delete;
    ST7735_Display& operator=(ST7735_Display&&) = delete;

    void Init() override;
    int GetWidth() override;
    int GetHeight() override;

    void SendImage(
        const int xStart,
        const int yStart,
        const int width,
        const int height,
        const uint16_t* data) override;

    void EnterSleepMode() override;

private:
    bool m_isInitialized;
    int m_width;
    int m_height;

    Adafruit_ST7735 m_tft;
};

#endif
