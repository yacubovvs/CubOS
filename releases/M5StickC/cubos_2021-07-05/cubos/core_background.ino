void backgroundWorkAfterSleep(){

    #ifdef RTC_ENABLE
        driver_RTC_setup();
        core_time_driver_RTC_refresh(true);
    #endif

    #ifdef WAKEUP_DEBUG
        debug("RTC inited "  + String(millis()), 10);
    #endif

    #ifdef PEDOMETER_ENABLE

        // Starting pedometer in background while sleeping
        
        core_pedometer_setup();

        #ifdef WAKEUP_DEBUG
          debug("Pedometer setup finished "  + String(millis()), 10);
        #endif

        core_pedometer_loop(true);
        #ifdef WAKEUP_DEBUG
          debug("Pedometer loop finish finished "  + String(millis()), 10);
        #endif
    #endif
}

