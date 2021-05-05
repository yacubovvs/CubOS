#define appNameClass    SettingsApp     // App name without spaces
#define appName         "Settings"      // App name with spaces 

#define CORE_VIEWS_SETTINGS_IMAGE_WIDTH 24
#define SETTINGS_ELEMENTS

#define PAGES_LIST_HEIGHT               20
#define ACTIVE_SCREEN_WIDTH             SCREEN_WIDTH
#define ACTIVE_SCREEN_HEIGHT            (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT - PAGES_LIST_HEIGHT)
#define SINGLE_ELEMENT_MIN_WIDTH        200
#define SINGLE_ELEMENT_MIN_HEIGHT       60

#define SINGLE_ELEMENTS_IN_X            ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y            ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#define SINGLE_ELEMENTS_IN_X_MACRO      ((ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y_MACRO      ((ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#if ((ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH)) < 1
  #define SINGLE_ELEMENTS_IN_X 1
  #define SINGLE_ELEMENTS_IN_X_MACRO 1
#endif

#if ((ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT)) < 1
  #define SINGLE_ELEMENTS_IN_Y 1
  #define SINGLE_ELEMENTS_IN_Y_MACRO 1
#endif

#if ( ((SINGLE_ELEMENTS_IN_X_MACRO)==1) && ((SINGLE_ELEMENTS_IN_Y_MACRO)==1))
  #define SINGLE_ELEMENT_ON_SCREEN
#endif

#ifdef NARROW_SCREEN
  #define SINGLE_ELEMENTS_IN_X 1
  #define SINGLE_ELEMENTS_IN_X_MACRO 1
  #define SINGLE_ELEMENTS_IN_Y 1
  #define SINGLE_ELEMENTS_IN_Y_MACRO 1
  #define SINGLE_ELEMENT_ON_SCREEN
#endif

#define SINGLE_ELEMENT_REAL_WIDTH       ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENTS_IN_X))
#define SINGLE_ELEMENT_REAL_HEIGHT      ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENTS_IN_Y))

#define PAGES_LIST_POSITION             (SCREEN_HEIGHT-PAGES_LIST_HEIGHT/2)
#define APPS_ON_SINGLE_PAGE             (SINGLE_ELEMENTS_IN_X * SINGLE_ELEMENTS_IN_Y)


// SUBMENUES
#define APP_SETTINGS_SUBMENU_MAIN 0x00
#define APP_SETTINGS_SUBMENU_SET_TIME 0x01

// SETTINGS PAGES
#define APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN 4

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
          switch(type){ 
            case PARAM_TYPE_NAME: return (unsigned char*)appName; 
            case PARAM_TYPE_ICON: return icon;
            default: return (unsigned char*)""; 
          }
        };
        const static unsigned char icon[] PROGMEM;
      
    private:
        const unsigned char* getApplicationTitle(unsigned char submenu, unsigned char num);
        const unsigned char* getApplicationIcon(unsigned char submenu, unsigned char num);
        void drawIcons(bool draw);
        void updateActiveAppIndex(int newSelectedAppIndex);
        void drawActiveAppFrame(bool draw);
        unsigned char getTotalPagesInSubMenu(unsigned char submenuType);
        unsigned char getTotalApplicationsInSubMenu(unsigned char subMenu);
        char app_settings_selectedAppIndex = 0;
        const static unsigned char def[]                PROGMEM;
        const static unsigned char icon_battery[]       PROGMEM;
        const static unsigned char icon_light[]         PROGMEM;
        const static unsigned char icon_time[]          PROGMEM;
        const static unsigned char icon_date[]          PROGMEM;
        const static unsigned char icon_sleep[]         PROGMEM;
        unsigned char currentSubMenu       = APP_SETTINGS_SUBMENU_MAIN;
        String getApplicationSubTitle(unsigned char submenu, unsigned char num);
        String getApplicationSubTitle(unsigned char submenu, unsigned char num, boolean getLast);
        void drawSettingsPageFirstTime();
        void clearWorkSpace();
        void switchToSubMenu(unsigned char newSubMenu);
        void drawSettingTimeArrows(bool draw, int position);
        void drawSettingTimeSelect(bool draw, int position);
        void drawSettingTimeDigits(bool draw);
        void drawSettingTimeDateDigits(bool draw, unsigned char position, int value);
        unsigned char lastSeconds   = 0;
        unsigned char lastMinutes   = 0;
        unsigned char lastHours     = 0;
        void pressPrevious();
        void pressNext();
        void pressSelect();

        String lastTimeString;
        String lastDateString;
        String lastBatteryString;

        char currentSelectedPosition        = 0;
        bool currentPositionIsSelected      = false;
        
        int getPositionBySelectedNumber(unsigned char selectedNumber);
};

unsigned char appNameClass::getTotalPagesInSubMenu(unsigned char submenuType){
    return (getTotalApplicationsInSubMenu(submenuType)%APPS_ON_SINGLE_PAGE==0?((int)(getTotalApplicationsInSubMenu(submenuType)/APPS_ON_SINGLE_PAGE)):((int)(getTotalApplicationsInSubMenu(submenuType)/APPS_ON_SINGLE_PAGE) + 1));
}

unsigned char appNameClass::getTotalApplicationsInSubMenu(unsigned char submenuType){
    switch (submenuType){
    case APP_SETTINGS_SUBMENU_MAIN:
        return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN;
    default:
        return APP_SETTINGS_PAGE_TOTAL_ELEMENTS_MAIN;
    }
}

void appNameClass::clearWorkSpace(){
    setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
    drawRect(0, STYLE_STATUSBAR_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, true);
}

#define OFFSET_POSITION_ELEMENTS 60
#define TIME_SET_POSITION_1 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*1 + OFFSET_POSITION_ELEMENTS/2
#define TIME_SET_POSITION_2 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*3 + OFFSET_POSITION_ELEMENTS/2
#define TIME_SET_POSITION_3 (SCREEN_WIDTH-OFFSET_POSITION_ELEMENTS)/6*5 + OFFSET_POSITION_ELEMENTS/2

void appNameClass::drawSettingsPageFirstTime(){
    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
        #ifndef SINGLE_ELEMENT_ON_SCREEN
            core_views_draw_pages_list_simple(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN));
        #endif
        core_views_draw_active_page(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN), 0);
        this->updateActiveAppIndex(app_settings_selectedAppIndex);  
        // Drawing icons
        this->drawIcons(true);
        #ifndef TOUCH_SCREEN_ENABLE
        #ifndef SINGLE_ELEMENT_ON_SCREEN
            this->drawActiveAppFrame(true);  
        #endif
        #endif
    }if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
        int y_position = (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT)/2;
        //drawString("Setting up time", 80,80);
        drawSettingTimeDigits(true);
        drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));

        //drawSettingTimeArrows(true, TIME_SET_POSITION_1);
        //drawSettingTimeArrows(true, TIME_SET_POSITION_2);
        //drawSettingTimeArrows(true, TIME_SET_POSITION_3);

        //drawSettingTimeSelect(true, TIME_SET_POSITION_1);
        //drawSettingTimeSelect(true, TIME_SET_POSITION_2);
        //drawSettingTimeSelect(true, TIME_SET_POSITION_3);
    }    
}

int appNameClass::getPositionBySelectedNumber(unsigned char selectedNumber){
    switch(selectedNumber){
        case 0: return TIME_SET_POSITION_1;
        case 1: return TIME_SET_POSITION_2;
        case 2: return TIME_SET_POSITION_3;
        default: return TIME_SET_POSITION_1;
    }
}

void appNameClass::drawSettingTimeArrows(bool draw, int position){
    //drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  

    //drawIcon(draw, icon_arrow_top, position + 3 - 16, SCREEN_HEIGHT/2 - 19 - 15 );
    //drawIcon(draw, icon_arrow_bottom, position + 3 - 16, SCREEN_HEIGHT/2 + 20 + 15);

    drawIcon(draw, getIcon(ICON_ARROW_UP), position + 3 - 16, SCREEN_HEIGHT/2 - 19 - 15 );
    drawIcon(draw, getIcon(ICON_ARROW_DOWN), position + 3 - 16, SCREEN_HEIGHT/2 + 20 + 15);
}

void appNameClass::drawSettingTimeSelect(bool draw, int position){
    //drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  
    if(draw) setDrawColor(255, 255, 255);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
    drawRect(position - FONT_CHAR_WIDTH*3, SCREEN_HEIGHT/2 + 25, position + FONT_CHAR_WIDTH*3-3, SCREEN_HEIGHT/2 + 28, true);
}

void appNameClass::drawSettingTimeDigits(bool draw){
    if(draw) setDrawColor(255, 255, 255);

    lastSeconds   = core_time_getSeconds_byte();
    lastMinutes   = core_time_getMinutes_byte();
    lastHours     = core_time_getHours_byte();

    drawSettingTimeDateDigits(true, TIME_SET_POSITION_1, lastHours);
    drawSettingTimeDateDigits(true, TIME_SET_POSITION_2, lastMinutes);
    drawSettingTimeDateDigits(true, TIME_SET_POSITION_3, lastSeconds);
}

void appNameClass::drawSettingTimeDateDigits(bool draw, unsigned char position, int value){
    if(draw){
        setDrawColor(255, 255, 255);
        drawString_centered(core_basic_addLeadBullToInt2digits(value), position, SCREEN_HEIGHT/2, 3);   
    }else{
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        clearString_centered(core_basic_addLeadBullToInt2digits(value), position, SCREEN_HEIGHT/2, 3); 
    
    }
}

void appNameClass::switchToSubMenu(unsigned char newSubMenu){
    app_settings_selectedAppIndex = 0;
    currentSubMenu = newSubMenu;
    clearWorkSpace();
    drawSettingsPageFirstTime(); 
}

void appNameClass::onCreate(){
    #ifndef TOUCH_SCREEN_ENABLE
        DRAW_LIMITS_setEnable(true);
        DRAW_LIMIT_reset();
        DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);
    #endif

    this->drawSettingsPageFirstTime();
    this->currentSubMenu = APP_SETTINGS_SUBMENU_MAIN;
    //switchToSubMenu(APP_SETTINGS_SUBMENU_SET_TIME);
}



void appNameClass::updateActiveAppIndex(int newSelectedAppIndex){

  if(newSelectedAppIndex<0) newSelectedAppIndex = getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN) - 1;
  if(newSelectedAppIndex>=getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN)) newSelectedAppIndex = 0;

  if(app_settings_selectedAppIndex!=newSelectedAppIndex){
    
    #ifndef TOUCH_SCREEN_ENABLE
    #ifndef SINGLE_ELEMENT_ON_SCREEN
        this->drawActiveAppFrame(false);
    #endif
    #endif
    
    if( (int)((app_settings_selectedAppIndex)/APPS_ON_SINGLE_PAGE) != (int)((newSelectedAppIndex)/APPS_ON_SINGLE_PAGE)){
      // update page
      this->drawIcons(false);
      core_views_draw_active_page(false, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN), (int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE));
      app_settings_selectedAppIndex = newSelectedAppIndex;
      core_views_draw_active_page(true, PAGES_LIST_POSITION, getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN), (int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE));
      this->drawIcons(true);
    }else{
      app_settings_selectedAppIndex = newSelectedAppIndex;
    }

    // update selected app frame
    #ifndef TOUCH_SCREEN_ENABLE
    #ifndef SINGLE_ELEMENT_ON_SCREEN
        this->drawActiveAppFrame(true);
    #endif
    #endif
    
  }
}

void appNameClass::drawActiveAppFrame(bool draw){
  unsigned char positionOnScreen     = app_settings_selectedAppIndex%APPS_ON_SINGLE_PAGE;
  unsigned char positionOnScreen_x   = app_settings_selectedAppIndex%SINGLE_ELEMENTS_IN_X;
  unsigned char positionOnScreen_y   = positionOnScreen/SINGLE_ELEMENTS_IN_X;

  int x0 = positionOnScreen_x*SINGLE_ELEMENT_REAL_WIDTH;
  int y0 = positionOnScreen_y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
  int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
  int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

  if(draw) setDrawColor(196, 196, 196);
  else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

  for(unsigned char i=0; i<4; i++){
    unsigned char delta = 5+i;
    drawRect(x0+delta, y0+delta, x1-delta, y1-delta);  
  }
  
}

void appNameClass::drawIcons(bool draw){
    #ifdef NARROW_SCREEN
        int app_num = app_settings_selectedAppIndex;
        
        #ifdef MAIN_MENU_SMOOTH_ANIMATION
            if(this->scroll_x!=0){
                if(this->scroll_x<0){
                }else if(this->scroll_x>0){

                    char elementsToPreDraw = this->scroll_x/SCREEN_WIDTH + 1;
                    elementsToPreDraw = elementsToPreDraw%getTotalPagesInSubMenu(currentSubMenu);
                    for(unsigned char elementDraw = 0; elementDraw<=elementsToPreDraw; elementDraw++){
                        int appElementDraw = app_num - elementDraw;
                        while(appElementDraw<0) appElementDraw+=getTotalPagesInSubMenu(currentSubMenu);
                        appElementDraw = appElementDraw%getTotalPagesInSubMenu(currentSubMenu);

                        core_views_draw_settings_item(
                            draw, 
                            this->scroll_x + SCREEN_WIDTH/2 - elementDraw*SCREEN_WIDTH,
                            SCREEN_HEIGHT/2, 
                            (const unsigned char*)this->getApplicationTitle(0, appElementDraw), 
                            this->getApplicationSubTitle(0, appElementDraw, !draw), 
                            this->getApplicationIcon(0, appElementDraw)
                        );
                    }


                    /*
                    

                        core_views_draw_app_icon(
                        draw, 
                        this->scroll_x + x_center - elementDraw*SCREEN_WIDTH , y_center, 
                        (const unsigned char*)this->getApplicationTitle(appElementDraw), 
                        this->getApplicationIcon(appElementDraw)
                        );
                    
                    */
                }
            }

            core_views_draw_settings_item(
                draw, 
                this->scroll_x + SCREEN_WIDTH/2,
                SCREEN_HEIGHT/2, 
                (const unsigned char*)this->getApplicationTitle(0, app_num), 
                this->getApplicationSubTitle(0, app_num, !draw), 
                this->getApplicationIcon(0, app_num)
            );
        #else
            core_views_draw_settings_item(
                draw, 
                SCREEN_WIDTH/2,
                SCREEN_HEIGHT/2, 
                (const unsigned char*)this->getApplicationTitle(0, app_num), 
                this->getApplicationSubTitle(0, app_num, !draw), 
                this->getApplicationIcon(0, app_num)
            );
        #endif


    #else
        #ifndef TOUCH_SCREEN_ENABLE
            for(unsigned char currentDrawPage=0; currentDrawPage<getTotalPagesInSubMenu(APP_SETTINGS_SUBMENU_MAIN); currentDrawPage++){
        #endif
            
            for (unsigned char y_position=0; y_position<SINGLE_ELEMENTS_IN_Y; y_position++){
                for (unsigned char x_position=0; x_position<SINGLE_ELEMENTS_IN_X; x_position++){
                    int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
                    int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
                    int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
                    int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

                    int x_center = (x0+x1)/2;
                    int y_center = (y0+y1)/2;

                    #ifndef TOUCH_SCREEN_ENABLE
                        int app_num = y_position*(SINGLE_ELEMENTS_IN_X) + x_position + currentDrawPage*APPS_ON_SINGLE_PAGE;
                    #else
                        int app_num = y_position*(SINGLE_ELEMENTS_IN_X) + x_position + APPS_ON_SINGLE_PAGE*(int)(app_settings_selectedAppIndex/APPS_ON_SINGLE_PAGE);
                    #endif
                    
                    if(app_num<getTotalApplicationsInSubMenu(APP_SETTINGS_SUBMENU_MAIN)){
                        #ifdef ESP8266
                            ESP.wdtDisable();
                        #endif

                        
                        core_views_draw_settings_item(
                            draw, 
                            #ifndef TOUCH_SCREEN_ENABLE
                                currentDrawPage*SCREEN_WIDTH - this->scroll_x + x0+35, 
                            #else
                                -this->scroll_x + x0+35, 
                            #endif
                            y_center, 
                            (const unsigned char*)this->getApplicationTitle(0, app_num), 
                            this->getApplicationSubTitle(0, app_num), 
                            this->getApplicationIcon(0, app_num)
                        );
                    }
                }
            }

        #ifndef TOUCH_SCREEN_ENABLE
        }
        #endif
    #endif
}

void appNameClass::onLoop(){
    #ifdef MAIN_MENU_SMOOTH_ANIMATION
        if(this->scroll_x!=0){
        this->drawIcons(false);
        if(this->scroll_x!=0){
            //this->scroll_x++;
            int dx = abs(scroll_x)/5 + 1;
            if(scroll_x>scroll_to_x) dx *= -1;
            scroll_x+=dx;

            if (abs(dx)<1) scroll_x=0;
        }
        this->drawIcons(true);
        }
    #endif
}

void appNameClass::onDestroy(){
}

void appNameClass::pressPrevious(){
    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
        this->updateActiveAppIndex(app_settings_selectedAppIndex-1);
        #ifdef MAIN_MENU_SMOOTH_ANIMATION
          this->scroll_x -= SCREEN_WIDTH;
        #endif
    } 
}

void appNameClass::pressNext(){
    if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
        this->drawIcons(false);
        #ifdef MAIN_MENU_SMOOTH_ANIMATION
          this->scroll_x += SCREEN_WIDTH;
        #endif
        this->updateActiveAppIndex(app_settings_selectedAppIndex+1);
    } 
}

void appNameClass::pressSelect(){

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
                debug("EVENT_BUTTON_LONG_PRESS");
                if(val1==BUTTON_SELECT){
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }    
            }else if(event==EVENT_BUTTON_SHORT_PRESS){
                debug("EVENT_BUTTON_SHORT_PRESS");
            }else if(event==EVENT_BUTTON_SHORT_SINGLE_PRESS){
                debug("EVENT_BUTTON_SHORT_SINGLE_PRESS");
                if(val1==BUTTON_SELECT){
                    this->pressNext();
                }else if(val1==BUTTON_BACK){
                    startApp(-1);
                }
            }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
                debug("EVENT_ON_TOUCH_DOUBLE_PRESS");
                if(val1==BUTTON_SELECT){
                    startApp(-1);
                }
            }
            
        #else
        /**/
            if(event==EVENT_BUTTON_PRESSED){
                
                if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
                    switch(val1){
                        case BUTTON_UP:
                            this->pressPrevious();
                            break;
                        case BUTTON_BACK:
                            startApp(-1);
                            break;
                        case BUTTON_DOWN:
                            this->pressNext();   
                            break;
                        case BUTTON_SELECT:
                            if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN && app_settings_selectedAppIndex==0) switchToSubMenu(APP_SETTINGS_SUBMENU_SET_TIME);
                            break;
                    }
                }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
                    
                    switch(val1){
                        case BUTTON_UP:
                        case BUTTON_DOWN:
                            if(currentPositionIsSelected==false){
                                drawSettingTimeSelect(false, getPositionBySelectedNumber(currentSelectedPosition));
                                if(val1==BUTTON_DOWN)currentSelectedPosition++; else currentSelectedPosition--;
                                if(currentSelectedPosition>=3)currentSelectedPosition=0;
                                if(currentSelectedPosition<0)currentSelectedPosition=2;
                                drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }else{
                                
                                // time changing
                            }
                            break;
                        case BUTTON_BACK:
                            switchToSubMenu(APP_SETTINGS_SUBMENU_MAIN);            
                            break;
                        
                        case BUTTON_SELECT:
                            currentPositionIsSelected = !currentPositionIsSelected;
                            if(currentPositionIsSelected){
                                drawSettingTimeSelect(false, getPositionBySelectedNumber(currentSelectedPosition));
                                drawSettingTimeArrows(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }else{
                                drawSettingTimeArrows(false, getPositionBySelectedNumber(currentSelectedPosition));
                                drawSettingTimeSelect(true, getPositionBySelectedNumber(currentSelectedPosition));
                            }
                            break;
                    }

                }
            
            }else if(event==EVENT_BUTTON_RELEASED){

            }else if(event==EVENT_BUTTON_LONG_PRESS){

            }
        #endif
    
    #endif

    else if(event==EVENT_ON_TIME_CHANGED){

        #ifdef SINGLE_ELEMENT_ON_SCREEN
            /*
            String lastTimeString;
            String lastDateString;
            String lastBatteryString;
            */
    
            if(app_settings_selectedAppIndex==0){
                //Setting time
                this->drawIcons(false);
                this->drawIcons(true);
            }
        #else
        if(currentSubMenu==APP_SETTINGS_SUBMENU_MAIN){
            if((int)((app_settings_selectedAppIndex)/APPS_ON_SINGLE_PAGE)==0){
                int x_position = 0;
                int y_position = 0;
                int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
                int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
                int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
                int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

                int x_center = (x0+x1)/2;
                int y_center = (y0+y1)/2;
                int y = y_center;

                int x = x0+35;
                int left_x = x + CORE_VIEWS_SETTINGS_IMAGE_WIDTH;
                String currentTime = core_time_getHourMinuteSecondsTime();
                setDrawColor(0, 0, 0);
                clearString(currentTime, left_x, y+4, 1);
                setDrawColor(255, 255, 255);
                drawString(currentTime, left_x, y+4, 1);
            }
        }else if(currentSubMenu==APP_SETTINGS_SUBMENU_SET_TIME){
            unsigned char lastSeconds_new   = core_time_getSeconds_byte();
            unsigned char lastMinutes_new   = core_time_getMinutes_byte();
            unsigned char lastHours_new     = core_time_getHours_byte();
            
            if(lastSeconds_new!=lastSeconds){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_3, lastSeconds);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_3, lastSeconds_new);
                lastSeconds = lastSeconds_new;
            }
            if(lastMinutes_new!=lastMinutes){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_2, lastMinutes);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_2, lastMinutes_new);
                lastMinutes = lastMinutes_new;
            }
            if(lastHours_new!=lastHours){
                drawSettingTimeDateDigits(false, TIME_SET_POSITION_1, lastHours);
                drawSettingTimeDateDigits(true, TIME_SET_POSITION_1, lastHours_new);
                lastHours = lastHours_new;
            }
            
        }
        #endif
    }

}

const unsigned char* appNameClass::getApplicationTitle(unsigned char submenu, unsigned char num){
    switch(APP_SETTINGS_SUBMENU_MAIN){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    return (const unsigned char*)"Time";
                case 1:
                    return (const unsigned char*)"Date";
                case 2:
                    return (const unsigned char*)"Sleep timout";
                case 3:
                    return (const unsigned char*)"Battery";
                case 4:
                    return (const unsigned char*)"Compass";                
                default:
                    return (const unsigned char*)"-";
                    break;
            }
            break;
        default:
            return (const unsigned char*)"-";
    }
}

String appNameClass::getApplicationSubTitle(unsigned char submenu, unsigned char num){
    return this->getApplicationSubTitle(submenu, num, false);
}

String appNameClass::getApplicationSubTitle(unsigned char submenu, unsigned char num, bool getLast){    

    switch(APP_SETTINGS_SUBMENU_MAIN){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    if(getLast) return this->lastTimeString;
                    else{
                        this->lastTimeString = core_time_getHourMinuteSecondsTime();
                        return this->lastTimeString;
                    }
                case 1:
                    if(getLast) return this->lastDateString;
                    else{
                        this->lastDateString = core_time_getDateFull();
                        return this->lastDateString;
                    }
                case 2:
                    #ifdef CPU_SLEEP_ENABLE
                        return String(core_cpu_getCpuSleepTimeDelay());
                    #else
                        return "-";
                    #endif
                case 3:
                    if(getLast) return this->lastBatteryString;
                    else{
                        this->lastBatteryString = String(core_batteryGetPercent()) + "%";
                        return this->lastBatteryString;
                    }
                case 4:
                    return "Calibrate";
                default:
                    return "Reset maximum";
                    break;
            }
            break;
        default:
            return "-";
    }
}

const unsigned char* appNameClass::getApplicationIcon(unsigned char submenu, unsigned char num){
    switch(APP_SETTINGS_SUBMENU_MAIN){
        case APP_SETTINGS_SUBMENU_MAIN:
            switch (num){
                case 0:
                    return this->icon_time;
                case 1:
                    return this->icon_date;
                case 2:
                    return this->icon_sleep;
                case 3:
                    return this->icon_battery;
                case 4:
                    return this->icon_battery;

                
                default:
                    return this->def;
                    break;
            }
            break;
        default:
            return this->def;
    }
}


const unsigned char appNameClass::def[] PROGMEM = {
    0x02,0x01,0x02,0x08,0x02,0x08,0x04,0xff,0xff,0xff,0x80,0xE0,0xF8,0xFF,0xFF,0xF8,0xE0,0x80,
};

const unsigned char appNameClass::icon_battery[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xEE,0x6E,0xEE,0xEE,0x6E,0xEE,0xEE,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x6E,0xEE,0xE8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xF8,0x80,0x00,0x04,0x80,0x00,0x04,0x80,0x00,0x06,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x06,0x80,0x00,0x04,0x80,0x00,0x04,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_light[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0xd9,0x00,0x03,0xC0,0x0F,0x30,0x1F,0x08,0x3F,0x04,0x7F,0x02,0x7F,
    0x02,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0x7F,0x02,0x7F,0x02,0x3F,0x04,0x1F,0x08,0x0F,0x30,0x03,0xC0,
};

const unsigned char appNameClass::icon_time[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x41,0x20,0x02,0x41,0x20,0x06,0xC3,0x60,0x02,0x59,0x20,0x02,0x41,0x20,0x02,0x59,0x20,0x02,0x41,0x20,0x02,0x41,0x20,0x02,0x41,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xd8,0xd8,0xd8,0x3E,0x00,0x7C,0x22,0x00,0x44,0x21,0xFF,0xC4,0x20,0x00,0x04,0x40,0x00,0x02,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x40,0x00,0x02,0x20,0x00,0x04,0x13,0xFF,0xC8,0x12,0x00,0x48,0x1E,0x00,0x78,0x04,0x8f,0x8f,0x8f,0x00,0x00,0x00,0x1C,0x00,0x38,0x1C,0x00,0x38,0x1F,0xFF,0xF8,0x3F,0xFF,0xFC,0x78,0x00,0x0E,0x70,0x00,0x06,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x60,0x00,0x02,0x70,0x00,0x06,0x78,0x00,0x0E,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0C,0x00,0x30,0x0C,0x00,0x30,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_date[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0xFF,0xFF,0xFF,0x04,0xd8,0xd8,0xd8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x1E,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char appNameClass::icon_sleep[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x18,0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x3E,0x08,0x00,0x78,0x00,0x00,0x70,0x00,0x00,0xF0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xE0,0x00,0x00,0xF0,0x00,0x00,0x70,0x00,0x00,0x78,0x00,0x00,0x3E,0x08,0x00,0x1F,0xF0,0x00,0x07,0xC0,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x07,0x00,0x00,0x01,0x00,0x0F,0xC2,0x00,0x00,0xC4,0x00,0x01,0x87,0x00,0x03,0x00,0x00,0x06,0x00,0x00,0x0C,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};




const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,
    0xF0,0x00,0x00,0x07,0xE0,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xb4,0xb4,0xb4,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x08,0x0F,
    0xF0,0x10,0x1C,0x3F,0xFC,0x38,0x3E,0x7F,0xFE,0x7C,0x7F,0xF8,0x1F,0xFE,0xFF,0xE0,
    0x07,0xFF,0xFF,0xC0,0x03,0xFF,0x7F,0x80,0x01,0xFE,0x3F,0x00,0x00,0xFC,0x1F,0x00,
    0x00,0xF8,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,
    0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x1F,0x00,0x00,0xF8,0x3F,0x00,
    0x00,0xFC,0x7F,0x80,0x01,0xFE,0xFF,0xC0,0x03,0xFF,0xFF,0xE0,0x07,0xFF,0x7F,0xF8,
    0x1F,0xFE,0x3E,0x7F,0xFE,0x7C,0x1C,0x3F,0xFC,0x38,0x08,0x0F,0xF0,0x10,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x04,0x47,
    0x47,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x1F,0xF8,0x00,0x00,0x3F,0xFC,0x00,0x00,0x7F,0xFE,0x00,0x00,0xFF,
    0xFF,0x00,0x00,0xFC,0x3F,0x00,0x01,0xF8,0x1F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,
    0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF8,0x1F,0x80,0x00,0xFC,
    0x3F,0x00,0x00,0xFF,0xFF,0x00,0x00,0x7F,0xFE,0x00,0x00,0x3F,0xFC,0x00,0x00,0x1F,
    0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,
};