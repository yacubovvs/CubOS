#include <M5Stack.h>

uint32_t current_drawColor;

uint32_t get_m5ColorFromPallette(unsigned char red, unsigned char green, unsigned char blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setDrawColor(unsigned char red, unsigned char green, unsigned char blue){
  current_drawColor = get_m5ColorFromPallette(red, green, blue);
}


// ##################################################
////////////////////////////////////////////////////////


void driver_display_setup(){
  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);
}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  M5.Lcd.fillScreen(get_m5ColorFromPallette(red, green, blue));
}

void display_driver_setPixel(int x, int y){
	M5.Lcd.drawPixel(x, y, current_drawColor);
}

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness =  (unsigned char)((int)brightness*255/100);
  M5.Lcd.setBrightness(brightness);
}

