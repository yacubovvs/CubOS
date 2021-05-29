#define PEDOMETER_ENABLE // just for tests

#ifdef PEDOMETER_ENABLE
    #ifndef PEDOMETER_STEP_DETECTION_EVERY_MS
        #define PEDOMETER_STEP_DETECTION_DELAY                  10000
    #endif

    #ifndef PEDOMETER_STEP_DETECTION_PERIOD_MS
        #define PEDOMETER_STEP_DETECTION_PERIOD_MS              2000
    #endif

    #ifndef PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD
        #define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      12
    #endif

    #define CORE_PEDOMETER_MESURE_EVERY_MS                      (PEDOMETER_STEP_DETECTION_PERIOD_MS/PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD)

    int    core_pedometer_current_step_detection = -1;
    float   core_pedometer_step_detection_arrays[PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD];
    long    core_pedometer_step_detection_start_time = 0;

    void core_pedometer_setup(){
        // Just for test M5StickC
        pinMode(10, OUTPUT);
        digitalWrite(10, 1);
    }

    void core_pedometer_loop(){
        if(core_pedometer_current_step_detection!=-1){
            core_pedometer_mesure_loop();
        }else{
            if(millis() - core_pedometer_step_detection_start_time>=PEDOMETER_STEP_DETECTION_DELAY){
                core_pedometer_start_step_detection();
            }
        }
        
    }

    void core_pedometer_mesure_loop(){ core_pedometer_mesure_loop(true); }
    void core_pedometer_mesure_loop(bool timer_by__millis){
        if(core_pedometer_current_step_detection!=-1){

            if(
                (!timer_by__millis) || 
                ( (millis()-core_pedometer_step_detection_start_time)/CORE_PEDOMETER_MESURE_EVERY_MS >= core_pedometer_current_step_detection ) 
                ){ // Mesure condition

                debug("Mesure " + String( core_pedometer_current_step_detection));

                driver_accelerometer_update_accelerometer();
                core_pedometer_step_detection_arrays[core_pedometer_current_step_detection] = driver_accelerometer_get_accel_total();
                core_pedometer_current_step_detection++;
                if(core_pedometer_current_step_detection==PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD){
                    core_pedometer_current_step_detection=-1;
                    core_pedometer_analyse_steps_mesure();
                }
            }
        }
    }

    void core_pedometer_start_step_detection(){
        core_pedometer_current_step_detection = 0;
        for(int i=0; i<PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD; i++){
            core_pedometer_step_detection_arrays[i] = 0.0f;
        }
        core_pedometer_step_detection_start_time = millis();
    }

    bool core_pedometer_analyse_steps_mesure(){
        debug("Steps analyse");
        return true;
    }


#endif