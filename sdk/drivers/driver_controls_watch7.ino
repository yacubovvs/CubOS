#define DRIVER_CONTROLS_TOTALBUTTONS 4
#define _millis() millis()
#define DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS 350

unsigned long last_user_activity = _millis();

byte    driver_control_buttonsPins[]  = {12,   15,    3,    1};
boolean driver_control_isPositive[]   = {true, false, true, true};     
// Do not change:
boolean driver_control_pressed[]      = {false, false, false, false};
unsigned long driver_control_time_pressed[]    = {0, 0, 0, 0};


void driver_controls_setup(){
  for (byte i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    pinMode(driver_control_buttonsPins[i], INPUT);
  }
  last_user_activity = _millis();
}

/*
#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
*/
void driver_controls_loop(){
  for (byte i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    //if (digitalRead(driver_control_buttonsPins[i])){
    if ((driver_control_isPositive[i]==true) ? (!digitalRead(driver_control_buttonsPins[i])) : (digitalRead(driver_control_buttonsPins[i]))){

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

void onButtonEvent(byte event, int button){
  currentApp->onEvent(event, button, 0);
}

/*



//////////////////////////////////////////////////////////////////////////////
//  Call to check is button started to press
boolean isPressStart(byte num){
  if (num>=os_control_buttons) return false;
  else return os_control_pressStart[num];
}

//////////////////////////////////////////////////////////////////////////////
//  Call to check is button [ress finished
boolean isPressEnd(byte num){
  if (num>=os_control_buttons) return false;
  else return os_control_pressEnd[num];
}

//////////////////////////////////////////////////////////////////////////////
//  Call to check is button pressed
boolean isPress(byte num){
  if (num>=os_control_buttons) return false;
  else return os_control_press[num];
}

void os_control_loop(){
  
  for (byte i=0; i<os_control_buttons; i++){
    if (digitalRead(os_control_buttonsAdr[i])){

      last_user_activity = _millis();

      if(os_control_pressStart[i]){
        // 2-nd loop after press
        os_control_pressStart[i]  = false;
      }else{
        if (os_control_press[i]){
          // 3+ loop after press
          // do nothing
        }else{
          // just pressed
          os_control_pressStart[i]  = true;
          os_control_press[i]       = true;
        }
      }
    }else{
      // Not pressed
      if (os_control_press[i]){
        os_control_pressStart[i]  = false;
        os_control_press[i]       = false;
        os_control_pressEnd[i]    = true;
      }else{
        if (os_control_pressEnd[i]){
          // 2-nd loop after press;
          os_control_pressEnd[i] = false;
        }else{
          // Not pressed more 2 loops
          // Do nothing, relax
        }
      }
    }
  }
  
}

//////////////////////////////////////////////////////////////////////////////
//  Events for apps
boolean isPressStart_Right(){
  return isPressStart(0);
}

boolean isPressStart_Select(){
  return isPressStart(2);
}

boolean isPressStart_Left(){
  return isPressStart(1);
}
//
//////////////////////////////////////////////////////////////////////////////
*/