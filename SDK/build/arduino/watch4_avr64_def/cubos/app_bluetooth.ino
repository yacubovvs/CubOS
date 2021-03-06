/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *                                                                                         *
 *                                  >>>   IMPORTANT!   <<<                                 *
 *                   DO NOT FORGET TO ADD YOU APP IN os_applications.ino                   *
 *                                                                                         *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef device_bluetooth_serial
  #define device_bluetooth_serial Serial1
#endif

#define appNameClass    Bluetooth         // App name without spaces
#define appName         "Bluetooth"      // App name with spaces 

class appNameClass: public Application{
    public:
        String inputSerial = "null";
        virtual void loop() override{
            /*
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            *                                                                                         *
            *                                >>>   MAIN APP LOOP   <<<                                *
            *                                                                                         *
            */

            //EVERY FRAME CODE
            drawString_centered("BlueTooth",SCREEN_WIDTH/2,10);

            if (isPressStart_Select()){
                digitalWrite(27, 0);
                device_bluetooth_serial.end();
                //pinMode(27, INPUT);
                os_switch_to_app(-1);
            }

            while(device_bluetooth_serial.available()){
              inputSerial += (char)(device_bluetooth_serial.read());
            }

            int str_len = inputSerial.length() + 1;
            char serialData[str_len];
            inputSerial.toCharArray(serialData, str_len);

            drawString(serialData, 0, 20);

           /*                                                                                         *
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            */

        };
        void setup(){
            /*
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            *                                                                                         *
            *                              >>>   APP SETUP ON START   <<<                             *
            *                                                                                         *
            */

            // ON START CODE
            #ifdef tabletView
                this->showStatusBar = true;
            #endif

            device_bluetooth_serial.begin(9600);
            //pinMode(27, OUTPUT);
            digitalWrite(27, 1);

           /*                                                                                         *
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
            * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
            */
        };

        appNameClass(){ // Constructor
            setup();
        };

        const static byte icon[];

        		static unsigned const char* getParams(unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };

};

const byte appNameClass::icon[] PROGMEM = { //128
	//////////////////////////////////////////////////////////////
	//		PUT YOUR ICON HERE
  #ifdef colorScreen
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x66,0xff,0x00,0x3F,0xFC,0x00,0x00,0xFF,0xFF,0x00,0x01,0xFF,0xFF,0x80,0x03,0xFE,0x3F,0xC0,0x03,0xFE,0x1F,0xC0,0x07,0xFE,0x0F,0xE0,0x07,0xFE,0x47,0xE0,0x07,0xFE,0x63,0xE0,0x07,0xFE,0x71,0xE0,0x07,0x8E,0x79,0xE0,0x07,0xC6,0x71,0xE0,0x07,0xE2,0x63,0xE0,0x07,0xF0,0x47,0xE0,0x07,0xF8,0x0F,0xE0,0x07,0xFC,0x1F,0xE0,0x07,0xFE,0x3F,0xE0,0x07,0xFC,0x1F,0xE0,0x07,0xF8,0x0F,0xE0,0x07,0xF0,0x47,0xE0,0x07,0xE2,0x63,0xE0,0x07,0xC6,0x71,0xE0,0x07,0x8E,0x79,0xE0,0x07,0xFE,0x71,0xE0,0x07,0xFE,0x63,0xE0,0x07,0xFE,0x47,0xE0,0x07,0xFE,0x0F,0xE0,0x03,0xFE,0x1F,0xC0,0x03,0xFE,0x3F,0xC0,0x01,0xFF,0xFF,0x80,0x00,0xFF,0xFF,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xF0,0x00,0x00,0x01,0xB8,0x00,0x00,0x01,0x9C,0x00,0x00,0x01,0x8E,0x00,0x00,0x71,0x86,0x00,0x00,0x39,0x8E,0x00,0x00,0x1D,0x9C,0x00,0x00,0x0F,0xB8,0x00,0x00,0x07,0xF0,0x00,0x00,0x03,0xE0,0x00,0x00,0x01,0xC0,0x00,0x00,0x03,0xE0,0x00,0x00,0x07,0xF0,0x00,0x00,0x0F,0xB8,0x00,0x00,0x1D,0x9C,0x00,0x00,0x39,0x8E,0x00,0x00,0x71,0x86,0x00,0x00,0x01,0x8E,0x00,0x00,0x01,0x9C,0x00,0x00,0x01,0xB8,0x00,0x00,0x01,0xF0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  #else
    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xF8,0x20,0x00,0x00,0x04,0x40,0x00,0x00,0x02,0x80,0x01,0x80,0x01,0x80,
    0x06,0x60,0x01,0x80,0x18,0x18,0x01,0x80,0x60,0x06,0x01,0x80,0x80,0x01,0x01,0x80,0xE0,0x07,0x01,0x80,0x98,0x1F,0x01,0x80,0x86,0x7F,0x01,
    0x80,0x81,0xFF,0x01,0x80,0x80,0xFF,0x01,0x80,0x80,0xFF,0x01,0x80,0x80,0xFF,0x01,0x80,0x80,0xFF,0x01,0x80,0x80,0xFF,0x01,0x80,0x60,0xFE,
    0x01,0x80,0x18,0xF8,0x01,0x80,0x06,0xE0,0x01,0x80,0x01,0x80,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x20,0x80,0x01,0x80,0x20,
    0x00,0x01,0x80,0x38,0x94,0x01,0x80,0x24,0x9A,0x01,0x80,0x24,0x92,0x01,0x80,0x38,0x92,0x01,0x40,0x00,0x00,0x02,0x20,0x00,0x00,0x04,0x1F,
    0xFF,0xFF,0xF8,
  #endif
	//
	//////////////////////////////////////////////////////////////
};