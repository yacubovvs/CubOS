#ifdef CPU_SLEEP_ENABLE
    void core_cpu_setup(){
        driver_cpu_setup();
        //core_cpu_modemSleep();

        //debug("Should be in sleep!");
    }

    void core_cpu_loop(){
        if(millis()/1000>10 && millis()/1000<15)
        driver_cpu_sleep(SLEEP_LIGHT, 10);
    }

    void core_cpu_modemSleep(){
        driver_cpu_sleep(SLEEP_MODEM, 0);
    }
#endif