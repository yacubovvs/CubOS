#ifdef PEDOMETER_ENABLE
    RTC_DATA_ATTR long pedometer_steps = 0;
    long get_pedometer_steps(){ return pedometer_steps;}
    void set_pedometer_steps(long steps){pedometer_steps = steps;}

    void core_pedometer_newDate(){
        set_pedometer_steps(0);
    }

    #ifndef PEDOMETER_STEPS_IN_SEC
        #define PEDOMETER_STEPS_IN_SEC                          1.65f
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
                if(core_pedometer_current_step_detection==PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD){
                    core_pedometer_current_step_detection=-1;
                    core_pedometer_analyse_steps_mesure(inBackGroung);
                }
            }

            if(inBackGroung){
                #ifdef PEDOMETER_DEBUG
                    // debug("PEDOMETER MESURE IN BACKGROUN", 10);
                #endif
                /*
                if( getCurrentSystemTime()==get_core_powersave_lastUserAction()){
                    core_cpu_sleep(STAND_BY_SLEEP_TYPE, 1);   
                }*/
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
            if(core_pedometer_step_detection_arrays[i]>=analysis_central_value){
                analysis_central_weight_value += core_pedometer_step_detection_arrays[i] - analysis_central_value;
            }else{
                analysis_central_weight_value += analysis_central_value - core_pedometer_step_detection_arrays[i];
            }
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
        #define PEDOMETER_DELTA_VALUE_MIN           0.5f
        #define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.1f

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        if( true && //|| 
                (
                    true
                    //&& analysis_axis_crossings<=PEDOMETER_CROSSINGS_MAX 
                    //&& analysis_axis_crossings>=PEDOMETER_CROSSINGS_MIN
                    && analysis_delta_value >= PEDOMETER_DELTA_VALUE_MIN
                    && analysis_central_value>=PEDOMETER_CENTRALWIGHT_VALUE_MIN
                )
            ){
                //
                #ifdef PEDOMETER_DEBUG
                    debug("Is walking", 10);
                    //if(!inBackground) digitalWrite(10,0);
                #endif
                pedometer_steps += (PEDOMETER_STEPS_IN_SEC*( (float)(PEDOMETER_STEP_DETECTION_DELAY + PEDOMETER_STEP_DETECTION_PERIOD_MS)))/1000;
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