#ifdef TOUCH_SCREEN_ENABLE

    #include <MCUFRIEND_kbv.h>
    MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
    #include <TouchScreen.h>

    const int XP=6,XM=A2,YP=A1,YM=7; //ID=0x9341
    const int TS_LEFT=907,TS_RT=136,TS_TOP=942,TS_BOT=139;

    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
    TSPoint tp;

    #define MINPRESSURE 200
    #define MAXPRESSURE 1000

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

    int driver_touchscreen_calibration_y_min = 140;
    int driver_touchscreen_calibration_y_max = 961;
    int driver_touchscreen_calibration_x_min = 146;
    int driver_touchscreen_calibration_x_max = 920;

    void loop_touchScreenDriver(){
        tp = ts.getPoint();   //tp.x, tp.y are ADC values

        // if sharing pins, you'll need to fix the directions of the touchscreen pins
        //pinMode(XM, OUTPUT);
        //pinMode(YP, OUTPUT);
        // we have some minimum pressure we consider 'valid'
        // pressure of 0 means no pressing!

        int x_delta = driver_touchscreen_calibration_x_max - driver_touchscreen_calibration_x_min;
        int y_delta = driver_touchscreen_calibration_y_max - driver_touchscreen_calibration_y_min;

        float x_k = ((float)(tp.x-driver_touchscreen_calibration_x_min))/(float)x_delta;
        float y_k = 1.0-((float)(tp.y-driver_touchscreen_calibration_y_min))/(float)y_delta;

        if(tp.z>0){
            //debug("X: " + String(tp.x) + "     Y: " + String(tp.y) + "     Z: " + String(tp.z));
            int x = y_k*SCREEN_WIDTH;
            int y = x_k*SCREEN_HEIGHT;

            if(x>SCREEN_WIDTH) x = SCREEN_WIDTH; 
            if(x<0) x = 0;
            if(y>SCREEN_HEIGHT) y = SCREEN_HEIGHT; 
            if(y<0) y = 0;

            //debug("X: " + String(x) + "     Y: " + String(y));
            TOUCH_SCREEN_isTouching = true;
            TOUCH_SCREEN_X = x;
            TOUCH_SCREEN_Y = y;
        }else{
            TOUCH_SCREEN_isTouching = false;
        }
        
        //if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
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

