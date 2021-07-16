

void driver_battery_setup(){
}

void driver_battery_loop(){

}

float driver_battery_getVoltage(){
    return get_core_driver_getBattVoltage()/1000;
}

int driver_battery_getVoltage_mV(){
    return (int)(driver_battery_getVoltage()*1000);
}

float driver_battery_getCurent_mA(){
    return get_core_driver_getBattChargeCurrent() + get_core_driver_getBattDischargeCurrent();
}

float driver_battery_getUsbVoltage(){
    return 0;
}

float driver_battery_getUsbCurent_mA(){
    return 0;//power_battery->getVbusCurrent();//(float)ttgo_battery->power->getChargeControlCur();
}

float driver_battery_getVinVoltage(){
    return get_core_driver_getVbusVoltage();
}

float driver_battery_getVinCurent_mA(){
    return get_core_driver_getVbusCurrent();
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
    //return get_core_driver_getBattPercentage();
}

bool driver_battery_isCharging(){
    return get_core_driver_isCharging();
}

bool driver_battery_isUsbConnected(){
    return get_core_driver_VBUSConnected();
}

bool driver_battery_isBatteryConnected(){
    return get_core_driver_isBatteryConnect();
}
