#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include "Arduino_ST7789.h" // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>

#define TFT_DC    2 // D4
#define TFT_RST   0
#define TFT_CS    -1 // 
#define TFT_MOSI  13
#define TFT_SCLK  14

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST); //for display without CS pin

byte red;
byte green;
byte blue;

byte red_bg     = 255;
byte green_bg   = 255;
byte blue_bg    = 255;

uint16_t current_drawColor;

uint16_t get_uint16Color(byte red, byte green, byte blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setup_displayDriver(){
  tft.init(240, 240);
  tft.setTextSize(2); 
}

void sleep_displayDriver(){
  tft.sleep();
  digitalWrite(0,0);
}

void wakeup_displayDriver(){
  tft.wakeup();
  setup_displayDriver();
}

void powerOff_displayDriver(){
  tft.sleep();
  //pinMode(0, OUTPUT);
  digitalWrite(0,0);
}

void powerOn_displayDriver(){
  digitalWrite(0,1);
  setup_displayDriver();
}


void fillScreen(byte red, byte green, byte blue){
  tft.fillScreen(get_uint16Color(red, green, blue));
}

void setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    tft.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_180)
    tft.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_270)
    tft.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #else
    tft.drawPixel(x, y, current_drawColor);
  #endif
}

void setDrawColor(byte red_new, byte green_new, byte blue_new){
  red = red_new;
  green = green_new;
  blue = blue_new;

  current_drawColor = get_uint16Color(red, green, blue);
}

#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t h){

    #if defined(SCREEN_ROTATION_90)
      tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y-h, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #else
      tft.drawFastVLine(x, y, h+1, current_drawColor);
    #endif
    

  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    
    #if defined(SCREEN_ROTATION_90)
      tft.drawFastHLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      tft.drawFastHLine(SCREEN_WIDTH-x-h, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      tft.drawFastHLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #else
      tft.drawFastHLine(x, y, h+1, current_drawColor);
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    #if defined(SCREEN_ROTATION_90)
      tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #else
      tft.fillRect(x, y, w+1, h+1, current_drawColor);
    #endif
  }
#endif