#define appNameClass    PedometerApp             // App name without spaces
#define appName         "Pedometer"              // App name with spaces 

#define PEDOMETER_PAGES_PEDOMETER               0x00
#define PEDOMETER_PAGES_PEDOMETR_STATISTICS     0x01
#define PEDOMETER_PAGES_SLEEP_MONITOR           0x02
#define PEDOMETER_PAGES_SLEEP_STATISTICS        0x03

#define PEDOMETER_PAGE_MARGIN 5
#define PEDOMETER_CHART_HEIGHT ((SCREEN_HEIGHT - PEDOMETER_PAGE_MARGIN*2 - STYLE_STATUSBAR_HEIGHT)/2)
#define PEDOMETER_CHART_WIDTH ((SCREEN_WIDTH - PEDOMETER_PAGE_MARGIN*2))
#define PEDOMETER_CHART_COLUMNS 7
#define PEDOMETER_CHART_COLUMN_MARGINS_PX 3
#define PEDOMETER_CHART_COLUMN_WIDTH ((PEDOMETER_CHART_WIDTH - PEDOMETER_CHART_COLUMN_MARGINS_PX*PEDOMETER_CHART_COLUMNS)/PEDOMETER_CHART_COLUMNS)

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
        void drawPage(unsigned char page);      
};

void appNameClass::drawPage(unsigned char page){

    /*
        PEDOMETER_PAGES_PEDOMETER
        PEDOMETER_PAGES_PEDOMETR_STATISTICS
        PEDOMETER_PAGES_SLEEP_MONITOR
        PEDOMETER_PAGES_SLEEP_STATISTICS
    */

    if(page==PEDOMETER_PAGES_PEDOMETER){
        for(unsigned char i=0; i<PEDOMETER_CHART_COLUMNS; i++){
            setDrawColor(0, 128 + 127*(int)i/7, 0);
            #define Y1_CHART (STYLE_STATUSBAR_HEIGHT + PEDOMETER_PAGE_MARGIN + PEDOMETER_CHART_HEIGHT)
            #define Y2_CHART (STYLE_STATUSBAR_HEIGHT + PEDOMETER_PAGE_MARGIN)
            #define X1_CHART (PEDOMETER_PAGE_MARGIN + (PEDOMETER_CHART_COLUMN_WIDTH + PEDOMETER_CHART_COLUMN_MARGINS_PX)*i)
            #define X2_CHART (X1_CHART + PEDOMETER_CHART_COLUMN_WIDTH - 1)
            drawRect(X1_CHART, Y1_CHART, X2_CHART, Y2_CHART, true);
        }
    }
}

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
    
    drawPage(PEDOMETER_PAGES_PEDOMETER);
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
    
     #ifdef TOUCH_SCREEN_ENABLE

        if(event==EVENT_ON_TOUCH_DRAG){
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
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0x00,0x00,0x07,0xF0,0x00,0x00,0x0F,0xF8,0x00,0x00,0x1F,
    0xFC,0x07,0xC0,0x1F,0xFC,0x1F,0xE0,0x3F,0xFE,0x3F,0xF0,0x3F,0xFE,0x3F,0xF0,0x3F,0xFE,0x3F,0xF8,0x3F,0xFE,
    0x7F,0xF8,0x1F,0xFE,0x7F,0xF8,0x1F,0xFE,0x7F,0xFC,0x0F,0xFE,0x7F,0xFC,0x0F,0xFE,0x3F,0xFC,0x0F,0xFC,0x3F,
    0xFC,0x07,0xFC,0x1F,0xFC,0x07,0xFC,0x1F,0xF8,0x03,0xF8,0x1F,0xF8,0x00,0x00,0x0F,0xF8,0x00,0x00,0x07,0xF8,
    0x00,0x00,0x07,0xE0,0x03,0xF8,0x03,0x00,0x07,0xFC,0x00,0x00,0x07,0xFC,0x00,0x06,0x07,0xFC,0x00,0x3E,0x07,
    0xFC,0x01,0xFF,0x03,0xFC,0x03,0xFF,0x03,0xF8,0x03,0xFF,0x01,0xF0,0x01,0xFF,0x00,0x00,0x01,0xFE,0x00,0x00,
    0x00,0xFC,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
};