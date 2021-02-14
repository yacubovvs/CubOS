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

//#define serialDebug
#define screenDebug

#define SCREEN_WIDTH            240     // Screen resolution width
#define SCREEN_HEIGHT           240     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define device_has_battery

#define platform_esp32
#define device_has_bluetooth
#define device_has_wifi

#define ON_TIME_CHANGE_EVERY_MS 1000

#define hasHardwareButtons              // Conf of controls with hardware btns    
//#define isTouchScreen                 // Conf of controls

#define colorScreen                     // Screen is colored
#define noAnimation                     // Caurse of framebuffer type

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM   7     // for App number 7

#define CPU_SLEEP_ENABLE
#define DELAY_BEFORE_SLEEP 25000

#define BUTTON_UP       0
#define BUTTON_SELECT   1
#define BUTTON_DOWN     2
#define BUTTON_BACK     3

#define BATTERY_ENABLE
#define CLOCK_ENABLE
#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define USE_RTC

//#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  40

/*
    ############################################################################################
    #                                                                                          #
    #                                    WATCH7 SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/