#ifdef TOUCH_SCREEN_ENABLE

    bool TOUCH_SCREEN_isTouching = false;
    int TOUCH_SCREEN_X = 0;
    int TOUCH_SCREEN_Y = 0;

    bool getTOUCH_SCREEN_isTouching(unsigned char finger){
        return TOUCH_SCREEN_isTouching;
    }

    int getTOUCH_SCREEN_X(unsigned char finger){
        return TOUCH_SCREEN_X;
    }

    int getTOUCH_SCREEN_Y(unsigned char finger){
        return TOUCH_SCREEN_Y;
    }

    void setup_touchScreenDriver(){
        
    }

    void loop_touchScreenDriver(){
        //driver_display_updateTouchScreen();
        //TOUCH_SCREEN_X = 0;
        //TOUCH_SCREEN_Y = 0;
        //TOUCH_SCREEN_isTouching = false;

        int16_t x, y;
        if (ttgo->getTouch(x, y)) {
            TOUCH_SCREEN_X = x;
            TOUCH_SCREEN_Y = y;
            TOUCH_SCREEN_isTouching = true;
            set_core_powersave_lastUserAction();
            /*
            debug("X: ");
            debug(String(TOUCH_SCREEN_X));
            debug("Y: ");
            debug(String(TOUCH_SCREEN_Y));
            */
        }else{
            TOUCH_SCREEN_isTouching = false;
        }
    }

#endif

