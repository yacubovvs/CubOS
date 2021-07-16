// MAIN DEVICE DRIVER
#define LILYGO_WATCH_2020_V3 
#include <LilyGoWatch.h>

TTGOClass *ttgo;
AXP20X_Class *ttgo_power;

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

void core_driver_openBL(){
    ttgo->openBL();
}

void core_driver_fillScreen(uint16_t fillColor){
    ttgo->tft->fillScreen(fillColor);
}

void core_driver_drawPixel(int x, int y, uint16_t color){
    ttgo->tft->drawPixel(x, y, color);
}
 