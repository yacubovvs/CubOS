#define appNameClass    TouchCalibration         // App name without spaces
#define appName         "Touch Calibr"              // App name with spaces 

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

        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */

    setBackgroundColor(0, 0, 0);
    setDrawColor(255, 255, 255);
    drawString("Not touched", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
    drawString("00000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */

    /*
    setBackgroundColor(0, 0, 0);
    setDrawColor(0, 0, 0);
    clearString("25500", 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    
    setDrawColor(255, 255, 255);
    drawString(getDe(), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
    //drawString(String((int) 2), 5, STYLE_STATUSBAR_HEIGHT + 3*20 + 10, 2);
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
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
        if(val1==BUTTON_POWER){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }else if(event==EVENT_ON_TOUCH_START){
        setDrawColor(0, 0, 0);
        clearString("Not touched released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);

        setDrawColor(255, 255, 255);
        drawString("Touch start", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }else if(event==EVENT_ON_TOUCH_RELEASED){
        setDrawColor(0, 0, 0);
        clearString("Not touched released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        clearString("000000000000000", 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);

        setDrawColor(255, 255, 255);
        drawString("Touch released", 5, STYLE_STATUSBAR_HEIGHT + 0*20 + 10, 2);
        drawString(String(val1), 5, STYLE_STATUSBAR_HEIGHT + 1*20 + 10, 2);
        drawString(String(val2), 5, STYLE_STATUSBAR_HEIGHT + 2*20 + 10, 2);
    }
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x3F,0xFC,0x00,0x00,0x3F,0xFC,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,
    0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x03,
    0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xFF,0x00,
    0x00,0xFF,0xFF,0x00,0x00,0xFF,
};