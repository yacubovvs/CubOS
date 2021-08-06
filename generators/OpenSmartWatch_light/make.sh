#BSOLUTE_FILENAME=`readlink -e "$0"`
BSOLUTE_FILENAME=`readlink "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/OpenSmartWatch_light
mkdir outputs/OpenSmartWatch_light
mkdir outputs/OpenSmartWatch_light/cubos

# Generating Arduino project
cat generators/default_settings.ino                                     > outputs/OpenSmartWatch_light/cubos/cubos.ino
cat generators/OpenSmartWatch_light/OpenSmartWatch_light_settings.ino       >> outputs/OpenSmartWatch_light/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/OpenSmartWatch_light/cubos/cubos.ino         >> outputs/OpenSmartWatch_light/cubos/cubos.ino
cat generators/OpenSmartWatch_light/OpenSmartWatch_light_apps.ino           >> outputs/OpenSmartWatch_light/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/OpenSmartWatch_light/cubos/     
cp sdk/apps/app_battery.ino         outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_compass.ino         outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_settings.ino        outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_test.ino            outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_barometer.ino       outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_clock.ino           outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_filemanager.ino     outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_internet.ino        outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_simplegame.ino      outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_z_menu.ino          outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_pedometer_test.ino  outputs/OpenSmartWatch_light/cubos/
cp sdk/apps/app_pedometer.ino       outputs/OpenSmartWatch_light/cubos/

# Drivers
#cp sdk/drivers/driver_battery_T-Wristband_LiLyGo.ino                outputs/OpenSmartWatch_light/cubos/     
cp sdk/drivers/driver_display_opensmartwatch.ino                     outputs/OpenSmartWatch_light/cubos/     
#cp sdk/drivers/driver_display_adafruit_ST7735.ino                   outputs/OpenSmartWatch_light/cubos/     
cp sdk/drivers/driver_controls_opensmartWatch_light.ino              outputs/OpenSmartWatch_light/cubos/     
#cp sdk/drivers/driver_rtc_pcf8563.ino                               outputs/OpenSmartWatch_light/cubos/     
#cp sdk/drivers/driver_cpu_T-Wristband_LiLyGo.ino                    outputs/OpenSmartWatch_light/cubos/     
#cp sdk/drivers/driver_IMU_MPU9250_T-Wristband_LiLyGo.ino            outputs/OpenSmartWatch_light/cubos/     

# Core
cp sdk/core/core_basic.ino              outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_views.ino              outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_display.ino            outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_time.ino               outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_cpu.ino                outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_battery.ino            outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_powersave.ino          outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_background.ino         outputs/OpenSmartWatch_light/cubos/  
cp sdk/core/core_pedometer.ino          outputs/OpenSmartWatch_light/cubos/  

echo Finished