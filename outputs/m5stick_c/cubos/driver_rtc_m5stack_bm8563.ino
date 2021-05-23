#include <M5StickC.h>
RTC_TimeTypeDef RTC_TimeStruct;
RTC_DateTypeDef RTC_DateStruct;

unsigned long driver_RTC_lastTimeRefresh = 0;

void driver_RTC_setup(){
}

void driver_RTC_refresh(bool hard){
	if(hard) driver_RTC_lastTimeRefresh = 0;

	if(millis() - driver_RTC_lastTimeRefresh>=UPDATE_RTC_EVERY){
		M5.Rtc.GetTime(&RTC_TimeStruct);
		M5.Rtc.GetData(&RTC_DateStruct);
		driver_RTC_lastTimeRefresh = millis();
	}
	
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

unsigned char driver_RTC_getMinutes(){
	return RTC_TimeStruct.Minutes;
}

void driver_RTC_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	RTC_TimeStruct.Minutes = minutes;
	M5.Rtc.SetTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getSeconds(){
	return RTC_TimeStruct.Seconds;
}

void driver_RTC_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	RTC_TimeStruct.Seconds = seconds;
	M5.Rtc.SetTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getHours(){
	return RTC_TimeStruct.Hours;
}

void driver_RTC_setHours(unsigned char hours){
	hours = hours%24;
	RTC_TimeStruct.Hours = hours;
	M5.Rtc.SetTime(&RTC_TimeStruct);
}

unsigned char driver_RTC_getTemperature(){
	return 0;
}

unsigned char driver_RTC_getWeekDay(){
	return RTC_DateStruct.WeekDay;
}

void driver_RTC_setWeekDay(unsigned char weekDay){
	weekDay = weekDay%7;
	RTC_DateStruct.WeekDay = weekDay;
	M5.Rtc.SetData(&RTC_DateStruct);
}

unsigned char driver_RTC_getDate(){
	return RTC_DateStruct.Date;
}

void driver_RTC_setDate(unsigned char date){
	date = date%31;
	RTC_DateStruct.Date = date;
	M5.Rtc.SetData(&RTC_DateStruct);
}

unsigned char driver_RTC_getMonth(){
	return RTC_DateStruct.Month;
}

void driver_RTC_setMonth(unsigned char month){
	month = month%12;
	RTC_DateStruct.Month = month;
	M5.Rtc.SetData(&RTC_DateStruct);
}

uint16_t driver_RTC_getYear(){
	return RTC_DateStruct.Year;
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
	
	RTC_DateStruct.Year = year;
	M5.Rtc.SetData(&RTC_DateStruct);
}

void driver_RTC_setAlarmBySeconds(unsigned char seconds){

}