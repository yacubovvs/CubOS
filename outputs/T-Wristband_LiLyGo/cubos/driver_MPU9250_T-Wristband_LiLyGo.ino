#ifdef ACCELEROMETER_ENABLE
    #include <SPI.h>
    #include <Wire.h>
    #include "sensor.h"

    extern MPU9250 IMU;

    //float accX = 0.0F; float accY = 0.0F; float accZ = 0.0F;
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
    float get_driver_accelerometer_x(){return IMU.ax;}
    float get_driver_accelerometer_y(){return IMU.ay;}
    float get_driver_accelerometer_z(){return IMU.az;}

    void driver_accelerometer_update_gyroscope(){}
    void driver_accelerometer_update_accelerometer(){
        
        if (IMU.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01){
            IMU.readAccelData(IMU.accelCount);  // Read the x/y/z adc values
            IMU.getAres();

            // Now we'll calculate the accleration value into actual g's
            // This depends on scale being set
            IMU.ax = (float)IMU.accelCount[0] * IMU.aRes; // - accelBias[0];
            IMU.ay = (float)IMU.accelCount[1] * IMU.aRes; // - accelBias[1];
            IMU.az = (float)IMU.accelCount[2] * IMU.aRes; // - accelBias[2];

            //IMU.readGyroData(IMU.gyroCount);  // Read the x/y/z adc values
            //IMU.getGres();

            // Calculate the gyro value into actual degrees per second
            // This depends on scale being set
            /*
            IMU.gx = (float)IMU.gyroCount[0] * IMU.gRes;
            IMU.gy = (float)IMU.gyroCount[1] * IMU.gRes;
            IMU.gz = (float)IMU.gyroCount[2] * IMU.gRes;

            IMU.readMagData(IMU.magCount);  // Read the x/y/z adc values
            IMU.getMres();
            // User environmental x-axis correction in milliGauss, should be
            // automatically calculated
            IMU.magbias[0] = +470.;
            // User environmental x-axis correction in milliGauss TODO axis??
            IMU.magbias[1] = +120.;
            // User environmental x-axis correction in milliGauss
            IMU.magbias[2] = +125.;

            // Calculate the magnetometer values in milliGauss
            // Include factory calibration per data sheet and user environmental
            // corrections
            // Get actual magnetometer value, this depends on scale being set
            IMU.mx = (float)IMU.magCount[0] * IMU.mRes * IMU.magCalibration[0] -
                    IMU.magbias[0];
            IMU.my = (float)IMU.magCount[1] * IMU.mRes * IMU.magCalibration[1] -
                    IMU.magbias[1];
            IMU.mz = (float)IMU.magCount[2] * IMU.mRes * IMU.magCalibration[2] -
                    IMU.magbias[2];
        } // if (readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01)

        // Must be called before updating quaternions!
        IMU.updateTime();

        // Sensors x (y)-axis of the accelerometer is aligned with the y (x)-axis of
        // the magnetometer; the magnetometer z-axis (+ down) is opposite to z-axis
        // (+ up) of accelerometer and gyro! We have to make some allowance for this
        // orientationmismatch in feeding the output to the quaternion filter. For the
        // MPU-9250, we have chosen a magnetic rotation that keeps the sensor forward
        // along the x-axis just like in the LSM9DS0 sensor. This rotation can be
        // modified to allow any convenient orientation convention. This is ok by
        // aircraft orientation standards! Pass gyro rate as rad/s
        //  MadgwickQuaternionUpdate(ax, ay, az, gx*PI/180.0f, gy*PI/180.0f, gz*PI/180.0f,  my,  mx, mz);
        MahonyQuaternionUpdate(IMU.ax, IMU.ay, IMU.az, IMU.gx * DEG_TO_RAD,
                                IMU.gy * DEG_TO_RAD, IMU.gz * DEG_TO_RAD, IMU.my,
                                IMU.mx, IMU.mz, IMU.deltat);
        // Serial print and/or display at 0.5 s rate independent of data rates
        IMU.delt_t = millis() - IMU.count;

        if (IMU.delt_t > 20) {
            if (SerialDebugMPU9250) {
            Serial.print("ax = ");
            Serial.print((int)1000 * IMU.ax);
            Serial.print(" ay = ");
            Serial.print((int)1000 * IMU.ay);
            Serial.print(" az = ");
            Serial.print((int)1000 * IMU.az);
            Serial.println(" mg");
            */
        }
    }
    void driver_accelerometer_update_angles(){}
    void driver_accelerometer_update_temperature(){}
    void driver_accelerometer_poweroff(){}
    void driver_accelerometer_poweron(){}

    void driver_accelerometer_setup(){
        //IMU.initMPU9250();
        setupMPU9250();
    }

    void driver_accelerometer_loop(){
    }

    void driver_accelerometer_wakeup(){
        IMU.setSleepEnabled(false);
    }

    void driver_accelerometer_sleep(){
        IMU.setSleepEnabled(true);
    }

    void driver_accelerometer_update(){
        //driver_accelerometer_update_accelerometer();
        //driver_accelerometer_update_gyroscope();
        //driver_accelerometer_update_angles();
        //driver_accelerometer_update_temperature();
    }

    float driver_accelerometer_get_accel_total(){
        return sqrt(pow(get_driver_accelerometer_x(),2) + pow(get_driver_accelerometer_y(),2) + pow(get_driver_accelerometer_z(),2));
    }

#endif