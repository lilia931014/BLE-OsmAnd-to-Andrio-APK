#include "ST7735_Display.h"
#include <Arduino.h>

namespace
{
    constexpr int SCREEN_WIDTH  = 128;
    constexpr int SCREEN_HEIGHT = 128;

    constexpr int TFT_SCLK = 2;
    constexpr int TFT_MOSI = 3;
    constexpr int TFT_RST  = 4;
    constexpr int TFT_DC   = 5;
    constexpr int TFT_CS   = 6;
}

ST7735_Display::ST7735_Display()
    : m_isInitialized(false)
    , m_width(SCREEN_WIDTH)
    , m_height(SCREEN_HEIGHT)
    , m_tft(TFT_CS, TFT_DC, TFT_RST)
{
}

int ST7735_Display::GetWidth()
{
    return m_width;
}

int ST7735_Display::GetHeight()
{
    return m_height;
}

void ST7735_Display::Init()
{
    if (m_isInitialized)
        return;

    m_isInitialized = true;

    // ESP32-S3 hardware SPI:
    // SCK = GPIO2, MISO unused, MOSI = GPIO3, CS = GPIO6
    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);

    // Most common initialization for 1.44" 128x128 ST7735 modules
    m_tft.initR(INITR_144GREENTAB);

    m_tft.setRotation(0);
    m_tft.fillScreen(ST77XX_BLACK);
}

void ST7735_Display::SendImage(
    const int xStart,
    const int yStart,
    const int width,
    const int height,
    const uint16_t* data)
{
    if (!m_isInitialized || data == nullptr)
        return;

    m_tft.drawRGBBitmap(
        xStart,
        yStart,
        const_cast<uint16_t*>(data),
        width,
        height);
}

void ST7735_Display::EnterSleepMode()
{
    if (!m_isInitialized)
        return;

    m_tft.fillScreen(ST77XX_BLACK);

    // ST7735 display-off and sleep-in commands
    m_tft.writeCommand(ST77XX_DISPOFF);
    delay(20);
    m_tft.writeCommand(ST77XX_SLPIN);
    delay(120);
}
