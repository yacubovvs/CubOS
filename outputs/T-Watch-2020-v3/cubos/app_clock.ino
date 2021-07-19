
#define appNameClass    ClockApp          // App name without spaces
#define appName         "Clock"              // App name with spaces 

#ifndef APP_CLOCK_POWER_AFTER_SECONDS
    #define APP_CLOCK_POWER_AFTER_SECONDS 0 
#endif

#ifdef PLATFORM_PC_EMULATOR
    long get_pedometer_days_steps(){
        return 8715;
    }
#endif

class appNameClass: public Application{
    public:
        bool isfullScreen         = true;
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0); 
            this->showStatusBar = false;
            super_onCreate(); 
            onCreate(); 
        };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;

        void draw_current_time(bool draw);
        String timeString;

        unsigned char last_seconds  = 0;
        String last_hours           = "";
        String last_minutes         = "";

        String last_date            = "";
        String sleep_time           = "";

        #ifdef BATTERY_ENABLE
            unsigned char last_battery  = 0;
            bool last_battery_charging  = "";
        #endif

        #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
            unsigned int last_pedometer   = 0;
        #endif

        void drawSecondsCircle(bool draw, unsigned char second);
        #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
            void drawStepsCircle(bool draw);
        #endif
      
};

#define BATTERY_LABEL_Y_POSITION (STYLE_STATUSBAR_HEIGHT/2 + 2)

#ifdef NARROW_SCREEN
    // For small screens as sport wristbands
    #define SECONDS_CIRCLE_X        (SCREEN_WIDTH/2)
    #define SECONDS_CIRCLE_Y        (SCREEN_HEIGHT/2 - 20)
    #define SECONDS_CIRCLE_RADIUS   (SCREEN_WIDTH/2-2)
#else
    // Big screens as 240x240 
    #define SECONDS_CIRCLE_X        (SCREEN_WIDTH/2)
    #define SECONDS_CIRCLE_Y        (SCREEN_HEIGHT/2)
    #define SECONDS_CIRCLE_RADIUS   (SCREEN_WIDTH/2-30)
#endif 


#if defined(PEDOMETER_ENABLE) //|| defined(PEDOMETER_EMULATOR)
    void appNameClass::drawStepsCircle(bool draw){
        if(draw){
            
            #ifdef PEDOMETER_EMULATOR
                int grad_i = 183;
            #else
                int grad_i = (long)360 * (long)get_pedometer_days_steps() / (long)get_pedometer_days_steps_min_limit();
            #endif

            if(grad_i>360) grad_i = 360;
            for(int grad=0; grad<=grad_i; grad++){
                
                setGradientColor(46, 255, 0, 255, 85, 0, 360, grad);
                drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-4, -90 + grad, -90 + grad + 2, 8, true);
            }
        }else{
            setDrawColor_BackGroundColor();
            int grad = 360;
            drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-4, -90 + 0, -90 + grad + 8, 8, true);
        }
    }
#endif

void appNameClass::onCreate(){
    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);

    setDrawColor(48, 48, 48);
    drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-2, true);

    this->last_seconds = core_time_getSeconds_byte();
    for(unsigned char isecond=0; isecond<=this->last_seconds; isecond++) this->drawSecondsCircle(true, isecond);
    this->draw_current_time(true);

    #if defined(PEDOMETER_ENABLE) //|| defined(PEDOMETER_EMULATOR)
        this->drawStepsCircle(true);
    #endif

    this->sleep_device_after = APP_CLOCK_POWER_AFTER_SECONDS;

}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        #if DRIVER_CONTROLS_TOTALBUTTONS > 3
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        #else 
            if(val1==BUTTON_POWER){
                startApp(-1);
            }    
        #endif
        
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
        if(val1==BUTTON_SELECT){

            #if DRIVER_CONTROLS_TOTALBUTTONS == 1
                startApp(-1);
            #elif DRIVER_CONTROLS_TOTALBUTTONS == 2
                startApp(-1);
            #else
            #endif
        }
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
        this->draw_current_time(false);
        this->draw_current_time(true);
    }else if(event==EVENT_ON_GOING_TO_SLEEP){
        this->draw_current_time(false);
    }else if(event==EVENT_ON_WAKE_UP){
        this->draw_current_time(true);
    }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
        if(val1==BUTTON_SELECT){
            startApp(-1);
        }
    }
    
}

void appNameClass::drawSecondsCircle(bool draw, unsigned char second){
    if(draw) setDrawColor(0, 0, 255);
    else setDrawColor_BackGroundColor();

    int grad = 6*second;
 
    drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS, -90 + grad, -90 + grad + 6, 4, true);
}

void appNameClass::draw_current_time(bool draw){
    #ifdef NARROW_SCREEN
        // For small screens as sport wristbands
        #define CLOCK_FONT        2
        #define CLOCK_MARGIN      3
        #define STRINGS_OFFSET_Y  2
    #else
        // Big screens as 240x240 
        #define CLOCK_FONT        4
        #define CLOCK_MARGIN      3
        #define STRINGS_OFFSET_Y  (-8)
    #endif 


    //this->preventSleep         = true;
    //this->preventInAppSleep    = true;


    // Draw
    if(draw){
        // SECONDS CIRCLE
        this->timeString = core_time_getHourMinuteSecondsTime();
        unsigned char seconds_draw;
        if(core_time_getSeconds_byte()>this->last_seconds) seconds_draw = core_time_getSeconds_byte() - this->last_seconds;
        else seconds_draw = 1;
        
        this->last_seconds = core_time_getSeconds_byte();
        for(char i_predrawSeconds=0; i_predrawSeconds<seconds_draw; i_predrawSeconds++) this->drawSecondsCircle(draw, this->last_seconds-i_predrawSeconds);

        setDrawColor_ContrastColor();

        this->last_hours    = core_time_getHours_String();
        this->last_minutes  = core_time_getMinutes_String();

        drawString_centered(core_time_getHours_String(), SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
        drawString_centered(core_time_getMinutes_String(), SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y + CLOCK_MARGIN, CLOCK_FONT);
        
        #ifdef NARROW_SCREEN
            // For small screens as sport wristbands
        #else
            // Big screens as 240x240 
            drawString_centered(core_time_getWeekDay_string(), SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y + CLOCK_MARGIN + 30, 1);
        #endif 
    }else{
        if(this->last_seconds>core_time_getSeconds_byte()){
            // if munutes changed
            setDrawColor_BackGroundColor();  
            for(int isecond=0; isecond<60; isecond++){
                drawSecondsCircle(draw, isecond);
            }

            setDrawColor(48, 48, 48);
            drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-2, true);
            
            clearString_centered(last_hours, SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
            clearString_centered(last_minutes, SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y + CLOCK_MARGIN, CLOCK_FONT);

            #ifdef NARROW_SCREEN
                // For small screens as sport wristbands
            #else
                // Big screens as 240x240 
                clearString_centered(core_time_getWeekDay_string(), SCREEN_WIDTH/2, STRINGS_OFFSET_Y + SECONDS_CIRCLE_Y + CLOCK_MARGIN + 30, 1);
            #endif 
        }

    }


    // BATTERY
    #ifdef BATTERY_ENABLE

        
        if(draw){        
            last_battery            = driver_battery_getPercent();
            last_battery_charging   = driver_battery_isCharging();
        }

        String battery_percent_toPrint = String(last_battery) + "%";

        #ifdef NARROW_SCREEN
            // For small screens as sport wristbands
            #define APP_CLOCK_ICON_X (SCREEN_WIDTH/2 + -1)
            #define APP_CLOCK_ICON_Y (BATTERY_LABEL_Y_POSITION - 10)
            #define APPP_CLOCK_BATTERY_LABEL_X (SCREEN_WIDTH/2 - battery_percent_toPrint.length()*FONT_CHAR_WIDTH - 7)
            #define APPP_CLOCK_BATTERY_LABEL_Y ( BATTERY_LABEL_Y_POSITION - FONT_CHAR_HEIGHT/2 -2)
        #else
            // Big screens as 240x240 
            #define APP_CLOCK_ICON_X (SCREEN_WIDTH - 38)
            #define APP_CLOCK_ICON_Y (BATTERY_LABEL_Y_POSITION - 10)
            #define APPP_CLOCK_BATTERY_LABEL_X (SCREEN_WIDTH - battery_percent_toPrint.length()*FONT_CHAR_WIDTH - 42)
            #define APPP_CLOCK_BATTERY_LABEL_Y ( BATTERY_LABEL_Y_POSITION - FONT_CHAR_HEIGHT/2 -2)
        #endif 
            
            
        // (battery icon 32x16 px) 
        drawBatteryIcon(APP_CLOCK_ICON_X, APP_CLOCK_ICON_Y, last_battery, last_battery_charging, draw);
        
        if(draw){
            setDrawColor_ContrastColor();
            drawString(battery_percent_toPrint, APPP_CLOCK_BATTERY_LABEL_X, APPP_CLOCK_BATTERY_LABEL_Y, 1);
        }else{
            setDrawColor_BackGroundColor();  
            clearString(battery_percent_toPrint, APPP_CLOCK_BATTERY_LABEL_X, APPP_CLOCK_BATTERY_LABEL_Y, 1);
        }
        

    #endif        

    #ifdef NARROW_SCREEN
        // For small screens as sport wristbands
        // SLEEP LABEL
        #define SLEEP_LABEL_POSITION_Y (SCREEN_HEIGHT - 35)
        // DATE LABEL
        #define DATE_LABEL_POSITION_Y (SCREEN_HEIGHT - 54)
        #define DATE_LABEL_POSITION_X (SCREEN_WIDTH/2)
        #define DATE_DRAW_STRING(A,B,C,D) drawString_centered(A,B,C,D)
        #define DATE_CLEAR_STRING(A,B,C,D) clearString_centered(A,B,C,D)
        // PEDOMETER LABEL
        #define PEDOMETER_LABEL_POSITION_Y (SCREEN_HEIGHT - 14)
        #define PEDOMETER_LABEL_POSITION_X_OFFSET (0)
        #define PEDOMETER_LABEL_POSITION_PADDING (3)
    #else
        // Big screens as 240x240 
        // SLEEP LABEL
        #define SLEEP_LABEL_POSITION_Y (SCREEN_HEIGHT - 14)
        // DATE LABEL
        #define DATE_LABEL_POSITION_Y (APPP_CLOCK_BATTERY_LABEL_Y)
        #define DATE_LABEL_POSITION_X (7)
        #define DATE_DRAW_STRING(A,B,C,D) drawString(A,B,C,D)
        #define DATE_CLEAR_STRING(A,B,C,D) clearString(A,B,C,D)

        // PEDOMETER LABEL
        #define PEDOMETER_LABEL_POSITION_Y (SCREEN_HEIGHT - 14)
        #define PEDOMETER_LABEL_POSITION_X_OFFSET (0)
        #define PEDOMETER_LABEL_POSITION_PADDING (3)
    #endif 
    

    if(draw){
        this->last_date = core_time_getDateFull();
        setDrawColor(192,192,192);
        DATE_DRAW_STRING(this->last_date, DATE_LABEL_POSITION_X, DATE_LABEL_POSITION_Y, 1);
    }else{
        setDrawColor_BackGroundColor();  
        DATE_CLEAR_STRING(this->last_date, DATE_LABEL_POSITION_X, DATE_LABEL_POSITION_Y, 1);
    }

    #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
        
        if(draw){
            this->last_pedometer = get_pedometer_days_steps();
            #ifdef PLATFORM_PC_EMULATOR
                this->sleep_time = String(5.82);
            #else
                this->sleep_time = get_pedometer_days_sleep_hours();
            #endif
        }

        String pedometer_toPrint = String(this->last_pedometer);
        String sleep_toPrint = String(this->sleep_time) + "  ";

            
        // 16px - leg and sleep icon width
        int pedometer_label_width_05 = (PEDOMETER_LABEL_POSITION_PADDING*2 + 16 + pedometer_toPrint.length()*FONT_CHAR_WIDTH)/2;
        int sleep_label_width_05 = (PEDOMETER_LABEL_POSITION_PADDING*2 + 16 + sleep_toPrint.length()*FONT_CHAR_WIDTH)/2;

        #ifdef NARROW_SCREEN
            // For small screens as sport wristbands
            #define PEDOMETER_ICON_POSITION_X   (SCREEN_WIDTH/2 + pedometer_label_width_05 - 16 + PEDOMETER_LABEL_POSITION_X_OFFSET)
            #define PEDOMETER_ICON_POSITION_Y   (PEDOMETER_LABEL_POSITION_Y + PEDOMETER_LABEL_POSITION_PADDING - 9)
            #define SLEEP_ICON_POSITION_X       (SCREEN_WIDTH/2 + sleep_label_width_05 - 16 + PEDOMETER_LABEL_POSITION_X_OFFSET)
            #define SLEEP_ICON_POSITION_Y       (SLEEP_LABEL_POSITION_Y + PEDOMETER_LABEL_POSITION_PADDING - 9)
        #else
            // Big screens as 240x240 
            #define PEDOMETER_ICON_POSITION_X   (SCREEN_WIDTH - 21)
            #define PEDOMETER_ICON_POSITION_Y   (SCREEN_HEIGHT - 19)
            #define SLEEP_ICON_POSITION_X       (5)
            #define SLEEP_ICON_POSITION_Y       (SCREEN_HEIGHT - 19)
        #endif 

        drawImage(draw, getIcon_legs_grey(), PEDOMETER_ICON_POSITION_X, PEDOMETER_ICON_POSITION_Y);
        drawImage(draw, getIcon_sleep_grey(), SLEEP_ICON_POSITION_X, SLEEP_ICON_POSITION_Y);

        #ifdef NARROW_SCREEN
            // For small screens as sport wristbands
            #define PEDOMETER_LABEL_X (SCREEN_WIDTH/2 - pedometer_label_width_05 + PEDOMETER_LABEL_POSITION_X_OFFSET)
            #define PEDOMETER_LABEL_Y (PEDOMETER_LABEL_POSITION_Y + 1)
            #define PEDOMETER_LABEL_SIZE (1)
            #define DRAW_PEDOMETER_LABEL(A,B,C,D) drawString(A,B,C,D)
            #define CLEAR_PEDOMETER_LABEL(A,B,C,D) clearString(A,B,C,D)

            #define SLEEP_LABEL_X (SCREEN_WIDTH/2)
            #define SLEEP_LABEL_Y (SLEEP_LABEL_POSITION_Y)
            #define SLEEP_LABEL_SIZE (1)
            #define DRAW_SLEEP_LABEL(A,B,C,D) drawString_centered(A,B,C,D)
            #define CLEAR_SLEEP_LABEL(A,B,C,D) clearString_centered(A,B,C,D)
        #else
            // Big screens as 240x240 
            #define PEDOMETER_LABEL_X (SCREEN_WIDTH - pedometer_label_width_05 - 28)
            #define PEDOMETER_LABEL_Y (PEDOMETER_LABEL_POSITION_Y)
            #define PEDOMETER_LABEL_SIZE (1)
            #define DRAW_PEDOMETER_LABEL(A,B,C,D) drawString(A,B,C,D)
            #define CLEAR_PEDOMETER_LABEL(A,B,C,D) drawString(A,B,C,D)

            #define SLEEP_LABEL_X (45)
            #define SLEEP_LABEL_Y (SLEEP_LABEL_POSITION_Y)
            #define SLEEP_LABEL_SIZE (1)
            #define DRAW_SLEEP_LABEL(A,B,C,D) drawString_centered(A,B,C,D)
            #define CLEAR_SLEEP_LABEL(A,B,C,D) drawString_centered(A,B,C,D)
        #endif 

        if(draw){
            setDrawColor(192,192,192);
            // PEDOMETER
            DRAW_PEDOMETER_LABEL(pedometer_toPrint, PEDOMETER_LABEL_X, PEDOMETER_LABEL_Y, PEDOMETER_LABEL_SIZE);
            // SLEEP
            DRAW_SLEEP_LABEL(sleep_toPrint, SLEEP_LABEL_X, SLEEP_LABEL_Y, SLEEP_LABEL_SIZE);

        }else{
            setDrawColor_BackGroundColor();  
            // PEDOMETER
            CLEAR_PEDOMETER_LABEL(pedometer_toPrint, PEDOMETER_LABEL_X, PEDOMETER_LABEL_Y, PEDOMETER_LABEL_SIZE);
            // SLEEP
            CLEAR_SLEEP_LABEL(sleep_toPrint, SLEEP_LABEL_X, SLEEP_LABEL_Y, SLEEP_LABEL_SIZE);
        }
        
    #endif
        
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x3F,0xFC,0x00,0x00,
    0xFF,0xFF,0x00,0x01,0xFF,0xFF,0x80,0x03,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xE0,0x19,0xFF,0xFF,0x80,
    0x18,0x7F,0xFE,0x00,0x3E,0x1F,0xF8,0x1C,0x3F,0x87,0xE0,0x7C,0x3F,0xE1,0x81,0xFC,0x3F,0xF8,0x07,0xFC,0x3F,0xFE,0x1F,0xFC,0x3F,0xFE,0x7F,
    0xFC,0x3F,0xFE,0x7F,0xFC,0x3F,0xFE,0x7F,0xFC,0x1F,0xFE,0x7F,0xF8,0x1F,0xFE,0x7F,0xF8,0x0F,0xFE,0x7F,0xF0,0x0F,0xFE,0x7F,0xF0,0x07,0xFE,
    0x7F,0xE0,0x03,0xFE,0x7F,0xC0,0x01,0xFE,0x7F,0x80,0x00,0xFE,0x7F,0x00,0x00,0x3E,0x7C,0x00,0x00,0x0E,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1C,0x06,0x00,0x00,0x78,0x07,0x80,0x01,
    0xE0,0x01,0xE0,0x07,0x80,0x00,0x78,0x1E,0x00,0x00,0x1E,0x78,0x00,0x00,0x07,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xb4,0xb4,0xb4,0x00,0x0F,0xF0,0x00,0x00,0x7F,0xFE,0x00,0x01,0xF0,0x0F,0x80,0x03,0xC0,0x03,0xC0,0x07,0x00,0x00,0xE0,0x0E,0x00,0x00,
    0x70,0x1C,0x00,0x00,0x38,0x38,0x00,0x00,0x1C,0x30,0x00,0x00,0x08,0x60,0x00,0x00,0x02,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0xC0,0x00,
    0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,
    0x00,0x00,0x03,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0x70,0x00,0x00,0x0E,0x30,0x00,0x00,0x0C,0x38,0x00,0x00,0x1C,0x1C,0x00,0x00,0x38,
    0x0E,0x00,0x00,0x70,0x07,0x00,0x00,0xE0,0x03,0xC0,0x03,0xC0,0x01,0xF0,0x0F,0x80,0x00,0x7E,0x7E,0x00,0x00,0x0E,0x70,0x00,0x04,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,
    0x00,0x01,0x80,0x00,0x00,0x06,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,
    0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,

   
};
