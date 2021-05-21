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

#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM    1 // Settings
//#define STARTING_APP_NUMM    7 // Battery

#define FONT_SIZE_DEFAULT   1

#define CPU_SLEEP_ENABLE

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define USE_RTC

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

#define MAIN_MENU_SMOOTH_ANIMATION
#define NARROW_SCREEN

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

//#define SCREEN_INVERT_COLORS
#define SCREEN_CHANGE_BLUE_RED

#define DRIVER_RTC_INTERRUPT_PIN    34

#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
//#define STAND_BY_SLEEP_TYPE     SLEEP_LIGHT
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP

/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/