bool core_ble_setted_up = false;
bool get_core_ble_setted_up(){return core_ble_setted_up;}
void set_core_ble_setted_up(bool value){core_ble_setted_up = value;}

void core_ble_sync_setup(){
    if(!get_core_ble_setted_up()){
        set_core_ble_setted_up(true);
        //debug("Start ble sriver setup " + String(millis()));
        driver_ble_sync_setup();
        //debug("Finish ble sriver setup " + String(millis()));
    }
}

/*
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                       SYNC SETTINGS +                       #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

RTC_DATA_ATTR bool core_ble_sync_time = true;
RTC_DATA_ATTR bool core_ble_auto_sync_on_charge = true;

bool get_core_ble_sync_time(){return core_ble_sync_time;}
bool get_core_ble_auto_sync_on_charge(){return core_ble_auto_sync_on_charge;}
void set_core_ble_sync_time(bool value){core_ble_sync_time = value;}
void set_core_ble_auto_sync_on_charge(bool value){core_ble_auto_sync_on_charge = value;}

/*
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                       SYNC SETTINGS -                       #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
*/

void core_ble_sync_loop(){
    
}

bool core_ble_sync_start(){
    if(!get_core_ble_is_syncing()){
        //set_core_ble_is_syncing(true);
        debug("Sync started");

        driver_ble_start_sync(SYNC_VARIANTS_GET_API_VERSION|SYNC_VARIANTS_GET_SETTINGS|SYNC_VARIANTS_GET_CURRENT_TIME|SYNC_VARIANTS_GET_DATA_HASH);
    }

    
}

unsigned char syncStatus = 0x00;
void core_ble_set_syncStatus(unsigned char syncStatusIn){syncStatus = syncStatusIn;}
unsigned char core_ble_get_syncStatus(){return syncStatus;}
String core_ble_get_syncStatus_String(){

    switch(syncStatus){
        case SYNC_STATUS_NOT_STARTED:
            return "Syncing"; break;
        case SYNC_STATUS_CONNECTING:
            return "Connecting"; break;
        case SYNC_STATUS_IN_PROGRESS:
            return "In progress"; break;
        case SYNC_STATUS_FINISHED:
            return "Finished"; break;
        case SYNC_STATUS_ERROR_SERVER_NOT_FOUND:
            return "Server not found"; break;
        case SYNC_STATUS_ERROR_DIFFERENT_API_VERSIONS:
            return "API error"; break;
        case SYNC_STATUS_ERROR_EXCHANGE_FAILED:
            return "Failed"; break;
        case SYNC_STATUS_ERROR_UNKNOWN:
            return "Unknown error"; break;
    }
}

bool core_ble_is_syncing = false;
void set_core_ble_is_syncing(bool isSyncing){core_ble_is_syncing = isSyncing;}
bool get_core_ble_is_syncing(){return core_ble_is_syncing;}

bool core_ble_sync_error = false;
void set_core_ble_sync_error(bool syncError){core_ble_sync_error = syncError;}
bool get_core_ble_sync_error(){return core_ble_sync_error;}

