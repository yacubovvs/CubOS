unsigned char core_battery_getPercent(){
    #ifdef BATTERY_ENABLE
        return driver_battery_getPercent();
    #else
        return 0;
    #endif
}

#ifdef BATTERY_ENABLE
    long last_upodate_battery = 0;
    void core_battery_loop(){
        
        TEMPORARILY_DISABLE_LIMITS();

        driver_battery_loop();

        if(millis()-last_upodate_battery>UPDATE_BATTERY_EVERY_MS || millis()<last_upodate_battery){
            last_upodate_battery = millis();
            
            if(currentApp->showStatusBar){
                core_views_draw_statusbar_battery(false, driver_battery_getPercent());
                core_views_draw_statusbar_battery(true, driver_battery_getPercent());
            }
            
        }

        //ICON_BATTERY_100
        TEMPORARILY_RESTORE_LIMITS();
    }
#endif
//
