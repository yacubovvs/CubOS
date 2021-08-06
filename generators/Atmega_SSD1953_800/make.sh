BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/Atmega_SSD1953_800
mkdir outputs/Atmega_SSD1953_800
mkdir outputs/Atmega_SSD1953_800/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/Atmega_SSD1953_800/cubos/cubos.ino
cat generators/Atmega_SSD1953_800/Atmega_SSD1953_800_settings.ino                     >> outputs/Atmega_SSD1953_800/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/Atmega_SSD1953_800/cubos/cubos.ino            >> outputs/Atmega_SSD1953_800/cubos/cubos.ino
cat generators/Atmega_SSD1953_800/Atmega_SSD1953_800_apps.ino                         >> outputs/Atmega_SSD1953_800/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/Atmega_SSD1953_800/cubos/     
#cp sdk/apps/app_battery.ino         outputs/Atmega_SSD1953_800/cubos/
#cp sdk/apps/app_compass.ino         outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_settings.ino        outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_test.ino            outputs/Atmega_SSD1953_800/cubos/
#cp sdk/apps/app_barometer.ino       outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_clock.ino           outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_filemanager.ino     outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_internet.ino        outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_simplegame.ino      outputs/Atmega_SSD1953_800/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/Atmega_SSD1953_800/cubos/
#cp sdk/apps/app_pedometer_test.ino       outputs/Atmega_SSD1953_800/cubos/

# Drivers
cp sdk/drivers/driver_display_Atmega_SSD1953_800.ino               outputs/Atmega_SSD1953_800/cubos/    
cp sdk/drivers/driver_touchscreen_Atmega_SSD1953_800.ino           outputs/Atmega_SSD1953_800/cubos/    
cp sdk/drivers/driver_cpu_Atmega.ino                             outputs/Atmega_SSD1953_800/cubos/    

# Core
cp sdk/core/core_basic.ino              outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_views.ino              outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_display.ino            outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_time.ino               outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_cpu.ino                outputs/Atmega_SSD1953_800/cubos/  
#cp sdk/core/core_software_keyboard.ino  outputs/Atmega_SSD1953_800/cubos/  
#cp sdk/core/core_battery.ino            outputs/Atmega_SSD1953_800/cubos/  
#cp sdk/core/core_powersave.ino          outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_background.ino         outputs/Atmega_SSD1953_800/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/Atmega_SSD1953_800/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/Atmega_SSD1953_800/cubos/  

#external libs


echo Finished