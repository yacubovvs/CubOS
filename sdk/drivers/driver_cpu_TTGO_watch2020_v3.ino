#include "WiFi.h"
#include "esp_sleep.h"


void driver_cpu_setup(){
}

void driver_cpu_wakeup(){
}

void driver_cpu_loop(){
}

#define TOUCH_SCREEN_INTERRUPT_PIN GPIO_NUM_38

void driver_cpu_sleep(unsigned char sleepType, long timeout){
    
    switch (sleepType)
    {
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            debug("SLEEP_DEEP!!!");
            //core_driver_ldo_poweroff_deepSleep_test();
            core_driver_ldo_poweroff_deepSleep();
            break;
            /*
            delay(50);
            
            
            if(driver_display_getBrightness()!=0){
                driver_display_setBrightness(0);
            }

            sleep_displayDriver();
            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_sleep();
            #endif


            core_driver_ldo_poweroff_deepSleep();

            //esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
            //esp_sleep_enable_ext0_wakeup(TOUCH_SCREEN_INTERRUPT_PIN, ESP_EXT1_WAKEUP_ANY_HIGH);
            //esp_sleep_enable_ext0_wakeup(TOUCH_SCREEN_INTERRUPT_PIN, LOW);
            //esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
            esp_sleep_enable_ext1_wakeup(GPIO_SEL_38, ESP_EXT1_WAKEUP_ALL_LOW);

            esp_deep_sleep_start();

            if(driver_display_getBrightness()!=100){
                driver_display_setBrightness(100);
            }*/
            
            break;
        case SLEEP_LIGHT_SCREEN_OFF:
            
            //debug("LIGHT_SLEEP_SCREENOFF!!! start");

            core_driver_ldo_poweroff_lightSleep();

            //debug("LIGHT_SLEEP_SCREENOFF!!! finished");
            break;
            /*
            core_driver_openBL();
            
            esp_sleep_enable_ext0_wakeup(TOUCH_SCREEN_INTERRUPT_PIN, LOW);
            esp_light_sleep_start();
            esp_sleep_enable_timer_wakeup(10*1000*1000);

            

            core_driver_closeBL() ;

            break;*/
        case SLEEP_LIGHT:
            //debug("LIGHT_SLEEP!!!");
            
            esp_sleep_enable_timer_wakeup(timeout*1000);

            esp_sleep_enable_ext0_wakeup(TOUCH_SCREEN_INTERRUPT_PIN, LOW);
            esp_light_sleep_start();

            if(driver_display_getBrightness()!=100){
                driver_display_setBrightness(100);
            }
            
            

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
            delay(1);
            break;
        case WAKE_DISPLAY:
            break;
        case WAKE:
            break;
        default:
            break;
    }
}
