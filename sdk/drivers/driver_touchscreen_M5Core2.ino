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

        Event& e = M5.Buttons.event;
        
        if(e & E_TOUCH | e & E_MOVE){
            TOUCH_SCREEN_X = e.to.x;
            TOUCH_SCREEN_Y = e.to.y;    
            TOUCH_SCREEN_isTouching = true;
            //debug("X: " + String(x) + ", Y:" + String(y));
        }
        //if(e & E_MOVE) debug("Move!");
        if(e & E_RELEASE){
            TOUCH_SCREEN_isTouching = false;
            //debug("X: " + String(x) + ", Y:" + String(y));
        }
        /*
        if(e & E_TOUCH) debug("Touch!");
        if(e & E_MOVE) debug("Move!");
        if(e & E_RELEASE) debug("Release!");
        if(e){
            
            if(E_RELEASE){
                x = e.to.x;
                y = e.to.y;    
                TOUCH_SCREEN_isTouching = false;
                debug("Released X: " + String(x) + ", Y:" + String(y));
            }

            if(E_TOUCH | E_MOVE){
                x = e.to.x;
                y = e.to.y;    
                TOUCH_SCREEN_isTouching = true;
                debug("X: " + String(x) + ", Y:" + String(y));
            }
            
        }else{
        }
        */
        //if (e & (E_MOVE | E_RELEASE)) circle(e & E_MOVE ? e.from : e.to, WHITE);
        //if (e & (E_TOUCH | E_MOVE)) circle(e.to, e.finger ? BLUE : RED);

        /*
        if (ttgo->getTouch(x, y)) {
            TOUCH_SCREEN_X = x;
            TOUCH_SCREEN_Y = y;
            TOUCH_SCREEN_isTouching = true;
            
            //debug("X: ");
            //debug(String(TOUCH_SCREEN_X));
            //debug("Y: ");
            //debug(String(TOUCH_SCREEN_Y));
        }else{
            TOUCH_SCREEN_isTouching = false;
        }
        */
    }

#endif

