#include <M5EPD.h>

void core_setup_driver(){
    M5.begin();
    M5.EPD.SetRotation(90);
    M5.EPD.Clear(true);
    M5.RTC.begin();
}

void core_loop_driver(){

}