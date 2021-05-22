#include <M5StickC.h>
#include <WiFi.h>

void driver_cpu_setup(){
    M5.begin();
}

void driver_cpu_wakeup(){

}

void driver_cpu_sleep(unsigned char sleepType, long timeout){
    
    switch (sleepType)
    {
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_37, LOW);
            esp_sleep_enable_ext0_wakeup(GPIO_NUM_35, LOW);
        
            if(timeout!=0) M5.Axp.DeepSleep(SLEEP_SEC(timeout));
            else M5.Axp.DeepSleep();
            break;
        case SLEEP_LIGHT:
            
            if(timeout!=0){
                M5.Axp.SetLDO2(false);
                M5.Axp.LightSleep(SLEEP_SEC(timeout));
            }else{
                M5.Axp.SetLDO2(false);
                M5.Axp.LightSleep();
            }

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
