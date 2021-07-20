#ifdef ACCELEROMETER_ENABLE
    float gyroX = 0.0F; float gyroY = 0.0F; float gyroZ = 0.0F;
    float pitch = 0.0F; float roll  = 0.0F; float yaw   = 0.0F;
    float temp = 0;

    float get_driver_accelerometer_temperature(){return temp;}
    float get_driver_accelerometer_pitch(){return pitch;}
    float get_driver_accelerometer_roll(){return roll;}
    float get_driver_accelerometer_yaw(){return yaw;}
    float get_driver_accelerometer_gyroscope_x(){return gyroX;}
    float get_driver_accelerometer_gyroscope_y(){return gyroY;}
    float get_driver_accelerometer_gyroscope_z(){return gyroZ;}
    float get_driver_accelerometer_x(){return core_driver_setup_accelerometer_getX();}
    float get_driver_accelerometer_y(){return core_driver_setup_accelerometer_getY();}
    float get_driver_accelerometer_z(){return core_driver_setup_accelerometer_getZ();}
    void driver_accelerometer_setup(){}
    void driver_accelerometer_loop(){}
    void driver_accelerometer_update(){
        driver_accelerometer_update_accelerometer();
        driver_accelerometer_update_gyroscope();
        driver_accelerometer_update_angles();
        driver_accelerometer_update_temperature();
    }
    void driver_accelerometer_update_gyroscope(){}
    void driver_accelerometer_update_accelerometer(){
        core_driver_setup_accelerometer_update();
    }
    void driver_accelerometer_update_angles(){}
    void driver_accelerometer_update_temperature(){}
    void driver_accelerometer_poweroff(){
        core_driver_setup_accelerometer_disableAccel();
    }
    void driver_accelerometer_poweron(){
        core_driver_setup_accelerometer_enableAccel();
    }
    void driver_accelerometer_wakeup(){
        core_driver_setup_accelerometer_enableAccel();
    }
    void driver_accelerometer_sleep(){
        core_driver_setup_accelerometer_disableAccel();
    }
    float driver_accelerometer_get_accel_total(){
        return sqrt(pow(get_driver_accelerometer_x(),2) + pow(get_driver_accelerometer_y(),2) + pow(get_driver_accelerometer_z(),2));
    }
    
#endif