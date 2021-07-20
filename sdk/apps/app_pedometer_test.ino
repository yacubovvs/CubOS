#define appNameClass    PedometerAppTest         // App name without spaces
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
    #ifdef ACCELEROMETER_ENABLE
        //core_pedometer_loop(false);
        //driver_accelerometer_update_accelerometer();
          #ifdef PEDOMETER_ENABLE
            //core_pedometer_loop(false);
        #endif
    #endif
   
    currentPrintScreenString = 0;
    setDrawColor_BackGroundColor();
    drawRect(0,0, SCREEN_WIDTH, SCREEN_HEIGHT, true);

    #ifdef ACCELEROMETER_ENABLE
        driver_accelerometer_update_accelerometer();

        drawStringOnScreen("Steps: ");
        #ifdef PEDOMETER_ENABLE
            drawStringOnScreen(String(get_pedometer_days_steps()));
        #else 
            drawStringOnScreen("-");
        #endif

        drawStringOnScreen("Sleep: ");
        #ifdef PEDOMETER_ENABLE
        drawStringOnScreen(String(get_pedometer_days_sleep()));
        #else 
            drawStringOnScreen("-");
        #endif

        drawStringOnScreen("Mesures: ");
        #ifdef PEDOMETER_ENABLE
        drawStringOnScreen(String(getPedometr_mesurings_in_a_day()));
        #else 
            drawStringOnScreen("-");
        #endif

        drawStringOnScreen("");
        drawStringOnScreen("Mesures ms: ");
        #ifdef PEDOMETER_ENABLE
            drawStringOnScreen(String(get_corePedometer_currentsleep_between_mesures()));
        #else 
            drawStringOnScreen("-");
        #endif
        
        /*
        #ifdef PEDOMETER_ENABLE
            drawStringOnScreen("");
            drawStringOnScreen("Accels X Y Z:");
            drawStringOnScreen(String(get_driver_accelerometer_x()));
            drawStringOnScreen(String(get_driver_accelerometer_y()));
            drawStringOnScreen(String(get_driver_accelerometer_z()));
        #endif
        */    

        //drawStringOnScreen("Accerometer: ");
        //drawStringOnScreen(String(driver_accelerometer_get_accel_total()));
    #endif

    #ifdef DEBUG_PEDOMETER
        #ifdef PEDOMETER_ENABLE
            drawStringOnScreen(" ");
            drawStringOnScreen("Delta: ");
            drawStringOnScreen(String(get_analysis_delta_value()));
            drawStringOnScreen("Central weight: ");
            drawStringOnScreen(String(get_analysis_central_weight_value()));
            drawStringOnScreen("");
            drawStringOnScreen("Mesure delay: ");
            drawStringOnScreen(String(get_corePedometer_currentsleep_between_mesures()));
        #endif
    #endif
    
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
    //digitalWrite(10,1);
    
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
     #ifdef TOUCH_SCREEN_ENABLE

        if(event==EVENT_ON_TOUCH_DRAG){
        }
        if(event==EVENT_BUTTON_PRESSED){
            if(val1==BUTTON_POWER){
                startApp(-1);
            }
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
                    set_pedometer_days_steps(0,0);
                    set_pedometer_days_sleep(0,0);
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