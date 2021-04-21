BSOLUTE_FILENAME=`readlink -e "$0"`
DIRECTORY=`dirname "$0"`
cd $DIRECTORY
cd ../../
rm -R outputs/esp8266_cubwatch7
mkdir outputs/esp8266_cubwatch7
mkdir outputs/esp8266_cubwatch7/cubos

# Generating Arduino project
cat generators/default_settings.ino                                 > outputs/esp8266_cubwatch7/cubos/cubos.ino
cat generators/esp8266_cubwatch7/esp8266_cubwatch7_settings.ino     >> outputs/esp8266_cubwatch7/cubos/cubos.ino
cat sdk/cubos.ino >> outputs/esp8266_cubwatch7/cubos/cubos.ino      >> outputs/esp8266_cubwatch7/cubos/cubos.ino
cat generators/esp8266_cubwatch7/esp8266_cubwatch7_apps.ino         >> outputs/esp8266_cubwatch7/cubos/cubos.ino

# Applications
cp sdk/apps/app_alarm.ino           outputs/esp8266_cubwatch7/cubos/     
cp sdk/apps/app_battery.ino         outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_compass.ino         outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_i2c_scanner.ino     outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_settings.ino        outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_test.ino            outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_barometer.ino       outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_clock.ino           outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_filemanager.ino     outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_internet.ino        outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_simplegame.ino      outputs/esp8266_cubwatch7/cubos/
cp sdk/apps/app_z_menu.ino          outputs/esp8266_cubwatch7/cubos/

# Drivers
cp sdk/drivers/driver_battery_esp8266.ino       outputs/esp8266_cubwatch7/cubos/     
cp sdk/drivers/driver_display_ST7789_spi.ino    outputs/esp8266_cubwatch7/cubos/     
cp sdk/drivers/driver_controls_watch7.ino       outputs/esp8266_cubwatch7/cubos/     
cp sdk/drivers/driver_RTC_DS3231.ino            outputs/esp8266_cubwatch7/cubos/     
cp sdk/drivers/driver_cpu_esp8266.ino           outputs/esp8266_cubwatch7/cubos/     

# Core
cp sdk/core/core_basic.ino              outputs/esp8266_cubwatch7/cubos/  
cp sdk/core/core_shared_functions.ino   outputs/esp8266_cubwatch7/cubos/  
cp sdk/core/core_views.ino              outputs/esp8266_cubwatch7/cubos/  
cp sdk/core/core_display.ino            outputs/esp8266_cubwatch7/cubos/  
cp sdk/core/core_time.ino               outputs/esp8266_cubwatch7/cubos/  
cp sdk/core/core_cpu.ino               outputs/esp8266_cubwatch7/cubos/  

cp sdk/libs/Arduino_ST7789.cpp          outputs/esp8266_cubwatch7/cubos/ 
cp sdk/libs/Arduino_ST7789.h            outputs/esp8266_cubwatch7/cubos/

echo Finished