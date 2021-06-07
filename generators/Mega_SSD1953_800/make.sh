BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/Mega_SSD1953_800
mkdir outputs/Mega_SSD1953_800
mkdir outputs/Mega_SSD1953_800/cubos

# Generating Arduino project
cat generators/default_settings.ino                             > outputs/Mega_SSD1953_800/cubos/cubos.ino
cat generators/Mega_SSD1953_800/Mega_SSD1953_800_settings.ino                     >> outputs/Mega_SSD1953_800/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/Mega_SSD1953_800/cubos/cubos.ino            >> outputs/Mega_SSD1953_800/cubos/cubos.ino
cat generators/Mega_SSD1953_800/Mega_SSD1953_800_apps.ino                         >> outputs/Mega_SSD1953_800/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/Mega_SSD1953_800/cubos/     
#cp sdk/apps/app_battery.ino         outputs/Mega_SSD1953_800/cubos/
#cp sdk/apps/app_compass.ino         outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_settings.ino        outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_test.ino            outputs/Mega_SSD1953_800/cubos/
#cp sdk/apps/app_barometer.ino       outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_clock.ino           outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_filemanager.ino     outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_internet.ino        outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_simplegame.ino      outputs/Mega_SSD1953_800/cubos/
cp sdk/apps/app_z_menu_touch.ino    outputs/Mega_SSD1953_800/cubos/
#cp sdk/apps/app_pedometer.ino       outputs/Mega_SSD1953_800/cubos/

# Drivers
cp sdk/drivers/driver_display_Mega_SSD1953_800.ino               outputs/Mega_SSD1953_800/cubos/    
cp sdk/drivers/driver_touchscreen_Mega_SSD1953_800.ino           outputs/Mega_SSD1953_800/cubos/    
cp sdk/drivers/driver_cpu_Mega_SSD1953_800.ino                   outputs/Mega_SSD1953_800/cubos/    

# Core
cp sdk/core/core_basic.ino              outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_views.ino              outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_display.ino            outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_time.ino               outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_cpu.ino                outputs/Mega_SSD1953_800/cubos/  
#cp sdk/core/core_battery.ino            outputs/Mega_SSD1953_800/cubos/  
#cp sdk/core/core_powersave.ino          outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_background.ino         outputs/Mega_SSD1953_800/cubos/  
#cp sdk/core/core_pedometer.ino          outputs/Mega_SSD1953_800/cubos/  
cp sdk/core/core_touchscreen.ino        outputs/Mega_SSD1953_800/cubos/  

#external libs


echo Finished