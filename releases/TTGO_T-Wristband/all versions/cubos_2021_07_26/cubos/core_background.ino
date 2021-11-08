#define DEBUG_BACKGROUND
void backgroundWorkAfterSleep(){

    #ifdef PEDOMETER_ENABLE
        #ifdef DEBUG_BACKGROUND
          debug("DEBUG_BACKGROUND: PEDOMETER_ENABLE", 10);
        #endif

        // Starting pedometer in background while sleeping
        
        core_pedometer_setup();

        #ifdef DEBUG_BACKGROUND
          debug("DEBUG_BACKGROUND: Pedometer setup finished "  + String(millis()), 10);
        #endif

        core_pedometer_loop(true);
        #ifdef DEBUG_BACKGROUND
          debug("DEBUG_BACKGROUND: Pedometer loop finish finished "  + String(millis()), 10);
        #endif
    #else 
        #ifdef DEBUG_BACKGROUND
          debug("DEBUG_BACKGROUND: PEDOMETER_DISABLE", 10);
        #endif
    #endif
}

