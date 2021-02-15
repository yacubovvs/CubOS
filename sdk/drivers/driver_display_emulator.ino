uint16_t get_uint16Color(byte red, byte green, byte blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setup_displayDriver(){
  debug("Setup display");
}

void sleep_displayDriver(){
  debug("Display sleep");
}

void wakeup_displayDriver(){
  debug("Display wakeup");
}

void powerOff_displayDriver(){
  debug("Display poweroff");
}

void powerOn_displayDriver(){
  debug("Display poweron");
}


void fillScreen(byte red, byte green, byte blue){
  debug("Fill screen");
}

void setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    
  #elif defined(SCREEN_ROTATION_180)
    
  #elif defined(SCREEN_ROTATION_270)
    
  #else
    
  #endif
}

void setDrawColor(byte red_new, byte green_new, byte blue_new){

}

#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t h){

    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
    
  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }
#endif