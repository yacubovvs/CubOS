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

		//debug("RTC updating");
	}
	
}

void driver_RTC_refresh(){
	driver_RTC_refresh(false);
}

unsigned char driver_RTC_getMinutes(){
	return RTC_TimeStruct.Minutes;
}

unsigned char driver_RTC_getSeconds(){
	return RTC_TimeStruct.Seconds;
}

unsigned char driver_RTC_getHours(){
	return RTC_TimeStruct.Hours;
}

unsigned char driver_RTC_getTemperature(){
	return 0;
}

unsigned char driver_RTC_getDate(){
	return RTC_DateStruct.Month;
}

unsigned char driver_RTC_getMonth(){
	return RTC_DateStruct.Month;
}

uint16_t driver_RTC_getYear(){
	return RTC_DateStruct.Month;
}

unsigned char driver_RTC_getWeekDay(){
	return RTC_DateStruct.WeekDay;
}
