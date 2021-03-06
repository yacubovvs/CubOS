

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
  PARAMS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
long last_user_activity = _millis();

// device buttons count
const byte os_control_buttons = 3; 

// Buttons address
const int os_control_buttonsAdr[] = {2, 4, 3};


// Do not change:
boolean os_control_pressStart[] = {false, false, false};
boolean os_control_pressEnd[]   = {false, false, false};
boolean os_control_press[]      = {false, false, false};

long os_control_get_last_user_avtivity(){
  return last_user_activity;
}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
  HENDLER
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/

void os_control_setup(){
  
  for (byte i=0; i<os_control_buttons; i++){
    pinMode(os_control_buttonsAdr[i], INPUT);
    //digitalWrite(os_control_buttonsAdr[i], HIGH);
  }
  
}

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