#ifdef M5STICKC_PLUS
  #include <M5StickCPlus.h>
#else
  #include <M5StickC.h>
#endif

#include "AXP192.h"

void driver_battery_setup(){
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

/* 
Unused:  
M5.Axp.GetBatPower() - (mW)
*/