/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 +                                   #
    #                                                                                          #
    ############################################################################################
*/

#define LILYGO_WATCH_2020_V3 

//#define DEBUG_SERIAL
//#define DEBUG_ON_SCREEN
#define WATCH_SCREEN

#define SCREEN_WIDTH            240     // Screen resolution width
#define SCREEN_HEIGHT           240     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2
#define FRAMEBUFFER_PSRAM

#define platform_esp32
#define BLUETOOTH_ENABLE
#define WIFI_ENABLE

//#define USE_L_MENU_IMAGES
#define USE_XL_MENU_IMAGES

#define ON_TIME_CHANGE_EVERY_MS 1000

#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE

#define COLOR_SCREEN                     // Screen is colored                     

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM   1 // Settings

#define CPU_SLEEP_ENABLE

#define BATTERY_ENABLE
#define POWERSAVE_ENABLE
#define CPU_CONTROLL_ENABLE

#undef RUN_BACKGROUND_AFTER_RESTART_MCU // This devicw will not get in deep sleep, only long light sleep
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define NARROW_SCREEN
#define RTC_ENABLE
#define SMOOTH_ANIMATION

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270
#undef DISPLAY_BACKLIGHT_CONTROL_ENABLE
#undef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE
#undef SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE  4

//#define DEFAULT_FADE_BRIGHTNES 5
//#define DEFAULT_SCREEN_BRIGHTNESS 10

#define DEFAULT_TIME_TO_POWEROFF_DISPLAY 15
#define APP_CLOCK_POWER_AFTER_SECONDS 15
//#define DEFAULT_DELAY_TO_FADE_DISPLAY 0

#define STYLE_STATUSBAR_HEIGHT  30 
#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define CORE_SETUP_INIT

#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS     400
#define CONTROLS_DELAY_TO_DOUBLE_CLICK_MS           400

#define FONT_SIZE_DEFAULT 2

#define DRIVER_RTC_INTERRUPT_PIN    37
#define IN_APP_SLEEP_TYPE           SLEEP_LIGHT
#define STAND_BY_SLEEP_TYPE         SLEEP_LIGHT_SCREEN_OFF
//#define STAND_BY_SLEEP_TYPE         SLEEP_DEEP

#define ACCELEROMETER_ENABLE
//#define MAGNITOMETER_ENABLE
#define PEDOMETER_ENABLE

#define PEDOMETER_STEP_DETECTION_PERIOD_MS             1000
#define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      7
#define PEDOMETER_DAY_STEP_LIMMIT_DEFAULT               10000

#define PEDOMETER_DELTA_VALUE_MIN           0.47f
#define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.15f

/*
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          300
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         30
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          180 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds
*/

#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          15
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         15
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          60 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds


//#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          60
//#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         60
//#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          60 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds


#define CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS           7 // mesures for sleep detection 
#define COREPEDOMETER_CENTRALWIGHT_SLEEP_VALUE_MIN      0.05f
#define COREPEDOMETER_DELTA_SLEEP_VALUE_MIN_100         3 // acceletometer sensitivity/100*G for sleep detection

#define APP_CLOCK_POWER_AFTER_SECONDS           2
#define APP_BATTERY_FONT_SIZE                   1
//#define DEBUG_CPU_CONTROLL_ENABLE
//#define DEBUG_CORE_POWERSAVE

#define DEBUG_SERIAL
//#define DEBUG_CORE_DISPLAY
//#define CORE_TOUCH_DEBUG
//#define APP_SETTINGS_DEBUG
//#define PEDOMETER_EMULATOR
//#define DEBUG_FPS
//#define DEBUG_WAKEUP
#define DEBUG_PEDOMETER
//#define DEBUG_ACELEROMETER
//#define DEBUG_BACKLIGHT
//#define DEBUG_DRIVER_CONTROLL
//#define DEBUG_DRIVER_BATTERY
/*
/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 -                                   #
    #                                                                                          #
    ############################################################################################
*/