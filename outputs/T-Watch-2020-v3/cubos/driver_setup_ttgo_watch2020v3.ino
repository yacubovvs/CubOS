// MAIN DEVICE DRIVER

#include <LilyGoWatch.h>

TTGOClass *ttgo;

bool core_driver_isCharging = false;
bool core_driver_VBUSConnected = false;
bool core_driver_isShortPressed = false;
bool core_driver_isLongPressed = false;

bool core_driver_irq = false;

void core_setup_driver(){
    ttgo = TTGOClass::getWatch();
    ttgo->begin();

    pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(AXP202_INT, [] {
        core_driver_irq = true;
    }, FALLING);

    //!Clear IRQ unprocessed  first
    ttgo->power->enableIRQ(AXP202_PEK_LONGPRESS_IRQ | AXP202_PEK_SHORTPRESS_IRQ | AXP202_VBUS_REMOVED_IRQ | AXP202_VBUS_CONNECT_IRQ | AXP202_CHARGING_IRQ, true);
    //ttgo->power->enableIRQ(AXP202_PEK_LONGPRESS_IRQ | AXP202_PEK_SHORTPRESS_IRQ, true);
    //ttgo->power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ | AXP202_VBUS_REMOVED_IRQ | AXP202_VBUS_CONNECT_IRQ | AXP202_CHARGING_IRQ, true);
    ttgo->power->clearIRQ();
}

void core_loop_driver(){
    
    if(core_driver_irq){
        core_driver_irq = false;
        debug("attachInterrupt AXP202_INT");
        /*
        ttgo->power->readIRQ();
        if (ttgo->power->isVbusPlugInIRQ()) {
            ttgo->tft->fillRect(20, 100, 200, 85, TFT_BLACK);
            ttgo->tft->drawString("Power Plug In", 25, 100);
        }
        if (ttgo->power->isVbusRemoveIRQ()) {
            ttgo->tft->fillRect(20, 100, 200, 85, TFT_BLACK);
            ttgo->tft->drawString("Power Remove", 25, 100);
        }
        if (ttgo->power->isPEKShortPressIRQ()) {
            ttgo->tft->fillRect(20, 100, 200, 85, TFT_BLACK);
            ttgo->tft->drawString("PowerKey Press", 25, 100);
        }
        ttgo->power->clearIRQ();
        */
        
        ttgo->power->readIRQ();
        
        if (ttgo->power->isVbusPlugInIRQ()){
            debug("isVbusPlugInIRQ");
            //core_driver_isCharging=true; 
            //core_driver_VBUSConnected=true;
        }

        if (ttgo->power->isVbusRemoveIRQ()){
            debug("isVbusRemoveIRQ");
            //core_driver_isCharging=false; 
            //core_driver_VBUSConnected=false;
        }

        if (ttgo->power->isPEKShortPressIRQ()){
            debug("isPEKShortPressIRQ");
            //core_driver_isShortPressed = true;  
        } 

        
        if (ttgo->power->isChargingDoneIRQ()){
            debug("isChargingDoneIRQ");
            //core_driver_isCharging=false; 
            //core_driver_VBUSConnected=true;
        }

        if (ttgo->power->isPEKLongtPressIRQ()){
            debug("isPEKLongtPressIRQ");
            //core_driver_isLongPressed = true;
        }
        
        ttgo->power->clearIRQ();
    }
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
 