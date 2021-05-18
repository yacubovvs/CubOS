#ifdef CPU_SLEEP_ENABLE
    void core_cpu_setup(){
        driver_cpu_setup();
        //core_cpu_modemSleep();

        //debug("Should be in sleep!");
    }

    void core_cpu_loop(){
        
        core_cpu_sleep(SLEEP_MODEM);
        /*
        if(millis()/1000>10 && millis()/1000<15)
        driver_cpu_sleep(SLEEP_LIGHT, 10);
        */
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE){
        core_cpu_sleep(SLEEP_TYPE, 0);
    }

    void core_cpu_sleep(unsigned char SLEEP_TYPE, long timeToWakeUp_s){
        driver_cpu_sleep(SLEEP_TYPE, timeToWakeUp_s);
    }
#endif