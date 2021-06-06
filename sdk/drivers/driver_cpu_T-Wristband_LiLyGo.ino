#include "WiFi.h"
#include "esp_sleep.h"

void driver_cpu_setup(){
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
}

void driver_cpu_wakeup(){
}

void driver_cpu_sleep(unsigned char sleepType, long timeout){
    
    switch (sleepType)
    {
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            
            sleep_displayDriver();
            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_sleep();
            #endif

            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            //esp_sleep_enable_ext1_wakeup(MULTIPLE_INT_BITMASK, ESP_EXT1_WAKEUP_ANY_HIGH);
            //esp_sleep_enable_timer_wakeup(1000);
            //esp_deep_sleep_disable_timer_wakeup();
            //esp_sleep_disable_timer_wakeup();
            esp_sleep_enable_timer_wakeup(1000*timeout);
            //s_config.wakeup_triggers &= ~RTC_TIMER_TRIG_EN;
            //s_config.sleep_duration = 0;
            esp_deep_sleep_start();
        
            break;
        case SLEEP_LIGHT_SCREEN_OFF:
            sleep_displayDriver();

            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_sleep();
            #endif

            gpio_hold_en((gpio_num_t) 26);
            gpio_deep_sleep_hold_en();
            esp_sleep_enable_timer_wakeup(timeout*1000);
            esp_light_sleep_start();

            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);

            break;
        case SLEEP_LIGHT:
            
            //if(timeout!=0)esp_sleep_enable_timer_wakeup(timeout * 1000);
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            //esp_sleep_enable_ext1_wakeup(0x600000000, ESP_EXT1_WAKEUP_ANY_HIGH);
            //core_time_setAlarmBySeconds(2);
            //esp_sleep_enable_ext1_wakeup(0x200000000, ESP_EXT1_WAKEUP_ANY_HIGH);
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            gpio_hold_en((gpio_num_t) 26);
            gpio_deep_sleep_hold_en();
            esp_sleep_enable_timer_wakeup(timeout*1000);
            //0000000200000000
            /*
            rtc.disableAlarm();
            rtc.setDateTime(2019, 4, 7, 9, 5, 57);
            rtc.setAlarmByMinutes(6);
            rtc.enableAlarm();
            */

            esp_light_sleep_start();

            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);

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