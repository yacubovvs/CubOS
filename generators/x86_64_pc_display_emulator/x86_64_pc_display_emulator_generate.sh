DIRECTORY=`dirname "$0"`
OUTPUT_DIRECTORY="outputs/x86_64_pc_display_emulator"
BUILDSCRIPT_DIRECTORY="generators/x86_64_pc_display_emulator/build.bat"
SETTINGS_FILE="generators/x86_64_pc_display_emulator/x86_64_pc_display_emulator_settings.ino"
APPS_FILE="generators/x86_64_pc_display_emulator/x86_64_pc_display_emulator_apps.ino"
cd $DIRECTORY
cd ../../
rm -R $OUTPUT_DIRECTORY
mkdir $OUTPUT_DIRECTORY
mkdir $OUTPUT_DIRECTORY/cubos

cp $BUILDSCRIPT_DIRECTORY  $OUTPUT_DIRECTORY

# Generating project
cat $SETTINGS_FILE                      > $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat "generators/default_settings.ino"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
# Drivers
cat "sdk/platforms/x86_64_pc.cpp"       >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/cubos.ino                       >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat $APPS_FILE                          >> $OUTPUT_DIRECTORY/cubos/main.cpp

# Applications
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_alarm.ino           >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_battery.ino         >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_compass.ino         >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_settings.ino        >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_test.ino            >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_barometer.ino       >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_clock.ino           >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_filemanager.ino     >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_internet.ino        >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_simplegame.ino      >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/apps/app_z_menu.ino          >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp

# Core
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/core/core_basic.ino              >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/core/core_shared_functions.ino   >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/core/core_views.ino              >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/core/core_display.ino            >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp
cat sdk/core/core_time.ino               >> $OUTPUT_DIRECTORY/cubos/main.cpp
echo "
"   >> $OUTPUT_DIRECTORY/cubos/main.cpp


#cat sdk/libs/Arduino_ST7789.cpp          $OUTPUT_DIRECTORY/cubos/main.cpp
#cat sdk/libs/Arduino_ST7789.h            $OUTPUT_DIRECTORY/cubos/main.cpp

echo Finished