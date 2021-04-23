/*
    ############################################################################################
    #                                                                                          #
    #                                    WATCH7 SETTINGS +                                     #
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
#define DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored
#define DISPLAY_NO_ANIMATION                     // Caurse of framebuffer type

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM   3     // for App number 7

#define FONT_SIZE_DEFAULT 1

//#define CPU_SLEEP_ENABLE
//#define CPU_SLEEP_TIME_DELAY core_cpu_getCpuSleepTimeDelay()


//#define BATTERY_ENABLE
//#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define USE_RTC

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

/*
    ############################################################################################
    #                                                                                          #
    #                                    WATCH7 SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/