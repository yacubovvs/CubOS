//#define CORE_TOUCH_DEBUG
//#define TOUCH_SCREEN_ENABLE
#ifndef MULTITOUCH_SCREEN_ENABLE
    #define MULTITOUCH_SCREEN_FINGERS 1
#endif

#ifdef TOUCH_SCREEN_ENABLE
    bool TOUCH_SCREEN_last_isTouching[MULTITOUCH_SCREEN_FINGERS];
    bool TOUCH_SCREEN_isDragging[MULTITOUCH_SCREEN_FINGERS];
    bool TOUCH_SCREEN_isLongPressed[MULTITOUCH_SCREEN_FINGERS];

    int TOUCH_SCREEN_last_x[MULTITOUCH_SCREEN_FINGERS];
    int TOUCH_SCREEN_last_y[MULTITOUCH_SCREEN_FINGERS];

    int TOUCH_SCREEN_touch_start_x[MULTITOUCH_SCREEN_FINGERS];
    int TOUCH_SCREEN_touch_start_y[MULTITOUCH_SCREEN_FINGERS];
    bool CORE_TOUCH_swipeStarted[MULTITOUCH_SCREEN_FINGERS];

    int getTOUCH_SCREEN_touch_start_x(uint8_t finger){
        return TOUCH_SCREEN_touch_start_x[finger];
    }
    int getTOUCH_SCREEN_touch_start_y(uint8_t finger){
        return TOUCH_SCREEN_touch_start_y[finger];
    }

    long TOUCH_SCREEN_touch_start_ms[MULTITOUCH_SCREEN_FINGERS];

    long getTOUCH_SCREEN_touch_start_ms(uint8_t finger){
        return TOUCH_SCREEN_touch_start_ms[finger];
    }

    void setup_touchScreenCore(){
        for(uint8_t finger=0; finger<MULTITOUCH_SCREEN_FINGERS; finger++){
            TOUCH_SCREEN_last_isTouching[finger] = false;
            TOUCH_SCREEN_isDragging[finger] = false;
            TOUCH_SCREEN_isLongPressed[finger] = false;
            CORE_TOUCH_swipeStarted[finger] = false;

            TOUCH_SCREEN_last_x[finger] = 0;
            TOUCH_SCREEN_last_y[finger] = 0;
            TOUCH_SCREEN_touch_start_x[finger] = 0;
            TOUCH_SCREEN_touch_start_y[finger] = 0;
            TOUCH_SCREEN_touch_start_ms[finger] = 0;
        }
    }

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

        for(uint8_t finger=0; finger<MULTITOUCH_SCREEN_FINGERS; finger++){

            if(!TOUCH_SCREEN_last_isTouching[finger] && getTOUCH_SCREEN_isTouching(finger)){

                TOUCH_SCREEN_last_isTouching[finger]    = true;
                TOUCH_SCREEN_last_x[finger]             = getTOUCH_SCREEN_X(finger);
                TOUCH_SCREEN_last_y[finger]             = getTOUCH_SCREEN_Y(finger);
                TOUCH_SCREEN_touch_start_x[finger]      = TOUCH_SCREEN_last_x[finger];
                TOUCH_SCREEN_touch_start_y[finger]      = TOUCH_SCREEN_last_y[finger];
                TOUCH_SCREEN_isDragging[finger]         = false;
                TOUCH_SCREEN_isLongPressed[finger]      = false;
                TOUCH_SCREEN_touch_start_ms[finger]     = millis();

                #ifdef CORE_TOUCH_DEBUG
                    debug("Touch start on finger " + String(finger));
                #endif

                
                currentApp->onEvent(EVENT_ON_TOUCH_START, TOUCH_SCREEN_last_x[finger], TOUCH_SCREEN_last_y[finger], 0, 0, finger);
                #ifdef SOFTWARE_KEYBOARD_ENABLE
                    core_software_keyboard_onEvent(EVENT_ON_TOUCH_START, TOUCH_SCREEN_last_x[finger], TOUCH_SCREEN_last_y[finger], 0, 0, 0);
                #endif
            }else if(TOUCH_SCREEN_last_isTouching[finger] && !getTOUCH_SCREEN_isTouching(finger)){

                TOUCH_SCREEN_last_isTouching[finger] = false;
                CORE_TOUCH_swipeStarted[finger] = false;

                #ifdef CORE_TOUCH_DEBUG
                    debug("Touch released on finger " + String(finger));
                #endif

                currentApp->onEvent(EVENT_ON_TOUCH_RELEASED, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, finger);
                #ifdef SOFTWARE_KEYBOARD_ENABLE
                    core_software_keyboard_onEvent(EVENT_ON_TOUCH_RELEASED, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, 0);
                #endif

                if(!TOUCH_SCREEN_isDragging[finger] && millis()-TOUCH_SCREEN_touch_start_ms[finger]<TOUCH_SCREEN_TIME_MS_FOR_LONG_TOUCH){
                    
                    #if defined(SOFTWARE_BUTTONS_ENABLE) || defined(SOFTWARE_KEYBOARD_ENABLE)
                        if(core_view_isSoftwareButtons_clicked(getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger))){
                            #ifdef CORE_TOUCH_DEBUG
                                debug("Touch click on software button on finger " + String(finger));
                            #endif    
                        }else{
                            #ifdef CORE_TOUCH_DEBUG
                                debug("Touch click on finger " + String(finger));
                            #endif    
                            currentApp->onEvent(EVENT_ON_TOUCH_CLICK, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, finger);
                            #ifdef SOFTWARE_KEYBOARD_ENABLE
                                core_software_keyboard_onEvent(EVENT_ON_TOUCH_CLICK, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, 0);
                            #endif
                        }
                    #else
                        #ifdef CORE_TOUCH_DEBUG
                            debug("Touch click on finger " + String(finger));
                        #endif    
                        currentApp->onEvent(EVENT_ON_TOUCH_CLICK, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, finger);
                        #ifdef SOFTWARE_KEYBOARD_ENABLE
                            core_software_keyboard_onEvent(EVENT_ON_TOUCH_CLICK, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, 0);
                        #endif
                    #endif
                    
                }else{
                    TOUCH_SCREEN_isDragging[finger] = false;
                    TOUCH_SCREEN_isLongPressed[finger] = false;
                }
                

            }else if(TOUCH_SCREEN_last_isTouching[finger] && getTOUCH_SCREEN_isTouching(finger)){

                int dx;
                int dy;

                if(!TOUCH_SCREEN_isDragging[finger]){
                    dx = getTOUCH_SCREEN_X(finger) - TOUCH_SCREEN_touch_start_x[finger];
                    dy = getTOUCH_SCREEN_Y(finger) - TOUCH_SCREEN_touch_start_y[finger];
                }else{
                    dx = getTOUCH_SCREEN_X(finger) - TOUCH_SCREEN_last_x[finger];
                    dy = getTOUCH_SCREEN_Y(finger) - TOUCH_SCREEN_last_y[finger];
                }

                //TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG
                if( (TOUCH_SCREEN_isDragging[finger]) || abs(dx)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG || abs(dy)>TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG){
                    TOUCH_SCREEN_isDragging[finger] = true;
                    TOUCH_SCREEN_last_x[finger] = getTOUCH_SCREEN_X(finger);
                    TOUCH_SCREEN_last_y[finger] = getTOUCH_SCREEN_Y(finger);

                    #ifdef CORE_TOUCH_DEBUG
                        debug("Touch drag on finger " + String(finger));
                    #endif
                    
                    currentApp->onEvent(EVENT_ON_TOUCH_DRAG, dx, dy, TOUCH_SCREEN_touch_start_x[finger], TOUCH_SCREEN_touch_start_y[finger], finger);

                    if(!CORE_TOUCH_swipeStarted[finger]){
                        if(abs(dx)>TOUCH_SCREEN_DELTA_MOVE_FOR_SWIPE || abs(dy)>TOUCH_SCREEN_DELTA_MOVE_FOR_SWIPE){
                            CORE_TOUCH_swipeStarted[finger] = true;
                            if(abs(dx)>abs(dy)){
                                if(dx>0){
                                    currentApp->onEvent(EVENT_ON_TOUCH_QUICK_SWIPE_TO_RIGHT, dx, dy, 0, 0, finger);
                                    #ifdef CORE_TOUCH_DEBUG
                                        debug("CORE_TOUCH_DEBUG: EVENT_ON_TOUCH_QUICK_SWIPE_TO_RIGHT on finger " + String(finger));
                                    #endif
                                }else{
                                    currentApp->onEvent(EVENT_ON_TOUCH_QUICK_SWIPE_TO_LEFT, dx, dy, 0, 0, finger);
                                    #ifdef CORE_TOUCH_DEBUG
                                        debug("CORE_TOUCH_DEBUG: EVENT_ON_TOUCH_QUICK_SWIPE_TO_LEFT on finger " + String(finger));
                                    #endif
                                } 
                            }else{
                                if(dy>0){
                                    currentApp->onEvent(EVENT_ON_TOUCH_QUICK_SWIPE_TO_BOTTOM, dx, dy, 0, 0, finger);
                                    #ifdef CORE_TOUCH_DEBUG
                                        debug("CORE_TOUCH_DEBUG: EVENT_ON_TOUCH_QUICK_SWIPE_TO_BOTTOM on finger " + String(finger));
                                    #endif
                                }else{
                                    currentApp->onEvent(EVENT_ON_TOUCH_QUICK_SWIPE_TO_TOP, dx, dy, 0, 0, finger);
                                    #ifdef CORE_TOUCH_DEBUG
                                        debug("CORE_TOUCH_DEBUG: EVENT_ON_TOUCH_QUICK_SWIPE_TO_TOP on finger " + String(finger));
                                    #endif
                                } 
                            }
                        }
                    }

                    #ifdef SOFTWARE_KEYBOARD_ENABLE
                        core_software_keyboard_onEvent(EVENT_ON_TOUCH_DRAG, dx, dy, 0, 0, 0);
                    #endif

                }else if(!TOUCH_SCREEN_isLongPressed[finger] && millis()-TOUCH_SCREEN_touch_start_ms[finger]>TOUCH_SCREEN_TIME_MS_FOR_LONG_TOUCH){
                    TOUCH_SCREEN_isLongPressed[finger] = true;

                    #ifdef CORE_TOUCH_DEBUG
                        debug("Touch long press on finger " + String(finger));
                    #endif
                    
                    currentApp->onEvent(EVENT_ON_TOUCH_LONG_PRESS, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, finger);
                    #ifdef SOFTWARE_KEYBOARD_ENABLE
                        core_software_keyboard_onEvent(EVENT_ON_TOUCH_LONG_PRESS, getTOUCH_SCREEN_X(finger), getTOUCH_SCREEN_Y(finger), 0, 0, 0);
                    #endif
                }
                
            } 
        }
    }

#endif
