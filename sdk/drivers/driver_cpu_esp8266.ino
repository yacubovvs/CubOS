#include "Arduino.h"
#include "ESP8266WiFi.h"
/*
#include "gpio.h"
extern "C" {
    #include "user_interface.h"
    //uint16 readvdd33(void);
    
}*/

extern "C" {
  #include "gpio.h"
}
extern "C" {
  #include "user_interface.h"
  bool wifi_set_sleep_type(sleep_type_t);
    sleep_type_t wifi_get_sleep_type(void);
}

void driver_cpu_setup(){
    driver_cpu_wakeup();
    //wifi_set_sleep_type(MODEM_SLEEP_T);


    //driver_cpu_wakeup();
    //wifi_fpm_open();
    //wifi_fpm_do_sleep(0xFFFFFFF); // Sl
}

void driver_cpu_wakeup(){
  WiFi.forceSleepWake();
    delay(50);
  
    wifi_set_sleep_type(MODEM_SLEEP_T);
    WiFi.disconnect();
    WiFi.mode(WIFI_OFF);
    // how do we call this: 
    //gpio_pin_wakeup_enable(GPIO_ID_PIN(switchPin),GPIO_PIN_INTR_NEGEDGE);
    wifi_fpm_open();
    wifi_fpm_do_sleep(26843455);
    WiFi.forceSleepBegin();
    delay(5);

    powerOn_displayDriver();
    driver_controls_setup();
    
}

void driver_cpu_sleep(){
    WiFi.forceSleepWake();
    //gpio_init(); // Initilise GPIO pins
    //wifi_fpm_open();
        wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);
        wifi_fpm_open();
        gpio_pin_wakeup_enable(GPIO_ID_PIN(3), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
        gpio_pin_wakeup_enable(GPIO_ID_PIN(1), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
        gpio_pin_wakeup_enable(GPIO_ID_PIN(15), GPIO_PIN_INTR_HILEVEL); // GPIO_PIN_INTR_LOLEVEL 
        gpio_pin_wakeup_enable(GPIO_ID_PIN(12), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 

        wifi_fpm_do_sleep(0xFFFFFFF);
        delay(50);
        debug("Going to sleep ");
        debug(String(millis()));
        debug("\n");

    /*
    powerOff_displayDriver();
    return;
    
    ESP.wdtDisable();
    */
    //wifi_fpm_set_sleep_type(LIGHT_SLEEP_T); // set sleep type, the above posters wifi_set_sleep_type() didnt seem to work for me although it did let me compile and upload with no errors
    //pinMode(0, OUTPUT);
    //digitalWrite(0, 0);
    

    //gpio_pin_wakeup_enable(GPIO_ID_PIN(16), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    
    /*
    // real:
    gpio_pin_wakeup_enable(GPIO_ID_PIN(12), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(15), GPIO_PIN_INTR_HILEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(3), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(4), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    */

    /*
    // testing:
    gpio_pin_wakeup_enable(GPIO_ID_PIN(3), GPIO_PIN_INTR_HILEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(0), GPIO_PIN_INTR_HILEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(1), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(15), GPIO_PIN_INTR_HILEVEL); // GPIO_PIN_INTR_LOLEVEL 
    gpio_pin_wakeup_enable(GPIO_ID_PIN(12), GPIO_PIN_INTR_LOLEVEL); // GPIO_PIN_INTR_LOLEVEL 
    */

   
   /*
    wifi_set_opmode_current(NULL_MODE);
    wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);

    wifi_fpm_open(); // Enables force sleep
   
    wifi_fpm_do_sleep(0xFFFFFFF); // Sl
    delay(1000);
    */
}
