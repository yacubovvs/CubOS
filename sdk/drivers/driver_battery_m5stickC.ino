//#define DEBUG_DRIVER_BATTERY

#ifdef M5STICKC_PLUS
  #include <M5StickCPlus.h>
#else
  #include <M5StickC.h>
#endif

#include "AXP192.h"

void driver_battery_setup(){
    #ifdef DEBUG_DRIVER_BATTERY
        debug("DEBUG_DRIVER_BATTERY: Battery is setted up");
    #endif

    M5.begin(false, true, false);
    //M5.Axp.EnableCoulombcounter();
    M5.Axp.SetChargeCurrent(CURRENT_100MA); // For M5StickC
}

void driver_battery_loop(){
}

float driver_battery_getVoltage(){
    return M5.Axp.GetBatVoltage();
}

int driver_battery_getVoltage_mV(){
    float voltage = driver_battery_getVoltage();
    return (int)(voltage*1000);
}

float driver_battery_getCurent_mA(){
    return M5.Axp.GetBatCurrent();
}

float driver_battery_getUsbVoltage(){
    return M5.Axp.GetVBusVoltage();
}

float driver_battery_getUsbCurent_mA(){
    return M5.Axp.GetVBusCurrent();
}

float driver_battery_getVinVoltage(){
    return M5.Axp.GetVinVoltage();
}

float driver_battery_getVinCurent_mA(){
    return M5.Axp.GetVinCurrent();
}

float driver_battery_controller_Temp(){
    return M5.Axp.GetTempInAXP192();
}

float driver_battery_Temp(){
    return M5.Axp.GetTempInAXP192();
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
    return driver_battery_getCurent_mA()>0;
}

bool driver_battery_isUsbConnected(){
    #ifdef DEBUG_DRIVER_BATTERY
        debug("DEBUG_DRIVER_BATTERY: M5.Axp.GetVinVoltage(): " + String((M5.Axp.GetVinVoltage())));
        debug("DEBUG_DRIVER_BATTERY: M5.Axp.GetVBusVoltage(): " + String((M5.Axp.GetVBusVoltage())));
    #endif

    if(M5.Axp.GetVBusVoltage()>4.3){
        return true;
    }else{
        return false;
    }
}

/* 
Unused:  
M5.Axp.GetBatPower() - (mW)
*/