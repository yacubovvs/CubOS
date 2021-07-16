
unsigned char driver_rtc_emulator_hours 	= 18;
unsigned char driver_rtc_emulator_minutes 	= 23;
unsigned char driver_rtc_emulator_seconds 	= 48;
uint16_t driver_rtc_emulator_year			= 2021;
unsigned char driver_rtc_emulator_date		= 9;
unsigned char driver_rtc_emulator_month		= 6;
unsigned char driver_rtc_emulator_weekday 	= 5;

unsigned char driver_rtc_emulator_temperature;

void driver_RTC_setup(){}

void driver_RTC_refresh(bool hard){
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

unsigned char driver_RTC_getMinutes(){
	return driver_rtc_emulator_minutes;
}

void driver_RTC_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	driver_rtc_emulator_minutes = minutes;
}

unsigned char driver_RTC_getSeconds(){
	return driver_rtc_emulator_seconds;
}

void driver_RTC_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	driver_rtc_emulator_seconds = seconds;
}

unsigned char driver_RTC_getHours(){
	return driver_rtc_emulator_hours;
}

void driver_RTC_setHours(unsigned char hours){
	hours = hours%24;
	driver_rtc_emulator_hours = hours;
}

unsigned char driver_RTC_getTemperature(){
	return driver_rtc_emulator_temperature;
}

unsigned char driver_RTC_getWeekDay(){
	// TODO
	return driver_rtc_emulator_weekday;
}

void driver_RTC_setWeekDay(unsigned char weekDay){
	weekDay = weekDay%7;
	driver_rtc_emulator_weekday = weekDay;
	// TODO
}

unsigned char driver_RTC_getDate(){
	return driver_rtc_emulator_date;
}

void driver_RTC_setDate(unsigned char date){
	date = date%31;
	driver_rtc_emulator_date = date;
}

unsigned char driver_RTC_getMonth(){
	return driver_rtc_emulator_month;
}

void driver_RTC_setMonth(unsigned char month){
	month = month%12;
	driver_rtc_emulator_month = month;
}

uint16_t driver_RTC_getYear(){
	return driver_rtc_emulator_year;
}


void driver_RTC_setYear(int year){
	#ifndef RTC_MIN_YEAR
		#define RTC_MIN_YEAR 2020
	#endif
	#ifndef RTC_MAX_YEAR
		#define RTC_MAX_YEAR 2070
	#endif

	if(year<RTC_MIN_YEAR) year = RTC_MAX_YEAR;
	if(year>RTC_MAX_YEAR) year = RTC_MIN_YEAR;
	
	driver_rtc_emulator_year = year;
}

void driver_RTC_setAlarmBySeconds(unsigned char seconds){
	/*
	rtc.disableAlarm();
    rtc.setAlarmBySeconds((driver_RTC_getSeconds()+seconds)%60);
    rtc.enableAlarm();
	*/
}