BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/Atmega_Shield35
mkdir outputs/Atmega_Shield35
mkdir outputs/Atmega_Shield35/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/Atmega_Shield35/cubos/cubos.ino
cat generators/Atmega_Shield35/Atmega_Shield35_settings.ino                     >> outputs/Atmega_Shield35/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/Atmega_Shield35/cubos/cubos.ino            >> outputs/Atmega_Shield35/cubos/cubos.ino
cat generators/Atmega_Shield35/Atmega_Shield35_apps.ino                         >> outputs/Atmega_Shield35/cubos/cubos.ino

# Applications
cp sdk/apps/app_z_menu_touch.ino    outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_filemanager.ino     outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_alarm.ino           outputs/Atmega_Shield35/cubos/     
cp sdk/apps/app_i2c_scanner.ino     outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_settings.ino        outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_test.ino            outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_clock.ino           outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_internet.ino        outputs/Atmega_Shield35/cubos/
cp sdk/apps/app_simplegame.ino      outputs/Atmega_Shield35/cubos/




# Drivers
cp sdk/drivers/driver_display_Atmega_Shield35.ino               outputs/Atmega_Shield35/cubos/    
cp sdk/drivers/driver_touchscreen_Atmega_Shield35.ino           outputs/Atmega_Shield35/cubos/     

# Core
cp sdk/core/core_basic.ino              outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_views.ino              outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_display.ino            outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_time.ino               outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_cpu.ino                outputs/Atmega_Shield35/cubos/  
#cp sdk/core/core_battery.ino            outputs/Atmega_Shield35/cubos/  
#cp sdk/core/core_powersave.ino          outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_background.ino         outputs/Atmega_Shield35/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/Atmega_Shield35/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/Atmega_Shield35/cubos/  

#external libs


echo Finished