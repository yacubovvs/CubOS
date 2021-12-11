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
            String sleepTypeText;

            switch (SLEEP_TYPE){
                case SLEEP_IDLE_CPU:
                    sleepTypeText = "SLEEP_IDLE_CPU"; break;
                case SLEEP_DEEP:
                    sleepTypeText = "SLEEP_DEEP"; break;
                case SLEEP_LIGHT:
                    sleepTypeText = "SLEEP_LIGHT"; break;
                case SLEEP_MODEM:
                    sleepTypeText = "SLEEP_MODEM"; break;
                case SLEEP_DISPLAY:
                    sleepTypeText = "SLEEP_DISPLAY"; break;
                case SLEEP_HIBERNATE:
                    sleepTypeText = "SLEEP_HIBERNATE"; break;
                case WAKE_MODEM:
                    sleepTypeText = "WAKE_MODEM"; break;
                case WAKE_DISPLAY:
                    sleepTypeText = "WAKE_DISPLAY"; break;
                case WAKE:
                    sleepTypeText = "WAKE"; break;
                case SLEEP_LIGHT_SCREEN_OFF:
                    sleepTypeText = "SLEEP_LIGHT_SCREEN_OFF"; break;
                case SLEEP_LIGHT_ACCELEROMETER_SLEEP:
                    sleepTypeText = "SLEEP_LIGHT_ACCELEROMETER_SLEEP"; break;
                
                default:
                    sleepTypeText = "UNKNOWN"; break;
            }
            debug("DEBUG_CPU_CONTROLL_ENABLE: going to sleep " + sleepTypeText + " for " + String(timeToWakeUp_s), 25);
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