#include <LilyGoWatch.h>

TTGOClass *watch;
AXP20X_Class *power;

void core_setup_driver(){
    watch = TTGOClass::getWatch();
    watch->begin();
    power = watch->power;
}