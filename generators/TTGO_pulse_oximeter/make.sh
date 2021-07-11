BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/TTGO_pulse_oximeter
mkdir outputs/TTGO_pulse_oximeter
mkdir outputs/TTGO_pulse_oximeter/cubos

# Generating Arduino project
cat generators/default_settings.ino                                     > outputs/TTGO_pulse_oximeter/cubos/cubos.ino
cat generators/TTGO_pulse_oximeter/TTGO_pulse_oximeter_settings.ino       >> outputs/TTGO_pulse_oximeter/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/TTGO_pulse_oximeter/cubos/cubos.ino         >> outputs/TTGO_pulse_oximeter/cubos/cubos.ino
cat generators/TTGO_pulse_oximeter/TTGO_pulse_oximeter_apps.ino           >> outputs/TTGO_pulse_oximeter/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/apps/app_battery.ino         outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_compass.ino         outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_settings.ino        outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_test.ino            outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_barometer.ino       outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_clock.ino           outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_filemanager.ino     outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_internet.ino        outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_simplegame.ino      outputs/TTGO_pulse_oximeter/cubos/
cp sdk/apps/app_z_menu.ino          outputs/TTGO_pulse_oximeter/cubos/

# Drivers
cp sdk/drivers/driver_battery_T-Wristband_LiLyGo.ino                outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/drivers/driver_display_eTFT_ST7735_T-Wristband_LiLyGo.ino    outputs/TTGO_pulse_oximeter/cubos/     
#cp sdk/drivers/driver_display_adafruit_ST7735.ino                   outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/drivers/driver_controls_T-Wristband_LiLyGo.ino               outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/drivers/driver_rtc_pcf8563.ino                               outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/drivers/driver_cpu_T-Wristband_LiLyGo.ino                    outputs/TTGO_pulse_oximeter/cubos/     
cp sdk/drivers/driver_IMU_MPU9250_T-Wristband_LiLyGo.ino                outputs/TTGO_pulse_oximeter/cubos/     

# Core
cp sdk/core/core_basic.ino              outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_views.ino              outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_display.ino            outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_time.ino               outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_cpu.ino                outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_battery.ino            outputs/TTGO_pulse_oximeter/cubos/  
cp sdk/core/core_powersave.ino          outputs/TTGO_pulse_oximeter/cubos/  

#external libs
cp external_libs/MPU9250_LiLyGO_T-Wristband/MPU9250.cpp                 outputs/TTGO_pulse_oximeter/cubos/ 
cp external_libs/MPU9250_LiLyGO_T-Wristband/MPU9250.h                   outputs/TTGO_pulse_oximeter/cubos/ 
cp external_libs/MPU9250_LiLyGO_T-Wristband/quaternionFilters.cpp       outputs/TTGO_pulse_oximeter/cubos/ 
cp external_libs/MPU9250_LiLyGO_T-Wristband/quaternionFilters.h         outputs/TTGO_pulse_oximeter/cubos/ 
cp external_libs/MPU9250_LiLyGO_T-Wristband/sensor.h                    outputs/TTGO_pulse_oximeter/cubos/ 

echo Finished