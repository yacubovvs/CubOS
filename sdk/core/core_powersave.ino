long core_powersave_lastUserAction = 0;

void set_core_powersave_lastUserAction(){
    core_powersave_lastUserAction = millis();
}

void core_powersave_setup(){

}

void core_powersave_loop(){
    if(core_powersave_lastUserAction>millis()) core_powersave_lastUserAction = 0;

    /*
    driver_display_getBrightness()

    get_core_display_brightness()
    get_core_display_brightness_fade()
    get_core_display_time_delay_to_fade()
    get_core_display_time_delay_to_poweroff()
    */

    if(millis() - core_powersave_lastUserAction>get_core_display_time_delay_to_fade()*1000){
        if(millis() - core_powersave_lastUserAction - get_core_display_time_delay_to_fade()>get_core_display_time_delay_to_poweroff()*1000){
            // switch off screen
            //debug("Switch off screen");
            if(driver_display_getBrightness()!=0){
                driver_display_setBrightness(0);
            }
        }else{
            // fade screen
            //debug("Fading screen");
            if(driver_display_getBrightness()!=get_core_display_brightness_fade()){
                if(get_core_display_brightness_fade()<driver_display_getBrightness()){
                    driver_display_setBrightness(driver_display_getBrightness()-1);
                    delay(4);
                }else{
                    driver_display_setBrightness(get_core_display_brightness_fade());
                }
            }
        }
    }else{
        //debug("Screen on");
        if(driver_display_getBrightness()!=get_core_display_brightness()){
            driver_display_setBrightness(get_core_display_brightness());
        }

    }

    
}