/*
#include <M5Stack.h>

byte red;
byte green;
byte blue;

byte red_bg     = 255;
byte green_bg   = 255;
byte blue_bg    = 255;

uint32_t current_drawColor;

uint32_t get_m5ColorFromPallette(byte red, byte green, byte blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setDrawColor(byte red, byte green, byte blue){
  current_drawColor = get_m5ColorFromPallette(red, green, blue);
}


// ##################################################
////////////////////////////////////////////////////////


void setup_displayDriver(){
  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);
}

void fillScreen(byte red, byte green, byte blue){
  M5.Lcd.fillScreen(get_m5ColorFromPallette(red, green, blue));
}

void setPixel(int x, int y){
	M5.Lcd.drawPixel(x, y, current_drawColor);
}
*/
