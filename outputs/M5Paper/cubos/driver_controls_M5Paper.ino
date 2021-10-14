#define _millis() millis()

unsigned long last_user_activity = _millis();
// Do not change:
bool driver_control_pressed[]      = {false, false, false};
unsigned char buttons_purpose[] = {BUTTON_UP, BUTTON_SELECT, BUTTON_DOWN};
unsigned long driver_control_time_pressed[]                 = {0, 0, 0};
unsigned long driver_control_DOUBLE_PRESS_lastPress[]       = {0, 0, 0};
unsigned long driver_control_DOUBLE_PRESS_doublePressed[]   = {false, false, false};
unsigned long driver_control_IS_LONG_PRESS[]                = {false, false, false};
unsigned char driver_control_buttonsPins[]                  = {37,   38,    39};
void driver_controls_setup(){
  last_user_activity = _millis();

  
}

void driver_controls_loop(){
    //M5.update();
    //debug(String(i) + " not pressed", 1000);
    //debug("Controls loop ", 1000);

    for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
        if (
            !digitalRead(driver_control_buttonsPins[i])
        ){
        /*if (
            (i==0 && M5.BtnL.isPressed())||
            (i==1 && M5.BtnP.isPressed())||
            (i==2 && M5.BtnR.isPressed())
        ){*/
        #ifdef POWERSAVE_ENABLE
            set_core_powersave_lastUserAction();
        #endif
        
        last_user_activity = _millis();
        if(driver_control_pressed[i]==false){
            // press start
            driver_control_pressed[i]=true;
            driver_control_time_pressed[i] = _millis();
            //1 set_core_powersave_lastUserAction();
            onButtonEvent(EVENT_BUTTON_PRESSED, i);
            if(driver_control_DOUBLE_PRESS_lastPress[i]!=0){
            if(_millis() - driver_control_DOUBLE_PRESS_lastPress[i]<CONTROLS_DELAY_TO_DOUBLE_CLICK_MS){
                driver_control_DOUBLE_PRESS_doublePressed[i] = true;
                onButtonEvent(EVENT_BUTTON_DOUBLE_PRESS, i, _millis() - driver_control_DOUBLE_PRESS_lastPress[i]);
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
            //debug("Long press " + String(i), 100);
            driver_control_IS_LONG_PRESS[i]=true;
            } 
        }

        
        }else{
        
        if(driver_control_pressed[i]==true){
            // released
            driver_control_pressed[i]=false;
            //1 set_core_powersave_lastUserAction();
            onButtonEvent(EVENT_BUTTON_RELEASED, i);

            
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

/*unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}


void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}
*/

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0, 0, 0, button);
}

void onButtonEvent(unsigned char event, int button, int value){
  currentApp->onEvent(event, buttons_purpose[button], value, 0, 0, button);
}
