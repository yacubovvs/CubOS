
#ifdef FRAMEBUFFER_ENABLE

  #ifdef FRAMEBUFFER_TWIN_FULL

    #define FRAMEBUFFER_SIZE SCREEN_WIDTH * SCREEN_HEIGHT * FRAMEBUFFER_BYTE_PER_PIXEL
    //#define FRAMEBUFFER_SIZE SCREEN_WIDTH * SCREEN_HEIGHT

    #if FRAMEBUFFER_BYTE_PER_PIXEL==2
      #define FRAMEBUFFER_TYPE uint16_t
    #endif

    #if FRAMEBUFFER_BYTE_PER_PIXEL==1
      #define FRAMEBUFFER_TYPE uint8_t
    #endif

    FRAMEBUFFER_TYPE * FRAMEBUFFER_currentFrame;
    FRAMEBUFFER_TYPE * FRAMEBUFFER_newFrame;
    bool FRAMEBUFFER_pixelChangedchanged[SCREEN_WIDTH*SCREEN_HEIGHT + 1];

  #endif
#endif


uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue){
  #ifdef SCREEN_INVERT_COLORS
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  
  #ifdef SCREEN_CHANGE_BLUE_RED
    return ( (blue*31/255) <<11)|( (green*31/255) <<6)|( (red*31/255) <<0);
  #else
    return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
    //return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
  #endif
}

void setGradientColor(
    unsigned char r1, 
    unsigned char g1, 
    unsigned char b1, 
    unsigned char r2, 
    unsigned char g2, 
    unsigned char b2, 
    unsigned int steps, 
    unsigned int current_steps
    ){

  unsigned char r;
  unsigned char g;
  unsigned char b;

  unsigned char r_min = min(r1,r2);
  unsigned char g_min = min(g1,g2);
  unsigned char b_min = min(b1,b2);

  unsigned char r_max = max(r1,r2);
  unsigned char g_max = max(g1,g2);
  unsigned char b_max = max(b1,b2);

  float k = (float)current_steps/(float)steps;

  if(r1==r2) r = r1;
  else{
    if(r1>r2) r = r_min + ((float)(r_max - r_min))*k;
    else r = r_max - ((float)(r_max - r_min))*k; 
  }
  

  if(g1==g2) g = g1;
  else{
    if(g1>g2) g = g_min + ((float)(g_max - g_min))*k;
    else g = g_max - ((float)(g_max - g_min))*k; 
  }

  if(b1==b2) b = b1;
  else{
    if(b1>b2) b = b_min + ((float)(b_max - b_min))*k;
    else b = b_max - ((float)(b_max - b_min))*k; 
  }

  setDrawColor(r, g, b);
}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                                  FRAMEBUFFER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/

unsigned char current_red;
unsigned char current_green;
unsigned char current_blue;

unsigned char get_current_red(){
  return current_red;
}

unsigned char get_current_green(){
  return current_green;
}

unsigned char get_current_blue(){
  return current_blue;
}

void setDrawColor(unsigned char red_new, unsigned char green_new, unsigned char blue_new){
  current_red     = red_new;
  current_green   = green_new;
  current_blue    = blue_new;
  driver_display_setDrawColor(red_new, green_new, blue_new);
}

void setDrawColor(uint16_t color){
  driver_display_setDrawColor(color);
}

#ifdef FRAMEBUFFER_ENABLE

  #ifdef FRAMEBUFFER_TWIN_FULL

    bool FRAMEBUFFER_isChanged = false;

    void setFRAMEBUFFER_isChanged(bool v){
      FRAMEBUFFER_isChanged = v;
    }

    bool getFRAMEBUFFER_isChanged(){
      return FRAMEBUFFER_isChanged;
    }

    void FRAMEBUFFER_fill(uint16_t fillColor){
      for(int x=0; x<SCREEN_WIDTH; x++){
        for(int y=0; y<SCREEN_HEIGHT; y++){
          long position = y * SCREEN_WIDTH + x;

          FRAMEBUFFER_pixelChangedchanged[x + SCREEN_WIDTH*y] = false;
          FRAMEBUFFER_new_setPixel(x, y, 0);
          FRAMEBUFFER_current_setPixel(x, y, 0);
        }
      }
    }

    void FRAMEBUFFER_reset(){
      FRAMEBUFFER_fill(0);
    }

    void FRAMEBUFFER_new_setPixel(uint16_t x, uint16_t y, uint16_t color){
      long position = y * (SCREEN_WIDTH-1) + x;
      FRAMEBUFFER_newFrame[position] = FRAMEBUFFER_16bitColor_to_framebufferColor(color);
    }

    void FRAMEBUFFER_current_setPixel(uint16_t x, uint16_t y, uint16_t color){
      long position = y * (SCREEN_WIDTH-1) + x;
      FRAMEBUFFER_currentFrame[position] = FRAMEBUFFER_16bitColor_to_framebufferColor(color);
    }

    void FRAMEBUFFER_current_setPixel(long position, uint16_t color){
      FRAMEBUFFER_currentFrame[position] = FRAMEBUFFER_16bitColor_to_framebufferColor(color);
    }

    FRAMEBUFFER_TYPE FRAMEBUFFER_16bitColor_to_framebufferColor(uint16_t color){
      
      #if FRAMEBUFFER_BYTE_PER_PIXEL==2
        return color;
      #elif FRAMEBUFFER_BYTE_PER_PIXEL==1

        unsigned char r = (color & 0xF800) >> 11; //  5bit
        unsigned char g = (color & 0x07E0) >> 5;  //  6bit
        unsigned char b = color & 0x001F;         //  5bit

        r = (r * 7) / 31;
        g = (g * 7) / 63;
        b = (b * 3) / 31;

        int bufferCollor = (r<<5) | (g<<2) | b;
        return (FRAMEBUFFER_TYPE)bufferCollor;
      #endif
      
    }

    uint16_t FRAMEBUFFER_framebufferColor_to_16bitColor(FRAMEBUFFER_TYPE color){
      
      #if FRAMEBUFFER_BYTE_PER_PIXEL==2
        return color;
      #elif FRAMEBUFFER_BYTE_PER_PIXEL==1
        
        unsigned char r = (color & 0b11100000) >> 5; //  3bit
        unsigned char g = (color & 0b00011100) >> 2;  //  3bit
        unsigned char b = color & 0b00000011;         //  2bit

        r = (r * 31) / 7;
        g = (g * 63) / 7;
        b = (b * 31) / 3;

        uint16_t bufferCollor = (r<<11) | (g<<5) | b;

        return (uint16_t)bufferCollor;
      #endif
      
    }

    uint16_t FRAMEBUFFER_new_getPixel(uint16_t x, uint16_t y){
      long position = y * (SCREEN_WIDTH-1) + x;
      return FRAMEBUFFER_framebufferColor_to_16bitColor(FRAMEBUFFER_newFrame[position]);
    }

    uint16_t FRAMEBUFFER_new_getPixel(long position){
      return FRAMEBUFFER_framebufferColor_to_16bitColor(FRAMEBUFFER_newFrame[position]);
    }

    uint16_t FRAMEBUFFER_current_getPixel(uint16_t x, uint16_t y){
      long position = y * (SCREEN_WIDTH-1) + x;
      return FRAMEBUFFER_framebufferColor_to_16bitColor(FRAMEBUFFER_currentFrame[position]);
    }

    uint16_t FRAMEBUFFER_current_getPixel(long position){
      return FRAMEBUFFER_framebufferColor_to_16bitColor(FRAMEBUFFER_currentFrame[position]);
    }

  #endif

#endif

void fillScreen(unsigned char red, unsigned char green, unsigned char blue){
  TEMPORARILY_DISABLE_LIMITS();

  #ifdef FRAMEBUFFER_ENABLE

    setDrawColor(red, green, blue);
    for(int x=0; x<SCREEN_WIDTH; x++){
      for(int y=0; y<SCREEN_HEIGHT; y++){
        drawPixel(x,y);
      }
    }

  #else

    deriver_displayfillScreen(red, green, blue);

  #endif

  TEMPORARILY_RESTORE_LIMITS();
}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                                  DRAW LIMITS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/

bool DRAW_LIMITS_Enabled  = false;
int DRAW_LIMITS_top       = 0;
int DRAW_LIMITS_bottom    = SCREEN_HEIGHT;
int DRAW_LIMITS_left      = 0;
int DRAW_LIMITS_right     = SCREEN_WIDTH;
 
void DRAW_LIMITS_setEnable(bool enabled){
  DRAW_LIMITS_Enabled = enabled;
}

void DRAW_LIMIT_reset(){
  DRAW_LIMITS_top       = 0;
  DRAW_LIMITS_bottom    = SCREEN_HEIGHT;
  DRAW_LIMITS_left      = 0;
  DRAW_LIMITS_right     = SCREEN_WIDTH;
}

void DRAW_LIMITS_setEnable(int top, int bottom, int left, int right){
  if(top!=-1)     DRAW_LIMITS_top       = top;
  if(bottom!=-1)  DRAW_LIMITS_bottom    = bottom;
  if(left!=-1)    DRAW_LIMITS_left      = left;
  if(right!=-1)   DRAW_LIMITS_right     = right;
}

bool DRAW_LIMITS_getEnable(){
  return DRAW_LIMITS_Enabled;
}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                                  POWER CONTROLL
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
unsigned char core_display_brightness             = 100;

#ifndef DEFAULT_TIME_TO_POWEROFF_DISPLAY
  #define DEFAULT_TIME_TO_POWEROFF_DISPLAY 5;
#endif

#ifndef DEFAULT_DELAY_TO_FADE_DISPLAY
  #define DEFAULT_DELAY_TO_FADE_DISPLAY 10;
#endif


#ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
  unsigned char core_display_brightness_fade        = 15;
  unsigned char core_display_time_delay_to_fade     = DEFAULT_DELAY_TO_FADE_DISPLAY; //10
#endif
unsigned char core_display_time_delay_to_poweroff = DEFAULT_TIME_TO_POWEROFF_DISPLAY; //5

#ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
  void set_core_display_brightness(unsigned char value){ 
    if(value>100) value = 100;
    core_display_brightness = value;
    driver_display_setBrightness(core_display_brightness);
  }
#endif

#ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
  void set_core_display_brightness_fade(unsigned char value){ 
    if(value>100) value = 100;
    core_display_brightness_fade = value;
  }

  void set_core_display_time_delay_to_fade(unsigned char value){
    if(value>240) value = 240;
    core_display_time_delay_to_fade = value;
  }
#endif

void set_core_display_time_delay_to_poweroff(unsigned char value){ 
  if(value==0) value = 1;
  if(value>240) value = 240;
  core_display_time_delay_to_poweroff = value;
}

unsigned char get_core_display_brightness(){return core_display_brightness; }
#ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
  unsigned char get_core_display_brightness_fade(){return core_display_brightness_fade; }
  unsigned char get_core_display_time_delay_to_fade(){return core_display_time_delay_to_fade; }
#endif
unsigned char get_core_display_time_delay_to_poweroff(){return core_display_time_delay_to_poweroff; }

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                                  DISPLAY FUNCTIONS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
unsigned char background_red = 0;
unsigned char background_green = 0;
unsigned char background_blue = 0;

unsigned char contrast_red = 255;
unsigned char contrast_green = 255;
unsigned char contrast_blue = 255;

unsigned char getBackgroundColor_red(){ return background_red;} 
unsigned char getContrastColor_red(){ return contrast_red;} 

unsigned char getBackgroundColor_green(){ return background_green;} 
unsigned char getContrastColor_green(){ return contrast_green;} 

unsigned char getBackgroundColor_blue(){ return background_blue;} 
unsigned char getContrastColor_blue(){ return contrast_blue;} 

void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b){
  background_red    = r;
  background_green  = g;
  background_blue   = b;
} 

void setContrastColor(unsigned char r, unsigned char g, unsigned char b){
  contrast_red    = r;
  contrast_green  = g;
  contrast_blue   = b;
} 

void setDrawColor_BackGroundColor(){
  setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
}

void setDrawColor_ContrastColor(){
  setDrawColor(getContrastColor_red(), getContrastColor_green(), getContrastColor_blue());
}

//////////////////////////////////////////////////
// Function needed for CubOS

static const unsigned char font_cubos[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x3E, 0x5B, 0x4F, 0x5B, 0x3E,
  0x3E, 0x6B, 0x4F, 0x6B, 0x3E,
  0x1C, 0x3E, 0x7C, 0x3E, 0x1C,
  0x18, 0x3C, 0x7E, 0x3C, 0x18,
  0x1C, 0x57, 0x7D, 0x57, 0x1C,
  0x1C, 0x5E, 0x7F, 0x5E, 0x1C,
  0x00, 0x18, 0x3C, 0x18, 0x00,
  0xFF, 0xE7, 0xC3, 0xE7, 0xFF,
  0x00, 0x18, 0x24, 0x18, 0x00,
  0xFF, 0xE7, 0xDB, 0xE7, 0xFF,
  0x30, 0x48, 0x3A, 0x06, 0x0E,
  0x26, 0x29, 0x79, 0x29, 0x26,
  0x40, 0x7F, 0x05, 0x05, 0x07,
  0x40, 0x7F, 0x05, 0x25, 0x3F,
  0x5A, 0x3C, 0xE7, 0x3C, 0x5A,
  0x7F, 0x3E, 0x1C, 0x1C, 0x08,
  0x08, 0x1C, 0x1C, 0x3E, 0x7F,
  0x14, 0x22, 0x7F, 0x22, 0x14,
  0x5F, 0x5F, 0x00, 0x5F, 0x5F,
  0x06, 0x09, 0x7F, 0x01, 0x7F,
  0x00, 0x66, 0x89, 0x95, 0x6A,
  0x60, 0x60, 0x60, 0x60, 0x60,
  0x94, 0xA2, 0xFF, 0xA2, 0x94,
  0x08, 0x04, 0x7E, 0x04, 0x08,
  0x10, 0x20, 0x7E, 0x20, 0x10,
  0x08, 0x08, 0x2A, 0x1C, 0x08,
  0x08, 0x1C, 0x2A, 0x08, 0x08,
  0x1E, 0x10, 0x10, 0x10, 0x10,
  0x0C, 0x1E, 0x0C, 0x1E, 0x0C,
  0x30, 0x38, 0x3E, 0x38, 0x30,
  0x06, 0x0E, 0x3E, 0x0E, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x5F, 0x00, 0x00,
  0x00, 0x07, 0x00, 0x07, 0x00,
  0x14, 0x7F, 0x14, 0x7F, 0x14,
  0x24, 0x2A, 0x7F, 0x2A, 0x12,
  0x23, 0x13, 0x08, 0x64, 0x62,
  0x36, 0x49, 0x56, 0x20, 0x50,
  0x00, 0x08, 0x07, 0x03, 0x00,
  0x00, 0x1C, 0x22, 0x41, 0x00,
  0x00, 0x41, 0x22, 0x1C, 0x00,
  0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
  0x08, 0x08, 0x3E, 0x08, 0x08,
  0x00, 0x80, 0x70, 0x30, 0x00,
  0x08, 0x08, 0x08, 0x08, 0x08,
  0x00, 0x00, 0x60, 0x60, 0x00,
  0x20, 0x10, 0x08, 0x04, 0x02,
  0x3E, 0x51, 0x49, 0x45, 0x3E,
  0x00, 0x42, 0x7F, 0x40, 0x00,
  0x72, 0x49, 0x49, 0x49, 0x46,
  0x21, 0x41, 0x49, 0x4D, 0x33,
  0x18, 0x14, 0x12, 0x7F, 0x10,
  0x27, 0x45, 0x45, 0x45, 0x39,
  0x3C, 0x4A, 0x49, 0x49, 0x31,
  0x41, 0x21, 0x11, 0x09, 0x07,
  0x36, 0x49, 0x49, 0x49, 0x36,
  0x46, 0x49, 0x49, 0x29, 0x1E,
  0x00, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x40, 0x34, 0x00, 0x00,
  0x00, 0x08, 0x14, 0x22, 0x41,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x00, 0x41, 0x22, 0x14, 0x08,
  0x02, 0x01, 0x59, 0x09, 0x06,
  0x3E, 0x41, 0x5D, 0x59, 0x4E,
  0x7C, 0x12, 0x11, 0x12, 0x7C,
  0x7F, 0x49, 0x49, 0x49, 0x36,
  0x3E, 0x41, 0x41, 0x41, 0x22,
  0x7F, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x49, 0x49, 0x49, 0x41,
  0x7F, 0x09, 0x09, 0x09, 0x01,
  0x3E, 0x41, 0x41, 0x51, 0x73,
  0x7F, 0x08, 0x08, 0x08, 0x7F,
  0x00, 0x41, 0x7F, 0x41, 0x00,
  0x20, 0x40, 0x41, 0x3F, 0x01,
  0x7F, 0x08, 0x14, 0x22, 0x41,
  0x7F, 0x40, 0x40, 0x40, 0x40,
  0x7F, 0x02, 0x1C, 0x02, 0x7F,
  0x7F, 0x04, 0x08, 0x10, 0x7F,
  0x3E, 0x41, 0x41, 0x41, 0x3E,
  0x7F, 0x09, 0x09, 0x09, 0x06,
  0x3E, 0x41, 0x51, 0x21, 0x5E,
  0x7F, 0x09, 0x19, 0x29, 0x46,
  0x26, 0x49, 0x49, 0x49, 0x32,
  0x03, 0x01, 0x7F, 0x01, 0x03,
  0x3F, 0x40, 0x40, 0x40, 0x3F,
  0x1F, 0x20, 0x40, 0x20, 0x1F,
  0x3F, 0x40, 0x38, 0x40, 0x3F,
  0x63, 0x14, 0x08, 0x14, 0x63,
  0x03, 0x04, 0x78, 0x04, 0x03,
  0x61, 0x59, 0x49, 0x4D, 0x43,
  0x00, 0x7F, 0x41, 0x41, 0x41,
  0x02, 0x04, 0x08, 0x10, 0x20,
  0x00, 0x41, 0x41, 0x41, 0x7F,
  0x04, 0x02, 0x01, 0x02, 0x04,
  0x40, 0x40, 0x40, 0x40, 0x40,
  0x00, 0x03, 0x07, 0x08, 0x00,
  0x20, 0x54, 0x54, 0x78, 0x40,
  0x7F, 0x28, 0x44, 0x44, 0x38,
  0x38, 0x44, 0x44, 0x44, 0x28,
  0x38, 0x44, 0x44, 0x28, 0x7F,
  0x38, 0x54, 0x54, 0x54, 0x18,
  0x00, 0x08, 0x7E, 0x09, 0x02,
  0x18, 0xA4, 0xA4, 0x9C, 0x78,
  0x7F, 0x08, 0x04, 0x04, 0x78,
  0x00, 0x44, 0x7D, 0x40, 0x00,
  0x20, 0x40, 0x40, 0x3D, 0x00,
  0x7F, 0x10, 0x28, 0x44, 0x00,
  0x00, 0x41, 0x7F, 0x40, 0x00,
  0x7C, 0x04, 0x78, 0x04, 0x78,
  0x7C, 0x08, 0x04, 0x04, 0x78,
  0x38, 0x44, 0x44, 0x44, 0x38,
  0xFC, 0x18, 0x24, 0x24, 0x18,
  0x18, 0x24, 0x24, 0x18, 0xFC,
  0x7C, 0x08, 0x04, 0x04, 0x08,
  0x48, 0x54, 0x54, 0x54, 0x24,
  0x04, 0x04, 0x3F, 0x44, 0x24,
  0x3C, 0x40, 0x40, 0x20, 0x7C,
  0x1C, 0x20, 0x40, 0x20, 0x1C,
  0x3C, 0x40, 0x30, 0x40, 0x3C,
  0x44, 0x28, 0x10, 0x28, 0x44,
  0x4C, 0x90, 0x90, 0x90, 0x7C,
  0x44, 0x64, 0x54, 0x4C, 0x44,
  0x00, 0x08, 0x36, 0x41, 0x00,
  0x00, 0x00, 0x77, 0x00, 0x00,
  0x00, 0x41, 0x36, 0x08, 0x00,
  0x02, 0x01, 0x02, 0x04, 0x02,
  0x3C, 0x26, 0x23, 0x26, 0x3C,
  0x1E, 0xA1, 0xA1, 0x61, 0x12,
  0x3A, 0x40, 0x40, 0x20, 0x7A,
  0x38, 0x54, 0x54, 0x55, 0x59,
  0x21, 0x55, 0x55, 0x79, 0x41,
  0x22, 0x54, 0x54, 0x78, 0x42, // a-umlaut
  0x21, 0x55, 0x54, 0x78, 0x40,
  0x20, 0x54, 0x55, 0x79, 0x40,
  0x0C, 0x1E, 0x52, 0x72, 0x12,
  0x39, 0x55, 0x55, 0x55, 0x59,
  0x39, 0x54, 0x54, 0x54, 0x59,
  0x39, 0x55, 0x54, 0x54, 0x58,
  0x00, 0x00, 0x45, 0x7C, 0x41,
  0x00, 0x02, 0x45, 0x7D, 0x42,
  0x00, 0x01, 0x45, 0x7C, 0x40,
  0x7D, 0x12, 0x11, 0x12, 0x7D, // A-umlaut
  0xF0, 0x28, 0x25, 0x28, 0xF0,
  0x7C, 0x54, 0x55, 0x45, 0x00,
  0x20, 0x54, 0x54, 0x7C, 0x54,
  0x7C, 0x0A, 0x09, 0x7F, 0x49,
  0x32, 0x49, 0x49, 0x49, 0x32,
  0x3A, 0x44, 0x44, 0x44, 0x3A, // o-umlaut
  0x32, 0x4A, 0x48, 0x48, 0x30,
  0x3A, 0x41, 0x41, 0x21, 0x7A,
  0x3A, 0x42, 0x40, 0x20, 0x78,
  0x00, 0x9D, 0xA0, 0xA0, 0x7D,
  0x3D, 0x42, 0x42, 0x42, 0x3D, // O-umlaut
  0x3D, 0x40, 0x40, 0x40, 0x3D,
  0x3C, 0x24, 0xFF, 0x24, 0x24,
  0x48, 0x7E, 0x49, 0x43, 0x66,
  0x2B, 0x2F, 0xFC, 0x2F, 0x2B,
  0xFF, 0x09, 0x29, 0xF6, 0x20,
  0xC0, 0x88, 0x7E, 0x09, 0x03,
  0x20, 0x54, 0x54, 0x79, 0x41,
  0x00, 0x00, 0x44, 0x7D, 0x41,
  0x30, 0x48, 0x48, 0x4A, 0x32,
  0x38, 0x40, 0x40, 0x22, 0x7A,
  0x00, 0x7A, 0x0A, 0x0A, 0x72,
  0x7D, 0x0D, 0x19, 0x31, 0x7D,
  0x26, 0x29, 0x29, 0x2F, 0x28,
  0x26, 0x29, 0x29, 0x29, 0x26,
  0x30, 0x48, 0x4D, 0x40, 0x20,
  0x38, 0x08, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x38,
  0x2F, 0x10, 0xC8, 0xAC, 0xBA,
  0x2F, 0x10, 0x28, 0x34, 0xFA,
  0x00, 0x00, 0x7B, 0x00, 0x00,
  0x08, 0x14, 0x2A, 0x14, 0x22,
  0x22, 0x14, 0x2A, 0x14, 0x08,
  0x55, 0x00, 0x55, 0x00, 0x55, // #176 (25% block) missing in old code
  0xAA, 0x55, 0xAA, 0x55, 0xAA, // 50% block
  0xFF, 0x55, 0xFF, 0x55, 0xFF, // 75% block
  0x00, 0x00, 0x00, 0xFF, 0x00,
  0x10, 0x10, 0x10, 0xFF, 0x00,
  0x14, 0x14, 0x14, 0xFF, 0x00,
  0x10, 0x10, 0xFF, 0x00, 0xFF,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x14, 0x14, 0x14, 0xFC, 0x00,
  0x14, 0x14, 0xF7, 0x00, 0xFF,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x14, 0x14, 0xF4, 0x04, 0xFC,
  0x14, 0x14, 0x17, 0x10, 0x1F,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0x1F, 0x00,
  0x10, 0x10, 0x10, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0x1F, 0x10,
  0x10, 0x10, 0x10, 0xF0, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0xFF, 0x10,
  0x00, 0x00, 0x00, 0xFF, 0x14,
  0x00, 0x00, 0xFF, 0x00, 0xFF,
  0x00, 0x00, 0x1F, 0x10, 0x17,
  0x00, 0x00, 0xFC, 0x04, 0xF4,
  0x14, 0x14, 0x17, 0x10, 0x17,
  0x14, 0x14, 0xF4, 0x04, 0xF4,
  0x00, 0x00, 0xFF, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x14, 0x14,
  0x14, 0x14, 0xF7, 0x00, 0xF7,
  0x14, 0x14, 0x14, 0x17, 0x14,
  0x10, 0x10, 0x1F, 0x10, 0x1F,
  0x14, 0x14, 0x14, 0xF4, 0x14,
  0x10, 0x10, 0xF0, 0x10, 0xF0,
  0x00, 0x00, 0x1F, 0x10, 0x1F,
  0x00, 0x00, 0x00, 0x1F, 0x14,
  0x00, 0x00, 0x00, 0xFC, 0x14,
  0x00, 0x00, 0xF0, 0x10, 0xF0,
  0x10, 0x10, 0xFF, 0x10, 0xFF,
  0x14, 0x14, 0x14, 0xFF, 0x14,
  0x10, 0x10, 0x10, 0x1F, 0x00,
  0x00, 0x00, 0x00, 0xF0, 0x10,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
  0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xFF, 0xFF,
  0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
  0x38, 0x44, 0x44, 0x38, 0x44,
  0xFC, 0x4A, 0x4A, 0x4A, 0x34, // sharp-s or beta
  0x7E, 0x02, 0x02, 0x06, 0x06,
  0x02, 0x7E, 0x02, 0x7E, 0x02,
  0x63, 0x55, 0x49, 0x41, 0x63,
  0x38, 0x44, 0x44, 0x3C, 0x04,
  0x40, 0x7E, 0x20, 0x1E, 0x20,
  0x06, 0x02, 0x7E, 0x02, 0x02,
  0x99, 0xA5, 0xE7, 0xA5, 0x99,
  0x1C, 0x2A, 0x49, 0x2A, 0x1C,
  0x4C, 0x72, 0x01, 0x72, 0x4C,
  0x30, 0x4A, 0x4D, 0x4D, 0x30,
  0x30, 0x48, 0x78, 0x48, 0x30,
  0xBC, 0x62, 0x5A, 0x46, 0x3D,
  0x3E, 0x49, 0x49, 0x49, 0x00,
  0x7E, 0x01, 0x01, 0x01, 0x7E,
  0x2A, 0x2A, 0x2A, 0x2A, 0x2A,
  0x44, 0x44, 0x5F, 0x44, 0x44,
  0x40, 0x51, 0x4A, 0x44, 0x40,
  0x40, 0x44, 0x4A, 0x51, 0x40,
  0x00, 0x00, 0xFF, 0x01, 0x03,
  0xE0, 0x80, 0xFF, 0x00, 0x00,
  0x08, 0x08, 0x6B, 0x6B, 0x08,
  0x36, 0x12, 0x36, 0x24, 0x36,
  0x06, 0x0F, 0x09, 0x0F, 0x06,
  0x00, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x00, 0x10, 0x10, 0x00,
  0x30, 0x40, 0xFF, 0x01, 0x01,
  0x00, 0x1F, 0x01, 0x01, 0x1E,
  0x00, 0x19, 0x1D, 0x17, 0x12,
  0x00, 0x3C, 0x3C, 0x3C, 0x3C,
  0x00, 0x00, 0x00, 0x00, 0x00  // #255 NBSP
};

void setStr(char * dString, int x, int y, unsigned char fontSize){
  
  if(DRAW_LIMITS_Enabled){
    //if out of screen
    if(x>DRAW_LIMITS_right||y>DRAW_LIMITS_bottom) return;
    if(y<DRAW_LIMITS_top - fontSize*FONT_CHAR_WIDTH-1) return;
  }

  int string_length = strlen(dString);
  for (int i=0; i<string_length; i++){

    for (unsigned char char_part=0; char_part<5; char_part++){
      const unsigned char_part_element = pgm_read_byte(&font_cubos[dString[i] *5 + char_part]);

      for (unsigned char bit=0; bit<8; bit++){

        if (getBitInByte(char_part_element, bit)){
          #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
            unsigned char pixelsInLine=0;
            for (unsigned char i=bit+1; i<8; i++){
              if(getBitInByte(char_part_element, i)) {
                pixelsInLine++;
              }else{
                break;
              }
            }
          #endif

          if(fontSize>1){
            int x_r = x + char_part*fontSize + i*FONT_CHAR_WIDTH*fontSize;
            int y_r = y + bit*fontSize;

            #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
              if(pixelsInLine>0){
                drawRect(x_r, y_r + (pixelsInLine)*fontSize, x_r + fontSize - 1, y_r - fontSize+1, true);
                bit+=pixelsInLine;
              }else{
                drawRect(x_r, y_r, x_r + fontSize - 1, y_r - fontSize+1, true);
              }
            #else
              drawRect(x_r, y_r, x_r + fontSize - 1, y_r - fontSize+1, true);
            #endif
            
          }else{
            #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
              

              if(pixelsInLine>0){
                driver_display_drawFastVLine(x +  char_part + i*FONT_CHAR_WIDTH, y + bit, pixelsInLine);
                bit+=pixelsInLine;
              }else{
                drawPixel(x + char_part + i*FONT_CHAR_WIDTH, y + bit);
              }
            #else
              drawPixel(x + char_part + i*FONT_CHAR_WIDTH, y + bit);
            #endif
          }
        }
      }
    }

  }
}

void drawString(char * dString, int x, int y){
  setStr(dString, x, y, 1);
}

void drawString(char * dString, int x, int y, unsigned char fontSize){
  setStr(dString, x, y, fontSize);
}

void drawString(int val, int x, int y){
  char str[16];
  sprintf(str, "%d", val);
  drawString( str, 0, y);
}

void drawString(String dString, int x, int y, unsigned char fontSize){
  int str_len = dString.length() + 1;
  char element_value[str_len];
  dString.toCharArray(element_value, str_len);

  drawString(element_value, x, y, fontSize);
}

void drawString(String dString, int x, int y){
  drawString(dString, x, y, 1);
}

void drawString_centered(char * dString, int y){
  drawString(dString, (SCREEN_WIDTH - strlen(dString)*FONT_CHAR_WIDTH)/2, y);  
}

void clearString(char * dString, int x, int y, unsigned char fontSize){
  #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
    if(fontSize==0) fontSize = 1;
    int string_length = strlen(dString);
    drawRect(x,y-fontSize, x+string_length*fontSize*FONT_CHAR_WIDTH, y+fontSize*(FONT_CHAR_HEIGHT-1),true);
  #else
    setStr(dString, x, y, fontSize);
  #endif
}
void clearString(char * dString, int x, int y){
  clearString(dString, x, y, 1);
}

void clearString_centered(char * dString, int y){
  clearString(dString, (SCREEN_WIDTH - strlen(dString)*FONT_CHAR_WIDTH)/2, y, 1);  
}

void clearString(String dString, int x, int y, unsigned char fontSize){
  int str_len = dString.length() + 1;
  char element_value[str_len];
  dString.toCharArray(element_value, str_len);

  clearString(element_value, x, y, fontSize);
}

void drawString_centered(char * dString, int x, int y){
  drawString(dString, x - strlen(dString)*FONT_CHAR_WIDTH/2, y);  
}

void clearString_centered(String dString, int x, int y, unsigned char fontSize){
  clearString(dString, x - dString.length()*fontSize*FONT_CHAR_WIDTH/2, y, fontSize);  
}

void clearString_centered(char * dString, int x, int y){
  clearString(dString, x - strlen(dString)*FONT_CHAR_WIDTH/2, y, 1);    
}

void drawString_centered(String dString, int y){
  drawString(dString, (SCREEN_WIDTH - dString.length()*FONT_CHAR_WIDTH)/2, y);  
}

void drawString_centered(String dString, int x, int y){
  drawString(dString, x - dString.length()*FONT_CHAR_WIDTH/2, y);  
}

void drawString_centered(String dString, int x, int y, unsigned char fontSize){
  drawString(dString, x - dString.length()*FONT_CHAR_WIDTH*fontSize/2, y, fontSize);  
}

void drawString_centered_fontSize(String dString, uint16_t y, unsigned char fontSize){
  drawString(dString, (SCREEN_WIDTH - dString.length()*(FONT_CHAR_WIDTH)*fontSize)/2 + (int)(fontSize/2), y, fontSize);
}

void drawString_rightAlign(String dString, int x, int y){
  drawString(dString, x - dString.length()*FONT_CHAR_WIDTH, y);  
}

void core_display_setup(){
  #ifdef FRAMEBUFFER_ENABLE

    #ifdef FRAMEBUFFER_TWIN_FULL

      #ifdef FRAMEBUFFER_PSRAM
        FRAMEBUFFER_currentFrame  = (FRAMEBUFFER_TYPE *)ps_malloc(FRAMEBUFFER_SIZE);
        FRAMEBUFFER_newFrame      = (FRAMEBUFFER_TYPE *)ps_malloc(FRAMEBUFFER_SIZE);
      #else
        FRAMEBUFFER_currentFrame  = (FRAMEBUFFER_TYPE *)malloc(FRAMEBUFFER_SIZE);
        FRAMEBUFFER_newFrame      = (FRAMEBUFFER_TYPE *)malloc(FRAMEBUFFER_SIZE);
      #endif
    #endif
  #endif

  driver_display_setup();
  #ifdef FRAMEBUFFER_ENABLE
    FRAMEBUFFER_reset();
  #endif
}

//int fs_ms_max = 0;

void core_display_loop(){
  
  #ifdef FRAMEBUFFER_ENABLE
    #ifdef FRAMEBUFFER_TWIN_FULL
      if(getFRAMEBUFFER_isChanged()){
        bool shown = false;

        for(int y=0; y<SCREEN_HEIGHT; y++){
          for(int x=0; x<SCREEN_WIDTH; x++){
            if(FRAMEBUFFER_pixelChangedchanged[x + (SCREEN_WIDTH-1)*y]==true){
              long position = y * (SCREEN_WIDTH-1) + x;  
              uint16_t newColor = FRAMEBUFFER_new_getPixel(position);
            
              if(FRAMEBUFFER_current_getPixel(position)!=newColor){
                display_driver_setPixel(x, y, newColor);
                FRAMEBUFFER_current_setPixel(position, newColor);
                FRAMEBUFFER_pixelChangedchanged[x + (SCREEN_WIDTH-1)*y] = false;
              }
            }
          }
        }

        //FRAMEBUFFER_pixelChangedchanged[239 + (SCREEN_WIDTH-1)*239] = true;
        //FRAMEBUFFER_new_setPixel(239,239, 65535);
      }
      setFRAMEBUFFER_isChanged(false);
    #endif
  #endif
  
}

void drawPixel(int x, int y){
  if(DRAW_LIMITS_Enabled){
    //if out of screen
    if(x>=DRAW_LIMITS_right || x<=DRAW_LIMITS_left || y<=DRAW_LIMITS_top+1 || y>DRAW_LIMITS_bottom) return;
  }
    
  #ifdef FRAMEBUFFER_ENABLE
    if(x>=SCREEN_WIDTH) return;
    #ifdef FRAMEBUFFER_TWIN_FULL
      FRAMEBUFFER_new_setPixel(x, y, getDrawColor());

      long position = x + (SCREEN_WIDTH-1)*y;
      if(position>=0 && position<=SCREEN_HEIGHT*SCREEN_WIDTH) FRAMEBUFFER_pixelChangedchanged[position] = true;

      if(!getFRAMEBUFFER_isChanged()) setFRAMEBUFFER_isChanged(true);
      
      //display_driver_setPixel(x, y);
    #endif
  #else
    display_driver_setPixel(x, y);
  #endif
  
}

void drawLine(int x0, int y0, int x1, int y1){

  #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
    if(x0==x1){
      driver_display_drawFastVLine(x0, min(y0, y1), abs(y0-y1));
      return;
    }

    if(y0==y1){
      driver_display_drawFastHLine(min(x0, x1), y0, abs(x0-x1));
      return;
    }
  #endif

  int dy = y1 - y0; // Difference between y0 and y1
  int dx = x1 - x0; // Difference between x0 and x1
  int stepx, stepy;

  if (dy < 0)
  {
    dy = -dy;
    stepy = -1;
  }
  else
    stepy = 1;

  if (dx < 0)
  {
    dx = -dx;
    stepx = -1;
  }
  else
    stepx = 1;

  dy <<= 1; // dy is now 2*dy
  dx <<= 1; // dx is now 2*dx
  drawPixel(x0, y0); // Draw the first pixel.

  if (dx > dy) 
  {
    int fraction = dy - (dx >> 1);
    while (x0 != x1)
    {
      if (fraction >= 0)
      {
        y0 += stepy;
        fraction -= dx;
      }
      x0 += stepx;
      fraction += dy;
      drawPixel(x0, y0);
    }
  }
  else
  {
    int fraction = dx - (dy >> 1);
    while (y0 != y1)
    {
      if (fraction >= 0)
      {
        x0 += stepx;
        fraction -= dy;
      }
      y0 += stepy;
      fraction += dx;
      drawPixel(x0, y0);
    }
  }
}

void drawRect(int x0, int y0, int x1, int y1){
  drawRect(x0, y0, x1, y1, false);
}

void drawRect(int x0, int y0, int x1, int y1, bool fill){
  // check if the rectangle is to be filled
  if (fill == 1)
  {
    #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
      driver_display_fillRect(min(x0, x1), min(y0, y1), abs(x0-x1), abs(y0-y1));
      return;
    #else
      int xDiff;

      if(x0 > x1)
        xDiff = x0 - x1; //Find the difference between the x vars
      else
        xDiff = x1 - x0;

      while(xDiff >= 0)
      {
        drawLine(x0, y0, x0, y1);

        if(x0 > x1)
          x0--;
        else
          x0++;

        xDiff--;
      }
    #endif
  }else{
    // best way to draw an unfilled rectangle is to draw four lines
    drawLine(x0, y0, x1, y0);
    drawLine(x0, y1, x1, y1);
    drawLine(x0, y0, x0, y1);
    drawLine(x1, y0, x1, y1);
  }
}

// The Bresenham algorithm
void drawCircle(int x0, int y0, int radius, bool fill){
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;
	while(y >= 0) {
    if(fill){
      drawLine(x0 + x, y0 + y, x0 + x, y0);
      drawLine(x0 + x, y0 - y, x0 + x, y0);
      drawLine(x0 - x, y0 + y, x0 - x, y0);
      drawLine(x0 - x, y0 - y, x0 - x, y0);
    }else{
      drawPixel(x0 + x, y0 + y);
      drawPixel(x0 + x, y0 - y);
      drawPixel(x0 - x, y0 + y);
      drawPixel(x0 - x, y0 - y);
    }

		error = 2 * (delta + y) - 1;
		if(delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if(delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
}


void drawCircle(int x0, int y0, int radius){
  drawCircle(x0, y0, radius, false);
}

/*
void drawArc_fade(int x0, int y0, int radius, int drawFromAngle, int drawToAngle, uint16_t width, byte r, byte g, byte b, byte r_fade, byte g_fade, byte b_fade){
  float start_angle = DEG_TO_RAD*drawFromAngle;
  float end_angle = DEG_TO_RAD*drawToAngle;
  float r = radius;

  float step = 1.0/((float)radius*1.6); // 1.6 imperical value
  for(float i = start_angle; i < end_angle; i = i + step)
  {
    float t_cos = cos(i);
    float t_sin = sin(i);

    setDrawColor(r_fade, g_fade, b_fade);
    drawPixel(x0 + t_cos * (r-0.8), y0 + t_sin * (r-0.8));
    drawPixel(x0 + t_cos * (r-width+0.8), y0 + t_sin * (r-width+0.8));

    setDrawColor(r, g, b);
    for(float radius_i=r-0.8; radius_i>=r-width+0.8; radius_i-=0.8){ // 0.8 imperical value
      drawPixel(x0 + t_cos * radius_i, y0 + t_sin * radius_i);
    }
  }
}
*/

void drawArc(int x0, int y0, int radius, int drawFromAngle, int drawToAngle, uint16_t width, bool drawFading){
  double start_angle = DEG_TO_RAD*drawFromAngle;
  double end_angle = DEG_TO_RAD*drawToAngle;
  double r = radius;

  double step = 1.0/((double)radius*1.6); // 1.6 imperical value

  unsigned char draw_red    = get_current_red();
  unsigned char draw_green  = get_current_green();
  unsigned char draw_blue   = get_current_blue();

  for(double i = start_angle; i < end_angle; i = i + step){
    double t_cos = cos(i);
    double t_sin = sin(i);
    if(!drawFading){
      for(double radius_i=r; radius_i>=r-width; radius_i-=0.8){ // 0.8 imperical value
        drawPixel(round(x0 + t_cos * radius_i), round(y0 + t_sin * radius_i));
      }
    }else{
      
      setDrawColor(draw_red, draw_green, draw_blue);

      //for(double radius_i=r-0.4; radius_i>=r-width+0.4; radius_i-=0.8){ // 0.8 imperical value
      for(double radius_i=r; radius_i>=r-width; radius_i-=0.8){ // 0.8 imperical value
        drawPixel(round(x0 + t_cos * radius_i), round(y0 + t_sin * radius_i));
      }

      setDrawColor( 
        (draw_red    + getBackgroundColor_red())/3, 
        (draw_green  + getBackgroundColor_green())/3, 
        (draw_blue   + getBackgroundColor_blue())/3
      );

      drawPixel(round(x0 + t_cos * (r)), round(y0 + t_sin * (r)));
      drawPixel(round(x0 + t_cos * (r-width)), round(y0 + t_sin * (r-width)));

      setDrawColor( 
        (draw_red    + getBackgroundColor_red())/2, 
        (draw_green  + getBackgroundColor_green())/2, 
        (draw_blue   + getBackgroundColor_blue())/2
      );

      drawPixel(round(x0 + t_cos * (r-0.4)), round(y0 + t_sin * (r-0.4)));
      drawPixel(round(x0 + t_cos * (r-width+0.8)), round(y0 + t_sin * (r-width+0.8)));

    }
    
  }
}

void drawArc(int x0, int y0, int radius, int drawFromAngle, int drawToAngle, uint16_t width){
  drawArc(x0, y0, radius, drawFromAngle, drawToAngle, width, false);
}

// System function
int treangle_area(int x0, int y0, int x1, int y1, int x2, int y2){
   return abs((x0 - x2)*(y1 - y2) + (x1-x2)*(y2-y0));
}

void drawRect_custom( int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, bool fill){
  if (fill){
    // all angles should be less thаn 180 degrees
    const int min_x = min(min(x0, x1), min(x2, x3));
    const int max_x = max(max(x0, x1), max(x2, x3));
    const int min_y = min(min(y0, y1), min(y2, y3));
    const int max_y = max(max(y0, y1), max(y2, y3));

    for (int i_x=min_x; i_x<max_x; i_x++){
      for (int i_y=min_y; i_y<max_y; i_y++){

        if (
          treangle_area(x0, y0, x1, y1, x2, y2) ==
          treangle_area(x0, y0, x1, y1, i_x, i_y) + 
          treangle_area(x0, y0, x2, y2, i_x, i_y) + 
          treangle_area(x2, y2, x1, y1, i_x, i_y)
          || 
          treangle_area(x0, y0, x3, y3, x2, y2) ==
          treangle_area(x0, y0, x3, y3, i_x, i_y) + 
          treangle_area(x0, y0, x2, y2, i_x, i_y) + 
          treangle_area(x2, y2, x3, y3, i_x, i_y)
        ){
          drawPixel(i_x, i_y);
        }
      }
    }    
  }else{
    drawLine(x0, y0, x1, y1);
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x0, y0);
  }
}

void drawImage(bool draw, const unsigned char* data, int x, int y){
    /*
    DRAW_LIMITS_Enabled
    DRAW_LIMITS_top
    DRAW_LIMITS_bottom
    DRAW_LIMITS_left
    DRAW_LIMITS_right
    */

  if(DRAW_LIMITS_Enabled){
    //if out of screen
    if(x>DRAW_LIMITS_right||y>DRAW_LIMITS_bottom) return;
  }
  /*
  ################################################
  #                                              #
  #               NEW IMAGE FORMAT               #
  #                                              #
  ################################################
  */

  long readPosition = 0;
  //int data_size = sizeof(data)/sizeof(data[0]);
  unsigned char currentBbyte;


  int image_type = readRawParam(data, readPosition);    // type of image
  int image_wigth = readRawParam(data, readPosition);   // width
  int image_height = readRawParam(data, readPosition);  // height

  if(DRAW_LIMITS_Enabled){
    //if out of screen
    if(x+image_wigth<DRAW_LIMITS_left||y+image_height<DRAW_LIMITS_top) return;
  }

  if(!draw){
    setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
    #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
      drawRect(x, y, x+image_wigth, y+image_height, true);
      return;
    #endif
  }

  int icon_x=0;
  int icon_y=0;

  if(image_type==0x01){
    
    while(1){
      unsigned char color_var = readRawChar(data, readPosition);
      
      if (color_var==0x04){ // new color layout
    
        unsigned char red    = readRawChar(data, readPosition); 
        unsigned char green  = readRawChar(data, readPosition); 
        unsigned char blue   = readRawChar(data, readPosition); 

        if(draw){
          setDrawColor(red, green, blue);
        }
        //else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        
        icon_x = 0;
        icon_y = 0;

        for (int readingBbyte=0; readingBbyte<(image_wigth*image_height%8==0?image_wigth*image_height/8:image_wigth*image_height/8+1); readingBbyte++){
          //if(data_size<=readPosition) break;
          currentBbyte = readRawChar(data, readPosition);

          if(currentBbyte!=0x00 && currentBbyte!=0xFF){
            for (unsigned char d=0; d<8; d++){
              if (icon_x>=image_wigth){
                icon_y+=icon_x/image_wigth;
                icon_x %= image_wigth;
              }

              //if (currentBbyte&1<<(7-d)) drawPixel(x + icon_x, y + icon_y);
              //if (getBitInByte(currentBbyte, d)) drawPixel(x + icon_x, y + icon_y);
              if (getBitInByte(currentBbyte, 7-d)){
                #ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
                  unsigned char pixelsInARow = 0;
                  if(d!=7){
                    for (unsigned char future_d=d+1; future_d<8; future_d++){
                      if (getBitInByte(currentBbyte, 7-future_d)){
                        pixelsInARow++;
                      } else{
                        break;
                      }
                    }
                  }

                  if(pixelsInARow>1){
                    driver_display_drawFastHLine(x + icon_x, y + icon_y, pixelsInARow);
                    d+=pixelsInARow;
                    icon_x+=pixelsInARow;
                  }else{
                    drawPixel(x + icon_x, y + icon_y);  
                  }
                #else
                  drawPixel(x + icon_x, y + icon_y);
                #endif
              }
              icon_x ++;
            }
          }else if(currentBbyte==0xFF){ // Saving 1ms!!!!

            if (icon_x>=image_wigth){
              icon_y+=icon_x/image_wigth;
              icon_x %= image_wigth;
            }

            drawLine(x + icon_x, y + icon_y, x + icon_x+7, y + icon_y); 
            icon_x+=8;
          }else{ // Saving 1ms!!!!
            icon_x+=8;
          }
        }
        
      }else{
        break;
      } 

    }
      
  #ifdef USE_TYPE2_OF_IMAGES
    }else if(image_type==0x02){
      // TYPE 2
      //image_wigth
      //image_height
      if(draw){
        uint16_t byte1;
        unsigned char byte2;
        for(icon_x=0; icon_x<image_wigth; icon_x++){
          for(icon_y=0; icon_y<image_height; icon_y++){
            byte1 = readRawChar(data, readPosition); 
            byte2 = readRawChar(data, readPosition); 

            uint16_t color = (byte1<<8) + byte2;
          
            //debug(String(byte1));
            //debug(String(byte2));
            //debug(String(color));
            //return;

            setDrawColor(color);
            drawPixel(x + icon_x, y + icon_y);
          }
        }
      }else{
        drawRect(x, y, x+image_wigth, y+image_height, true);
      }
      
  #endif
  }else{
    // Unknow type of image
    

  }

}

void drawImage(const unsigned char* data, int x, int y){
  drawImage(1, data, x, y);
}

bool getBitInByte(unsigned char currentbyte, unsigned char bitNum){
  return currentbyte&1<<(bitNum);
}

//////////////////////////////////////////////////
// For debugging
void drawIntString(long val, int x, int y){  
  char str[14];
  sprintf(str, "%d", val);
  drawString( str, x, y);
}

//////////////////////////////////////////////////
// For debugging
void drawDebugString(int val, int y){  
  drawString(val, 0, y);
}
