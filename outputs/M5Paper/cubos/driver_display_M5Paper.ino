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

void driver_display_partial_loop(){
  if(driver_display_changed){
    canvas.pushCanvas(0,0,UPDATE_MODE_DU4);
    driver_display_changed = false;

    //debug("Display partial canvas update " + String(millis()));
  }
}

void driver_display_loop(){
  
  //
  if(driver_display_changed){

    canvas.pushCanvas(0,0,UPDATE_MODE_GC16);
    driver_display_changed = false;

    //debug("Display canvas update " + String(millis()));
    //M5.update();
  }else{
    //debug("c");
    //delay(200);
    //M5.update();
  }
}

void driver_display_setup(){
  canvas.createCanvas(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void display_driver_setPixel(int x, int y){
  display_driver_setPixel(x, y, current_drawColor);
}

void display_driver_setPixel(int x, int y, int color){
  driver_display_changed = true;
  canvas.drawPixel(x, y, color);
}

unsigned char driver_display_getBrightness(){return 0;}
void driver_display_setBrightness(unsigned char brightness){}

void deriver_displayfillScreen(unsigned char red, unsigned char green, unsigned char blue){
  driver_display_changed = true;
  canvas.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, get_16GrayscaleColor(red, green, blue));
  //debug("Filling " + String(red) + " " + String(green) + " " + String(blue) + " " + String(get_16GrayscaleColor(red, green, blue)));
}

void driver_display_setDrawColor(unsigned char red, unsigned char green, unsigned char blue){

  //uint16_t grayColor = (((uint16_t)red) + ((uint16_t)green) + ((uint16_t)blue))/3;
  //grayColor = get_uint16Color(red, green, blue);
  //current_drawColor = get_uint16Color(red, green, blue);
  
  //current_drawColor = get_uint16Color(grayColor, grayColor, grayColor);
  current_drawColor = get_16GrayscaleColor(red, green, blue);

  //if(grayColor<127) current_drawColor = WHITE;
  //if(grayColor<get_16GrayscaleColor(red, green, blue);
  //else current_drawColor = BLACK;

  
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
