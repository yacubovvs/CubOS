#define LION_EMULATOR_BATTERY_VOLTAGE_100 420 

int getMaxBatteryAnalogValue(){
    return 0;
}

void driver_battery_setup(){
}

void driver_battery_loop(){

}

int driver_battery_raw(){
    return getMaxBatteryAnalogValue();
}

float driver_battery_getVoltage(){
    return (float)LION_EMULATOR_BATTERY_VOLTAGE_100 / 100.0;
}

int driver_battery_getVoltage_mV(){
    return LION_EMULATOR_BATTERY_VOLTAGE_100;
}

unsigned char driver_battery_getPercent(){
    int mV = driver_battery_getVoltage_mV();
    if(mV>=400){
        return 100;
    }else if(mV<=320){
        return 0;
    }else{
        int dmV = mV - 320;
        return dmV*100/80;
    }
    return 0;
}