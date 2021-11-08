
/*
    ############################################################################################
    #                                                                                          #
    #                                   APPLIACATION OJECT +                                   #
    #                                                                                          #
    ############################################################################################
*/

// PREDEFINITION
void core_views_statusBar_draw();
void core_views_draw_active_page(bool draw, int y0, unsigned char pages_quantity, unsigned char position);
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
    virtual void onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5) = 0;

    void onEvent(unsigned char event, int val1, int val2){
      onEvent(event, val1, val2, 0, 0, 0);
    }

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
    #ifndef DO_NOT_INIT_SERIAL
      DEBUG_SERIAL_PORT.begin(115200);
    #endif
    delay(500);
    debug("\n\nSerial debug started " + String(millis()));
  #endif

  #ifdef RUN_BACKGROUND_AFTER_RESTART_MCU
    #ifdef POWERSAVE_ENABLE
      #ifdef CPU_SLEEP_ENABLE
        unsigned char wakeUpReason = core_powersave_wakeup_reason();
        if(wakeUpReason==WAKE_UP_REASON_TIMER){
          #ifdef DEBUG_WAKEUP
            debug("DEBUG_WAKEUP: Background start " + String(millis()));
            //core_cpu_setup();
          #endif
          #ifdef PEDOMETER_DO_NOT_USE_PEDOMETER_WHILE_CONNECTED_TO_USB
            #ifdef BATTERY_ENABLE
              driver_battery_setup();
            #endif
          #endif
          core_cpu_setup();
          driver_controls_setup();
          #ifdef DEBUG_WAKEUP
            debug("DEBUG_WAKEUP: Backgroung controls inited "  + String(millis()));
          #endif

          #ifdef RTC_ENABLE
              driver_RTC_setup();
              core_time_driver_RTC_refresh(true);
          #endif

          #ifdef DEBUG_WAKEUP
              debug("DEBUG_WAKEUP: RTC inited "  + String(millis()), 10);
          #endif

          backgroundWorkAfterSleep();
          #ifdef PEDOMETER_ENABLE
            #ifdef DEBUG_WAKEUP
              debug("DEBUG_WAKEUP: Going to sleep again for " + String(get_corePedometer_currentsleep_between_mesures()) + "ms " + String(millis()));
              delay(50);
            #endif
            #ifdef PEDOMETER_ENABLE
              if(core_pedometer_getEnable()){
                core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
              }else{
                core_cpu_sleep(STAND_BY_SLEEP_TYPE, 24*60*60*1000);// Do not wake up for 1 day 
              }
            #else
              core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
            #endif
          #else
            #ifdef DEBUG_WAKEUP
              debug("DEBUG_WAKEUP: Going to sleep while interrupt");
              delay(50);
              core_cpu_sleep(STAND_BY_SLEEP_TYPE);
            #endif
          #endif
        }else{
          #ifdef DEBUG_WAKEUP
            debug("DEBUG_WAKEUP: Not background start", 10);
          #endif
        }
      #endif
    #endif
  #else
    #ifdef DEBUG_WAKEUP
      debug("DEBUG_WAKEUP: Not background start", 10);
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

  #ifdef TOUCH_SCREEN_ENABLE
    setup_touchScreenCore();
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

  currentApp->onLoop(); 

  #ifdef ESP8266
    //ESP.wdtDisable();
    ESP.wdtFeed();
  #endif

  #ifndef RUN_BACKGROUND_AFTER_RESTART_MCU
    core_pedometer_loop(false);
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
      Serial.flush();
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
