
#ifdef POWERSAVE_ENABLE

    unsigned char core_powersave_wakeup_reason(){
        esp_sleep_wakeup_cause_t wakeup_reason;
        wakeup_reason = esp_sleep_get_wakeup_cause();
        switch(wakeup_reason)
        {
            case 1  : return WAKE_UP_REASON_EXTERNAL_RTC_IO;
            case 2  : return WAKE_UP_REASON_TPOUCHPAD;
            case 3  :  return WAKE_UP_REASON_EXTERNAL_RTC_CNTL;
            case 4  : return WAKE_UP_REASON_TIMER;
            case 5  :  return WAKE_UP_REASON_ULP;
            default :  return WAKE_UP_REASON_NOT_DEEP_SLEEP;
        }
    }

    long core_powersave_lastUserAction = 0;
    long core_powersave_lastUserAction_tick = 0;

    long get_core_powersave_lastUserAction(){
        return core_powersave_lastUserAction;
    }


    void set_core_powersave_lastUserAction(){
        /*
        #ifdef DEBUG_CORE_POWERSAVE
            debug("DEBUG_CORE_POWERSAVE: Setting core_powersave_lastUserAction");
        #endif
        */
        core_powersave_lastUserAction = getCurrentSystemTime();
        core_powersave_lastUserAction_tick = millis();
    }

    void core_powersave_setup(){
        #ifdef RTC_ENABLE
            core_time_driver_RTC_refresh();
        #endif

        set_core_powersave_lastUserAction();
        #ifdef DEBUG_CORE_POWERSAVE
            debug("DEBUG_CORE_POWERSAVE: Sleep modem");
            delay(25);
        #endif

        core_cpu_sleep(SLEEP_MODEM);
    }

    void core_powersave_loop(){
        if(core_powersave_lastUserAction>getCurrentSystemTime()){
            core_powersave_lastUserAction = 0;
            #ifdef DEBUG_CORE_POWERSAVE
                debug("DEBUG_CORE_POWERSAVE: reseting core_powersave_lastUserAction");
            #endif
        }
        long timeSincelastUserAction = getCurrentSystemTime() - core_powersave_lastUserAction;
        bool sleepByAppSetting = (currentApp->sleep_device_after!=0) && timeSincelastUserAction>=currentApp->sleep_device_after;

        #ifdef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE    

            if(timeSincelastUserAction>=get_core_display_time_delay_to_fade() || sleepByAppSetting){
                if(
                    timeSincelastUserAction - get_core_display_time_delay_to_fade()>=get_core_display_time_delay_to_poweroff()
                    || sleepByAppSetting
                  ){
                    /*
                    #ifdef DEBUG_CORE_POWERSAVE
                        debug("DEBUG_CORE_POWERSAVE: time to sleep no fade");
                    #endif
                    */
                    
                    #ifdef CPU_SLEEP_ENABLE
                        // Going to sleep
                        if(currentApp->preventSleep==false){
                            // switch off screen
                            if(driver_display_getBrightness()!=0){
                                driver_display_setBrightness(0);
                            }
                            
                            #ifdef DEBUG_CORE_POWERSAVE
                                debug("DEBUG_CORE_POWERSAVE: Deep sleep 1 ", 25);
                            #endif
                            #ifdef PEDOMETER_ENABLE
                                if(core_pedometer_getEnable()){
                                    core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
                                }else{
                                    core_cpu_sleep(STAND_BY_SLEEP_TYPE, 24*60*60*1000);// Do not wake up for 1 day 
                                }
                            #else
                                core_cpu_sleep(STAND_BY_SLEEP_TYPE, 24*60*60*1000);// Do not wake up for 1 day 
                            #endif
                        }
                    #endif
                }else{
                    // fade screen
                    
                    if(driver_display_getBrightness()!=get_core_display_brightness_fade()){
                        #ifdef DEBUG_CORE_POWERSAVE
                            debug("DEBUG_CORE_POWERSAVE: Fading screen");
                        #endif
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
                    #ifdef DEBUG_CORE_POWERSAVE
                        debug("DEBUG_CORE_POWERSAVE: Changing sceren brightness");
                    #endif
                    driver_display_setBrightness(get_core_display_brightness());
                }
            }
        #else
            if(
                timeSincelastUserAction>=get_core_display_time_delay_to_poweroff()
                || sleepByAppSetting
                ){

                #ifdef CPU_SLEEP_ENABLE
                    // Going to sleep
                    if(currentApp->preventSleep==false){
                        // switch off screen
                        if(driver_display_getBrightness()!=0){
                            driver_display_setBrightness(0);
                        }
                        
                        #ifdef DEBUG_CORE_POWERSAVE
                            debug("DEBUG_CORE_POWERSAVE: Deep sleep 2 ", 25);
                        #endif
                        #ifdef PEDOMETER_ENABLE
                            if(core_pedometer_getEnable()){
                                core_cpu_sleep(STAND_BY_SLEEP_TYPE, get_corePedometer_currentsleep_between_mesures()*1000);
                            }else{
                                core_cpu_sleep(STAND_BY_SLEEP_TYPE, 24*60*60*1000);// Do not wake up for 1 day 
                            }
                        #else
                            core_cpu_sleep(STAND_BY_SLEEP_TYPE);
                        #endif
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
                            //debug("DEBUG_CORE_POWERSAVE: timeSincelastUserAction " + String(timeSincelastUserAction));
                        #endif

                        #ifdef DEBUG_CORE_POWERSAVE
                            debug("DEBUG_CORE_POWERSAVE: Light sleep", 25);
                        #endif
                        core_cpu_sleep(IN_APP_SLEEP_TYPE, WAKEUP_FOR_BACKGROUND_WORK_IDLE);   
                    }
                #endif
                
                /* */
            }
        #endif
        
    }
#endif