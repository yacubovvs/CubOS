#define TP_PIN_PIN          33
#define I2C_SDA_PIN         21
#define I2C_SCL_PIN         22
#define IMU_INT_PIN         38
#define RTC_INT_PIN         34
#define BATT_ADC_PIN        35
#define VBUS_PIN            36
#define TP_PWR_PIN          25
#define LED_PIN             4
#define CHARGE_PIN          32

#define ANALOG_VALUE_ION_BATTERY 2440

//#define DEBUG_DRIVER_BATTERY

void driver_battery_setup(){
    //pinMode(BATT_ADC_PIN, INPUT);
    //pinMode(VBUS_PIN, INPUT);
}

void driver_battery_loop(){
    
    #ifdef DEBUG_DRIVER_BATTERY
        //debug("VBUS_PIN: " + String(analogRead(VBUS_PIN)));
        //debug("BATT_ADC_PIN: " + String(analogRead(BATT_ADC_PIN)));
    #endif
}

float driver_battery_getVoltage(){
    int analogValue = analogRead(BATT_ADC_PIN);
    if(analogValue==0) return 0;
    float voltage = 4.2/((float)ANALOG_VALUE_ION_BATTERY)*((float)analogValue);
    return voltage;
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
    return 0;
}

float driver_battery_getVinVoltage(){
    int analogValue = analogRead(VBUS_PIN);
    if(analogValue==0) return 0;
    float voltage = 4.2/((float)ANALOG_VALUE_ION_BATTERY)*((float)analogValue);
    return voltage;
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

    return analogRead(VBUS_PIN)>analogRead(BATT_ADC_PIN);
}

bool driver_battery_isUsbConnected(){
    //return analogRead(VBUS_PIN)>1024;
    return driver_battery_isCharging();
}