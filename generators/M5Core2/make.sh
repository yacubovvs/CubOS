BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/M5Core2
mkdir outputs/M5Core2
mkdir outputs/M5Core2/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/M5Core2/cubos/cubos.ino
cat generators/M5Core2/M5Core2_settings.ino                     >> outputs/M5Core2/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/M5Core2/cubos/cubos.ino            >> outputs/M5Core2/cubos/cubos.ino
cat generators/M5Core2/M5Core2_apps.ino                         >> outputs/M5Core2/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/M5Core2/cubos/     
#cp sdk/apps/app_battery.ino         outputs/M5Core2/cubos/
#cp sdk/apps/app_compass.ino         outputs/M5Core2/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/M5Core2/cubos/
cp sdk/apps/app_settings.ino        outputs/M5Core2/cubos/
cp sdk/apps/app_test.ino            outputs/M5Core2/cubos/
#cp sdk/apps/app_barometer.ino       outputs/M5Core2/cubos/
cp sdk/apps/app_clock.ino           outputs/M5Core2/cubos/
cp sdk/apps/app_filemanager.ino     outputs/M5Core2/cubos/
cp sdk/apps/app_internet.ino        outputs/M5Core2/cubos/
cp sdk/apps/app_simplegame.ino      outputs/M5Core2/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/M5Core2/cubos/
#cp sdk/apps/app_pedometer.ino       outputs/M5Core2/cubos/

# Drivers
cp sdk/drivers/driver_display_m5Core2.ino               outputs/M5Core2/cubos/    
cp sdk/drivers/driver_touchscreen_M5Core2.ino           outputs/M5Core2/cubos/    
cp sdk/drivers/driver_cpu_M5Core2.ino                   outputs/M5Core2/cubos/    

# Core
cp sdk/core/core_basic.ino              outputs/M5Core2/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/M5Core2/cubos/  
cp sdk/core/core_views.ino              outputs/M5Core2/cubos/  
cp sdk/core/core_display.ino            outputs/M5Core2/cubos/  
cp sdk/core/core_time.ino               outputs/M5Core2/cubos/  
cp sdk/core/core_cpu.ino                outputs/M5Core2/cubos/  
#cp sdk/core/core_battery.ino            outputs/M5Core2/cubos/  
#cp sdk/core/core_powersave.ino          outputs/M5Core2/cubos/  
cp sdk/core/core_background.ino         outputs/M5Core2/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/M5Core2/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/M5Core2/cubos/  

#external libs


echo Finished