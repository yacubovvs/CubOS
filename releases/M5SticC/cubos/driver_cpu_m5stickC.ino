#include "esp_sleep.h"

#ifdef M5STICKC_PLUS
  #include <M5StickCPlus.h>
#else
  #include <M5StickC.h>
#endif

#include <WiFi.h>

void driver_cpu_setup(){
    M5.begin();
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_37, LOW);
    set_core_powersave_lastUserAction();

    M5.Axp.ClearAllIRQ();
    M5.Axp.DisableAllIRQ();
}

void driver_cpu_wakeup(){}

void driver_cpu_loop(){}

void driver_cpu_sleep(unsigned char sleepType, long timeout_ms){
    
    switch (sleepType)
    {
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_37, LOW);
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_35, LOW);

            //M5.Axp.DisableCoulombcounter();
            //M5.Axp.ClearCoulombcounter();
            //M5.Axp.StopCoulombcounter();

            
            M5.Axp.SetLDO2(false);
            M5.Axp.SetLDO3(false);

    
            if(timeout_ms!=0){
                M5.Axp.DeepSleep(SLEEP_SEC(timeout_ms)/1000);
            }else{
                M5.Axp.DeepSleep();
            } 

            break;
        case SLEEP_LIGHT:
            
            
            //esp_sleep_enable_ext0_wakeup(GPIO_NUM_35, LOW);
            
            if(timeout_ms!=0){    
                M5.Axp.LightSleep(SLEEP_SEC(timeout_ms)/1000);
                //M5.Axp.LightSleep();
            }else{
                M5.Axp.LightSleep();
            }
            

            //M5.Axp.LightSleep();

            //debug("Light slepp");

            //esp_sleep_enable_timer_wakeup(WAKEUP_FROM_LIGHT_SLEEP_EVERY_MS*1000);
            //0000000200000000
            /*
            rtc.disableAlarm();
            rtc.setDateTime(2019, 4, 7, 9, 5, 57);
            rtc.setAlarmByMinutes(6);
            rtc.enableAlarm();
            */

            

            
            //esp_light_sleep_start();
            
            //delay(1);
            //set_core_powersave_lastUserAction();
            //debug("Light wake up");
            
            /*
            gpio_hold_en((gpio_num_t) 26);
            gpio_deep_sleep_hold_en();
            esp_sleep_enable_timer_wakeup(WAKEUP_FROM_LIGHT_SLEEP_EVERY_MS*1000);
            */

            break;
        case SLEEP_MODEM:
            //WiFi.disconnect();
            //WiFi.forceSleepBegin();
            WiFi.mode(WIFI_OFF);
            btStop();

            debug("Set sleep wifi + bt");
            break;
        case SLEEP_DISPLAY:
            M5.Axp.SetLDO2(false);
            break;
        case WAKE_MODEM:
            //WiFi.forceSleepEnd();
            delay(1);
            break;
        case WAKE_DISPLAY:
            M5.Axp.SetLDO2(true); 
            break;
        case WAKE:
            M5.Axp.SetLDO2(true); 
            break;
        default:
            break;
    }
}
