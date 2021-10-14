//#define DEBUG_DRIVER_BATTERY

#include <M5EPD.h>

void driver_battery_setup(){
    //begin(bool LCDEnable, bool PowerEnable, bool SerialEnable){ // temp n103
    #ifdef DEBUG_DRIVER_BATTERY
        debug("DEBUG_DRIVER_BATTERY: Battery is setted up");
    #endif

    //M5.begin(false, true, false);
    //M5.Axp.EnableCoulombcounter();
    //M5.Axp.SetChargeCurrent(CURRENT_100MA); // For M5StickC
}

void driver_battery_loop(){
}

float driver_battery_getVoltage(){
    //return 1.0; //M5.Axp.GetBatVoltage();
    return ((float)M5.getBatteryVoltage())/1000;
    //return M5.getBatteryRaw();
}

int driver_battery_getVoltage_mV(){
    float voltage = M5.getBatteryVoltage();
    return (int)(voltage);
    //return M5.getBatteryRaw();
}

float driver_battery_getCurent_mA(){
    //return M5.Axp.GetBatCurrent();
    return 0;
}

float driver_battery_getUsbVoltage(){
    //return M5.Axp.GetVBusVoltage();
    return 0;
}

float driver_battery_getUsbCurent_mA(){
    //return M5.Axp.GetVBusCurrent();
    return 0;
}

float driver_battery_getVinVoltage(){
    //return M5.Axp.GetVinVoltage();
    return 0;
}

float driver_battery_getVinCurent_mA(){
    //return M5.Axp.GetVinCurrent();
    return 0;
}

float driver_battery_controller_Temp(){
    //return M5.Axp.GetTempInAXP192();
    return 0;
}

float driver_battery_Temp(){
    //return M5.Axp.GetTempInAXP192();
    return 0;
}

unsigned char driver_battery_getPercent(){
    int mV = driver_battery_getVoltage_mV();
    if(mV>=4100){
        return 100;
    }else if(mV<=3200){
        return 0;
    }else{
        int dmV = mV - 3200;
        return dmV*10/90;
    }
    return 0;
}

bool driver_battery_isCharging(){
    //return driver_battery_getCurent_mA()>0;
    return false;
}

bool driver_battery_isUsbConnected(){
    #ifdef DEBUG_DRIVER_BATTERY
        //debug("DEBUG_DRIVER_BATTERY: M5.Axp.GetVinVoltage(): " + String((M5.Axp.GetVinVoltage())));
        //debug("DEBUG_DRIVER_BATTERY: M5.Axp.GetVBusVoltage(): " + String((M5.Axp.GetVBusVoltage())));
    #endif

    /*
    if(M5.Axp.GetVBusVoltage()>4.3){
        return true;
    }else{
        return false;
    }
    */

   return false;
}

/* 
Unused:  
M5.Axp.GetBatPower() - (mW)
*/