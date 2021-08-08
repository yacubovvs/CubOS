#define appNameClass    MainMenuApp      // App name without spaces
#define appName         "Main menu"      // App name with spaces 

#ifdef SOFTWARE_BUTTONS_PORITION_RIGHT
  #define ACTIVE_SCREEN_WIDTH             (SCREEN_WIDTH - SOFTWARE_BUTTONS_BAR_SIZE)
#else
  #define ACTIVE_SCREEN_WIDTH             (SCREEN_WIDTH)
#endif

#define ACTIVE_SCREEN_HEIGHT            (SCREEN_HEIGHT - STYLE_STATUSBAR_HEIGHT)
#define SINGLE_ELEMENT_MIN_WIDTH        100
#define SINGLE_ELEMENT_MIN_HEIGHT       80

#define SINGLE_ELEMENTS_IN_X            ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENT_MIN_WIDTH))
#define SINGLE_ELEMENTS_IN_Y            ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENT_MIN_HEIGHT))

#define SINGLE_ELEMENT_REAL_WIDTH       ((int)(ACTIVE_SCREEN_WIDTH/SINGLE_ELEMENTS_IN_X))
#define SINGLE_ELEMENT_REAL_HEIGHT      ((int)(ACTIVE_SCREEN_HEIGHT/SINGLE_ELEMENTS_IN_Y))

#define PAGES_LIST_POSITION             (SCREEN_HEIGHT)
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

#define APPS_ON_SINGLE_PAGE             (SINGLE_ELEMENTS_IN_X * SINGLE_ELEMENTS_IN_Y)

#ifdef  APP_MENU_APPLICATIONS_0
  #define APP_MENU_APPLICATIONS_QUANTITY 1
#endif
#ifdef  APP_MENU_APPLICATIONS_1
  #define APP_MENU_APPLICATIONS_QUANTITY 2
#endif
#ifdef  APP_MENU_APPLICATIONS_2
  #define APP_MENU_APPLICATIONS_QUANTITY 3
#endif
#ifdef  APP_MENU_APPLICATIONS_3
  #define APP_MENU_APPLICATIONS_QUANTITY 4
#endif
#ifdef  APP_MENU_APPLICATIONS_4
  #define APP_MENU_APPLICATIONS_QUANTITY 5
#endif
#ifdef  APP_MENU_APPLICATIONS_5
  #define APP_MENU_APPLICATIONS_QUANTITY 6
#endif
#ifdef  APP_MENU_APPLICATIONS_6
  #define APP_MENU_APPLICATIONS_QUANTITY 7
#endif
#ifdef  APP_MENU_APPLICATIONS_7
  #define APP_MENU_APPLICATIONS_QUANTITY 8
#endif
#ifdef  APP_MENU_APPLICATIONS_8
  #define APP_MENU_APPLICATIONS_QUANTITY 9
#endif
#ifdef  APP_MENU_APPLICATIONS_9
  #define APP_MENU_APPLICATIONS_QUANTITY 10
#endif
#ifdef  APP_MENU_APPLICATIONS_10
  #define APP_MENU_APPLICATIONS_QUANTITY 11
#endif
#ifdef  APP_MENU_APPLICATIONS_11
  #define APP_MENU_APPLICATIONS_QUANTITY 12
#endif
#ifdef  APP_MENU_APPLICATIONS_12
  #define APP_MENU_APPLICATIONS_QUANTITY 13
#endif
#ifdef  APP_MENU_APPLICATIONS_13
  #define APP_MENU_APPLICATIONS_QUANTITY 14
#endif
#ifdef  APP_MENU_APPLICATIONS_14
  #define APP_MENU_APPLICATIONS_QUANTITY 15
#endif
#ifdef  APP_MENU_APPLICATIONS_15
  #define APP_MENU_APPLICATIONS_QUANTITY 16
#endif
#ifdef  APP_MENU_APPLICATIONS_16
  #define APP_MENU_APPLICATIONS_QUANTITY 17
#endif
#ifdef  APP_MENU_APPLICATIONS_17
  #define APP_MENU_APPLICATIONS_QUANTITY 18
#endif
#ifdef  APP_MENU_APPLICATIONS_18
  #define APP_MENU_APPLICATIONS_QUANTITY 19
#endif
#ifdef  APP_MENU_APPLICATIONS_19
  #define APP_MENU_APPLICATIONS_QUANTITY 20
#endif
#ifdef  APP_MENU_APPLICATIONS_20
  #define APP_MENU_APPLICATIONS_QUANTITY 21
#endif
#ifdef  APP_MENU_APPLICATIONS_21
  #define APP_MENU_APPLICATIONS_QUANTITY 22
#endif
#ifdef  APP_MENU_APPLICATIONS_22
  #define APP_MENU_APPLICATIONS_QUANTITY 23
#endif
#ifdef  APP_MENU_APPLICATIONS_23
  #define APP_MENU_APPLICATIONS_QUANTITY 24
#endif
#ifdef  APP_MENU_APPLICATIONS_24
  #define APP_MENU_APPLICATIONS_QUANTITY 25
#endif
#ifdef  APP_MENU_APPLICATIONS_25
  #define APP_MENU_APPLICATIONS_QUANTITY 26
#endif
#ifdef  APP_MENU_APPLICATIONS_26
  #define APP_MENU_APPLICATIONS_QUANTITY 27
#endif
#ifdef  APP_MENU_APPLICATIONS_27
  #define APP_MENU_APPLICATIONS_QUANTITY 28
#endif
#ifdef  APP_MENU_APPLICATIONS_28
  #define APP_MENU_APPLICATIONS_QUANTITY 29
#endif
#ifdef  APP_MENU_APPLICATIONS_29
  #define APP_MENU_APPLICATIONS_QUANTITY 30
#endif
#ifdef  APP_MENU_APPLICATIONS_30
  #define APP_MENU_APPLICATIONS_QUANTITY 31
#endif
#ifdef  APP_MENU_APPLICATIONS_31
  #define APP_MENU_APPLICATIONS_QUANTITY 32
#endif

#define TOTAL_PAGES (APP_MENU_APPLICATIONS_QUANTITY%APPS_ON_SINGLE_PAGE==0?((int)(APP_MENU_APPLICATIONS_QUANTITY/APPS_ON_SINGLE_PAGE)):((int)(APP_MENU_APPLICATIONS_QUANTITY/APPS_ON_SINGLE_PAGE) + 1))

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # //

char app_z_menu_selectedAppIndex = 0; // Now it is a global variable

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
        const unsigned char* getApplicationTitle(int num);
        const unsigned char* getApplicationIcon(int num);
        void drawIcons(bool draw);

};

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

void appNameClass::onCreate(){
    setBackgroundColor(0, 0, 0); 
    this->drawIcons(true);
    //setDrawColor(255,255,255);
    //drawRect(210, 20, 239, 239, true);
}

void appNameClass::drawIcons(bool draw){

  DRAW_LIMITS_setEnable(true);
  DRAW_LIMIT_reset();
  DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);

	for(unsigned char app_num=0; app_num<APP_MENU_APPLICATIONS_QUANTITY; app_num++){

		unsigned char x_position = app_num%SINGLE_ELEMENTS_IN_X;
		unsigned char y_position = app_num/SINGLE_ELEMENTS_IN_X;

		int x0 = x_position*SINGLE_ELEMENT_REAL_WIDTH;
		int y0 = y_position*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1;
		int x1 = x0+SINGLE_ELEMENT_REAL_WIDTH;
		int y1 = y0+SINGLE_ELEMENT_REAL_HEIGHT;

		int x_center = (x0+x1)/2;
		int y_center = (y0+y1)/2;

		core_views_draw_app_icon(
			draw, 
			x_center, y_center - this->scroll_y, 
			(const unsigned char*)this->getApplicationTitle(app_num), 
			this->getApplicationIcon(app_num)
		);
	}

  DRAW_LIMITS_setEnable(false);
}

void appNameClass::onLoop(){
}

void appNameClass::onDestroy(){
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){

    if(event==EVENT_ON_TOUCH_START){

    }else if(event==EVENT_ON_TOUCH_CLICK){    

      int position_x = (this->scroll_x + val1)/(SINGLE_ELEMENT_REAL_WIDTH);
      int position_y = (this->scroll_y + val2 + STYLE_STATUSBAR_HEIGHT)/(SINGLE_ELEMENT_REAL_HEIGHT);
      //if(position_y<0) position_y = 1;

      position_y -= 1;
      if(position_y<0) position_y = 0;
      if(position_x>SINGLE_ELEMENTS_IN_X-1)position_x=SINGLE_ELEMENTS_IN_X-1;
      if(position_x<0) position_x = 0;
      
      int appNum = position_x + position_y*SINGLE_ELEMENTS_IN_X;
      //if(appNum<0) appNum = 0;
      if(appNum<0 || appNum>APP_MENU_APPLICATIONS_QUANTITY-1) return; //appNum = APP_MENU_APPLICATIONS_QUANTITY-1;
      startApp(appNum);

    }else if(event==EVENT_ON_TOUCH_RELEASED){
      #ifdef TOUCH_SCREEN_ENABLE
        /*
        #ifdef PLATFORM_PC_EMULATOR
          this->drawIcons(false);
          float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);
          this->scroll_y = round(position) * SINGLE_ELEMENT_REAL_HEIGHT;
          this->drawIcons(true);
        #else
          if(millis() - getTOUCH_SCREEN_touch_start_ms()<150){
            // Fast scroll (swipe)
            if(abs(getTOUCH_SCREEN_touch_start_y()-val2)>10){
              // Slow scroll
              this->drawIcons(false);
              float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);

              if(getTOUCH_SCREEN_touch_start_y()-val2>0) this->scroll_y = round(position+2) * SINGLE_ELEMENT_REAL_HEIGHT;
              else this->scroll_y = round(position-2) * SINGLE_ELEMENT_REAL_HEIGHT;

              int max_scroll = (APP_MENU_APPLICATIONS_QUANTITY-1)/SINGLE_ELEMENTS_IN_Y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1+SINGLE_ELEMENT_REAL_HEIGHT - SCREEN_HEIGHT;
              if(scroll_y>max_scroll) {
                scroll_y = max_scroll;
              }
              if(scroll_y<0){
                scroll_y=0;
              }
              this->drawIcons(true);    
            }
          }else{
            // Slow scroll
            this->drawIcons(false);
            float position = ((float)this->scroll_y)/((float)SINGLE_ELEMENT_REAL_HEIGHT);
            this->scroll_y = round(position) * SINGLE_ELEMENT_REAL_HEIGHT;
            this->drawIcons(true);
          }
        #endif
        */
      #endif
    }else if(event==EVENT_ON_TOUCH_DRAG){

      // SCREEN SCROLL
      this->drawIcons(false);
      this->scroll_y -= val2;
      if(scroll_y<0) scroll_y = 0;

      //int max_scroll = (APP_MENU_APPLICATIONS_QUANTITY-1)/SINGLE_ELEMENTS_IN_Y*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1+SINGLE_ELEMENT_REAL_HEIGHT - SCREEN_HEIGHT;
      int max_scroll = (APP_MENU_APPLICATIONS_QUANTITY-1)/SINGLE_ELEMENTS_IN_X*SINGLE_ELEMENT_REAL_HEIGHT + STYLE_STATUSBAR_HEIGHT+1+SINGLE_ELEMENT_REAL_HEIGHT - SCREEN_HEIGHT;
      if(scroll_y>max_scroll) {
        scroll_y = max_scroll;
      }

      this->drawIcons(true);
    }

}

const unsigned char* appNameClass::getApplicationTitle(int num){
    return getAppParams(num,(PARAM_TYPE_NAME));
}

const unsigned char*  appNameClass::getApplicationIcon(int num){
    return (const unsigned char *)getAppParams(num,(PARAM_TYPE_ICON));
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS +                                    #
    #                                                                                          #
    ############################################################################################
*/

Application *getApp(unsigned char i){  
    if (i==0) return new APP_MENU_APPLICATIONS_0; 
    #if APP_MENU_APPLICATIONS_QUANTITY > 1
      else if (i==1) return new APP_MENU_APPLICATIONS_1; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 2
      else if (i==2) return new APP_MENU_APPLICATIONS_2; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 3
      else if (i==3) return new APP_MENU_APPLICATIONS_3; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 4
      else if (i==4) return new APP_MENU_APPLICATIONS_4; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 5
      else if (i==5) return new APP_MENU_APPLICATIONS_5; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 6
      else if (i==6) return new APP_MENU_APPLICATIONS_6; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 7
      else if (i==7) return new APP_MENU_APPLICATIONS_7; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 8
      else if (i==8) return new APP_MENU_APPLICATIONS_8; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 9
      else if (i==9) return new APP_MENU_APPLICATIONS_9; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 10
      else if (i==10) return new APP_MENU_APPLICATIONS_10; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 11
      else if (i==11) return new APP_MENU_APPLICATIONS_11; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 12
      else if (i==12) return new APP_MENU_APPLICATIONS_12; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 13
      else if (i==13) return new APP_MENU_APPLICATIONS_13; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 14
      else if (i==14) return new APP_MENU_APPLICATIONS_14; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 15
      else if (i==15) return new APP_MENU_APPLICATIONS_15; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 16
      else if (i==16) return new APP_MENU_APPLICATIONS_16; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 17
      else if (i==17) return new APP_MENU_APPLICATIONS_17; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 18
      else if (i==18) return new APP_MENU_APPLICATIONS_18; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 19
      else if (i==19) return new APP_MENU_APPLICATIONS_19; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 20
      else if (i==20) return new APP_MENU_APPLICATIONS_20; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 21
      else if (i==21) return new APP_MENU_APPLICATIONS_21; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 22
      else if (i==22) return new APP_MENU_APPLICATIONS_22; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 23
      else if (i==23) return new APP_MENU_APPLICATIONS_23; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 24
      else if (i==24) return new APP_MENU_APPLICATIONS_24; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 25
      else if (i==25) return new APP_MENU_APPLICATIONS_25; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 26
      else if (i==26) return new APP_MENU_APPLICATIONS_26; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 27
      else if (i==27) return new APP_MENU_APPLICATIONS_27; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 28
      else if (i==28) return new APP_MENU_APPLICATIONS_28; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 29
      else if (i==29) return new APP_MENU_APPLICATIONS_29; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 30
      else if (i==30) return new APP_MENU_APPLICATIONS_30; 
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 31
      else if (i==31) return new APP_MENU_APPLICATIONS_31; 
    #endif
    else return new appNameClass;
}

const unsigned char *getAppParams(char i, unsigned char type){
    if(i==0){ APP_MENU_APPLICATIONS_0 *app; return ((*app).getParams(type));
    #if APP_MENU_APPLICATIONS_QUANTITY > 1
      }else if(i==1){ APP_MENU_APPLICATIONS_1 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 2
      }else if(i==2){ APP_MENU_APPLICATIONS_2 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 3
      }else if(i==3){ APP_MENU_APPLICATIONS_3 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 4
      }else if(i==4){ APP_MENU_APPLICATIONS_4 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 5
      }else if(i==5){ APP_MENU_APPLICATIONS_5 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 6
      }else if(i==6){ APP_MENU_APPLICATIONS_6 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 7
      }else if(i==7){ APP_MENU_APPLICATIONS_7 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 8
      }else if(i==8){ APP_MENU_APPLICATIONS_8 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 9
      }else if(i==9){ APP_MENU_APPLICATIONS_9 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 10
      }else if(i==10){ APP_MENU_APPLICATIONS_10 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 11
      }else if(i==11){ APP_MENU_APPLICATIONS_11 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 12
      }else if(i==12){ APP_MENU_APPLICATIONS_12 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 13
      }else if(i==13){ APP_MENU_APPLICATIONS_13 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 14
      }else if(i==14){ APP_MENU_APPLICATIONS_14 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 15
      }else if(i==15){ APP_MENU_APPLICATIONS_15 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 16
      }else if(i==16){ APP_MENU_APPLICATIONS_16 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 17
      }else if(i==17){ APP_MENU_APPLICATIONS_17 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 18
      }else if(i==18){ APP_MENU_APPLICATIONS_18 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 19
      }else if(i==19){ APP_MENU_APPLICATIONS_19 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 20
      }else if(i==20){ APP_MENU_APPLICATIONS_20 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 21
      }else if(i==21){ APP_MENU_APPLICATIONS_21 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 22
      }else if(i==22){ APP_MENU_APPLICATIONS_22 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 23
      }else if(i==23){ APP_MENU_APPLICATIONS_23 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 24
      }else if(i==24){ APP_MENU_APPLICATIONS_24 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 25
      }else if(i==25){ APP_MENU_APPLICATIONS_25 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 26
      }else if(i==26){ APP_MENU_APPLICATIONS_26 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 27
      }else if(i==27){ APP_MENU_APPLICATIONS_27 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 28
      }else if(i==28){ APP_MENU_APPLICATIONS_28 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 29
      }else if(i==29){ APP_MENU_APPLICATIONS_29 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 30
      }else if(i==30){ APP_MENU_APPLICATIONS_30 *app; return ((*app).getParams(type));
    #endif
    #if APP_MENU_APPLICATIONS_QUANTITY > 31
      }else if(i==31){ APP_MENU_APPLICATIONS_31 *app; return ((*app).getParams(type));
    #endif
    }else return 0;
}

void startApp(char num){
  currentApp->onDestroy();
  currentApp = getApp(num);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    SHARED FUNCTIONS -                                    #
    #                                                                                          #
    ############################################################################################
*/
