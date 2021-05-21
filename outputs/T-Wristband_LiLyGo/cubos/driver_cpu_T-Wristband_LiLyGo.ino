#include "WiFi.h"

void driver_cpu_setup(){
}

void driver_cpu_wakeup(){
}

void driver_cpu_sleep(unsigned char sleepType, long timeout){
    
    switch (sleepType)
    {
        case SLEEP_CPU:
            break;
        case SLEEP_DEEP:
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_37, LOW);
            sleep_displayDriver();
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            //esp_sleep_enable_ext1_wakeup(MULTIPLE_INT_BITMASK, ESP_EXT1_WAKEUP_ANY_HIGH);
            esp_deep_sleep_start();
        
            //if(timeout!=0) M5.Axp.DeepSleep(SLEEP_SEC(timeout));
            //else M5.Axp.DeepSleep();
            break;
        case SLEEP_LIGHT:
            
            //debug("Light sleep");
            //digitalWrite(27,0);
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            esp_sleep_enable_ext1_wakeup(GPIO_SEL_33, ESP_EXT1_WAKEUP_ANY_HIGH);
            esp_light_sleep_start();
            /*
            if(timeout!=0){
                M5.Axp.SetLDO2(false);
                M5.Axp.LightSleep(SLEEP_SEC(timeout));
            }else{
                M5.Axp.SetLDO2(false);
                M5.Axp.LightSleep();
            }*/

            break;
        case SLEEP_MODEM:
            WiFi.disconnect();
            //WiFi.forceSleepBegin();
            WiFi.mode(WIFI_OFF);
            btStop();

            debug("Set sleep wifi + bt");
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
