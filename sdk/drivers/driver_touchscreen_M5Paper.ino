#ifdef TOUCH_SCREEN_ENABLE

    // bool TOUCH_SCREEN_isTouching
    // int TOUCH_SCREEN_X = 0;
    // int TOUCH_SCREEN_Y = 0;

    bool TOUCH_SCREEN_isTouching[MULTITOUCH_SCREEN_FINGERS] = {false, false};
    int TOUCH_SCREEN_TOUCHES[MULTITOUCH_SCREEN_FINGERS][2] = {{539,0},{539,0}};

    bool getTOUCH_SCREEN_isTouching(int touch){
        return TOUCH_SCREEN_isTouching[touch];
    }

    int getTOUCH_SCREEN_X(int touch){
        return TOUCH_SCREEN_TOUCHES[touch][0];
    }

    int getTOUCH_SCREEN_Y(int touch){
        return TOUCH_SCREEN_TOUCHES[touch][1];
    }

    void setup_touchScreenDriver(){}

    void loop_touchScreenDriver(){

        if(M5.TP.avaliable()){
            if(!M5.TP.isFingerUp()){
                M5.TP.update();
                //canvas.fillCanvas(0);
                //bool is_update = false;
                for(int i=0;i<MULTITOUCH_SCREEN_FINGERS; i++){
                    tp_finger_t FingerItem = M5.TP.readFinger(i);
                    #define x_value (SCREEN_WIDTH - 1 - FingerItem.y)
                    #define y_value FingerItem.x
                    
                    if((TOUCH_SCREEN_TOUCHES[i][0]!=x_value)||(TOUCH_SCREEN_TOUCHES[i][1]!=y_value)){
                        TOUCH_SCREEN_TOUCHES[i][0] = x_value;
                        TOUCH_SCREEN_TOUCHES[i][1] = y_value;

                        TOUCH_SCREEN_isTouching[i] = true;
                        //canvas.fillRect(FingerItem.x-50, FingerItem.y-50, 100, 100, 15);
                        //Serial.printf("Finger ID:%d-->X: %d*C  Y: %d  Size: %d\r\n", FingerItem.id, FingerItem.x, FingerItem.y , FingerItem.size);
                    }
                    
                }
            }else{
                for(int i=0;i<MULTITOUCH_SCREEN_FINGERS; i++){
                    TOUCH_SCREEN_isTouching[i] = false;
                }
            }
        }

    }

#endif

