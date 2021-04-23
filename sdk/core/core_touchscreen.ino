#ifdef TOUCH_SCREEN_ENABLE
    bool TOUCH_SCREEN_last_isTouching   = false;
    bool TOUCH_SCREEN_isDragging        = false;
    bool TOUCH_SCREEN_isLongPressed     = false;

    int TOUCH_SCREEN_last_x = 0;
    int TOUCH_SCREEN_last_y = 0;

    int TOUCH_SCREEN_touch_start_x = 0;
    int TOUCH_SCREEN_touch_start_y = 0;

    int getTOUCH_SCREEN_touch_start_x(){
        return TOUCH_SCREEN_touch_start_x;
    }
    int getTOUCH_SCREEN_touch_start_y(){
        return TOUCH_SCREEN_touch_start_y;
    }

    long TOUCH_SCREEN_touch_start_ms = 0;

    void loop_touchScreenCore(){
        loop_touchScreenDriver();
        
        /*
        #define EVENT_ON_TOUCH_START            0x06
        #define EVENT_ON_TOUCH_RELEASED         0x07
        #define EVENT_ON_TOUCH_CLICK            0x08
        #define EVENT_ON_TOUCH_LONG_PRESS       0x09
        #define EVENT_ON_TOUCH_DRAG             0x0A
        #define EVENT_ON_TOUCH_DOUBLE_CLICK     0x0B
        */

        if(!TOUCH_SCREEN_last_isTouching && getTOUCH_SCREEN_isTouching()){

            TOUCH_SCREEN_last_isTouching = true;
            TOUCH_SCREEN_last_x = getTOUCH_SCREEN_X();
            TOUCH_SCREEN_last_y = getTOUCH_SCREEN_Y();
            TOUCH_SCREEN_touch_start_x = TOUCH_SCREEN_last_x;
            TOUCH_SCREEN_touch_start_y = TOUCH_SCREEN_last_y;
            TOUCH_SCREEN_isDragging = false;
            TOUCH_SCREEN_isLongPressed = false;
            TOUCH_SCREEN_touch_start_ms = millis();
            currentApp->onEvent(EVENT_ON_TOUCH_START, TOUCH_SCREEN_last_x, TOUCH_SCREEN_last_y);

        }else if(TOUCH_SCREEN_last_isTouching && !getTOUCH_SCREEN_isTouching()){

            TOUCH_SCREEN_last_isTouching = false;
            currentApp->onEvent(EVENT_ON_TOUCH_RELEASED, getTOUCH_SCREEN_X(), getTOUCH_SCREEN_Y());

        }else if(TOUCH_SCREEN_last_isTouching && getTOUCH_SCREEN_isTouching()){

            int dx = getTOUCH_SCREEN_X() - TOUCH_SCREEN_touch_start_x;
            int dy = getTOUCH_SCREEN_Y() - TOUCH_SCREEN_touch_start_y;

            //TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG
            if(TOUCH_SCREEN_isDragging || abs(dx)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG || abs(dy)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG){
                TOUCH_SCREEN_isDragging = true;
                TOUCH_SCREEN_last_x = getTOUCH_SCREEN_X();
                TOUCH_SCREEN_last_y = getTOUCH_SCREEN_Y();

                currentApp->onEvent(EVENT_ON_TOUCH_DRAG, dx, dy);
            }else if(!TOUCH_SCREEN_isLongPressed && millis()-TOUCH_SCREEN_touch_start_ms>TOUCH_SCREEN_TIME_MS_FOT_LONG_TOUCH){
                TOUCH_SCREEN_isLongPressed = true;
                currentApp->onEvent(EVENT_ON_TOUCH_LONG_PRESS, getTOUCH_SCREEN_X(), getTOUCH_SCREEN_Y());
            }
            
        } 
    }

#endif
