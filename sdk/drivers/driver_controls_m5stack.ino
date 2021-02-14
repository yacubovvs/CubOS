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

void onButtonEvent(byte event, int button){
  currentApp->onEvent(event, button, 0);
}
*/
