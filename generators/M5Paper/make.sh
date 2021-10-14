#BSOLUTE_FILENAME=`readlink -e "$0"`
BSOLUTE_FILENAME=`readlink "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/M5Paper
mkdir outputs/M5Paper
mkdir outputs/M5Paper/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/M5Paper/cubos/cubos.ino
cat generators/M5Paper/M5Paper_settings.ino                     >> outputs/M5Paper/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/M5Paper/cubos/cubos.ino            >> outputs/M5Paper/cubos/cubos.ino
cat generators/M5Paper/M5Paper_apps.ino                         >> outputs/M5Paper/cubos/cubos.ino

# Applications
#cp sdk/apps/app_alarm.ino           outputs/M5Paper/cubos/     
#cp sdk/apps/app_battery.ino         outputs/M5Paper/cubos/
#cp sdk/apps/app_compass.ino         outputs/M5Paper/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/M5Paper/cubos/
cp sdk/apps/app_settings.ino        outputs/M5Paper/cubos/
cp sdk/apps/app_test.ino            outputs/M5Paper/cubos/
#cp sdk/apps/app_barometer.ino       outputs/M5Paper/cubos/
cp sdk/apps/app_epaper_clock.ino    outputs/M5Paper/cubos/
cp sdk/apps/app_filemanager.ino     outputs/M5Paper/cubos/
cp sdk/apps/app_internet.ino        outputs/M5Paper/cubos/
cp sdk/apps/app_simplegame.ino      outputs/M5Paper/cubos/
cp sdk/apps/app_touchTest.ino       outputs/M5Paper/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/M5Paper/cubos/
cp sdk/apps/app_battery.ino         outputs/M5Paper/cubos/
cp sdk/apps/app_test_buttons.ino    outputs/M5Paper/cubos/
cp sdk/apps/app_poweroff.ino        outputs/M5Paper/cubos/
#cp sdk/apps/app_pedometer_test.ino  outputs/M5Paper/cubos/

# Drivers
cp sdk/drivers/driver_display_M5Paper.ino               outputs/M5Paper/cubos/
cp sdk/drivers/driver_setup_M5Paper.ino                 outputs/M5Paper/cubos/
cp sdk/drivers/driver_controls_M5Paper.ino              outputs/M5Paper/cubos/
cp sdk/drivers/driver_touchscreen_M5Paper.ino           outputs/M5Paper/cubos/
cp sdk/drivers/driver_rtc_m5paper_bm8563.ino            outputs/M5Paper/cubos/
cp sdk/drivers/driver_battery_m5paper.ino               outputs/M5Paper/cubos/
cp sdk/drivers/driver_cpu_M5Paper.ino                   outputs/M5Paper/cubos/

# Core
cp sdk/core/core_basic.ino              outputs/M5Paper/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/M5Paper/cubos/  
cp sdk/core/core_views.ino              outputs/M5Paper/cubos/  
cp sdk/core/core_display.ino            outputs/M5Paper/cubos/  
cp sdk/core/core_time.ino               outputs/M5Paper/cubos/  
cp sdk/core/core_cpu.ino                outputs/M5Paper/cubos/  
cp sdk/core/core_battery.ino            outputs/M5Paper/cubos/  
#cp sdk/core/core_powersave.ino          outputs/M5Paper/cubos/  
cp sdk/core/core_background.ino         outputs/M5Paper/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/M5Paper/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/M5Paper/cubos/  
cp sdk/core/core_powersave.ino          outputs/M5Paper/cubos/  

#external libs


echo Finished