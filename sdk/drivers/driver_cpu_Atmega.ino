
void driver_cpu_setup(){
}

void driver_cpu_loop(){
}

void driver_cpu_wakeup(){

}

void driver_cpu_poweroff(){}

void driver_cpu_sleep(unsigned char sleepType, long timeout_ms){
    
    switch (sleepType)
    {
        case SLEEP_IDLE_CPU:
            break;
        case SLEEP_DEEP:
            break;
        case SLEEP_LIGHT:
            break;
        case SLEEP_MODEM:
            break;
        case SLEEP_DISPLAY:
            break;
        case WAKE_MODEM:
            break;
        case WAKE_DISPLAY:
            break;
        case WAKE:
            break;
        default:
            break;
    }
}
