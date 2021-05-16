void driver_battery_setup(){
}

void driver_battery_loop(){
}

float driver_battery_getVoltage(){
    return 4.2;
}

int driver_battery_getVoltage_mV(){
    return 4200;
}

float driver_battery_getCurent_mA(){
    return 0;
}

float driver_battery_getUsbVoltage(){
    return 0;
}

float driver_battery_getUsbCurent_mA(){
    return 0;
}

float driver_battery_getVinVoltage(){
    return 0;
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
    return driver_battery_getCurent_mA()>0;
}
