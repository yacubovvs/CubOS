#ifdef ACCELEROMETER_ENABLE
    #include <telit_bma400.h>

    #define GRAVITY_EARTH     (9.80665f)
    #define SENSOR_TICK_TO_S  (0.0000390625f)

    struct bma400_dev bma;
    struct bma400_sensor_conf conf;
    struct bma400_sensor_data data;
    struct bma400_int_enable int_en;
    int8_t rslt;

    uint16_t int_status = 0;
    
    //float accelX = 0.0F; float accelY = 0.0F; float accelZ = 0.0F;
    float accelX = 0.0F; float accelY = 0.0F; float accelZ = 0.0F;
    float pitch = 0.0F; float roll  = 0.0F; float yaw   = 0.0F;
    float temp = 0;

    float get_driver_accelerometer_temperature(){return temp;}
    float get_driver_accelerometer_pitch(){return pitch;}
    float get_driver_accelerometer_roll(){return roll;}
    float get_driver_accelerometer_yaw(){return yaw;}
    float get_driver_accelerometer_gyroscope_x(){return accelX;}
    float get_driver_accelerometer_gyroscope_y(){return accelY;}
    float get_driver_accelerometer_gyroscope_z(){return accelZ;}
    float get_driver_accelerometer_x(){return accelX;}
    float get_driver_accelerometer_y(){return accelY;}
    float get_driver_accelerometer_z(){return accelZ;}

    void driver_accelerometer_update_gyroscope(){}

    void driver_accelerometer_setup(){
        rslt = bma400_interface_init(&bma, BMA400_I2C_INTF);
        bma400_check_rslt("bma400_interface_init", rslt);

        rslt = bma400_soft_reset(&bma);
        bma400_check_rslt("bma400_soft_reset", rslt);

        rslt = bma400_init(&bma);
        bma400_check_rslt("bma400_init", rslt);

        /* Select the type of configuration to be modified */
        conf.type = BMA400_ACCEL;

        /* Get the accelerometer configurations which are set in the sensor */
        rslt = bma400_get_sensor_conf(&conf, 1, &bma);
        bma400_check_rslt("bma400_get_sensor_conf", rslt);

        /* Modify the desired configurations as per macros
        * available in bma400_defs.h file */
        conf.param.accel.odr = BMA400_ODR_800HZ;
        conf.param.accel.range = BMA400_RANGE_4G;
        conf.param.accel.data_src = BMA400_DATA_SRC_ACCEL_FILT_2;

        /* Set the desired configurations to the sensor */
        rslt = bma400_set_sensor_conf(&conf, 1, &bma);
        bma400_check_rslt("bma400_set_sensor_conf", rslt);

        rslt = bma400_set_power_mode(BMA400_MODE_NORMAL, &bma);
        bma400_check_rslt("bma400_set_power_mode", rslt);

        int_en.type = BMA400_DRDY_INT_EN;
        int_en.conf = BMA400_ENABLE;

        rslt = bma400_enable_interrupt(&int_en, 1, &bma);
        bma400_check_rslt("bma400_enable_interrupt", rslt);
    }

    void driver_accelerometer_update_accelerometer(){
        rslt = bma400_get_interrupt_status(&int_status, &bma);
        bma400_check_rslt("bma400_get_interrupt_status", rslt);

        if (int_status & BMA400_ASSERTED_DRDY_INT)
        {
            rslt = bma400_get_accel_data(BMA400_DATA_ONLY, &data, &bma);
            bma400_check_rslt("bma400_get_accel_data", rslt);

            /* 12-bit accelerometer at range 2G */
            accelX = lsb_to_ms2(data.x, 2, 12);
            accelY = lsb_to_ms2(data.y, 2, 12);
            accelZ = lsb_to_ms2(data.z, 2, 12);

            /*
            Serial.print("Gravity-x : ");
            Serial.print(x);
            Serial.print(", Gravity-y : ");
            Serial.print(y);
            Serial.print(", Gravity-z : ");
            Serial.println(z);
            Serial.flush();
            */
            //n_samples--;
            //delay(100);
        }
    }
    void driver_accelerometer_update_angles(){}
    void driver_accelerometer_update_temperature(){}
    void driver_accelerometer_poweroff(){}
    void driver_accelerometer_poweron(){}

    void driver_accelerometer_loop(){
    }

    void driver_accelerometer_wakeup(){
        //IMU.setSleepEnabled(false);
        rslt = bma400_set_power_mode(BMA400_MODE_NORMAL, &bma);
        bma400_check_rslt("bma400_set_low_power_mode", rslt);
    }

    void driver_accelerometer_sleep(){
        //rslt = bma400_set_power_mode(BMA400_MODE_LOW_POWER, &bma);
        rslt = bma400_set_power_mode(BMA400_MODE_SLEEP, &bma);
        //rslt = bma400_set_power_mode(BMA400_MODE_NORMAL, &bma);
        //bma400_check_rslt("bma400_set_power_mode", rslt);
        bma400_check_rslt("bma400_set_sleep_mode", rslt);
        //bma400_check_rslt("bma400_set_low_power_mode", rslt);
    }

    void driver_accelerometer_deepSleep(){
        //IMU.deepSleep();
        rslt = bma400_set_power_mode(BMA400_MODE_SLEEP, &bma);
        bma400_check_rslt("bma400_set_sleep_mode", rslt);
    }

    void driver_accelerometer_update(){
        driver_accelerometer_update_accelerometer();
        //driver_accelerometer_update_accelerometer();
        //driver_accelerometer_update_gyroscope();
        //driver_accelerometer_update_angles();
        //driver_accelerometer_update_temperature();
    }

    float driver_accelerometer_get_accel_total(){
        return sqrt(pow(get_driver_accelerometer_x(),2) + pow(get_driver_accelerometer_y(),2) + pow(get_driver_accelerometer_z(),2));
        //return abs(get_driver_accelerometer_x());
    }


    /*
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
                                        OTHER                                    
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    */
    static float lsb_to_ms2(int16_t accel_data, uint8_t g_range, uint8_t bit_width){
        float accel_ms2;
        int16_t half_scale;

        half_scale = 1 << (bit_width - 1);
        accel_ms2 = (GRAVITY_EARTH * accel_data * g_range) / half_scale;

        return accel_ms2;

    }

#endif

