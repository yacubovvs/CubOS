
void core_time_onNewDate(){ 
    // Calling once in a day
    // Clearing all counting data for a day
    #ifdef PEDOMETER_ENABLE
        core_pedometer_newDate();
    #endif

    if(currentAppSetted) currentApp->onEvent(EVENT_ON_DATE_CHANGED, 0, 0);
}

void core_time_onNewMinute(){
    //debug("EVENT_ON_MINUTE_CHANGED!", 10);
    if(currentAppSetted) currentApp->onEvent(EVENT_ON_MINUTE_CHANGED, 0, 0);
}

void core_time_onNewHour(){
    //debug("EVENT_ON_HOUR_CHANGED!", 10);
    if(currentAppSetted) currentApp->onEvent(EVENT_ON_HOUR_CHANGED, 0, 0);
}

long getCurrentSystemTime(){
    #ifdef RTC_ENABLE
        long currentSystemTime =  ((long)core_time_getHours_byte())*60*60 + ((long)core_time_getMinutes_byte())*60 + ((long)core_time_getSeconds_byte());
        return currentSystemTime;
    #else
        return millis()/1000;
    #endif
}

#ifdef RTC_ENABLE
    RTC_DATA_ATTR unsigned char lastDay = 0;
    RTC_DATA_ATTR unsigned char lastHour = 0;
    RTC_DATA_ATTR unsigned char lastMinute = 0;
    
    unsigned long driver_RTC_lastTimeRefresh = 0;
    
    void core_time_driver_RTC_refresh(bool hard){
        if(hard || (millis() - driver_RTC_lastTimeRefresh>=UPDATE_RTC_EVERY)){
            driver_RTC_refresh(hard);
            if(core_time_getDate()!=lastDay){
                core_time_onNewDate();
                lastDay = core_time_getDate();
            }

            if(core_time_getMinutes_byte()!=lastMinute){
                core_time_onNewMinute();
                lastMinute = core_time_getMinutes_byte();
            }

            if(core_time_getHours_byte()!=lastHour){
                core_time_onNewHour();
                lastHour = core_time_getHours_byte();
            }
        }
    }

    void core_time_driver_RTC_refresh(){
        core_time_driver_RTC_refresh(false);
    }
#endif

unsigned char core_time_getHours_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getHours();
    #else
        return millis()/(1000*60*60)%24;
    #endif
}

void core_time_setHours(unsigned char hours){
    #ifdef RTC_ENABLE
        driver_RTC_setHours(hours);
    #else
        // TODO
    #endif
}

unsigned char core_time_getMinutes_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getMinutes();
    #else
        return millis()/(1000*60)%60;
    #endif
}

void core_time_setMinutes(unsigned char minutes){
    #ifdef RTC_ENABLE
        driver_RTC_setMinutes(minutes);
    #else
        // TODO
    #endif
}

unsigned char core_time_getSeconds_byte(){
    #ifdef RTC_ENABLE
        return driver_RTC_getSeconds();
    #else
        return millis()/(1000)%60;
    #endif
}

void core_time_setSeconds(unsigned char seconds){
    #ifdef RTC_ENABLE
        driver_RTC_setSeconds(seconds);
    #else
        // TODO
    #endif
}

String core_time_getHours_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getHours_byte());
}

String core_time_getMinutes_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getMinutes_byte());
}

String core_time_getSeconds_String(){
    return core_basic_addLeadBullToInt2digits(core_time_getSeconds_byte());
}

String core_time_getHourMinuteSecondsTime(){
    #ifdef RTC_ENABLE
        core_time_driver_RTC_refresh();
    #endif
    return core_time_getHours_String() + ":" + core_time_getMinutes_String() + ":" + core_time_getSeconds_String();
}

String core_time_getHourMinuteTime(){
    #ifdef RTC_ENABLE
        core_time_driver_RTC_refresh();
    #endif
    return core_time_getHours_String() + ":" + core_time_getMinutes_String();
}

unsigned char core_time_getMonth(){
    //return "February";
    #ifdef RTC_ENABLE
        return driver_RTC_getMonth();
    #else
        return 1;
    #endif
}

String core_time_getMonth_string(){
    switch(core_time_getMonth()){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "-";
    }  
}

String core_time_getMonth_stringShort(){
    switch(core_time_getMonth()){
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sep";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
        default:
            return "-";
    }  
}

unsigned char core_time_getDate(){
    #ifdef RTC_ENABLE
        return driver_RTC_getDate();
    #else
        return 1;
    #endif
}

unsigned char core_time_getWeekDay(){
    #ifdef RTC_ENABLE
        return driver_RTC_getWeekDay();
    #else
        return 0;
    #endif
}

String core_time_getWeekDay_string(){
	switch (core_time_getWeekDay()){
		case 0:
			return "Monday";
		case 1:
			return "Tuesday";
		case 2:
			return "Wednesday";
		case 3:
			return "Thursday";
		case 4:
			return "Friday";
		case 5:
			return "Saturday";
		case 6:
			return "Sunday";
		default:
			return "-";
	}
}

String core_time_getWeekDay_stringShort(){
	switch (core_time_getWeekDay()){
		case 0:
			return "Mon";
		case 1:
			return "Tue";
		case 2:
			return "Wed";
		case 3:
			return "Thu";
		case 4:
			return "Fri";
		case 5:
			return "Sat";
		case 6:
			return "Sun";
		default:
			return "-";
	}
}

uint16_t core_time_getYear(){
    #ifdef RTC_ENABLE
        return driver_RTC_getYear();
    #else
        return 2021;
    #endif
}

String core_time_getDateFull(){
    return core_basic_addLeadBullToInt2digits(core_time_getDate()) + "." + core_basic_addLeadBullToInt2digits(core_time_getMonth()) + "." + String(core_time_getYear());
}

void core_time_setYear(uint16_t year){
    #ifdef RTC_ENABLE
        return driver_RTC_setYear(year);
    #else
        // TODO
    #endif
}

void core_time_setMonth(unsigned char month){
    #ifdef RTC_ENABLE
        return driver_RTC_setMonth(month);
    #else
        // TODO
    #endif
}

void core_time_setDate(unsigned char date){
    #ifdef RTC_ENABLE
        return driver_RTC_setDate(date);
    #else
        // TODO
    #endif
}

void core_time_setWeekDay(unsigned char weekDay){
    #ifdef RTC_ENABLE
        return driver_RTC_setWeekDay(weekDay);
    #else
        // TODO
    #endif
}


//#define EVENT_ON_TIME_CHANGED              0x03
long lastTimeChange = millis()/ON_TIME_CHANGE_EVERY_MS;
void core_time_loop(){
    long currentTime = millis()/ON_TIME_CHANGE_EVERY_MS;
    if(currentTime!=lastTimeChange){
        #ifdef CLOCK_ENABLE
            if(currentApp->showStatusBar==true){
                core_views_statusBar_draw_time(false);
                core_views_statusBar_draw_time(true);
            }
        #endif
        #ifdef RTC_ENABLE
            core_time_driver_RTC_refresh();
        #endif
        currentApp->onEvent(EVENT_ON_TIME_CHANGED, currentTime, 0);
        lastTimeChange = currentTime;
    }
}

void core_time_setAlarmBySeconds(unsigned char seconds){
    #ifdef RTC_ENABLE
        driver_RTC_setAlarmBySeconds(seconds);
    #endif
}