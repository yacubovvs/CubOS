#ifdef ACCELEROMETER_ENABLE
    #include <SPI.h>
    #include <Wire.h>
    #include "sensor.h"

    extern MPU9250 IMU;

    void driver_accelerometer_setup(){
    }

    void driver_accelerometer_loop(){
    }

    void driver_accelerometer_wakeup(){
    }

    void driver_accelerometer_sleep(){
        IMU.setSleepEnabled(true);
    }

#endif