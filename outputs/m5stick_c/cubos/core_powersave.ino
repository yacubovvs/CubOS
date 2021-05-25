//#define DEBUG_CORE_POWERSAVE

#ifdef POWERSAVE_ENABLE
    long core_powersave_lastUserAction = 0;
    long core_powersave_lastUserAction_tick = 0;

    void set_core_powersave_lastUserAction(){
        core_powersave_lastUserAction = getCurrentSystemTime();
        core_powersave_lastUserAction_tick = millis();
    }

    long getCurrentSystemTime(){
        #ifdef RTC_ENABLE
            long currentSystemTime =  ((long)core_time_getHours_byte())*60*60 + ((long)core_time_getMinutes_byte())*60 + ((long)core_time_getSeconds_byte());
            return currentSystemTime;
            //return millis()/1000;
        #else
            return millis()/1000;
        #endif
    }

    void core_powersave_setup(){
        #ifdef RTC_ENABLE
            driver_RTC_refresh();
        #endif

        set_core_powersave_lastUserAction();
        #ifdef DEBUG_CORE_POWERSAVE
            debug("Sleep modem");
            delay(25);
        #endif

        core_cpu_sleep(SLEEP_MODEM);
    }

    void core_powersave_loop(){
        if(core_powersave_lastUserAction>getCurrentSystemTime()) core_powersave_lastUserAction = 0;
        long timeSincelastUserAction = getCurrentSystemTime() - core_powersave_lastUserAction;
        
        #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
            if(timeSincelastUserAction>=get_core_display_time_delay_to_fade()){
                if(timeSincelastUserAction - get_core_display_time_delay_to_fade()>=get_core_display_time_delay_to_poweroff()){
                    // switch off screen
                    if(driver_display_getBrightness()!=0){
                        driver_display_setBrightness(0);
                    }

                    #ifdef CPU_SLEEP_ENABLE
                        // Going to sleep
                        if(currentApp->preventSleep==false){
                            #ifdef DEBUG_CORE_POWERSAVE
                                debug("Deep sleep");
                                delay(25);
                            #endif
                            core_cpu_sleep(STAND_BY_SLEEP_TYPE);
                        }
                    #endif
                }else{
                    // fade screen
                    #ifdef DEBUG_CORE_POWERSAVE
                        debug("Fade screen");
                        delay(25);
                    #endif
                    if(driver_display_getBrightness()!=get_core_display_brightness_fade()){
                        #ifdef SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE
                        if(get_core_display_brightness_fade()<driver_display_getBrightness()){
                            driver_display_setBrightness(driver_display_getBrightness()-1);
                            delay(SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE);
                        }else{
                            driver_display_setBrightness(get_core_display_brightness_fade());
                        }
                        #else
                            driver_display_setBrightness(get_core_display_brightness_fade());
                        #endif
                    }
                    
                }
            }else{
                if(driver_display_getBrightness()!=get_core_display_brightness()){
                    driver_display_setBrightness(get_core_display_brightness());
                }

            }
        #else
            if(timeSincelastUserAction>=get_core_display_time_delay_to_poweroff()){

                if(driver_display_getBrightness()!=0){
                    driver_display_setBrightness(0);
                }

                #ifdef CPU_SLEEP_ENABLE
                    // Going to sleep
                    if(currentApp->preventSleep==false){
                        #ifdef DEBUG_CORE_POWERSAVE
                            debug("Deep sleep");
                            delay(25);
                        #endif
                        core_cpu_sleep(STAND_BY_SLEEP_TYPE);
                    }
                #endif
            }
        #endif
        
        #ifdef IN_APP_SLEEP_TYPE
            if(currentApp->preventInAppSleep==false){
                /* */
                #ifdef CPU_SLEEP_ENABLE
                    //if(core_powersave_lastUserAction_tick>1000){
                    #if (CONTROLS_DELAY_TO_DOUBLE_CLICK_MS>DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS)
                        if(millis() - core_powersave_lastUserAction_tick>CONTROLS_DELAY_TO_DOUBLE_CLICK_MS+1){
                    #else 
                        if(millis() - core_powersave_lastUserAction_tick>DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS+1){
                    #endif
                        #ifdef DEBUG_CORE_POWERSAVE
                            debug("Light sleep");
                            delay(25);
                        #endif
                        core_cpu_sleep(SLEEP_LIGHT, 1);   
                    }
                #endif
                
                /* */
            }
        #endif
        
    }
#endif