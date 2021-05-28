/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/

// TOUCH


#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH 300

// BUTTONS

#define BUTTON_UP       0x01
#define BUTTON_SELECT   0x02
#define BUTTON_DOWN     0x03
#define BUTTON_BACK     0x04
#define BUTTON_POWER    0x05

#define DRIVER_CONTROLS_TOTALBUTTONS 3
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS     50
#define DRIVER_CONTROLS_DELAY_BEFORE_MULTY_PRESS    400

/*
############################################################################
#                                 EVENTS +                                 #
############################################################################
*/

#define EVENT_BUTTON_PRESSED                0x00
#define EVENT_BUTTON_RELEASED               0x01
#define EVENT_BUTTON_LONG_PRESS             0x02
#define EVENT_BUTTON_SHORT_PRESS            0x03
#define EVENT_BUTTON_SHORT_SINGLE_PRESS     0x04
#define EVENT_BUTTON_DOUBLE_PRESS           0x05
#define EVENT_ON_TIME_CHANGED               0x06
#define EVENT_ON_GOING_TO_SLEEP             0x07
#define EVENT_ON_WAKE_UP                    0x08

#define EVENT_ON_TOUCH_START                0x09
#define EVENT_ON_TOUCH_RELEASED             0x0A
#define EVENT_ON_TOUCH_CLICK                0x0B
#define EVENT_ON_TOUCH_LONG_PRESS           0x0C
#define EVENT_ON_TOUCH_DRAG                 0x0D
#define EVENT_ON_TOUCH_DOUBLE_PRESS         0x0E
#define EVENT_ON_TOUCH_SWIPE_FROM_LEFT      0x0F
#define EVENT_ON_TOUCH_SWIPE_FROM_RIGHT     0x10
#define EVENT_ON_TOUCH_SWIPE_FROM_TOP       0x11
#define EVENT_ON_TOUCH_SWIPE_FROM_BOTTOM    0x12


/*
 ############################################################################
                                 SLEEP TYPES -                               
*/

#define SLEEP_IDLE_CPU           0x01
#define SLEEP_DEEP          0x02
#define SLEEP_LIGHT         0x03
#define SLEEP_MODEM         0x04
#define SLEEP_DISPLAY       0x05
#define SLEEP_HIBERNATE     0x03
#define WAKE_MODEM          0x06
#define WAKE_DISPLAY        0x07
#define WAKE                0x08


#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP
/*
############################################################################
#                                 EVENTS -                                 #
############################################################################
*/

/*
############################################################################
#                                 STYLES +                                 #
############################################################################
*/

#define COREVIEWS_NO_ICON_ELEMENT_HEIGHT 40

/*
############################################################################
#                                 STYLES -                                 #
############################################################################
*/

#define ON_TIME_CHANGE_EVERY_MS 1000

#define UPDATE_RTC_EVERY 65
#define I2C_ENABLE
#define CPU_CONTROLL_ENABLE
#define POWERSAVE_ENABLE

#define FONT_SIZE_DEFAULT 2
#define HARDWARE_BUTTONS_VALUE 3

#define CONTROLS_DELAY_TO_DOUBLE_CLICK_MS DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS

#define SMOOTH_ANIMATION_COEFFICIENT    5
// #define MAIN_MENU_SMOOTH_ANIMATION
// #define NARROW_SCREEN

#define UPDATE_BATTERY_EVERY_MS 3000
#define SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE  4

// #define ACCELEROMETER_ENABLE
#define DISPLAY_BACKLIGHT_CONTROL_ENABLE
#define DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define WAKEUP_FROM_LIGHT_SLEEP_EVERY_MS 1000
#define WAKEUP_FROM_DEEP_SLEEP_EVERY_SECONDS 60*60*24

#define USE_TYPE2_OF_IMAGES
//#define PEDOMETER_ENABLE
/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/


/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      FOR ESP8266 USE NONOSSDK 2.2.2 +
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

//#define DEBUG_SERIAL
//#define screenDebug
#define TERMINAL_DEBUG

#define SCREEN_WIDTH            240     // Screen resolution width
#define SCREEN_HEIGHT           240     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

//#define device_has_battery

#define PLATFORM_PC_emulator
#define device_has_bluetooth
#define device_has_wifi

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED        // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE

#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH 300

#define colorScreen                     // Screen is colored
//#define noAnimation                   // Caurse of framebuffer type

//#define toDefaultApp_onLeftLongPress

//#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
#define STARTING_APP_NUMM   6     // for App number 7

#define CPU_SLEEP_ENABLE
#define CPU_SLEEP_TIME_DELAY 25000

#define BUTTON_UP       0
#define BUTTON_SELECT   1
#define BUTTON_DOWN     2
#define BUTTON_BACK     3

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define RTC_ENABLE

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  40

#undef I2C_ENABLE
#undef CPU_CONTROLL_ENABLE

/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/

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



/*
#ifdef _WIN32
  // See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 
  #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0501
  #endif
  #include <winsock2.h>
  #include <Ws2tcpip.h>
#else
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netdb.h>
  #include <unistd.h>
#endif
*/

#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
    //#pragma comment(lib, "ws2_32")//включаем библиотеку для сокетов
    //#include <winsock2.h>
    #include <sys/types.h>
#include <winsock2.h>
#include <memory.h>
#include <conio.h>
    //#include <Ws2tcpip.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

#define MSG_SIZE 1024
#define REPLY_SIZE 65536

#ifdef TOUCH_SCREEN_ENABLE
  bool TOUCH_SCREEN_isTouching = false;
  int TOUCH_SCREEN_X = 0;
  int TOUCH_SCREEN_Y = 0;

  bool getTOUCH_SCREEN_isTouching(){
    return TOUCH_SCREEN_isTouching;
  }

  int getTOUCH_SCREEN_X(){
    return TOUCH_SCREEN_X;
  }

  int getTOUCH_SCREEN_Y(){
    return TOUCH_SCREEN_Y;
  }
#endif

bool driver_display_needToUpdateScreen = false;

uint16_t get_uint16Color(unsigned char red, unsigned char green, unsigned char blue){
  return ( (red*31/255) <<11)|( (green*31/255) <<6)|( (blue*31/255) <<0);
}

#if defined(_WIN32) || defined(_WIN64) 
#else
  typedef int SOCKET;
#endif

SOCKET sock;

void sendMessageToDisplay(String message){
  const int str_len = message.length() + 1; 
  char char_array[str_len];
  message.toCharArray(char_array, str_len);
  send(sock,char_array,sizeof(char_array),0);
}

void driver_display_setup(){


  #if defined(_WIN32) || defined(_WIN64)
    WSADATA wData;
  #endif
  
	struct sockaddr_in addr,serv_addr;
	#if defined(_WIN32) || defined(_WIN64) 
    if(WSAStartup(MAKEWORD(1,1),&wData)!=0)
    {
      std::cout<<"socket not initialized\n";
    }
  #else
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    memset(recvBuff, '0',sizeof(recvBuff));
  #endif
	std::cout<<"socket initialized\n";

	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
	{
		std::cout<<"socket not created\n";
	}
	
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9100);
	addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
	bind(sock,(struct sockaddr *)&addr,sizeof(addr));

	
  
  #if defined(_WIN32) || defined(_WIN64)
  char HostName[1024];
    DWORD HostIP = 0;
    LPHOSTENT lphost;	  
    gethostname(HostName, 1024);
	  lphost=gethostbyname(HostName);
    serv_addr.sin_family=AF_INET;
	  memcpy((char*)&serv_addr.sin_addr,lphost->h_addr,lphost->h_length);
    serv_addr.sin_port=htons(9100);
  #else
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(9100);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){
        printf("\n inet_pton error occured\n");
    }

/*
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
       printf("\n Error : Connect Failed \n");
    }*/

  #endif	

	int error;
	//if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
  if(connect(sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		std::cout<<"connect error\n";
    #if defined(_WIN32) || defined(_WIN64) 
      error=WSAGetLastError();
      std::cout<<error<<"\n";
    #endif
		//_getch();
	}else{
    std::cout<<"connect success\n";
  }
	
}

void sleep_displayDriver(){
  //debug("Display sleep");
}

void wakeup_displayDriver(){
  //debug("Display wakeup");
}

void powerOff_displayDriver(){
  //debug("Display poweroff");
}

void powerOn_displayDriver(){
  //debug("Display poweron");
}

void driver_display_loop(){
  if(driver_display_needToUpdateScreen){
    sendMessageToDisplay("U\n");
    driver_display_needToUpdateScreen = false;
  }
}

void setPixel(int x, int y){
  sendMessageToDisplay("P " + String(x) + " " + String(y) + "\n");
  driver_display_needToUpdateScreen = true;
  #if defined(SCREEN_ROTATION_90)
    
  #elif defined(SCREEN_ROTATION_180)
    
  #elif defined(SCREEN_ROTATION_270)
    
  #else
    
  #endif
}

void setDrawColor(unsigned char red_new, unsigned char green_new, unsigned char blue_new){
  sendMessageToDisplay("C " + String(red_new) + " " + String(green_new) + " " + String(blue_new) + "\n");
}

void fillScreen(unsigned char red, unsigned char green, unsigned char blue){
  //debug("Fill screen");
  setDrawColor(red, green, blue);
  sendMessageToDisplay("F\n");
  driver_display_needToUpdateScreen = true;
}

bool button[] = {false, false, false, false};
bool digRead(unsigned char b){
  return button[b];
}

#ifdef TOUCH_SCREEN_ENABLE

  void driver_display_updateTouchScreen(){
    char buff[15];  
    sendMessageToDisplay("T\n");
    recv(sock,buff,sizeof(buff),0);

    TOUCH_SCREEN_isTouching = (buff[0]=='1');

    //char x[1];
    //char y[1];

    std::string x = "     ";
    std::string y = "     ";
    
    x[0] = buff[1];
    x[1] = buff[2];
    x[2] = buff[3];
    x[3] = buff[4];
    x[4] = buff[5];

    y[0] = buff[6];
    y[1] = buff[7];
    y[2] = buff[8];
    y[3] = buff[9];
    y[4] = buff[10];

    TOUCH_SCREEN_X = stoi(x);
    TOUCH_SCREEN_Y = stoi(y);
  }
#endif

void driver_display_updateControls(){
  char buff[15];
  sendMessageToDisplay("K\n");
	recv(sock,buff,sizeof(buff),0);
  //printf(buff);

  button[0] = (buff[0]=='1');
  button[1] = (buff[1]=='1');
  button[2] = (buff[2]=='1');
  button[3] = (buff[3]=='1');
  
  /*
  printf("%d-", (int)(buff[0]=='1'));
  printf("%d-", (int)(buff[1]=='1'));
  printf("%d-", (int)(buff[2]=='1'));
  printf("%d\n", (int)(buff[3]=='1'));
  */
}


#ifdef USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION
  void driver_display_drawFastVLine(int16_t x, int16_t y, int16_t w){
    sendMessageToDisplay("LV " + String(x) + " " + String(y) + " " + String(w) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
    
  }

  void driver_display_drawFastHLine(int16_t x, int16_t y, int16_t h){
    sendMessageToDisplay("LH " + String(x) + " " + String(y) + " " + String(h) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }

  void driver_display_fillRect(int16_t x, int16_t y, int16_t w, int16_t h){
    sendMessageToDisplay("R " + String(x) + " " + String(y) + " " + String(w) + " " + String(h) + "\n");
    driver_display_needToUpdateScreen = true;
    #if defined(SCREEN_ROTATION_90)
      
    #elif defined(SCREEN_ROTATION_180)
      
    #elif defined(SCREEN_ROTATION_270)
      
    #else
      
    #endif
  }
#endif

void driver_cpu_sleep(){}

void driver_cpu_wakeup(){}




#define LION_EMULATOR_BATTERY_VOLTAGE_100 420 

int getMaxBatteryAnalogValue(){
    return 0;
}

void driver_battery_setup(){
}

void driver_battery_loop(){

}

int driver_battery_raw(){
    return getMaxBatteryAnalogValue();
}

float driver_battery_getVoltage(){
    return (float)LION_EMULATOR_BATTERY_VOLTAGE_100 / 100.0;
}

int driver_battery_getVoltage_mV(){
    return LION_EMULATOR_BATTERY_VOLTAGE_100;
}

unsigned char driver_battery_getPercent(){
    int mV = driver_battery_getVoltage_mV();
    if(mV>=400){
        return 100;
    }else if(mV<=320){
        return 0;
    }else{
        int dmV = mV - 320;
        return dmV*100/80;
    }
    return 0;
}





/*
    ############################################################################################
    #                                     PREDEFINED +                                         #
    ############################################################################################
*/

void core_views_statusBar_draw();
void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b);
void drawRect(int x0, int y0, int x1, int y1, bool fill);
void setDrawColor(unsigned char red, unsigned char green, unsigned char blue);
void fillScreen(unsigned char red, unsigned char green, unsigned char blue);

/*
    ############################################################################################
    #                                     PREDEFINED -                                         #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                         EVENTS +                                         #
    #                                                                                          #
    ############################################################################################
*/

/*
#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
#define EVENT_ON_TIME_CHANGED           0x03
#define EVENT_ON_GOING_TO_SLEEP         0x04
#define EVENT_ON_WAKE_UP                0x05

#define EVENT_ON_TOUCH_START            0x06
#define EVENT_ON_TOUCH_RELEASED         0x07
#define EVENT_ON_TOUCH_CLICK            0x08
#define EVENT_ON_TOUCH_LONG_PRESS       0x09
#define EVENT_ON_TOUCH_DRAG             0x0A
#define EVENT_ON_TOUCH_DOUBLE_CLICK     0x0B
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                         EVENTS -                                         #
    #                                                                                          #
    ############################################################################################
*/


/*
    ############################################################################################
    #                                                                                          #
    #                                   APPLIACATION OJECT +                                   #
    #                                                                                          #
    ############################################################################################
*/


/////////////////////////////////////
// APPLICATION CLASS

class Application{
  public:
    int scroll_x              = 0;
    int scroll_y              = 0;
    int scroll_to_x           = 0;
    int scroll_to_y           = 0;
    bool isfullScreen         = true;
    bool showStatusBar        = true;
    bool preventSleep         = false;
    bool preventInAppSleep    = false;

    virtual void onLoop()     = 0;
    virtual void onDestroy()  = 0;
    virtual void onEvent(unsigned char event, int val1, int val2) = 0;

    void super_onCreate(){
      this->preventSleep = false;
      this->preventInAppSleep = false;
      if(this->showStatusBar) core_views_statusBar_draw();
    }

    Application(){};
};

Application* currentApp;
/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION OJECT -                                   #
    #                                                                                          #
    ############################################################################################
*/

void setup(){ 
  #ifdef BATTERY_ENABLE
    driver_battery_setup();
  #endif

  #ifdef RTC_ENABLE
      driver_RTC_setup();
  #endif

  #ifdef DEBUG_SERIAL
      Serial.begin(115200);
      debug("Serial debug started");
  #endif

  #ifdef ESP8266
      ESP.wdtDisable();
  #endif

  #ifdef CPU_CONTROLL_ENABLE
    core_cpu_setup();
  #endif
  
  driver_display_setup();
  core_display_setup();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_setup();
  #endif

  #ifdef TOUCH_SCREEN_ENABLE
    setup_touchScreenDriver();
  #endif

  #ifdef POWERSAVE_ENABLE
    core_powersave_setup();
  #endif

  #ifdef ACCELEROMETER_ENABLE
    driver_accelerometer_setup();
  #endif
  
  currentApp = getApp(STARTING_APP_NUMM);
  
}

bool isInSleep = false;
void loop(){
  
  core_display_loop();
  driver_display_loop();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_loop();
  #endif

  #ifdef TOUCH_SCREEN_ENABLE
    //loop_touchScreenDriver();
    loop_touchScreenCore();
  #endif

  #ifdef BATTERY_ENABLE
    core_battery_loop();
  #endif

  #ifdef CLOCK_ENABLE
    core_time_loop();
  #endif

  #ifdef CPU_CONTROLL_ENABLE
    core_cpu_loop();
  #endif

  #ifdef POWERSAVE_ENABLE
    core_powersave_loop();
  #endif

  #ifdef ACCELEROMETER_ENABLE
    driver_accelerometer_loop();
  #endif

  currentApp->onLoop(); 
  //currentApp->onLoop(); 

  #ifdef ESP8266
    //ESP.wdtDisable();
    ESP.wdtFeed();
  #endif

/*
  #ifdef CPU_SLEEP_ENABLE
//driver_cpu_sleep();
    if(millis() - driver_control_get_last_user_avtivity() > CPU_SLEEP_TIME_DELAY){
        if(!isInSleep){
            isInSleep = true;
            currentApp->onEvent(EVENT_ON_GOING_TO_SLEEP, 0, 0);
            powerOff_displayDriver();
        }

        do_cpu_sleep();
      
    }else{
      if(isInSleep){
        isInSleep = false;
        driver_cpu_wakeup();
        currentApp->onEvent(EVENT_ON_WAKE_UP, 0, 0);
      }
    }
    //driver_cpu_wakeup();
  #endif
*/

}

/*
#ifdef CPU_SLEEP_ENABLE
  void do_cpu_sleep(){
      driver_cpu_sleep();
  }
#endif
*/

void debug(String string){
  debug(string, 0);
}

void debug(int string){
  debug(String(string), 0);
}

void debug(String string, int delaytime){
    #ifdef TERMINAL_DEBUG
      int str_len = string.length() + 1;
      char element_value[str_len];
      string.toCharArray(element_value, str_len);
      printf(element_value);
      printf("\n");
    #endif

    #ifdef DEBUG_SERIAL
      Serial.println(string);
    #endif

    #ifdef screenDebug
      setDrawColor(255, 255, 255);
      drawString(string, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
      delay(delaytime);
      setDrawColor(0, 0, 0);
      drawString(string, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
    #endif
}

/*
void debug(const char* string, int delaytime){
  debug(String(string), delaytime);
}

void debug(const char* string){
  debug(String(string));
}*/


/*
    ############################################################################################
    #                                                                                          #
    #                                          ICONS +                                         #
    #                                                                                          #
    ############################################################################################
*/

#define ICON_ARROW_RIGHT            0x01
#define ICON_ARROW_LEFT             0x02
#define ICON_ARROW_UP               0x03
#define ICON_ARROW_DOWN             0x04
#define ICON_BATTERY_UNKNOWN        0x05

#define ICON_BATTERY_CHARGING       0x06
#define ICON_BATTERY_100            0x07
#define ICON_BATTERY_90             0x08
#define ICON_BATTERY_80             0x09
#define ICON_BATTERY_70             0x0A
#define ICON_BATTERY_60             0x0B
#define ICON_BATTERY_50             0x0C
#define ICON_BATTERY_40             0x0D
#define ICON_BATTERY_30             0x0E
#define ICON_BATTERY_20             0x0F
#define ICON_BATTERY_10             0x10
#define ICON_BATTERY_0              0x11

#define ICON_WIFI_CONNECTED         0x11
#define ICON_WIFI_NOTCONNECTED      0x12
#define ICON_WI_FI_IMG_OFF          0x13
#define ICON_BT_CONNECTED           0x14
#define ICON_BT_NOTCONNECTED        0x15
#define ICON_BT_OFF                 0x16

#define PARAM_TYPE_ICON             0x01
#define PARAM_TYPE_NAME             0x02

/*
    ############################################################################################
    #                                                                                          #
    #                                          ICONS -                                         #
    #                                                                                          #
    ############################################################################################
*/

// HELPERS
#define TEMPORARILY_DISABLE_LIMITS() bool DRAW_LIMITS_wasEnable = DRAW_LIMITS_getEnable(); DRAW_LIMITS_setEnable(false);
#define TEMPORARILY_RESTORE_LIMITS() DRAW_LIMITS_setEnable(DRAW_LIMITS_wasEnable);

#define TEMPORARILY_DISABLE_BACKGROUND() unsigned char tdbg_r = getBackgroundColor_red(); unsigned char tdbg_g = getBackgroundColor_green(); unsigned char tdbg_b = getBackgroundColor_blue();
#define TEMPORARILY_RESTORE_BACKGROUND() setBackgroundColor(tdbg_r, tdbg_g, tdbg_b);


#define DRIVER_CONTROLS_TOTALBUTTONS 4
#define _millis() millis()
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS 350

unsigned long last_user_activity = _millis();

// Do not change:
bool driver_control_pressed[]      = {false, false, false, false};
unsigned long driver_control_time_pressed[]    = {0, 0, 0, 0};

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, button, 0);
}

void driver_controls_setup(){
  last_user_activity = _millis();
}


void driver_controls_loop(){

    driver_display_updateControls();
    

    for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
        if (digRead(i)){
        last_user_activity = _millis();
        if(driver_control_pressed[i]==false){
            // press start
            driver_control_pressed[i]=true;
            driver_control_time_pressed[i] = _millis();
            onButtonEvent(EVENT_BUTTON_PRESSED, i);
        }else{
            // was pressed
            if(_millis()-driver_control_time_pressed[i]>DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS){
            // long press
            driver_control_time_pressed[i]=-1;
            onButtonEvent(EVENT_BUTTON_LONG_PRESS, i);
            }
        }

        }else{
        if(driver_control_pressed[i]==true){
            // released
            driver_control_pressed[i]=false;
            onButtonEvent(EVENT_BUTTON_RELEASED, i);

        }
        }
    }

}

unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}

void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}


#ifdef TOUCH_SCREEN_ENABLE
    void setup_touchScreenDriver(){
        
    }

    void loop_touchScreenDriver(){
        driver_display_updateTouchScreen();
    }

#endif



/*
    ############################################################################################
    #                                                                                          #
    #                                       APPLICATIONS +                                     #
    #                                                                                          #
    ############################################################################################
*/

#define APP_MENU_APPLICATIONS_0             AlarmApp
#define APP_MENU_APPLICATIONS_1             BarometerApp
#define APP_MENU_APPLICATIONS_2             ClockApp
#define APP_MENU_APPLICATIONS_3             CompassApp
#define APP_MENU_APPLICATIONS_4             FileManagerApp
#define APP_MENU_APPLICATIONS_5             InternetApp
#define APP_MENU_APPLICATIONS_6             SettingsApp
#define APP_MENU_APPLICATIONS_7             SimpleGameApp
#define APP_MENU_APPLICATIONS_8             TestApplicationApp
#define APP_MENU_APPLICATIONS_9             BatteryApp
#define APP_MENU_APPLICATIONS_10            TouchCalibration
#define APP_MENU_APPLICATIONS_11            TouchTest
#define APP_MENU_APPLICATIONS_12            KeyboardTest


/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                       #
    #                    -->> Add your application here                     #
    #                                                                       #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

/*
#define APP_MENU_APPLICATIONS_11            AppName
#define APP_MENU_APPLICATIONS_12            AppName
#define APP_MENU_APPLICATIONS_13            AppName
#define APP_MENU_APPLICATIONS_14            AppName
#define APP_MENU_APPLICATIONS_15            AppName
#define APP_MENU_APPLICATIONS_16            AppName
#define APP_MENU_APPLICATIONS_17            AppName
#define APP_MENU_APPLICATIONS_18            AppName
#define APP_MENU_APPLICATIONS_19            AppName
#define APP_MENU_APPLICATIONS_20            AppName
#define APP_MENU_APPLICATIONS_21            AppName
#define APP_MENU_APPLICATIONS_22            AppName
#define APP_MENU_APPLICATIONS_23            AppName
#define APP_MENU_APPLICATIONS_24            AppName
#define APP_MENU_APPLICATIONS_25            AppName
#define APP_MENU_APPLICATIONS_26            AppName
#define APP_MENU_APPLICATIONS_27            AppName
#define APP_MENU_APPLICATIONS_28            AppName
#define APP_MENU_APPLICATIONS_29            AppName
#define APP_MENU_APPLICATIONS_30            AppName
#define APP_MENU_APPLICATIONS_31            AppName
*/


/*
    ############################################################################################
    #                                                                                          #
    #                                       APPLICATIONS -                                     #
    #                                                                                          #
    ############################################################################################
*/

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                           READ RAW DATA                           #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

long readRawChar(const unsigned char* data, long &position){
    unsigned char data_char = (char)pgm_read_word(&(data[position]));
    position ++;
    return data_char;
}   

// Also this func need for B apps
uint64_t byte_to_value(unsigned char byte0, unsigned char byte1, unsigned char byte2, unsigned char byte3, unsigned char byte4, unsigned char byte5, unsigned char byte6, unsigned char byte7){
  return (byte7<<56)|(byte6<<48)|(byte5<<40)|(byte4<<32)|(byte3<<24)|(byte2<<16)|(byte1<<8)|byte0;
}

int readRawParam(const unsigned char* data, long &position){
    unsigned char paramType = readRawChar(data, position);

    if (paramType==0x02){
      return (unsigned char)readRawChar(data, position);
    }else if(paramType==0x03){
      return (unsigned int)byte_to_value(readRawChar(data, position), readRawChar(data, position),0,0,0,0,0,0);
    }
    return 0;
}

/*
*************************************
*                                   *
*          BASIC FUNCTIONS          *
*                                   *
*************************************
*/

//const float pi = 3.141592;

const float get_pi(){
    #ifdef platform_m5stack
        return 3.141592;
    #endif

    #ifdef platform_esp8266
        return 3.141592;
    #endif

    #ifdef platform_avr
        #ifndef conf_atm64_watch4
            return pi;
        #endif
    #endif

    return 3.141592;
}

char * int_to_char(int val){
    char str[2] = "";
    printf(str, "%d", val);
    return str;
}

void int_to_char(char *string, int num, bool fillNull){
    sprintf(string, (num<10&&fillNull?"0%d":"%d"), num);
}

// 1 bit array operations
void set_bit_toBbyte(unsigned char &b, unsigned char position, bool value){ if (value) b|=1<<position; else b&=~(1<<position);}
bool get_bit_fromBbyte(unsigned char b, unsigned char position){return (b&1<<position);}


/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                              CONVERT                              #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                   #
    #                               OTHER                               #
    #                                                                   #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

#ifdef device_can_cpu_prescale
    #ifdef platform_avr
        void set_cpu_prescale(clock_div_t prescale){
            clock_prescale_set(prescale);
        }
    #endif
#endif

String core_basic_addLeadBullToInt2digits(unsigned char byteIn){
    if(byteIn<10){
        return "0" + String(byteIn);
    }else{
        return String(byteIn);
    }
}

String getHexNumberFromNumber(unsigned char b){
    switch(b){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return String((int)b);
        case 10:
            return "A";
        case 11:
            return "B";
        case 12:
            return "C";
        case 13:
            return "D";
        case 14:
            return "E";
        case 15:
            return "F";
        default:
            return "";
    }

}

String getHexStringFromByte(unsigned char b){
    return "0x" + getHexNumberFromNumber(b/16) + getHexNumberFromNumber(b%16);
}


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

/*
FRAMEBUFFER_ENABLE
FRAMEBUFFER_TWIN_FULL
FRAMEBUFFER_BYTE_PER_PIXEL
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

    #define FRAMEBUFFER_SIZE SCREEN_WIDTH * SCREEN_HEIGHT * FRAMEBUFFER_BYTE_PER_PIXEL
    //#define FRAMEBUFFER_SIZE SCREEN_WIDTH * SCREEN_HEIGHT

    #if FRAMEBUFFER_BYTE_PER_PIXEL==2
      #define FRAMEBUFFER_TYPE uint16_t
    #endif

    bool FRAMEBUFFER_isChanged = false;

    void setFRAMEBUFFER_isChanged(bool v){
      FRAMEBUFFER_isChanged = v;
    }

    bool getFRAMEBUFFER_isChanged(){
      return FRAMEBUFFER_isChanged;
    }

    FRAMEBUFFER_TYPE * FRAMEBUFFER_currentFrame;
    FRAMEBUFFER_TYPE * FRAMEBUFFER_newFrame;
    bool FRAMEBUFFER_pixelChangedchanged[SCREEN_WIDTH*SCREEN_HEIGHT + 1];


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
      #ifdef FRAMEBUFFER_PSRAM
        FRAMEBUFFER_currentFrame  = (FRAMEBUFFER_TYPE *)ps_malloc(FRAMEBUFFER_SIZE);
        FRAMEBUFFER_newFrame      = (FRAMEBUFFER_TYPE *)ps_malloc(FRAMEBUFFER_SIZE);
      #else
        FRAMEBUFFER_currentFrame  = (FRAMEBUFFER_TYPE *)malloc(FRAMEBUFFER_SIZE);
        FRAMEBUFFER_newFrame      = (FRAMEBUFFER_TYPE *)malloc(FRAMEBUFFER_SIZE);
      #endif
      
      FRAMEBUFFER_fill(0);
    }

    void FRAMEBUFFER_new_setPixel(uint16_t x, uint16_t y, FRAMEBUFFER_TYPE color){
      long position = y * (SCREEN_WIDTH-1) + x;
      FRAMEBUFFER_newFrame[position] = color;
    }

    void FRAMEBUFFER_current_setPixel(uint16_t x, uint16_t y, FRAMEBUFFER_TYPE color){
      long position = y * (SCREEN_WIDTH-1) + x;
      FRAMEBUFFER_currentFrame[position] = color;
    }

    void FRAMEBUFFER_current_setPixel(uint16_t position, FRAMEBUFFER_TYPE color){
      FRAMEBUFFER_currentFrame[position] = color;
    }

    FRAMEBUFFER_TYPE FRAMEBUFFER_new_getPixel(uint16_t x, uint16_t y){
      long position = y * (SCREEN_WIDTH-1) + x;
      return FRAMEBUFFER_newFrame[position];
    }

    FRAMEBUFFER_TYPE FRAMEBUFFER_new_getPixel(uint16_t position){
      return FRAMEBUFFER_newFrame[position];
    }

    FRAMEBUFFER_TYPE FRAMEBUFFER_current_getPixel(uint16_t x, uint16_t y){
      long position = y * (SCREEN_WIDTH-1) + x;
      return FRAMEBUFFER_currentFrame[position];
    }

    FRAMEBUFFER_TYPE FRAMEBUFFER_current_getPixel(uint16_t position){
      return FRAMEBUFFER_currentFrame[position];
    }

  #endif

#endif

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

#ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
  unsigned char core_display_brightness_fade        = 20;
  unsigned char core_display_time_delay_to_fade     = 15;
#endif
unsigned char core_display_time_delay_to_poweroff = 30;

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
    FRAMEBUFFER_reset();
  #endif
}

//int fs_ms_max = 0;

void core_display_loop(){
  
  #ifdef FRAMEBUFFER_ENABLE
    #ifdef FRAMEBUFFER_TWIN_FULL
      if(getFRAMEBUFFER_isChanged()){

        //long drawMillis = millis();

        for(int y=0; y<SCREEN_HEIGHT; y++){
          for(int x=0; x<SCREEN_WIDTH; x++){
            if(FRAMEBUFFER_pixelChangedchanged[x + (SCREEN_WIDTH-1)*y]==true){
              uint16_t position = y * (SCREEN_WIDTH-1) + x;
              uint16_t newColor = FRAMEBUFFER_new_getPixel(position);
              if(FRAMEBUFFER_current_getPixel(position)!=newColor){
                //if(getDrawColor()!=newColor) setDrawColor(newColor);
                setPixel(x, y, newColor);
                //if(x>=SCREEN_WIDTH) debug("XMORE!");
                //if(y>=SCREEN_HEIGHT) debug("YMORE!");

                FRAMEBUFFER_current_setPixel(position, newColor);
                FRAMEBUFFER_pixelChangedchanged[x + (SCREEN_WIDTH-1)*y] = false;
              }
            }
          }
        }

        //int timeToDraw = millis() - drawMillis;
        /*
        if(fs_ms_max==0) fs_ms_max=1;
        else if(fs_ms_max<timeToDraw){
          fs_ms_max = timeToDraw;
          log_d("Framebuffer drawing %d", fs_ms_max);
        }*/

        //log_d("Framebuffer drawing %d", timeToDraw);
        
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

      uint16_t position = x + (SCREEN_WIDTH-1)*y;
      if(position>=0 && position<=SCREEN_HEIGHT*SCREEN_WIDTH) FRAMEBUFFER_pixelChangedchanged[position] = true;

      if(!getFRAMEBUFFER_isChanged()) setFRAMEBUFFER_isChanged(true);
      
      //setPixel(x, y);
    #endif
  #else
    setPixel(x, y);
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

void drawArc(int x0, int y0, int radius, int drawFromAngle, int drawToAngle, uint16_t width){
  drawArc(x0, y0, radius, drawFromAngle, drawToAngle, width, false);
}

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


unsigned char core_time_getHours_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getHours();
    #else
        return millis()/(1000*60*60)%24;
    #endif
}

void core_time_setHours(unsigned char hours){
    #ifdef RTC_ENABLE
        driver_RTC_setHours(hours);
    #else
        // TODO
    #endif
}

unsigned char core_time_getMinutes_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getMinutes();
    #else
        return millis()/(1000*60)%60;
    #endif
}

void core_time_setMinutes(unsigned char minutes){
    #ifdef RTC_ENABLE
        driver_RTC_setMinutes(minutes);
    #else
        // TODO
    #endif
}

unsigned char core_time_getSeconds_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getSeconds();
    #else
        return millis()/(1000)%60;
    #endif
}

void core_time_setSeconds(unsigned char seconds){
    #ifdef RTC_ENABLE
        driver_RTC_setSeconds(seconds);
    #else
        // TODO
    #endif
}

String core_time_getHours_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getHours_byte());
}

String core_time_getMinutes_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getMinutes_byte());
}

String core_time_getSeconds_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getSeconds_byte());
}

String core_time_getHourMinuteSecondsTime(){
    #ifdef RTC_ENABLE
        driver_RTC_refresh();
    #endif
    return core_time_getHours_String() + ":" + core_time_getMinutes_String() + ":" + core_time_getSeconds_String();
}

String core_time_getHourMinuteTime(){
    #ifdef RTC_ENABLE
        driver_RTC_refresh();
    #endif
    return core_time_getHours_String() + ":" + core_time_getMinutes_String();
}

unsigned char core_time_getMonth(){
    //return "February";
    #ifdef RTC_ENABLE
        return driver_RTC_getMonth();
    #else
        return 1;
    #endif
}

String core_time_getMonth_string(){
    switch(core_time_getMonth()){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "-";
    }  
}

String core_time_getMonth_stringShort(){
    switch(core_time_getMonth()){
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
        default:
            return "-";
    }  
}

unsigned char core_time_getDate(){
    #ifdef RTC_ENABLE
        return driver_RTC_getDate();
    #else
        return 1;
    #endif
}

unsigned char core_time_getWeekDay(){
    #ifdef RTC_ENABLE
        return driver_RTC_getWeekDay();
    #else
        return 0;
    #endif
}

String core_time_getWeekDay_string(){
	switch (core_time_getWeekDay()){
		case 0:
			return "Monday";
		case 1:
			return "Tuesday";
		case 2:
			return "Wednesday";
		case 3:
			return "Thursday";
		case 4:
			return "Friday";
		case 5:
			return "Saturday";
		case 6:
			return "Sunday";
		default:
			return "-";
	}
}

String core_time_getWeekDay_stringShort(){
	switch (core_time_getWeekDay()){
		case 0:
			return "Mon";
		case 1:
			return "Tue";
		case 2:
			return "Wed";
		case 3:
			return "Thu";
		case 4:
			return "Fri";
		case 5:
			return "Sat";
		case 6:
			return "Sun";
		default:
			return "-";
	}
}

uint16_t core_time_getYear(){
    #ifdef RTC_ENABLE
        return driver_RTC_getYear();
    #else
        return 2021;
    #endif
}

String core_time_getDateFull(){
    return core_basic_addLeadBullToInt2digits(core_time_getDate()) + "." + core_basic_addLeadBullToInt2digits(core_time_getMonth()) + "." + String(core_time_getYear());
}

void core_time_setYear(uint16_t year){
    #ifdef RTC_ENABLE
        return driver_RTC_setYear(year);
    #else
        // TODO
    #endif
}

void core_time_setMonth(unsigned char month){
    #ifdef RTC_ENABLE
        return driver_RTC_setMonth(month);
    #else
        // TODO
    #endif
}

void core_time_setDate(unsigned char date){
    #ifdef RTC_ENABLE
        return driver_RTC_setDate(date);
    #else
        // TODO
    #endif
}

void core_time_setWeekDay(unsigned char weekDay){
    #ifdef RTC_ENABLE
        return driver_RTC_setWeekDay(weekDay);
    #else
        // TODO
    #endif
}


//#define EVENT_ON_TIME_CHANGED              0x03
long lastTimeChange = millis()/ON_TIME_CHANGE_EVERY_MS;
void core_time_loop(){
    long currentTime = millis()/ON_TIME_CHANGE_EVERY_MS;
    if(currentTime!=lastTimeChange){
        #ifdef CLOCK_ENABLE
            if(currentApp->showStatusBar==true){
                core_views_statusBar_draw_time(false);
                core_views_statusBar_draw_time(true);
            }
        #endif
        driver_RTC_refresh();
        currentApp->onEvent(EVENT_ON_TIME_CHANGED, currentTime, 0);
        lastTimeChange = currentTime;
    }
}

void core_time_setAlarmBySeconds(unsigned char seconds){
    driver_RTC_setAlarmBySeconds(seconds);
}

unsigned char core_battery_getPercent(){
    #ifdef BATTERY_ENABLE
        return driver_battery_getPercent();
    #else
        return 0;
    #endif
}

#ifdef BATTERY_ENABLE
    long last_upodate_battery = 0;
    void core_battery_loop(){
        
        TEMPORARILY_DISABLE_LIMITS();
        driver_battery_loop();

        if(millis()-last_upodate_battery>UPDATE_BATTERY_EVERY_MS || millis()<last_upodate_battery){
            last_upodate_battery = millis();
            
            if(currentApp->showStatusBar){
                core_views_draw_statusbar_battery(false, driver_battery_getPercent());
                core_views_draw_statusbar_battery(true, driver_battery_getPercent());
            }
            
        }

        //ICON_BATTERY_100
        TEMPORARILY_RESTORE_LIMITS();
    }
#endif
//


/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR +                                       #
    #                                                                                          #
    ############################################################################################
*/

// background
#define STYLE_STATUSBAR_BACKGROUND_RED      116
#define STYLE_STATUSBAR_BACKGROUND_GREEN    0
#define STYLE_STATUSBAR_BACKGROUND_BLUE     176

// text color
#define STYLE_STATUSBAR_TEXT_RED      255
#define STYLE_STATUSBAR_TEXT_GREEN    255
#define STYLE_STATUSBAR_TEXT_BLUE     255

#ifdef BATTERY_ENABLE

    // BATTERY CHARGING ICON
    const unsigned char battery_charging[] PROGMEM = {
        //0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xdd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        //0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xF8,0xE0,0x00,0x00,0x1C,0xC0,0x00,0x00,0x0C,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0C,0xE0,0x00,0x00,0x1C,0x7F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0xE4,0xBF,0xFF,0xFF,0xF4,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF4,0x9F,0xFF,0xFF,0xE4,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 100% ICON
    const unsigned char battery100[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0xE4,0xBF,0xFF,0xFF,0xF4,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF4,0x9F,0xFF,0xFF,0xE4,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 90% ICON
    const unsigned char battery90[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x84,0x9F,0xFF,0xFF,0x84,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 80% ICON
    const unsigned char battery80[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x04,0x9F,0xFF,0xFE,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 70% ICON
    const unsigned char battery70[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x04,0x9F,0xFF,0xF0,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 60% ICON
    const unsigned char battery60[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x04,0x9F,0xFF,0x80,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 50% ICON
    const unsigned char battery50[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x04,0x9F,0xFC,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 40% ICON
    const unsigned char battery40[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x04,0x9F,0xF0,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 30% ICON
    const unsigned char battery30[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0x80,0x00,0x04,0xBF,0x80,0x00,0x04,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x04,0x9F,0x80,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 20% ICON
    const unsigned char battery20[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9C,0x00,0x00,0x04,0xBC,0x00,0x00,0x04,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x04,0x9C,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 10% ICON
    const unsigned char battery10[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x90,0x00,0x00,0x04,0xB0,0x00,0x00,0x04,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x04,0x90,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 0% ICON
    const unsigned char battery0[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };
#endif

void core_views_statusBar_draw(){
    /*
            [ TIME | ----- | NOTIFICATIONS | BATTERY ]
    */
    bool DRAW_LIMITS_wasEnable = DRAW_LIMITS_Enabled;
    DRAW_LIMITS_setEnable(false);
    
    // BACKGROUND
    setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
    drawRect(0, 0, SCREEN_WIDTH, STYLE_STATUSBAR_HEIGHT, true);

    // TIME
    #ifdef CLOCK_ENABLE
        core_views_statusBar_draw_time(true);
    #endif

    // BATTERY
    #ifdef BATTERY_ENABLE
        core_views_draw_statusbar_battery(true, driver_battery_getPercent());
    #endif

    DRAW_LIMITS_setEnable(DRAW_LIMITS_Enabled);
}

#ifdef BATTERY_ENABLE
    unsigned char batteryCharge_last = 0;
    bool batteryCharge_last_wasCharging = false;
    void core_views_draw_statusbar_battery(bool draw, unsigned char batteryCharge){
        TEMPORARILY_DISABLE_BACKGROUND();

        setBackgroundColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
        if(draw){
            batteryCharge_last = batteryCharge;
            batteryCharge_last_wasCharging = driver_battery_isCharging();
        }

        const unsigned char *batteryIcon;
        if(batteryCharge_last>=100){
            batteryIcon = battery100;
        }else if(batteryCharge_last>=90){
            batteryIcon = battery90;
        }else if(batteryCharge_last>=80){
            batteryIcon = battery80;
        }else if(batteryCharge_last>=70){
            batteryIcon = battery70;
        }else if(batteryCharge_last>=60){
            batteryIcon = battery60;
        }else if(batteryCharge_last>=50){
            batteryIcon = battery50;
        }else if(batteryCharge_last>=40){
            batteryIcon = battery40;
        }else if(batteryCharge_last>=30){
            batteryIcon = battery30;
        }else if(batteryCharge_last>=20){
            batteryIcon = battery20;
        }else if(batteryCharge_last>=10){
            batteryIcon = battery10;
        }else{
            batteryIcon = battery0;
        }

        if(batteryCharge_last_wasCharging){
            drawImage(draw, battery_charging, SCREEN_WIDTH-32-STYLE_STATUSBAR_HEIGHT/5, STYLE_STATUSBAR_HEIGHT/2 - 8 + 1);
        }else{
            drawImage(draw, batteryIcon, SCREEN_WIDTH-32-STYLE_STATUSBAR_HEIGHT/5, STYLE_STATUSBAR_HEIGHT/2 - 8 + 1);
        }

        TEMPORARILY_RESTORE_BACKGROUND();
    }
#endif

String core_views_statusBar_draw_time_TimeString = "";
void core_views_statusBar_draw_time(bool draw){
    bool lastLimits = DRAW_LIMITS_getEnable();
    DRAW_LIMITS_setEnable(false);
    if(draw){
        setDrawColor(STYLE_STATUSBAR_TEXT_RED, STYLE_STATUSBAR_TEXT_GREEN, STYLE_STATUSBAR_TEXT_BLUE);
        core_views_statusBar_draw_time_TimeString = core_time_getHourMinuteTime();
        drawString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + 2, FONT_SIZE_DEFAULT);
    }else{
        setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
        clearString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + 2, FONT_SIZE_DEFAULT);
    }
    DRAW_LIMITS_setEnable(lastLimits);
}


/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST +                                       #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE                  4
#define CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE         20


int core_views_pages_list_get_element_position_x(int pages_quantity, int position){
    return ( (pages_quantity%2==1) ? (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE : -((-CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE/2) ) + (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE);
}

void core_views_draw_pages_list_simple(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity
){
    //SCREEN_WIDTH
    //SCREEN_HEIGHT

    if(draw) setDrawColor(128, 128, 128);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    for(int i=0; i<pages_quantity; i++){
        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, i);
        int element_y = y0;
        drawRect(element_x - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_x + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE);
    }
}

void core_views_draw_active_page(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity,
    unsigned char position
){
    #ifdef NARROW_SCREEN
        //if(draw) setDrawColor(getContrastColor_red(), getContrastColor_green(), getContrastColor_blue());
        #define GRAY_COLOR 164
        if(draw) setDrawColor(GRAY_COLOR, GRAY_COLOR, GRAY_COLOR);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        //drawString_centered(String(position) + "/" + String(pages_quantity), y0, 1);
        String activePageString = String(position + 1) + "/" + String(pages_quantity);
        drawString(activePageString, (SCREEN_WIDTH - activePageString.length()*FONT_CHAR_WIDTH*2)/2, y0 - FONT_CHAR_HEIGHT, 2);
    #else
        if(draw) setDrawColor(0, 255, 0);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, position);
        int element_y = y0;
        drawRect(element_x - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_x + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), true);
    #endif

}

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON +                                    #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_APPICON_IMAGE_WIDTH          32
#define CORE_VIEWS_APPICON_IMAGE_HEIGHT         32
#define CORE_VIEWS_APPICON_IMAGE_Y_OFFSET       -10
#define CORE_VIEWS_APPICON_TITLE_Y_OFFSET       20

void core_views_draw_app_icon(bool draw, int x, int y, const unsigned char* title, const unsigned char* icon){
    // image
    drawImage(draw, icon, x-CORE_VIEWS_APPICON_IMAGE_WIDTH/2, y-CORE_VIEWS_APPICON_IMAGE_HEIGHT/2 + CORE_VIEWS_APPICON_IMAGE_Y_OFFSET);

    // title
    if(draw){
        setDrawColor(255, 255, 255);
        drawString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET);
    }else{
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        clearString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET);
    }

    
}


#define CORE_VIEWS_SETTINGS_IMAGE_WIDTH 24
void core_views_draw_settings_item(bool draw, int x, int y, const unsigned char* title, String subTitle, const unsigned char* icon){

    #ifdef NARROW_SCREEN
        drawImage(draw, icon, x-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2, y-30);
        uint16_t titleShift = strlen((const char*)title)*FONT_CHAR_WIDTH/2;
        uint16_t subTitleShift = subTitle.length()*FONT_CHAR_WIDTH/2;

        #define TITLE_Y_POSITION y+10
        #define SUBTITLE_Y_POSITION y+30
        x+=2;
        
        if(draw){
            setDrawColor_ContrastColor();
            drawString((char*)title, x - titleShift,    TITLE_Y_POSITION, 1);
            drawString(subTitle, x - subTitleShift,     SUBTITLE_Y_POSITION, 1);
        }else{
            setDrawColor_BackGroundColor();
            clearString((char*)title, x - titleShift,   TITLE_Y_POSITION, 1);
            clearString(subTitle, x - subTitleShift,    SUBTITLE_Y_POSITION, 1);
        }
    #else
        // image
        int left_x = x + CORE_VIEWS_SETTINGS_IMAGE_WIDTH;
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        drawImage(draw, icon, x-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2, y-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2);

        // title
        if(draw){
            setDrawColor(255, 255, 255);
            drawString((char*)title, left_x, y-12);
            drawString(subTitle, left_x, y+4);
        }else{    
            clearString((char*)title, left_x, y-12);
            clearString(subTitle, left_x, y+4, 1);
        }
    #endif
    
}

void core_views_draw_settings_item_noicon(bool draw, int x, int y, String title, String subTitle, unsigned char titleFontSize, unsigned char subTitleFontSize){
    
    if(draw){
        setDrawColor_ContrastColor();
        drawString(
            title,                                                                          // TEXT
            x - title.length()*FONT_CHAR_WIDTH/2*titleFontSize,                             // X
            y - COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2,                                         // Y
            titleFontSize                                                                   // FONT SIZE
        );

        drawString(
            subTitle,                                                                       // TEXT
            x - subTitle.length()*FONT_CHAR_WIDTH/2*subTitleFontSize,                       // X
            y + COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2 - subTitleFontSize * FONT_CHAR_HEIGHT,   // Y
            subTitleFontSize                                                                // FONT SIZE
        );
    }else{
        setDrawColor_BackGroundColor();
        clearString(
            title,                                                                          // TEXT
            x - title.length()*FONT_CHAR_WIDTH/2*titleFontSize,                             // X
            y - COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2,                                         // Y
            titleFontSize                                                                   // FONT SIZE
        );

        clearString(
            subTitle,                                                                       // TEXT
            x - subTitle.length()*FONT_CHAR_WIDTH/2*subTitleFontSize,                       // X
            y + COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2 - subTitleFontSize * FONT_CHAR_HEIGHT,   // Y
            subTitleFontSize                                                                // FONT SIZE
        );
    }
    
}

void drawMenuElement(bool draw, uint16_t x, uint16_t y, uint16_t width, uint16_t height, const unsigned char* icon, String string1, String string2){
    if(draw) setDrawColor(255, 255, 255);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    drawRect( x, y, x + width, y + height, false);

    drawString(string1, x + 36 + 10, y + height/3 - FONT_CHAR_HEIGHT/2);
    //drawString_rightAlign(string2, x + width - 15, y + height*2/3 - FONT_CHAR_HEIGHT/2);
    drawString(string2, x + 36 + 10, y + height*2/3 - FONT_CHAR_HEIGHT/2);

    drawImage(draw, icon, x + 10, y + height/2 - 16/2);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON -                                    #
    #                                                                                          #
    ############################################################################################
*/

const unsigned char icon_arrow_top[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x3C,0x00,0x00,0x7E,0x00,0x00,0xFF,0x00,0x01,0xFF,0x80,0x03,0xFF,0xC0,0x07,0xFF,0xE0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0xFF,0xFF,0xFF,
};

const unsigned char icon_arrow_bottom[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0xFF,0xFF,0xFF,0x7F,0xFF,0xFE,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x07,0xFF,0xE0,0x03,0xFF,0xC0,0x01,0xFF,0x80,0x00,0xFF,0x00,0x00,0x7E,0x00,0x00,0x3C,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte* getIcon(int icon){

    switch (icon){
        #ifdef BATTERY_ENABLE
            case ICON_BATTERY_CHARGING:   return battery_charging;
            case ICON_BATTERY_100:        return battery100;  
            case ICON_BATTERY_90:         return battery90;  
            case ICON_BATTERY_80:         return battery80;  
            case ICON_BATTERY_70:         return battery70;  
            case ICON_BATTERY_60:         return battery60;  
            case ICON_BATTERY_50:         return battery50;  
            case ICON_BATTERY_40:         return battery40;  
            case ICON_BATTERY_30:         return battery30;  
            case ICON_BATTERY_20:         return battery20;  
            case ICON_BATTERY_10:         return battery10;  
            case ICON_BATTERY_0:          return battery0;
        #endif
        case ICON_ARROW_UP:             return icon_arrow_top;
        case ICON_ARROW_DOWN:           return icon_arrow_bottom;
        default: return {0};
    }
  
}



#ifdef CPU_CONTROLL_ENABLE
    void core_cpu_setup(){
        driver_cpu_setup();

        #ifdef ACCELEROMETER_ENABLE
        #endif
        //core_cpu_modemSleep();

        //debug("Should be in sleep!");
    }

    void core_cpu_loop(){
        
        //core_cpu_sleep(SLEEP_MODEM);
        /*
        if(millis()/1000>10 && millis()/1000<15)
        driver_cpu_sleep(SLEEP_LIGHT, 10);
        */
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE){
        core_cpu_sleep(SLEEP_TYPE, 0);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s){
        driver_accelerometer_sleep();
        driver_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s);
        driver_accelerometer_wakeup();
    }
#endif

#ifdef TOUCH_SCREEN_ENABLE
    bool TOUCH_SCREEN_last_isTouching   = false;
    bool TOUCH_SCREEN_isDragging        = false;
    bool TOUCH_SCREEN_isLongPressed     = false;

    int TOUCH_SCREEN_last_x = 0;
    int TOUCH_SCREEN_last_y = 0;

    int TOUCH_SCREEN_touch_start_x = 0;
    int TOUCH_SCREEN_touch_start_y = 0;

    int getTOUCH_SCREEN_touch_start_x(){
        return TOUCH_SCREEN_touch_start_x;
    }
    int getTOUCH_SCREEN_touch_start_y(){
        return TOUCH_SCREEN_touch_start_y;
    }

    long TOUCH_SCREEN_touch_start_ms = 0;

    long getTOUCH_SCREEN_touch_start_ms(){
        return TOUCH_SCREEN_touch_start_ms;
    }

    void loop_touchScreenCore(){
        loop_touchScreenDriver();
        
        /*
        #define EVENT_ON_TOUCH_START            0x06
        #define EVENT_ON_TOUCH_RELEASED         0x07
        #define EVENT_ON_TOUCH_CLICK            0x08
        #define EVENT_ON_TOUCH_LONG_PRESS       0x09
        #define EVENT_ON_TOUCH_DRAG             0x0A
        #define EVENT_ON_TOUCH_DOUBLE_CLICK     0x0B
        */

        if(!TOUCH_SCREEN_last_isTouching && getTOUCH_SCREEN_isTouching()){

            TOUCH_SCREEN_last_isTouching = true;
            TOUCH_SCREEN_last_x = getTOUCH_SCREEN_X();
            TOUCH_SCREEN_last_y = getTOUCH_SCREEN_Y();
            TOUCH_SCREEN_touch_start_x = TOUCH_SCREEN_last_x;
            TOUCH_SCREEN_touch_start_y = TOUCH_SCREEN_last_y;
            TOUCH_SCREEN_isDragging = false;
            TOUCH_SCREEN_isLongPressed = false;
            TOUCH_SCREEN_touch_start_ms = millis();
            currentApp->onEvent(EVENT_ON_TOUCH_START, TOUCH_SCREEN_last_x, TOUCH_SCREEN_last_y);

        }else if(TOUCH_SCREEN_last_isTouching && !getTOUCH_SCREEN_isTouching()){

            TOUCH_SCREEN_last_isTouching = false;
            currentApp->onEvent(EVENT_ON_TOUCH_RELEASED, getTOUCH_SCREEN_X(), getTOUCH_SCREEN_Y());

            if(!TOUCH_SCREEN_isDragging && millis()-TOUCH_SCREEN_touch_start_ms<TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH){
                currentApp->onEvent(EVENT_ON_TOUCH_CLICK, getTOUCH_SCREEN_X(), getTOUCH_SCREEN_Y());
            }else{
                TOUCH_SCREEN_isDragging = false;
                TOUCH_SCREEN_isLongPressed = false;
            }
            

        }else if(TOUCH_SCREEN_last_isTouching && getTOUCH_SCREEN_isTouching()){

            int dx;
            int dy;

            if(!TOUCH_SCREEN_isDragging){
                dx = getTOUCH_SCREEN_X() - TOUCH_SCREEN_touch_start_x;
                dy = getTOUCH_SCREEN_Y() - TOUCH_SCREEN_touch_start_y;
            }else{
                dx = getTOUCH_SCREEN_X() - TOUCH_SCREEN_last_x;
                dy = getTOUCH_SCREEN_Y() - TOUCH_SCREEN_last_y;
            }

            //TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG
            if( (TOUCH_SCREEN_isDragging && (abs(dx)>0 || abs(dy)>0) ) || abs(dx)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG || abs(dy)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG){
                TOUCH_SCREEN_isDragging = true;
                TOUCH_SCREEN_last_x = getTOUCH_SCREEN_X();
                TOUCH_SCREEN_last_y = getTOUCH_SCREEN_Y();

                currentApp->onEvent(EVENT_ON_TOUCH_DRAG, dx, dy);
            }else if(!TOUCH_SCREEN_isLongPressed && millis()-TOUCH_SCREEN_touch_start_ms>TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH){
                TOUCH_SCREEN_isLongPressed = true;
                currentApp->onEvent(EVENT_ON_TOUCH_LONG_PRESS, getTOUCH_SCREEN_X(), getTOUCH_SCREEN_Y());
            }
            
        } 
    }

#endif


#define appNameClass    AlarmApp          // App name without spaces
#define appName         "Alarm"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */

    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }

    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x37,0xFC,
    0x00,0x00,0x6F,0xFE,0x00,0x00,0xDF,0xFF,0x00,0x00,0xDF,0xFF,0x00,0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,
    0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,
    0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,0x9F,0xFF,0x80,0x01,0xDF,0xFF,0x80,0x00,0x7F,0xFE,0x00,0x00,0x0F,
    0xF0,0x00,0x03,0x80,0x01,0xC0,0x03,0xF0,0x0F,0xC0,0x07,0x3F,0xFF,0xE0,0x0C,0x7F,0xFF,0xF0,0x18,0xFF,0xFF,
    0xF8,0x71,0xFF,0xFF,0xFE,0x79,0xFF,0xFF,0xFE,0x1F,0xFF,0xFF,0xF8,0x03,0xFF,0xFF,0xC0,0x00,0x7F,0xFE,0x00,
    0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x60,
    0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,
    0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x20,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x03,
    0x80,0x00,0x00,0x07,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xd8,0xd8,
    0xd8,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x60,0x00,0x00,0x03,0xC0,0x00,0x00,
    0x01,0x80,0x00,0x04,0x8f,0x8f,0x8f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x01,0x80,0x01,0xF0,0x0F,0x80,0x00,
    0x7F,0xFE,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define appNameClass    CompassApp          // App name without spaces
#define appName         "Compass"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x70,0x00,0x00,0x0F,0xF0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,
    0x03,0xC0,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,
    0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0E,0x70,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xb4,0xb4,0xb4,0x00,0x0F,0xF0,0x00,0x00,0x7F,0xFE,0x00,
    0x01,0xF0,0x0F,0x80,0x03,0xC0,0x03,0xC0,0x07,0x00,0x00,0xE0,0x0E,0x00,0x00,0x70,0x1C,0x00,0x00,0x38,0x38,0x00,0x00,
    0x1C,0x30,0x00,0x00,0x0C,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0xC0,0x00,0x00,0x03,0xC0,0x00,
    0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,
    0x00,0x00,0x03,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0x70,0x00,0x00,0x0E,0x30,0x00,0x00,0x0C,0x38,0x00,0x00,0x1C,
    0x1C,0x00,0x00,0x38,0x0E,0x00,0x00,0x70,0x07,0x00,0x00,0xE0,0x03,0xC0,0x03,0xC0,0x01,0xF0,0x0F,0x80,0x00,0x7F,0xFE,
    0x00,0x00,0x0F,0xF0,0x00,0x04,0x6b,0x6b,0x6b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x70,0x00,0x00,0x3E,
    0x7C,0x00,0x00,0xFE,0x7F,0x00,0x01,0xFC,0x3F,0x80,0x03,0xFC,0x3F,0xC0,0x07,0xFC,0x3F,0xE0,0x0F,0xFC,0x3F,0xF0,0x1F,
    0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x3F,0xF8,0x1F,0xFC,0x3F,0xF8,0x1F,0xFC,0x3F,0xF0,0x0F,0xFC,
    0x3F,0xF0,0x0F,0xFC,0x3F,0xF0,0x0F,0xFC,0x3F,0xF0,0x0F,0xFC,0x3F,0xF8,0x1F,0xFC,0x3F,0xF8,0x1F,0xFC,0x1F,0xF8,0x1F,
    0xF8,0x1F,0xF8,0x1F,0xF8,0x0F,0xF8,0x1F,0xF0,0x0F,0xFC,0x3F,0xF0,0x07,0xFC,0x3F,0xE0,0x03,0xFC,0x3F,0xC0,0x01,0xFC,
    0x3F,0x80,0x00,0xFE,0x7F,0x00,0x00,0x3E,0x7C,0x00,0x00,0x0E,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};


#define appNameClass                        BatteryApp              // App name without spaces
#define appName                             "Battery"              // App name with spaces 

#ifndef APP_BATTERY_UPDATE_EVERY_MS
    #define APP_BATTERY_UPDATE_EVERY_MS         500
#endif

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        void drawInfo();
        long lastUpdate = 0;

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
        
        unsigned char currentPrintScreenString = 0;
        void drawStringOnScreen(String stringToPrint);
};

void appNameClass::drawStringOnScreen(String stringToPrint){
    drawString(stringToPrint, 5, STYLE_STATUSBAR_HEIGHT + currentPrintScreenString*10*FONT_SIZE_DEFAULT + 10, FONT_SIZE_DEFAULT);
    currentPrintScreenString ++;
}

/*
float driver_battery_getVoltage()
int driver_battery_getVoltage_mV()
float driver_battery_getCurent_mA()
float driver_battery_getUsbVoltage()
float driver_battery_getUsbCurent_mA()
float driver_battery_controller_Temp()
float driver_battery_Temp()
unsigned char driver_battery_getPercent()
*/

void appNameClass::onCreate(){
    setBackgroundColor(0, 0, 0); 

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    this->drawInfo();
}

void appNameClass::drawInfo(){
    this->lastUpdate = millis();
    this->currentPrintScreenString = 0;

    setDrawColor(255, 255, 255);
    #ifdef BATTERY_ENABLE
        //#ifdef NARROW_SCREEN
            
            drawStringOnScreen("Bat voltage:");
            drawStringOnScreen(String(driver_battery_getVoltage()) + " V");
            
            drawStringOnScreen("Bat voltage:");
            drawStringOnScreen(String(driver_battery_getVoltage_mV()) + " mV");
            
            drawStringOnScreen("Bat current:");
            drawStringOnScreen(String(driver_battery_getCurent_mA()) + " mA");
                        
            drawStringOnScreen("Usb voltage:");
            drawStringOnScreen(String(driver_battery_getUsbVoltage()) + " mV");

            drawStringOnScreen("Usb current:");
            drawStringOnScreen(String(driver_battery_getUsbCurent_mA()) + " mA");
            
            /*
            drawStringOnScreen("Vin voltage:");
            drawStringOnScreen(String(driver_battery_getVinVoltage()) + " mV");

            drawStringOnScreen("Vin current:");
            drawStringOnScreen(String(driver_battery_getVinCurent_mA()) + " mA");

            drawStringOnScreen("Battery temp:");
            drawStringOnScreen(String(driver_battery_Temp()) + " C");
            
            drawStringOnScreen("Controller temp:");
            drawStringOnScreen(String(driver_battery_controller_Temp()) + " C");
            */

            drawStringOnScreen("Battery:");
            drawStringOnScreen(String(core_battery_getPercent()) + " %");
    
        //#else
            
        //#endif
        
    #else
        drawStringOnScreen("Battery not supported");
    #endif
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
    #ifdef BATTERY_ENABLE
        if(millis()-this->lastUpdate>APP_BATTERY_UPDATE_EVERY_MS){
            //fillScreen(0, 0, 0);
            setDrawColor_BackGroundColor();
            drawRect(0, STYLE_STATUSBAR_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, true);
            this->drawInfo();
        }
    #endif
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
        if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
            if(val1==BUTTON_SELECT){
                startApp(-1);
            }
        }
    #else
        if(event==EVENT_BUTTON_PRESSED){
            // Write you code on [val1] button pressed here
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        }else if(event==EVENT_BUTTON_RELEASED){
            // Write you code on [val1] button released here
        }else if(event==EVENT_BUTTON_LONG_PRESS){
            // Write you code on [val1] button long press here
        }else if(event==EVENT_ON_TIME_CHANGED){
            // Write you code on system time changed
        }
    #endif
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,
    0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,
    0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,
    0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,
    0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,
    0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x07,0xE0,0x00,0x00,0x08,0x10,0x00,
    0x00,0x08,0x10,0x00,0x0F,0xF8,0x1F,0xF0,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,
    0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,
    0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,
    0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,
    0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x0F,0xFF,0xFF,0xF0,
};

/* 
* /
#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define MAIN_MENU_SMOOTH_ANIMATION
#define NARROW_SCREEN
// */

#define appNameClass    SettingsApp     // App name without spaces
#define appName         "Settings"      // App name with spaces 

#define CORE_VIEWS_SETTINGS_IMAGE_WIDTH 24
#define SETTINGS_ELEMENTS

#define PAGES_LIST_HEIGHT               20
#define ACTIVE_SCREEN_WIDTH             SCREEN_WIDTH
#define ACTIVE_SCREEN_HEIGHT            (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT - PAGES_LIST_HEIGHT)
#define SINGLE_ELEMENT_MIN_WIDTH        200
#define SINGLE_ELEMENT_MIN_HEIGHT       60

#define SINGLE_ELEMENTS_IN_X            ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y            ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#define SINGLE_ELEMENTS_IN_X_MACRO      ((ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y_MACRO      ((ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#if ((ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH)) < 1
  #define SINGLE_ELEMENTS_IN_X 1
  #define SINGLE_ELEMENTS_IN_X_MACRO 1
#endif

#if ((ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT)) < 1
  #define SINGLE_ELEMENTS_IN_Y 1
  #define SINGLE_ELEMENTS_IN_Y_MACRO 1
#endif

#if ( ((SINGLE_ELEMENTS_IN_X_MACRO)==1) && ((SINGLE_ELEMENTS_IN_Y_MACRO)==1))
  #define SINGLE_ELEMENT_ON_SCREEN
#endif

#ifdef NARROW_SCREEN
  #define SINGLE_ELEMENTS_IN_X 1
  #define SINGLE_ELEMENTS_IN_X_MACRO 1
  #define SINGLE_ELEMENTS_IN_Y 1
  #define SINGLE_ELEMENTS_IN_Y_MACRO 1
  #define SINGLE_ELEMENT_ON_SCREEN
#endif

#define SINGLE_ELEMENT_REAL_WIDTH       ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENTS_IN_X))
#define SINGLE_ELEMENT_REAL_HEIGHT      ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENTS_IN_Y))

#define PAGES_LIST_POSITION             (SCREEN_HEIGHT-PAGES_LIST_HEIGHT/2)
#define APPS_ON_SINGLE_PAGE             (SINGLE_ELEMENTS_IN_X * SINGLE_ELEMENTS_IN_Y)


// SUBMENUES
#define APP_SETTINGS_SUBMENU_MAIN           0x00
#define APP_SETTINGS_SUBMENU_SET_TIME       0x01
#define APP_SETTINGS_SUBMENU_SET_DATE       0x02
#define APP_SETTINGS_SUBMENU_SCREEN         0x03
//#define APP_SETTINGS_SUBMENU_POWERSAVE      0x04

// SETTINGS PAGES
#define APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN       3
#define APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SET_TIME   3
#define APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SET_DATE   4
#define APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SCREEN     4


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
          switch(type){ 
            case PARAM_TYPE_NAME: return (unsigned char*)appName; 
            case PARAM_TYPE_ICON: return icon;
            default: return (unsigned char*)""; 
          }
        };
        const static unsigned char icon[] PROGMEM;
      
    private:
        const unsigned char* getApplicationTitle(unsigned char submenu, unsigned char num);
        const unsigned char* getApplicationIcon(unsigned char submenu, unsigned char num);
        void drawIcons(bool draw);
        void updateActiveAppIndex(int newSelectedAppIndex);
        void drawActiveAppFrame(bool draw);
        unsigned char getTotalPagesInSubMenu(unsigned char submenuType);
        unsigned char getTotalApplicationsInSubMenu(unsigned char subMenu);
        char app_settings_selectedAppIndex = 0;
        const static unsigned char def[]                PROGMEM;
        const static unsigned char icon_battery[]       PROGMEM;
        const static unsigned char icon_light[]         PROGMEM;
        const static unsigned char icon_time[]          PROGMEM;
        const static unsigned char icon_date[]          PROGMEM;
        const static unsigned char icon_sleep[]         PROGMEM;
        unsigned char currentSubMenu       = APP_SETTINGS_SUBMENU_MAIN;
        String getApplicationSubTitle(unsigned char submenu, unsigned char num);
        String getApplicationSubTitle(unsigned char submenu, unsigned char num, boolean getLast);
        void drawSettingsPageFirstTime();
        void clearWorkSpace();
        void switchToSubMenu(unsigned char newSubMenu);
        void drawSettingTimeArrows(bool draw, int position);
        void drawSettingTimeSelect(bool draw, int position);
        void drawSettingTimeDigits(bool draw);
        void drawSettingTimeDateDigits(bool draw, unsigned char position, int value);
        unsigned char lastSeconds   = 0;
        unsigned char lastMinutes   = 0;
        unsigned char lastHours     = 0;
        void pressPrevious();
        void pressNext();
        void pressSelect();

        String lastTimeString           = "";
        String lastDateString           = "";
        String lastBatteryString        = "";

        String lastTimeString_hours     = "";
        String lastTimeString_minutes   = "";
        String lastTimeString_seconds   = "";
        String lastDateString_year      = "";
        String lastDateString_month     = "";
        String lastDateString_date      = "";
        String lastDateString_weekDay   = "";

        #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
            unsigned long stillPressingSelect_time = 0;
        #endif

        char currentSelectedPosition        = 0;
        bool currentPositionIsSelected      = false;
        
        int getPositionBySelectedNumber(unsigned char selectedNumber);
};

unsigned char appNameClass::getTotalPagesInSubMenu(unsigned char submenuType){
    return (getTotalApplicationsInSubMenu(submenuType)%APPS_ON_SINGLE_PAGE==0?((int)(getTotalApplicationsInSubMenu(submenuType)/APPS_ON_SINGLE_PAGE)):((int)(getTotalApplicationsInSubMenu(submenuType)/APPS_ON_SINGLE_PAGE) + 1));
}

unsigned char appNameClass::getTotalApplicationsInSubMenu(unsigned char submenuType){
    switch (submenuType){
        case APP_SETTINGS_SUBMENU_MAIN:
            return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN;
        case APP_SETTINGS_SUBMENU_SET_TIME:
            return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SET_TIME;
        case APP_SETTINGS_SUBMENU_SET_DATE:
            return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SET_DATE;
        case APP_SETTINGS_SUBMENU_SCREEN:
            return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_SCREEN;
        default:
            return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN;
    }
}

void appNameClass::clearWorkSpace(){
    setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
    drawRect(0, STYLE_STATUSBAR_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, true);
}

#define OFFSET_POSITION_ELEMENTS 60
#define TIME_SET_POSITION_1 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*1 + OFFSET_POSITION_ELEMENTS/2
#define TIME_SET_POSITION_2 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*3 + OFFSET_POSITION_ELEMENTS/2
#define TIME_SET_POSITION_3 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*5 + OFFSET_POSITION_ELEMENTS/2

void appNameClass::drawSettingsPageFirstTime(){
    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
        #ifndef SINGLE_ELEMENT_ON_SCREEN
            core_views_draw_pages_list_simple(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN));
        #endif
        core_views_draw_active_page(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN), 0);
        this->updateActiveAppIndex(app_settings_selectedAppIndex);  
        // Drawing icons
        this->drawIcons(true);
        #ifndef TOUCH_SCREEN_ENABLE
        #ifndef SINGLE_ELEMENT_ON_SCREEN
            this->drawActiveAppFrame(true);  
        #endif
        #endif
    }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){

        #ifdef NARROW_SCREEN
            this->drawIcons(true);
        #else
            int y_position = (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT)/2;

            drawSettingTimeDigits(true);
            drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));
        #endif

    }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE){

        #ifdef NARROW_SCREEN
            this->drawIcons(true);
        #else
            /*
            TODO
            */
        #endif

    }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN){

        #ifdef NARROW_SCREEN
            this->drawIcons(true);
        #else
            /*
            TODO
            */
        #endif

    }      
}

int appNameClass::getPositionBySelectedNumber(unsigned char selectedNumber){
    switch(selectedNumber){
        case 0: return TIME_SET_POSITION_1;
        case 1: return TIME_SET_POSITION_2;
        case 2: return TIME_SET_POSITION_3;
        default: return TIME_SET_POSITION_1;
    }
}

void appNameClass::drawSettingTimeArrows(bool draw, int position){
    //drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  

    //drawImage(draw, icon_arrow_top, position + 3 - 16, SCREEN_HEIGHT/2 - 19 - 15 );
    //drawImage(draw, icon_arrow_bottom, position + 3 - 16, SCREEN_HEIGHT/2 + 20 + 15);

    drawImage(draw, getIcon(ICON_ARROW_UP), position + 3 - 16, SCREEN_HEIGHT/2 - 19 - 15 );
    drawImage(draw, getIcon(ICON_ARROW_DOWN), position + 3 - 16, SCREEN_HEIGHT/2 + 20 + 15);
}

void appNameClass::drawSettingTimeSelect(bool draw, int position){
    //drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  
    if(draw) setDrawColor(255, 255, 255);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
    drawRect(position - FONT_CHAR_WIDTH*3, SCREEN_HEIGHT/2 + 25, position + FONT_CHAR_WIDTH*3-3, SCREEN_HEIGHT/2 + 28, true);
}

void appNameClass::drawSettingTimeDigits(bool draw){
    if(draw) setDrawColor(255, 255, 255);

    lastSeconds   = core_time_getSeconds_byte();
    lastMinutes   = core_time_getMinutes_byte();
    lastHours     = core_time_getHours_byte();

    drawSettingTimeDateDigits(true, TIME_SET_POSITION_1, lastHours);
    drawSettingTimeDateDigits(true, TIME_SET_POSITION_2, lastMinutes);
    drawSettingTimeDateDigits(true, TIME_SET_POSITION_3, lastSeconds);
}

void appNameClass::drawSettingTimeDateDigits(bool draw, unsigned char position, int value){
    if(draw){
        setDrawColor(255, 255, 255);
        drawString_centered(core_basic_addLeadBullToInt2digits(value), position, SCREEN_HEIGHT/2, 3);   
    }else{
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        clearString_centered(core_basic_addLeadBullToInt2digits(value), position, SCREEN_HEIGHT/2, 3); 
    
    }
}

void appNameClass::switchToSubMenu(unsigned char newSubMenu){
    app_settings_selectedAppIndex = 0;
    currentSubMenu = newSubMenu;
    clearWorkSpace();
    drawSettingsPageFirstTime(); 
}

void appNameClass::onCreate(){
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);
    #ifndef TOUCH_SCREEN_ENABLE
        DRAW_LIMITS_setEnable(true);
        DRAW_LIMIT_reset();
        DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    #endif

    this->drawSettingsPageFirstTime();
    this->currentSubMenu = APP_SETTINGS_SUBMENU_MAIN;
}



void appNameClass::updateActiveAppIndex(int newSelectedAppIndex){

  if(newSelectedAppIndex<0) newSelectedAppIndex = getTotalApplicationsInSubMenu(currentSubMenu) - 1;
  if(newSelectedAppIndex>=getTotalApplicationsInSubMenu(currentSubMenu)) newSelectedAppIndex = 0;

  if(app_settings_selectedAppIndex!=newSelectedAppIndex){
    
    #ifndef TOUCH_SCREEN_ENABLE
    #ifndef SINGLE_ELEMENT_ON_SCREEN
        this->drawActiveAppFrame(false);
    #endif
    #endif
    
    //debug("Current submenu: " + String(currentSubMenu));

    if( (int)((app_settings_selectedAppIndex)/APPS_ON_SINGLE_PAGE) != (int)((newSelectedAppIndex)/APPS_ON_SINGLE_PAGE)){
      // update page
      this->drawIcons(false);
      if(
          currentSubMenu!=APP_SETTINGS_SUBMENU_SET_TIME 
          && currentSubMenu!=APP_SETTINGS_SUBMENU_SET_DATE
          && currentSubMenu!=APP_SETTINGS_SUBMENU_SCREEN
          ){
        core_views_draw_active_page(false, PAGES_LIST_POSITION, getTotalPagesInSubMenu(currentSubMenu), (int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE));
      }
      
      app_settings_selectedAppIndex = newSelectedAppIndex;

      if(
          currentSubMenu!=APP_SETTINGS_SUBMENU_SET_TIME 
          && currentSubMenu!=APP_SETTINGS_SUBMENU_SET_DATE
          && currentSubMenu!=APP_SETTINGS_SUBMENU_SCREEN
          ){
        core_views_draw_active_page(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(currentSubMenu), (int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE));
      }
      this->drawIcons(true);
    }else{
      app_settings_selectedAppIndex = newSelectedAppIndex;
    }

    // update selected app frame
    #ifndef TOUCH_SCREEN_ENABLE
    #ifndef SINGLE_ELEMENT_ON_SCREEN
        this->drawActiveAppFrame(true);
    #endif
    #endif
    
  }
}

void appNameClass::drawActiveAppFrame(bool draw){
  unsigned char positionOnScreen     = app_settings_selectedAppIndex%APPS_ON_SINGLE_PAGE;
  unsigned char positionOnScreen_x   = app_settings_selectedAppIndex%SINGLE_ELEMENTS_IN_X;
  unsigned char positionOnScreen_y   = positionOnScreen/SINGLE_ELEMENTS_IN_X;

  int x0 = positionOnScreen_x*SINGLE_ELEMENT_REAL_WIDTH;
  int y0 = positionOnScreen_y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
  int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
  int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

  if(draw) setDrawColor(196, 196, 196);
  else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

  for(unsigned char i=0; i<4; i++){
    unsigned char delta = 5+i;
    drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  
  }
  
}

void appNameClass::drawIcons(bool draw){
    #ifdef NARROW_SCREEN
        int app_num = app_settings_selectedAppIndex;
        
        #ifdef MAIN_MENU_SMOOTH_ANIMATION
            if(this->scroll_x!=0){
                this->preventInAppSleep=true;
                if(this->scroll_x<0){
                }else if(this->scroll_x>0){
                    char elementsToPreDraw = this->scroll_x/SCREEN_WIDTH + 1;
                    elementsToPreDraw = elementsToPreDraw%getTotalPagesInSubMenu(currentSubMenu);
                    for(unsigned char elementDraw = 0; elementDraw<=elementsToPreDraw; elementDraw++){
                        int appElementDraw = app_num - elementDraw;
                        while(appElementDraw<0) appElementDraw+=getTotalPagesInSubMenu(currentSubMenu);
                        appElementDraw = appElementDraw%getTotalPagesInSubMenu(currentSubMenu);

                        if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                            core_views_draw_settings_item(
                                draw, 
                                this->scroll_x + SCREEN_WIDTH/2 - elementDraw*SCREEN_WIDTH,
                                SCREEN_HEIGHT/2, 
                                (const unsigned char*)this->getApplicationTitle(APP_SETTINGS_SUBMENU_MAIN, appElementDraw), 
                                this->getApplicationSubTitle(currentSubMenu, appElementDraw, !draw), 
                                this->getApplicationIcon(currentSubMenu, appElementDraw)
                            );
                        }else if(
                                    currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME 
                                    || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE 
                                    || currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
                                ){

                            String stringTitle = reinterpret_cast<const char*>(this->getApplicationTitle(currentSubMenu, appElementDraw));

                            core_views_draw_settings_item_noicon(
                                draw, 
                                this->scroll_x + SCREEN_WIDTH/2 - elementDraw*SCREEN_WIDTH, 
                                SCREEN_HEIGHT/2, 
                                stringTitle, 
                                this->getApplicationSubTitle(currentSubMenu, appElementDraw, !draw), 
                                1, 
                                2
                            );
                        }
                        
                    }
                }
            }else{
                if(draw) this->preventInAppSleep=false;
                if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                    core_views_draw_settings_item(
                        draw, 
                        this->scroll_x + SCREEN_WIDTH/2,
                        SCREEN_HEIGHT/2, 
                        (const unsigned char*)this->getApplicationTitle(APP_SETTINGS_SUBMENU_MAIN, app_num), 
                        this->getApplicationSubTitle(currentSubMenu, app_num, !draw), 
                        this->getApplicationIcon(currentSubMenu, app_num)
                    );
                }else if(
                            currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME 
                            || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE
                            || currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
                        ){
                    String stringTitle = reinterpret_cast<const char*>(this->getApplicationTitle(currentSubMenu, app_num));
                    core_views_draw_settings_item_noicon(
                        draw, 
                        this->scroll_x + SCREEN_WIDTH/2, 
                        SCREEN_HEIGHT/2, 
                        stringTitle, 
                        this->getApplicationSubTitle(currentSubMenu, app_num, !draw), 
                        1, 
                        2
                    );
                }
            }
        #else
            if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                core_views_draw_settings_item(
                    draw, 
                    SCREEN_WIDTH/2,
                    SCREEN_HEIGHT/2, 
                    (const unsigned char*)this->getApplicationTitle(APP_SETTINGS_SUBMENU_MAIN, app_num), 
                    this->getApplicationSubTitle(currentSubMenu, app_num, !draw), 
                    this->getApplicationIcon(currentSubMenu, app_num)
                );
            }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
                // TODO
            }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE){
                // TODO
            }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN){
                // TODO
            }
        #endif


    #else
        #ifndef TOUCH_SCREEN_ENABLE
            for(unsigned char currentDrawPage=0; currentDrawPage<getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN); currentDrawPage++){
        #endif
            
            for (unsigned char y_position=0; y_position<SINGLE_ELEMENTS_IN_Y; y_position++){
                for (unsigned char x_position=0; x_position<SINGLE_ELEMENTS_IN_X; x_position++){
                    int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
                    int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
                    int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
                    int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

                    int x_center = (x0+x1)/2;
                    int y_center = (y0+y1)/2;

                    #ifndef TOUCH_SCREEN_ENABLE
                        int app_num = y_position*(SINGLE_ELEMENTS_IN_X) + x_position + currentDrawPage*APPS_ON_SINGLE_PAGE;
                    #else
                        int app_num = y_position*(SINGLE_ELEMENTS_IN_X) + x_position + APPS_ON_SINGLE_PAGE*(int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE);
                    #endif
                    
                    if(app_num<getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN)){
                        #ifdef ESP8266
                            ESP.wdtDisable();
                        #endif

                        
                        core_views_draw_settings_item(
                            draw, 
                            #ifndef TOUCH_SCREEN_ENABLE
                                currentDrawPage*SCREEN_WIDTH - this->scroll_x + x0+35, 
                            #else
                                -this->scroll_x + x0+35, 
                            #endif
                            y_center, 
                            (const unsigned char*)this->getApplicationTitle(APP_SETTINGS_SUBMENU_MAIN, app_num), 
                            this->getApplicationSubTitle(0, app_num), 
                            this->getApplicationIcon(0, app_num)
                        );
                    }
                }
            }

        #ifndef TOUCH_SCREEN_ENABLE
        }
        #endif
    #endif
}

void appNameClass::onLoop(){
    #ifdef MAIN_MENU_SMOOTH_ANIMATION
        if(this->scroll_x!=0){
            this->drawIcons(false);
            if(this->scroll_x!=0){
                //this->scroll_x++;
                int dx = abs(scroll_x)/SMOOTH_ANIMATION_COEFFICIENT + 1;
                if(scroll_x>scroll_to_x) dx *= -1;
                scroll_x+=dx;

                if (abs(dx)<1) scroll_x=0;
            }
            this->drawIcons(true);
        }
    #endif
    if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
        if(stillPressingSelect_time!=0 && millis()-this->stillPressingSelect_time>=DRIVER_CONTROLS_DELAY_BEFORE_MULTY_PRESS){
            stillPressingSelect_time = millis();
            switch(app_settings_selectedAppIndex){
                case 0:
                    // Add hours
                    core_time_setHours(core_time_getHours_byte() + 1);
                    break;
                case 1:
                    // Add minutes
                    core_time_setMinutes(core_time_getMinutes_byte() + 1);
                    break;
                case 2:
                    // Reset seconds
                    core_time_setSeconds(0);
                    break;
            } 
            this->drawIcons(false);
            this->drawIcons(true);
        }
    }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE){
        if(stillPressingSelect_time!=0 && millis()-this->stillPressingSelect_time>=DRIVER_CONTROLS_DELAY_BEFORE_MULTY_PRESS){
            stillPressingSelect_time = millis();
            switch(app_settings_selectedAppIndex){
                case 0:
                    // Add year
                    core_time_setYear(core_time_getYear() + 1);
                    break;
                case 1:
                    // Add month
                    core_time_setMonth(core_time_getMonth() + 1);
                    break;
                case 2:
                    // Add date
                    core_time_setDate(core_time_getDate() + 1);
                    break;
                case 3:
                    // Set week day
                    core_time_setWeekDay(core_time_getWeekDay() + 1);
                    break;
            } 
            this->drawIcons(false);
            this->drawIcons(true);
        }
    }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN){
        if(stillPressingSelect_time!=0 && millis()-this->stillPressingSelect_time>=DRIVER_CONTROLS_DELAY_BEFORE_MULTY_PRESS){
            stillPressingSelect_time = millis();
            int value = 0;

            this->drawIcons(false);
            switch(app_settings_selectedAppIndex){
                case 0:
                    #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE
                        // Change display brightness
                        value = get_core_display_brightness();
                        if(value>=100) value = 0;
                        else value+=5;
                        if(value==0) value = 1;
                        if(value==6) value = 5;
                        set_core_display_brightness(value);
                    #endif
                    break;
                case 1:
                    #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
                        // Change display fade brightness
                        value = get_core_display_brightness_fade();
                        if(value>=100) value = 0;
                        else value+=5;
                        if(value==0) value = 1;
                        if(value==6) value = 5;
                        set_core_display_brightness_fade(value);
                    #endif
                    break;
                case 2:
                    #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
                        // Change time delay to fade
                        value = get_core_display_time_delay_to_fade();
                        if(value>=240) value = 0;
                        else{
                            if(value<4)         value+=1;
                            else if(value<10)   value+=2;
                            else if(value<30)   value+=5;
                            else if(value<100)  value+=10;
                            else value+=20;
                        }
                        set_core_display_time_delay_to_fade(value);
                        break;
                    #endif
                case 3:
                    // Change time delay to poweroff
                    value = get_core_display_time_delay_to_poweroff();
                    if(value>=240) value = 1;
                    else{
                        if(value<4)         value+=1;
                        else if(value<10)   value+=2;
                        else if(value<30)   value+=5;
                        else if(value<100)  value+=10;
                        else value+=20;
                    }
                    set_core_display_time_delay_to_poweroff(value);
                    break;
            } 
            this->drawIcons(true);
        }
    }

    
}

void appNameClass::onDestroy(){
}

void appNameClass::pressPrevious(){
    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
        this->updateActiveAppIndex(app_settings_selectedAppIndex-1);
        #ifdef MAIN_MENU_SMOOTH_ANIMATION
          this->scroll_x -= SCREEN_WIDTH;
        #endif
    } 
}

void appNameClass::pressNext(){
    //if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
    this->drawIcons(false);
    #ifdef MAIN_MENU_SMOOTH_ANIMATION
        this->scroll_x += SCREEN_WIDTH;
    #endif
    
    if(
            currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME || 
            currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE || 
            currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
      ){
        if(app_settings_selectedAppIndex>=this->getTotalApplicationsInSubMenu(currentSubMenu)-1){
            this->scroll_x = 0;
            switchToSubMenu(APP_SETTINGS_SUBMENU_MAIN);
            return;
        }
    }

    this->updateActiveAppIndex(this->app_settings_selectedAppIndex+1);
}

void appNameClass::pressSelect(){

}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    #ifdef TOUCH_SCREEN_ENABLE

        if(event==EVENT_ON_TOUCH_DRAG){
            // SCREEN SCROLL
            this->drawIcons(false);
            this->scroll_x -= val1;
            if(this->scroll_x<0) scroll_x = 0;

            int max_scroll = (this->getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN) - 1 ) * SCREEN_WIDTH;
            if(this->scroll_x>max_scroll) {
                this->scroll_x = max_scroll;
            }

            this->drawIcons(true);
        }

    #else

        /**/
        #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
            
            if(event==EVENT_BUTTON_PRESSED){
                if(
                    currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME 
                    || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE
                    || currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
                  ){
                    if(this->stillPressingSelect_time==0) this->stillPressingSelect_time = millis();
                }  
            }else if(event==EVENT_BUTTON_RELEASED){
                if(
                    currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME 
                    || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE
                    || currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
                    ){
                    this->stillPressingSelect_time = 0;
                }
            }else if(event==EVENT_BUTTON_LONG_PRESS){
                //debug("EVENT_BUTTON_LONG_PRESS");
                if(val1==BUTTON_SELECT){
                    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                        switch(app_settings_selectedAppIndex){
                            case 0:
                                switchToSubMenu(APP_SETTINGS_SUBMENU_SET_TIME);
                                break;
                            case 1:
                                switchToSubMenu(APP_SETTINGS_SUBMENU_SET_DATE);
                                break;
                            case 2:
                                switchToSubMenu(APP_SETTINGS_SUBMENU_SCREEN);
                                break;
                        }
                    }
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }    
            }else if(event==EVENT_BUTTON_SHORT_PRESS){
                //debug("EVENT_BUTTON_SHORT_PRESS");
            }else if(event==EVENT_BUTTON_SHORT_SINGLE_PRESS){
                //debug("EVENT_BUTTON_SHORT_SINGLE_PRESS");
                if(val1==BUTTON_SELECT){
                    this->pressNext();
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }
            }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
                //debug("EVENT_ON_TOUCH_DOUBLE_PRESS");
                if(val1==BUTTON_SELECT){
                    if(
                        currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME 
                        || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE
                        || currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN
                      ){
                        this->pressNext();
                    } else startApp(-1);
                }
            }
            
        #else
            if(event==EVENT_BUTTON_PRESSED){
                
                if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                    switch(val1){
                        case BUTTON_UP:
                            this->pressPrevious();
                            break;
                        case BUTTON_BACK:
                            startApp(-1);
                            break;
                        case BUTTON_DOWN:
                            this->pressNext();   
                            break;
                        case BUTTON_SELECT:
                            if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                                switch (app_settings_selectedAppIndex){
                                case 0:
                                    switchToSubMenu(APP_SETTINGS_SUBMENU_SET_TIME);    
                                    break;
                                case 1:
                                    switchToSubMenu(APP_SETTINGS_SUBMENU_SET_DATE);    
                                    break;
                                case 2:
                                    switchToSubMenu(APP_SETTINGS_SUBMENU_SCREEN);    
                                    break;
                                }
                            }
                            break;
                    }
                }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
                    
                    switch(val1){
                        case BUTTON_UP:
                        case BUTTON_DOWN:
                            if(currentPositionIsSelected==false){
                                drawSettingTimeSelect(false, getPositionBySelectedNumber(currentSelectedPosition));
                                if(val1==BUTTON_DOWN)currentSelectedPosition++; else currentSelectedPosition--;
                                if(currentSelectedPosition>=3)currentSelectedPosition=0;
                                if(currentSelectedPosition<0)currentSelectedPosition=2;
                                drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }else{
                                
                                // time changing
                            }
                            break;
                        case BUTTON_BACK:
                            switchToSubMenu(APP_SETTINGS_SUBMENU_MAIN);            
                            break;
                        
                        case BUTTON_SELECT:
                            currentPositionIsSelected = !currentPositionIsSelected;
                            if(currentPositionIsSelected){
                                drawSettingTimeSelect(false, getPositionBySelectedNumber(currentSelectedPosition));
                                drawSettingTimeArrows(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }else{
                                drawSettingTimeArrows(false, getPositionBySelectedNumber(currentSelectedPosition));
                                drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }
                            break;
                    }

                }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE){
                    // TODO
                }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SCREEN){
                    // TODO
                }
            
            }else if(event==EVENT_BUTTON_RELEASED){

            }else if(event==EVENT_BUTTON_LONG_PRESS){

            }
        #endif
    
    #endif

    else if(event==EVENT_ON_TIME_CHANGED){

        #ifdef SINGLE_ELEMENT_ON_SCREEN
            /*
            String lastTimeString;
            String lastDateString;
            String lastBatteryString;
            */
    
            if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN && app_settings_selectedAppIndex==0 && app_settings_selectedAppIndex==0){
                this->drawIcons(false);
                this->drawIcons(true);
            }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME || currentSubMenu==APP_SETTINGS_SUBMENU_SET_DATE){
                this->drawIcons(false);
                this->drawIcons(true);
            }
        #else
        if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
            if((int)((app_settings_selectedAppIndex)/APPS_ON_SINGLE_PAGE)==0){
                int x_position = 0;
                int y_position = 0;
                int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
                int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
                int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
                int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

                int x_center = (x0+x1)/2;
                int y_center = (y0+y1)/2;
                int y = y_center;

                int x = x0+35;
                int left_x = x + CORE_VIEWS_SETTINGS_IMAGE_WIDTH;
                String currentTime = core_time_getHourMinuteSecondsTime();
                setDrawColor(0, 0, 0);
                clearString(currentTime, left_x, y+4, 1);
                setDrawColor(255, 255, 255);
                drawString(currentTime, left_x, y+4, 1);
            }
        }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
            unsigned char lastSeconds_new   = core_time_getSeconds_byte();
            unsigned char lastMinutes_new   = core_time_getMinutes_byte();
            unsigned char lastHours_new     = core_time_getHours_byte();
            
            if(lastSeconds_new!=lastSeconds){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_3, lastSeconds);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_3, lastSeconds_new);
                lastSeconds = lastSeconds_new;
            }
            if(lastMinutes_new!=lastMinutes){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_2, lastMinutes);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_2, lastMinutes_new);
                lastMinutes = lastMinutes_new;
            }
            if(lastHours_new!=lastHours){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_1, lastHours);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_1, lastHours_new);
                lastHours = lastHours_new;
            }
            
        }
        #endif
    }

}

const unsigned char* appNameClass::getApplicationTitle(unsigned char submenu, unsigned char num){
    switch(submenu){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    return (const unsigned char*)"Time";
                case 1:
                    return (const unsigned char*)"Date";
                case 2:
                    return (const unsigned char*)"Screen";
                case 3:
                    return (const unsigned char*)"Power save";               
                default:
                    return (const unsigned char*)"-";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SET_TIME:
            switch (num){
                case 0:
                    return (const unsigned char*)"Hours";
                case 1:
                    return (const unsigned char*)"Minutes";
                case 2:
                    return (const unsigned char*)"Seconds";          
                default:
                    return (const unsigned char*)"-";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SET_DATE:
            switch (num){
                case 0:
                    return (const unsigned char*)"Year";
                case 1:
                    return (const unsigned char*)"Month";
                case 2:
                    return (const unsigned char*)"Day";          
                case 3:
                    return (const unsigned char*)"Day"; 
                default:
                    return (const unsigned char*)"-";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SCREEN:
            switch (num){
                case 0:
                    return (const unsigned char*)"Brightness";
                case 1:
                    return (const unsigned char*)"Fade bright.";
                case 2:
                    return (const unsigned char*)"Fade after";          
                case 3:
                    return (const unsigned char*)"Sleep after"; 
                default:
                    return (const unsigned char*)"-";
                    break;
            }
            break;
        default:
            return (const unsigned char*)"-";
    }
}

String appNameClass::getApplicationSubTitle(unsigned char submenu, unsigned char num){
    return this->getApplicationSubTitle(submenu, num, false);
}

String appNameClass::getApplicationSubTitle(unsigned char submenu, unsigned char num, bool getLast){    

    switch(submenu){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    if(getLast) return this->lastTimeString;
                    else{
                        this->lastTimeString = core_time_getHourMinuteSecondsTime();
                        return this->lastTimeString;
                    }
                case 1:
                    if(getLast) return this->lastDateString;
                    else{
                        this->lastDateString = core_time_getDateFull();
                        return this->lastDateString;
                    }
                case 2:
                    return String(get_core_display_brightness()) + "%";
                case 3:
                    if(getLast) return this->lastBatteryString;
                    else{
                        this->lastBatteryString = String(core_battery_getPercent()) + "%";
                        return this->lastBatteryString;
                    }
                case 4:
                    return "Calibrate";
                default:
                    return "Reset maximum";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SET_TIME:
            switch (num){
                case 0:
                    if(getLast) return this->lastTimeString_hours;
                    else{
                        this->lastTimeString_hours = core_time_getHours_String();
                        return this->lastTimeString_hours;
                    }
                case 1:
                    if(getLast) return this->lastTimeString_minutes;
                    else{
                        this->lastTimeString_minutes = core_time_getMinutes_String();
                        return this->lastTimeString_minutes;
                    }
                case 2:
                    if(getLast) return this->lastTimeString_seconds;
                    else{
                        this->lastTimeString_seconds = core_time_getSeconds_String();
                        return this->lastTimeString_seconds;
                    }      
                default:
                    return "-";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SET_DATE:
            switch (num){
                case 0:
                    if(getLast) return this->lastDateString_year;
                    else{
                        this->lastDateString_year = core_time_getYear();
                        return this->lastDateString_year;
                    }   
                case 1:
                    if(getLast) return this->lastDateString_month;
                    else{
                        this->lastDateString_month = core_time_getMonth_stringShort();
                        return this->lastDateString_month;
                    }   
                case 2:
                    if(getLast) return this->lastDateString_date;
                    else{
                        this->lastDateString_date = core_time_getDate();
                        return this->lastDateString_date;
                    }   
                case 3:
                    if(getLast) return this->lastDateString_weekDay;
                    else{
                        this->lastDateString_weekDay = core_time_getWeekDay_stringShort();
                        return this->lastDateString_weekDay;
                    }   
                    
                default:
                    return "-";
                    break;
            }
            break;
        case APP_SETTINGS_SUBMENU_SCREEN:
            switch (num){
                case 0:
                    #ifdef DISPLAY_BACKLIGHT_CONTROL_ENABLE 
                        return String(get_core_display_brightness()) + " %";
                    #else
                        return "-";
                    #endif
                case 1:
                    #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
                        return String(get_core_display_brightness_fade()) + " %"; 
                    #else
                        return "-";
                    #endif
                case 2:
                    #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
                        return String(get_core_display_time_delay_to_fade()) + " s";  
                    #else
                        return "-";
                    #endif
                case 3:
                    return String(get_core_display_time_delay_to_poweroff()) + " s";  
                default:
                    return "-";
            }
            break;
        default:
            return "-";
    }
}

const unsigned char* appNameClass::getApplicationIcon(unsigned char submenu, unsigned char num){
    switch(APP_SETTINGS_SUBMENU_MAIN){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    return this->icon_time;
                case 1:
                    return this->icon_date;
                case 2:
                    return this->icon_sleep;
                case 3:
                    return this->icon_battery;
                case 4:
                    return this->icon_battery;

                
                default:
                    return this->def;
                    break;
            }
            break;
        default:
            return this->def;
    }
}


const unsigned char appNameClass::def[] PROGMEM = {
    0x02,0x01,0x02,0x08,0x02,0x08,0x04,0xff,0xff,0xff,0x80,0xE0,0xF8,0xFF,0xFF,0xF8,0xE0,0x80,
};

const unsigned char appNameClass::icon_battery[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xEE,0x6E,0xEE,0xEE,0x6E,0xEE,0xEE,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xF8,0x80,0x00,0x04,0x80,0x00,0x04,0x80,0x00,0x06,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x06,0x80,0x00,0x04,0x80,0x00,0x04,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_light[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0xd9,0x00,0x03,0xC0,0x0F,0x30,0x1F,0x08,0x3F,0x04,0x7F,0x02,0x7F,
    0x02,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0x7F,0x02,0x7F,0x02,0x3F,0x04,0x1F,0x08,0x0F,0x30,0x03,0xC0,
};

const unsigned char appNameClass::icon_time[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x41,0x20,0x02,0x41,0x20,0x06,0xC3,0x60,0x02,0x59,0x20,0x02,0x41,0x20,0x02,0x59,0x20,0x02,0x41,0x20,0x02,0x41,0x20,0x02,0x41,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xd8,0xd8,0xd8,0x3E,0x00,0x7C,0x22,0x00,0x44,0x21,0xFF,0xC4,0x20,0x00,0x04,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x20,0x00,0x04,0x13,0xFF,0xC8,0x12,0x00,0x48,0x1E,0x00,0x78,0x04,0x8f,0x8f,0x8f,0x00,0x00,0x00,0x1C,0x00,0x38,0x1C,0x00,0x38,0x1F,0xFF,0xF8,0x3F,0xFF,0xFC,0x78,0x00,0x0E,0x70,0x00,0x06,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x70,0x00,0x06,0x78,0x00,0x0E,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0C,0x00,0x30,0x0C,0x00,0x30,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_date[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0xFF,0xFF,0xFF,0x04,0xd8,0xd8,0xd8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_sleep[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x3E,0x08,0x00,0x78,0x00,0x00,0x70,0x00,0x00,0xF0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xF0,0x00,0x00,0x70,0x00,0x00,0x78,0x00,0x00,0x3E,0x08,0x00,0x1F,0xF0,0x00,0x07,0xC0,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x07,0x00,0x00,0x01,0x00,0x0F,0xC2,0x00,0x00,0xC4,0x00,0x01,0x87,0x00,0x03,0x00,0x00,0x06,0x00,0x00,0x0C,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};




const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,
    0xF0,0x00,0x00,0x07,0xE0,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xb4,0xb4,0xb4,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x08,0x0F,
    0xF0,0x10,0x1C,0x3F,0xFC,0x38,0x3E,0x7F,0xFE,0x7C,0x7F,0xF8,0x1F,0xFE,0xFF,0xE0,
    0x07,0xFF,0xFF,0xC0,0x03,0xFF,0x7F,0x80,0x01,0xFE,0x3F,0x00,0x00,0xFC,0x1F,0x00,
    0x00,0xF8,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,
    0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x1F,0x00,0x00,0xF8,0x3F,0x00,
    0x00,0xFC,0x7F,0x80,0x01,0xFE,0xFF,0xC0,0x03,0xFF,0xFF,0xE0,0x07,0xFF,0x7F,0xF8,
    0x1F,0xFE,0x3E,0x7F,0xFE,0x7C,0x1C,0x3F,0xFC,0x38,0x08,0x0F,0xF0,0x10,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x04,0x47,
    0x47,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x1F,0xF8,0x00,0x00,0x3F,0xFC,0x00,0x00,0x7F,0xFE,0x00,0x00,0xFF,
    0xFF,0x00,0x00,0xFC,0x3F,0x00,0x01,0xF8,0x1F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,
    0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF8,0x1F,0x80,0x00,0xFC,
    0x3F,0x00,0x00,0xFF,0xFF,0x00,0x00,0x7F,0xFE,0x00,0x00,0x3F,0xFC,0x00,0x00,0x1F,
    0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,
};

#define appNameClass    TestApplicationApp         // App name without spaces
#define appName         "Test app"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);

    long time_finish;
    long time_start;

    setDrawColor(255, 255, 255);
    drawLine(40,30, SCREEN_WIDTH, 30);

    const unsigned char testIcon[] = {
        0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xC0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,
        0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,
        0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x3F,0xFF,
        0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x03,0xFF,0xC0,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0xFF,
        0xC0,0x0C,0x00,0x30,0x10,0x00,0x08,0x20,0x00,0x04,0x40,0x00,0x02,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,
        0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,
        0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x02,0x20,0x00,0x04,0x10,0x00,0x08,0x0C,0x00,
        0x30,0x03,0xFF,0xC0,
    };

    drawImage(true, testIcon, 70, 70); 

    /* * /
    fillScreen(0, 0, 0);
    setDrawColor(255, 255, 255);
    delay(10);
    time_start = millis();
    drawString("Rect test", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*0, 2);
    
    for(unsigned char i=0; i<61; i++){
        drawRect(1+i, 120+i, 240-i, 240-i);      
    }

    time_finish = millis()-time_start;
    drawString("Finish at " + String(time_finish), 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*1, 2);

    //  Results:
    // 13.02.2021 - 3442 ms
    // 13.02.2021 - 259 ms    - hardware acceleration for drawing lines

    delay(2000);
    // */

    /* * /
    const unsigned char testIcon[] = {
        0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xC0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,
        0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,
        0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x3F,0xFF,
        0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x03,0xFF,0xC0,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0xFF,
        0xC0,0x0C,0x00,0x30,0x10,0x00,0x08,0x20,0x00,0x04,0x40,0x00,0x02,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,
        0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,
        0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x02,0x20,0x00,0x04,0x10,0x00,0x08,0x0C,0x00,
        0x30,0x03,0xFF,0xC0,
    };
   
    fillScreen(0, 0, 0);
    core_views_statusBar_draw();
    setDrawColor(255, 255, 255);
    delay(10);
    time_start = millis();
    drawString("Icon test", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*0, 2);
    
    for(unsigned char i=0; i<30; i++){
        drawImage(true, testIcon, 120, 120);      
        drawImage(false, testIcon, 120, 120);      
    }

    setDrawColor(255, 255, 255);
    time_finish = millis()-time_start;
    drawString("Finish at " + String(time_finish), 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*1, 2);

    //  Results:
    // 13.02.2021 - 3581 ms
    // 13.02.2021 - 2480 ms    - Hardware acceleration for drawing lines
    // 13.02.2021 - 2476 ms    - I down`t know why, just a surprise for me
    // 13.02.2021 - 1377 ms    - Double pixels changed to fast lines
    // 13.02.2021 - 911 ms     - Clear icon with rect
    // 13.02.2021 - 833 ms     - Hardware acceleration for filling rect
    // 13.02.2021 - 828 ms     - Draw a line if more 2 pixels in raw

    delay(2000);
    // */

    /* * /
    const unsigned char testIcon[] = {
        0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xC0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,
        0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,
        0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x3F,0xFF,
        0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x03,0xFF,0xC0,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0xFF,
        0xC0,0x0C,0x00,0x30,0x10,0x00,0x08,0x20,0x00,0x04,0x40,0x00,0x02,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,
        0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,
        0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x02,0x20,0x00,0x04,0x10,0x00,0x08,0x0C,0x00,
        0x30,0x03,0xFF,0xC0,
    };

    fillScreen(0, 0, 0);
    core_views_statusBar_draw();
    setDrawColor(255, 255, 255);
    delay(10);
    time_start = millis();
    drawString("String test", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*0, 2);
    
    for(unsigned char ii=0; ii<10; ii++){
        #ifdef ESP8266
            ESP.wdtDisable();
        #endif
        for(unsigned char i=0; i<10; i++){
            setDrawColor(255, 255, 255);
            drawString("Blink string", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*5, 1);
            setDrawColor(0, 0, 0);
            //drawString("Blink string", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*5, 1);    
            clearString("Blink string", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*5, 1);    
        }
    }

    setDrawColor(255, 255, 255);
    time_finish = millis()-time_start;
    drawString("Finish at " + String(time_finish), 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*1, 2);

    //  Results:
    // 13.02.2021 3170ms
    // 13.02.2021 1935ms - Hardware acceleration for drawing lines
    // 14.02.2021 1933ms - Some optimization
    // 14.02.2021 1418ms - Added function clearString

    delay(2000);
    // */
    
    /* * /
    const unsigned char testIcon[] = {
        0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xC0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,
        0x3F,0xFF,0xFC,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,
        0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x3F,0xFF,
        0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x03,0xFF,0xC0,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0xFF,
        0xC0,0x0C,0x00,0x30,0x10,0x00,0x08,0x20,0x00,0x04,0x40,0x00,0x02,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,
        0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,
        0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x02,0x20,0x00,0x04,0x10,0x00,0x08,0x0C,0x00,
        0x30,0x03,0xFF,0xC0,
    };

    fillScreen(0, 0, 0);
    core_views_statusBar_draw();
    setDrawColor(255, 255, 255);
    delay(10);
    time_start = millis();
    drawString("String test", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*0, 2);
    
    for(unsigned char ii=0; ii<5; ii++){
        #ifdef ESP8266
            ESP.wdtDisable();
        #endif

        setDrawColor(255, 255, 255);
        drawString("Blink", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*5, 7);
        setDrawColor(0, 0, 0);
        clearString("Blink", 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*5, 7);    

    }

    setDrawColor(255, 255, 255);
    time_finish = millis()-time_start;
    drawString("Finish at " + String(time_finish), 5, STYLE_STATUSBAR_HEIGHT + 10 + 16*1, 2);

    //  Results:
    // 13.02.2021 3620 ms
    // 14.02.2021 2215 ms    - Added function clearString
    // 14.02.2021 525 ms     - Draw optimization
    // 14.02.2021 504 ms     - Drawing pixels in raw with fontsize>1

    delay(2000);
    
    // */
    
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        #if DRIVER_CONTROLS_TOTALBUTTONS > 3
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        #endif
        
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
        if(val1==BUTTON_SELECT){

            #if DRIVER_CONTROLS_TOTALBUTTONS == 1
                startApp(-1);
            #elif DRIVER_CONTROLS_TOTALBUTTONS == 2
                startApp(-1);
            #else
            #endif
        }
    }else if(event==EVENT_ON_TIME_CHANGED){
    }else if(event==EVENT_ON_GOING_TO_SLEEP){
    }else if(event==EVENT_ON_WAKE_UP){
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x6f,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x78,
    0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0xFE,0xFF,0xFE,0x7F,0xFF,0xFF,0xF9,0x9F,0xFF,
    0xFF,0xE7,0xE7,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0x7F,0xFE,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x67,0xE0,0xFF,0xFF,0x79,0x80,0xFF,0xFF,0x7E,0x00,
    0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x9F,0x01,0xFF,0xFF,0xE7,
    0x07,0xFF,0xFF,0xF9,0x1F,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x7F,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,
    0xC7,0x6B,0xFF,0xFF,0xDB,0x65,0xFF,0xFF,0xDB,0x6D,0xFF,0xFF,0xC7,0x6D,0xFF,0x7F,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x06,0x60,0x00,0x00,0x18,0x18,
    0x00,0x00,0x60,0x06,0x00,0x00,0x80,0x01,0x00,0x00,0xE0,0x07,0x00,0x00,0x98,0x19,0x00,0x00,0x86,0x61,0x00,0x00,0x81,0x81,0x00,0x00,0x80,
    0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x60,0x86,0x00,0x00,0x18,0x98,0x00,0x00,
    0x06,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x80,0x00,0x00,0x20,0x00,0x00,0x00,0x38,0x94,0x00,
    0x00,0x24,0x9A,0x00,0x00,0x24,0x92,0x00,0x00,0x38,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define appNameClass    BarometerApp          // App name without spaces
#define appName         "Barometer"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xd9,0x00,0x00,0x00,0x81,0x00,0x00,0x00,0x82,0x01,0x00,0x00,0x82,0x02,0x00,0x00,0x84,0x04,
    0x00,0x07,0xE4,0x08,0x00,0x1F,0xF8,0x10,0x00,0x7F,0xFE,0x20,0x00,0xFF,0xFF,0x40,0x01,0xC1,0xFF,0x81,0x03,0x00,0xFF,0xC6,0x02,0x00,
    0xFF,0xD8,0x04,0x00,0xFF,0xE0,0x04,0x00,0xFF,0xE0,0x00,0x00,0xFF,0xF0,0x00,0x00,0xFF,0xF0,0x00,0x00,0xFF,0xF0,0x00,0x00,0xFF,0xFF,
    0x00,0x00,0xFF,0xF0,0x00,0x00,0xFF,0xF0,0x00,0x00,0xFF,0xE0,0x00,0x00,0xFF,0xE0,0x00,0x00,0xFF,0xD8,0x00,0x00,0xFF,0xC6,0x00,0x00,
    0xFF,0x81,0x00,0x00,0xFF,0x40,0x00,0x00,0xFE,0x20,0x00,0x00,0xFC,0x10,0x00,0x00,0xE4,0x08,0x00,0x00,0x82,0x04,0x00,0x00,0x82,0x02,
    0x00,0x00,0x81,0x01,0x00,0x00,0x81,0x00,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x40,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x11,0x11,
    0x00,0x00,0x22,0x22,0x00,0x00,0x44,0x44,0x00,0x00,0x04,0xd8,0xd8,0xd8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,
    0x00,0x00,0x00,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x01,0xFF,0x00,0x00,0x03,0xFF,0x00,0x00,0x03,0xFF,0x00,0x00,0x03,0xFF,0x00,0x00,
    0x0D,0xFF,0x00,0x00,0x3F,0xFF,0x00,0x00,0x7F,0xFF,0x00,0x00,0x7F,0xFF,0x00,0x00,0x7F,0xFF,0x00,0x00,0x7F,0xFF,0x00,0x00,0x37,0xFF,
    0x00,0x00,0x07,0xFF,0x00,0x00,0x07,0xFF,0x00,0x00,0x07,0xFF,0x00,0x00,0x03,0xFF,0x00,0x00,0x00,0xF3,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x8f,0x8f,0x8f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,
    0x00,0xC1,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x32,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
    0x48,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x03,0x0C,0x00,0x00,0x00,0xF3,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define appNameClass    ClockApp          // App name without spaces
#define appName         "Clock"              // App name with spaces 

class appNameClass: public Application{
    public:
        bool isfullScreen         = true;
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0); 
            this->showStatusBar = false;
            super_onCreate(); 
            onCreate(); 
        };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;

        void draw_current_time(bool draw);
        String timeString;

        unsigned char last_seconds  = 0;
        String last_hours           = "";
        String last_minutes         = "";

        #define BATTERY_ENABLE
            String last_battery     = "";
        #endif

        #ifdef PEDOMETER_ENABLE
            String last_pedometer   = "";
        #endif

        void drawSecondsCircle(bool draw, unsigned char second);
      
};

#define SECONDS_CIRCLE_X        (SCREEN_WIDTH/2) 
#define SECONDS_CIRCLE_Y        (SCREEN_HEIGHT/2)
#define SECONDS_CIRCLE_RADIUS   (SCREEN_WIDTH/2-2)

void appNameClass::onCreate(){
    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);

    setDrawColor(48, 48, 48);
    drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-1, true);

    this->last_seconds = core_time_getSeconds_byte();
    for(unsigned char isecond=0; isecond<=this->last_seconds; isecond++) this->drawSecondsCircle(true, isecond);
    this->draw_current_time(true);

}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        #if DRIVER_CONTROLS_TOTALBUTTONS > 3
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        #endif
        
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
        if(val1==BUTTON_SELECT){

            #if DRIVER_CONTROLS_TOTALBUTTONS == 1
                startApp(-1);
            #elif DRIVER_CONTROLS_TOTALBUTTONS == 2
                startApp(-1);
            #else
            #endif
        }
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
        this->draw_current_time(false);
        this->draw_current_time(true);
    }else if(event==EVENT_ON_GOING_TO_SLEEP){
        this->draw_current_time(false);
    }else if(event==EVENT_ON_WAKE_UP){
        this->draw_current_time(true);
    }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
        if(val1==BUTTON_SELECT){
            startApp(-1);
        }
    }
    
}

/*
#define NARROW_CLOCK_STRING1 18
#define NARROW_CLOCK_STRING2 73
#define NARROW_CLOCK_STRING3 125
*/

void appNameClass::drawSecondsCircle(bool draw, unsigned char second){
    if(draw)setGradientColor(255, 85, 0, 46, 255, 0, 60, second);
    else setDrawColor_BackGroundColor();

    int grad = 6*second;
 
    drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS, -90 + grad, -90 + grad + 6, 8, true);
}

void appNameClass::draw_current_time(bool draw){
    #define CLOCK_FONT      2
    #define CLOCK_MARGIN    3
    #define STRINGS_OFFSET  2

    this->preventSleep         = true;
    this->preventInAppSleep    = true;
    if(draw){
        // Draw
        setDrawColor_ContrastColor();
        this->timeString = core_time_getHourMinuteSecondsTime();
        #ifdef NARROW_SCREEN

            // SECONDS CIRCLE
            unsigned char seconds_draw;
            if(core_time_getSeconds_byte()>this->last_seconds) seconds_draw = core_time_getSeconds_byte() - this->last_seconds;
            else seconds_draw = 1;
            
            this->last_seconds = core_time_getSeconds_byte();
            for(char i_predrawSeconds=0; i_predrawSeconds<seconds_draw; i_predrawSeconds++) this->drawSecondsCircle(draw, this->last_seconds-i_predrawSeconds);
            
            // HOURS AND MINUTES 
            setDrawColor_ContrastColor();

            this->last_hours    = core_time_getHours_String();
            this->last_minutes  = core_time_getMinutes_String();

            drawString_centered(core_time_getHours_String(), SCREEN_WIDTH/2, STRINGS_OFFSET + SCREEN_HEIGHT/2-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
            drawString_centered(core_time_getMinutes_String(), SCREEN_WIDTH/2, STRINGS_OFFSET + SCREEN_HEIGHT/2 + CLOCK_MARGIN, CLOCK_FONT);
            
            #define BATTERY_ENABLE
                // BATTERY
                String last_battery     = "";
            #endif
        #else
            drawString(this->timeString, 2, 90, 5);
        #endif
    }else{
        // Clear
        setDrawColor_BackGroundColor();
        #ifdef NARROW_SCREEN
            
            // SECONDS CIRCLE
            if(this->last_seconds>core_time_getSeconds_byte()){
                // if munutes changed
                setDrawColor_BackGroundColor();
                
                for(int isecond=0; isecond<60; isecond++){
                    drawSecondsCircle(draw, isecond);
                }

                setDrawColor(48, 48, 48);
                drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-1, true);
                
                clearString_centered(last_hours, SCREEN_WIDTH/2, STRINGS_OFFSET + SCREEN_HEIGHT/2-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
                clearString_centered(last_minutes, SCREEN_WIDTH/2, STRINGS_OFFSET + SCREEN_HEIGHT/2 + CLOCK_MARGIN, CLOCK_FONT);
            }
            

        #else
            clearString(this->timeString, 2, 90, 5);
        #endif
    }

    /*
    this->timeString = core_time_getHourMinuteSecondsTime();
    setDrawColor(0, 0, 0);
    clearString(this->timeString, 2, 90, 5);
    setDrawColor(255, 255, 255);
    drawString(this->timeString, 2, 90, 5);
    */
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x3F,0xFC,0x00,0x00,
    0xFF,0xFF,0x00,0x01,0xFF,0xFF,0x80,0x03,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xE0,0x19,0xFF,0xFF,0x80,
    0x18,0x7F,0xFE,0x00,0x3E,0x1F,0xF8,0x1C,0x3F,0x87,0xE0,0x7C,0x3F,0xE1,0x81,0xFC,0x3F,0xF8,0x07,0xFC,0x3F,0xFE,0x1F,0xFC,0x3F,0xFE,0x7F,
    0xFC,0x3F,0xFE,0x7F,0xFC,0x3F,0xFE,0x7F,0xFC,0x1F,0xFE,0x7F,0xF8,0x1F,0xFE,0x7F,0xF8,0x0F,0xFE,0x7F,0xF0,0x0F,0xFE,0x7F,0xF0,0x07,0xFE,
    0x7F,0xE0,0x03,0xFE,0x7F,0xC0,0x01,0xFE,0x7F,0x80,0x00,0xFE,0x7F,0x00,0x00,0x3E,0x7C,0x00,0x00,0x0E,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1C,0x06,0x00,0x00,0x78,0x07,0x80,0x01,
    0xE0,0x01,0xE0,0x07,0x80,0x00,0x78,0x1E,0x00,0x00,0x1E,0x78,0x00,0x00,0x07,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xb4,0xb4,0xb4,0x00,0x0F,0xF0,0x00,0x00,0x7F,0xFE,0x00,0x01,0xF0,0x0F,0x80,0x03,0xC0,0x03,0xC0,0x07,0x00,0x00,0xE0,0x0E,0x00,0x00,
    0x70,0x1C,0x00,0x00,0x38,0x38,0x00,0x00,0x1C,0x30,0x00,0x00,0x08,0x60,0x00,0x00,0x02,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0xC0,0x00,
    0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,
    0x00,0x00,0x03,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0x70,0x00,0x00,0x0E,0x30,0x00,0x00,0x0C,0x38,0x00,0x00,0x1C,0x1C,0x00,0x00,0x38,
    0x0E,0x00,0x00,0x70,0x07,0x00,0x00,0xE0,0x03,0xC0,0x03,0xC0,0x01,0xF0,0x0F,0x80,0x00,0x7E,0x7E,0x00,0x00,0x0E,0x70,0x00,0x04,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,
    0x00,0x01,0x80,0x00,0x00,0x06,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,
    0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,

   
};

#define appNameClass    FileManagerApp          // App name without spaces
#define appName         "Files"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x06,0x00,0x00,
    0x00,0x03,0xFF,0xFE,0x1F,0xE0,0x00,0x06,0x3F,0xF0,0x00,0x02,0x7F,0xF8,0x00,
    0x02,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,
    0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,
    0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,
    0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,
    0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,
    0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x00,
    0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x18,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x07,0xFF,0xF8,0x00,0x00,0x00,0x18,0x00,0x00,
    0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,
    0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,
    0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,
    0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,
    0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,
    0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x02,0x04,0x00,
    0x00,0x07,0xF2,0x00,0x00,0x08,0x09,0xFF,0xFE,0x1F,0xE4,0x00,0x01,0x20,0x13,
    0xFF,0xF9,0x40,0x08,0x00,0x05,0x80,0x07,0xFF,0xE5,0x80,0x00,0x00,0x15,0x80,
    0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,
    0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,
    0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,
    0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,
    0x00,0x00,0x15,0x80,0x00,0x00,0x17,0x80,0x00,0x00,0x14,0x80,0x00,0x00,0x14,
    0x80,0x00,0x00,0x1C,0x80,0x00,0x00,0x10,0xFF,0xFF,0xFF,0xF0,

};

#define appNameClass    InternetApp          // App name without spaces
#define appName         "Internet"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

        0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x03,0xC0,0x00,0x40,0x07,0xF0,0x00,0xE0,0x0F,0xF0,0x00,0xF0,0x1F,0xC0,0x03,0xF8,0x1F,0x00,0x03,0xF8,0x3F,0x00,0x07,0xFC,
        0x3E,0x00,0x0F,0xFC,0x3E,0x00,0x0E,0xFC,0x7E,0x00,0x3A,0x7E,0x7C,0x00,0x3A,0x76,0x70,0x00,0x38,0xC0,0x40,0x00,0x00,0x20,0x70,
        0x00,0x0F,0xE0,0x78,0x00,0x1F,0xF0,0x7F,0x00,0x3F,0xF0,0x7F,0x80,0x3F,0xF0,0x3F,0x80,0x3F,0xF0,0x3F,0x80,0x1F,0xF0,0x3F,0x80,
        0x0F,0xE0,0x1F,0x00,0x01,0xE8,0x1E,0x00,0x01,0xE8,0x0E,0x00,0x00,0xE0,0x06,0x00,0x00,0xC0,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,
        0x00,0x7F,0xFE,0x00,0x01,0xFF,0xFF,0x80,0x00,0x3F,0xFF,0x80,0x00,0x0F,0xFF,0x00,0x00,0x0F,0xFF,0x00,0x00,0x3F,0xFC,0x00,0x00,
        0xFF,0xFC,0x00,0x00,0xFF,0xF8,0x00,0x01,0xFF,0xF0,0x00,0x01,0xFF,0xF1,0x00,0x01,0xFF,0xC5,0x80,0x03,0xFF,0xC5,0x88,0x0F,0xFF,
        0xC7,0x3E,0x3F,0xFF,0xFF,0xDE,0x0F,0xFF,0xF0,0x1E,0x07,0xFF,0xE0,0x0E,0x00,0xFF,0xC0,0x0E,0x00,0x7F,0xC0,0x0E,0x00,0x7F,0xC0,
        0x0C,0x00,0x7F,0xE0,0x0C,0x00,0x7F,0xF0,0x1C,0x00,0xFF,0xFE,0x10,0x01,0xFF,0xFE,0x10,0x01,0xFF,0xFF,0x10,0x01,0xFF,0xFF,0x20,
        0x01,0xFF,0xFF,0xC0,0x01,0xFF,0xFF,0x80,0x00,0x7F,0xFE,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
        0x0F,0xF0,0x00,0x00,0x70,0x0E,0x00,0x01,0x80,0x01,0x80,0x02,0x00,0x00,0x40,0x04,0x00,0x00,0x20,0x08,0x00,0x00,0x10,0x10,0x00,
        0x00,0x08,0x20,0x00,0x00,0x04,0x20,0x00,0x00,0x04,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x80,0x00,0x00,
        0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,
        0x80,0x00,0x00,0x01,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x20,0x00,0x00,0x04,0x20,0x00,0x00,0x04,0x10,
        0x00,0x00,0x08,0x08,0x00,0x00,0x10,0x04,0x00,0x00,0x20,0x02,0x00,0x00,0x40,0x01,0x80,0x01,0x80,0x00,0x70,0x0E,0x00,0x00,0x0F,
        0xF0,0x00,

};

#define appNameClass    SimpleGameApp          // App name without spaces
#define appName         "Game"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }

    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0xE0,0x07,0x00,
    0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x03,0x80,
    0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x03,
    0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xC0,0x1F,0x8F,0xF1,0xF8,0x1F,0x8F,0xF1,0xF8,0x1F,0x8F,0xF1,0xF8,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE3,0xFF,0xFF,0xC7,0xE3,0xFF,0xFF,0xC7,0xE3,0xFF,0xFF,
    0xC7,0xE3,0x80,0x01,0xC7,0xE3,0x80,0x01,0xC7,0xE3,0x80,0x01,0xC7,0x00,0x7E,0x7E,0x00,0x00,0x7E,0x7E,0x00,0x00,0x7E,
    0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define appNameClass    KeyboardTest         // App name without spaces
#define appName         "Keyboard test"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0x01,0xC7,0x07,0x00,0x02,0x24,0x48,0x80,0x02,0x24,0x48,0x00,0x02,
    0x27,0x88,0x00,0x03,0xE4,0x48,0x00,0x02,0x24,0x48,0x00,0x02,0x24,0x48,0x80,0x02,0x27,0x87,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x7F,0xFF,0xFF,
    0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x7F,0xFF,0xFF,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,
    0x44,0x44,0x44,0x44,0x44,0x44,0x7F,0xFF,0xFF,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x7F,
    0xFF,0xFF,0xFC,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x7F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,
    0x04,0x47,0x47,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x00,0x00,0x00,0x00,0x3B,0xBB,0xBB,0xB8,0x3B,
    0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x00,0x00,0x00,0x00,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,
    0x00,0x00,0x00,0x00,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x00,0x00,0x00,0x00,0x3B,0xBB,0xBB,
    0xB8,0x3B,0xBB,0xBB,0xB8,0x3B,0xBB,0xBB,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#define appNameClass    TouchCalibration         // App name without spaces
#define appName         "Touch Calibr"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */

    setBackgroundColor(0, 0, 0);
    setDrawColor(255, 255, 255);
    drawString("Not touched", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */

    /*
    setBackgroundColor(0, 0, 0);
    setDrawColor(0, 0, 0);
    clearString("25500", 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    
    setDrawColor(255, 255, 255);
    drawString(getDe(), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    //drawString(String((int) 2), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }else if(event==EVENT_ON_TOUCH_START){
        setDrawColor(0, 0, 0);
        clearString("Not touched released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);

        setDrawColor(255, 255, 255);
        drawString("Touch start", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }else if(event==EVENT_ON_TOUCH_RELEASED){
        setDrawColor(0, 0, 0);
        clearString("Not touched released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);

        setDrawColor(255, 255, 255);
        drawString("Touch released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x3F,0xFC,0x00,0x00,0x3F,0xFC,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,
    0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xFF,0x00,
    0x00,0xFF,0xFF,0x00,0x00,0xFF,
};

#define appNameClass    TouchTest         // App name without spaces
#define appName         "Touch test"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        void clearLabels();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */

    setBackgroundColor(0, 0, 0);
    setDrawColor(255, 255, 255);
    drawString("Not touched", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */

    /*
    setBackgroundColor(0, 0, 0);
    setDrawColor(0, 0, 0);
    clearString("25500", 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    
    setDrawColor(255, 255, 255);
    drawString(getDe(), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    //drawString(String((int) 2), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::clearLabels(){
    setDrawColor(0, 0, 0);
    //drawRect(5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 240, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, true);
    drawRect(0, STYLE_STATUSBAR_HEIGHT, 240, 240, true);
    /*
    clearString("Not touched released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
    clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
    clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }else if(event==EVENT_ON_TOUCH_START){
        this->clearLabels();

        setDrawColor(255, 255, 255);
        drawString("Touch start", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }else if(event==EVENT_ON_TOUCH_RELEASED){
        this->clearLabels();

        setDrawColor(255, 255, 255);
        drawString("Touch released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }else if(event==EVENT_ON_TOUCH_DRAG){
        this->clearLabels();

        setDrawColor(255, 255, 255);
        drawString("Touch drag", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }else if(event==EVENT_ON_TOUCH_LONG_PRESS){
        this->clearLabels();

        setDrawColor(255, 255, 255);
        drawString("Long press", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }

    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x3F,0xFC,0x00,0x00,0x3F,0xFC,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,
    0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xFF,0x00,
    0x00,0xFF,0xFF,0x00,0x00,0xFF,
};

#define appNameClass    MainMenuApp      // App name without spaces
#define appName         "Main menu"      // App name with spaces 

#define ACTIVE_SCREEN_WIDTH             SCREEN_WIDTH
#define ACTIVE_SCREEN_HEIGHT            (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT)
#define SINGLE_ELEMENT_MIN_WIDTH        100
#define SINGLE_ELEMENT_MIN_HEIGHT       80

#define SINGLE_ELEMENTS_IN_X            ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y            ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#define SINGLE_ELEMENT_REAL_WIDTH       ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENTS_IN_X))
#define SINGLE_ELEMENT_REAL_HEIGHT      ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENTS_IN_Y))

#define PAGES_LIST_POSITION             (SCREEN_HEIGHT)

#define APPS_ON_SINGLE_PAGE             (SINGLE_ELEMENTS_IN_X * SINGLE_ELEMENTS_IN_Y)




#ifdef  APP_MENU_APPLICATIONS_0
  #define APP_MENU_APPLICATIONS_QUANTITY 1
#endif
#ifdef  APP_MENU_APPLICATIONS_1
  #define APP_MENU_APPLICATIONS_QUANTITY 2
#endif
#ifdef  APP_MENU_APPLICATIONS_2
  #define APP_MENU_APPLICATIONS_QUANTITY 3
#endif
#ifdef  APP_MENU_APPLICATIONS_3
  #define APP_MENU_APPLICATIONS_QUANTITY 4
#endif
#ifdef  APP_MENU_APPLICATIONS_4
  #define APP_MENU_APPLICATIONS_QUANTITY 5
#endif
#ifdef  APP_MENU_APPLICATIONS_5
  #define APP_MENU_APPLICATIONS_QUANTITY 6
#endif
#ifdef  APP_MENU_APPLICATIONS_6
  #define APP_MENU_APPLICATIONS_QUANTITY 7
#endif
#ifdef  APP_MENU_APPLICATIONS_7
  #define APP_MENU_APPLICATIONS_QUANTITY 8
#endif
#ifdef  APP_MENU_APPLICATIONS_8
  #define APP_MENU_APPLICATIONS_QUANTITY 9
#endif
#ifdef  APP_MENU_APPLICATIONS_9
  #define APP_MENU_APPLICATIONS_QUANTITY 10
#endif
#ifdef  APP_MENU_APPLICATIONS_10
  #define APP_MENU_APPLICATIONS_QUANTITY 11
#endif
#ifdef  APP_MENU_APPLICATIONS_11
  #define APP_MENU_APPLICATIONS_QUANTITY 12
#endif
#ifdef  APP_MENU_APPLICATIONS_12
  #define APP_MENU_APPLICATIONS_QUANTITY 13
#endif
#ifdef  APP_MENU_APPLICATIONS_13
  #define APP_MENU_APPLICATIONS_QUANTITY 14
#endif
#ifdef  APP_MENU_APPLICATIONS_14
  #define APP_MENU_APPLICATIONS_QUANTITY 15
#endif
#ifdef  APP_MENU_APPLICATIONS_15
  #define APP_MENU_APPLICATIONS_QUANTITY 16
#endif
#ifdef  APP_MENU_APPLICATIONS_16
  #define APP_MENU_APPLICATIONS_QUANTITY 17
#endif
#ifdef  APP_MENU_APPLICATIONS_17
  #define APP_MENU_APPLICATIONS_QUANTITY 18
#endif
#ifdef  APP_MENU_APPLICATIONS_18
  #define APP_MENU_APPLICATIONS_QUANTITY 19
#endif
#ifdef  APP_MENU_APPLICATIONS_19
  #define APP_MENU_APPLICATIONS_QUANTITY 20
#endif
#ifdef  APP_MENU_APPLICATIONS_20
  #define APP_MENU_APPLICATIONS_QUANTITY 21
#endif
#ifdef  APP_MENU_APPLICATIONS_21
  #define APP_MENU_APPLICATIONS_QUANTITY 22
#endif
#ifdef  APP_MENU_APPLICATIONS_22
  #define APP_MENU_APPLICATIONS_QUANTITY 23
#endif
#ifdef  APP_MENU_APPLICATIONS_23
  #define APP_MENU_APPLICATIONS_QUANTITY 24
#endif
#ifdef  APP_MENU_APPLICATIONS_24
  #define APP_MENU_APPLICATIONS_QUANTITY 25
#endif
#ifdef  APP_MENU_APPLICATIONS_25
  #define APP_MENU_APPLICATIONS_QUANTITY 26
#endif
#ifdef  APP_MENU_APPLICATIONS_26
  #define APP_MENU_APPLICATIONS_QUANTITY 27
#endif
#ifdef  APP_MENU_APPLICATIONS_27
  #define APP_MENU_APPLICATIONS_QUANTITY 28
#endif
#ifdef  APP_MENU_APPLICATIONS_28
  #define APP_MENU_APPLICATIONS_QUANTITY 29
#endif
#ifdef  APP_MENU_APPLICATIONS_29
  #define APP_MENU_APPLICATIONS_QUANTITY 30
#endif
#ifdef  APP_MENU_APPLICATIONS_30
  #define APP_MENU_APPLICATIONS_QUANTITY 31
#endif
#ifdef  APP_MENU_APPLICATIONS_31
  #define APP_MENU_APPLICATIONS_QUANTITY 32
#endif

#define TOTAL_PAGES (APP_MENU_APPLICATIONS_QUANTITY%APPS_ON_SINGLE_PAGE==0?((int)(APP_MENU_APPLICATIONS_QUANTITY/APPS_ON_SINGLE_PAGE)):((int)(APP_MENU_APPLICATIONS_QUANTITY/APPS_ON_SINGLE_PAGE) + 1))

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //

char app_z_menu_selectedAppIndex = 0; // Now it is a global variable

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
          switch(type){ 
            case PARAM_TYPE_NAME: return (unsigned char*)appName; 
            case PARAM_TYPE_ICON: return icon;
            default: return (unsigned char*)""; 
          }
        };
        const static unsigned char icon[] PROGMEM;
      
    private:
        const unsigned char* getApplicationTitle(int num);
        const unsigned char* getApplicationIcon(int num);
        void drawIcons(bool draw);

};

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x6f,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x78,
    0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0xFE,0xFF,0xFE,0x7F,0xFF,0xFF,0xF9,0x9F,0xFF,
    0xFF,0xE7,0xE7,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0x7F,0xFE,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x67,0xE0,0xFF,0xFF,0x79,0x80,0xFF,0xFF,0x7E,0x00,
    0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x9F,0x01,0xFF,0xFF,0xE7,
    0x07,0xFF,0xFF,0xF9,0x1F,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x7F,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,
    0xC7,0x6B,0xFF,0xFF,0xDB,0x65,0xFF,0xFF,0xDB,0x6D,0xFF,0xFF,0xC7,0x6D,0xFF,0x7F,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x06,0x60,0x00,0x00,0x18,0x18,
    0x00,0x00,0x60,0x06,0x00,0x00,0x80,0x01,0x00,0x00,0xE0,0x07,0x00,0x00,0x98,0x19,0x00,0x00,0x86,0x61,0x00,0x00,0x81,0x81,0x00,0x00,0x80,
    0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x60,0x86,0x00,0x00,0x18,0x98,0x00,0x00,
    0x06,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x80,0x00,0x00,0x20,0x00,0x00,0x00,0x38,0x94,0x00,
    0x00,0x24,0x9A,0x00,0x00,0x24,0x92,0x00,0x00,0x38,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void appNameClass::onCreate(){
    this->drawIcons(true);
    
}

void appNameClass::drawIcons(bool draw){

  DRAW_LIMITS_setEnable(true);
  DRAW_LIMIT_reset();
  DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
  
	for(unsigned char app_num=0; app_num<APP_MENU_APPLICATIONS_QUANTITY; app_num++){

		unsigned char x_position = app_num%SINGLE_ELEMENTS_IN_X;
		unsigned char y_position = app_num/SINGLE_ELEMENTS_IN_Y;

		int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
		int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
		int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
		int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

		int x_center = (x0+x1)/2;
		int y_center = (y0+y1)/2;

		core_views_draw_app_icon(
			draw, 
			x_center, y_center - this->scroll_y, 
			(const unsigned char*)this->getApplicationTitle(app_num), 
			this->getApplicationIcon(app_num)
		);
	}

  DRAW_LIMITS_setEnable(false);
}

void appNameClass::onLoop(){
}

void appNameClass::onDestroy(){
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){

    if(event==EVENT_ON_TOUCH_START){

    }else if(event==EVENT_ON_TOUCH_CLICK){    

      int position_x = (this->scroll_x + val1)/(SINGLE_ELEMENT_REAL_WIDTH);
      int position_y = (this->scroll_y + val2 + STYLE_STATUSBAR_HEIGHT)/(SINGLE_ELEMENT_REAL_HEIGHT);
      //if(position_y<0) position_y = 1;

      position_y -= 1;
      if(position_y<0) position_y = 0;
      if(position_x>SINGLE_ELEMENTS_IN_X-1)position_x=SINGLE_ELEMENTS_IN_X-1;
      if(position_x<0) position_x = 0;
      
      int appNum = position_x + position_y*SINGLE_ELEMENTS_IN_X;
      //if(appNum<0) appNum = 0;
      if(appNum<0 || appNum>APP_MENU_APPLICATIONS_QUANTITY-1) return; //appNum = APP_MENU_APPLICATIONS_QUANTITY-1;
      startApp(appNum);

    }else if(event==EVENT_ON_TOUCH_RELEASED){

      #ifdef PLATFORM_PC_emulator
        this->drawIcons(false);
        float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);
        this->scroll_y = round(position) * SINGLE_ELEMENT_REAL_HEIGHT;
        this->drawIcons(true);
      #else
        if(millis() - getTOUCH_SCREEN_touch_start_ms()<150){
          // Fast scroll
          if(abs(getTOUCH_SCREEN_touch_start_y()-val2)>10){
            // Slow scroll
            this->drawIcons(false);
            float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);

            if(getTOUCH_SCREEN_touch_start_y()-val2>0) this->scroll_y = round(position+2) * SINGLE_ELEMENT_REAL_HEIGHT;
            else this->scroll_y = round(position-2) * SINGLE_ELEMENT_REAL_HEIGHT;

            int max_scroll = (APP_MENU_APPLICATIONS_QUANTITY-1)/SINGLE_ELEMENTS_IN_Y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1+SINGLE_ELEMENT_REAL_HEIGHT - SCREEN_HEIGHT;
            if(scroll_y>max_scroll) {
              scroll_y = max_scroll;
            }
            if(scroll_y<0){
              scroll_y=0;
            }
            this->drawIcons(true);    
          }
        }else{
          // Slow scroll
          this->drawIcons(false);
          float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);
          this->scroll_y = round(position) * SINGLE_ELEMENT_REAL_HEIGHT;
          this->drawIcons(true);
        }
      #endif
      
    }else if(event==EVENT_ON_TOUCH_DRAG){

      // SCREEN SCROLL
      this->drawIcons(false);
      this->scroll_y -= val2;
      if(scroll_y<0) scroll_y = 0;

      int max_scroll = (APP_MENU_APPLICATIONS_QUANTITY-1)/SINGLE_ELEMENTS_IN_Y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1+SINGLE_ELEMENT_REAL_HEIGHT - SCREEN_HEIGHT;
      if(scroll_y>max_scroll) {
        scroll_y = max_scroll;
      }

      this->drawIcons(true);
    }

}

const unsigned char* appNameClass::getApplicationTitle(int num){
    return getAppParams(num,(PARAM_TYPE_NAME));
}

const unsigned char*  appNameClass::getApplicationIcon(int num){
    return (const unsigned char *)getAppParams(num,(PARAM_TYPE_ICON));
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS +                                    #
    #                                                                                          #
    ############################################################################################
*/

Application *getApp(unsigned char i){  
    if (i==0) return new APP_MENU_APPLICATIONS_0; 
    #if APP_MENU_APPLICATIONS_QUANTITY > 1
      else if (i==1) return new APP_MENU_APPLICATIONS_1; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 2
      else if (i==2) return new APP_MENU_APPLICATIONS_2; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 3
      else if (i==3) return new APP_MENU_APPLICATIONS_3; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 4
      else if (i==4) return new APP_MENU_APPLICATIONS_4; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 5
      else if (i==5) return new APP_MENU_APPLICATIONS_5; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 6
      else if (i==6) return new APP_MENU_APPLICATIONS_6; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 7
      else if (i==7) return new APP_MENU_APPLICATIONS_7; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 8
      else if (i==8) return new APP_MENU_APPLICATIONS_8; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 9
      else if (i==9) return new APP_MENU_APPLICATIONS_9; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 10
      else if (i==10) return new APP_MENU_APPLICATIONS_10; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 11
      else if (i==11) return new APP_MENU_APPLICATIONS_11; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 12
      else if (i==12) return new APP_MENU_APPLICATIONS_12; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 13
      else if (i==13) return new APP_MENU_APPLICATIONS_13; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 14
      else if (i==14) return new APP_MENU_APPLICATIONS_14; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 15
      else if (i==15) return new APP_MENU_APPLICATIONS_15; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 16
      else if (i==16) return new APP_MENU_APPLICATIONS_16; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 17
      else if (i==17) return new APP_MENU_APPLICATIONS_17; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 18
      else if (i==18) return new APP_MENU_APPLICATIONS_18; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 19
      else if (i==19) return new APP_MENU_APPLICATIONS_19; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 20
      else if (i==20) return new APP_MENU_APPLICATIONS_20; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 21
      else if (i==21) return new APP_MENU_APPLICATIONS_21; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 22
      else if (i==22) return new APP_MENU_APPLICATIONS_22; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 23
      else if (i==23) return new APP_MENU_APPLICATIONS_23; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 24
      else if (i==24) return new APP_MENU_APPLICATIONS_24; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 25
      else if (i==25) return new APP_MENU_APPLICATIONS_25; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 26
      else if (i==26) return new APP_MENU_APPLICATIONS_26; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 27
      else if (i==27) return new APP_MENU_APPLICATIONS_27; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 28
      else if (i==28) return new APP_MENU_APPLICATIONS_28; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 29
      else if (i==29) return new APP_MENU_APPLICATIONS_29; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 30
      else if (i==30) return new APP_MENU_APPLICATIONS_30; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 31
      else if (i==31) return new APP_MENU_APPLICATIONS_31; 
    #endif
    else return new appNameClass;
}

const unsigned char *getAppParams(char i, unsigned char type){
    if(i==0){ APP_MENU_APPLICATIONS_0 *app; return ((*app).getParams(type));
    #if APP_MENU_APPLICATIONS_QUANTITY > 1
      }else if(i==1){ APP_MENU_APPLICATIONS_1 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 2
      }else if(i==2){ APP_MENU_APPLICATIONS_2 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 3
      }else if(i==3){ APP_MENU_APPLICATIONS_3 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 4
      }else if(i==4){ APP_MENU_APPLICATIONS_4 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 5
      }else if(i==5){ APP_MENU_APPLICATIONS_5 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 6
      }else if(i==6){ APP_MENU_APPLICATIONS_6 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 7
      }else if(i==7){ APP_MENU_APPLICATIONS_7 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 8
      }else if(i==8){ APP_MENU_APPLICATIONS_8 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 9
      }else if(i==9){ APP_MENU_APPLICATIONS_9 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 10
      }else if(i==10){ APP_MENU_APPLICATIONS_10 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 11
      }else if(i==11){ APP_MENU_APPLICATIONS_11 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 12
      }else if(i==12){ APP_MENU_APPLICATIONS_12 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 13
      }else if(i==13){ APP_MENU_APPLICATIONS_13 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 14
      }else if(i==14){ APP_MENU_APPLICATIONS_14 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 15
      }else if(i==15){ APP_MENU_APPLICATIONS_15 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 16
      }else if(i==16){ APP_MENU_APPLICATIONS_16 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 17
      }else if(i==17){ APP_MENU_APPLICATIONS_17 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 18
      }else if(i==18){ APP_MENU_APPLICATIONS_18 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 19
      }else if(i==19){ APP_MENU_APPLICATIONS_19 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 20
      }else if(i==20){ APP_MENU_APPLICATIONS_20 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 21
      }else if(i==21){ APP_MENU_APPLICATIONS_21 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 22
      }else if(i==22){ APP_MENU_APPLICATIONS_22 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 23
      }else if(i==23){ APP_MENU_APPLICATIONS_23 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 24
      }else if(i==24){ APP_MENU_APPLICATIONS_24 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 25
      }else if(i==25){ APP_MENU_APPLICATIONS_25 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 26
      }else if(i==26){ APP_MENU_APPLICATIONS_26 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 27
      }else if(i==27){ APP_MENU_APPLICATIONS_27 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 28
      }else if(i==28){ APP_MENU_APPLICATIONS_28 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 29
      }else if(i==29){ APP_MENU_APPLICATIONS_29 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 30
      }else if(i==30){ APP_MENU_APPLICATIONS_30 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 31
      }else if(i==31){ APP_MENU_APPLICATIONS_31 *app; return ((*app).getParams(type));
    #endif
    }else return 0;
}

void startApp(char num){
  currentApp->onDestroy();
  currentApp = getApp(num);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS -                                    #
    #                                                                                          #
    ############################################################################################
*/


