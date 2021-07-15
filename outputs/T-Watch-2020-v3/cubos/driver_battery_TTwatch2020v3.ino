#include <LilyGoWatch.h>

TTGOClass *ttgo_battery;
AXP20X_Class *power_battery;

void driver_battery_setup(){
    ttgo_battery = TTGOClass::getWatch();
    power_battery = ttgo_battery->power;
    power_battery->setChargeControlCur(500);
}

void driver_battery_loop(){

}

float driver_battery_getVoltage(){
    return 4.2;
}

int driver_battery_getVoltage_mV(){
    return (int)(driver_battery_getVoltage()*1000);
}

float driver_battery_getCurent_mA(){
    return 0;
}

float driver_battery_getUsbVoltage(){
    return 0;
}

float driver_battery_getUsbCurent_mA(){
    return 0;//power_battery->getVbusCurrent();//(float)ttgo_battery->power->getChargeControlCur();
}

float driver_battery_getVinVoltage(){
    return 5.0;
}

float driver_battery_getVinCurent_mA(){
    return 0;
}

float driver_battery_controller_Temp(){
    return 0;
}

float driver_battery_Temp(){
    return 0;
}

unsigned char driver_battery_getPercent(){
    int mV = driver_battery_getVoltage_mV();
    if(mV>=4000){
        return 100;
    }else if(mV<=3200){
        return 0;
    }else{
        int dmV = mV - 3200;
        return dmV*10/80;
    }
    return 0;
}

bool driver_battery_isCharging(){
    return get_core_driver_isCharging();
}

bool driver_battery_isUsbConnected(){
    return get_core_driver_VBUSConnected();
}
