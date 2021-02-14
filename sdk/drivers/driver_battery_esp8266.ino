int maxBatteryAnalogValue = 890;

int getMaxBatteryAnalogValue(){
    return maxBatteryAnalogValue;
}

void driver_battery_setup(){
    pinMode(A0, INPUT);
}

void driver_battery_loop(){

}

int driver_battery_raw(){
    int analogValue = analogRead(A0);
    //if(analogValue>getMaxBatteryAnalogValue()) maxBatteryAnalogValue=analogValue;
    return analogValue;
}

float driver_battery_getVoltage(){
    int analogValue = driver_battery_raw();
    float voltage = 4.2/((float)getMaxBatteryAnalogValue())*((float)analogValue);
    return voltage;
}

int driver_battery_getmVoltage(){
    int analogValue = driver_battery_raw();
    long voltage = 420*((float)analogValue)/((float)getMaxBatteryAnalogValue());
    return (int)voltage;
}

byte driver_battery_getPercent(){
    int mV = driver_battery_getmVoltage();
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