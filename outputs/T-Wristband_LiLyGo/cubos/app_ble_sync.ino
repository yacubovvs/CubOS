#define appNameClass    BleSync         // App name without spaces
#define appName         "BLE Sync"              // App name with spaces 


#define ACTIVITY_NONE                   0x00
#define ACTIVITY_CONNECT_TO_CHARGE      0x01
#define ACTIVITY_SYNCING                0x02

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;

        void drawActivity(bool draw, byte activity);
        void drawActivity(byte activity);
        void checkCharging();
        unsigned char currentActivity = ACTIVITY_NONE;
      
};

void appNameClass::checkCharging(){
    if(this->currentActivity!=ACTIVITY_SYNCING){
        #ifdef BATTERY_ENABLE
            if(this->currentActivity==ACTIVITY_CONNECT_TO_CHARGE){
                if(driver_battery_isCharging()){
                    drawActivity(ACTIVITY_SYNCING);
                }
                //drawActivity(true, ACTIVITY_CONNECT_TO_CHARGE);
            }else if(this->currentActivity==ACTIVITY_NONE){
                if(driver_battery_isCharging()){
                    drawActivity(ACTIVITY_SYNCING);
                }else{
                    drawActivity(ACTIVITY_CONNECT_TO_CHARGE);
                }
            }
        #else
            drawActivity(ACTIVITY_SYNCING);
        #endif
    }
}

void appNameClass::drawActivity(byte activity){
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);
    this->drawActivity(true, activity);
}

void appNameClass::drawActivity(bool draw, byte activity){

    if(draw){
        this->drawActivity(false, this->currentActivity);
        this->currentActivity = activity;
    }

    if(this->currentActivity==ACTIVITY_CONNECT_TO_CHARGE){
        #ifdef DIVICE_LILYGO_T_WRISTBAND

            #define IMAGE_CONNECT_COLOR_R 0xc0
            #define IMAGE_CONNECT_COLOR_G 0xc0
            #define IMAGE_CONNECT_COLOR_B 0

            const unsigned char chargeIcon[] = {
                    0x02,0x01,0x02,0x10,0x02,0x10,0x04,IMAGE_CONNECT_COLOR_R,IMAGE_CONNECT_COLOR_G,IMAGE_CONNECT_COLOR_B,0x07,0xE0,
                    0x1F,0xF8,0x38,0x1C,0x60,0x06,0x60,0x06,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xFF,0xFF,0xFF,0xFF,
                    0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,};

            if(draw){
                debug("DRAWING ACTIVITY_CONNECT_TO_CHARGE");
                setDrawColor_ContrastColor();
                drawString_centered("Connect the", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
                drawString_centered("charging", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*3, FONT_SIZE_DEFAULT);
                drawString_centered("to sync", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*4, FONT_SIZE_DEFAULT);

                drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 24);
                setDrawColor(IMAGE_CONNECT_COLOR_R, IMAGE_CONNECT_COLOR_G, IMAGE_CONNECT_COLOR_B);
                drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-24);
                drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-24);

                setDrawColor_ContrastColor();
                
            }else{

                debug("CLEARING ACTIVITY_CONNECT_TO_CHARGE");
                setDrawColor_BackGroundColor();
                clearString_centered("Connect the", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
                clearString_centered("charging", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*3, FONT_SIZE_DEFAULT);
                clearString_centered("to sync", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*4, FONT_SIZE_DEFAULT);

                drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 24);
                setDrawColor_BackGroundColor();
                drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-24);
                drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-24);

                setDrawColor_ContrastColor();
            }
        #else

            if(draw){
                setDrawColor_ContrastColor();
                drawString("Connect to charge for synchronization", 5, STYLE_STATUSBAR_HEIGHT + 10, FONT_SIZE_DEFAULT);
            }else{
                setDrawColor_BackGroundColor();
                clearString("Connect to charge for synchronization", 5, STYLE_STATUSBAR_HEIGHT + 10, FONT_SIZE_DEFAULT);
            }
            
        #endif
    }else if(this->currentActivity==ACTIVITY_SYNCING){

        #ifdef DIVICE_LILYGO_T_WRISTBAND

            #define IMAGE_CONNECT_COLOR_R 0
            #define IMAGE_CONNECT_COLOR_G 0xc0
            #define IMAGE_CONNECT_COLOR_B 0

            const unsigned char chargeIcon[] = {
                    0x02,0x01,0x02,0x10,0x02,0x10,0x04,IMAGE_CONNECT_COLOR_R,IMAGE_CONNECT_COLOR_G,IMAGE_CONNECT_COLOR_B,0x07,0xE0,0x1F,0xF8,0x38,0x1C,0x60,0x06,0x60,0x06,0xC0,0x03,0xC0,
                    0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

            const unsigned char sync_process_icon[] = {
                    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0x00,0x66,0xff,0x00,0x7E,0x00,0x03,0xFF,0xC0,0x0F,0xFF,0xF0,0x1F,0xFF,
                    0xF8,0x3F,0xF7,0xFC,0x3F,0xF3,0xFC,0x7F,0xF5,0xFE,0x7F,0xF6,0xFE,0x7F,0x77,0x7E,0xFF,0xB6,0xFF,0xFF,0xD5,
                    0xFF,0xFF,0xE3,0xFF,0xFF,0xE3,0xFF,0xFF,0xD5,0xFF,0xFF,0xB6,0xFF,0x7F,0x77,0x7E,0x7F,0xF6,0xFE,0x7F,0xF5,
                    0xFE,0x3F,0xF3,0xFC,0x3F,0xF7,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x03,0xFF,0xC0,0x00,0x7E,0x00,0x04,0xff,
                    0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x0C,0x00,0x00,
                    0x0A,0x00,0x00,0x09,0x00,0x00,0x88,0x80,0x00,0x49,0x00,0x00,0x2A,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00,
                    0x2A,0x00,0x00,0x49,0x00,0x00,0x88,0x80,0x00,0x09,0x00,0x00,0x0A,0x00,0x00,0x0C,0x00,0x00,0x08,0x00,0x00,
                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

            if(draw){
                setDrawColor_ContrastColor();
                drawString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 15, FONT_SIZE_DEFAULT);
                drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 14);

                drawImage(draw, sync_process_icon, SCREEN_WIDTH/2 - 12, STYLE_STATUSBAR_HEIGHT + 38);

                setDrawColor(IMAGE_CONNECT_COLOR_R, IMAGE_CONNECT_COLOR_G, IMAGE_CONNECT_COLOR_B);
                drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-14);
                drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-14);
                //
            }else{
                setDrawColor_BackGroundColor();
                clearString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 15, FONT_SIZE_DEFAULT);
                drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 14);

                drawImage(draw, sync_process_icon, SCREEN_WIDTH/2 - 12, STYLE_STATUSBAR_HEIGHT + 38);

                setDrawColor_BackGroundColor();
                drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-14);
                drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-14);   
            }
        #else
            if(draw){
                setDrawColor_ContrastColor();
                drawString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
            }else{
                setDrawColor_BackGroundColor();
                clearString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
            }
        #endif 
        
    }
    
}

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */

    this->preventSleep         = true;
    //this->preventInAppSleep    = true;

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);
    //setDrawColor_ContrastColor();

    drawActivity(ACTIVITY_CONNECT_TO_CHARGE);
    this->checkCharging();
    //drawActivity(true, ACTIVITY_CONNECT_TO_CHARGE);
    //drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, FONT_SIZE_DEFAULT);
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

void appNameClass::onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5){

    if(event==EVENT_ON_BATTERY_VALUE_CHANGE){
        //debug("EVENT_ON_BATTERY_VALUE_CHANGE " + String(val1) + " " + String(val2));        
    }else if(event==EVENT_ON_BATTERY_CHARGING_CHANGE){
        this->checkCharging();
    }


    #ifdef TOUCH_SCREEN_ENABLE

        if(event==EVENT_ON_TOUCH_DRAG){
            // SCREEN SCROLL
        }

    #else

        /**/
        #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
            
            if(event==EVENT_BUTTON_PRESSED){
            }else if(event==EVENT_BUTTON_RELEASED){
            }else if(event==EVENT_BUTTON_LONG_PRESS){
                if(val1==BUTTON_SELECT){
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }    
            }else if(event==EVENT_BUTTON_SHORT_PRESS){
            }else if(event==EVENT_BUTTON_SHORT_SINGLE_PRESS){
                if(val1==BUTTON_SELECT){
                }else if(val1==BUTTON_BACK){
                }
            }else if(event==EVENT_BUTTON_DOUBLE_PRESS){
                #if (DRIVER_CONTROLS_TOTALBUTTONS == 1)
                    if(val1==BUTTON_SELECT){
                        startApp(-1);
                    }
                #else
                #endif
                
            }
            
        #else
            if(event==EVENT_BUTTON_PRESSED){
                switch(val1){
                    case BUTTON_UP:
                        break;
                    case BUTTON_BACK:
                        break;
                    case BUTTON_DOWN:
                        break;
                    case BUTTON_SELECT:
                        break;
                }
                
            
            }else if(event==EVENT_BUTTON_RELEASED){

            }else if(event==EVENT_BUTTON_LONG_PRESS){

            }
        #endif
    
    #endif
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x66,0xff,0x03,0xFF,0xFF,0xC0,0x0F,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,
    0xFF,0xFC,0x7F,0xFC,0x7F,0xFE,0x7F,0xFC,0x3F,0xFE,0xFF,0xFC,0x9F,0xFF,0xFF,0xFC,0xCF,0xFF,0xFF,0xFC,0xE7,0xFF,0xFF,0xBC,
    0xF3,0xFF,0xFF,0x9C,0xF9,0xFF,0xFF,0xCC,0xF9,0xFF,0xFF,0xE4,0xF3,0xFF,0xFF,0xF0,0xE7,0xFF,0xFF,0xF8,0x8F,0xFF,0xFF,0xFC,
    0x1F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,0x8F,0xFF,0xFF,0xF0,0xE7,0xFF,0xFF,0xE4,0xF3,0xFF,0xFF,0xCC,0xF9,0xFF,0xFF,0x9C,
    0xF9,0xFF,0xFF,0xBC,0xF3,0xFF,0xFF,0xFC,0xE7,0xFF,0xFF,0xFC,0xCF,0xFF,0xFF,0xFC,0x9F,0xFF,0x7F,0xFC,0x3F,0xFE,0x7F,0xFC,
    0x7F,0xFE,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,0x0F,0xFF,0xFF,0xF0,0x03,0xFF,0xFF,0xC0,0x04,0xff,0xff,0xff,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,
    0x60,0x00,0x00,0x03,0x30,0x00,0x00,0x03,0x18,0x00,0x00,0x43,0x0C,0x00,0x00,0x63,0x06,0x00,0x00,0x33,0x06,0x00,0x00,0x1B,
    0x0C,0x00,0x00,0x0F,0x18,0x00,0x00,0x07,0x70,0x00,0x00,0x03,0xE0,0x00,0x00,0x03,0xE0,0x00,0x00,0x07,0x70,0x00,0x00,0x0F,
    0x18,0x00,0x00,0x1B,0x0C,0x00,0x00,0x33,0x06,0x00,0x00,0x63,0x06,0x00,0x00,0x43,0x0C,0x00,0x00,0x03,0x18,0x00,0x00,0x03,
    0x30,0x00,0x00,0x03,0x60,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
};