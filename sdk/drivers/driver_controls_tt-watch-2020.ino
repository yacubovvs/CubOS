
#define DRIVER_CONTROLL_DEBUG
#define _millis() millis()
//#define TP_PWR_PIN          25


// unsigned long last_user_activity = _millis();
unsigned long last_user_buttons_activity = _millis();

unsigned char buttons_purpose[]                             = {BUTTON_POWER};

unsigned long driver_control_time_pressed[]                 = {0};
unsigned long driver_control_DOUBLE_PRESS_lastPress[]       = {0};
unsigned long driver_control_DOUBLE_PRESS_doublePressed[]   = {false};
unsigned long driver_control_IS_LONG_PRESS[]                = {false};

TTGOClass *watch_controlls;

void driver_controls_setup(){
  last_user_activity = _millis();
}

bool isDoubleOrSinglePressed = true;

void driver_controls_loop(){
  if(get_core_driver_isLongPressed()){
    onButtonEvent(EVENT_BUTTON_PRESSED, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_PRESSED");
    #endif
    onButtonEvent(EVENT_BUTTON_LONG_PRESS, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_LONG_PRESS");
    #endif
    onButtonEvent(EVENT_BUTTON_RELEASED, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_RELEASED");
    #endif
  }

  if (get_core_driver_isShortPressed()){
    isDoubleOrSinglePressed = false;
    watch_controlls->power->clearIRQ();

    #ifdef POWERSAVE_ENABLE
      set_core_powersave_lastUserAction();
    #endif
    
    onButtonEvent(EVENT_BUTTON_PRESSED, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_PRESSED");
    #endif
    
    if(_millis() - last_user_buttons_activity<CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
      onButtonEvent(EVENT_ON_TOUCH_DOUBLE_PRESS, 0, _millis() - last_user_activity);
      isDoubleOrSinglePressed = true;
      #ifdef DRIVER_CONTROLL_DEBUG
        debug("EVENT_ON_TOUCH_DOUBLE_PRESS " + String(_millis() - last_user_buttons_activity));
      #endif
    }

    onButtonEvent(EVENT_BUTTON_SHORT_PRESS, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_SHORT_PRESS");
    #endif

    onButtonEvent(EVENT_BUTTON_RELEASED, 0);
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_RELEASED");
    #endif
    
    last_user_buttons_activity = _millis();
    last_user_activity = _millis();
  }

  if(isDoubleOrSinglePressed==false && _millis() - last_user_buttons_activity>=CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
    onButtonEvent(EVENT_BUTTON_SHORT_SINGLE_PRESS, 0);
    isDoubleOrSinglePressed=true;
    #ifdef DRIVER_CONTROLL_DEBUG
      debug("EVENT_BUTTON_SHORT_SINGLE_PRESS " + String(_millis() - last_user_buttons_activity));
    #endif
    
  }

}

/*unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}

*/void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0);
}

void onButtonEvent(unsigned char event, int button, int value){
  currentApp->onEvent(event, buttons_purpose[button], value);
}
