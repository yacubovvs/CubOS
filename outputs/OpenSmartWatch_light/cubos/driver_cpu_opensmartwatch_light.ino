#include "WiFi.h"
#include "esp_sleep.h"

#define ALL_BUTTONS_WAKEUP_MASK 0x1401 //(GPIO00 + GPIO10 + GPIO13)

void driver_cpu_setup(){
    //esp_sleep_enable_ext1_wakeup(1, ESP_EXT1_WAKEUP_ANY_HIGH);
}

void driver_cpu_wakeup(){
}

void driver_cpu_poweroff(){}

void driver_cpu_loop(){
}

void driver_cpu_sleep(unsigned char sleepType, long timeout_ms){
    
    switch (sleepType){
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            core_driver_cpu_displayoff_lightSleep();
            /*
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_sleep();
                //driver_accelerometer_wakeup();
            #endif

            startApp(0); // Start clock app
            powerOff_displayDriver();

            esp_sleep_enable_timer_wakeup(timeout_ms*1000);
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, HIGH);
            esp_light_sleep_start();
            //esp_deep_sleep_start();

            powerOn_displayDriver();
            
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_wakeup();
                //delay(100)
            #endif
            */
            break;

        case SLEEP_LIGHT_SCREEN_OFF:
            break;
        case SLEEP_LIGHT:
            
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_sleep();
                //driver_accelerometer_wakeup();
            #endif

            #ifndef MIDDLE_LIGHTSLEEP_WAKERUP_DELAY
                #define MIDDLE_LIGHTSLEEP_WAKERUP_DELAY 150
            #endif

            for (long timer=0; timer<timeout_ms/MIDDLE_LIGHTSLEEP_WAKERUP_DELAY; timer++){
                esp_sleep_enable_timer_wakeup(MIDDLE_LIGHTSLEEP_WAKERUP_DELAY*1000);
                esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, HIGH);
                esp_light_sleep_start();

                if(
                    !digitalRead(0) ||
                    digitalRead(10) ||
                    digitalRead(13)
                ){      
                    driver_controls_loop();
                    break;
                }
            }

            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_wakeup();
                //delay(100)
            #endif
            
            break;
        case SLEEP_MODEM:
            WiFi.disconnect();
            //WiFi.forceSleepBegin();
            WiFi.mode(WIFI_OFF);
            btStop();

            break;
        case SLEEP_DISPLAY:
            break;
        case WAKE_MODEM:
            //WiFi.forceSleepEnd();
            //delay(1);
            break;
        case WAKE_DISPLAY:
            break;
        case WAKE:
            break;
        default:
            break;
    }
}

void core_driver_cpu_displayoff_lightSleep(){
    #ifdef DEBUG_WAKEUP
        debug("Getting in a sleep cycle"); 
    #endif

    //core_driver_setBrigtness(0);
    powerOff_displayDriver();
    
    startApp(0); // start clock surface
    core_display_loop();
    driver_display_loop();

    esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, HIGH);
    
    // Time between mesures
    while(true){

        if(core_pedometer_getEnable()){
            esp_sleep_enable_timer_wakeup(get_corePedometer_currentsleep_between_mesures()*1000*1000);
        }else{
            esp_sleep_enable_timer_wakeup(1000*1000*1000);
        }


        if(get_pedometer_in_work()){
            #ifdef DEBUG_WAKEUP
                debug("!!!!!! Pedometer is in work ! Sleeping for " + String(PEDOMETER_STEP_DETECTION_PERIOD_MS/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD), 5);
            #endif
            esp_sleep_enable_timer_wakeup(PEDOMETER_STEP_DETECTION_PERIOD_MS/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD*1000);
        }else{
            #ifdef DEBUG_WAKEUP
                debug("!!!!!! Pedometer is not in work! Sleeping for " + String(get_corePedometer_currentsleep_between_mesures()*1000), 5);
            #endif

            if(core_pedometer_getEnable()){
                esp_sleep_enable_timer_wakeup(get_corePedometer_currentsleep_between_mesures()*1000*1000);
            }else{
                esp_sleep_enable_timer_wakeup(1000*1000*1000);
            }
            
        }
        
        //get_pedometer_in_work()

        if(core_pedometer_current_get_isNotInMesure()) driver_accelerometer_sleep();
        esp_light_sleep_start();   
        unsigned char wakeUpReason = core_powersave_wakeup_reason();
        if(wakeUpReason==WAKE_UP_REASON_TIMER){
            #ifdef DEBUG_WAKEUP
                //debug("DEBUG_WAKEUP: wake up by timer " + String(WAKE_UP_REASON_TIMER), 10);
            #endif
            #ifdef RTC_ENABLE
                core_time_driver_RTC_refresh();
            #endif
            core_pedometer_loop(false);
        }else{
            #ifdef DEBUG_WAKEUP
                //debug("DEBUG_WAKEUP: Interrupt wakeup " + String(WAKE_UP_REASON_TIMER), 10);
            #endif
            set_core_powersave_lastUserAction();
            break;
        }

        //
    }
    
    #ifdef DEBUG_WAKEUP
        debug("Going out of sleep");
    #endif

    powerOn_displayDriver();
    //core_driver_setBrigtness(255);
    set_core_powersave_lastUserAction();
}