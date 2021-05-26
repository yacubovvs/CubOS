// Download library from https://github.com/m5stack/M5StickC
#include <M5StickC.h>

uint16_t current_drawColor;

void driver_display_setup(){
  driver_display_setBrightness(0);
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.fillScreen(TFT_BLACK);
  debug("Initing display");
  driver_display_setBrightness(get_core_display_brightness());
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

unsigned char driver_display_currentBrightness=0;
void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  driver_display_currentBrightness = brightness;
  brightness = 7 + (unsigned char)((int)brightness*8/100);
  //debug("Setting screen brightness to " + String(brightness));
  // brightness 7..15
  M5.Axp.ScreenBreath(brightness);
}

unsigned char driver_display_getBrightness(){
  return driver_display_currentBrightness;
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

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
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
