
/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      FOR ESP8266 USE NONOSSDK 2.2.2 +
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

//#define DEBUG_SERIAL
//#define screenDebug
#define TERMINAL_DEBUG

#define SCREEN_WIDTH            80     // Screen resolution width
#define SCREEN_HEIGHT           160     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

//#define device_has_battery

#define PLATFORM_PC_EMULATOR
#define device_has_bluetooth
#define device_has_wifi

#define MAIN_MENU_SMOOTH_ANIMATION
#define NARROW_SCREEN

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED        // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE

#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH 300

#define colorScreen                     // Screen is colored
//#define noAnimation                   // Caurse of framebuffer type

//#define toDefaultApp_onLeftLongPress

//#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
#define STARTING_APP_NUMM   2     // for App number 7

#undef CPU_SLEEP_ENABLE
#undef POWERSAVE_ENABLE
//#define CPU_SLEEP_TIME_DELAY 25000

#define BUTTON_UP       0
#define BUTTON_SELECT   1
#define BUTTON_DOWN     2
#define BUTTON_BACK     3

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define RTC_ENABLE
#define FONT_SIZE_DEFAULT 2
#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

//#define PEDOMETER_ENABLE
//#define ACCELEROMETER_ENABLE
#define STYLE_STATUSBAR_HEIGHT  20

#undef I2C_ENABLE
#undef CPU_CONTROLL_ENABLE

#define PEDOMETER_EMULATOR
#define FONT_SIZE_DEFAULT   1

/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/