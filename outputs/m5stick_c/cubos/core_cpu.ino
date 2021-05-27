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
        core_cpu_sleep(SLEEP_TYPE, 0);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s){
        driver_accelerometer_sleep();
        driver_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s);
        driver_accelerometer_wakeup();
    }
#endif