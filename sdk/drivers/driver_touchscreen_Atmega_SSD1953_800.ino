#ifdef TOUCH_SCREEN_ENABLE
    #define CAL_X 1118123
    #define CAL_Y 5410664
    #define CAL_S 2150756831

    #include <UTouch.h>
    
    UTouch myTouch(6,5,4,3,2);
    bool TOUCH_SCREEN_isTouching = false;
    int TOUCH_SCREEN_X = 0;
    int TOUCH_SCREEN_Y = 0;

    bool getTOUCH_SCREEN_isTouching(){
        return TOUCH_SCREEN_isTouching;
    }

    int getTOUCH_SCREEN_X(){
        return TOUCH_SCREEN_X;
    }

    int getTOUCH_SCREEN_Y(){
        return TOUCH_SCREEN_Y;
    }

    void setup_touchScreenDriver(){
        myTouch.InitTouch();
        myTouch.setPrecision(PREC_HI);
    }

    void loop_touchScreenDriver(){
        //driver_display_updateTouchScreen();
        //TOUCH_SCREEN_X = 0;
        //TOUCH_SCREEN_Y = 0;
        //TOUCH_SCREEN_isTouching = false;

        /*
        int16_t x, y;
        if (ttgo->getTouch(x, y)) {
            TOUCH_SCREEN_X = x;
            TOUCH_SCREEN_Y = y;
            TOUCH_SCREEN_isTouching = true;
        }else{
            TOUCH_SCREEN_isTouching = false;
        }
        */
        int X_RAW;
        int Y_RAW;
        int X;
        int Y;
        
        if (myTouch.dataAvailable() == true){
            myTouch.read();
            X_RAW=myTouch.TP_X;
            Y_RAW=myTouch.TP_Y;
            X=myTouch.getX();
            Y=myTouch.getY();
            
            debug("X" + String(X) + "    Y" + String(Y));
            
        }

    }

#endif

