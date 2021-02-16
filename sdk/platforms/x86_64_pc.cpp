#define byte unsigned char
#define boolean bool
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

#include <unistd.h>

unsigned long millis(){
    return clock();
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
    usleep(x);
}

// PREDEFINED
const byte *getAppParams(char i, byte type);
void startApp(char num);
boolean getBitInByte(byte currentByte, byte bitNum);
void debug(String string);
void debug(String string, int delaytime);

void driver_controls_loop();
void driver_battery_loop();
void core_time_loop();
void driver_controls_setup();
void driver_battery_setup();
void core_time_setup();

class Application;
Application *getApp(byte i);

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