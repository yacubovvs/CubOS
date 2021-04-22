// Download library from https://github.com/m5stack/M5StickC
#include <M5StickC.h>

unsigned char red;
unsigned char green;
unsigned char blue;

unsigned char red_bg     = 255;
unsigned char green_bg   = 255;
unsigned char blue_bg    = 255;

uint16_t current_drawColor;

uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

void setup_displayDriver(){
  M5.begin();
  M5.IMU.Init();
}

void sleep_displayDriver(){
}

void wakeup_displayDriver(){
}

void powerOff_displayDriver(){
}

void powerOn_displayDriver(){
}


void fillScreen(unsigned char red, unsigned char green, unsigned char blue){
}


void driver_display_loop(){
}

void setPixel(int x, int y){
  #if defined(SCREEN_ROTATION_90)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_180)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #elif defined(SCREEN_ROTATION_270)
    M5.Lcd.drawPixel(SCREEN_WIDTH-x, SCREEN_HEIGHT-y, current_drawColor);
  #else
    M5.Lcd.drawPixel(x, y, current_drawColor);
  #endif
}

void setDrawColor(unsigned char red_new, unsigned char green_new, unsigned char blue_new){
  red = red_new;
  green = green_new;
  blue = blue_new;

  current_drawColor = get_uint16Color(red, green, blue);
}

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

/*



#define DOT_SIZE 6
int dot[6][6][2] {
  {{35,35}},
  {{15,15},{55,55}},
  {{15,15},{35,35},{55,55}},
  {{15,15},{15,55},{55,15},{55,55}},
  {{15,15},{15,55},{35,35},{55,15},{55,55}},
  {{15,15},{15,35},{15,55},{55,15},{55,35},{55,55}},
  };

float accX = 0;
float accY = 0;
float accZ = 0;


void setup(void) {
  

  M5.Lcd.setRotation(1);
  
  M5.Lcd.fillScreen(TFT_GREEN);
  
  M5.Lcd.setTextColor(TFT_BLACK);  // Adding a background colour erases previous text automatically


  M5.Lcd.setCursor(10, 30);  
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("SHAKE ME");  
  delay(1000);
}

void loop() {


  while(1) {
    M5.IMU.getAccelData(&accX,&accY,&accZ);
    if (accX > 1.5 ||  accY > 1.5 ) {
      break;
    }
  }

  M5.Lcd.fillScreen(TFT_GREEN);

  // Draw first dice
  delay(500);  // A little delay to increase suspense :-D
  int number = random(0, 6);
  draw_dice(5,5,number);

  // Draw second dice
  delay(500);
  number = random(0, 6);
  draw_dice(85,5,number);


}

void draw_dice(int16_t x, int16_t y, int n) {

  M5.Lcd.fillRect(x, y, 70, 70, WHITE);

  for(int d = 0; d < 6; d++) {
    if (dot[n][d][0] > 0) {
        M5.Lcd.fillCircle(x+dot[n][d][0], y+dot[n][d][1], DOT_SIZE, TFT_BLACK);
    }
  }  

}
*/