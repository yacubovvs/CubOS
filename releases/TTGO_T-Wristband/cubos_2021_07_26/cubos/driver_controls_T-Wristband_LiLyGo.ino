#define _millis() millis()
#define TP_PWR_PIN          25


// unsigned long last_user_activity = _millis();

unsigned char    driver_control_buttonsPins[]  = {33};
bool driver_control_isPositive[]   = {false};
// Do not change:
bool driver_control_pressed[]      = {false};
byte buttons_purpose[] = {BUTTON_SELECT};
unsigned long driver_control_time_pressed[]                 = {0};
unsigned long driver_control_DOUBLE_PRESS_lastPress[]       = {0};
unsigned long driver_control_DOUBLE_PRESS_doublePressed[]   = {false};
unsigned long driver_control_IS_LONG_PRESS[]                = {false};

void driver_controls_setup(){
  pinMode(TP_PWR_PIN, PULLUP);
  pinMode(RTC_INT_PIN, INPUT_PULLUP);
  digitalWrite(TP_PWR_PIN, HIGH);
  
  for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    pinMode(driver_control_buttonsPins[i], INPUT);
  }
  //last_user_activity = _millis();
}

/*
#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
*/
void driver_controls_loop(){
  for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    //if (digitalRead(driver_control_buttonsPins[i])){
    if ((driver_control_isPositive[i]==true) ? (!digitalRead(driver_control_buttonsPins[i])) : (digitalRead(driver_control_buttonsPins[i]))){

      set_core_powersave_lastUserAction();
      //last_user_activity = _millis();
      if(driver_control_pressed[i]==false){
        // press start
        driver_control_pressed[i]=true;
        driver_control_time_pressed[i] = _millis();
        //set_core_powersave_lastUserAction();
        onButtonEvent(EVENT_BUTTON_PRESSED, i);
        //debug("EVENT_BUTTON_PRESSED");
        if(driver_control_DOUBLE_PRESS_lastPress[i]!=0){
          if(_millis() - driver_control_DOUBLE_PRESS_lastPress[i]<CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
            driver_control_DOUBLE_PRESS_doublePressed[i] = true;
            onButtonEvent(EVENT_ON_TOUCH_DOUBLE_PRESS, i, _millis() - driver_control_DOUBLE_PRESS_lastPress[i]);
          }
        }else{
          driver_control_DOUBLE_PRESS_lastPress[i] = millis();
        }
          
      }else{
        // was pressed
        if(driver_control_time_pressed[i]!=0 && _millis()-driver_control_time_pressed[i]>DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS){
          // long press
          driver_control_time_pressed[i]=0;
          driver_control_DOUBLE_PRESS_lastPress[i]=0;
          onButtonEvent(EVENT_BUTTON_LONG_PRESS, i);
          driver_control_IS_LONG_PRESS[i]=true;
        } 
      }

      
    }else{
      
      if(driver_control_pressed[i]==true){
        // released
        driver_control_pressed[i]=false;
        //set_core_powersave_lastUserAction();
        onButtonEvent(EVENT_BUTTON_RELEASED, i);
        //debug("EVENT_BUTTON_RELEASED");
        
        if(driver_control_IS_LONG_PRESS[i]==false && driver_control_DOUBLE_PRESS_doublePressed[i]==false){
          onButtonEvent(EVENT_BUTTON_SHORT_PRESS, i);
        }
        
        driver_control_IS_LONG_PRESS[i]=false;
      }
    }

    if(driver_control_DOUBLE_PRESS_lastPress[i]!=0 && _millis() - driver_control_DOUBLE_PRESS_lastPress[i]>CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
      if(driver_control_DOUBLE_PRESS_doublePressed[i] == false){
        if(driver_control_pressed[i]==false)onButtonEvent(EVENT_BUTTON_SHORT_SINGLE_PRESS, i);
      }else driver_control_DOUBLE_PRESS_doublePressed[i] = false;
      driver_control_DOUBLE_PRESS_lastPress[i]=0;
    }
  }

}


void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0);
}

void onButtonEvent(unsigned char event, int button, int value){
  currentApp->onEvent(event, buttons_purpose[button], value);
}
