#ifdef CPU_CONTROLL_ENABLE
    void core_cpu_setup(){
        driver_cpu_setup();

        #ifdef ACCELEROMETER_ENABLE
        #endif
        //core_cpu_modemSleep();

        //debug("Should be in sleep!");
    }

    void core_cpu_loop(){
    }
    void core_cpu_sleep(unsigned char SLEEP_TYPE){
        core_cpu_sleep(SLEEP_TYPE, 0, true);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s){
        core_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s, true);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s, bool accelerometer_sleep){
        #ifdef ACCELEROMETER_ENABLE
            if(accelerometer_sleep) driver_accelerometer_sleep();
        #endif

        driver_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s);
        
        #ifdef ACCELEROMETER_ENABLE
            if(accelerometer_sleep) driver_accelerometer_wakeup();
        #endif
    }
#endif