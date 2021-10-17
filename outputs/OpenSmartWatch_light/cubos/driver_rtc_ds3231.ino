#include "Arduino.h"
#include "uRTCLib.h"

uRTCLib rtc;

void driver_RTC_setup(){

    URTCLIB_WIRE.begin();

	rtc.set_rtc_address(0x68);
	rtc.set_model(URTCLIB_MODEL_DS3231);
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

void driver_RTC_refresh(bool hard){
	rtc.refresh();
	driver_RTC_lastTimeRefresh = millis();
}

unsigned char driver_RTC_getMinutes(){
	return rtc.minute();
}

unsigned char driver_RTC_getSeconds(){
	return rtc.second();
}

unsigned char driver_RTC_getHours(){
	return rtc.hour();
}

unsigned char driver_RTC_getTemperature(){
	return rtc.temp();
}

unsigned char driver_RTC_getWeekDay(){
	return rtc.dayOfWeek();
}

unsigned char driver_RTC_getDate(){
	return rtc.day();
}

unsigned char driver_RTC_getMonth(){
	return rtc.month();
}

uint16_t driver_RTC_getYear(){
	return rtc.year();
}

/*
void driver_DS3231SN_start_1sec_wakeupTimer(){
    tft.setCursor(0, 3); 
    tft.println("Sleep for 1 sec");

    rtc.sqwgSetMode(URTCLIB_SQWG_1H);
	//rtc.sqwgSetMode(URTCLIB_SQWG_OFF_0);
}

void driver_DS3231SN_start_1min_wakeupTimer(){
    tft.setCursor(0, 3); 
    tft.println("Sleep for 1 min");

	rtc.alarmClearFlag(URTCLIB_ALARM_1);
	rtc.alarmSet(URTCLIB_ALARM_TYPE_1_FIXED_S, 20, 0, 0, 1); // Each minute, at just :20 seconds
    //rtc.sqwgSetMode(URTCLIB_SQWG_1H);
	//rtc.sqwgSetMode(URTCLIB_SQWG_OFF_0);
}

void driver_DS3231SN_stop_wakeupTimer(){
    tft.setCursor(0, 3); 
    tft.println("Waked up!        ");
	rtc.alarmClearFlag(URTCLIB_ALARM_1);
    rtc.sqwgSetMode(URTCLIB_SQWG_OFF_1);
	rtc.sqwgSetMode(URTCLIB_SQWG_OFF_1);
	//rtc.sqwgSetMode(URTCLIB_SQWG_32768H);
}

void driver_DS3231SN_printsomething(){
    tft.setCursor(0, 3); 
    tft.println("Waked up!        ");
}*/



void driver_RTC_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, minutes, -1, -1, -1, -1, -1);
}

void driver_RTC_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(seconds, -1, -1, -1, -1, -1, -1);
}

void driver_RTC_setHours(unsigned char hours){
	hours = hours%24;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, -1, hours, -1, -1, -1, -1);
}



void driver_RTC_setWeekDay(unsigned char weekDay){
	weekDay = weekDay%7;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, -1, -1, weekDay, -1, -1, -1);
}

void driver_RTC_setDate(unsigned char date){
	date = date%31;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, -1, -1, -1, date, -1, -1);
}

void driver_RTC_setMonth(unsigned char month){
	month = month%12;
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, -1, -1, -1, -1, month, -1);
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
	
	//driver_RTC_set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
	driver_RTC_set(-1, -1, -1, -1, -1, -1, year);
}

void driver_RTC_setAlarmBySeconds(unsigned char seconds){}

void driver_RTC_set(int second_value, int minute_value, int hour_value, int dayOfWeek_value, int dayOfMonth_value, int month_value, int year_value){
	driver_RTC_refresh(true);

	uint8_t second;
	uint8_t minute; 
	uint8_t hour; 
	uint8_t dayOfWeek; 
	uint8_t dayOfMonth; 
	uint8_t month; 
	uint8_t year;

	if(second_value==-1) second = driver_RTC_getSeconds();
	else second = second_value;

	if(minute_value==-1) minute = driver_RTC_getMinutes();
	else minute = minute_value;

	if(hour_value==-1) hour = driver_RTC_getHours();
	else hour = hour_value;

	if(dayOfWeek_value==-1) dayOfWeek = driver_RTC_getWeekDay();
	else dayOfWeek = dayOfWeek_value;

	if(dayOfMonth_value==-1) dayOfMonth = driver_RTC_getDate();
	else dayOfMonth = dayOfMonth_value;

	if(month_value==-1) month = driver_RTC_getMonth();
	else month = month_value;

	if(year_value==-1) year = driver_RTC_getYear();
	else year = year_value;

	rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
}