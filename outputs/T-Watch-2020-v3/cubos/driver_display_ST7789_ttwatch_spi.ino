#define LILYGO_WATCH_2020_V3 
#include <LilyGoWatch.h>

TTGOClass *ttgo;

uint16_t current_drawColor;

uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue){
  return ((red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

uint16_t getDrawColor(){
  return current_drawColor;
}

void driver_display_setup(){
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    //ttgo->tft->fillScreen(BLACK);
}

void sleep_displayDriver(){}
void wakeup_displayDriver(){}
void powerOff_displayDriver(){}
void powerOn_displayDriver(){}
void driver_display_loop(){}

void fillScreen(unsigned char red, unsigned char green, unsigned char blue){
  ttgo->tft->fillScreen(get_uint16Color(red, green, blue));
}

void setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    ttgo->tft->drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_180)
    ttgo->tft->drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_270)
    ttgo->tft->drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #else
    ttgo->tft->drawPixel(x, y, current_drawColor);
  #endif
}


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