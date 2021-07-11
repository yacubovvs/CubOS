#include <M5Stack.h>

uint32_t current_drawColor;

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_uint16Color(red, green, blue);
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
}

void driver_display_loop(){
  //M5.update();
  M5.update();
}

void driver_display_setup(){
  //M5.begin();
  M5.Power.begin();
  M5.Lcd.setBrightness(255);

  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);
}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  M5.Lcd.fillScreen(get_uint16Color(red, green, blue));
}

void display_driver_setPixel(int x, int y){
	M5.Lcd.drawPixel(x, y, current_drawColor);
}

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness =  (unsigned char)((int)brightness*255/100);
  M5.Lcd.setBrightness(brightness);
}
