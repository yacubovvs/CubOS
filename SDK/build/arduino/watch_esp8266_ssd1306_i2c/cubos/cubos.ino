/*
    ############################################################################################
    #                                                                                          #
    #                                     M5STACK SETTINGS                                     #
    #                                                                                          #
    ############################################################################################
*/

/*
    ###   #   ##    #   ## ##   ##      
    # #  # #  # #  # #  # # #  #        #
    ###  ###  ##   ###  #   #   ##    #####     
    #    # #  # #  # #  #   #    #      #
    #    # #  # #  # #  #   #  ##       
*/

#define SCREEN_WIDTH            128     // Note: x-coordinates go wide
#define SCREEN_HEIGHT           64     // Note: y-coordinates go high

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define useNativeMenu                   // Using default app_menu.ino
#define conf_esp8266_nokia_watch        // Name of Mconfiguration
#define platform_esp8266                // Platform
#define control_buttons_count 3
#define control_buttons_pins {12, 14, 13}
#define control_buttons_on_HIGH_level

#define hasHardwareButtons              // Conf of controls with hardware btns 

#define display_i2c_ssd1306

//#define device_has_barometer
//#define device_has_accelerometer

#define device_has_vibro
#define device_vibro_pin 16

// #####################################
// ##           POWER CONTROL           
#define device_has_power_manager
#define device_can_sleep

#define millis() (os_get_rtc_Millis())

extern "C"
        {
            #include "user_interface.h"
            #include "osapi.h"
            #include "ets_sys.h"
        }
        
//#define millis() (system_get_rtc_time()/system_rtc_clock_cali_proc()*100)

#define debug
//#define device_has_backlight_control
//#define backlight_init 128


//#define isTouchScreen                 // Conf of controls

//#define tabletView                      // View
//#define tabletView_statusBarHeight 24   // Height of status bar at top of screen

//#define colorScreen                   // Screen is colored
//#define noAnimation                     // Caurse of framebuffer type
#define os_MAINMENU_APP_COUNT 5         // How much apps in menu

//#define mainMenu_iconsInRow 3           // Count of apps in row in tabview in mainMenu
//#define frame_selected_app_padding 10   // Padding of frame on hardware buttons navigate in menu

//#define mainMenu_scrollSize 16          // Size of scrollbar at right of screen
//#define mainMenu_icon_element_size ((SCREEN_WIDTH-1)/mainMenu_iconsInRow - mainMenu_scrollSize/mainMenu_iconsInRow)

//#define appArea_margin_top tabletView_statusBarHeight

// Max ram for apllications runs from TFCard
//#define MAX_RAM_SIZE_FOR_B_APPS 255     //in bytes

/*
    ###   #   ##    #   ## ##   ##      
    # #  # #  # #  # #  # # #  #        
    ###  ###  ##   ###  #   #   ##    #####     
    #    # #  # #  # #  #   #    #      
    #    # #  # #  # #  #   #  ##       
*/#define SCREEN_CENTER_X (SCREEN_WIDTH/2)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT/2)

#ifdef platform_avr
	#include "libs_h/CyberLib/CyberLib.h"
#endif

unsigned int dtime = 0;

/*
**************************************
*                                    *
*            APPLICATIONS +          *
*                                    *
**************************************
*/
#define ICON_ARROW_RIGHT 	0x01
#define ICON_ARROW_LEFT 	0x02
#define ICON_ARROW_UP 		0x03
#define ICON_ARROW_DOWN 	0x04
#define BATTERY_UNKNOWN		0x05

#define BATTERY_100			0x06
#define BATTERY_90			0x07
#define BATTERY_80			0x08
#define BATTERY_70			0x09
#define BATTERY_60			0x0A
#define BATTERY_50			0x0B
#define BATTERY_40			0x0C
#define BATTERY_30			0x0D
#define BATTERY_20			0x0E
#define BATTERY_10			0x0F
#define BATTERY_0			0x10

#define WIFI_CONNECTED		0x11
#define WIFI_NOTCONNECTED	0x12
#define WI_FI_IMG_OFF		0x13
#define BT_CONNECTED		0x14
#define BT_NOTCONNECTED		0x15
#define BT_OFF				0x16

#define PARAM_TYPE_ICON 	0x01
#define PARAM_TYPE_NAME 	0x02


/////////////////////////////////////
// APPLICATION CLASS
#ifndef do_Not_use_native_apps
	class Application{
		public:
		#ifdef tabletView
		boolean showStatusBar = false;
		#endif
		
			int scroll_x	      	= 0;
			int scroll_y	      	= 0;
			int scroll_to_x			= 0;
			int scroll_to_y			= 0;
			virtual void loop() = 0;
			void loop_app(){
				loop();

				#ifdef noAnimation
					scroll_x = scroll_to_x;
					scroll_y = scroll_to_y;
				#else
					int dy=0; int dx =0;
		
					if(scroll_x!=scroll_to_x){
						dx = abs(scroll_x-scroll_to_x)/5 + 2;
						if(scroll_x>scroll_to_x) dx *= -1;
						scroll_x+=dx;
		
						if (abs(scroll_x-scroll_to_x)<abs(dx)) scroll_to_x=scroll_x;
					}
		
					if(scroll_y!=scroll_to_y){
						dy = abs(scroll_y-scroll_to_y)/5 + 2;
						if(scroll_y>scroll_to_y) dy *= -1;
						scroll_y+=dy;
				
						if (abs(scroll_y-scroll_to_y)<abs(dy)) scroll_y=scroll_to_y;
					}

					//Serial.println(scroll_to_y);
				#endif
			}
			Application(){};
	};

	Application* currentApp;

#else
	int scroll_x	      = 0;
	int scroll_y	      = 0;
	int scroll_to_x		  = 0;
	int scroll_to_y		  = 0;

	void appsetup(){
		no_native_apps_SETUP();
	}

	void apploop(){		
		no_native_apps_LOOP();
	}
#endif
//
/////////////////////////////////////

#ifdef useNativeMenu
	Application *getApp(byte i);
	////////////////////////////////////

	void os_switch_to_app(byte app_numm){
		delete currentApp;
		#ifdef colorScreen
			// for correct drawing background
			driver_clearScreen();
		#endif
		currentApp = getApp(app_numm);
	}
#endif
/*
**************************************
*                                    *
*            APPLICATIONS -          *
*                                    *
**************************************
*/

#ifdef platform_avr
	#include <avr/sleep.h>
#endif

void setup()
{ 
  #ifdef debug
	Serial.begin(115200);
  #endif

  #ifdef platform_avr
	//set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	//sleep_enable();

	//MCUCR = bit (BODS) | bit (BODSE);
	//MCUCR = bit (BODS);
	//sleep_cpu();
  #endif

  #ifdef device_has_power_manager
	power_manager_setup();
  #endif

  setup_displayDriver();
	os_control_setup();
	//setup_os_menu();

	#ifndef do_Not_use_native_apps
		#ifdef BOOT_FUNC
			BOOT_FUNC();
		#else
			app_mainmenu_start(); // Start first app
		#endif
	#else
		no_native_apps_SETUP();
	#endif

	#ifdef device_has_barometer
		//barometer_setup();
	#endif

	#ifndef device_has_power_manager
		#ifdef device_has_accelerometer
			accelerometer_setup();
		#endif
	#else
		// if device_has_power_manager define - start accelerometer then need
	#endif

	#ifdef device_has_vibro
		driver_vibro_setup();
	#endif


  calibrate_rtc(100);

}

/*
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# #                                     TESTING +                                   # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/
long lastMillis = 0;
long lastRTC = 0;

long rtc_k = 0;

long current_rtcTime = 0;

long os_get_rtc_Millis(){
  return current_rtcTime;
}

long get_rtc_k(){
  return rtc_k; 
}

void os_update_rtc_Millis(){
  if(rtc_k==0){
    Serial.println("rtc_k==0");
    return;
  }
  
  long new_rtc = system_get_rtc_time();
  long new_millis = millis();

  current_rtcTime += (lastRTC-new_rtc)/rtc_k;

  lastRTC = new_rtc;
  lastMillis = new_millis;
  //lastMillis = millis();

  Serial.print("rtc_k ");
  Serial.println(rtc_k);
}

void calibrate_rtc(){
  calibrate_rtc(100);
}

void calibrate_rtc(int t_delay){
  long t1_millis = system_get_rtc_time();
  long t1_rtc = millis();

  delay(t_delay);

  long t2_millis = system_get_rtc_time();
  long t2_rtc = millis();

  rtc_k = (t1_rtc - t2_rtc)/(t1_millis - t2_millis);
  os_update_rtc_Millis();
}



/*
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# #                                     TESTING -                                   # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

void loop(){
  calibrate_rtc(100);
	clearscreen_displayDriver();

	#ifdef tabletView
    	if (currentApp->showStatusBar) os_draw_statusbar();
	#endif

	dtime = os_clock_update();
	
	os_control_loop(); // Check buttons

	#ifndef do_Not_use_native_apps
		currentApp->loop_app();
	#else
		no_native_apps_LOOP();
	#endif
	

	////////////////////////////////////////////////////////////////////
	//  Debug string data
      	
		#ifdef colorScreen
			setDrawColor_background();
			drawRect(0,310, 30, 320, true);
		#endif  
      	//showFreeMemory(); // show free memory
      	//drawDebugString(dtime, 0); // show time needed for 1 loop
      	//drawDebugString(1000/dtime, 10); // FPS
      	//drawDebugString(millis()/1000, 55); // Timer (if you want to know is os freezing)


        /*
       long millis_time = millis();
       long rtc_time = system_get_rtc_time();
       long cali_proc = system_rtc_clock_cali_proc();

       delay(1000);

       long d_millis_time = millis() - millis_time;
       long d_rtc_time = system_get_rtc_time() - rtc_time;

       drawDebugString(d_rtc_time*100/d_millis_time, 0);

       //drawDebugString(millis() - millis_time, 0);
       //drawDebugString(system_get_rtc_time() - rtc_time, 8);
       drawDebugString(system_rtc_clock_cali_proc(), 16);

       //system_get_rtc_time()/system_rtc_clock_cali_proc()*100
       */

       os_update_rtc_Millis();

      /*
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # #                                     TESTING +                                   # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      */
      //long lastMillis = 0;
      //long lastRTC = 0;
      
      //long count_rtcTime = 0;

      drawDebugString(lastMillis/1000, 0);
      drawDebugString(lastRTC/1000/1000, 10);

      lastMillis = millis();
      lastRTC = system_get_time();
      /*
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # #                                     TESTING -                                   # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      */
       

      //drawDebugString(get_timeInsleep(), 0);
       

		#ifdef colorScreen
			setDrawColor_contrast();
		#endif  
  	//
  	////////////////////////////////////////////////////////////////////

	#ifdef device_can_sleep	
    	device_powermanager_sleep_loop();
	#endif

  	updatescreen_displayDriver();
}
