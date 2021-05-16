// Add TFT_eSPI library to Arduino IDE from:
// <CUBOS DIRECTORY>/external_libs/TFT_eSPI (T-Wristband ttgo)/

#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>


//#define SPI_FREQUENCY  27000000


TFT_eSPI tft = TFT_eSPI(); 

unsigned char red;
unsigned char green;
unsigned char blue;

unsigned char red_bg     = 255;
unsigned char green_bg   = 255;
unsigned char blue_bg    = 255;

uint16_t current_drawColor;

void driver_display_setup(){
  debug(String(TFT_SCLK));
  tft.init();
  //tft.setRotation(1);
  tft.setSwapBytes(true);
  //tft.pushImage(0, 0,  160, 80, ttgo);

  debug(String(TFT_SCLK));
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 1);

  tft.fillScreen(TFT_BLACK);
  
}

void sleep_displayDriver(){
}

void wakeup_displayDriver(){
}

void powerOff_displayDriver(){
}

void powerOn_displayDriver(){
}


void fillScreen(unsigned char red, unsigned char green, unsigned char blue){
  TEMPORARILY_DISABLE_LIMITS();

  #ifdef FRAMEBUFFER_ENABLE

    setDrawColor(red, green, blue);
    for(int x=0; x<SCREEN_WIDTH; x++){
      for(int y=0; y<SCREEN_HEIGHT; y++){
        drawPixel(x,y);
      }
    }

  #else

    tft.fillScreen(get_uint16Color(red, green, blue));

  #endif

  TEMPORARILY_RESTORE_LIMITS();
}

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness = 7 + (unsigned char)((int)brightness*8/100);
  debug("Setting screen brightness to " + String(brightness));
  // brightness 7..15
  //M5.Axp.ScreenBreath(brightness);
}

void driver_display_loop(){
}

void setPixel(int x, int y){
  //M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  tft.drawPixel(x, y, current_drawColor);
}

void setPixel(int x, int y, uint16_t color){
  //M5.Lcd.drawPixel(x, y, color);
  tft.drawPixel(x, y, color);
}

void setDrawColor(unsigned char red_new, unsigned char green_new, unsigned char blue_new){
  red = red_new;
  green = green_new;
  blue = blue_new;

  current_drawColor = get_uint16Color(red, green, blue);
}

uint16_t getDrawColor(){
  return current_drawColor;
}

/*
#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t h){

    #if defined(SCREEN_ROTATION_90)
      //tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      //tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y-h, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      //tft.drawFastVLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #else
      //tft.drawFastVLine(x, y, h+1, current_drawColor);
    #endif
    

  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    
    #if defined(SCREEN_ROTATION_90)
      //tft.drawFastHLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      //tft.drawFastHLine(SCREEN_WIDTH-x-h, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      //tft.drawFastHLine(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, h+1, current_drawColor);
    #else
      //tft.drawFastHLine(x, y, h+1, current_drawColor);
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    #if defined(SCREEN_ROTATION_90)
      //tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_180)
      //tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #elif defined(SCREEN_ROTATION_270)
      //tft.fillRect(SCREEN_WIDTH-x-w, SCREEN_HEIGHT-y-h, w+1, h+1, current_drawColor);
    #else
      //tft.fillRect(x, y, w+1, h+1, current_drawColor);
    #endif
  }
#endif
*/