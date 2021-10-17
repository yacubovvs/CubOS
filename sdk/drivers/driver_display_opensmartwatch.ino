
#include "Arduino_HWSPI.h"
#include "Arduino_ESP32SPI.h"
#include "Arduino_SWSPI.h"
#include "Arduino_GFX.h"     // Core graphics library
#include "Arduino_Display.h" // Various display driver

#define TFT_CS 5
#define TFT_DC 12
#define TFT_RST 33
#define TFT_BL -1

Arduino_DataBus *bus = new Arduino_HWSPI(TFT_DC, TFT_CS);
Arduino_GC9A01 *gfx = new Arduino_GC9A01(bus, TFT_RST, 0 /* rotation */, true /* IPS */);
unsigned char red;
unsigned char green;
unsigned char blue;

uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 0;

void driver_display_setup(){
  gfx->begin();
  //gfx->fillScreen(BACKGROUND);
  
  #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
    ledcAttachPin(TFT_BL, 0);
  #endif

  //gfx->fillScreen(TFT_BLACK);
  driver_display_setBrightness(get_core_display_brightness());

  pinMode(9, OUTPUT);
  digitalWrite(9, 1);
}

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
}

void sleep_displayDriver(){
  gfx->displayOff();
  digitalWrite(9, 0);
}

void wakeup_displayDriver(){
  gfx->displayOn();
  digitalWrite(9, 1);
}

void powerOff_displayDriver(){
  gfx->displayOff();
  digitalWrite(9, 0);
}

void powerOn_displayDriver(){
  gfx->displayOn();
  digitalWrite(9, 1);
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

    gfx->fillScreen(get_uint16Color(red, green, blue));

  #endif

  TEMPORARILY_RESTORE_LIMITS();
}

unsigned char driver_display_getBrightness(){
  return driver_display_screenBrightness;
}

void driver_display_setBrightness(unsigned int brightness){
  debug("Setting brightness to " + String(brightness));
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
  gfx->drawPixel(x, y, current_drawColor);
}

void display_driver_setPixel(int x, int y, uint16_t color){
  //M5.Lcd.drawPixel(x, y, color);
  gfx->drawPixel(x, y, color);
}

uint16_t getDrawColor(){
  return current_drawColor;
}
