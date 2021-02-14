#include "Arduino.h"
#include "uRTCLib.h"

uRTCLib rtc;

void driver_RTC_setup(){

    URTCLIB_WIRE.begin();

	rtc.set_rtc_address(0x68);
	rtc.set_model(URTCLIB_MODEL_DS3231);

	// Only used once, then disabled
	//rtc.set(0, 42, 16, 6, 2, 5, 15);
	//  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)

    /*
	if (rtc.enableBattery()) {
		Serial.println("Battery activated correctly.");
	} else {
		Serial.println("ERROR activating battery.");
	}*/

    /*
	Serial.print("Lost power status: ");
	if (rtc.lostPower()) {
		Serial.print("POWER FAILED. Clearing flag...");
		rtc.lostPowerClear();
		Serial.println(" done.");
	} else {
		Serial.println("POWER OK");
	}


	Serial.print("Aging register value: ");
	Serial.println(rtc.agingGet());

	Serial.println("Not changing aging register value. To do so you can execute: rtc.agingSet(newValue)");

    */
}

void driver_RTC_refresh(){
	rtc.refresh();
}

byte driver_RTC_getMinutes(){
	return rtc.minute();
}

byte driver_RTC_getSeconds(){
	return rtc.second();
}

byte driver_RTC_getHours(){
	return rtc.hour();
}

byte driver_RTC_getTemperature(){
	return rtc.temp();
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