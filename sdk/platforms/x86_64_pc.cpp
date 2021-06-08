//#define unsigned char unsigned char
//#define bool bool
#define PROGMEM /**/
#define pgm_read_byte *
#define pgm_read_word *

#define max MAX
#define min MIN

#define PLATFORM_x86_64

#include <stdio.h>
#include <stdint.h>
#include "WString.h"
#include "stdlib_noniso.h"

#include "core_esp8266_noniso.cpp"
#include "stdlib_noniso.cpp"
#include "noniso.c"
#include "WString.cpp"
#include <ctime>
#include <chrono>

#if defined(_WIN32) || defined(_WIN64)
    #include <dos.h>
#endif

#include <unistd.h>

unsigned long millis(){
    return clock()/100;
}

int max(int a, int b){
    return ((a>b)?a:b);
}

int min(int a, int b){
    return ((a<b)?a:b);
}

unsigned char max(unsigned char a, unsigned char b){
    return ((a>b)?a:b);
}

unsigned char min(unsigned char a, unsigned char b){
    return ((a<b)?a:b);
}


void delay(int x){
    //sleep(x/1000);
    #if defined(_WIN32) || defined(_WIN64)
        _sleep(x);
    #endif
}

// PREDEFINED
void loop_touchScreenCore();
const unsigned char *getAppParams(char i, unsigned char type);
void startApp(char num);
bool getBitInByte(unsigned char currentByte, unsigned char bitNum);
void debug(String string);
void debug(String string, int delaytime);

void core_display_setup();
void core_display_loop();
void drawPixel(int x, int y);

void driver_controls_loop();
void driver_battery_loop();
void core_time_loop();
void driver_controls_setup();
void driver_battery_setup();
void core_time_setup();
void do_cpu_sleep();
unsigned long driver_control_get_last_user_avtivity();
void setup_touchScreenDriver();
void loop_touchScreenDriver();


class Application;
Application *getApp(unsigned char i);

void setup();
void loop();

#ifdef CPU_CONTROLL_ENABLE
    void driver_cpu_setup();
#endif

// START
int main()
{
  debug("App started");
  setup();
  while(true){
      loop();
  }
}

void core_battery_loop();
void core_views_statusBar_draw();
void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b);
void drawRect(int x0, int y0, int x1, int y1, bool fill);
void setDrawColor(unsigned char red, unsigned char green, unsigned char blue);
void fillScreen(unsigned char red, unsigned char green, unsigned char blue);
bool DRAW_LIMITS_getEnable();
uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue);
void DRAW_LIMITS_setEnable(bool enabled);
void core_views_statusBar_draw_time(bool draw);
void core_views_draw_statusbar_battery(bool draw, unsigned char batteryCharge);
void drawBatteryIcon(int x, int y, unsigned char charge, bool isCharging, bool draw);

#define DEG_TO_RAD      0.01745329
#define RAD_TO_DEG      57.2957786