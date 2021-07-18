#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_scheduled
const unsigned char gridicons_scheduled[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 
0x3F, 0xFC, 0xFF, 0x3F, 0xF0, 0x00, 0x0F, 0xE0, 
0x00, 0x07, 0xE0, 0x00, 0x07, 0xE0, 0x00, 0x07, 
0xE7, 0xFF, 0xE7, 0xE7, 0xFF, 0xE7, 0xE7, 0x7F, 
0xE7, 0xE6, 0x3F, 0xE7, 0xE7, 0x1F, 0xE7, 0xE7, 
0x8E, 0xE7, 0xE7, 0xC4, 0x67, 0xE7, 0xE0, 0xE7, 
0xE7, 0xF1, 0xE7, 0xE7, 0xFB, 0xE7, 0xE7, 0xFF, 
0xE7, 0xE0, 0x00, 0x07, 0xF0, 0x00, 0x0F, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
