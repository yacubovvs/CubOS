#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_chat
const unsigned char gridicons_chat[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFF, 0xC0, 
0x03, 0xFF, 0xC0, 0x03, 0xFF, 0xC0, 0x03, 0xFF, 
0xC0, 0x3F, 0xFF, 0xC0, 0x20, 0x07, 0xC0, 0x40, 
0x03, 0xC0, 0x40, 0x03, 0xC0, 0x40, 0x03, 0xE1, 
0xC0, 0x03, 0xF1, 0xC0, 0x03, 0xFD, 0xC0, 0x03, 
0xFF, 0xC0, 0x03, 0xFF, 0xE0, 0x03, 0xFF, 0xFF, 
0x87, 0xFF, 0xFF, 0x8F, 0xFF, 0xFF, 0xBF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
