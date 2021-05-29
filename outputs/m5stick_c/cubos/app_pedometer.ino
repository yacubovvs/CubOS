#define appNameClass    PedometerApp         // App name without spaces
#define appName         "Pedometer"              // App name with spaces 

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
        void drawStringOnScreen(String stringToPrint);
        int currentPrintScreenString = 0;
        float acceleration_max = 0;
        float acceleration_min = 0;
      
};

void appNameClass::onCreate(){
    /*
        Write you code on App create here
    */
    this->preventSleep         = true;
    this->preventInAppSleep    = true;

    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);
    setDrawColor_ContrastColor();
    
    //drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, FONT_SIZE_DEFAULT);
    //core_pedometer_start_step_detection();
}

void appNameClass::drawStringOnScreen(String stringToPrint){
    setDrawColor_ContrastColor();
    drawString(stringToPrint, 5, STYLE_STATUSBAR_HEIGHT + currentPrintScreenString*10*FONT_SIZE_DEFAULT + 10, FONT_SIZE_DEFAULT);
    currentPrintScreenString ++;
}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */

    currentPrintScreenString = 0;
    setDrawColor_BackGroundColor();
    drawRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, true);

    //driver_accelerometer_update();
    driver_accelerometer_update_accelerometer();

    /*
    float get_driver_accelerometer_temperature(){return temp;}
    float get_driver_accelerometer_pitch(){return pitch;}
    float get_driver_accelerometer_roll(){return roll;}
    float get_driver_accelerometer_yaw(){return yaw;}
    float get_driver_accelerometer_gyroscope_x(){return gyroX;}
    float get_driver_accelerometer_gyroscope_y(){return gyroY;}
    float get_driver_accelerometer_gyroscope_z(){return gyroZ;}
    float get_driver_accelerometer_x(){return accX;}
    float get_driver_accelerometer_y(){return accY;}
    float get_driver_accelerometer_z(){return accZ;}
    */
    
    //drawStringOnScreen(String(get_driver_accelerometer_x()) + " " + String(get_driver_accelerometer_y()) + " " + String(get_driver_accelerometer_y()));
    
    drawStringOnScreen(String(get_driver_accelerometer_x()));
    drawStringOnScreen(String(get_driver_accelerometer_y()));
    drawStringOnScreen(String(get_driver_accelerometer_z()));
    drawStringOnScreen("");
    

    float acceleration_qudr = driver_accelerometer_get_accel_total();

    if(acceleration_max==0) acceleration_max = acceleration_qudr;
    if(acceleration_min==0) acceleration_min = acceleration_qudr;

    if(acceleration_qudr>acceleration_max) acceleration_max = acceleration_qudr;
    if(acceleration_qudr<acceleration_min) acceleration_min = acceleration_qudr;

    //if(acceleration_current_max>acceleration_max) acceleration_max = acceleration_current_max;
    //if(acceleration_current_min<acceleration_min) acceleration_min = acceleration_current_min;

    //drawStringOnScreen(String(acceleration_min));
    //drawStringOnScreen(String(acceleration_qudr));
    //drawStringOnScreen(String(acceleration_max));

    //drawStringOnScreen("");

    drawStringOnScreen(String(acceleration_min));
    drawStringOnScreen(String(acceleration_qudr));
    drawStringOnScreen(String(acceleration_max));

    /*
    if(acceleration_qudr>1.5) digitalWrite(10,0);
    else if(acceleration_qudr<0.5) digitalWrite(10,0);
    else digitalWrite(10,1);
    */

    //drawStringOnScreen("Gyroscope:");
    //drawStringOnScreen(String(get_driver_accelerometer_gyroscope_x()) + " " + String(get_driver_accelerometer_gyroscope_y()) + " " + String(get_driver_accelerometer_gyroscope_z()));

    //drawStringOnScreen("get_driver_accelerometer_temperature:");
    //drawStringOnScreen(String(get_driver_accelerometer_temperature()));

    //drawStringOnScreen("Pitch, roll, yaw:");
    //drawStringOnScreen(String(get_driver_accelerometer_pitch()) + " " + String(get_driver_accelerometer_roll()) + " " + String(get_driver_accelerometer_yaw()));
   
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
    digitalWrite(10,1);
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
     #ifdef TOUCH_SCREEN_ENABLE

        if(event==EVENT_ON_TOUCH_DRAG){
            // SCREEN SCROLL
            this->drawIcons(false);
            this->scroll_x -= val1;
            if(this->scroll_x<0) scroll_x = 0;

            int max_scroll = (this->getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN) - 1 ) * SCREEN_WIDTH;
            if(this->scroll_x>max_scroll) {
                this->scroll_x = max_scroll;
            }

            this->drawIcons(true);
        }

    #else

        /**/
        #if (DRIVER_CONTROLS_TOTALBUTTONS == 2 || DRIVER_CONTROLS_TOTALBUTTONS == 1)
            
            if(event==EVENT_BUTTON_PRESSED){
            }else if(event==EVENT_BUTTON_RELEASED){
            }else if(event==EVENT_BUTTON_LONG_PRESS){
                if(val1==BUTTON_SELECT){
                    acceleration_max = 0;
                    acceleration_min = 0;
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }    
            }else if(event==EVENT_BUTTON_SHORT_PRESS){
            }else if(event==EVENT_BUTTON_SHORT_SINGLE_PRESS){
                if(val1==BUTTON_SELECT){
                }else if(val1==BUTTON_BACK){
                }
            }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
                #if (DRIVER_CONTROLS_TOTALBUTTONS == 1)
                    if(val1==BUTTON_SELECT){
                        startApp(-1);
                    }
                #else
                #endif
                
            }
            
        #else
            if(event==EVENT_BUTTON_PRESSED){
                
                if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
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
                }   
            
            }else if(event==EVENT_BUTTON_RELEASED){

            }else if(event==EVENT_BUTTON_LONG_PRESS){

            }
        #endif
    
    #endif
    
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x6f,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1E,0x00,
    0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x78,
    0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFC,0x7F,0xFF,0xFF,0xFE,0xFF,0xFE,0x7F,0xFF,0xFF,0xF9,0x9F,0xFF,
    0xFF,0xE7,0xE7,0xFF,0xFF,0x9F,0xF9,0xFF,0xFF,0x7F,0xFE,0xFF,0xFF,0x1F,0xF8,0xFF,0xFF,0x67,0xE0,0xFF,0xFF,0x79,0x80,0xFF,0xFF,0x7E,0x00,
    0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x7F,0x00,0xFF,0xFF,0x9F,0x01,0xFF,0xFF,0xE7,
    0x07,0xFF,0xFF,0xF9,0x1F,0xFF,0xFF,0xFE,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x7F,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,
    0xC7,0x6B,0xFF,0xFF,0xDB,0x65,0xFF,0xFF,0xDB,0x6D,0xFF,0xFF,0xC7,0x6D,0xFF,0x7F,0xFF,0xFF,0xFE,0x3F,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xF8,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x06,0x60,0x00,0x00,0x18,0x18,
    0x00,0x00,0x60,0x06,0x00,0x00,0x80,0x01,0x00,0x00,0xE0,0x07,0x00,0x00,0x98,0x19,0x00,0x00,0x86,0x61,0x00,0x00,0x81,0x81,0x00,0x00,0x80,
    0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x80,0x81,0x00,0x00,0x60,0x86,0x00,0x00,0x18,0x98,0x00,0x00,
    0x06,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x80,0x00,0x00,0x20,0x00,0x00,0x00,0x38,0x94,0x00,
    0x00,0x24,0x9A,0x00,0x00,0x24,0x92,0x00,0x00,0x38,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};