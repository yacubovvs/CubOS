/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 +                                   #
    #                                                                                          #
    ############################################################################################
*/

#undef CPU_CONTROLL_ENABLE

#define LILYGO_WATCH_2020_V3 

//#define DEBUG_SERIAL
#define screenDebug

#define SCREEN_WIDTH            240     // Screen resolution width
#define SCREEN_HEIGHT           240     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

#define platform_esp32
#define device_has_bluetooth
#define device_has_wifi

#define ON_TIME_CHANGE_EVERY_MS 1000

//#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE

#define colorScreen                     // Screen is colored
#define noAnimation                     

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM   11     // for App number 7

//#define CPU_SLEEP_ENABLE
//#define CPU_SLEEP_TIME_DELAY core_cpu_getCpuSleepTimeDelay()


#define BUTTON_UP       0x01
#define BUTTON_SELECT   0x02
#define BUTTON_DOWN     0x03
#define BUTTON_BACK     0x04


//#define BATTERY_ENABLE
//#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

//#define USE_RTC

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  40

#define LILYGO_WATCH_2020_V3 

/*
    ############################################################################################
    #                                                                                          #
    #                                 LILYGO_WATCH_2020_V3 -                                   #
    #                                                                                          #
    ############################################################################################
*/