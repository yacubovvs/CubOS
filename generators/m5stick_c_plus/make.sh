BSOLUTE_FILENAME=`readlink "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/m5stick_c_plus
mkdir outputs/m5stick_c_plus
mkdir outputs/m5stick_c_plus/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/m5stick_c_plus/cubos/cubos.ino
cat generators/m5stick_c_plus/m5stick_c_plus_settings.ino       >> outputs/m5stick_c_plus/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/m5stick_c_plus/cubos/cubos.ino     >> outputs/m5stick_c_plus/cubos/cubos.ino
cat generators/m5stick_c_plus/m5stick_c_plus_apps.ino           >> outputs/m5stick_c_plus/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/m5stick_c_plus/cubos/     
cp sdk/apps/app_battery.ino         outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_compass.ino         outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_settings.ino        outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_test.ino            outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_barometer.ino       outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_clock.ino           outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_filemanager.ino     outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_internet.ino        outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_simplegame.ino      outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_z_menu.ino          outputs/m5stick_c_plus/cubos/
cp sdk/apps/app_pedometer.ino       outputs/m5stick_c_plus/cubos/

# Drivers
cp sdk/drivers/driver_battery_m5stickC.ino                  outputs/m5stick_c_plus/cubos/     
#cp sdk/drivers/driver_display_m5stickC_ST7735S.ino         outputs/m5stick_c_plus/cubos/   
cp sdk/drivers/driver_display_m5stickCPlus_ST7789v2.ino     outputs/m5stick_c_plus/cubos/   
cp sdk/drivers/driver_controls_m5stickC.ino                 outputs/m5stick_c_plus/cubos/     
cp sdk/drivers/driver_rtc_m5stack_bm8563.ino                outputs/m5stick_c_plus/cubos/     
cp sdk/drivers/driver_cpu_m5stickC.ino                      outputs/m5stick_c_plus/cubos/   
cp sdk/drivers/driver_device_m5stickC.ino                   outputs/m5stick_c_plus/cubos/
cp sdk/drivers/driver_accelerometer_m5stickC.ino            outputs/m5stick_c_plus/cubos/

# Core
cp sdk/core/core_basic.ino              outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_views.ino              outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_display.ino            outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_time.ino               outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_cpu.ino                outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_battery.ino            outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_powersave.ino          outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_background.ino         outputs/m5stick_c_plus/cubos/  
cp sdk/core/core_pedometer.ino          outputs/m5stick_c_plus/cubos/  

echo Finished