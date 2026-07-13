BLE HUD Navi - ESP32-S3 + 1.44-inch ST7735 128x128

Required Arduino libraries:
- Adafruit GFX Library
- Adafruit ST7735 and ST7789 Library
- Button2

Wiring:
- ST7735 SCK/SCL -> GPIO2
- ST7735 MOSI/SDA -> GPIO3
- ST7735 RST/RES -> GPIO4
- ST7735 DC/A0 -> GPIO5
- ST7735 CS -> GPIO6
- ST7735 VCC -> 3.3V
- ST7735 GND -> GND
- ST7735 BL/LED -> 3.3V

This build removes the unused SSD1351 and TTGO display drivers because Arduino compiles every .cpp file in the sketch directory.
