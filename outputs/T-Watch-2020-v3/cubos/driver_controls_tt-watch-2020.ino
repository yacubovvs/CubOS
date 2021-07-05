#include <LilyGoWatch.h>

#define CRIVER_CONTROLL_DEBUG
#define _millis() millis()
//#define TP_PWR_PIN          25


unsigned long last_user_activity = _millis();

unsigned char    driver_control_buttonsPins[]               = {AXP202_INT};
bool driver_control_isPositive[]                            = {false};
unsigned char buttons_purpose[]                             = {BUTTON_POWER};

// Do not change:
bool driver_control_pressed[]                               = {false};
unsigned long driver_control_time_pressed[]                 = {0};
unsigned long driver_control_DOUBLE_PRESS_lastPress[]       = {0};
unsigned long driver_control_DOUBLE_PRESS_doublePressed[]   = {false};
unsigned long driver_control_IS_LONG_PRESS[]                = {false};


TTGOClass *watch_controlls;

void driver_controls_setup(){
  watch_controlls = TTGOClass::getWatch();
  pinMode(AXP202_INT, INPUT);
  last_user_activity = _millis();
}

/*
#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
*/

void driver_controls_loop(){
  debug("driver_controls_loop");
  for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    //if ((driver_control_isPositive[i]==true) ? (!digitalRead(driver_control_buttonsPins[i])) : (digitalRead(driver_control_buttonsPins[i]))){
    if(!digitalRead(AXP202_INT)){

      #ifdef POWERSAVE_ENABLE
        set_core_powersave_lastUserAction();
      #endif
      
      last_user_activity = _millis();
      if(driver_control_pressed[i]==false){
        // press start
        driver_control_pressed[i]=true;
        driver_control_time_pressed[i] = _millis();
        onButtonEvent(EVENT_BUTTON_PRESSED, i);
        #ifdef CRIVER_CONTROLL_DEBUG
          debug("EVENT_BUTTON_PRESSED");
        #endif

        watch_controlls->power->clearIRQ();

        driver_control_pressed[i]=false;
        onButtonEvent(EVENT_BUTTON_RELEASED, i);
        #ifdef CRIVER_CONTROLL_DEBUG
          debug("EVENT_BUTTON_RELEASED");
        #endif
        
        if(driver_control_IS_LONG_PRESS[i]==false && driver_control_DOUBLE_PRESS_doublePressed[i]==false){
          onButtonEvent(EVENT_BUTTON_SHORT_PRESS, i);
          #ifdef CRIVER_CONTROLL_DEBUG
            debug("EVENT_BUTTON_SHOTRPRESS");
          #endif
        }
        
        driver_control_IS_LONG_PRESS[i]=false;


        if(driver_control_DOUBLE_PRESS_lastPress[i]!=0){
          if(_millis() - driver_control_DOUBLE_PRESS_lastPress[i]<CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
            driver_control_DOUBLE_PRESS_doublePressed[i] = true;
            onButtonEvent(EVENT_ON_TOUCH_DOUBLE_PRESS, i, _millis() - driver_control_DOUBLE_PRESS_lastPress[i]);
            #ifdef CRIVER_CONTROLL_DEBUG
              debug("EVENT_BUTTON_DOUBLE_PRESS");
            #endif
          }
        }else{
          driver_control_DOUBLE_PRESS_lastPress[i] = millis();
        }
          
      }
      
    }

    if(driver_control_DOUBLE_PRESS_lastPress[i]!=0 && _millis() - driver_control_DOUBLE_PRESS_lastPress[i]>CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
      if(driver_control_DOUBLE_PRESS_doublePressed[i] == false){
        if(driver_control_pressed[i]==false){
          onButtonEvent(EVENT_BUTTON_SHORT_SINGLE_PRESS, i);
          #ifdef CRIVER_CONTROLL_DEBUG
            debug("EVENT_BUTTON_SHORT_SINGLE_PRESS");
          #endif
        }
      }else driver_control_DOUBLE_PRESS_doublePressed[i] = false;
      driver_control_DOUBLE_PRESS_lastPress[i]=0;
    }
  }
  
}

unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}

void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0);
}

void onButtonEvent(unsigned char event, int button, int value){
  currentApp->onEvent(event, buttons_purpose[button], value);
}
