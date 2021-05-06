// Download library from https://github.com/m5stack/M5StickC
#include <M5StickC.h>

unsigned char red;
unsigned char green;
unsigned char blue;

unsigned char red_bg     = 255;
unsigned char green_bg   = 255;
unsigned char blue_bg    = 255;

uint16_t current_drawColor;

uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void driver_display_setup(){
  M5.begin();
  M5.IMU.Init();
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
  bool lastLimits = DRAW_LIMITS_getEnable();
  DRAW_LIMITS_setEnable(false);
  setDrawColor(red, green, blue);
  for(int x=0; x<SCREEN_WIDTH; x++){
    for(int y=0; y<SCREEN_HEIGHT; y++){
      drawPixel(x,y);
    }
  }
  DRAW_LIMITS_setEnable(lastLimits);

  
  /*
  //M5.Lcd.fillScreen(fillColor);
  #ifdef FRAMEBUFFER_ENABLE
    FRAMEBUFFER_fill(fillColor);
  #endif
  */
}


void driver_display_loop(){
}

void setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_180)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_270)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #else
    M5.Lcd.drawPixel(x, y, current_drawColor);
  #endif
}

void setPixel(int x, int y, uint16_t color){
    #if defined(SCREEN_ROTATION_90)
      M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
    #elif defined(SCREEN_ROTATION_180)
      M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
    #elif defined(SCREEN_ROTATION_270)
      M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
    #else
      M5.Lcd.drawPixel(x, y, color);
    #endif
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
