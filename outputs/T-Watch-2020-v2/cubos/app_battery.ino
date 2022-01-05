
#define appNameClass                        BatteryApp              // App name without spaces
#define appName                             "Battery"              // App name with spaces 

#ifndef APP_BATTERY_UPDATE_EVERY_MS
    #define APP_BATTERY_UPDATE_EVERY_MS         500
#endif

#ifndef APP_BATTERY_FONT_SIZE
    #define APP_BATTERY_FONT_SIZE FONT_SIZE_DEFAULT
#endif

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5) override;

        void onCreate();
        appNameClass(){ 
            #ifdef LIGHT_COLOR_THEME
                fillScreen(255, 255, 255); 
            #else
                fillScreen(0, 0, 0); 
            #endif
            super_onCreate();           // Drawind statusbar and etc if needed
            onCreate(); 
        };

        void drawInfo();
        long lastUpdate = 0;

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
        
        unsigned char currentPrintScreenString = 0;
        void drawStringOnScreen(String stringToPrint);
};

void appNameClass::drawStringOnScreen(String stringToPrint){
    #ifdef ROUND_SCREEN
        drawString_centered(stringToPrint, SCREEN_WIDTH/2, STYLE_STATUSBAR_HEIGHT + currentPrintScreenString*10*APP_BATTERY_FONT_SIZE + 10, APP_BATTERY_FONT_SIZE);
        currentPrintScreenString ++;
    #else
        drawString(stringToPrint, 5, STYLE_STATUSBAR_HEIGHT + currentPrintScreenString*10*APP_BATTERY_FONT_SIZE + 10, APP_BATTERY_FONT_SIZE);
        currentPrintScreenString ++;
    #endif
}

/*
float driver_battery_getVoltage()
int driver_battery_getVoltage_mV()
float driver_battery_getCurent_mA()
float driver_battery_getUsbVoltage()
float driver_battery_getUsbCurent_mA()
float driver_battery_controller_Temp()
float driver_battery_Temp()
unsigned char driver_battery_getPercent()
*/

void appNameClass::onCreate(){
    #ifdef LIGHT_COLOR_THEME
        setBackgroundColor(255, 255, 255); 
    #else
        setBackgroundColor(0, 0, 0);
    #endif

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    this->drawInfo();
}

void appNameClass::drawInfo(){
    this->lastUpdate = millis();
    this->currentPrintScreenString = 0;

    #ifdef LIGHT_COLOR_THEME
        setDrawColor(0, 0, 0);
    #else
        setDrawColor(255, 255, 255);
    #endif

    #ifdef BATTERY_ENABLE
        //#ifdef NARROW_SCREEN
            drawStringOnScreen("Bat voltage:");
            drawStringOnScreen(String(driver_battery_getVoltage()) + " V");
            
            drawStringOnScreen("Bat voltage:");
            drawStringOnScreen(String(driver_battery_getVoltage_mV()) + " mV");
            
            drawStringOnScreen("Bat current:");
            drawStringOnScreen(String(driver_battery_getCurent_mA()) + " mA");
                        
            drawStringOnScreen("Usb voltage:");
            drawStringOnScreen(String(driver_battery_getUsbVoltage()) + " mV");

            drawStringOnScreen("Usb current:");
            drawStringOnScreen(String(driver_battery_getUsbCurent_mA()) + " mA");
            
            /*
            drawStringOnScreen("Vin voltage:");
            drawStringOnScreen(String(driver_battery_getVinVoltage()) + " mV");

            drawStringOnScreen("Vin current:");
            drawStringOnScreen(String(driver_battery_getVinCurent_mA()) + " mA");

            drawStringOnScreen("Battery temp:");
            drawStringOnScreen(String(driver_battery_Temp()) + " C");
            
            drawStringOnScreen("Controller temp:");
            drawStringOnScreen(String(driver_battery_controller_Temp()) + " C");
            */

            drawStringOnScreen("Battery:");
            drawStringOnScreen(String(core_battery_getPercent()) + " %");
    
            drawStringOnScreen("Battery is charging:");
            if(driver_battery_isCharging()) drawStringOnScreen("True");
            else drawStringOnScreen("False");

            drawStringOnScreen("USB is connected:");
            if(driver_battery_isUsbConnected()) drawStringOnScreen("True");
            else drawStringOnScreen("False");
        //#else
            
        //#endif
        
    #else
        drawStringOnScreen("Battery not supported");
    #endif
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
    #ifdef BATTERY_ENABLE
        if(millis()-this->lastUpdate>APP_BATTERY_UPDATE_EVERY_MS){
            //fillScreen(0, 0, 0);
            setDrawColor_BackGroundColor();
            drawRect(0, STYLE_STATUSBAR_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, true);
            this->drawInfo();
            #ifdef PARTIAL_DISPLAY_DRAWING
                driver_display_partial_loop();
            #endif
        }
    #endif
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2, int val3, int val4, int val5){
    #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
        if(event==EVENT_BUTTON_PRESSED){
            // Write you code on [val1] button pressed here
            if(val1==BUTTON_POWER){
                startApp(-1);
            }
        }else if(event==EVENT_BUTTON_DOUBLE_PRESS){
            if(val1==BUTTON_SELECT){
                startApp(-1);
            }
        }
    #else
        if(event==EVENT_BUTTON_PRESSED){
            // Write you code on [val1] button pressed here
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        }else if(event==EVENT_BUTTON_RELEASED){
            // Write you code on [val1] button released here
        }else if(event==EVENT_BUTTON_LONG_PRESS){
            // Write you code on [val1] button long press here
        }else if(event==EVENT_ON_TIME_CHANGED){
            // Write you code on system time changed
        }
    #endif

    #ifdef TOUCH_SCREEN_ENABLE
        if(event==EVENT_ON_TOUCH_START){
            startApp(-1);
        }
    #endif
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    #ifdef USE_L_MENU_IMAGES
    #elif defined(USE_XL_MENU_IMAGES)
        #ifdef COLOR_GRAY_16
            0x02,0x01,0x02,0x50,0x02,0x50,0x04,0x7E,0x7E,0x7E,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x40,0x02,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x01,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x01,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x08,0x00,0x00,0x10,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x04,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x50,0x00,0x00,0x0A,0x00,0x00,0x00,0x08,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x10,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x10,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x08,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x20,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x04,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x42,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x41,0xFF,0xFF,0x82,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x20,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x04,0x00,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x10,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x08,0x00,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x00,0x08,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x10,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x04,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x20,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x40,0x00,0x00,0x00,0x50,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x40,0x00,0x20,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xC0,0x01,0xFF,0xFF,0xFC,0x00,0x00,0x7F,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFE,0x00,0x00,0xFF,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0xFF,0x00,0x01,0xFF,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xE0,0x1F,0xF8,0x07,0xFF,0xFF,0x80,0x03,0xFF,0xFF,0xC0,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0x8F,0xFF,0xFF,0xF3,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0x8F,0xFF,0xFF,0xF1,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9E,0x00,0x00,0x39,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0x9E,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9E,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9E,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9E,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0x9E,0x00,0x00,0x79,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF8,0x0F,0xFF,0xFF,0x9F,0xFF,0xFF,0xF9,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xF0,0x07,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xE0,0x03,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0xC0,0x01,0xFF,0xFF,0x9C,0x00,0x00,0x39,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0x8F,0xFF,0xFF,0xF9,0xFF,0xFF,0x80,0x00,0xFF,0xFF,0x8F,0xFF,0xFF,0xF1,0xFF,0xFF,0x00,0x00,0x7F,0xFF,0xC0,0x00,0x00,0x03,0xFF,0xFE,0x00,0x00,0x3F,0xFF,0xC0,0x00,0x00,0x07,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        #else
            0x02,0x01,0x02,0x50,0x02,0x50,0x04,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF8,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x1F,0xF0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x0F,0xF0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x0F,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xC0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x03,0xC0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x03,0xC0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x03,0x80,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x01,0x80,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x01,0x80,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x01,0x80,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x01,0x80,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x01,0x80,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x01,0x00,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x00,0x80,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x01,0x80,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x01,0x80,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x01,0x80,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x01,0x80,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x01,0x80,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x01,0xC0,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x03,0xC0,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x03,0xC0,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x03,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x07,0xF0,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x0F,0xF0,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x0F,0xF8,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x1F,0xF8,0x00,0x00,0x1C,0x00,0x00,0x38,0x00,0x00,0x1F,0xFC,0x00,0x00,0x1E,0x00,0x00,0x78,0x00,0x00,0x3F,0xFE,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x7F,0xFE,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xFF,0xFF,0x04,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x7F,0xFF,0xFF,0xC0,0x03,0xFF,0xFF,0xFE,0x00,0x00,0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0x00,0x01,0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0x80,0x03,0xFF,0xFF,0xE0,0x00,0x00,0x07,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xC0,0x00,0x00,0x03,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x1F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF8,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xF0,0x07,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xE0,0x03,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0xC0,0x01,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0x80,0x00,0x00,0x01,0xFF,0xFF,0x80,0x00,0xFF,0xFF,0xC0,0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,0x7F,0xFF,0xE0,0x00,0x00,0x07,0xFF,0xFE,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x07,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0xFF,0xFF,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x61,0xFF,0xFF,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        #endif
        
    #else
        // small image
        0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,0x00,0x00,0x07,0xE0,
        0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,
        0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,
        0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,
        0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,
        0xF0,0x0F,0xFF,0xFF,0xF0,0x0F,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x07,0xE0,0x00,0x00,0x08,0x10,0x00,
        0x00,0x08,0x10,0x00,0x0F,0xF8,0x1F,0xF0,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,
        0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,
        0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,
        0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,
        0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x10,0x00,0x00,0x08,0x0F,0xFF,0xFF,0xF0,
    #endif
    
};