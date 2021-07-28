/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      FOR ESP8266 USE NONOSSDK 2.2.2 +
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

#define DEBUG_SERIAL

#define SCREEN_WIDTH            80     // Screen resolution width
#define SCREEN_HEIGHT           160     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define PLATFORM_ESP32
#define BLUETOOTH_ENABLED
#define WIFI_ENABLED

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    

#define DRIVER_CONTROLS_TOTALBUTTONS 2
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1      // for Mainmenu (default app)
//#define STARTING_APP_NUMM    3      // Pedometer
#define STARTING_APP_NUMM    0    // Clock

#define FONT_SIZE_DEFAULT   1

#define CPU_SLEEP_ENABLE
#define ACCELEROMETER_ENABLE

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define RTC_ENABLE

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

#define SMOOTH_ANIMATION
#define NARROW_SCREEN

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
//#define STAND_BY_SLEEP_TYPE     SLEEP_LIGHT
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP

#undef SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE
//#undef DISPLAY_BACKLIGHT_CONTROL_ENABLE
//#undef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define PEDOMETER_STEP_DETECTION_DELAY                  1000
#define PEDOMETER_STEP_DETECTION_PERIOD_MS              1000

#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          10
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         10
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          60 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds

#define DEFAULT_DELAY_TO_FADE_DISPLAY       5
#define DEFAULT_TIME_TO_POWEROFF_DISPLAY    5
#define PEDOMETER_ENABLE
//#define DEBUG_PEDOMETER

#define PEDOMETER_DELTA_VALUE_MIN           0.47f
#define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.17f

#define CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS   2 // mesures for sleep detection 
#define COREPEDOMETER_DELTA_SLEEP_VALUE_MIN_100     3 // acceletometer sensitivity/100*G for sleep detection
/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/