#include <M5Stack.h>

uint32_t current_drawColor;

uint32_t get_m5ColorFromPallette(unsigned char red, unsigned char green, unsigned char blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

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

/*
#include <M5Stack.h>

int drawLimit_x_min = 0;
int drawLimit_y_min = 0;
int drawLimit_x_max = SCREEN_WIDTH;
int drawLimit_y_max = SCREEN_HEIGHT;

void set_DrawLimits(int min_x, int min_y, int max_x, int max_y){
  drawLimit_x_min = min_x;
  drawLimit_y_min = min_y;
  drawLimit_x_max = max_x;
  drawLimit_y_max = max_y;
}

//#define framebuffer_color_256 // 256 color on screen
#define framebuffer_color_16  // 16 colors on screen

byte current_color = 0;
byte current_pallete_color = 0;

/////////////////////////////////////////////////////
//  DISPLAY BUFFER



#ifdef framebuffer_color_16
  // 4 bit per pixel (max 16 unique colors on frame)
  unsigned char frameBuffer[SCREEN_WIDTH/2][SCREEN_HEIGHT];
#endif
#ifdef framebuffer_color_256
  // 8 bit per pixel (max 256 unique colors on frame)
  unsigned char frameBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];
#endif

// 1 bit oer pixel (if need to update pixel on screen)
unsigned char needToClear[SCREEN_WIDTH/8+1][SCREEN_HEIGHT];

// Initing of arrays
void init_frameBuffer(){
  #ifdef framebuffer_color_16
    for (int x=0; x<SCREEN_WIDTH/2; x++){
  #endif
  #ifdef framebuffer_color_256
    for (int x=0; x<SCREEN_WIDTH; x++){
  #endif
    for (int y=0; y<SCREEN_HEIGHT; y++){
      frameBuffer[x][y] = 0;
    }
  }

  for (int x=0; x<SCREEN_WIDTH/8; x++){
    for (int y=0; y<SCREEN_HEIGHT; y++){
      needToClear[x][y] = 1;
    }
  }
}

// 4 bits array operations 
unsigned char get_first4bit_of_byte (unsigned char b){ return (0|(b>>4));}
unsigned char get_last4bit_of_byte  (unsigned char b){ return (b & 0b00001111); }
void          set_first4bit_of_byte (unsigned char &b, unsigned char val){ b = (val<<4|get_last4bit_of_byte(b));}
void          set_last4bit_of_byte  (unsigned char &b, unsigned char val){ b = (get_first4bit_of_byte(b)<<4|val);}

// "Public" functions
void set_frameBuffer_val(uint16_t x, uint16_t y, unsigned char val){
  #ifdef framebuffer_color_16
    if (x%2==0){
      set_first4bit_of_byte (frameBuffer[x/2][y], val);
    }else{
      set_last4bit_of_byte  (frameBuffer[x/2][y], val);
    }
  #endif
  #ifdef framebuffer_color_256
    frameBuffer[x][y] = val;
  #endif
}

unsigned char get_frameBuffer_val(uint16_t x, uint16_t y){
  #ifdef framebuffer_color_16
    if (x%2==0){
      return get_first4bit_of_byte (frameBuffer[x/2][y]);
    }else{
      return get_last4bit_of_byte  (frameBuffer[x/2][y]);
    }
  #endif
  #ifdef framebuffer_color_256
    return frameBuffer[x][y];
  #endif
}

void set_needToClear_val(uint16_t x, uint16_t y, bool val){
  //if (x<0||y<0||x>=SCREEN_WIDTH||y>=SCREEN_HEIGHT) return;
  return set_bit_to_byte(needToClear[x/8][y], x%8, val);
}

bool get_needToClear_val(uint16_t x, uint16_t y){
  //if (x<0||y<0||x>=SCREEN_WIDTH||y>=SCREEN_HEIGHT) return false;
  return get_bit_from_byte(needToClear[x/8][y], x%8);
}
//
/////////////////////////////////////////////////////


void clearscreen_displayDriver(){
  for (uint16_t x=0; x<SCREEN_WIDTH; x++){
    for (uint16_t y=0; y<SCREEN_HEIGHT; y++){
      if (get_needToClear_val(x,y) && get_frameBuffer_val(x,y)!=0){
        set_frameBuffer_val(x,y, 0);
        M5.Lcd.drawPixel(x, y, get_m5ColorFromPallette(0)); //Background color
      }
      
      set_needToClear_val(x,y,1);
    }
  }

  set_DrawLimits(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

}

void updatescreen_displayDriver(){

  M5.update();

  //drawDebugString(get_CurrentColor_from16_palette(0x00, 0x00, 0x00), 40);
}

void driver_clearScreen(){
  setDrawColor_background();
  init_frameBuffer();
  M5.Lcd.fillScreen(get_m5ColorFromPallette(current_color));
  setDrawColor_contrast();
}

////////////////////////////////////////////////////////
// ##################################################

byte red;
byte green;
byte blue;

byte red_bg     = 255;
byte green_bg   = 255;
byte blue_bg    = 255;

byte palette[16][3] = {
  {0xFF, 0x00, 0x00}, // 0,   Background
  {0xff, 0x00, 0x00}, // 1,   Red
  {0xff, 0xd9, 0x00}, // 2
  {0x33, 0xff, 0x00}, // 3
  {0x00, 0xff, 0xea}, // 4
  {0x00, 0x66, 0xff}, // 5
  {0x00, 0x24, 0x5a}, // 6
  {0x6f, 0x00, 0xff}, // 7
  {0xff, 0x00, 0x8c}, // 8
  {0xff, 0xff, 0xff}, // 9,   White
  {0xd8, 0xd8, 0xd8}, // 10
  {0xb4, 0xb4, 0xb4}, // 11
  {0x8f, 0x8f, 0x8f}, // 12
  {0x6b, 0x6b, 0x6b}, // 13
  {0x47, 0x47, 0x47}, // 14
  {0x00, 0x00, 0x00}, // 15,  Black
};

uint32_t get_m5ColorFromPallette(byte num){
  return ( (palette[num][0]*31/255) <<11)|( (palette[num][1]*31/255) <<6)|( (palette[num][2]*31/255) <<0);
}

void set_CurrentColor(byte r, byte g, byte b){
  
  current_color = get_CurrentColor_from16_palette(r, g, b);
  return;
}

byte get_CurrentColor_from16_palette(byte r, byte g, byte b){
  //current_color = (r<<16)|(g<<8)|(b<<0);
  byte nearest_color = 0;
  int nearest_color_vector = 255*4;

  int current_vector;
  for(int i=1; i<16; i++){
    current_vector = abs(r - palette[i][0]) + abs(g - palette[i][1]) + abs(b - palette[i][2]);
    if (current_vector==0){
      current_color =  i;
      return current_color;
    }
    if (current_vector<nearest_color_vector){
      nearest_color = i;
      nearest_color_vector = current_vector;
    }
  }

  return nearest_color;
}

void setDrawColor(byte red_set, byte green_set, byte blue_set){
  red   = red_set;
  green = green_set;
  blue  = blue_set;
  
  set_CurrentColor(red, green, blue);
}

void initColor_background(byte red_set, byte green_set, byte blue_set){
  red_bg   = red_set;
  green_bg = green_set;
  blue_bg  = blue_set;

  palette[0][0] = red_set;
  palette[0][1] = green_set;
  palette[0][2] = blue_set;
}

void setDrawColor_background(){
  //set_CurrentColor(red_bg, green_bg, blue_bg);
  current_color = 0;
}

void setDrawColor_contrast(){
  if (red_bg + green_bg + blue_bg > 383){
    //red   = 0;
    //green = 0;
    //blue  = 0;
    current_color = 15; // Black
  }else{
    //red   = 255;
    //green = 255;
    //blue  = 255;
    current_color = 9;  // White
  }
  
  
  //M5.Lcd.setColor(red, green, blue);
}

// ##################################################
////////////////////////////////////////////////////////


void setup_displayDriver(){
    M5.begin();
  // M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);

  init_frameBuffer();
}

void setPixel(int x, int y){

  if ( 
    x>=drawLimit_x_min  &&
    y>=drawLimit_y_min  &&
    x<drawLimit_x_max   &&
    y<drawLimit_y_max   &&

    x>=0                &&
    y>=0                &&
    x<SCREEN_WIDTH      &&
    y<SCREEN_HEIGHT
    ){

      if (get_frameBuffer_val(x,y)!=current_color){
        M5.Lcd.drawPixel(x, y, get_m5ColorFromPallette(current_color));
        set_frameBuffer_val(x,y, current_color);
      }
      
      set_needToClear_val(x,y,0);

    }
}
*/