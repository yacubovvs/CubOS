
uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 100;

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
}

uint16_t getDrawColor(){
  return current_drawColor;
}

void driver_display_setup(){
    core_driver_openBL();
}

void sleep_displayDriver(){}
void wakeup_displayDriver(){}
void powerOff_displayDriver(){}
void powerOn_displayDriver(){}
void driver_display_loop(){}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  uint16_t fillColor = get_uint16Color(red, green, blue);
  core_driver_fillScreen(fillColor);
  #ifdef FRAMEBUFFER_ENABLE
    FRAMEBUFFER_fill(fillColor);
  #endif
}

void display_driver_setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_180)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_270)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #else
    core_driver_drawPixel(x, y, current_drawColor);
  #endif
}

void display_driver_setPixel(int x, int y, uint16_t color){
  #if defined(SCREEN_ROTATION_90)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
  #elif defined(SCREEN_ROTATION_180)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
  #elif defined(SCREEN_ROTATION_270)
    core_driver_drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, color);
  #else
    core_driver_drawPixel(x, y, color);
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


unsigned char driver_display_getBrightness(){
  return driver_display_screenBrightness;
}

void driver_display_setBrightness(unsigned int brightness){
  #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
    #ifdef DEBUG_BACKLIGHT
        debug("DEBUG_BACKLIGHT: Setting backlight to " + String(brightness));
    #endif
    driver_display_screenBrightness = brightness;
    #ifdef DEBUG_BACKLIGHT
        //debug("DEBUG_BACKLIGHT: Backlight convert to " + String(driver_display_screenBrightness), 20);
    #endif
    core_driver_setBrigtness((unsigned char)(((int)driver_display_screenBrightness)*255/100));
  #else
    driver_display_screenBrightness = 100;
    core_driver_setBrigtness((unsigned char)(((int)driver_display_screenBrightness)*255/100));
  #endif
}