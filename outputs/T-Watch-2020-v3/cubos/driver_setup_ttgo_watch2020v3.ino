// MAIN DEVICE DRIVER
#define LILYGO_WATCH_2020_V3 
#include <LilyGoWatch.h>

TTGOClass *ttgo;
AXP20X_Class *ttgo_power;
PCF8563_Class *rtc;

/*
PCF8563_Class * driver_setup_getRTC(){
    return ttgo->rtc;
}*/

/*
    ############################################################################################
    #                                                                                          #
    #                                           POWER                                          #
    #                                                                                          #
    ############################################################################################
*/

bool core_driver_isCharging         = true; 
bool core_driver_VBUSConnected      = true;
bool core_driver_isLongPressed      = false;
bool core_driver_isShortPressed     = false;
bool core_driver_irq                = false;

bool get_core_driver_isCharging(){return core_driver_isCharging;}
bool get_core_driver_VBUSConnected(){return core_driver_VBUSConnected;}
float get_core_driver_getVbusVoltage(){return ttgo_power->getVbusVoltage();}
float get_core_driver_getVbusCurrent(){return ttgo_power->getVbusCurrent();}
float get_core_driver_getBattChargeCurrent(){return ttgo_power->getBattChargeCurrent();}
float get_core_driver_getBattDischargeCurrent(){return ttgo_power->getBattDischargeCurrent();}
float get_core_driver_getBattPercentage(){return ttgo_power->getBattPercentage();}
float get_core_driver_getBattVoltage(){return ttgo_power->getBattVoltage();}
bool get_core_driver_isBatteryConnect(){return ttgo_power->isBatteryConnect();}

/*
ttgo_power->getVbusVoltage());
ttgo_power->getVbusCurrent();
ttgo_power->getBattChargeCurrent();
ttgo_power->getBattDischargeCurrent();
ttgo_power->getBattPercentage()
ttgo_power->getBattVoltage()
ttgo_power->isBatteryConnect()
*/

void core_setup_driver(){
    ttgo = TTGOClass::getWatch();
    ttgo->begin();

    ttgo_power = ttgo->power;
    ttgo_power->setChargeControlCur(300);

    rtc = ttgo->rtc;

    ttgo_power->adc1Enable(
        AXP202_VBUS_VOL_ADC1 |
        AXP202_VBUS_CUR_ADC1 |
        AXP202_BATT_CUR_ADC1 |
        AXP202_BATT_VOL_ADC1,
        true);

    pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(AXP202_INT, [] {
        core_driver_irq = true;
    }, FALLING);

    //!Clear IRQ unprocessed  first
    ttgo_power->enableIRQ(AXP202_PEK_LONGPRESS_IRQ | AXP202_PEK_SHORTPRESS_IRQ | AXP202_VBUS_REMOVED_IRQ | AXP202_VBUS_CONNECT_IRQ | AXP202_CHARGING_IRQ, true);
    //ttgo_power->enableIRQ(AXP202_PEK_LONGPRESS_IRQ | AXP202_PEK_SHORTPRESS_IRQ, true);
    //ttgo_power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ | AXP202_VBUS_REMOVED_IRQ | AXP202_VBUS_CONNECT_IRQ | AXP202_CHARGING_IRQ, true);
    ttgo_power->clearIRQ();

    core_driver_VBUSConnected = ttgo_power->isVBUSPlug();
    core_driver_isCharging = ttgo_power->getBattChargeCurrent()>0;

}

void core_loop_irq_check(){
    if(core_driver_irq){
        core_driver_irq = false;
        ttgo_power->readIRQ(); 

        if (ttgo_power->isVbusPlugInIRQ()){
            core_driver_isCharging=true; 
            core_driver_VBUSConnected=true;
        }
        if (ttgo_power->isVbusRemoveIRQ()){
            core_driver_isCharging=false; 
            core_driver_VBUSConnected=false;
        }
        if (ttgo_power->isPEKShortPressIRQ()){
            core_driver_isShortPressed = true;
            set_core_powersave_lastUserAction();
        }
        if (ttgo_power->isChargingDoneIRQ()){
            core_driver_isCharging=false; 
            core_driver_VBUSConnected=true;
        }
        if (ttgo_power->isPEKLongtPressIRQ()){
            core_driver_isLongPressed = true;
        }
        
        ttgo_power->clearIRQ();
    }
}

void core_loop_driver(){
    core_loop_irq_check();
}

/*
    ############################################################################################
    #                                                                                          #
    #                                        POWER BUTTON                                      #
    #                                                                                          #
    ############################################################################################
*/

bool get_core_driver_isShortPressed(){
    if(core_driver_isShortPressed==true){
        core_driver_isShortPressed = false;
        return true;
    }else{
        return false;
    }
}

bool get_core_driver_isLongPressed(){
    if(core_driver_isLongPressed){
        core_driver_isLongPressed = false;
        return true;
    }else{
        return false;
    }
}


//SCREEN FUNCTIONS

/*
    ############################################################################################
    #                                                                                          #
    #                                          DISPLAY                                         #
    #                                                                                          #
    ############################################################################################
*/

void core_driver_openBL(){
    ttgo->openBL();
}

void core_driver_closeBL(){
    ttgo->closeBL();
}

void core_driver_fillScreen(uint16_t fillColor){
    ttgo->tft->fillScreen(fillColor);
}

void core_driver_drawPixel(int x, int y, uint16_t color){
    ttgo->tft->drawPixel(x, y, color);
}

void core_driver_setBrigtness(unsigned char brightness){
    ttgo->setBrightness(brightness); // 0..255
}

 
//SCREEN FUNCTIONS

/*
    ############################################################################################
    #                                                                                          #
    #                                            RTC                                           #
    #                                                                                          #
    ############################################################################################
*/

RTC_Date core_driver_setup_rtc_dateTime;

void core_driver_setup_rtc_disableAlarm(){
    ttgo->rtc->disableAlarm();
}
void core_driver_setup_rtc_setDateTime(int year, unsigned char month, unsigned char day, unsigned char hour, unsigned char minute, unsigned char second){
    ttgo->rtc->setDateTime(year, month, day, hour, minute, second);
}
void core_driver_setup_rtc_setAlarmByMinutes(int minutes){
    ttgo->rtc->setAlarmByMinutes(minutes);
}

void core_driver_setup_rtc_enableAlarm(){
    ttgo->rtc->enableAlarm();
}

/*

const char *formatDateTime(uint8_t style = PCF_TIMEFORMAT_HMS);
uint32_t getDayOfWeek(uint32_t day, uint32_t month, uint32_t year);
*/

unsigned char core_driver_setup_rtc_weekDay_shift = 0;

void core_driver_setup__setup(){
	driver_RTC_refresh(true);
}

void core_driver_setup__refresh(bool hard){
	core_driver_setup_rtc_dateTime = ttgo->rtc->getDateTime();
}

void core_driver_setup_rtc_setup(){
	//Wire.begin(21, 22);
	//ttgo->rtc->begin();
	core_driver_setup_rtc_refresh(true);
}

void core_driver_setup_rtc_refresh(bool hard){
	core_driver_setup_rtc_dateTime = ttgo->rtc->getDateTime();
}

void core_driver_setup_rtc_refresh(){
	core_driver_setup_rtc_refresh(false);
}

unsigned char core_driver_setup_rtc_getMinutes(){
	return core_driver_setup_rtc_dateTime.minute;
}

void core_driver_setup_rtc_setMinutes(unsigned char minutes){
	minutes = minutes%60;
	core_driver_setup_rtc_dateTime.minute = minutes;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

unsigned char core_driver_setup_rtc_getSeconds(){
	return core_driver_setup_rtc_dateTime.second;
}

void core_driver_setup_rtc_setSeconds(unsigned char seconds){
	seconds = seconds%60;
	core_driver_setup_rtc_dateTime.second = seconds;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

unsigned char core_driver_setup_rtc_getHours(){
	return core_driver_setup_rtc_dateTime.hour;
}

void core_driver_setup_rtc_setHours(unsigned char hours){
	hours = hours%24;
	core_driver_setup_rtc_dateTime.hour = hours;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

unsigned char core_driver_setup_rtc_getTemperature(){
	return 0;
}

unsigned char core_driver_setup_rtc_getWeekDay(){
	// TODO
	unsigned char day = ttgo->rtc->getDayOfWeek(core_driver_setup_rtc_dateTime.day, core_driver_setup_rtc_dateTime.month, core_driver_setup_rtc_dateTime.year);
	day = (day-1+7 + core_driver_setup_rtc_weekDay_shift)%7;
	return day;
}

void core_driver_setup_rtc_setWeekDay(unsigned char weekDay){
	//weekDay = weekDay%7;
	core_driver_setup_rtc_weekDay_shift ++;
	core_driver_setup_rtc_weekDay_shift = core_driver_setup_rtc_weekDay_shift%7;
	// TODO
}

unsigned char core_driver_setup_rtc_getDate(){
	return core_driver_setup_rtc_dateTime.day;
}

void core_driver_setup_rtc_setDate(unsigned char date){
	date = date%31;
	core_driver_setup_rtc_dateTime.day = date;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

unsigned char core_driver_setup_rtc_getMonth(){
	return core_driver_setup_rtc_dateTime.month;
}

void core_driver_setup_rtc_setMonth(unsigned char month){
	month = month%12;

	core_driver_setup_rtc_dateTime.month = month;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

uint16_t core_driver_setup_rtc_getYear(){
	return core_driver_setup_rtc_dateTime.year;
}


void core_driver_setup_rtc_setYear(int year){
	#ifndef RTC_MIN_YEAR
		#define RTC_MIN_YEAR 2020
	#endif
	#ifndef RTC_MAX_YEAR
		#define RTC_MAX_YEAR 2070
	#endif

	if(year<RTC_MIN_YEAR) year = RTC_MAX_YEAR;
	if(year>RTC_MAX_YEAR) year = RTC_MIN_YEAR;
	
	core_driver_setup_rtc_dateTime.year = year;
	ttgo->rtc->setDateTime(core_driver_setup_rtc_dateTime);
}

void core_driver_setup_rtc_setAlarmBySeconds(unsigned char seconds){
}