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
#define DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS 350

// EVENTS

#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
#define EVENT_BUTTON_SHORT_PRESS        0x03
#define EVENT_ON_TIME_CHANGED           0x04
#define EVENT_ON_GOING_TO_SLEEP         0x05
#define EVENT_ON_WAKE_UP                0x06

#define EVENT_ON_TOUCH_START                0x06
#define EVENT_ON_TOUCH_RELEASED             0x07
#define EVENT_ON_TOUCH_CLICK                0x08
#define EVENT_ON_TOUCH_LONG_PRESS           0x09
#define EVENT_ON_TOUCH_DRAG                 0x0A
#define EVENT_ON_TOUCH_DOUBLE_CLICK         0x0B
#define EVENT_ON_TOUCH_SWIPE_FROM_LEFT      0x0C
#define EVENT_ON_TOUCH_SWIPE_FROM_RIGHT     0x0D
#define EVENT_ON_TOUCH_SWIPE_FROM_TOP       0x0E
#define EVENT_ON_TOUCH_SWIPE_FROM_BOTTOM    0x0F

#define EVENT_BUTTON_DOUBLE_PRESS       0x10

#define I2C_ENABLE
#define CPU_CONTROLL_ENABLE

#define FONT_SIZE_DEFAULT 2
#define HARDWARE_BUTTONS_VALUE 3

#define CONTROLS_DELAY_TO_DOUBLE_CLICK_MS 250
// #define MAIN_MENU_SMOOTH_ANIMATION
// #define NARROW_SCREEN
/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*//*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      FOR ESP8266 USE NONOSSDK 2.2.2 +
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

#define DEBUG_SERIAL

#define SCREEN_WIDTH            80     // Screen resolution width
#define SCREEN_HEIGHT           160     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define PLATFORM_ESP32
#define BLUETOOTH_ENABLED
#define WIFI_ENABLED

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    

#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
#define STARTING_APP_NUMM    1

#define FONT_SIZE_DEFAULT   1

//#define CPU_SLEEP_ENABLE
//#define CPU_SLEEP_TIME_DELAY core_cpu_getCpuSleepTimeDelay()


#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define USE_RTC

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

#define MAIN_MENU_SMOOTH_ANIMATION
#define NARROW_SCREEN

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/

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

    virtual void onLoop()     = 0;
    virtual void onDestroy()  = 0;
    virtual void onEvent(unsigned char event, int val1, int val2) = 0;

    void super_onCreate(){
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

  #ifdef USE_RTC
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
    driver_cpu_setup();
  #endif
  
  driver_display_setup();
  core_display_setup();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_setup();
  #endif

  #ifdef TOUCH_SCREEN_ENABLE
    setup_touchScreenDriver();
  #endif
  
  currentApp = getApp(STARTING_APP_NUMM);
  
}

bool isInSleep = false;
void loop(){
  driver_display_loop();
  core_display_loop();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_loop();
  #endif

  #ifdef TOUCH_SCREEN_ENABLE
    //loop_touchScreenDriver();
    loop_touchScreenCore();
  #endif

  #ifdef BATTERY_ENABLE
    driver_battery_loop();
  #endif

  #ifdef CLOCK_ENABLE
    core_time_loop();
  #endif

  currentApp->onLoop(); 
  //currentApp->onLoop(); 

  #ifdef ESP8266
    //ESP.wdtDisable();
    ESP.wdtFeed();
  #endif

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


}

#ifdef CPU_SLEEP_ENABLE
  void do_cpu_sleep(){
      driver_cpu_sleep();
  }
#endif

void debug(String string){
  debug(string, 0);
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

#define ICON_BATTERY_100            0x06
#define ICON_BATTERY_90             0x07
#define ICON_BATTERY_80             0x08
#define ICON_BATTERY_70             0x09
#define ICON_BATTERY_60             0x0A
#define ICON_BATTERY_50             0x0B
#define ICON_BATTERY_40             0x0C
#define ICON_BATTERY_30             0x0D
#define ICON_BATTERY_20             0x0E
#define ICON_BATTERY_10             0x0F
#define ICON_BATTERY_0              0x10

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

/*
    ############################################################################################
    #                                                                                          #
    #                                       APPLICATIONS +                                     #
    #                                                                                          #
    ############################################################################################
*/

#define APP_MENU_APPLICATIONS_0             ClockApp
#define APP_MENU_APPLICATIONS_1             SettingsApp
#define APP_MENU_APPLICATIONS_2             CompassApp
#define APP_MENU_APPLICATIONS_3             I2CScannerApp
#define APP_MENU_APPLICATIONS_4             AlarmApp
#define APP_MENU_APPLICATIONS_5             SimpleGameApp
#define APP_MENU_APPLICATIONS_6             TestApplicationApp
#define APP_MENU_APPLICATIONS_7             BatteryApp

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                       #
    #                    -->> Add your application here                     #
    #                                                                       #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

/*
#define APP_MENU_APPLICATIONS_10            AppName
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