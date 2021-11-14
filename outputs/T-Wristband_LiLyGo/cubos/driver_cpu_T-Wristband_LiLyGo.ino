#include "WiFi.h"
#include "esp_sleep.h"

void driver_cpu_setup(){
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
}

void driver_cpu_wakeup(){
}

void driver_cpu_poweroff(){}

void driver_cpu_loop(){
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
            #define MULTIPLE_INT_BITMASK_ONCHARGE  0b1000000000000000000000000000000000000
            #define MULTIPLE_INT_BITMASK_EMPTY  0b0000000000000000000000000000000000000
            if(driver_battery_isCharging()) esp_sleep_enable_ext1_wakeup(MULTIPLE_INT_BITMASK_EMPTY, ESP_EXT1_WAKEUP_ANY_HIGH);
            else esp_sleep_enable_ext1_wakeup(MULTIPLE_INT_BITMASK_ONCHARGE, ESP_EXT1_WAKEUP_ANY_HIGH);
            
            
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
            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_deepSleep();
            #endif
            digitalWrite(27, 0);
            //esp_sleep_enable_ext0_wakeup(TOUCH_SCREEN_INTERRUPT_PIN, LOW);
            driver_display_setBrightness(0);
            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_sleep();
            #endif

            esp_light_sleep_start();

            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_wakeup();
            #endif
            driver_display_setBrightness(100);

            esp_light_sleep_start();

            digitalWrite(27, 1);
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            #ifdef ACCELEROMETER_ENABLE
                driver_accelerometer_sleep();
            #endif
            break;

        case SLEEP_LIGHT:
            
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_sleep();
                //driver_accelerometer_wakeup();
            #endif
            esp_sleep_enable_timer_wakeup(timeout*1000);
            esp_light_sleep_start();
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            #ifdef ACCELEROMETER_ENABLE
                //driver_accelerometer_wakeup();
                //delay(100)
                //esp_sleep_enable_timer_wakeup(100*1000);
                //esp_light_sleep_start();
                //esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            #endif
            /*
            esp_sleep_enable_timer_wakeup(1*1000);
            esp_light_sleep_start();
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, HIGH);
            */
            break;
        case SLEEP_MODEM:
            WiFi.disconnect();
            //WiFi.forceSleepBegin();
            WiFi.mode(WIFI_OFF);
            
            #ifndef BLUETOOTH_ENABLED 
            #ifndef BLE_ENABLED
                btStop();
            #endif 
            #endif

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

