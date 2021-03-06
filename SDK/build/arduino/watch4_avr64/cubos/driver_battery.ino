#ifdef platform_esp8266
  ADC_MODE(ADC_VCC);
#endif

#ifdef platform_m5stack
  //ADC_MODE(ADC_VCC);
  #include <Wire.h>
  #include <M5Stack.h>
  
  //M5.begin();
  
#endif

byte driver_battery_value = 0;
int battery_voltage = 0;

void driver_battery_updateChargeLevel(){
    driver_battery_value = 0;


    #ifdef platform_avr
       
       battery_voltage = driver_battery_readChargeLevel() * 11 / 10; //(Volts * 100)

       /*
          minVoltage - Volts and less - 0% of charge level
          maxVoltage - Volts and more - 100% of charge
       */

       #define minVoltage 300
       #define maxVoltage 410

       int battery_voltage_temp = battery_voltage;
       if (battery_voltage_temp<minVoltage) battery_voltage_temp = minVoltage;
       if (battery_voltage_temp>maxVoltage) battery_voltage_temp = maxVoltage;
       
       driver_battery_value = map(battery_voltage_temp, minVoltage, maxVoltage,  0, 100);

    #else
        driver_battery_value = driver_battery_readChargeLevel();
    #endif

    return;
}

byte driver_battery_getChargeLevel(){
    return driver_battery_value;
}

int driver_battery_getVoltage(){
    return battery_voltage;
}

int driver_battery_readChargeLevel() {
    
    #ifdef platform_avr
        // Read 1.1V reference against AVcc
        // set the reference to Vcc and the measurement to the internal 1.1V reference
    
        #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
            ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
        #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
            ADMUX = _BV(MUX5) | _BV(MUX0);
        #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
            ADMUX = _BV(MUX3) | _BV(MUX2);
        #else
            ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
        #endif  
        

        //delay(10); // Wait for Vref to settle
        ADCSRA |= _BV(ADSC); // Start conversion
        while (bit_is_set(ADCSRA,ADSC)); // measuring

        uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
        uint8_t high = ADCH; // unlocks both

        long result = (high<<8) | low;

        result = 1125300L / result / 10; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
        return (int)result; // Vcc in millivolts
    #endif

    #ifdef platform_esp8266
        return ESP.getVcc()*100;
    #endif

    #ifdef platform_m5stack
        Wire.begin();
    
        Wire.beginTransmission(0x75);
        Wire.write(0x78);
        if (Wire.endTransmission(false) == 0
        && Wire.requestFrom(0x75, 1)) {

            //return Wire.read();
            
            switch (Wire.read() & 0xF0) {
              case 0xE0: return 25;
              case 0xC0: return 50;
              case 0x80: return 75;
              case 0x00: return 100;
              default: return 0;
            }
            
        }
        return -1;
    #endif

    return 0;
}