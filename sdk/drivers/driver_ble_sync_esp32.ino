#include "NimBLEDevice.h"

#define DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT // for exchange debug

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
static BLEUUID  driver_ble_day_steps_sleep_limit_characteristic_UUID ("080a2a2b-0000-1000-8000-00805f9b34fb");

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
        set_core_ble_is_syncing(true);
        xTaskCreatePinnedToCore(
                        driver_ble_BleEsp32SyncTask,
                        "driver_ble_esp32_syncTask",
                        10000,
                        NULL,
                        1,
                        &driver_ble_Task1,
                        0); 
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
    driver_ble_pRemoteService = nullptr;  
    driver_ble_pBLEScan->start(5, false);

    driver_ble_connected = driver_ble_connectToServer();
    if (driver_ble_connected) {
        #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("--Get current time");
        #endif
        driver_ble_getCurrentTime();
        driver_ble_getDataHash();
        #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("--Disconnect");
        #endif
    
        if(current_sync_variant&SYNC_VARIANTS_GET_API_VERSION){
            debug("Sync variant SYNC_VARIANTS_GET_API_VERSION");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_SETTINGS){
            debug("Sync variant SYNC_VARIANTS_GET_SETTINGS");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_CURRENT_TIME){
            debug("Sync variant SYNC_VARIANTS_GET_CURRENT_TIME");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_PEDOMETER_DAY_STEPS_SLEEP_LIMITS){
            debug("Sync variant SYNC_VARIANTS_GET_PEDOMETER_DAY_STEPS_SLEEP_LIMITS");
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_CURRENT_DAY_STEPS_SLEEP){
            debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_CURRENT_DAY_STEPS_SLEEP");
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_DAY_DATA_PER_HOUR){
            debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_DAY_DATA_PER_HOUR");
        }

        if(current_sync_variant&SYNC_VARIANTS_SET_PEDOMETER_WEEK_DATA_PER_DAY){
            debug("Sync variant SYNC_VARIANTS_SET_PEDOMETER_WEEK_DATA_PER_DAY");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_NOTIFICATIONS){
            debug("Sync variant SYNC_VARIANTS_GET_NOTIFICATIONS");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_CURRENT_CALL){
            debug("Sync variant SYNC_VARIANTS_GET_CURRENT_CALL");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_MISSED_CALLS){
            debug("Sync variant SYNC_VARIANTS_GET_MISSED_CALLS");
        }

        if(current_sync_variant&SYNC_VARIANTS_GET_DATA_HASH){
            debug("Sync variant SYNC_VARIANTS_GET_DATA_HASH");
        }

        driver_ble_pClient->disconnect();
    } else {
        #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
            debug("--- Was not connected");
        #endif
    }//*/
    
    driver_ble_connected = false;
    //delete myDevice;
    driver_ble_myDevice = nullptr;

    set_core_ble_is_syncing(false);
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


void driver_ble_getCurrentTime(){
    BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_currentTime_characteristic_UUID);
    if(pRemoteCharacteristic==nullptr) return;
    
    std::string readValue = pRemoteCharacteristic->readValue();

    unsigned char server_month      = readValue[2];
    unsigned char server_date       = readValue[3];
    unsigned char server_dayOfWeek  = readValue[4];
    unsigned char server_hours      = readValue[5];
    unsigned char server_minutes    = readValue[6];
    unsigned char server_seconds    = readValue[7];

    int server_year = readValue[0]|(readValue[1]<<8);

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
    #endif
    
}

void driver_ble_getAPIVersion(){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_apiVersion_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  int api_version = readValue[0]|(readValue[1]<<8);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting server API version: ");
    debug(String((int)api_version));
  #endif
}

void driver_ble_getSettings(){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_settings_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();


  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Pedometer is enable: ");
    //debug((int)pedometer_enable );
  #endif
}

void driver_ble_getDataHash(){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_dataHash_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  uint16_t notifications_hash = readValue[0]|(readValue[1]<<8);
  uint16_t missedcalls_hash = readValue[2]|(readValue[3]<<8);
  uint16_t currentcall_hash = readValue[4];
  uint16_t settings_changed = readValue[5];

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Getting notification hash: ");
    debug(String((uint16_t)notifications_hash));
    debug("Getting missedcalls hash: ");
    debug(String((uint16_t)missedcalls_hash));
    debug("Getting current call hash: ");
    debug(String((uint16_t)currentcall_hash));
    debug("Settings changed flag: ");
    debug(String((uint16_t)settings_changed));
  #endif
  
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
* *                          DAY STEP AND SLEEP LIMITS                            * *
* *                                                                               * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

void driver_ble_getStepSleepLimits(){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_day_steps_sleep_limit_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue  = pRemoteCharacteristic->readValue();

  byte step_limits_enable = readValue[0];
  byte sleep_limits_enable = readValue[1];

  int step_limits = readValue[2]|(readValue[3]<<8);
  int sleep_limits = readValue[4]|(readValue[5]<<8);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    if(step_limits_enable) debug("Step limits on: ");
    else debug("Step limits off:");
    debug(String((int)step_limits) + " steps");

  
    if(sleep_limits_enable) debug("Sleep limits on: ");
    else debug("Sleep limits off: ");
    debug(String((int)sleep_limits) + " minutes");
  #endif
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

void driver_ble_setStepsAndSleep_values(uint32_t steps, uint16_t sleep_min){
  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_day_set_steps_sleep_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  //std::string string = "" + (byte)step_1 + (byte)step_2 + (byte)step_3 + (byte)step_4 + (byte)sleep_1 + (byte)sleep_2;
  
  pRemoteCharacteristic->writeValue({step_1,step_2,step_3,step_4,sleep_1,sleep_2});

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

void driver_ble_setWeekData_values(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint32_t steps, uint16_t sleep_min){

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_week_data_per_day_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  byte year_1 = (year&0xFF00)>>(8*1);
  byte year_2 = (year&0x00FF);
  
  pRemoteCharacteristic->writeValue({
    year_1,
    year_2,
    month,
    day,
    hour,
    step_1,
    step_2,
    step_3,
    step_4,
    sleep_1,
    sleep_2,
  });

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Week data sended");
  #endif
}

void driver_ble_setDayData_values(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint32_t steps, uint16_t sleep_min){

  BLERemoteCharacteristic* pRemoteCharacteristic = driver_ble_pRemoteService->getCharacteristic(driver_ble_day_date_per_hour_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;

  byte step_1 = (steps&0xFF000000)>>(8*3);
  byte step_2 = (steps&0x00FF0000)>>(8*2);
  byte step_3 = (steps&0x0000FF00)>>(8*1);
  byte step_4 = (steps&0x000000FF);

  byte sleep_1 = (sleep_min&0xFF00)>>(8*1);
  byte sleep_2 = (sleep_min&0x00FF);

  byte year_1 = (year&0xFF00)>>(8*1);
  byte year_2 = (year&0x00FF);
  
  pRemoteCharacteristic->writeValue({
    year_1,
    year_2,
    month,
    day,
    hour,
    step_1,
    step_2,
    step_3,
    step_4,
    sleep_1,
    sleep_2,
  });

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    debug("Day data sentded");
  #endif
}
