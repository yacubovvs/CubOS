
#include <UTFT.h>

UTFT myGLCD(SSD1963_800ALT,38,39,40,41);

uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 0;

void driver_display_loop(){
}

void driver_display_setup(){
  myGLCD.InitLCD();
}

void display_driver_setPixel(int x, int y){
	//M5.Lcd.drawPixel(x, y, current_drawColor);
  myGLCD.drawPixel(x,y);
}

void display_driver_setPixel(int x, int y, uint16_t color){
  driver_display_setDrawColor(color);
  myGLCD.drawPixel(x,y);
}

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness =  (unsigned char)((int)brightness*255/100);
  //M5.Lcd.setBrightness(brightness);
}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  //M5.Lcd.fillScreen(get_uint16Color(red, green, blue));
  myGLCD.fillScr(get_uint16Color(red, green, blue));
}

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
  myGLCD.setColor(current_drawColor);
  
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
  myGLCD.setColor(color);
}

uint16_t getDrawColor(){
  return current_drawColor;
}

void sleep_displayDriver(){
}

void wakeup_displayDriver(){
}

void powerOff_displayDriver(){
}

void powerOn_displayDriver(){
}

/*






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



void display_driver_setPixel(int x, int y){
  //M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  tft.drawPixel(x, y, current_drawColor);
}

void display_driver_setPixel(int x, int y, uint16_t color){
  //M5.Lcd.drawPixel(x, y, color);
  tft.drawPixel(x, y, color);
}


*/