#define appNameClass    BleSync         // App name without spaces
#define appName         "BLE Sync"      // App name with spaces 

#define IMAGE_NOT_CONNECTED_COLOR_R 0xc0
#define IMAGE_NOT_CONNECTED_COLOR_G 0xc0
#define IMAGE_NOT_CONNECTED_COLOR_B 0

#define IMAGE_NOT_CONNECTED_ALERT_COLOR_R 0xff
#define IMAGE_NOT_CONNECTED_ALERT_COLOR_G 0
#define IMAGE_NOT_CONNECTED_ALERT_COLOR_B 0

#define IMAGE_CONNECT_COLOR_R 0
#define IMAGE_CONNECT_COLOR_G 0xc0
#define IMAGE_CONNECT_COLOR_B 0

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
            fillScreen(0, 0, 0);
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

        void drawActivity(bool draw, byte activity);
        void drawActivity(byte activity);
        void checkCharging();
        void drawSyncIconAnimation(bool draw, bool onlyBgDraw);
        void draw_charging_plug(bool draw, bool ischarging, unsigned char r, unsigned char g, unsigned char b);
        
        uint16_t drawSyncIconAnimation_lastK = 0;
        unsigned char currentActivity = ACTIVITY_NONE;
      
};

void appNameClass::draw_charging_plug(bool draw, bool ischarging, unsigned char r, unsigned char g, unsigned char b){
    #ifdef DIVICE_LILYGO_T_WRISTBAND

        if(ischarging){
            const unsigned char chargeIcon[] = {
                0x02,0x01,0x02,0x10,0x02,0x10,0x04,r,g,b,0x07,0xE0,0x1F,0xF8,0x38,0x1C,0x60,0x06,0x60,0x06,0xC0,0x03,0xC0,
                0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            };

            if(draw){
                setDrawColor(r, g, b);
            }else{
                setDrawColor_BackGroundColor();
            }

            drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 14);
            drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-14);
            drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-14);
        }else{
            const unsigned char chargeIcon[] = {
                0x02,0x01,0x02,0x10,0x02,0x10,0x04,r,g,b,0x07,0xE0,
                0x1F,0xF8,0x38,0x1C,0x60,0x06,0x60,0x06,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xC0,0x03,0xFF,0xFF,0xFF,0xFF,
                0x0C,0x30,0x0C,0x30,0x0C,0x30,0x0C,0x30,
            };

            if(draw){
                setDrawColor(r, g, b);
            }else{
                setDrawColor_BackGroundColor();
            }

            drawImage(draw, chargeIcon, SCREEN_WIDTH/2 - 7, SCREEN_HEIGHT - 24);
            drawLine(SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2, SCREEN_HEIGHT-24);
            drawLine(SCREEN_WIDTH/2+1, STYLE_STATUSBAR_HEIGHT + 10*8, SCREEN_WIDTH/2+1, SCREEN_HEIGHT-24);
        }
        
    #else
    #endif
}

void appNameClass::drawSyncIconAnimation(bool draw, bool onlyBgDraw){
    #define MIN_K_PREVALUE 64
    #define MAX_K_PREVALUE 255

    uint16_t k = (millis()/3)%( (MAX_K_PREVALUE - MIN_K_PREVALUE)*2) + MIN_K_PREVALUE;
    if(k==drawSyncIconAnimation_lastK) return;
    drawSyncIconAnimation_lastK = k;

    unsigned char icon_circle_red = 0x00;
    unsigned char icon_circle_green = 0x66;
    unsigned char icon_circle_blue = 0xff;

    if(k<=MAX_K_PREVALUE){
        icon_circle_green = (unsigned char)((uint16_t)0x66 * k / 255);
        icon_circle_blue = (unsigned char)((uint16_t)0xff * k / 255);
    }else{
        icon_circle_green = (unsigned char)((uint16_t)0x66 * (MAX_K_PREVALUE*2-k) / 255);
        icon_circle_blue = (unsigned char)((uint16_t)0xff * (MAX_K_PREVALUE*2-k) / 255);
    }
    
    if(onlyBgDraw){
        const unsigned char sync_process_icon[] = {
            0x02,0x01,0x02,0x18,0x02,0x18,0x04,icon_circle_red,icon_circle_green,icon_circle_blue,0x00,0xFF,0x00,0x07,0xFF,0xE0,0x1F,0xFF,0xF8,0x3F,0xFF,
            0xFC,0x3F,0xF7,0xFC,0x7F,0xF3,0xFE,0x7F,0xF5,0xFE,0x7F,0xF6,0xFE,0xFF,0x77,0x7F,0xFF,0xB6,0xFF,0xFF,0xD5,
            0xFF,0xFF,0xE3,0xFF,0xFF,0xE3,0xFF,0xFF,0xD5,0xFF,0xFF,0xB6,0xFF,0xFF,0x77,0x7F,0x7F,0xF6,0xFE,0x7F,0xF5,
            0xFE,0x7F,0xF3,0xFE,0x3F,0xF7,0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x07,0xFF,0xE0,0x00,0xFF,0x00,
        };

        drawImage(draw, sync_process_icon, SCREEN_WIDTH/2 - 12, STYLE_STATUSBAR_HEIGHT + 38);
    }else{
        const unsigned char sync_process_icon[] PROGMEM = {
            0x02,0x01,0x02,0x18,0x02,0x18,0x04,0x00,0x66,0xff,0x00,0xFF,0x00,0x07,0xFF,0xE0,0x1F,0xFF,0xF8,0x3F,0xFF,
            0xFC,0x3F,0xF7,0xFC,0x7F,0xF3,0xFE,0x7F,0xF5,0xFE,0x7F,0xF6,0xFE,0xFF,0x77,0x7F,0xFF,0xB6,0xFF,0xFF,0xD5,
            0xFF,0xFF,0xE3,0xFF,0xFF,0xE3,0xFF,0xFF,0xD5,0xFF,0xFF,0xB6,0xFF,0xFF,0x77,0x7F,0x7F,0xF6,0xFE,0x7F,0xF5,
            0xFE,0x7F,0xF3,0xFE,0x3F,0xF7,0xFC,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x07,0xFF,0xE0,0x00,0xFF,0x00,0x04,0xff,
            0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x0C,0x00,0x00,
            0x0A,0x00,0x00,0x09,0x00,0x00,0x88,0x80,0x00,0x49,0x00,0x00,0x2A,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00,
            0x2A,0x00,0x00,0x49,0x00,0x00,0x88,0x80,0x00,0x09,0x00,0x00,0x0A,0x00,0x00,0x0C,0x00,0x00,0x08,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        };

        drawImage(draw, sync_process_icon, SCREEN_WIDTH/2 - 12, STYLE_STATUSBAR_HEIGHT + 38);
    }
    
}

void appNameClass::checkCharging(){
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);

    #ifdef BATTERY_ENABLE
        if(driver_battery_isCharging()){
            this->draw_charging_plug(false, false, IMAGE_NOT_CONNECTED_COLOR_R, IMAGE_NOT_CONNECTED_COLOR_G, IMAGE_NOT_CONNECTED_COLOR_B);
            this->draw_charging_plug(true, true, IMAGE_CONNECT_COLOR_R, IMAGE_CONNECT_COLOR_G, IMAGE_CONNECT_COLOR_B);
        }else{
            this->draw_charging_plug(false, true, IMAGE_CONNECT_COLOR_R, IMAGE_CONNECT_COLOR_G, IMAGE_CONNECT_COLOR_B);
            if(this->currentActivity==ACTIVITY_SYNCING){
                this->draw_charging_plug(true, false, IMAGE_NOT_CONNECTED_ALERT_COLOR_R, IMAGE_NOT_CONNECTED_ALERT_COLOR_G, IMAGE_NOT_CONNECTED_ALERT_COLOR_B);
            }else{
                this->draw_charging_plug(true, false, IMAGE_NOT_CONNECTED_COLOR_R, IMAGE_NOT_CONNECTED_COLOR_G, IMAGE_NOT_CONNECTED_COLOR_B);
            }
        }
        
    #endif
    
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

    if(this->currentActivity==ACTIVITY_SYNCING){
        core_ble_sync_setup();
        core_ble_sync_start();
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

        if(this->currentActivity==ACTIVITY_SYNCING){
            this->preventInAppSleep    = true;
        }else{
            this->preventInAppSleep    = false;
        }
    }

    if(this->currentActivity==ACTIVITY_CONNECT_TO_CHARGE){
        #ifdef DIVICE_LILYGO_T_WRISTBAND

            //this->draw_charging_plug(draw, false, IMAGE_NOT_CONNECTED_COLOR_R, IMAGE_NOT_CONNECTED_COLOR_G, IMAGE_NOT_CONNECTED_COLOR_B);

            if(draw){
                //debug("DRAWING ACTIVITY_CONNECT_TO_CHARGE");
                setDrawColor_ContrastColor();
                drawString_centered("Connect the", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
                drawString_centered("charging", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*3, FONT_SIZE_DEFAULT);
                drawString_centered("to sync", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*4, FONT_SIZE_DEFAULT);
                setDrawColor_ContrastColor();
            }else{

                //debug("CLEARING ACTIVITY_CONNECT_TO_CHARGE");
                setDrawColor_BackGroundColor();
                clearString_centered("Connect the", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*2, FONT_SIZE_DEFAULT);
                clearString_centered("charging", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*3, FONT_SIZE_DEFAULT);
                clearString_centered("to sync", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 10*4, FONT_SIZE_DEFAULT);
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
            
            //this->draw_charging_plug(draw, true, IMAGE_CONNECT_COLOR_R, IMAGE_CONNECT_COLOR_G, IMAGE_CONNECT_COLOR_B);

            if(draw){
                setDrawColor_ContrastColor();
                drawString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 15, FONT_SIZE_DEFAULT);
                this->drawSyncIconAnimation(draw, false);
            }else{
                setDrawColor_BackGroundColor();
                clearString_centered("Syncing", SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + 15, FONT_SIZE_DEFAULT);
                this->drawSyncIconAnimation(draw, false);
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

    this->preventSleep         = true;

    this->preventInAppSleep    = false;

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);

    this->checkCharging();
}

void appNameClass::onLoop(){
    if(this->currentActivity==ACTIVITY_SYNCING){
        this->drawSyncIconAnimation(true, true);
    }
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