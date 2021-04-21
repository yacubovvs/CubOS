

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

#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
#define EVENT_ON_TIME_CHANGED           0x03
#define EVENT_ON_GOING_TO_SLEEP         0x04
#define EVENT_ON_WAKE_UP                0x05

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

    void loop_app(){
      onLoop();
      

      #ifdef noAnimation
        scroll_x = scroll_to_x;
        scroll_y = scroll_to_y;
      #else
        int dy=0; int dx =0;
  
        if(scroll_x!=scroll_to_x){
          dx = abs(scroll_x-scroll_to_x)/5 + 2;
          if(scroll_x>scroll_to_x) dx *= -1;
          scroll_x+=dx;
  
          if (abs(scroll_x-scroll_to_x)<abs(dx)) scroll_to_x=scroll_x;
        }
  
        if(scroll_y!=scroll_to_y){
          dy = abs(scroll_y-scroll_to_y)/5 + 2;
          if(scroll_y>scroll_to_y) dy *= -1;
          scroll_y+=dy;
      
          if (abs(scroll_y-scroll_to_y)<abs(dy)) scroll_y=scroll_to_y;
        }

        //Serial.println(scroll_to_y);
      #endif
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

void setup()
{ 
  #ifdef BATTERY_ENABLE
    driver_battery_setup();
  #endif

  #ifdef USE_RTC
      driver_RTC_setup();
  #endif

  #ifdef serialDebug
      Serial.begin(115200);
      debug("Serial debug started");
  #endif

  #ifdef ESP8266
      ESP.wdtDisable();
  #endif

  #ifdef CPU_CONTROLL_ENABLE
    driver_cpu_setup();
  #endif
  
  setup_displayDriver();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_setup();
  #endif
  
  currentApp = getApp(STARTING_APP_NUMM);
  
}

bool isInSleep = false;
void loop(){
  driver_display_loop();

  #ifdef HARDWARE_BUTTONS_ENABLED
    driver_controls_loop();
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

    #ifdef serialDebug
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

