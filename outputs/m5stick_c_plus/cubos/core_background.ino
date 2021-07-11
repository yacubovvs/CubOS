void backgroundWorkAfterSleep(){

    #ifdef RTC_ENABLE
        driver_RTC_setup();
        core_time_driver_RTC_refresh(true);
    #endif

    #ifdef PEDOMETER_ENABLE

        // Starting pedometer in background while sleeping
        
        core_pedometer_setup();;
        core_pedometer_loop(true);
    #endif
}

