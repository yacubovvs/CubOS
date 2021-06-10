/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/

// TOUCH


#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH 300

// BUTTONS

#define BUTTON_UP       0x01
#define BUTTON_SELECT   0x02
#define BUTTON_DOWN     0x03
#define BUTTON_BACK     0x04
#define BUTTON_POWER    0x05

#define DRIVER_CONTROLS_TOTALBUTTONS 3
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS     50
#define DRIVER_CONTROLS_DELAY_BEFORE_MULTY_PRESS    400

/*
############################################################################
#                                 EVENTS +                                 #
############################################################################
*/

#define EVENT_BUTTON_PRESSED                0x00
#define EVENT_BUTTON_RELEASED               0x01
#define EVENT_BUTTON_LONG_PRESS             0x02
#define EVENT_BUTTON_SHORT_PRESS            0x03
#define EVENT_BUTTON_SHORT_SINGLE_PRESS     0x04
#define EVENT_BUTTON_DOUBLE_PRESS           0x05
#define EVENT_ON_TIME_CHANGED               0x06
#define EVENT_ON_GOING_TO_SLEEP             0x07
#define EVENT_ON_WAKE_UP                    0x08

#define EVENT_ON_TOUCH_START                0x09
#define EVENT_ON_TOUCH_RELEASED             0x0A
#define EVENT_ON_TOUCH_CLICK                0x0B
#define EVENT_ON_TOUCH_LONG_PRESS           0x0C
#define EVENT_ON_TOUCH_DRAG                 0x0D
#define EVENT_ON_TOUCH_DOUBLE_PRESS         0x0E
#define EVENT_ON_TOUCH_SWIPE_FROM_LEFT      0x0F
#define EVENT_ON_TOUCH_SWIPE_FROM_RIGHT     0x10
#define EVENT_ON_TOUCH_SWIPE_FROM_TOP       0x11
#define EVENT_ON_TOUCH_SWIPE_FROM_BOTTOM    0x12


// WAKEUP REASONS
#define WAKE_UP_REASON_EXTERNAL_RTC_IO      0x01
#define WAKE_UP_REASON_EXTERNAL_RTC_CNTL    0x02
#define WAKE_UP_REASON_TIMER                0x03
#define WAKE_UP_REASON_TPOUCHPAD            0x04
#define WAKE_UP_REASON_ULP                  0x05
#define WAKE_UP_REASON_NOT_DEEP_SLEEP       0x06

// SOFTWARE_BUTTONS
#define SOFTWARE_BAR_BUTTON_UP              0x0001
#define SOFTWARE_BAR_BUTTON_SELECT          0x0002
#define SOFTWARE_BAR_BUTTON_DOWN            0x0003
#define SOFTWARE_BAR_BUTTON_BACK            0x0004

/*
 ############################################################################
                                 SLEEP TYPES -                               
*/

#define SLEEP_IDLE_CPU          0x01
#define SLEEP_DEEP              0x02
#define SLEEP_LIGHT             0x03
#define SLEEP_MODEM             0x04
#define SLEEP_DISPLAY           0x05
#define SLEEP_HIBERNATE         0x03
#define WAKE_MODEM              0x06
#define WAKE_DISPLAY            0x07
#define WAKE                    0x08
#define SLEEP_LIGHT_SCREEN_OFF  0x09


#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP
/*
############################################################################
#                                 EVENTS -                                 #
############################################################################
*/

/*
############################################################################
#                                 STYLES +                                 #
############################################################################
*/

#define COREVIEWS_NO_ICON_ELEMENT_HEIGHT 40

#define SOFTWARE_BUTTONS_COLOR_RED          255
#define SOFTWARE_BUTTONS_COLOR_GREEN        255
#define SOFTWARE_BUTTONS_COLOR_BLUE         255

#define SOFTWARE_BUTTONS_COLOR_RED_BG       59
#define SOFTWARE_BUTTONS_COLOR_GREEN_BG     35
#define SOFTWARE_BUTTONS_COLOR_BLUE_BG      71

/*
############################################################################
#                                 STYLES -                                 #
############################################################################
*/

#define ON_TIME_CHANGE_EVERY_MS 1000

#define UPDATE_RTC_EVERY 65
#define I2C_ENABLE
#define CPU_CONTROLL_ENABLE
#define POWERSAVE_ENABLE

#define FONT_SIZE_DEFAULT 2
#define HARDWARE_BUTTONS_VALUE 3

#define CONTROLS_DELAY_TO_DOUBLE_CLICK_MS DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS

#define SMOOTH_ANIMATION_COEFFICIENT    5
// #define MAIN_MENU_SMOOTH_ANIMATION
// #define NARROW_SCREEN

#define UPDATE_BATTERY_EVERY_MS 3000
#define SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE  4
#define BATTERY_ENABLE

// #define ACCELEROMETER_ENABLE
#define DISPLAY_BACKLIGHT_CONTROL_ENABLE
#define DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define WAKEUP_FROM_LIGHT_SLEEP_EVERY_MS 1000
#define WAKEUP_FROM_DEEP_SLEEP_EVERY_SECONDS 60*60*24 // Wake up if no any other background works as pedometer

#define USE_TYPE2_OF_IMAGES
//#define PEDOMETER_ENABLE

//#define PEDOMETER_STEP_DETECTION_DELAY                30000
#define PEDOMETER_STEP_DETECTION_DELAY                  15000
//#define PEDOMETER_STEP_DETECTION_DELAY                  1000
#define PEDOMETER_STEP_DETECTION_PERIOD_MS              1000
#define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      5
#define PEDOMETER_ENABLE_ON_START                       true

#define WAKEUP_FOR_BACKGROUND_WORK_STANDBY PEDOMETER_STEP_DETECTION_DELAY
#define WAKEUP_FOR_BACKGROUND_WORK_IDLE 1000

//#define PEDOMETER_DEBUG // Just for teste

#define FORCE_DISPLAY_UPDATE_ON_START // Will quick update screen on start and wakeup. Comment on unknown error.
#define DEFAULT_TIME_TO_POWEROFF_DISPLAY 7
#define DEFAULT_DELAY_TO_FADE_DISPLAY 7

//#define DEBUG_SERIAL

#define SOFTWARE_BUTTONS_BAR_SIZE 0

/*
    ############################################################################################
    #                                                                                          #
    #                                    DEFAULT SETTINGS +                                    #
    #                                                                                          #
    ############################################################################################
*/

