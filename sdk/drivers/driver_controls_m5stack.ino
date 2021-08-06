#include <M5Stack.h>
#define _millis() millis()

unsigned long last_user_activity = _millis();
// Do not change:
bool driver_control_pressed[]      = {false, false, false};
unsigned char buttons_purpose[] = {BUTTON_UP, BUTTON_SELECT, BUTTON_DOWN};
unsigned long driver_control_time_pressed[]                 = {0, 0, 0};
unsigned long driver_control_DOUBLE_PRESS_lastPress[]       = {0, 0, 0};
unsigned long driver_control_DOUBLE_PRESS_doublePressed[]   = {false, false, false};
unsigned long driver_control_IS_LONG_PRESS[]                = {false, false, false};

void driver_controls_setup(){
  last_user_activity = _millis();
}

void driver_controls_loop(){
    //M5.update();
    //debug(String(i) + " not pressed", 1000);
    //debug("Controls loop ", 1000);

    for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
        if (
            (i==0 && M5.BtnA.isPressed())||
            (i==1 && M5.BtnB.isPressed())||
            (i==2 && M5.BtnC.isPressed())
        ){
        #ifdef POWERSAVE_ENABLE
            //set_core_powersave_lastUserAction();
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

*/
void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0);
}

void onButtonEvent(unsigned char event, int button, int value){
  currentApp->onEvent(event, buttons_purpose[button], value);
}


/*
long driver_controls_m5stack_pressStartBtn_A = 0;
long driver_controls_m5stack_pressStartBtn_B = 0;
long driver_controls_m5stack_pressStartBtn_C = 0;
bool driver_controls_m5stack_LongPressPressed_Btn_A = false;
bool driver_controls_m5stack_LongPressPressed_Btn_B = false;
bool driver_controls_m5stack_LongPressPressed_Btn_C = false;

void driver_controls_setup(){}
void driver_controls_loop(){
    M5.update();

    if(M5.BtnA.wasPressed()){
        driver_controls_m5stack_pressStartBtn_A = MILLIS();
        driver_controls_m5stack_LongPressPressed_Btn_A = false;
        onButtonEvent(EVENT_BUTTON_PRESSED, 0);
    }

    if(M5.BtnB.wasPressed()){
        driver_controls_m5stack_pressStartBtn_B = MILLIS();
        driver_controls_m5stack_LongPressPressed_Btn_B = false;
        onButtonEvent(EVENT_BUTTON_PRESSED, 1);
    }

    if(M5.BtnC.wasPressed()){
        driver_controls_m5stack_pressStartBtn_C = MILLIS();
        driver_controls_m5stack_LongPressPressed_Btn_C = false;
        onButtonEvent(EVENT_BUTTON_PRESSED, 2);
    }

    if(M5.BtnA.wasReleased()) onButtonEvent(EVENT_BUTTON_RELEASED, 0);
    if(M5.BtnB.wasReleased()) onButtonEvent(EVENT_BUTTON_RELEASED, 1);
    if(M5.BtnC.wasReleased()) onButtonEvent(EVENT_BUTTON_RELEASED, 2);

    if(M5.BtnA.isPressed() && MILLIS() - driver_controls_m5stack_pressStartBtn_A > CONTROLS_LONG_PRESS_TIMEOUT && driver_controls_m5stack_LongPressPressed_Btn_A==false){
        driver_controls_m5stack_LongPressPressed_Btn_A = true;
        onButtonEvent(EVENT_BUTTON_LONG_PRESS, 0);
        
        #ifdef toDefaultApp_onLeftLongPress
            startApp(-1);
        #endif
    }

    if(M5.BtnB.isPressed() && MILLIS() - driver_controls_m5stack_pressStartBtn_B > CONTROLS_LONG_PRESS_TIMEOUT && driver_controls_m5stack_LongPressPressed_Btn_B==false){
        driver_controls_m5stack_LongPressPressed_Btn_B = true;
        onButtonEvent(EVENT_BUTTON_LONG_PRESS, 1);
    }

    if(M5.BtnC.isPressed() && MILLIS() - driver_controls_m5stack_pressStartBtn_C > CONTROLS_LONG_PRESS_TIMEOUT && driver_controls_m5stack_LongPressPressed_Btn_C==false){
        driver_controls_m5stack_LongPressPressed_Btn_C = true;
        onButtonEvent(EVENT_BUTTON_LONG_PRESS, 2);
    }
};

bool driver_controls_isPressed(int num){
    switch(num){
        case 0: return M5.BtnA.isPressed();
        case 1: return M5.BtnB.isPressed();
        case 2: return M5.BtnC.isPressed();
        default: return false;
    }
}

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, button, 0);
}
*/
