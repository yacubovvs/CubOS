
#include "NimBLEDevice.h"
#include "soc/rtc_wdt.h"

#undef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT

// The remote service we wish to connect to.
static BLEUUID serviceUUID("000a1805-0000-1000-8000-00805f9b34fb");

// The characteristic of the remote service we are interested in.
static BLEUUID  currentTime_characteristic_UUID           ("00aa2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  notifications_characteristic_UUID         ("00ba2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  missedCalls_characteristic_UUID           ("00ca2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  isCalling_characteristic_UUID             ("00da2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  dataHash_characteristic_UUID              ("00ea2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  apiVersion_characteristic_UUID            ("00fa2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  alarms_characteristic_UUID                ("010a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  day_set_steps_sleep_characteristic_UUID   ("020a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  settings_characteristic_UUID              ("030a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  day_date_per_hour_characteristic_UUID     ("040a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  week_data_per_day_characteristic_UUID     ("060a2a2b-0000-1000-8000-00805f9b34fb");
static BLEUUID  day_steps_sleep_limit_characteristic_UUID ("080a2a2b-0000-1000-8000-00805f9b34fb");

static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;

static void notifyCallback(BLERemoteCharacteristic* pBLERemoteCharacteristic, uint8_t* pData, size_t length, bool isNotify) {
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.print("Notify callback for characteristic ");
      Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
      Serial.print(" of data length ");
      Serial.println(length);
      Serial.print("data: ");
      Serial.println((char*)pData);
    #endif
}
class MyClientCallback : public BLEClientCallbacks {
  void onConnect(BLEClient* pclient) {
  }

  void onDisconnect(BLEClient* pclient) {
    connected = false;
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("onDisconnect");
    #endif
  }

  uint32_t onPassKeyRequest(){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("Client PassKeyRequest");
    #endif
    return 123456; 
  }
  bool onConfirmPIN(uint32_t pass_key){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.print("The passkey YES/NO number: ");Serial.println(pass_key);
    #endif
    return true; 
  }

  void onAuthenticationComplete(ble_gap_conn_desc desc){
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("Starting BLE work!");
    #endif
  }

};

BLERemoteService* pRemoteService;
BLEClient*  pClient;

bool connectToServer() {
    //pClient = nullptr;

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("---connectToServer 1");
    #endif

    if(myDevice!=nullptr){
      pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
    }else{
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        Serial.println("myDevice==nulptp");
      #endif
      return false;
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("---connectToServer 2");
    #endif
    
    pRemoteService = pClient->getService(serviceUUID);
    
    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial .println("---connectToServer 3");
     #endif
     
    if (pRemoteService == nullptr) {
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        Serial.print("Failed to find our service UUID: ");
        Serial.println(serviceUUID.toString().c_str());
      #endif
      pClient->disconnect();
      //pClient = nullptr;
      return false;
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("---connectToServer 4");
    #endif
    BLEDevice::getScan()->clearResults();

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.println("---connectToServer 5");
    #endif
    connected = true;
    return true;
}

/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {

 
  void onResult(BLEAdvertisedDevice* advertisedDevice) {
    if (advertisedDevice->haveServiceUUID() && advertisedDevice->isAdvertisingService(serviceUUID)) {
      BLEDevice::getScan()->stop();
      myDevice = advertisedDevice;
      doScan = true;
    }
  }
};


void setup() {
  Serial.begin(115200);
  Serial.println("Starting Arduino BLE Client application... Press Enter to begin");

  init_BLE();
  init_BLE_SCAN();

  client_init();
  //init_BLE();
  while(Serial.available()<=0){}

  //rtc_wdt_protect_off();
  //rtc_wdt_disable();
  //disableCore0WDT();
  //disableLoopWDT();

  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());
  
  //esp_task_wdt_delete(NULL)
} // End of setup.

void client_init(){
  pClient  = BLEDevice::createClient();

  //pClient->clearClientCallbacks();
  pClient->setClientCallbacks(new MyClientCallback(), true);
}

void deinit_BLE(){
  BLEDevice::deinit(true);
}

void init_BLE(){
  BLEDevice::init("");
}

BLEScan* pBLEScan;
void init_BLE_SCAN(){
  //BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan = BLEDevice::getScan();
  pBLEScan->clearAdvertisedDeviceCallbacks();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);  
}

TaskHandle_t Task1;
bool driver_ble_sync_in_progress = false;

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());

  if(driver_ble_sync_in_progress==false){
    Serial.println("=== Starting new sync task");
    driver_ble_sync_in_progress=true;
    //vTaskDelete(NULL);
    xTaskCreatePinnedToCore(
                    driver_ble_BleEsp32SyncTask,   /* Функция задачи. */
                    "driver_ble_esp32_syncTask",     /* Ее имя. */
                    10000,       /* Размер стека функции */
                    NULL,        /* Параметры */
                    1,           /* Приоритет */
                    &Task1,      /* Дескриптор задачи для отслеживания */
                    0);          /* Указываем пин для данного ядра */          
  }

  delay(1000);
  //driver_ble_startSync();
  
} 


void driver_ble_BleEsp32SyncTask( void * pvParameters ){
  //delay(10000);
  driver_ble_startSync();
  driver_ble_sync_in_progress=false;
  vTaskDelete(NULL);
}




void driver_ble_startSync(){  
  pRemoteService = nullptr;
  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.println("--Scan");
  #endif
  
  pBLEScan->start(5, false);
  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.println("# # # # # # # # # # # # # # # #");
    Serial.println(ESP.getFreeHeap());
    Serial.println("# # # # # # # # # # # # # # # #");
  #endif

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.println("--Connect");
  #endif
  connected = connectToServer();
  if (connected) {
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        Serial.println("--Get current time");
      #endif
      driver_ble_getCurrentTime();
      driver_ble_getDataHash();
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        Serial.println("--Disconnect");
      #endif
      pClient->disconnect();
  } else {
      #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
        Serial.println("--- Was not connected");
      #endif
  }//*/
  
  connected = false;
  //delete myDevice;
  myDevice = nullptr;

  //Serial.println("Going to sleep");
  //Serial.flush();
  //esp_sleep_enable_timer_wakeup(100*1000);
  //esp_light_sleep_start();
  //Serial.println("Wake up");
  //delay(100); // Delay a second between loops.
}


void driver_ble_getCurrentTime(){
    BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(currentTime_characteristic_UUID);
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
      Serial.println("Getting current time: ");
      Serial.print("Year: ");
      Serial.print((int)server_year);
      Serial.print(", month: ");
      Serial.print((byte)server_month);
      Serial.print(", day: ");
      Serial.print((byte)server_date);
      Serial.print(", day of week: ");
      Serial.print((byte)server_dayOfWeek);
      Serial.print(", hours: ");
      Serial.print((byte)server_hours);
      Serial.print(", minutes: ");
      Serial.print((byte)server_minutes);
      Serial.print(", seconds: ");
      Serial.print((byte)server_seconds);
      Serial.println("");
    #endif
    
}

void driver_ble_getAPIVersion(){
  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(apiVersion_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  int api_version = readValue[0]|(readValue[1]<<8);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.print("Getting server API version: ");
    Serial.print((int)api_version);
    Serial.println("");
  #endif
}

void driver_ble_getSettings(){
  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(settings_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();


  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.print("Pedometer is enable: ");
    //Serial.print((int)pedometer_enable );
    Serial.println("");
  #endif
}

void driver_ble_getDataHash(){
  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(dataHash_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue = pRemoteCharacteristic->readValue();

  uint16_t notifications_hash = readValue[0]|(readValue[1]<<8);
  uint16_t missedcalls_hash = readValue[2]|(readValue[3]<<8);
  uint16_t currentcall_hash = readValue[4];
  uint16_t settings_changed = readValue[5];

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.print("Getting notification hash: ");
    Serial.println((uint16_t)notifications_hash);
    Serial.print("Getting missedcalls hash: ");
    Serial.println((uint16_t)missedcalls_hash);
    Serial.print("Getting current call hash: ");
    Serial.println((uint16_t)currentcall_hash);
    Serial.print("Settings changed flag: ");
    Serial.println((uint16_t)settings_changed);
    Serial.println("");
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
    BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(missedCalls_characteristic_UUID);
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
    Serial.print("Getting missed calls: ");
    Serial.print(missedCallsNum);
    Serial.println(" calls");
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
    //Serial.println(name_length);
    for(int i=0; i<name_length; i++){
      name += String((char)driver_ble_getMissedCalls_readByte());
    }

    uint16_t dateTime_length = (uint16_t)driver_ble_getMissedCalls_readByte();
    for(int i=0; i<dateTime_length ; i++){
      timeDate += String((char)driver_ble_getMissedCalls_readByte());
    }

    #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
      Serial.print("Number: " + number);
      Serial.print(", Name: " + name);
      Serial.print(", Time/Date: " + timeDate);
      Serial.println();
    #endif

    missedCallsNum--;
  }

  driver_ble_read_currentbyte = 0;

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    Serial.println();
  #endif
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
    BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(notifications_characteristic_UUID);
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
    Serial.print("Getting Notifications: ");
    Serial.print(notificationsNum);
    Serial.println("");
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
      Serial.print("App: " + nitificationName);
      Serial.print(", Text: " + notificationText);
      Serial.print(", Time/Date: " + timeDate);
      Serial.println();
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
    BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(isCalling_characteristic_UUID);
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
    Serial.print("Calling status: ");
    Serial.print((int)callingStatus );
    Serial.println("");
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
    Serial.print("Number: " + callingNumber);
    Serial.print(", Name: " + CallingName);
    Serial.print(", Duration: " + CallingTime);
    Serial.println();
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
  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(day_steps_sleep_limit_characteristic_UUID);
  if(pRemoteCharacteristic==nullptr) return;
  
  std::string readValue  = pRemoteCharacteristic->readValue();

  byte step_limits_enable = readValue[0];
  byte sleep_limits_enable = readValue[1];

  int step_limits = readValue[2]|(readValue[3]<<8);
  int sleep_limits = readValue[4]|(readValue[5]<<8);

  #ifdef DEBUG_DRIVER_BLE_PRINT_INCONNECT_OUTPUT
    if(step_limits_enable) Serial.print("Step limits on: ");
    else Serial.print("Step limits off:");
    Serial.print((int)step_limits);
    Serial.println(" steps");
  
    if(sleep_limits_enable) Serial.print("Sleep limits on: ");
    else Serial.print("Sleep limits off: ");
    Serial.print((int)sleep_limits);
    Serial.println(" minutes");
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
  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(day_set_steps_sleep_characteristic_UUID);
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
    Serial.println("Steps and sleep data sended");
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

  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(week_data_per_day_characteristic_UUID);
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
    Serial.println("Week data sended");
  #endif
}

void driver_ble_setDayData_values(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint32_t steps, uint16_t sleep_min){

  BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(day_date_per_hour_characteristic_UUID);
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
    Serial.println("Day data sentded");
  #endif
}
