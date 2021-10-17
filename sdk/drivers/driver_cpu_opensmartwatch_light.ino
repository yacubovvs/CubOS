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
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_sleep();
                //driver_accelerometer_wakeup();
            #endif

            startApp(0); // Start clock app
            powerOff_displayDriver();

            esp_sleep_enable_timer_wakeup(timeout_ms*1000);
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, HIGH);
            //esp_light_sleep_start();
            esp_deep_sleep_start();

            powerOn_displayDriver();
            
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_wakeup();
                //delay(100)
            #endif
            
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