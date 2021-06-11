BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/M5Stack
mkdir outputs/M5Stack
mkdir outputs/M5Stack/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/M5Stack/cubos/cubos.ino
cat generators/M5Stack/M5Stack_settings.ino                     >> outputs/M5Stack/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/M5Stack/cubos/cubos.ino            >> outputs/M5Stack/cubos/cubos.ino
cat generators/M5Stack/M5Stack_apps.ino                         >> outputs/M5Stack/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/M5Stack/cubos/     
#cp sdk/apps/app_battery.ino         outputs/M5Stack/cubos/
#cp sdk/apps/app_compass.ino         outputs/M5Stack/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/M5Stack/cubos/
cp sdk/apps/app_settings.ino        outputs/M5Stack/cubos/
cp sdk/apps/app_test.ino            outputs/M5Stack/cubos/
#cp sdk/apps/app_barometer.ino       outputs/M5Stack/cubos/
cp sdk/apps/app_clock.ino           outputs/M5Stack/cubos/
cp sdk/apps/app_filemanager.ino     outputs/M5Stack/cubos/
cp sdk/apps/app_internet.ino        outputs/M5Stack/cubos/
cp sdk/apps/app_simplegame.ino      outputs/M5Stack/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/M5Stack/cubos/
#cp sdk/apps/app_pedometer.ino       outputs/M5Stack/cubos/

# Drivers
cp sdk/drivers/driver_display_m5Core2.ino               outputs/M5Stack/cubos/    
//#cp sdk/drivers/driver_touchscreen_M5Core2.ino           outputs/M5Stack/cubos/    
cp sdk/drivers/driver_cpu_M5Core2.ino                   outputs/M5Stack/cubos/    

# Core
cp sdk/core/core_basic.ino              outputs/M5Stack/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/M5Stack/cubos/  
cp sdk/core/core_views.ino              outputs/M5Stack/cubos/  
cp sdk/core/core_display.ino            outputs/M5Stack/cubos/  
cp sdk/core/core_time.ino               outputs/M5Stack/cubos/  
cp sdk/core/core_cpu.ino                outputs/M5Stack/cubos/  
#cp sdk/core/core_battery.ino            outputs/M5Stack/cubos/  
#cp sdk/core/core_powersave.ino          outputs/M5Stack/cubos/  
cp sdk/core/core_background.ino         outputs/M5Stack/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/M5Stack/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/M5Stack/cubos/  

#external libs


echo Finished