/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR +                                       #
    #                                                                                          #
    ############################################################################################
*/

// background
#ifdef E_PAPER_DISPLAY
    #ifndef STYLE_STATUSBAR_BACKGROUND_RED
        #define STYLE_STATUSBAR_BACKGROUND_RED      0
    #endif
    #ifndef STYLE_STATUSBAR_BACKGROUND_GREEN
        #define STYLE_STATUSBAR_BACKGROUND_GREEN    0
    #endif
    #ifndef STYLE_STATUSBAR_BACKGROUND_BLUE
        #define STYLE_STATUSBAR_BACKGROUND_BLUE     0
    #endif
#else
    #ifndef STYLE_STATUSBAR_BACKGROUND_RED
        #define STYLE_STATUSBAR_BACKGROUND_RED      116
    #endif
    #ifndef STYLE_STATUSBAR_BACKGROUND_GREEN
        #define STYLE_STATUSBAR_BACKGROUND_GREEN    0
    #endif
    #ifndef STYLE_STATUSBAR_BACKGROUND_BLUE
        #define STYLE_STATUSBAR_BACKGROUND_BLUE     176
    #endif
#endif

// text color
#ifdef E_PAPER_DISPLAY
     #ifndef STYLE_STATUSBAR_TEXT_RED
        #define STYLE_STATUSBAR_TEXT_RED      255
    #endif
    #ifndef STYLE_STATUSBAR_TEXT_GREEN
        #define STYLE_STATUSBAR_TEXT_GREEN    255
    #endif
    #ifndef STYLE_STATUSBAR_TEXT_BLUE
        #define STYLE_STATUSBAR_TEXT_BLUE     255
    #endif
#else
    #ifndef STYLE_STATUSBAR_TEXT_RED
        #define STYLE_STATUSBAR_TEXT_RED      255
    #endif
    #ifndef STYLE_STATUSBAR_TEXT_GREEN
        #define STYLE_STATUSBAR_TEXT_GREEN    255
    #endif
    #ifndef STYLE_STATUSBAR_TEXT_BLUE
        #define STYLE_STATUSBAR_TEXT_BLUE     255
    #endif
#endif

#ifdef BATTERY_ENABLE

    // BATTERY CHARGING ICON
    const unsigned char battery_charging[] PROGMEM = {
        //0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xdd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        //0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xF8,0xE0,0x00,0x00,0x1C,0xC0,0x00,0x00,0x0C,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x0C,0xE0,0x00,0x00,0x1C,0x7F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0x00,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0xE4,0xBF,0xFF,0xFF,0xF4,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF4,0x9F,0xFF,0xFF,0xE4,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 100% ICON
    const unsigned char battery100[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0xE4,0xBF,0xFF,0xFF,0xF4,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF4,0x9F,0xFF,0xFF,0xE4,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 90% ICON
    const unsigned char battery90[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x84,0x9F,0xFF,0xFF,0x84,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 80% ICON
    const unsigned char battery80[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x04,0x9F,0xFF,0xFE,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 70% ICON
    const unsigned char battery70[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x04,0x9F,0xFF,0xF0,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 60% ICON
    const unsigned char battery60[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x04,0x9F,0xFF,0x80,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 50% ICON
    const unsigned char battery50[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x04,0x9F,0xFC,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 40% ICON
    const unsigned char battery40[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x04,0x9F,0xF0,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 30% ICON
    const unsigned char battery30[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9F,0x80,0x00,0x04,0xBF,0x80,0x00,0x04,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x04,0x9F,0x80,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 20% ICON
    const unsigned char battery20[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x9C,0x00,0x00,0x04,0xBC,0x00,0x00,0x04,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x04,0x9C,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 10% ICON
    const unsigned char battery10[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x90,0x00,0x00,0x04,0xB0,0x00,0x00,0x04,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x04,0x90,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 0% ICON
    const unsigned char battery0[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xF0,0x40,0x00,0x00,0x08,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x40,0x00,0x00,0x08,0x3F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };
#endif

String core_views_statusBar_draw_time_TimeString = "";
void core_views_statusBar_draw_time(bool draw){
    bool lastLimits = DRAW_LIMITS_getEnable();
    DRAW_LIMITS_setEnable(false);

    #if FONT_SIZE_DEFAULT==1
        #define CORE_VIEWS_STATUSBAR_TIMESTRING_OFFSET 2
    #elif FONT_SIZE_DEFAULT==2
        #define CORE_VIEWS_STATUSBAR_TIMESTRING_OFFSET 0
    #else
        #define CORE_VIEWS_STATUSBAR_TIMESTRING_OFFSET 0
    #endif

    if(draw){
        setDrawColor(STYLE_STATUSBAR_TEXT_RED, STYLE_STATUSBAR_TEXT_GREEN, STYLE_STATUSBAR_TEXT_BLUE);
        core_views_statusBar_draw_time_TimeString = core_time_getHourMinuteTime();
        drawString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + CORE_VIEWS_STATUSBAR_TIMESTRING_OFFSET, FONT_SIZE_DEFAULT);
    }else{
        setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
        clearString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + CORE_VIEWS_STATUSBAR_TIMESTRING_OFFSET, FONT_SIZE_DEFAULT);
    }
    DRAW_LIMITS_setEnable(lastLimits);
}

#ifdef SOFTWARE_BUTTONS_ENABLE
    
    #define SOFTWARE_BUTTON_SIZE (SOFTWARE_BUTTONS_BAR_SIZE/2)

    #define SOFTWARE_BUTTON1_X (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE/2)
    #define SOFTWARE_BUTTON1_Y (SCREEN_HEIGHT)/2

    #define SOFTWARE_BUTTON2_X SOFTWARE_BUTTON1_X 
    #define SOFTWARE_BUTTON2_Y (SOFTWARE_BUTTON1_Y - SOFTWARE_BUTTONS_PADDING)

    #define SOFTWARE_BUTTON3_X SOFTWARE_BUTTON1_X 
    #define SOFTWARE_BUTTON3_Y (SOFTWARE_BUTTON1_Y + SOFTWARE_BUTTONS_PADDING)

    #define SOFTWARE_BUTTON4_X SOFTWARE_BUTTON1_X 
    #define SOFTWARE_BUTTON4_Y (SCREEN_HEIGHT - SOFTWARE_BUTTON_SIZE)

    void core_views_softwareButtons_draw(uint16_t offset, uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t color_red_bg, uint8_t color_green_bg, uint8_t color_blue_bg){
        #ifdef SOFTWARE_BUTTONS_PORITION_RIGHT
            setDrawColor(color_red_bg, color_green_bg, color_blue_bg);
            drawRect(SCREEN_WIDTH-1, offset + 1, SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE, SCREEN_HEIGHT, true);

            setDrawColor(color_red, color_green, color_blue);

            // Button 1
            drawCircle(SOFTWARE_BUTTON1_X, SOFTWARE_BUTTON1_Y, SOFTWARE_BUTTON_SIZE/2, false);
        
            // Button 2
            drawLine(SOFTWARE_BUTTON2_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_Y + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_X, SOFTWARE_BUTTON2_Y - SOFTWARE_BUTTON_SIZE/3);
            drawLine(SOFTWARE_BUTTON2_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_Y + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_X, SOFTWARE_BUTTON2_Y - SOFTWARE_BUTTON_SIZE/3);
            drawLine(SOFTWARE_BUTTON2_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_Y + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON2_Y + SOFTWARE_BUTTON_SIZE/2);

            // Button 3
            drawLine(SOFTWARE_BUTTON3_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_X, SOFTWARE_BUTTON3_Y + SOFTWARE_BUTTON_SIZE/3);
            drawLine(SOFTWARE_BUTTON3_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_X, SOFTWARE_BUTTON3_Y + SOFTWARE_BUTTON_SIZE/3);
            drawLine(SOFTWARE_BUTTON3_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON3_Y - SOFTWARE_BUTTON_SIZE/2);

            // Button 4
            drawLine(SOFTWARE_BUTTON4_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y, SOFTWARE_BUTTON4_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y);            
            drawLine(SOFTWARE_BUTTON4_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y);
            drawLine(SOFTWARE_BUTTON4_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y);
            drawLine(SOFTWARE_BUTTON4_X - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_X, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE);
            drawLine(SOFTWARE_BUTTON4_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_X, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE);
            //drawLine(SOFTWARE_BUTTON4_X + SOFTWARE_BUTTON_SIZE/2, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE/3, SOFTWARE_BUTTON4_X, SOFTWARE_BUTTON4_Y - SOFTWARE_BUTTON_SIZE);
            

            //void drawArc(int x0, int y0, int radius, int drawFromAngle, int drawToAngle, uint16_t width, bool drawFading){
        #else
            // for SOFTWARE_BUTTONS_PORITION_BOTTOM
        #endif
    }

    void core_views_softwareButtons_draw(){
        #ifdef SOFTWARE_BUTTONS_PORITION_RIGHT
            core_views_softwareButtons_draw(STYLE_STATUSBAR_HEIGHT, SOFTWARE_BUTTONS_COLOR_RED,SOFTWARE_BUTTONS_COLOR_GREEN, SOFTWARE_BUTTONS_COLOR_BLUE, SOFTWARE_BUTTONS_COLOR_RED_BG,SOFTWARE_BUTTONS_COLOR_GREEN_BG, SOFTWARE_BUTTONS_COLOR_BLUE_BG);


        #else
            // for SOFTWARE_BUTTONS_PORITION_BOTTOM
        #endif
    }
#endif

#if defined(SOFTWARE_BUTTONS_ENABLE) || defined(SOFTWARE_KEYBOARD_ENABLE)
    uint16_t core_view_isSoftwareButtons_clicked(int x, int y){
        #ifdef SOFTWARE_BUTTONS_ENABLE
            #ifdef SOFTWARE_BUTTONS_PORITION_RIGHT
                if(x>=SCREEN_WIDTH-SOFTWARE_BUTTONS_BAR_SIZE){

                    if ( abs(SOFTWARE_BUTTON1_Y-y)<=SOFTWARE_BUTTONS_BAR_SIZE ){
                        return SOFTWARE_BAR_BUTTON_UP;
                    }

                    if ( abs(SOFTWARE_BUTTON2_Y-y)<=SOFTWARE_BUTTONS_BAR_SIZE ){
                        return SOFTWARE_BAR_BUTTON_SELECT;
                    }

                    if ( abs(SOFTWARE_BUTTON3_Y-y)<=SOFTWARE_BUTTONS_BAR_SIZE ){
                        return SOFTWARE_BAR_BUTTON_DOWN;
                    }

                    if ( abs(SOFTWARE_BUTTON4_Y-y)<=SOFTWARE_BUTTONS_BAR_SIZE ){
                        return SOFTWARE_BAR_BUTTON_BACK;
                    }

                    /*
                    #define SOFTWARE_BUTTON_SIZE (SOFTWARE_BUTTONS_BAR_SIZE/2)

                    #define SOFTWARE_BUTTON1_X (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE/2)
                    #define SOFTWARE_BUTTON1_Y (SCREEN_HEIGHT - offset)/2

                    #define SOFTWARE_BUTTON2_X SOFTWARE_BUTTON1_X 
                    #define SOFTWARE_BUTTON2_Y (SOFTWARE_BUTTON1_Y - SOFTWARE_BUTTONS_PADDING)

                    #define SOFTWARE_BUTTON3_X SOFTWARE_BUTTON1_X 
                    #define SOFTWARE_BUTTON3_Y (SOFTWARE_BUTTON1_Y + SOFTWARE_BUTTONS_PADDING)

                    #define SOFTWARE_BUTTON4_X SOFTWARE_BUTTON1_X 
                    #define SOFTWARE_BUTTON4_Y (SCREEN_HEIGHT - SOFTWARE_BUTTON_SIZE)
                    */
                }
            #endif
        #endif
        return 0;
    }
#else
    uint16_t core_view_isSoftwareButtons_clicked(int x, int y){}
#endif

void core_views_statusBar_draw(){
    /*
            [ TIME | ----- | NOTIFICATIONS | BATTERY ]
    */
    bool DRAW_LIMITS_wasEnable = DRAW_LIMITS_Enabled;
    DRAW_LIMITS_setEnable(false);
    
    // BACKGROUND
    setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
    drawRect(0, 0, SCREEN_WIDTH-1, STYLE_STATUSBAR_HEIGHT, true);

    // TIME
    #ifdef CLOCK_ENABLE
        core_views_statusBar_draw_time(true);
    #endif

    // BATTERY
    #ifdef BATTERY_ENABLE
        core_views_draw_statusbar_battery(true, driver_battery_getPercent());
    #endif

    DRAW_LIMITS_setEnable(DRAW_LIMITS_Enabled);
}

#ifdef BATTERY_ENABLE
    unsigned char batteryCharge_last = 0;
    bool batteryCharge_last_wasCharging = false;
    void core_views_draw_statusbar_battery(bool draw, unsigned char batteryCharge){
        TEMPORARILY_DISABLE_BACKGROUND();

        setBackgroundColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
        if(draw){
            batteryCharge_last = batteryCharge;
            batteryCharge_last_wasCharging = driver_battery_isCharging();
        }

        drawBatteryIcon(SCREEN_WIDTH-32-STYLE_STATUSBAR_HEIGHT/5, STYLE_STATUSBAR_HEIGHT/2 - 8 + 1, batteryCharge_last, batteryCharge_last_wasCharging, draw);

        TEMPORARILY_RESTORE_BACKGROUND();
    }

    void drawBatteryIcon(int x, int y, unsigned char charge, bool isCharging, bool draw){
        const unsigned char *batteryIcon;
        if(charge>=100){
            batteryIcon = battery100;
        }else if(charge>=90){
            batteryIcon = battery90;
        }else if(charge>=80){
            batteryIcon = battery80;
        }else if(charge>=70){
            batteryIcon = battery70;
        }else if(charge>=60){
            batteryIcon = battery60;
        }else if(charge>=50){
            batteryIcon = battery50;
        }else if(charge>=40){
            batteryIcon = battery40;
        }else if(charge>=30){
            batteryIcon = battery30;
        }else if(charge>=20){
            batteryIcon = battery20;
        }else if(charge>=10){
            batteryIcon = battery10;
        }else{
            batteryIcon = battery0;
        }

        if(isCharging){
            drawImage(draw, battery_charging, x, y);
        }else{
            drawImage(draw, batteryIcon, x, y);
        }
    }
#endif

/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST +                                       #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE                  4
#define CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE         20


int core_views_pages_list_get_element_position_x(int pages_quantity, int position){
    return ( (pages_quantity%2==1) ? (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE : -((-CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE/2) ) + (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE);
}

void core_views_draw_pages_list_simple(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity
){
    //SCREEN_WIDTH
    //SCREEN_HEIGHT

    if(draw) setDrawColor(128, 128, 128);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    for(int i=0; i<pages_quantity; i++){
        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, i);
        int element_y = y0;
        drawRect(element_x - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_x + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE);
    }
}

void core_views_draw_active_page(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity,
    unsigned char position
){
    
    #ifdef NARROW_SCREEN
        #define USE_NUMBERS_MAIN_MENU_IN_ACTIVE_PAGES
    #endif

    #ifdef USE_NUMBERS_MAIN_MENU_IN_ACTIVE_PAGES
        //if(draw) setDrawColor(getContrastColor_red(), getContrastColor_green(), getContrastColor_blue());
        #define GRAY_COLOR 164
        if(draw) setDrawColor(GRAY_COLOR, GRAY_COLOR, GRAY_COLOR);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        //drawString_centered(String(position) + "/" + String(pages_quantity), y0, 1);
        String activePageString = String(position + 1) + "/" + String(pages_quantity);
        drawString(activePageString, (SCREEN_WIDTH - activePageString.length()*FONT_CHAR_WIDTH*2)/2, y0 - FONT_CHAR_HEIGHT, 2);
    #else
        if(draw) setDrawColor(0, 255, 0);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, position);
        int element_y = y0;
        drawRect(element_x - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_x + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), true);
    #endif

}

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON +                                    #
    #                                                                                          #
    ############################################################################################
*/


#define CORE_VIEWS_APPICON_IMAGE_WIDTH          32
#define CORE_VIEWS_APPICON_IMAGE_HEIGHT         32
#define CORE_VIEWS_APPICON_IMAGE_Y_OFFSET       -10
#define CORE_VIEWS_APPICON_TITLE_Y_OFFSET       20

#ifdef USE_L_MENU_IMAGES
    #define CORE_VIEWS_APPICON_IMAGE_WIDTH          56 
    #define CORE_VIEWS_APPICON_IMAGE_HEIGHT         56 
    #define CORE_VIEWS_APPICON_IMAGE_Y_OFFSET       -10
    #define CORE_VIEWS_APPICON_TITLE_Y_OFFSET       20
#endif
#ifdef USE_XL_MENU_IMAGES
    #define CORE_VIEWS_APPICON_IMAGE_WIDTH          80
    #define CORE_VIEWS_APPICON_IMAGE_HEIGHT         80
    #define CORE_VIEWS_APPICON_IMAGE_Y_OFFSET       -10
    #define CORE_VIEWS_APPICON_TITLE_Y_OFFSET       45
#endif

void core_views_draw_app_icon(bool draw, int x, int y, const unsigned char* title, const unsigned char* icon){
    // image
    drawImage(draw, icon, x-CORE_VIEWS_APPICON_IMAGE_WIDTH/2, y-CORE_VIEWS_APPICON_IMAGE_HEIGHT/2 + CORE_VIEWS_APPICON_IMAGE_Y_OFFSET);

    // title
    if(draw){
        #ifdef LIGHT_COLOR_THEME
            setDrawColor(0, 0, 0);
        #else 
            setDrawColor(255, 255, 255);
        #endif

        drawString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET, FONT_SIZE_DEFAULT);
    }else{
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        clearString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET, FONT_SIZE_DEFAULT);
    }

}

void drawMenuElement(bool draw, uint16_t x, uint16_t y, uint16_t width, uint16_t height, const unsigned char* icon, String string1, String string2){
    if(draw) setDrawColor(255, 255, 255);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    drawRect( x, y, x + width, y + height, false);

    drawString(string1, x + 36 + 10, y + height/3 - FONT_CHAR_HEIGHT/2);
    //drawString_rightAlign(string2, x + width - 15, y + height*2/3 - FONT_CHAR_HEIGHT/2);
    drawString(string2, x + 36 + 10, y + height*2/3 - FONT_CHAR_HEIGHT/2);

    drawImage(draw, icon, x + 10, y + height/2 - 16/2);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON -                                    #
    #                                                                                          #
    ############################################################################################
*/

#if defined(USE_L_MENU_IMAGES)
    
#elif defined(USE_XL_MENU_IMAGES)

#else
    
#endif

const unsigned char icon_arrow_up[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x3C,0x00,0x00,0x7E,0x00,0x00,0xFF,0x00,0x01,0xFF,0x80,0x03,0xFF,0xC0,0x07,0xFF,0xE0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0xFF,0xFF,0xFF,
};    
const unsigned char icon_arrow_down[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0xFF,0xFF,0xFF,0x7F,0xFF,0xFE,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x07,0xFF,0xE0,0x03,0xFF,0xC0,0x01,0xFF,0x80,0x00,0xFF,0x00,0x00,0x7E,0x00,0x00,0x3C,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

#if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)

    const unsigned char icon_leg[] PROGMEM = {
        0x02,0x01,0x02,0x10,0x02,0x10,0x04,0x00,0x00,0x00,0xC7,0xE3,0x83,0xC1,0x03,0xC1,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x81,0x83,0xC1,0xC3,0xC3,0xFF,0xFF,0xFF,0xFF,0xE3,0xC7,0xC1,0x83,0xC1,0x83,0xE3,0xC7,0x04,0xff,0xff,0xff,0x38,0x1C,0x7C,0x3E,0xFC,0x3E,0xFE,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x7E,0x7C,0x3E,0x3C,0x3C,0x00,0x00,0x00,0x00,0x1C,0x38,0x3E,0x7C,0x3E,0x7C,0x1C,0x38,
    };
    const unsigned char icon_leg_grey[] PROGMEM = {
        0x02,0x01,0x02,0x10,0x02,0x10,0x04,0x00,0x00,0x00,0xC7,0xE3,0x83,0xC1,0x03,0xC1,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x81,0x83,0xC1,0xC3,0xC3,0xFF,0xFF,0xFF,0xFF,0xE3,0xC7,0xC1,0x83,0xC1,0x83,0xE3,0xC7,0x04,0xb4,0xb4,0xb4,0x38,0x1C,0x7C,0x3E,0xFC,0x3E,0xFE,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x7F,0xFE,0x7E,0x7C,0x3E,0x3C,0x3C,0x00,0x00,0x00,0x00,0x1C,0x38,0x3E,0x7C,0x3E,0x7C,0x1C,0x38,
    };

    const unsigned char icon_sleep_grey[] PROGMEM = {
        0x02,0x01,0x02,0x10,0x02,0x10,0x04,0x00,0x00,0x00,0xFC,0x3F,0xF0,0x0F,0xE0,0x07,0xC0,0xF3,0x81,0xF9,0x83,0xFF,0x03,0xFF,0x07,0xFF,0x07,0xFF,0x03,0xFF,0x03,0xFF,0x81,0xF9,0x80,0xF3,0xC0,0x07,0xF0,0x0F,0xFC,0x3F,0x04,0xb4,0xb4,0xb4,0x03,0xC0,0x0F,0xF0,0x1F,0xF8,0x3F,0x0C,0x7E,0x06,0x7C,0x00,0xFC,0x00,0xF8,0x00,0xF8,0x00,0xFC,0x00,0xFC,0x00,0x7E,0x06,0x7F,0x0C,0x3F,0xF8,0x0F,0xF0,0x03,0xC0,
    };
#endif

#ifdef LEGACY_GET_ICONS
    const unsigned char* getIcon(int icon){

        switch (icon){
            #ifdef BATTERY_ENABLE
                case ICON_BATTERY_CHARGING:     return battery_charging;
                case ICON_BATTERY_100:          return battery100;  
                case ICON_BATTERY_90:           return battery90;  
                case ICON_BATTERY_80:           return battery80;  
                case ICON_BATTERY_70:           return battery70;  
                case ICON_BATTERY_60:           return battery60;  
                case ICON_BATTERY_50:           return battery50;  
                case ICON_BATTERY_40:           return battery40;  
                case ICON_BATTERY_30:           return battery30;  
                case ICON_BATTERY_20:           return battery20;  
                case ICON_BATTERY_10:           return battery10;  
                case ICON_BATTERY_0:            return battery0;
            #endif
            #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
                case ICON_LEG:                  return icon_leg;
                case ICON_LEG_GREY:             return icon_leg_grey;
            #endif
            case ICON_ARROW_UP:             return icon_arrow_up;
            case ICON_ARROW_DOWN:           return icon_arrow_down;
            default: return {0};
        }
    
    }

#else
    #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
        const unsigned char* getIcon_legs_white(){
            return icon_leg;
        }

        const unsigned char* getIcon_legs_grey(){
            return icon_leg_grey;
        }

        const unsigned char* getIcon_sleep_grey(){
            return icon_sleep_grey;
        }
    #endif

    const unsigned char* getIcon_arrow_down(){
        return icon_arrow_down;
    }

    const unsigned char* getIcon_arrow_up(){
        return icon_arrow_up;
    }
    
#endif