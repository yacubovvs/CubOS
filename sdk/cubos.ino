
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
    int scroll_x              = 0;
    int scroll_y              = 0;
    int scroll_to_x           = 0;
    int scroll_to_y           = 0;
    bool isfullScreen         = true;
    bool showStatusBar        = true;
    bool preventSleep         = false;
    bool preventInAppSleep    = false;

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
  #ifdef CORE_SETUP_INIT
    core_setup_driver();
  #endif

  #ifdef DEBUG_SERIAL
      DEBUG_SERIAL_PORT.begin(115200);
      delay(100);
      debug("Serial debug started", 10);
  #endif

  #ifdef POWERSAVE_ENABLE
    #ifdef CPU_SLEEP_ENABLE
      unsigned char wakeUpReason = core_powersave_wakeup_reason();
      if(wakeUpReason==WAKE_UP_REASON_TIMER){
        #ifdef WAKEUP_DEBUG
          debug("Background start " + String(millis()), 10);
          //core_cpu_setup();
        #endif
        core_cpu_setup();
        driver_controls_setup();
        #ifdef WAKEUP_DEBUG
          debug("Backgroung controls inited "  + String(millis()), 10);
        #endif
        backgroundWorkAfterSleep();
        #ifdef WAKEUP_DEBUG
          debug("Going to sleep again "  + String(millis()), 10);
        #endif
        core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
      }else{
        #ifdef WAKEUP_DEBUG
          debug("Not background start", 10);
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
