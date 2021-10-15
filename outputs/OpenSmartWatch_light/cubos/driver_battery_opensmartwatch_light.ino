//#define DEBUG_DRIVER_BATTERY

void driver_battery_setup(){
    pinMode(25, INPUT); // Analog value battery voltage
    pinMode(15, INPUT); // Charge indicator
    #ifdef DEBUG_DRIVER_BATTERY
        debug("DEBUG_DRIVER_BATTERY: Battery is setted up");
    #endif
}

void driver_battery_loop(){
}

float driver_battery_getVoltage(){
    float voltage = (driver_battery_getVoltage_mV()/100)/10.0; 
    #ifdef DEBUG_DRIVER_BATTERY
        debug("Analog GPIO25 value " + String((unsigned int)analogRead(25)));
    #endif
    return voltage;
}

int driver_battery_getVoltage_mV(){
    //float voltage = 2900 + ((float)(analogRead(25)))*1000/86.0; //real dependence is nonlinear
    float voltage = 3200 + ((float)(analogRead(25)-43))*1000/69.0; //real dependence is nonlinear
    return (int)(voltage);
}

float driver_battery_getCurent_mA(){
    return 0; // Not supported
}

float driver_battery_getUsbVoltage(){
    return 0; // Not supported
}

float driver_battery_getUsbCurent_mA(){
    return 0; // Not supported
}

float driver_battery_getVinVoltage(){
    return 0; // Not supported
}

float driver_battery_getVinCurent_mA(){
    return 0; // Not supported
}

float driver_battery_controller_Temp(){
    return 0; // Not supported
}

float driver_battery_Temp(){
    return 0; // Not supported
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
    #ifdef DEBUG_DRIVER_BATTERY
        debug("Digital GPIO15 value (charging) " + (digitalRead(15)?String("on"):String("off")) );
    #endif
    return digitalRead(15);
}

bool driver_battery_isUsbConnected(){
    return driver_battery_isCharging();
}
