// Add TFT_eSPI library to Arduino IDE from:
// <CUBOS DIRECTORY>/external_libs/PCF8563_Library/
#include <pcf8563.h>

PCF8563_Class rtc;

RTC_DATA_ATTR unsigned char driver_rtc_weekDay_shift = 0;
RTC_Date driver_rtc_dateTime;

void driver_RTC_setup(){
	Wire.begin(21, 22);
	rtc.begin();
	driver_RTC_refresh(true);
}

void driver_RTC_refresh(bool hard){
	driver_rtc_dateTime = rtc.getDateTime();
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

unsigned char driver_RTC_getMinutes(){
	return driver_rtc_dateTime.minute;
}

void driver_RTC_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	driver_rtc_dateTime.minute = minutes;
	rtc.setDateTime(driver_rtc_dateTime);
}

unsigned char driver_RTC_getSeconds(){
	return driver_rtc_dateTime.second;
}

void driver_RTC_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	driver_rtc_dateTime.second = seconds;
	rtc.setDateTime(driver_rtc_dateTime);
}

unsigned char driver_RTC_getHours(){
	return driver_rtc_dateTime.hour;
}

void driver_RTC_setHours(unsigned char hours){
	hours = hours%24;
	driver_rtc_dateTime.hour = hours;
	rtc.setDateTime(driver_rtc_dateTime);
}

unsigned char driver_RTC_getTemperature(){
	return 0;
}

unsigned char driver_RTC_getWeekDay(){
	// TODO
	unsigned char day = rtc.getDayOfWeek(driver_rtc_dateTime.day, driver_rtc_dateTime.month, driver_rtc_dateTime.year);
	day = (day-1+7 + driver_rtc_weekDay_shift)%7;
	return day;
}

void driver_RTC_setWeekDay(unsigned char weekDay){
	//weekDay = weekDay%7;
	driver_rtc_weekDay_shift ++;
	driver_rtc_weekDay_shift = driver_rtc_weekDay_shift%7;
	// TODO
}

unsigned char driver_RTC_getDate(){
	return driver_rtc_dateTime.day;
}

void driver_RTC_setDate(unsigned char date){
	date = date%31;
	driver_rtc_dateTime.day = date;
	rtc.setDateTime(driver_rtc_dateTime);
}

unsigned char driver_RTC_getMonth(){
	return driver_rtc_dateTime.month;
}

void driver_RTC_setMonth(unsigned char month){
	month = month%12;

	driver_rtc_dateTime.month = month;
	rtc.setDateTime(driver_rtc_dateTime);
}

uint16_t driver_RTC_getYear(){
	return driver_rtc_dateTime.year;
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
	
	driver_rtc_dateTime.year = year;
	rtc.setDateTime(driver_rtc_dateTime);
}

void driver_RTC_setAlarmBySeconds(unsigned char seconds){
	/*
	rtc.disableAlarm();
    rtc.setAlarmBySeconds((driver_RTC_getSeconds()+seconds)%60);
    rtc.enableAlarm();
	*/
}