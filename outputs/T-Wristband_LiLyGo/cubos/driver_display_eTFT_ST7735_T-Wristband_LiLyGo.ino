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

uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 0;

void driver_display_setup(){
  tft.init();
  //tft.setRotation(1);
  tft.setSwapBytes(true);
  
  //pinMode(TFT_BL, OUTPUT);
  //digitalWrite(TFT_BL, 1);

  ledcSetup(0, 15000, 13);
  
  #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
    ledcAttachPin(TFT_BL, 0);
  #endif

  tft.fillScreen(TFT_BLACK);
  driver_display_setBrightness(get_core_display_brightness());
}

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
}

void sleep_displayDriver(){
  tft.writecommand(ST7735_SWRESET);
  tft.writecommand(ST7735_SLPIN);
  tft.writecommand(ST7735_DISPOFF);
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

unsigned char driver_display_getBrightness(){
  return driver_display_screenBrightness;
}

void driver_display_setBrightness(unsigned int brightness){
  #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
    if(brightness==0) ledcAttachPin(TFT_BL, 0);
    else ledcAttachPin(TFT_BL, 1);
  #else
    driver_display_screenBrightness = brightness;
    brightness = (((long)brightness)*1024/100);
    ledcWrite(0, brightness);
  #endif
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