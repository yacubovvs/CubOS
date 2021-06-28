#ifdef PEDOMETER_ENABLE
    //RTC_DATA_ATTR long pedometer_days_steps = 0;

    //#define PEDOMETER_DAY_VALUE_TYPE long
    RTC_DATA_ATTR uint16_t pedometer_days_steps_min_limit = PEDOMETER_DAY_STEP_LIMMIT_DEFAULT;
    RTC_DATA_ATTR uint16_t pedometer_days_sleep_min_limit = PEDOMETER_DAY_SLEEP_LIMMIT_DEFAULT; // in minutes
    
    RTC_DATA_ATTR PEDOMETER_DAY_VALUE_TYPE pedometer_days_steps[PEDOMETER_DAYS_HISTORY] = {10001,5002,2003,1004,7005,8006,4007};
    RTC_DATA_ATTR uint16_t pedometer_days_sleep[PEDOMETER_DAYS_HISTORY] = {420,180,600,300,200,520,418};

    // Steps in every hour
    RTC_DATA_ATTR uint16_t pedometer_hours_steps[24] = {200, 50, 0, 0, 0, 0, 0, 0, 300, 500, 1000, 400, 200, 300, 200, 300, 1000, 1500, 1700, 1500, 1200, 600, 300, 240};
    // Sleep minutes in every hour
    RTC_DATA_ATTR uint8_t pedometer_hours_sleep[24] = {0, 7, 50, 60, 60, 55, 45, 60, 10, 0, 0, 4, 0, 0, 15, 35, 0, 0, 0, 0, 0, 0, 0, 15};

    PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(unsigned char day){ return pedometer_days_steps[day];}
    PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(){ return get_pedometer_days_steps(0);}
    
    uint16_t get_pedometer_hours_steps(unsigned char hour){ return pedometer_hours_steps[hour];}
    uint8_t get_pedometer_hours_sleep(unsigned char hour){ return pedometer_hours_sleep[hour];}
    uint16_t get_pedometer_days_sleep(unsigned char day){ return pedometer_days_sleep[day];}
    uint16_t get_pedometer_days_sleep(){ return get_pedometer_days_sleep(0);}
    uint16_t get_pedometer_days_steps_min_limit(){return pedometer_days_steps_min_limit;}
    uint16_t get_pedometer_days_sleep_min_limit(){return pedometer_days_sleep_min_limit;} //in minutes

    void set_pedometer_hours_steps(unsigned char hour, uint16_t steps){ pedometer_hours_steps[hour] = steps;}
    void set_pedometer_hours_sleep(unsigned char hour, uint8_t sleep_minutes){ pedometer_hours_sleep[hour] = sleep_minutes;}
    void set_pedometer_days_steps_min_limit(uint16_t limit){pedometer_days_steps_min_limit = limit;}
    void set_pedometer_days_sleep_min_limit(uint16_t limit){pedometer_days_sleep_min_limit = limit;} //in minutes
    void set_pedometer_days_steps(unsigned char day, PEDOMETER_DAY_VALUE_TYPE steps){pedometer_days_steps[0] = steps;}
    void set_pedometer_days_sleep(unsigned char day, uint16_t sleep){pedometer_days_sleep[0] = sleep;}
    void set_pedometer_days_steps(uint16_t sleep){set_pedometer_days_sleep(0, sleep);}

    void core_pedometer_newDate(){
        for(unsigned char i=PEDOMETER_DAYS_HISTORY-1; i>0; i--){
            pedometer_days_steps[i] = pedometer_days_steps[i-1];
        }
        debug("new date");
        set_pedometer_days_steps(0, 0);
    }

    #ifndef pedometer_days_steps_IN_SEC
        #define pedometer_days_steps_IN_SEC                          1.65f
    #endif

    #define CORE_PEDOMETER_MESURE_EVERY_MS                      (PEDOMETER_STEP_DETECTION_PERIOD_MS/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD)

    bool pedometer_on = PEDOMETER_ENABLE_ON_START;
    void core_pedometer_setEnable(bool enable){
        pedometer_on = enable;
    }

    int     core_pedometer_current_step_detection = -1;
    float   core_pedometer_step_detection_arrays[PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD];
    long    core_pedometer_step_detection_start_time = 0;
    RTC_DATA_ATTR long    lastTimeWalkingDetection = 0;

    void core_pedometer_setup(){
        // Just for test M5StickC
        #ifdef PEDOMETER_DEBUG
            //pinMode(10, OUTPUT);
            //digitalWrite(10, 1);
        #endif
    }

    void core_pedometer_loop(bool inBackGroung){
        if(pedometer_on){
            #ifdef PEDOMETER_DEBUG
                //debug("Pedometer is ON!", 10);
            #endif 

            if(core_pedometer_current_step_detection!=-1){
                #ifdef PEDOMETER_DEBUG
                    //debug("Pedometer - Not first mesure!", 10);
                #endif
                core_pedometer_mesure_loop(inBackGroung);
            }else{
                #ifdef PEDOMETER_DEBUG 
                    //debug("Pedometer - check time!", 10);
                #endif
                
                if(getCurrentSystemTime()<lastTimeWalkingDetection) lastTimeWalkingDetection = getCurrentSystemTime();

                if( (inBackGroung && (lastTimeWalkingDetection + (PEDOMETER_STEP_DETECTION_DELAY)/1000<=getCurrentSystemTime()))
                    || ( !inBackGroung && millis() - core_pedometer_step_detection_start_time>=(PEDOMETER_STEP_DETECTION_DELAY) )
                ){
                    if(inBackGroung){
                        #ifdef ACCELEROMETER_ENABLE
                            driver_accelerometer_setup();
                            #ifdef WAKEUP_DEBUG
                                debug("Accelerometer is setted up " + String(millis()), 10);;
                            #endif
                            #ifdef PEDOMETER_DEBUG
                                debug("Accelerometer is setted up", 10);
                            #endif
                        #endif
                    }

                    #ifdef PEDOMETER_DEBUG
                        debug("Pedometer - Start step!", 10);
                    #endif
                    core_pedometer_start_step_detection(inBackGroung);
                    core_pedometer_mesure_loop(inBackGroung);
                }else{
                    #ifdef PEDOMETER_DEBUG
                        //debug("!!!!! Time not come", 10);
                    #endif
                }
            }
        }else{
            #ifdef PEDOMETER_DEBUG
                debug("Pedometer is OFF!", 10);
            #endif 
        }
    }

    void core_pedometer_mesure_loop(){ core_pedometer_mesure_loop(true); }
    void core_pedometer_mesure_loop(bool inBackGroung){
        if(core_pedometer_current_step_detection!=-1){

            if(
                (inBackGroung) || 
                ( (millis()-core_pedometer_step_detection_start_time)/CORE_PEDOMETER_MESURE_EVERY_MS >= core_pedometer_current_step_detection ) 
                ){ // Mesure condition

                #ifdef PEDOMETER_DEBUG
                    debug("Mesure " + String( core_pedometer_current_step_detection));
                #endif

                driver_accelerometer_update_accelerometer();
                core_pedometer_step_detection_arrays[core_pedometer_current_step_detection] = driver_accelerometer_get_accel_total();

                core_pedometer_current_step_detection++;
                if(
                    core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1]<0.2f ||
                    core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1]>1.8f
                ){
                    core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1] = 1;
                    core_pedometer_current_step_detection--;
                    // Testnig fot detecting noise n103
                }

                if(core_pedometer_current_step_detection==PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD){
                    core_pedometer_current_step_detection=-1;
                    core_pedometer_analyse_steps_mesure(inBackGroung);
                }
            }

            if(inBackGroung){
                #ifdef PEDOMETER_DEBUG
                    // debug("PEDOMETER MESURE IN BACKGROUN", 10);
                #endif
                
                #ifdef WAKEUP_DEBUG
                    debug("Mesure in BG "  + String(millis()), 10);
                #endif
                core_cpu_sleep(SLEEP_LIGHT, CORE_PEDOMETER_MESURE_EVERY_MS, false); 
                core_pedometer_mesure_loop(true);
            }
        }
        

    }

    void core_pedometer_start_step_detection(bool inBackGroung){
        core_pedometer_current_step_detection = 0;
        for(int i=0; i<PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD; i++){
            core_pedometer_step_detection_arrays[i] = 0.0f;
        }
        core_pedometer_step_detection_start_time = millis();
    }

    #ifdef PEDOMETER_DEBUG
        float analysis_max_value = -1;
        float analysis_min_value = 100;
        float analysis_delta_value;
        float analysis_central_weight_value = 0;
        float analysis_central_value;
        int analysis_axis_crossings = 0;

        float get_analysis_max_value(){             return analysis_max_value;}
        float get_analysis_min_value(){             return analysis_min_value;}
        float get_analysis_delta_value(){           return analysis_delta_value;}
        float get_analysis_central_weight_value(){  return analysis_central_weight_value;}
        float get_analysis_central_value(){         return analysis_central_value;}
        int get_analysis_axis_crossings(){          return analysis_axis_crossings;}
    #endif

    #define ABS(x) ((x)>0?(x):-(x))

    bool core_pedometer_analyse_steps_mesure(bool inBackground){

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        #ifdef PEDOMETER_DEBUG
            analysis_max_value = -1;
            analysis_min_value = 100;
            analysis_delta_value;
            analysis_central_weight_value = 0;
            analysis_central_value;
            analysis_axis_crossings = 0;
        #else
            float analysis_max_value = -1;
            float analysis_min_value = 100;
            float analysis_delta_value;
            float analysis_central_weight_value = 0;
            float analysis_central_value;
            int analysis_axis_crossings = 0;
        #endif

        // getiing max and min dots
        for(int i=0; i<PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD; i++){
            if(core_pedometer_step_detection_arrays[i]>analysis_max_value){
                analysis_max_value = core_pedometer_step_detection_arrays[i];
            }

            if(core_pedometer_step_detection_arrays[i]<analysis_min_value){
                analysis_min_value = core_pedometer_step_detection_arrays[i];
            }
        }

        analysis_central_value = (analysis_max_value + analysis_min_value)/2;
        analysis_delta_value = analysis_max_value - analysis_min_value;

        bool isMin = false;
        if(core_pedometer_step_detection_arrays[0]<analysis_central_value) isMin = true;

        for(int i=0; i<PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD; i++){
            //core_pedometer_step_detection_arrays[i]
            if(
                (isMin && core_pedometer_step_detection_arrays[i]>=analysis_central_value)
                || (!isMin && core_pedometer_step_detection_arrays[i]<=analysis_central_value)
            ){
                isMin = !isMin;
                analysis_axis_crossings++;
            }

            //analysis_central_weight_value += core_pedometer_step_detection_arrays[i];
            /*
            if(core_pedometer_step_detection_arrays[i]>=analysis_central_value){
                analysis_central_weight_value += core_pedometer_step_detection_arrays[i] - analysis_central_value;
            }else{
                analysis_central_weight_value += analysis_central_value - core_pedometer_step_detection_arrays[i];
            }*/
            analysis_central_weight_value += ABS(core_pedometer_step_detection_arrays[i] - analysis_central_value);
        }

        analysis_central_weight_value = analysis_central_weight_value/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD;

        #ifdef PEDOMETER_DEBUG
            debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
            debug( String("max_value: ") + analysis_max_value);
            debug( String("min_value: ") + analysis_min_value);
            debug( String("delta_value: ") + analysis_delta_value);
            debug( String("axis_crossings: ") + analysis_axis_crossings);
            debug( String("central_value: ") + analysis_central_value);
            debug( String("central_weight_value: ") + analysis_central_weight_value);
            debug("                                                                    ");
        #endif
        

        #define PEDOMETER_CROSSINGS_MIN             (8*1000/PEDOMETER_STEP_DETECTION_PERIOD_MS)
        #define PEDOMETER_CROSSINGS_MAX             (16*1000/PEDOMETER_STEP_DETECTION_PERIOD_MS)
        #ifndef PEDOMETER_DELTA_VALUE_MIN
            #define PEDOMETER_DELTA_VALUE_MIN           0.5f
        #endif
        #ifndef PEDOMETER_CENTRALWIGHT_VALUE_MIN
            #define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.1f
        #endif

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        if( true && //|| 
                (
                    true
                    //&& analysis_axis_crossings<=PEDOMETER_CROSSINGS_MAX 
                    //&& analysis_axis_crossings>=PEDOMETER_CROSSINGS_MIN
                    && analysis_delta_value >= PEDOMETER_DELTA_VALUE_MIN
                    && analysis_central_weight_value>=PEDOMETER_CENTRALWIGHT_VALUE_MIN
                )
            ){
                //
                #ifdef PEDOMETER_DEBUG
                    debug("Is walking", 10);
                    //if(!inBackground) digitalWrite(10,0);
                #endif
                pedometer_days_steps[0] += (PEDOMETER_DAY_VALUE_TYPE)((pedometer_days_steps_IN_SEC*( (float)(PEDOMETER_STEP_DETECTION_DELAY + PEDOMETER_STEP_DETECTION_PERIOD_MS)))/1000);
            }else{
                #ifdef PEDOMETER_DEBUG
                    debug("Is not walking", 10);
                    //if(!inBackground) digitalWrite(10,1);
                #endif
                
            }

        core_pedometer_step_detection_start_time = millis();
        lastTimeWalkingDetection = getCurrentSystemTime();
        return true;
    }


#endif