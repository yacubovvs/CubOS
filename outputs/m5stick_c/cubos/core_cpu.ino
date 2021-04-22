long core_cpu_getCpuSleepTimeDelay(){
    #ifdef CPU_SLEEP_ENABLE
        return 25000;
    #else
        return 0;
    #endif
}
