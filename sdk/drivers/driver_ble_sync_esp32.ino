#include "NimBLEDevice.h"

#ifndef SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR
  #define SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR 3
#endif

// The server service:
static BLEUUID driver_ble_serviceUUID("000a1805-0000-1000-8000-00805f9b34fb");

// The characteristics:
static BLEUUID  driver_ble_currentTime_characteristic_UUID           ("00aa2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_notifications_characteristic_UUID         ("00ba2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_missedCalls_characteristic_UUID           ("00ca2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_isCalling_characteristic_UUID             ("00da2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_dataHash_characteristic_UUID              ("00ea2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_apiVersion_characteristic_UUID            ("00fa2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_alarms_characteristic_UUID                ("010a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_day_set_steps_sleep_characteristic_UUID   ("020a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_settings_characteristic_UUID              ("030a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_day_date_per_hour_characteristic_UUID     ("040a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  driver_ble_week_data_per_day_characteristic_UUID     ("060a2a2b-0000-1000-8000-00805f9b34fb");

static boolean driver_ble_connected = false;
static boolean driver_ble_doScan = false;
static BLERemoteCharacteristic* driver_ble_pRemoteCharacteristic;
static BLEAdvertisedDevice* driver_ble_myDevice;
BLEScan* driver_ble_pBLEScan;
BLERemoteService* driver_ble_pRemoteService;
BLEClient*  driver_ble_pClient;
TaskHandle_t driver_ble_Task1;

long current_sync_variant = 0;
void driver_ble_start_sync(long syncVariants){
    current_sync_variant = syncVariants;

    debug("driver_ble_start_sync");

    // Created FreeRTOS task for running in multitask
    if(get_core_ble_is_syncing()==false){
        debug("Ready to create task");
        set_core_ble_is_syncing(true);
        xTaskCreatePinnedToCore(
                        driver_ble_BleEsp32SyncTask,
                        "driver_ble_esp32_syncTask",
                        10000,
                        NULL,
                        1,
                        &driver_ble_Task1,
                        0); 
    } else{
        debug("Task already created");
    }
}

bool driver_ble_connectToServer() {
    //pClient = nullptr;

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("---connectToServer 1");
    #endif

    if(driver_ble_myDevice!=nullptr){
      driver_ble_pClient->connect(driver_ble_myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
    }else{
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        debug("myDevice==nulptp");
      #endif
      return false;
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("---connectToServer 2");
    #endif
    
    driver_ble_pRemoteService = driver_ble_pClient->getService(driver_ble_serviceUUID);
    
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("---connectToServer 3");
     #endif
     
    if(driver_ble_pRemoteService == nullptr) {
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        debug("Failed to find our service UUID: ");
        debug(driver_ble_serviceUUID.toString().c_str());
      #endif
      driver_ble_pClient->disconnect();
      //pClient = nullptr;
      return false;
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("---connectToServer 4");
    #endif
    BLEDevice::getScan()->clearResults();

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("---connectToServer 5");
    #endif
    driver_ble_connected = true;
    return true;
}

void driver_ble_BleEsp32SyncTask( void * pvParameters ){
    // This is running on Core0
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      long start_time = millis();
    #endif 
    core_ble_set_syncStatus(SYNC_STATUS_CONNECTING);
    
    //debug("Task started");
    driver_ble_pRemoteService = nullptr;  
    //debug("Task started--1");
    driver_ble_pBLEScan->start(5, false);
    //debug("Task started--2");
    driver_ble_connected = driver_ble_connectToServer();
    //debug("Task started--3");
    if (driver_ble_connected) {
        core_ble_set_syncStatus(SYNC_STATUS_IN_PROGRESS);

        if(current_sync_variant&SYNC_VARIANTS_GET_API_VERSION){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_API_VERSION");
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_DATA_HASH){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_DATA_HASH");
          #endif
          driver_ble_getDataHash(0);
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_SETTINGS){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_SETTINGS");
          #endif
          driver_ble_getSettings(0);
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_CURRENT_TIME){
          if(get_core_ble_sync_time()){
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("Sync variant SYNC_VARIANTS_GET_CURRENT_TIME");
            #endif
            driver_ble_getCurrentTime(0);
          }else{
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("** Time will not be syncing by sync settings");
            #endif
          }
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_PEDOMETER_DAY_STEPS_SLEEP_LIMITS){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_PEDOMETER_DAY_STEPS_SLEEP_LIMITS");
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_CURRENT_DAY_STEPS_SLEEP){
          #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_CURRENT_DAY_STEPS_SLEEP");
            #endif
            //(uint32_t steps, uint16_t sleep_min, uint16_t steps_limits, uint16_t sleep_min_limits)
            driver_ble_setStepsAndSleep_values(get_pedometer_days_steps(), get_pedometer_days_sleep(), get_pedometer_days_steps_min_limit(), get_pedometer_days_sleep_min_limit());
          #else
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("Can't sync variant SYNC_VARIANTS_SET_PEDOMETER_CURRENT_DAY_STEPS_SLEEP. Pedometer is not available on this device");
            #endif
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_DAY_DATA_PER_HOUR){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_DAY_DATA_PER_HOUR");
          #endif

          #ifdef PEDOMETER_ENABLE
            uint8_t current_day = core_time_getDate();
            uint8_t current_hour = core_time_getHours_byte();
            //for(int hour=0; hour<24; hour++){
            for(int hour=current_hour; hour>=0; hour--){
              driver_ble_setDayData_values(current_day, current_hour, current_hour-hour, get_pedometer_hours_steps(hour), get_pedometer_hours_sleep(hour));
              delay(50);
            }

            // yesterday data of steps and sleep
            for(int hour=0; hour<24; hour++){
              /*
              uint16_t get_pedometer_hours_steps_lastDay(unsigned char hour){ return pedometer_hours_steps_lastDay[hour];}
              uint8_t get_pedometer_hours_sleep_lastDay(unsigned char hour){ return pedometer_hours_sleep_lastDay[hour];}
              */
              driver_ble_setDayData_values(current_day, current_hour, current_hour-hour+24, get_pedometer_hours_steps_lastDay(hour), get_pedometer_hours_sleep_lastDay(hour));
              delay(50);
            }
            
          #else
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("Can't sync variant SYNC_VARIANTS_SET_PEDOMETER_DAY_DATA_PER_HOUR. Pedometer is not available on this device");
            #endif
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_WEEK_DATA_PER_DAY){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_WEEK_DATA_PER_DAY");
          #endif

          #ifdef PEDOMETER_ENABLE
            uint8_t current_day = core_time_getDate();
            for(uint16_t day_shift=0; day_shift<PEDOMETER_DAYS_HISTORY; day_shift++){
              driver_ble_setWeekData_values(current_day, day_shift, get_pedometer_days_steps(day_shift), get_pedometer_days_sleep(day_shift));
              delay(50);
            }
          #else
            #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
              debug("Can't sync variant SYNC_VARIANTS_SET_PEDOMETER_WEEK_DATA_PER_DAY. Pedometer is not available on this device");
            #endif
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_NOTIFICATIONS){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_NOTIFICATIONS");
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_CURRENT_CALL){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_CURRENT_CALL");
          #endif
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_MISSED_CALLS){
          #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("Sync variant SYNC_VARIANTS_GET_MISSED_CALLS");
          #endif
        }

        driver_ble_pClient->disconnect();
        core_ble_set_syncStatus(SYNC_STATUS_FINISHED);
    }else{
        #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
          debug("--- Was not connected");
        #endif
        core_ble_set_syncStatus(SYNC_STATUS_ERROR_SERVER_NOT_FOUND);
        set_core_ble_sync_error(true);
    }//*/
    
    driver_ble_connected = false;
    //delete myDevice;
    driver_ble_myDevice = nullptr;

    set_core_ble_is_syncing(false);

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("##### SYNC TOOK " + String(millis()-start_time) + "ms");
    #endif

    vTaskDelete(NULL);
}
/*
static void notifyCallback(BLERemoteCharacteristic* driver_ble_pRemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify) {
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("Notify callback for characteristic ");
      debug(driver_ble_pRemoteCharacteristic->getUUID().toString().c_str());
      debug(" of data length ");
      debug(length);
      debug("data: ");
      debug((char*)pData);
    #endif
}
*/

class driver_ble_MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
  }

  void onDisconnect(BLEClient* pclient) {
    driver_ble_connected = false;
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("onDisconnect");
    #endif
  }

  uint32_t onPassKeyRequest(){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("Client PassKeyRequest");
    #endif
    return 123456; 
  }
  bool onConfirmPIN(uint32_t pass_key){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("The passkey YES/NO number: ");debug(String(pass_key));
    #endif
    return true; 
  }

  void onAuthenticationComplete(ble_gap_conn_desc desc){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("Starting BLE work!");
    #endif
  }

};

class driver_ble_MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* advertisedDevice) {
    if (advertisedDevice->haveServiceUUID() && advertisedDevice->isAdvertisingService(driver_ble_serviceUUID)) {
      BLEDevice::getScan()->stop();
      driver_ble_myDevice = advertisedDevice;
      driver_ble_doScan = true;
    }
  }
};

void driver_ble_sync_setup(){
    driver_ble_init_BLE();
    driver_ble_init_BLE_SCAN();
    driver_ble_client_init();
}

void driver_ble_client_init(){
  driver_ble_pClient  = BLEDevice::createClient();
  driver_ble_pClient->setClientCallbacks(new driver_ble_MyClientCallback(), true);
}

void driver_ble_deinit_BLE(){
    BLEDevice::deinit(true);
}

void driver_ble_init_BLE(){
    BLEDevice::init("");
}

void driver_ble_init_BLE_SCAN(){
    driver_ble_pBLEScan = BLEDevice::getScan();
    driver_ble_pBLEScan->clearAdvertisedDeviceCallbacks();
    driver_ble_pBLEScan->setAdvertisedDeviceCallbacks(new driver_ble_MyAdvertisedDeviceCallbacks());
    driver_ble_pBLEScan->setInterval(1349);
    driver_ble_pBLEScan->setWindow(449);
    driver_ble_pBLEScan->setActiveScan(true);
    driver_ble_pBLEScan->start(5, false);
}


/*
        # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # #                                                                                                     # # # # #
    # # # #                                                                                                         # # # #
    # # # #                                              SYNC FUNCTION!                                             # # # #
    # # # #                                                                                                         # # # #
    # # # # #                                                                                                     # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
        # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #   
*/


bool driver_ble_getCurrentTime(unsigned char attemptNum){
    if(attemptNum>=SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR) return false;

    BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_currentTime_characteristic_UUID);
    if(pRemoteCharacteristic==nullptr) return false;
    
    std::string readValue = pRemoteCharacteristic->readValue();

    unsigned char server_month      = readValue[2];
    unsigned char server_date       = readValue[3];
    unsigned char server_dayOfWeek  = readValue[4];
    unsigned char server_hours      = readValue[5];
    unsigned char server_minutes    = readValue[6];
    unsigned char server_seconds    = readValue[7];
    unsigned char hashSum1          = readValue[8];
    unsigned char hashSum2          = readValue[9];

    int server_year = readValue[0]|(readValue[1]<<8);

    bool hashCheck = driver_ble_checkgetHashSum( (unsigned char)(readValue[0] + readValue[2] + readValue[4] + readValue[6]), (unsigned char)(readValue[1] + readValue[3] + readValue[5] + readValue[7]), (unsigned char)hashSum1, (unsigned char)hashSum2);

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("Getting current time: ");
      debug("Year: ");
      debug(String((int)server_year));
      debug("month: ");
      debug(String((byte)server_month));
      debug("day: ");
      debug(String((byte)server_date));
      debug("day of week: ");
      debug(String((byte)server_dayOfWeek));
      debug("hours: ");
      debug(String((byte)server_hours));
      debug("minutes: ");
      debug(String((byte)server_minutes));
      debug("seconds: ");
      debug(String((byte)server_seconds));

      if(hashCheck) debug("### driver_ble_getCurrentTime CHECKSUM CHECK SUCCESS");
      else{
        debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
        debug("#                                  ERROR!!!                                   #");
        debug("#               driver_ble_getCurrentTime CHECKSUM CHECK FAILED               #");
        debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
      }

    #endif
    
    if(!hashCheck){
      delay(20); // Just in case
      return driver_ble_getCurrentTime(attemptNum + 1);
    }else{
      unsigned char wdt_settingsTime = 0;
      core_time_settings_lastDay_currentDate();
      
      // Fixed some bugs in RTC
      while(
        core_time_getYear()!=server_year ||
        core_time_getMonth()!=server_month ||
        core_time_getDate()!=server_date ||
        core_time_getHours_byte()!=server_hours ||
        core_time_getMinutes_byte()!=server_minutes ||
        core_time_getSeconds_byte()!=server_seconds
      ){
        core_time_driver_RTC_refresh(true);

        core_time_setYear(server_year);
        core_time_setMonth(server_month);
        core_time_setDate(server_date);
        core_time_setHours(server_hours);
        core_time_setMinutes(server_minutes);
        core_time_setSeconds(server_seconds);
        core_time_setWeekDay( (server_dayOfWeek-1+7)%7);

        wdt_settingsTime++;

        #ifdef RTC_ENABLE 
          core_time_settings_lastDay_currentDate();
        #endif

        #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
          if(wdt_settingsTime>0){
            debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
            debug("#                                RTC ERROR!!!                                 #");
            debug("#                            RTC BUG SETTING TIME!                            #");
            debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
          }
        #endif

        if(wdt_settingsTime>=5) break;
      }
    }
    
    /*
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        debug("###########################################################");
        debug("Server day of week " + String(server_dayOfWeek));
        debug("Cubos day of week " + String(core_time_getWeekDay()));
        debug("Day of week string " + core_time_getWeekDay_stringShort());
    #endif
    */

    return true;

}

bool driver_ble_getAPIVersion(unsigned char attemptNum){

  if(attemptNum>=SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR) return false;

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_apiVersion_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return false;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  int api_version = readValue[0]|(readValue[1]<<8);
  unsigned char hashSum1          = readValue[2];
  unsigned char hashSum2          = readValue[3];

  bool hashCheck = driver_ble_checkgetHashSum( (unsigned char)(readValue[0]), (unsigned char)(readValue[1]), (unsigned char)hashSum1, (unsigned char)hashSum2);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting server API version: ");
    debug(String((int)api_version));
    if(hashCheck) debug("### driver_ble_getSettings CHECKSUM CHECK SUCCESS");
    else{
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
      debug("#                                  ERROR!!!                                   #");
      debug("#                 driver_ble_getSettings CHECKSUM CHECK FAILED                #");
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
    }
  #endif

  if(!hashCheck){
    delay(20);
    return driver_ble_getAPIVersion(attemptNum + 1);
  }else{
    //TODO
  }

  return true;
}

bool driver_ble_getSettings(unsigned char attemptNum){

  if(attemptNum>=SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR) return false;

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_settings_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return false;
  
  std::string readValue = pRemoteCharacteristic->readValue();
  
  /*
    (byte) (pedometerOn?0x01:0x00),  // - 0x00 - pedometer off, 0x01 - pedometer on
    (byte) (syncTime?0x01:0x00),
    (byte) (autosyncOnCharge?0x01:0x00),
    stepsLimit_1,
    stepsLimit_2,
    sleepLimit_1,
    sleepLimit_2,
    screenOffTime,
    screenOffClock
  */

  bool pedometer_enable     = readValue[0];
  bool syncTime_enable      = readValue[1];
  bool syncOnCharge_enable  = readValue[2];
  int steps_limit = readValue[3]|(readValue[4]<<8);
  int sleep_limit = readValue[5]|(readValue[6]<<8);
  uint8_t screen_off_time = readValue[7];
  uint8_t screen_off_time_clock = readValue[8];
  unsigned char hashSum1          = readValue[9];
  unsigned char hashSum2          = readValue[10];

  bool hashCheck = driver_ble_checkgetHashSum( (unsigned char)(readValue[0] + readValue[2] + readValue[4] + readValue[6] + readValue[8]), (unsigned char)(readValue[1] + readValue[3] + readValue[5] + readValue[7]), (unsigned char)hashSum1, (unsigned char)hashSum2);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    if (pedometer_enable)debug("* BLE got settings: Pedometer is enable");
    else debug("* BLE got settings: Pedometer is not enable");

    if (syncTime_enable) debug("* BLE got settings: Sync time is enable");
    else debug("* BLE got settings: Sync time not is enable");

    if (syncOnCharge_enable) debug("* BLE got settings: Sync on charge is enable");
    else debug("* BLE got settings: Sync on charge is not enable");

    debug("* BLE got settings: step limit: " + String(steps_limit));
    debug("* BLE got settings: sleep limit: " + String(sleep_limit));
    debug("* BLE got settings: screen off time: " + String(screen_off_time));
    debug("* BLE got settings: screen off time clock: " + String(screen_off_time_clock));

    if(hashCheck) debug("### driver_ble_getSettings CHECKSUM CHECK SUCCESS");
    else{
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
      debug("#                                  ERROR!!!                                   #");
      debug("#                 driver_ble_getSettings CHECKSUM CHECK FAILED                #");
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
    }

  #endif

  if(!hashCheck){
    delay(20); // Just in case
    return driver_ble_getSettings(attemptNum + 1);
  }else{
      #ifdef PEDOMETER_ENABLE
        core_pedometer_setEnable(pedometer_enable);
        set_pedometer_days_steps_min_limit(steps_limit);
        set_pedometer_days_sleep_min_limit(sleep_limit);
      #endif

      set_core_ble_sync_time(syncTime_enable);
      set_core_ble_auto_sync_on_charge(syncOnCharge_enable);

      set_core_display_time_delay_to_poweroff(screen_off_time);
      set_core_display_time_delay_to_poweroff_clock_app(screen_off_time_clock);
  }

  return true;
}

bool driver_ble_getDataHash(unsigned char attemptNum){
  if(attemptNum>=SYNC_ATTEMPTS_TO_CONNECT_ON_HASHSUM_ERROR) return false;

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_dataHash_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return false;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  uint16_t notifications_hash     = readValue[0]|(readValue[1]<<8);
  uint16_t missedcalls_hash       = readValue[2]|(readValue[3]<<8);
  uint8_t currentcall_hash        = readValue[4];
  uint8_t settings_changed        = readValue[5];
  uint8_t alarms_changed          = readValue[6];
  uint8_t weather_changed         = readValue[7];
  unsigned char hashSum1          = readValue[8];
  unsigned char hashSum2          = readValue[9];

  bool hashCheck = driver_ble_checkgetHashSum( (unsigned char)(readValue[0] + readValue[2] + readValue[4] + readValue[6]), (unsigned char)(readValue[1] + readValue[3] + readValue[5] + readValue[7]), (unsigned char)hashSum1, (unsigned char)hashSum2);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting notification hash: ");
    debug(String((uint16_t)notifications_hash));
    debug("Getting missedcalls hash: ");
    debug(String((uint16_t)missedcalls_hash));
    debug("Getting current call hash: ");
    debug(String((uint16_t)currentcall_hash));
    debug("Settings changed flag: ");
    debug(String((uint16_t)settings_changed));

    if(hashCheck) debug("### driver_ble_getDataHash CHECKSUM CHECK SUCCESS");
    else{
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
      debug("#                                  ERROR!!!                                   #");
      debug("#                 driver_ble_getDataHash CHECKSUM CHECK FAILED                #");
      debug("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
    }
  #endif

  if(!hashCheck){
      delay(20); // Just in case
      return driver_ble_getDataHash(attemptNum + 1);
    }else{
      // TODO
    }

  return true;
  
}

byte driver_ble_read_currentbyte = 0;
std::string driver_ble_readValue;

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *                                                                               * *
* *                                BLE MISSED CALLS                               * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

byte driver_ble_getMissedCalls_readByte(){
  if(driver_ble_read_currentbyte==0 || driver_ble_read_currentbyte>=20){
    BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_missedCalls_characteristic_UUID);
    if(pRemoteCharacteristic==nullptr) return 0x00;
    
    driver_ble_readValue  = pRemoteCharacteristic->readValue();
    driver_ble_read_currentbyte = 0;
  }
  
  driver_ble_read_currentbyte ++;
  return driver_ble_readValue[driver_ble_read_currentbyte-1];
}

void driver_ble_getMissedCalls(){
  
  unsigned char missedCallsNum = driver_ble_getMissedCalls_readByte();

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting missed calls: " + String(missedCallsNum));
  #endif
  long readPosition = 1;
  
  while(missedCallsNum!=0){
    // Has missed calls
    String number = "";
    String name = "";
    String timeDate = "";
    
    uint16_t number_length = (uint16_t)driver_ble_getMissedCalls_readByte();
    for(int i=0; i<number_length; i++){
      number += String((char)driver_ble_getMissedCalls_readByte());
    }

    uint16_t name_length = (uint16_t)driver_ble_getMissedCalls_readByte();
    //debug(name_length);
    for(int i=0; i<name_length; i++){
      name += String((char)driver_ble_getMissedCalls_readByte());
    }

    uint16_t dateTime_length = (uint16_t)driver_ble_getMissedCalls_readByte();
    for(int i=0; i<dateTime_length ; i++){
      timeDate += String((char)driver_ble_getMissedCalls_readByte());
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("Number: " + number);
      debug("Name: " + name);
      debug("Time/Date: " + timeDate);
    #endif

    missedCallsNum--;
  }

  driver_ble_read_currentbyte = 0;

}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *                                                                               * *
* *                               BLE NITIFICATIONS                               * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

byte driver_ble_getNotifications_readByte(){
  if(driver_ble_read_currentbyte==0 || driver_ble_read_currentbyte>=20){
    BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_notifications_characteristic_UUID);
    if(pRemoteCharacteristic==nullptr) return 0x00;
    
    driver_ble_readValue  = pRemoteCharacteristic->readValue();
    driver_ble_read_currentbyte = 0;
  }
  
  driver_ble_read_currentbyte ++;
  return driver_ble_readValue[driver_ble_read_currentbyte-1];
}

void driver_ble_getNotifications(){
  
  unsigned char notificationsNum = driver_ble_getNotifications_readByte();

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting Notifications: ");
    debug(String(notificationsNum));
  #endif
  long readPosition = 1;
  
  while(notificationsNum!=0){
    String nitificationName = "";
    String notificationText = "";
    String timeDate = "";
    
    uint16_t nitificationName_length = (uint16_t)driver_ble_getNotifications_readByte();
    for(int i=0; i<nitificationName_length; i++){
      nitificationName += String((char)driver_ble_getNotifications_readByte());
    }

    uint16_t notificationText_length = (uint16_t)driver_ble_getNotifications_readByte();
    for(int i=0; i<notificationText_length; i++){
      notificationText += String((char)driver_ble_getNotifications_readByte());
    }

    uint16_t dateTime_length = (uint16_t)driver_ble_getNotifications_readByte();
    for(int i=0; i<dateTime_length ; i++){
      timeDate += String((char)driver_ble_getNotifications_readByte());
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      debug("App: " + nitificationName);
      debug("Text: " + notificationText);
      debug("Time/Date: " + timeDate);
    #endif

    notificationsNum--;
  }

  driver_ble_read_currentbyte = 0;

}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *                                                                               * *
* *                                 CURRENT CALL                                  * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

byte driver_ble_getCurrentCall_readByte(){
  if(driver_ble_read_currentbyte==0 || driver_ble_read_currentbyte>=20){
    BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_isCalling_characteristic_UUID);
    if(pRemoteCharacteristic==nullptr) return 0x00;
    
    driver_ble_readValue  = pRemoteCharacteristic->readValue();
    driver_ble_read_currentbyte = 0;
  }
  
  driver_ble_read_currentbyte ++;
  return driver_ble_readValue[driver_ble_read_currentbyte-1];
}

void driver_ble_getCurrentCall(){
  
  byte callingStatus = driver_ble_getCurrentCall_readByte();

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Calling status: ");
    debug(String((int)callingStatus));
  #endif
  long readPosition = 1;
  
  String callingNumber = "";
  String CallingName = "";
  String CallingTime = "";
  
  uint16_t nitificationName_length = (uint16_t)driver_ble_getCurrentCall_readByte();
  for(int i=0; i<nitificationName_length; i++){
    callingNumber += String((char)driver_ble_getCurrentCall_readByte());
  }

  uint16_t notificationText_length = (uint16_t)driver_ble_getCurrentCall_readByte();
  for(int i=0; i<notificationText_length; i++){
    CallingName += String((char)driver_ble_getCurrentCall_readByte());
  }

  uint16_t dateTime_length = (uint16_t)driver_ble_getCurrentCall_readByte();
  for(int i=0; i<dateTime_length ; i++){
    CallingTime += String((char)driver_ble_getCurrentCall_readByte());
  }

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Number: " + callingNumber);
    debug("Name: " + CallingName);
    debug("Duration: " + CallingTime);
  #endif

  driver_ble_read_currentbyte = 0;
}


/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *                                                                               * *
* *                        SETTING DAY STEP AND SLEEP                             * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

void driver_ble_setStepsAndSleep_values(uint32_t steps, uint16_t sleep_min, uint16_t steps_limits, uint16_t sleep_min_limits){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_day_set_steps_sleep_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  byte steps_limits_1 = (steps_limits&0x0000FF00)>>(8*1);
  byte steps_limits_2 = (steps_limits&0x000000FF);

  byte sleep_min_limits_1 = (sleep_min_limits&0x0000FF00)>>(8*1);
  byte sleep_min_limits_2 = (sleep_min_limits&0x000000FF);

  unsigned char hashSum1 = (unsigned char)(step_1 + step_3 + sleep_1 + steps_limits_1 + sleep_min_limits_1);
  unsigned char hashSum2 = (unsigned char)(step_2 + step_4 + sleep_2 + steps_limits_2 + sleep_min_limits_2);

  pRemoteCharacteristic->writeValue({
    step_1,   // 0
    step_2,   // 1
    step_3,   // 2
    step_4,   // 3

    sleep_1,  // 4
    sleep_2,  // 5

    steps_limits_1, // 6
    steps_limits_2, // 7

    sleep_min_limits_1, // 8
    sleep_min_limits_2, // 9

    hashSum1, // 10
    hashSum2, // 11
  });

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Steps and sleep data sended");
  #endif
}

/*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* *                                                                               * *
* *            SENDING WEEK AND DAY STEP/SLEEPS PER DAY AND HOURS                 * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

void driver_ble_setWeekData_values(uint8_t current_day, uint8_t day_shift, uint32_t steps, uint16_t sleep_min){

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_week_data_per_day_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  unsigned char hashSum1 = (unsigned char)(current_day + step_1 + step_3 + sleep_1);
  unsigned char hashSum2 = (unsigned char)(day_shift + step_2 + step_4 + sleep_2);
  
  pRemoteCharacteristic->writeValue({
    current_day,
    day_shift,
    step_1,
    step_2,
    step_3,
    step_4,
    sleep_1,
    sleep_2,
    hashSum1,
    hashSum2,
  });

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    //debug("Week data sended");
  #endif
}

void driver_ble_setDayData_values(uint8_t current_day, uint8_t current_hour, uint8_t hour, uint32_t steps, uint16_t sleep_min){

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_day_date_per_hour_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  unsigned char hashSum1 = (unsigned char)(current_day + hour + step_2 + step_4 + sleep_2);
  unsigned char hashSum2 = (unsigned char)(current_hour + step_1 + step_3 + sleep_1);
  
  pRemoteCharacteristic->writeValue({
    current_day,
    current_hour,
    hour,
    step_1,
    step_2,
    step_3,
    step_4,
    sleep_1,
    sleep_2,
    hashSum1,
    hashSum2,
  });

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    //debug("Day data sentded");
  #endif
}


/*
        # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # #                                                                                                     # # # # #
    # # # #                                                                                                         # # # #
    # # # #                                                 HELPERS!                                                # # # #
    # # # #                                                                                                         # # # #
    # # # # #                                                                                                     # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #  
        # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #   
*/

bool driver_ble_checkgetHashSum(unsigned char hashByte1, unsigned char hashByte2, unsigned char checkHashByte1, unsigned char checkHashByte2){
  if(
    hashByte1==checkHashByte1
    && hashByte2==checkHashByte2
  ) return true;
  else return false;
}

bool driver_ble_checkgetHashSum(uint16_t val1, uint16_t val2){
  if(val1==val2) return true;
  else return false;
}

bool driver_ble_checkgetHashSum(int val, unsigned char hashByte1, unsigned char hashByte2){
  unsigned char checkHashByte1 = ((val>>8)&0xff);
  unsigned char checkHashByte2 = ((val)&0xff);
  return driver_ble_checkgetHashSum(hashByte1, hashByte2, checkHashByte1, checkHashByte2);
}

