#define DRIVER_CONTROLS_TOTALBUTTONS 4
#define _millis() millis()
#define DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS 350

unsigned long last_user_activity = _millis();

// Do not change:
bool driver_control_pressed[]      = {false, false, false, false};
unsigned long driver_control_time_pressed[]    = {0, 0, 0, 0};

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, button, 0);
}

void driver_controls_setup(){
  last_user_activity = _millis();
}


void driver_controls_loop(){
    int b1=0, b2=0, b3=0, b4=0;
    
    scanf("%d %d %d %d", &b1, &b2, &b3, &b4);
    //read(b1, b2, b3, b4);

    int digRead[] = {b1,b2,b3,b4};

    for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
        if (digRead[i]){
        last_user_activity = _millis();
        if(driver_control_pressed[i]==false){
            // press start
            driver_control_pressed[i]=true;
            driver_control_time_pressed[i] = _millis();
            onButtonEvent(EVENT_BUTTON_PRESSED, i);
        }else{
            // was pressed
            if(_millis()-driver_control_time_pressed[i]>DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS){
            // long press
            driver_control_time_pressed[i]=-1;
            onButtonEvent(EVENT_BUTTON_LONG_PRESS, i);
            }
        }

        }else{
        if(driver_control_pressed[i]==true){
            // released
            driver_control_pressed[i]=false;
            onButtonEvent(EVENT_BUTTON_RELEASED, i);

        }
        }
    }

}

unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}

void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}
