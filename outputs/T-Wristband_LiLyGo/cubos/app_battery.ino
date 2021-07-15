
#define appNameClass                        BatteryApp              // App name without spaces
#define appName                             "Battery"              // App name with spaces 

#ifndef APP_BATTERY_UPDATE_EVERY_MS
    #define APP_BATTERY_UPDATE_EVERY_MS         500
#endif

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0);  // filling background
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
    drawString(stringToPrint, 5, STYLE_STATUSBAR_HEIGHT + currentPrintScreenString*10*FONT_SIZE_DEFAULT + 10, FONT_SIZE_DEFAULT);
    currentPrintScreenString ++;
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
    setBackgroundColor(0, 0, 0); 

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    this->drawInfo();
}

void appNameClass::drawInfo(){
    this->lastUpdate = millis();
    this->currentPrintScreenString = 0;

    setDrawColor(255, 255, 255);
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
        }
    #endif
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
        if(event==EVENT_BUTTON_PRESSED){
            // Write you code on [val1] button pressed here
            if(val1==BUTTON_POWER){
                startApp(-1);
            }
        }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
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
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
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
};