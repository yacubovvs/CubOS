String core_time_getHourMinuteTime(){
    #ifdef USE_RTC
        return "10:28";
    #else
        return "10:28";
    #endif
}

String core_time_getHourMinuteSecondsTime(){
    #ifdef USE_RTC
        driver_RTC_refresh();
    #endif
    return core_time_getHours_String() + ":" + core_time_getMinutes_String() + ":" + core_time_getSeconds_String();
}

String core_time_byteToTimeStringWithLeaderNull(byte byteIn){
    if(byteIn<10){
        return "0" + String(byteIn);
    }else{
        return String(byteIn);
    }
}

String core_time_getHours_String(){
    return core_time_byteToTimeStringWithLeaderNull(core_time_getHours_byte());
}

String core_time_getMinutes_String(){
    return core_time_byteToTimeStringWithLeaderNull(core_time_getMinutes_byte());
}

String core_time_getSeconds_String(){
    return core_time_byteToTimeStringWithLeaderNull(core_time_getSeconds_byte());
}

byte core_time_getHours_byte(){
    #ifdef USE_RTC
        return driver_RTC_getHours();
    #else
        return millis()/(1000*60*60)%24;
    #endif
}

byte core_time_getMinutes_byte(){
    #ifdef USE_RTC
        return driver_RTC_getMinutes();
    #else
        return millis()/(1000*60)%60;
    #endif
}


byte core_time_getSeconds_byte(){
    #ifdef USE_RTC
        return driver_RTC_getSeconds();
    #else
        return millis()/(1000)%60;
    #endif
}

//#define EVENT_ON_TIME_CHANGED              0x03
long lastTimeChange = millis()/ON_TIME_CHANGE_EVERY_MS;
void core_time_loop(){
    long currentTime = millis()/ON_TIME_CHANGE_EVERY_MS;
    if(currentTime!=lastTimeChange){
        currentApp->onEvent(EVENT_ON_TIME_CHANGED, currentTime, 0);
        lastTimeChange = currentTime;
    }
}