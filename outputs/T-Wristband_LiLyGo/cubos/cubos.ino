/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/

// TOUCH
#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOR_LONG_TOUCH 300

// BUTTONS
#define BUTTON_UP       0x01
#define BUTTON_SELECT   0x02
#define BUTTON_DOWN     0x03
#define BUTTON_BACK     0x04
#define BUTTON_POWER    0x05

#define DRIVER_CONTROLS_TOTALBUTTONS 0
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

#define EVENT_ON_TIME_CHANGED               0x06
#define EVENT_ON_MINUTE_CHANGED             0x14
#define EVENT_ON_HOUR_CHANGED               0x15
#define EVENT_ON_DATE_CHANGED               0x13

// WAKEUP REASONS
#define WAKE_UP_REASON_EXTERNAL_RTC_IO      0x01
#define WAKE_UP_REASON_EXTERNAL_RTC_CNTL    0x02
#define WAKE_UP_REASON_TIMER                0x03
#define WAKE_UP_REASON_TPOUCHPAD            0x04
#define WAKE_UP_REASON_ULP                  0x05
#define WAKE_UP_REASON_NOT_DEEP_SLEEP       0x06

// SOFTWARE_BUTTONS
#define SOFTWARE_BAR_BUTTON_UP              0x0001
#define SOFTWARE_BAR_BUTTON_SELECT          0x0002
#define SOFTWARE_BAR_BUTTON_DOWN            0x0003
#define SOFTWARE_BAR_BUTTON_BACK            0x0004

/*
 ############################################################################
                                 SLEEP TYPES -                               
*/

#define SLEEP_IDLE_CPU                      0x01
#define SLEEP_DEEP                          0x02
#define SLEEP_LIGHT                         0x03
#define SLEEP_MODEM                         0x04
#define SLEEP_DISPLAY                       0x05
#define SLEEP_HIBERNATE                     0x03
#define WAKE_MODEM                          0x06
#define WAKE_DISPLAY                        0x07
#define WAKE                                0x08
#define SLEEP_LIGHT_SCREEN_OFF              0x09
#define SLEEP_LIGHT_ACCELEROMETER_SLEEP     0x0A


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

#define SOFTWARE_BUTTONS_COLOR_RED          255
#define SOFTWARE_BUTTONS_COLOR_GREEN        255
#define SOFTWARE_BUTTONS_COLOR_BLUE         255

#define SOFTWARE_BUTTONS_COLOR_RED_BG       59
#define SOFTWARE_BUTTONS_COLOR_GREEN_BG     35
#define SOFTWARE_BUTTONS_COLOR_BLUE_BG      71

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
// #define SMOOTH_ANIMATION
// #define NARROW_SCREEN

#define UPDATE_BATTERY_EVERY_MS 3000
#define SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE  4
#define BATTERY_ENABLE

// #define ACCELEROMETER_ENABLE
#define DISPLAY_BACKLIGHT_CONTROL_ENABLE
#define DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define WAKEUP_FROM_LIGHT_SLEEP_EVERY_MS 1000
#define WAKEUP_FROM_DEEP_SLEEP_EVERY_SECONDS 60*60*24 // Wake up if no any other background works as pedometer

#define USE_TYPE2_OF_IMAGES
//#define PEDOMETER_ENABLE

//#define PEDOMETER_STEP_DETECTION_DELAY                30000

#define PEDOMETER_DO_NOT_USE_PEDOMETER_WHILE_CONNECTED_TO_USB

//#define PEDOMETER_STEP_DETECTION_DELAY                  1000
#define PEDOMETER_STEP_DETECTION_PERIOD_MS              1000
#define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      5
#define PEDOMETER_ENABLE_ON_START                       true
#define PEDOMETER_DAY_VALUE_TYPE                        uint16_t
#define PEDOMETER_DAYS_HISTORY                          7
#define PEDOMETER_DAY_STEP_LIMMIT_DEFAULT               10000
#define PEDOMETER_DAY_SLEEP_LIMMIT_DEFAULT              7*60 //minutes

#define WAKEUP_FOR_BACKGROUND_WORK_IDLE 1000

//#define DEBUG_PEDOMETER // Just for teste

#define FORCE_DISPLAY_UPDATE_ON_START // Will quick update screen on start and wakeup. Comment on unknown error.
#define DEFAULT_TIME_TO_POWEROFF_DISPLAY 7
#define DEFAULT_DELAY_TO_FADE_DISPLAY 7

//#define DEBUG_SERIAL

#define SOFTWARE_BUTTONS_BAR_SIZE 0
//#define LEGACY_GET_ICONS

#define DEBUG_SERIAL_PORT Serial

#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          10
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         10
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          60 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds

#define CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS   1 // mesures for sleep detection 
#define CORE_PEDOMETER_SLEEP_MIN_ACCELL_100     3 // acceletometer sensitivity/100*G for sleep detection


#define APP_CLOCK_POWER_AFTER_SECONDS           4
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
    #                                   M5STICK SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      USING ESP32 DEV MODULE FOR FLASHING
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

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
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM    1 // Settings
//#define STARTING_APP_NUMM    2 // Pedometer
#define STARTING_APP_NUMM    0

#define FONT_SIZE_DEFAULT   1

#define CPU_SLEEP_ENABLE

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define RTC_ENABLE

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

#define SMOOTH_ANIMATION
#define NARROW_SCREEN

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

//#define SCREEN_INVERT_COLORS
#define SCREEN_CHANGE_BLUE_RED

#define DRIVER_RTC_INTERRUPT_PIN    34

#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
//#define STAND_BY_SLEEP_TYPE     SLEEP_LIGHT_SCREEN_OFF
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP

#undef SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE
#undef DISPLAY_BACKLIGHT_CONTROL_ENABLE

#define SMOOTH_ANIMATION_COEFFICIENT    4

#define ACCELEROMETER_ENABLE
//#define MAGNITOMETER_ENABLE
#define PEDOMETER_ENABLE
//#define DEBUG_PEDOMETER
#undef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define PEDOMETER_STEP_DETECTION_DELAY          20000 // Wake up to check accelerometer
//#define PEDOMETER_STEP_DETECTION_DELAY          1000 // Wake up to check accelerometer
#define DEFAULT_TIME_TO_POWEROFF_DISPLAY        12
#define DEFAULT_DELAY_TO_FADE_DISPLAY           0
#define PEDOMETER_STEP_DETECTION_PERIOD_MS              900
#define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      5
#define PEDOMETER_DAY_STEP_LIMMIT_DEFAULT               10000

#define PEDOMETER_DELTA_VALUE_MIN           0.47f
#define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.17f

#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          20
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         20
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          120 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds

#define CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS   5 // mesures for sleep detection 
#define CORE_PEDOMETER_SLEEP_MIN_ACCELL_100     3 // acceletometer sensitivity/100*G for sleep detection

#define APP_CLOCK_POWER_AFTER_SECONDS           4

//#define DEBUG_SERIAL
//#define DEBUG_PEDOMETER
//#define WAKEUP_DEBUG
//#define DEBUG_DRIVER_BATTERY
/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS -                                     #
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

// PREDEFINITION
void core_views_statusBar_draw();
#ifdef SOFTWARE_BUTTONS_ENABLE
  void core_views_softwareButtons_draw();
#endif
class Application;
Application *getApp(unsigned char i);


/////////////////////////////////////
// APPLICATION CLASS

class Application{
  public:
    int scroll_x                        = 0;
    int scroll_y                        = 0;
    int scroll_to_x                     = 0;
    int scroll_to_y                     = 0;
    unsigned char sleep_device_after    = 0;
    bool isfullScreen                   = true;
    bool showStatusBar                  = true;
    bool preventSleep                   = false;
    bool preventInAppSleep              = false;

    #ifdef SOFTWARE_BUTTONS_ENABLE
      bool showSoftWareButtons = true;
    #endif

    virtual void onLoop()     = 0;
    virtual void onDestroy()  = 0;
    virtual void onEvent(unsigned char event, int val1, int val2) = 0;

    void super_onCreate(){
      this->preventSleep = false;
      this->preventInAppSleep = false;
      if(this->showStatusBar) core_views_statusBar_draw();
      #ifdef SOFTWARE_BUTTONS_ENABLE
        if(this->showSoftWareButtons) core_views_softwareButtons_draw();
      #endif
    }

    Application(){};
};

bool currentAppSetted = false;
Application* currentApp;
/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION OJECT -                                   #
    #                                                                                          #
    ############################################################################################
*/

void setup(){   

  #ifdef DEBUG_SERIAL
      DEBUG_SERIAL_PORT.begin(115200);
      delay(100);
      debug("\n\nSerial debug started " + String(millis()));
  #endif

  #ifdef CORE_SETUP_INIT
    core_setup_driver();
  #endif

  #ifdef POWERSAVE_ENABLE
    #ifdef CPU_SLEEP_ENABLE
      unsigned char wakeUpReason = core_powersave_wakeup_reason();
      if(wakeUpReason==WAKE_UP_REASON_TIMER){
        #ifdef WAKEUP_DEBUG
          debug("WAKEUP_DEBUG: Background start " + String(millis()));
          //core_cpu_setup();
        #endif
        #ifdef PEDOMETER_DO_NOT_USE_PEDOMETER_WHILE_CONNECTED_TO_USB
          #ifdef BATTERY_ENABLE
            driver_battery_setup();
          #endif
        #endif
        core_cpu_setup();
        driver_controls_setup();
        #ifdef WAKEUP_DEBUG
          debug("WAKEUP_DEBUG: Backgroung controls inited "  + String(millis()));
        #endif
        backgroundWorkAfterSleep();
        #ifdef WAKEUP_DEBUG
          debug("WAKEUP_DEBUG: Going to sleep again for " + String(get_corePedometer_currentsleep_between_mesures()) + "ms " + String(millis()));
          delay(50);
        #endif
        core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
      }else{
        #ifdef WAKEUP_DEBUG
          debug("WAKEUP_DEBUG: Not background start", 10);
        #endif
      }
    #endif
  #endif
  //debug("**** Main app start", 10);
  core_display_setup();
  
  #ifdef RTC_ENABLE
      driver_RTC_setup();
  #endif

  #ifdef FORCE_DISPLAY_UPDATE_ON_START
    currentApp = getApp(STARTING_APP_NUMM);
    core_display_loop();
    driver_display_loop();
    currentAppSetted = true;
  #endif

  #ifdef BATTERY_ENABLE
    driver_battery_setup();
  #endif

  #ifdef ESP8266
    ESP.wdtDisable();
  #endif

  #ifdef CPU_CONTROLL_ENABLE
    core_cpu_setup();
  #endif

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

  #ifdef PEDOMETER_ENABLE
    core_pedometer_setup();
  #endif
  
  #ifndef FORCE_DISPLAY_UPDATE_ON_START
    currentApp = getApp(STARTING_APP_NUMM);
    currentAppSetted = true;
  #endif
  
}

bool isInSleep = false;
void loop(){

  #ifdef CORE_SETUP_INIT
    core_loop_driver();
  #endif

  //long t = millis();
  core_display_loop();
  driver_display_loop();
  //t = millis() - t;
  //if(t!=0)debug("FPS: " + String(1000/t));

  #ifdef CPU_CONTROLL_ENABLE
    core_cpu_loop();
  #endif

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

  #ifdef POWERSAVE_ENABLE
    core_powersave_loop();
  #endif

  #ifdef ACCELEROMETER_ENABLE
    driver_accelerometer_loop();
  #endif

  #ifdef PEDOMETER_ENABLE
    //core_pedometer_loop(false);
  #endif

  currentApp->onLoop(); 
  //currentApp->onLoop(); 

  #ifdef ESP8266
    //ESP.wdtDisable();
    ESP.wdtFeed();
  #endif

}

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
      delay(delaytime);
    #endif

    #ifdef DEBUG_ON_SCREEN
      setDrawColor(255, 255, 255);
      drawString(string, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
      delay(delaytime);
      setDrawColor(0, 0, 0);
      drawString(string, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
    #endif
}

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

#define ICON_LEG                    0x17
#define ICON_LEG_GREY               0x18


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
/*
    ############################################################################################
    #                                                                                          #
    #                                       APPLICATIONS +                                     #
    #                                                                                          #
    ############################################################################################
*/

#define APP_MENU_APPLICATIONS_0             ClockApp
#define APP_MENU_APPLICATIONS_1             SettingsApp
#define APP_MENU_APPLICATIONS_2             PedometerApp
#define APP_MENU_APPLICATIONS_3             PedometerAppTest
#define APP_MENU_APPLICATIONS_4             BatteryApp
#define APP_MENU_APPLICATIONS_5             I2CScannerApp

/*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    #                                                                       #
    #                    -->> Add your application here                     #
    #                                                                       #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

/*
#define APP_MENU_APPLICATIONS_5             AppName
#define APP_MENU_APPLICATIONS_6             AppName
#define APP_MENU_APPLICATIONS_7             AppName
#define APP_MENU_APPLICATIONS_8             AppName
#define APP_MENU_APPLICATIONS_9             AppName
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