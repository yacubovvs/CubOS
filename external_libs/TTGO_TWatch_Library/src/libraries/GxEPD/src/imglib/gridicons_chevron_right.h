#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_chevron_right
const unsigned char gridicons_chevron_right[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFF, 0xFF, 
0xF1, 0xFF, 0xFF, 0xE3, 0xFF, 0xFF, 0xC7, 0xFF, 
0xFF, 0x8F, 0xFF, 0xFF, 0x1F, 0xFF, 0xFE, 0x3F, 
0xFF, 0xFC, 0x7F, 0xFF, 0xFC, 0x7F, 0xFF, 0xFE, 
0x3F, 0xFF, 0xFF, 0x1F, 0xFF, 0xFF, 0x8F, 0xFF, 
0xFF, 0xC7, 0xFF, 0xFF, 0xE3, 0xFF, 0xFF, 0xF1, 
0xFF, 0xFF, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
