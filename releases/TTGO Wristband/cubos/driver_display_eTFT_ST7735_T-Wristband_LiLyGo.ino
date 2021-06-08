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

  driver_display_setBrightness(0);
}

void wakeup_displayDriver(){
}

void powerOff_displayDriver(){
}

void powerOn_displayDriver(){
}


void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
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
    //if(brightness==0) ledcAttachPin(TFT_BL, 1);
    //else ledcAttachPin(TFT_BL, 0);
  #else
    //driver_display_screenBrightness = brightness;
    //brightness = (((long)brightness)*1024/100);
    //ledcWrite(0, brightness);
  #endif
}

void driver_display_loop(){
}

void display_driver_setPixel(int x, int y){
  //M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  tft.drawPixel(x, y, current_drawColor);
}

void display_driver_setPixel(int x, int y, uint16_t color){
  //M5.Lcd.drawPixel(x, y, color);
  tft.drawPixel(x, y, color);
}

uint16_t getDrawColor(){
  return current_drawColor;
}
