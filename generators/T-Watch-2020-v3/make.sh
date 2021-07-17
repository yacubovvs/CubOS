BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/T-Watch-2020-v3
mkdir outputs/T-Watch-2020-v3
mkdir outputs/T-Watch-2020-v3/cubos

# Generating Arduino project
cat generators/default_settings.ino                                     > outputs/T-Watch-2020-v3/cubos/cubos.ino
cat generators/T-Watch-2020-v3/T-Watch-2020-v3_settings.ino             >> outputs/T-Watch-2020-v3/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/T-Watch-2020-v3/cubos/cubos.ino            >> outputs/T-Watch-2020-v3/cubos/cubos.ino
cat generators/T-Watch-2020-v3/T-Watch-2020-v3_apps.ino                 >> outputs/T-Watch-2020-v3/cubos/cubos.ino

# Applications
#cp sdk/apps/app_alarm.ino           outputs/T-Watch-2020-v3/cubos/     
cp sdk/apps/app_battery.ino         outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_settings.ino        outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_test.ino            outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_clock.ino           outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_touchTest.ino       outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_pedometer_test.ino  outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_pedometer.ino       outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_ble_tester.ino      outputs/T-Watch-2020-v3/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/T-Watch-2020-v3/cubos/

# External libraries
#cp external_libs/AXP202/axp20x.cpp                  outputs/T-Watch-2020-v3/cubos/
#cp external_libs/AXP202/axp20x.h                    outputs/T-Watch-2020-v3/cubos/ 

# Drivers
#cp sdk/drivers/driver_battery_m5stickC.ino                  outputs/T-Watch-2020-v3/cubos/     
cp sdk/drivers/driver_setup_ttgo_watch2020v3.ino            outputs/T-Watch-2020-v3/cubos/
cp sdk/drivers/driver_display_ST7789_ttwatch_spi.ino        outputs/T-Watch-2020-v3/cubos/
cp sdk/drivers/driver_touchscreen_ttwatch.ino               outputs/T-Watch-2020-v3/cubos/     
cp sdk/drivers/driver_controls_tt-watch-2020.ino            outputs/T-Watch-2020-v3/cubos/     
cp sdk/drivers/driver_cpu_TTGO_watch2020_v3.ino             outputs/T-Watch-2020-v3/cubos/     
cp sdk/drivers/driver_battery_TTwatch2020v3.ino             outputs/T-Watch-2020-v3/cubos/ 
cp sdk/drivers/driver_rtc_ttgo_watch2020v3.ino              outputs/T-Watch-2020-v3/cubos/ 
cp sdk/drivers/driver_IMU_ttgo_watch2020v3.ino              outputs/T-Watch-2020-v3/cubos/ 
#cp sdk/drivers/driver_rtc_ds3231.ino                        outputs/T-Watch-2020-v3/cubos/     
#cp sdk/drivers/driver_cpu_m5StickS.ino                      outputs/T-Watch-2020-v3/cubos/     

# Core
cp sdk/core/core_basic.ino              outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_views.ino              outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_display.ino            outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_time.ino               outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_cpu.ino                outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_battery.ino            outputs/T-Watch-2020-v3/cubos/ 
cp sdk/core/core_powersave.ino          outputs/T-Watch-2020-v3/cubos/ 
cp sdk/core/core_background.ino         outputs/T-Watch-2020-v3/cubos/ 
cp sdk/core/core_touchscreen.ino        outputs/T-Watch-2020-v3/cubos/  
cp sdk/core/core_pedometer.ino          outputs/T-Watch-2020-v3/cubos/ 

echo Finished