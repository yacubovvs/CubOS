#include <M5EPD.h>

//RTC_TimeTypeDef RTC_TimeStruct;
//RTC_DateTypeDef RTC_DateStruct;
rtc_time_t RTC_TimeStruct;
rtc_date_t RTC_DateStruct;

void driver_RTC_setup(){
	//M5.begin();
	M5.RTC.begin();
}

void driver_RTC_refresh(bool hard){
	M5.RTC.getTime(&RTC_TimeStruct);
	M5.RTC.getDate(&RTC_DateStruct);
	driver_RTC_lastTimeRefresh = millis();
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

unsigned char driver_RTC_getMinutes(){
	return RTC_TimeStruct.min;
}

void driver_RTC_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	RTC_TimeStruct.min = minutes;
	M5.RTC.setTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getSeconds(){
	return RTC_TimeStruct.sec;
}

void driver_RTC_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	RTC_TimeStruct.sec = seconds;
	M5.RTC.setTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getHours(){
	return RTC_TimeStruct.hour;
}

void driver_RTC_setHours(unsigned char hours){
	hours = hours%24;
	RTC_TimeStruct.hour = hours;
	M5.RTC.setTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getTemperature(){
	return 0;
}

unsigned char driver_RTC_getWeekDay(){
	return RTC_DateStruct.week;
}

void driver_RTC_setWeekDay(unsigned char weekDay){
	weekDay = weekDay%7;
	RTC_DateStruct.week = weekDay;
	M5.RTC.setDate(&RTC_DateStruct);
}

unsigned char driver_RTC_getDate(){
	return RTC_DateStruct.day;
}

void driver_RTC_setDate(unsigned char date){
	date = date%31;
	RTC_DateStruct.day = date;
	M5.RTC.setDate(&RTC_DateStruct);
}

unsigned char driver_RTC_getMonth(){
	return RTC_DateStruct.mon;
}

void driver_RTC_setMonth(unsigned char month){
	month = month%12;
	RTC_DateStruct.mon = month;
	M5.RTC.setDate(&RTC_DateStruct);
}

uint16_t driver_RTC_getYear(){
	return RTC_DateStruct.year;
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
	
	RTC_DateStruct.year = year;
	M5.RTC.setDate(&RTC_DateStruct);
}

void driver_RTC_setAlarmBySeconds(unsigned char seconds){

}