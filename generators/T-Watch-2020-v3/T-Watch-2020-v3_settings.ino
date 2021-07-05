/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 +                                   #
    #                                                                                          #
    ############################################################################################
*/

#undef CPU_CONTROLL_ENABLE

#define LILYGO_WATCH_2020_V3 

#define DEBUG_SERIAL
//#define DEBUG_ON_SCREEN

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

#define ON_TIME_CHANGE_EVERY_MS 1000

#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE
//#define PEDOMETER_ENABLE

#define COLOR_SCREEN                     // Screen is colored
//#define NO_ANIMATION                     

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM   11     // for App number 7

//#define CPU_SLEEP_ENABLE

#undef BATTERY_ENABLE
#undef POWERSAVE_ENABLE
#define CPU_CONTROLL_ENABLE

//#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define RTC_ENABLE

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270
#undef DISPLAY_BACKLIGHT_CONTROL_ENABLE
#undef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define STYLE_STATUSBAR_HEIGHT  40 
#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define CORE_SETUP_INIT

#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS     400
#define CONTROLS_DELAY_TO_DOUBLE_CLICK_MS           400

/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 -                                   #
    #                                                                                          #
    ############################################################################################
*/