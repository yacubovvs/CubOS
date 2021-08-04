//#define DEBUG_CPU_CONTROLL_ENABLE
#ifdef CPU_CONTROLL_ENABLE
    void core_cpu_setup(){
        driver_cpu_setup();

        #ifdef ACCELEROMETER_ENABLE
        #endif
        //core_cpu_modemSleep();

        //debug("Should be in sleep!");
    }

    void core_cpu_loop(){
        driver_cpu_loop();
    }
    void core_cpu_sleep(unsigned char SLEEP_TYPE){
        core_cpu_sleep(SLEEP_TYPE, 0, true);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s){
        core_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s, true);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s, bool accelerometer_sleep){
        #ifdef DEBUG_CPU_CONTROLL_ENABLE
            debug("DEBUG_CPU_CONTROLL_ENABLE: going to sleep " + String(SLEEP_TYPE) + " for " + String(timeToWakeUp_s), 25);
        #endif

        #ifdef ACCELEROMETER_ENABLE
            if(accelerometer_sleep) driver_accelerometer_sleep();
        #endif

        driver_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s);
        
        //#ifdef ACCELEROMETER_ENABLE
        //    if(accelerometer_sleep) driver_accelerometer_wakeup();
        //#endif
    }
#endif