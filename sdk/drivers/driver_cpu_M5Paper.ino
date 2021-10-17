#ifdef CPU_CONTROLL_ENABLE
    #include "esp_sleep.h"
    #include <M5EPD.h>
    // #include <M5Stack.h>
    #include <WiFi.h>

    void driver_cpu_poweroff(){
        pinMode(M5EPD_MAIN_PWR_PIN, OUTPUT);
        M5.shutdown();
        M5.disableMainPower();
        digitalWrite(M5EPD_MAIN_PWR_PIN, 0);
    }

    void driver_cpu_setup(){
        //M5.begin();
    }

    void driver_cpu_loop(){
        //M5.update();
    }

    void driver_cpu_wakeup(){

    }

    void driver_cpu_sleep(unsigned char sleepType, long timeout_ms){
        
        switch (sleepType)
        {
            case SLEEP_IDLE_CPU:
                break;
            case SLEEP_DEEP:
                startApp(0); // Start clock app
                
                driver_display_loop();
                while(true){
                    #define TIME_TO_SLEEP ((60 - core_time_getSeconds_byte()))
                    //debug("Going to deep sleep " + String(TIME_TO_SLEEP) + " seconds");
                    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*1000*1000);
                    esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, LOW);
                    esp_light_sleep_start();

                    if(!digitalRead(36)) break;
                    
                    core_time_driver_RTC_refresh(true);
                    core_battery_loop();
                    currentApp->onEvent(EVENT_ON_TIME_CHANGED, 0, 0);
                }
                //debug("Wake up from deep sleep");

                break;
            case SLEEP_LIGHT:
                //delay(200);
                
                //debug("Going to sleep");
                //Serial.flush();

                driver_controls_loop();
                driver_display_loop();

                //#define MIDDLE_LIGHTSLEEP_WAKERUP_DELAY 200
                #ifndef MIDDLE_LIGHTSLEEP_WAKERUP_DELAY
                    #define MIDDLE_LIGHTSLEEP_WAKERUP_DELAY 150
                #endif

                for (long timer=0; timer<timeout_ms/MIDDLE_LIGHTSLEEP_WAKERUP_DELAY; timer++){
                    //debug("Middle sleep");
                    //Serial.flush();
                    esp_sleep_enable_timer_wakeup(MIDDLE_LIGHTSLEEP_WAKERUP_DELAY*1000);
                    esp_sleep_enable_ext0_wakeup(GPIO_NUM_36, LOW);
                    esp_light_sleep_start();

                    if(
                        !digitalRead(37) ||
                        !digitalRead(38) ||
                        !digitalRead(39)
                    ){
                        //debug("BUTTON INTERRUPT WAKEUP");        
                        driver_controls_loop();
                        driver_display_loop();
                        break;
                    }
                    //debug("Middle wakeup");
                }
                //debug("Wake up");

                break;
            case SLEEP_MODEM:
                //WiFi.disconnect();
                //WiFi.forceSleepBegin();
                WiFi.mode(WIFI_OFF);
                btStop();

                //debug("Set sleep wifi + bt");
                break;
            case SLEEP_DISPLAY:
                //M5.Axp.SetLDO2(false);
                break;
            case WAKE_MODEM:
                //WiFi.forceSleepEnd();
                delay(1);
                break;
            case WAKE_DISPLAY:
                //M5.Axp.SetLDO2(true); 
                break;
            case WAKE:
                //M5.Axp.SetLDO2(true); 
                break;
            default:
                break;
        }
    }
#endif