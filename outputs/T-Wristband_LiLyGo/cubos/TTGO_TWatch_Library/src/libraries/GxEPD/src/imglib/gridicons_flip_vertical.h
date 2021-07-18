#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
// 24 x 24 gridicons_flip_vertical
const unsigned char gridicons_flip_vertical[] PROGMEM = { /* 0X01,0X01,0XB4,0X00,0X40,0X00, */
0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xFF, 0xFF, 0xE7, 
0xFF, 0xFF, 0xE7, 0xFF, 0xF8, 0x00, 0x1F, 0xF0, 
0x00, 0x0F, 0xF0, 0x07, 0xCF, 0xF0, 0x07, 0xCF, 
0xF0, 0x07, 0xCF, 0xF0, 0x07, 0xCF, 0xF0, 0x07, 
0xCF, 0xF0, 0x07, 0xCF, 0xF0, 0x07, 0xCF, 0xF0, 
0x07, 0xCF, 0xF0, 0x07, 0xCF, 0xF0, 0x07, 0xCF, 
0xF0, 0x07, 0xCF, 0xF0, 0x07, 0xCF, 0xF0, 0x00, 
0x0F, 0xF8, 0x00, 0x1F, 0xFF, 0xE7, 0xFF, 0xFF, 
0xE7, 0xFF, 0xFF, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF
};
