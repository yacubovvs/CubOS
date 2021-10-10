#include <M5EPD.h>
M5EPD_Canvas canvas(&M5.EPD);

uint16_t current_drawColor;
unsigned char driver_display_screenBrightness = 0;
bool driver_display_changed = false;

//#ifdef E_PAPER_DISPLAY
bool driver_siaply_particaly_update = false;
void setParticalyUpdateEnable(bool value){
  driver_siaply_particaly_update = value;
}
//#endif

void driver_display_loop(){
  
  //
  if(driver_display_changed){
    //
    if(driver_siaply_particaly_update) canvas.pushCanvas(0,0,UPDATE_MODE_DU4);
    else canvas.pushCanvas(0,0,UPDATE_MODE_GC16);
    driver_display_changed = false;

    debug("Display canvas update " + String(millis()));
    //M5.update();
  }else{
    //debug("Loop with out updating " + String(millis()));
    //debug("c");
    //delay(200);
    //M5.update();
  }
}

void driver_display_setup(){
  canvas.createCanvas(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void display_driver_setPixel(int x, int y){
	//M5.Lcd.drawPixel(x, y, current_drawColor);
  display_driver_setPixel(x, y, current_drawColor);
}

//int val = 0;
void display_driver_setPixel(int x, int y, int color){
  //driver_display_setDrawColor(color);

  driver_display_changed = true;
  canvas.drawPixel(x, y, color);

}

void driver_display_setBrightness(unsigned char brightness){
  // brightness: 0..100%
  brightness =  (unsigned char)((int)brightness*255/100);
  //M5.Lcd.setBrightness(brightness);
}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  //M5.Lcd.fillScreen(get_uint16Color(red, green, blue));
}

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){

  uint16_t grayColor = (((uint16_t)red) + ((uint16_t)green) + ((uint16_t)blue))/3;
  //grayColor = get_uint16Color(red, green, blue);
  //current_drawColor = get_uint16Color(red, green, blue);
  
  current_drawColor = get_uint16Color(grayColor, grayColor, grayColor);

  if(grayColor<127) current_drawColor = WHITE;
  else current_drawColor = BLACK;

  
}

void driver_display_setDrawColor(uint16_t color){
  current_drawColor = color;
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
