#ifdef ACCELEROMETER_ENABLE

    #include <M5StickC.h>

    float accX = 0.0F; float accY = 0.0F; float accZ = 0.0F;
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
    float get_driver_accelerometer_x(){return accX;}
    float get_driver_accelerometer_y(){return accY;}
    float get_driver_accelerometer_z(){return accZ;}

    void driver_accelerometer_setup(){
        //M5.begin(); // No need for accelerometer
        M5.IMU.Init();
    }

    void driver_accelerometer_loop(){}

    void driver_accelerometer_update(){
        driver_accelerometer_update_accelerometer();
        driver_accelerometer_update_gyroscope();
        driver_accelerometer_update_angles();
        driver_accelerometer_update_temperature();
    }

    void driver_accelerometer_update_gyroscope(){M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);}
    void driver_accelerometer_update_accelerometer(){M5.IMU.getAccelData(&accX,&accY,&accZ);}
    void driver_accelerometer_update_angles(){M5.IMU.getAhrsData(&pitch,&roll,&yaw);}
    void driver_accelerometer_update_temperature(){M5.IMU.getTempData(&temp);}
    void driver_accelerometer_poweroff(){}
    void driver_accelerometer_poweron(){}

    void driver_accelerometer_wakeup(){
        switch(M5.IMU.imuType){
            case M5.IMU.ImuType::IMU_UNKNOWN:
                break;
            case M5.IMU.ImuType::IMU_SH200Q:
                break;
            case M5.IMU.ImuType::IMU_MPU6886:
                //Just a hard code for m5stick
                Wire1.beginTransmission(0x68);
                Wire1.write(0x6B);
                Wire1.write(0x00<<6);
                Wire1.endTransmission();
                break;
            default:
                break;
        }

        //M5.IMU.setSleepEnabled(false);
    }
    
    void driver_accelerometer_sleep(){
        switch(M5.IMU.imuType){
            case M5.IMU.ImuType::IMU_UNKNOWN:
                break;
            case M5.IMU.ImuType::IMU_SH200Q:
                break;
            case M5.IMU.ImuType::IMU_MPU6886:
                //Just a hard code for m5stick
                Wire1.beginTransmission(0x68);
                Wire1.write(0x6B);
                Wire1.write(0x01<<6);
                Wire1.endTransmission();                
                
                break;
            default:
                break;
        }
    }

    float driver_accelerometer_get_accel_total(){
        return sqrt(pow(get_driver_accelerometer_x(),2) + pow(get_driver_accelerometer_y(),2) + pow(get_driver_accelerometer_z(),2));
    }
    
#endif