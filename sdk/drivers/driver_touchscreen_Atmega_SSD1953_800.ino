#ifdef TOUCH_SCREEN_ENABLE

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
    }

#endif

