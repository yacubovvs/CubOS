#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_comment
const unsigned char gridicons_comment[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x0F, 0xE0, 
0x00, 0x07, 0xE0, 0x00, 0x07, 0xE0, 0x00, 0x07, 
0xE0, 0x00, 0x07, 0xE0, 0x00, 0x07, 0xE0, 0x00, 
0x07, 0xE0, 0x00, 0x07, 0xE0, 0x00, 0x07, 0xE0, 
0x00, 0x07, 0xE0, 0x00, 0x07, 0xE0, 0x00, 0x07, 
0xE0, 0x00, 0x0F, 0xF0, 0x3F, 0xFF, 0xF8, 0x3F, 
0xFF, 0xFE, 0x3F, 0xFF, 0xFF, 0x3F, 0xFF, 0xFF, 
0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
