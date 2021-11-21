
#if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
    //RTC_DATA_ATTR long pedometer_days_steps = 0;

    bool pedometer_in_work = false;
    bool get_pedometer_in_work(){
        return pedometer_in_work;
    }

    RTC_DATA_ATTR unsigned char analyse_sleep_delta_accels = 0;
    RTC_DATA_ATTR unsigned char corePedometer_currentsleep_between_mesures = PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN;

    //#define PEDOMETER_DAY_VALUE_TYPE long
    RTC_DATA_ATTR uint16_t pedometer_days_steps_min_limit = PEDOMETER_DAY_STEP_LIMMIT_DEFAULT;
    RTC_DATA_ATTR uint16_t pedometer_days_sleep_min_limit = PEDOMETER_DAY_SLEEP_LIMMIT_DEFAULT; // in minutes
    
    #ifdef PEDOMETER_EMULATOR
        // Presentation and emulator data
        RTC_DATA_ATTR PEDOMETER_DAY_VALUE_TYPE pedometer_days_steps[PEDOMETER_DAYS_HISTORY] = {8340,12234,7654,23593,5633,1290,430};
        RTC_DATA_ATTR uint16_t pedometer_days_sleep[PEDOMETER_DAYS_HISTORY] = {430,550,230,500,349,765,234};
        RTC_DATA_ATTR uint16_t pedometer_hours_steps[24] = {0,   0,  0,  0,  0,  0, 120, 300, 1232, 10, 23, 43, 1230, 900, 534, 230, 890, 600, 200, 100, 10,  0, 10, 0};
        RTC_DATA_ATTR uint8_t pedometer_hours_sleep[24] =  {60, 60, 60, 58, 60, 34, 0,   0,   0,    0,  0,  0,  0,    0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 23};

        PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(unsigned char day){ 
            pedometer_days_steps[0] = 8340; pedometer_days_steps[1] = 12234; pedometer_days_steps[2] = 7654; pedometer_days_steps[3] = 23593;
            pedometer_days_steps[4] = 5633; pedometer_days_steps[5] = 1290; pedometer_days_steps[6] = 430;

            return pedometer_days_steps[day];
        }
        uint16_t get_pedometer_days_sleep(unsigned char day){ 
            pedometer_days_sleep[0] = 430; pedometer_days_sleep[1] = 550; pedometer_days_sleep[2] = 230; pedometer_days_sleep[3] = 500;
            pedometer_days_sleep[4] = 349; pedometer_days_sleep[5] = 765; pedometer_days_sleep[6] = 234;

            return pedometer_days_sleep[day];
        }
        uint16_t get_pedometer_hours_steps(unsigned char hour){ 
            pedometer_hours_steps[0] = 0; pedometer_hours_steps[1] = 0; pedometer_hours_steps[2] = 0;  pedometer_hours_steps[3] = 0; pedometer_hours_steps[4] = 0;
            pedometer_hours_steps[5] = 0; pedometer_hours_steps[6] = 120; pedometer_hours_steps[7] = 300; pedometer_hours_steps[8] = 1232; pedometer_hours_steps[9] = 10;
            pedometer_hours_steps[10] = 23; pedometer_hours_steps[11] = 43; pedometer_hours_steps[12] = 1230; pedometer_hours_steps[13] = 900; pedometer_hours_steps[14] = 534;
            pedometer_hours_steps[15] = 230; pedometer_hours_steps[16] = 890; pedometer_hours_steps[17] = 600; pedometer_hours_steps[18] = 200; pedometer_hours_steps[19] = 100;
            pedometer_hours_steps[20] = 10; pedometer_hours_steps[21] = 0; pedometer_hours_steps[22] = 10; pedometer_hours_steps[23] = 0; 
            return pedometer_hours_steps[hour];
        }
        uint8_t get_pedometer_hours_sleep(unsigned char hour){ 
            pedometer_hours_sleep[0] = 60; pedometer_hours_sleep[1] = 60; pedometer_hours_sleep[2] = 60; pedometer_hours_sleep[3] = 58; pedometer_hours_sleep[4] = 60; 
            pedometer_hours_sleep[5] = 34; pedometer_hours_sleep[6] = 0; pedometer_hours_sleep[7] = 0; pedometer_hours_sleep[8] = 0; pedometer_hours_sleep[9] = 0;  
            pedometer_hours_sleep[10] = 0; pedometer_hours_sleep[11] = 0; pedometer_hours_sleep[12] = 0; pedometer_hours_sleep[13] = 0; pedometer_hours_sleep[14] = 0;   
            pedometer_hours_sleep[15] = 0; pedometer_hours_sleep[16] = 0; pedometer_hours_sleep[17] = 0; pedometer_hours_sleep[18] = 0; pedometer_hours_sleep[19] = 0;   
            pedometer_hours_sleep[20] = 0; pedometer_hours_sleep[21] = 0; pedometer_hours_sleep[22] = 0; pedometer_hours_sleep[23] = 23; 
            return pedometer_hours_sleep[hour];
        }
    #else
        
        RTC_DATA_ATTR PEDOMETER_DAY_VALUE_TYPE pedometer_days_steps[PEDOMETER_DAYS_HISTORY] = {0,0,0,0,0,0,0};
        RTC_DATA_ATTR uint16_t pedometer_days_sleep[PEDOMETER_DAYS_HISTORY] = {0,0,0,0,0,0,0};
        // Steps in every hour
        RTC_DATA_ATTR uint16_t pedometer_hours_steps[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        // Sleep minutes in every hour
        RTC_DATA_ATTR uint8_t pedometer_hours_sleep[24] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(unsigned char day){ return pedometer_days_steps[day];}
        uint16_t get_pedometer_days_sleep(unsigned char day){ return pedometer_days_sleep[day];}
        uint16_t get_pedometer_hours_steps(unsigned char hour){ return pedometer_hours_steps[hour];}
        uint8_t get_pedometer_hours_sleep(unsigned char hour){ return pedometer_hours_sleep[hour];}
    #endif

    float get_pedometer_days_sleep_hours(unsigned char day){ return (((float)(((int)pedometer_days_sleep[day])*100/60))/100.0);}

    #ifdef PEDOMETER_EMULATOR
        float get_pedometer_days_sleep_hours(){ return 8*60 - 10;}
        uint16_t get_pedometer_days_sleep(){return 8*60 - 10;}
        PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(){ return 5500;}
    #else
        float get_pedometer_days_sleep_hours(){return get_pedometer_days_sleep_hours(0);}
        uint16_t get_pedometer_days_sleep(){return get_pedometer_days_sleep(0);}
        PEDOMETER_DAY_VALUE_TYPE get_pedometer_days_steps(){ return get_pedometer_days_steps(0);}
    #endif

    uint16_t get_pedometer_days_steps_min_limit(){return pedometer_days_steps_min_limit;}
    uint16_t get_pedometer_days_sleep_min_limit(){return pedometer_days_sleep_min_limit;} //in minutes
    float get_pedometer_days_sleep_hours_limit(){return (((float)(((int)get_pedometer_days_sleep_min_limit())*100/60))/100.0);} //in hours

    void set_pedometer_hours_steps(unsigned char hour, uint16_t steps){ pedometer_hours_steps[hour] = steps;}
    void set_pedometer_hours_sleep(unsigned char hour, uint8_t sleep_minutes){ pedometer_hours_sleep[hour] = sleep_minutes;}
    void set_pedometer_days_steps_min_limit(uint16_t limit){pedometer_days_steps_min_limit = limit;}
    void set_pedometer_days_sleep_min_limit(uint16_t limit){pedometer_days_sleep_min_limit = limit;} //in minutes
    void set_pedometer_days_steps(unsigned char day, PEDOMETER_DAY_VALUE_TYPE steps){pedometer_days_steps[day] = steps;}
    void set_pedometer_days_sleep(unsigned char day, uint16_t sleep){pedometer_days_sleep[day] = sleep;}
    void set_pedometer_days_sleep(uint16_t sleep){set_pedometer_days_sleep(0, sleep);}
    void set_pedometer_days_steps(uint16_t steps){set_pedometer_days_steps(0, steps);}

    RTC_DATA_ATTR uint32_t pedometr_mesurings_in_a_day = 0;

    long getPedometr_mesurings_in_a_day(){
        return pedometr_mesurings_in_a_day;
    }


    void core_pedometer_newDate(){
        for(unsigned char i=PEDOMETER_DAYS_HISTORY-1; i>0; i--){
            pedometer_days_steps[i] = pedometer_days_steps[i-1];
            pedometer_days_sleep[i] = pedometer_days_sleep[i-1];
        }
        //debug("new date");
        set_pedometer_days_steps(0, 0);
        set_pedometer_days_sleep(0, 0);
        //get_pedometer_hours_sleep = 0;

        for(unsigned char i=0; i<24; i++){
            pedometer_hours_steps[i] = 0;
            pedometer_hours_sleep[i] = 0;
        }

        pedometr_mesurings_in_a_day = 0;
        
    }

    #ifndef pedometer_days_steps_IN_SEC
        #define pedometer_days_steps_IN_SEC                          1.68f
    #endif

    #define CORE_PEDOMETER_MESURE_EVERY_MS                      (PEDOMETER_STEP_DETECTION_PERIOD_MS/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD)

    RTC_DATA_ATTR bool core_pedometer_on = PEDOMETER_ENABLE_ON_START;
    void core_pedometer_setEnable(bool enable){core_pedometer_on = enable;}
    bool core_pedometer_getEnable(){return core_pedometer_on;}
    String core_pedometer_getEnable_String(){return (core_pedometer_on?"On":"Off");}

    int     core_pedometer_current_step_detection = -1;
    bool    core_pedometer_current_get_isNotInMesure(){
        core_pedometer_current_step_detection==-1;
    };
    float   core_pedometer_step_detection_arrays[PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD];
    long    core_pedometer_step_detection_start_time = 0;
    RTC_DATA_ATTR long    lastTimeWalkingDetection = 0;

    void core_pedometer_setup(){
        // Just for test M5StickC
        #ifdef DEBUG_PEDOMETER
            //pinMode(10, OUTPUT);
            //digitalWrite(10, 1);
        #endif
    }

    #ifdef PEDOMETER_ENABLE
        void core_pedometer_loop(bool inBackGroung){
            #ifdef DEBUG_PEDOMETER
                //debug("Core pedometer loop");
            #endif 
            #ifdef PEDOMETER_DO_NOT_USER_PEDOMETER_WHILE_CONNECTED_TO_USB
                #ifdef BATTERY_ENABLE
                    #ifndef DEBUG_PEDOMETER
                        if(driver_battery_isUsbConnected() || !core_pedometer_getEnable()){
                            #ifdef DEBUG_PEDOMETER
                                debug("DEBUG_PEDOMETER: exit job course on usb");
                            #endif 
                            analyse_sleep_delta_accels=0;
                            return;
                        }
                    #else
                        #ifdef DEBUG_PEDOMETER
                            if(driver_battery_isUsbConnected()){
                                //debug("DEBUG_PEDOMETER: usb is connected");
                            }
                        #endif 
                    #endif
                #endif
            #endif

            if(core_pedometer_on){
                #ifdef DEBUG_PEDOMETER
                    //debug("Pedometer is ON!");
                #endif 

                if(core_pedometer_current_step_detection!=-1){
                    #ifdef DEBUG_PEDOMETER
                        //debug("Pedometer - Not first mesure!");
                    #endif
                    core_pedometer_mesure_loop(inBackGroung);
                }else{
                    driver_accelerometer_wakeup();
                    #ifdef DEBUG_PEDOMETER 
                        //debug("Pedometer - check time!", 10);
                    #endif
                    
                    if(getCurrentSystemTime()<lastTimeWalkingDetection) lastTimeWalkingDetection = getCurrentSystemTime();

                    if( (inBackGroung && (lastTimeWalkingDetection + corePedometer_currentsleep_between_mesures<=getCurrentSystemTime()))
                        || ( !inBackGroung && millis() - core_pedometer_step_detection_start_time>=(((long)corePedometer_currentsleep_between_mesures)*1000) )
                    ){
                        if(inBackGroung){
                            #ifdef ACCELEROMETER_ENABLE
                                driver_accelerometer_setup();
                                #ifdef DEBUG_PEDOMETER
                                    debug("DEBUG_PEDOMETER: Accelerometer is setted up " + String(millis()), 10);
                                #endif
                            #endif
                        }

                        #ifdef DEBUG_PEDOMETER
                            debug("DEBUG_PEDOMETER: Pedometer - Start step!", 10);
                        #endif
                        #ifdef PEDOMETER_ENABLE
                            core_pedometer_start_step_detection(inBackGroung);
                            core_pedometer_mesure_loop(inBackGroung);
                        #endif
                    }else{
                        #ifdef DEBUG_PEDOMETER
                            //debug("!!!!! Time is not come", 10);
                        #endif
                    }
                }
            }else{
                #ifdef DEBUG_PEDOMETER
                    debug("Pedometer is OFF!", 10);
                #endif 
            }
        }
    #endif

    #ifdef PEDOMETER_ENABLE
        void core_pedometer_mesure_loop(){ core_pedometer_mesure_loop(true); }
        void core_pedometer_mesure_loop(bool inBackGroung){
            if(core_pedometer_current_step_detection!=-1){

                if(
                    (inBackGroung) || 
                    ( (millis()-core_pedometer_step_detection_start_time)/CORE_PEDOMETER_MESURE_EVERY_MS >= core_pedometer_current_step_detection ) 
                    ){ // Mesure condition

                    #ifdef DEBUG_PEDOMETER
                        debug("DEBUG_PEDOMETER: Mesure " + String( core_pedometer_current_step_detection));
                    #endif

                    driver_accelerometer_update_accelerometer();
                    core_pedometer_step_detection_arrays[core_pedometer_current_step_detection] = driver_accelerometer_get_accel_total();

                    core_pedometer_current_step_detection++;

                    /*
                    if(
                        core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1]<0.2f ||
                        core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1]>1.8f
                    ){
                        core_pedometer_step_detection_arrays[core_pedometer_current_step_detection-1] = 1;
                        core_pedometer_current_step_detection--;
                    }*/

                    if(core_pedometer_current_step_detection==PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD){
                        core_pedometer_current_step_detection=-1;
                        driver_accelerometer_sleep();
                        core_pedometer_analyse_steps_mesure(inBackGroung);
                    }

                    //if(!inBackGroung) core_pedometer_current_step_detection++;
                }

                if(inBackGroung){
                    #ifdef DEBUG_PEDOMETER
                        // debug("PEDOMETER MESURE IN BACKGROUN", 10);
                    #endif
                    
                    #ifdef DEBUG_WAKEUP
                        debug("Mesure in BG "  + String(millis()), 10);
                    #endif

                    #ifdef PEDOMETER_ENABLE
                        core_cpu_sleep(SLEEP_LIGHT, CORE_PEDOMETER_MESURE_EVERY_MS, false); 
                        core_pedometer_mesure_loop(true);
                    #endif
                }
            }
            

        }

        void core_pedometer_start_step_detection(bool inBackGroung){
            pedometer_in_work = true;
            core_pedometer_current_step_detection = 0;
            for(int i=0; i<PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD; i++){
                core_pedometer_step_detection_arrays[i] = 0.0f;
            }
            core_pedometer_step_detection_start_time = millis();
        }
    #endif

    #ifdef DEBUG_PEDOMETER
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

    unsigned char get_corePedometer_currentsleep_between_mesures(){
        return corePedometer_currentsleep_between_mesures;
    }
    #define ABS(x) ((x)>0?(x):-(x))

    bool core_pedometer_analyse_steps_mesure(bool inBackground){

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        pedometr_mesurings_in_a_day++;

        #ifdef DEBUG_PEDOMETER
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

        #ifdef DEBUG_PEDOMETER
            debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
            //debug( String("max_value: ") + analysis_max_value);
            //debug( String("min_value: ") + analysis_min_value);
            debug( String("delta_value: ") + analysis_delta_value);
            //debug( String("axis_crossings: ") + analysis_axis_crossings);
            //debug( String("central_value: ") + analysis_central_value);
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
                #ifdef DEBUG_PEDOMETER
                    debug("Is walking", 20);
                    //if(!inBackground) digitalWrite(10,0);
                #endif
                unsigned char hours_to_add = (PEDOMETER_DAY_VALUE_TYPE)((pedometer_days_steps_IN_SEC*( (float)( ((long)corePedometer_currentsleep_between_mesures)*1000 + PEDOMETER_STEP_DETECTION_PERIOD_MS)))/1000);
                pedometer_hours_steps[core_time_getHours_byte()] += hours_to_add;
                pedometer_days_steps[0] += hours_to_add;

                // reset sleep counting
                analyse_sleep_delta_accels = 0;
                corePedometer_currentsleep_between_mesures = PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN;
            }else{
                corePedometer_currentsleep_between_mesures += PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP;
                unsigned char between_mesure_realy_delay = (corePedometer_currentsleep_between_mesures + PEDOMETER_STEP_DETECTION_PERIOD_MS/1000);

                if((between_mesure_realy_delay)>=60){
                    corePedometer_currentsleep_between_mesures += 60;
                    between_mesure_realy_delay += 60;
                }
                
                if((between_mesure_realy_delay)>=60){
                    corePedometer_currentsleep_between_mesures = corePedometer_currentsleep_between_mesures - (between_mesure_realy_delay)%60;
                }

                if(between_mesure_realy_delay>PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX){
                    corePedometer_currentsleep_between_mesures = PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000;
                }

                #ifdef DEBUG_PEDOMETER
                    debug("DEBUG_PEDOMETER: Is not walking", 10);    
                #endif

                unsigned char analysis_delta_value_byte = (unsigned char)(analysis_delta_value*100.0);

                if(analysis_delta_value_byte<=COREPEDOMETER_DELTA_SLEEP_VALUE_MIN_100 && analysis_central_weight_value<=COREPEDOMETER_CENTRALWIGHT_SLEEP_VALUE_MIN){
                    #ifdef DEBUG_PEDOMETER
                        debug("DEBUG_PEDOMETER: Sleeping analyse - " + String(analyse_sleep_delta_accels));
                    #endif
                    
                    if(analyse_sleep_delta_accels>=CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS){
                        #ifdef DEBUG_PEDOMETER
                            debug("IS SLEEPING");
                        #endif

                        between_mesure_realy_delay = (corePedometer_currentsleep_between_mesures + PEDOMETER_STEP_DETECTION_PERIOD_MS/1000);
                        #ifdef SLEEP_VALUE_DEBUG
                            unsigned char sleep_minutes_to_add = 1;
                        #else    
                            unsigned char sleep_minutes_to_add = (between_mesure_realy_delay+1)/60;
                        #endif
                        
                        #ifdef DEBUG_PEDOMETER_TIMING
                        
                            debug("corePedometer_currentsleep_between_mesures " + String(corePedometer_currentsleep_between_mesures));
                            debug("sleep_minutes_to_add " + String(sleep_minutes_to_add));
                            debug("between_mesure_realy_delay " + String(between_mesure_realy_delay));
                        #endif

                        #ifdef DEBUG_PEDOMETER
                            debug("sleep_minutes_to_add " + String(sleep_minutes_to_add));
                        #endif
                        pedometer_hours_sleep[core_time_getHours_byte()] += sleep_minutes_to_add;
                        pedometer_days_sleep[0] += sleep_minutes_to_add;

                    }else{
                        analyse_sleep_delta_accels++;
                    }
                }else{
                    // reset sleep counting
                    analyse_sleep_delta_accels = 0;
                }

                
                
            }

        core_pedometer_step_detection_start_time = millis();
        lastTimeWalkingDetection = getCurrentSystemTime();

        //core_pedometer_current_step_detection = -1;
        pedometer_in_work = false;
        return true;
    }


#endif