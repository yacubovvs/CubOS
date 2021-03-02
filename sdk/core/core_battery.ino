unsigned char core_batteryGetPercent(){
    #ifdef BATTERY_ENABLE
        return driver_battery_getPercent();
    #else
        return 0;
    #endif
}