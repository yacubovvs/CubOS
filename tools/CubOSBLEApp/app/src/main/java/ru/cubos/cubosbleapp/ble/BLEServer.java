package ru.cubos.cubosbleapp.ble;

import static android.content.Context.BLUETOOTH_SERVICE;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattServer;
import android.bluetooth.BluetoothGattServerCallback;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothProfile;
import android.bluetooth.le.AdvertiseCallback;
import android.bluetooth.le.AdvertiseData;
import android.bluetooth.le.AdvertiseSettings;
import android.bluetooth.le.BluetoothLeAdvertiser;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.ParcelUuid;
import android.util.Log;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;
import java.util.UUID;

import ru.cubos.cubosbleapp.MainActivity;
import ru.cubos.cubosbleapp.R;
import ru.cubos.cubosbleapp.helpers.Common;

public class BLEServer extends BluetoothGattServerCallback {

    /* Bluetooth API */
    public BluetoothManager mBluetoothManager;
    private BluetoothGattServer mBluetoothGattServer;
    private BluetoothLeAdvertiser mBluetoothLeAdvertiser;
    /* Collection of notification subscribers */
    private Set<BluetoothDevice> mRegisteredDevices = new HashSet<>();
    Context context;

    public BLEServer(Context context){
        super();
        this.context = context;
        mBluetoothManager = (BluetoothManager) context.getSystemService(BLUETOOTH_SERVICE);
        BluetoothAdapter bluetoothAdapter = mBluetoothManager.getAdapter();
        //luetoothAdapter.
        // We can't continue without proper Bluetooth support
        /*
        if (!checkBluetoothSupport(bluetoothAdapter)) {
            //activity.finish();
        }*/

        // Register for system Bluetooth events

        IntentFilter filter = new IntentFilter(BluetoothAdapter.ACTION_STATE_CHANGED);
        context.registerReceiver(mBluetoothReceiver, filter);
        if (!bluetoothAdapter.isEnabled()) {
            bluetoothAdapter.enable();
        } else {
            startAdvertising();
            startServer();
        }
    }

    /* Service UUID */
    public static UUID CUBOS_SERVICE = UUID.fromString("000a1805-0000-1000-8000-00805f9b34fb");
    /* Characteristics */

    public static UUID CURRENT_TIME             = UUID.fromString("00aa2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID NOTIFICATIONS            = UUID.fromString("00ba2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID MISSED_CALLS             = UUID.fromString("00ca2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID IS_CALLING               = UUID.fromString("00da2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID DATA_HASH                = UUID.fromString("00ea2a2b-0000-1000-8000-00805f9b34fb"); // Changed when one of data changed
    public static UUID API_VERSION              = UUID.fromString("00fa2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID ALARMS                   = UUID.fromString("010a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID SETTINGS                 = UUID.fromString("030a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID DAY_SET_STEPS_SLEEP      = UUID.fromString("020a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID DAY_DATA_PER_HOURS       = UUID.fromString("040a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID WEEK_DATA_PER_DAYS       = UUID.fromString("060a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID DAY_STEPS_SLEEP_LIMIT    = UUID.fromString("080a2a2b-0000-1000-8000-00805f9b34fb");
    public static UUID DISCONNECT               = UUID.fromString("090a2a2b-0000-1000-8000-00805f9b34fb");


    public static BluetoothGattService createTimeService() {
        BluetoothGattService service = new BluetoothGattService(CUBOS_SERVICE,  BluetoothGattService.SERVICE_TYPE_PRIMARY);

        BluetoothGattCharacteristic dataHash = new BluetoothGattCharacteristic(DATA_HASH, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        //BluetoothGattDescriptor dataHashDescriptor = new BluetoothGattDescriptor(DATA_HASH, BluetoothGattDescriptor.PERMISSION_READ);
        //dataHash.addDescriptor(dataHashDescriptor);
        service.addCharacteristic(dataHash);

        BluetoothGattCharacteristic currentTime = new BluetoothGattCharacteristic(CURRENT_TIME, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(currentTime);

        BluetoothGattCharacteristic notifications = new BluetoothGattCharacteristic(NOTIFICATIONS, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(notifications);

        BluetoothGattCharacteristic missedCalls = new BluetoothGattCharacteristic(MISSED_CALLS, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(missedCalls);

        BluetoothGattCharacteristic alarms = new BluetoothGattCharacteristic(ALARMS, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(alarms);

        BluetoothGattCharacteristic isCalling = new BluetoothGattCharacteristic(IS_CALLING, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(isCalling);

        BluetoothGattCharacteristic apiVersion = new BluetoothGattCharacteristic(API_VERSION, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(apiVersion);

        BluetoothGattCharacteristic stepSleepLimits = new BluetoothGattCharacteristic(DAY_STEPS_SLEEP_LIMIT, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(stepSleepLimits);

        BluetoothGattCharacteristic dayStepsSleep = new BluetoothGattCharacteristic(DAY_SET_STEPS_SLEEP, BluetoothGattCharacteristic.PROPERTY_WRITE, BluetoothGattCharacteristic.PERMISSION_WRITE);
        service.addCharacteristic(dayStepsSleep);

        BluetoothGattCharacteristic weekDataPerDay = new BluetoothGattCharacteristic(WEEK_DATA_PER_DAYS, BluetoothGattCharacteristic.PROPERTY_WRITE, BluetoothGattCharacteristic.PERMISSION_WRITE);
        service.addCharacteristic(weekDataPerDay);

        BluetoothGattCharacteristic dayDataPerDay = new BluetoothGattCharacteristic(DAY_DATA_PER_HOURS, BluetoothGattCharacteristic.PROPERTY_WRITE, BluetoothGattCharacteristic.PERMISSION_WRITE);
        service.addCharacteristic(dayDataPerDay);

        BluetoothGattCharacteristic settings = new BluetoothGattCharacteristic(SETTINGS, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(settings);

        BluetoothGattCharacteristic disconnect = new BluetoothGattCharacteristic(DISCONNECT, BluetoothGattCharacteristic.PROPERTY_READ, BluetoothGattCharacteristic.PERMISSION_READ);
        service.addCharacteristic(disconnect);

        return service;
    }

    private boolean checkBluetoothSupport(BluetoothAdapter bluetoothAdapter) {

        if (bluetoothAdapter == null) {
            return false;
        }

        if (!context.getPackageManager().hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE)) {
            return false;
        }

        return true;
    }


    @Override
    public void onConnectionStateChange(BluetoothDevice device, int status, int newState) {
        if (newState == BluetoothProfile.STATE_CONNECTED) {
            Log.d("BLE_log", "Somebody CONNECTED");
        } else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
            //Remove device from any active subscriptions
            Log.d("BLE_log", "Somebody DISCONNECTED");
            mRegisteredDevices.remove(device);
        }
    }

    /*
    *  VARIABLES FOR SENDING LONG MESSAGES (more than 20 bytes) +
    * */

    int missed_calls_current_position_message = 0;
    byte[] missed_calls_message = null;

    int unread_notifications_current_position_message = 0;
    byte[] unread_notifications_message = null;

    int currentCall_current_position_message = 0;
    byte[] currentCall_message = null;

    /*
     *  VARIABLES FOR SENDING LONG MESSAGES (more than 20 bytes) -
     * */



    @Override
    public void onCharacteristicReadRequest(BluetoothDevice device, int requestId, int offset, BluetoothGattCharacteristic characteristic) {

        Log.d("BLE_log", "Something was read");
        if (BLEServer.CURRENT_TIME.equals(characteristic.getUuid())) {
            long now = System.currentTimeMillis();
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    Time.getExactTime(now, Time.ADJUST_NONE)
            );
        } else if (BLEServer.DATA_HASH.equals(characteristic.getUuid())) {
            missed_calls_current_position_message = 0;
            missed_calls_message = null;
            unread_notifications_current_position_message = 0;
            unread_notifications_message = null;
            currentCall_current_position_message = 0;
            currentCall_message = null;

            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    // Structure:
                    // byte[0xFF, 0xFF, 0xFF, 0xFF] - random bytes
                    new byte[]{
                            0x01, 0x02,  // - notification hash code
                            0x02, 0x02,  // - missed calls hash code
                            0x01,       // - current call hash
                            0x03,       // - settings changed flag
                    }
            );

            MainActivity.mainActivity.preferences.putInt("last_DateUpdate", (new Date()).getDate());
            MainActivity.mainActivity.updateLastSync();
        }
        else if (BLEServer.DISCONNECT.equals(characteristic.getUuid())){
             //device.
        }
        else if (BLEServer.SETTINGS.equals(characteristic.getUuid())){

            boolean pedometerOn         = MainActivity.mainActivity.preferences.getBoolean("switch_usePedometer", true);
            boolean syncTime            = MainActivity.mainActivity.preferences.getBoolean("switch_syncTime", true);
            boolean autosyncOnCharge    = MainActivity.mainActivity.preferences.getBoolean("switch_autosyncOnCharge", true);
            int stepsLimit = MainActivity.mainActivity.preferences.getInt("last_stepsLimits", 7000);
            int sleepLimit = MainActivity.mainActivity.preferences.getInt("last_sleepLimits", 480);
            byte screenOffTime = (byte) MainActivity.mainActivity.preferences.getInt("last_screenOffTime", 10);
            byte screenOffClock = (byte) MainActivity.mainActivity.preferences.getInt("last_screenOffClock", 3);

            byte stepsLimit_1 = (byte) (stepsLimit&0xFF);
            byte stepsLimit_2 = (byte) (stepsLimit>>8&0xFF);
            byte sleepLimit_1 = (byte) (sleepLimit&0xFF);
            byte sleepLimit_2 = (byte) (sleepLimit>>8&0xFF);

            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    new byte[]{
                            (byte) (pedometerOn?0x01:0x00),  // - 0x00 - pedometer off, 0x01 - pedometer on
                            (byte) (syncTime?0x01:0x00),
                            (byte) (autosyncOnCharge?0x01:0x00),
                            stepsLimit_1,
                            stepsLimit_2,
                            sleepLimit_1,
                            sleepLimit_2,
                            screenOffTime,
                            screenOffClock
                    }
            );
        }
        else if (BLEServer.IS_CALLING.equals(characteristic.getUuid())) {
            //currentCall_current_position_message = 0;
            //currentCall_message = null;

            if(currentCall_current_position_message==0) currentCall_message = CurrentCall.getCurrentCall();
            if(currentCall_current_position_message==-1){
                mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, new byte[0x00]);
                return;
            }

            byte[] message_new = new byte[20];

            for (int i = 0; i < 20; i++) {
                message_new[i] = currentCall_message[currentCall_current_position_message];
                currentCall_current_position_message++;
                if (currentCall_current_position_message >= currentCall_message.length){
                    mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);
                    currentCall_current_position_message = -1;
                    break;
                }
            }

            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);

            if (currentCall_current_position_message >= currentCall_message.length){
                currentCall_current_position_message = -1;
            }

            /*
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                CurrentCall.getCurrentCall()
            );
            */
        }
        else if (BLEServer.MISSED_CALLS.equals(characteristic.getUuid())) {

            if(missed_calls_current_position_message==0) missed_calls_message = MissedCalls.getMissedCallsMessage();
            if(missed_calls_current_position_message==-1){
                mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, new byte[0x00]);
                return;
            }

            byte[] message_new = new byte[20];

            for (int i = 0; i < 20; i++) {
                message_new[i] = missed_calls_message[missed_calls_current_position_message];
                missed_calls_current_position_message++;
                if (missed_calls_current_position_message >= missed_calls_message.length){
                    mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);
                    missed_calls_current_position_message = -1;
                    break;
                }
            }

            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);

            if (missed_calls_current_position_message >= missed_calls_message.length){
                missed_calls_current_position_message = -1;
            }

        }
        else if (BLEServer.NOTIFICATIONS.equals(characteristic.getUuid())) {

            if(unread_notifications_current_position_message==0) unread_notifications_message = Notifications.getUnreadNotifications();
            if(unread_notifications_current_position_message==-1){
                mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, new byte[0x00]);
                return;
            }

            byte[] message_new = new byte[20];

            for (int i = 0; i < 20; i++) {
                message_new[i] = unread_notifications_message[unread_notifications_current_position_message];
                unread_notifications_current_position_message++;
                if (unread_notifications_current_position_message >= unread_notifications_message.length){
                    mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);
                    unread_notifications_current_position_message = -1;
                    break;
                }
            }

            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, message_new);

            if (unread_notifications_current_position_message >= unread_notifications_message.length){
                unread_notifications_current_position_message = -1;
            }

        }
        else if (BLEServer.API_VERSION.equals(characteristic.getUuid())) {
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    // Structure:
                    // byte[0x00, 0x01] - version
                    new byte[]{0x01,0x00} // version 1
            );
        }
        else if (BLEServer.ALARMS.equals(characteristic.getUuid())) {
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    // Structure:
                    // byte[0x00, 0x01] - version
                    new byte[]{0x01,0x02,0x0a}
            );
        }
        else if (BLEServer.DAY_STEPS_SLEEP_LIMIT.equals(characteristic.getUuid())) {
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0,
                    // Structure:
                    // byte[0x00, 0x01] - version
                    DayLimits.getDayLimits()
            );
        }
        else{
            mBluetoothGattServer.sendResponse(device, requestId, BluetoothGatt.GATT_SUCCESS, 0, new byte[0x01]);
        }

        /*else if (TimeProfile.LOCAL_TIME_INFO.equals(characteristic.getUuid())) {
            mBluetoothGattServer.sendResponse(device,
                    requestId,
                    BluetoothGatt.GATT_SUCCESS,
                    0,
                    TimeProfile.getLocalTimeInfo(now));
        } else {
            // Invalid characteristic
            mBluetoothGattServer.sendResponse(device,
                    requestId,
                    BluetoothGatt.GATT_FAILURE,
                    0,
                    null);
        }*/
    }

    public void onCharacteristicWriteRequest(BluetoothDevice device, int requestId, BluetoothGattCharacteristic characteristic, boolean preparedWrite, boolean responseNeeded, int offset, byte[] value) {
        //Log.d("BLE_log", "DataGot " + value);
        if(BLEServer.DAY_SET_STEPS_SLEEP.equals(characteristic.getUuid())){

            int day_steps = ((value[0]&0xFF)<<24) | ((value[1]&0xFF)<<16) | ((value[2]&0xFF)<<8) | (value[3]&0xFF);
            int sleep_minutes = ((value[4]&0xFF)<<8) | (value[5]&0xFF);
            int steps_limit = ((value[6]&0xFF)<<8) | (value[7]&0xFF);
            int sleep_limit = ((value[8]&0xFF)<<8) | (value[9]&0xFF);

            if(MainActivity.mainActivity!=null) {
                MainActivity.mainActivity.setCurrentSteps(day_steps, steps_limit);
                MainActivity.mainActivity.setCurrentSleepTime(sleep_minutes, sleep_limit);
            }

        }
        else if(BLEServer.WEEK_DATA_PER_DAYS.equals(characteristic.getUuid())){
            /*
            current_day,
            day_shift,
            step_1,
            step_2,
            step_3,
            step_4,
            sleep_1,
            sleep_2,
            */

            int current_day = (value[0]&0xFF);
            int day_shift = (value[1]&0xFF);

            int steps = ((value[2]&0xFF)<<24) | ((value[3]&0xFF)<<16) | ((value[4]&0xFF)<<8) | (value[5]&0xFF);
            int sleep = ((value[6]&0xFF)<<8) | (value[7]&0xFF);

            boolean checkDay = Common.isDateInACurrentDay(current_day);
            if(checkDay){
                Date logDate = Common.shiftDate(Common.getStartOfDay(new Date()), -day_shift, 0);
                DateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH");
                String string_user = df.format(logDate);

                Log.d("BLE_log", "DAY_DATA_PER_HOURS current_day: " + current_day);
                MainActivity.mainActivity.dbHelper.insert_day_pedometer_data(string_user, steps, sleep);
            }else{
                //TODO: Show alert to sync time
            }


            //MainActivity.mainActivity.dbHelper.insert_day_pedometer_data("2021-11-" + Common.fillZero(thisDay, 2) + "-00", 10, (int) (0.1*60));
            //MainActivity.mainActivity.dbHelper.insert_hour_pedometer_data("2021-11-" + Common.fillZero((thisDay - 2), 2) + "-04", 30, (int) (0.5*60));
            /*
            StepSleepHistory.addWeekData(
                StepSleepHistory.getDateHash(year, month, day, hour, 0, 0),
                StepSleepHistory.getDate(year, month, day, hour, 0, 0),
                sleep,
                steps
            );*/

            //Log.d("BLE_log", "DataGot " + (new String(value)));
        }
        else if(BLEServer.DAY_DATA_PER_HOURS.equals(characteristic.getUuid())){

            /*
            0: current_day,
            1: current_hour,
            2: hour,
            3: step_1,
            4: step_2,
            5: step_3,
            6: step_4,
            7: sleep_1,
            8: sleep_2,
            */

            int current_day = (value[0]&0xFF);
            int current_hour = (value[1]&0xFF);
            int hour_shift = (value[2]&0xFF);

            int steps = ((value[3]&0xFF)<<24) | ((value[4]&0xFF)<<16) | ((value[5]&0xFF)<<8) | (value[6]&0xFF);
            int sleep = ((value[7]&0xFF)<<8) | (value[8]&0xFF);

            boolean checkDay = Common.isDateInACurrentDay(current_day);
            if(checkDay){
                Date current_date = Common.getStartOfDay(new Date());
                current_date.setHours(current_hour);
                Date logDate = Common.shiftDate(current_date, 0, -hour_shift);

                DateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH");
                String string_user = df.format(logDate);

                Log.d("BLE_log", "DAY_DATA_PER_HOURS hour_shift: " + hour_shift);
                MainActivity.mainActivity.dbHelper.insert_hour_pedometer_data(string_user, steps, sleep);
            }else{
                //TODO: Show alert to sync time
            }
            /*
            StepSleepHistory.addDayData(
                    StepSleepHistory.getDateHash(year, month, day, hour, 0, 0),
                    StepSleepHistory.getDate(year, month, day, hour, 0, 0),
                    sleep,
                    steps
            );
            */

            //Log.d("BLE_log", "DataGot " + (new String(value)));
        }

    }

    @Override
    public void onDescriptorReadRequest(BluetoothDevice device, int requestId, int offset,
                                        BluetoothGattDescriptor descriptor) {

            /*
            if (TimeProfile.DATA_HASH.equals(descriptor.getUuid())) {
                mBluetoothGattServer.sendResponse(device,
                        requestId,
                        BluetoothGatt.GATT_SUCCESS,
                        0,
                        new byte[]{0x01,0x02,0x04});
            }
            */
            /*
            if (TimeProfile.CLIENT_CONFIG.equals(descriptor.getUuid())) {
                byte[] returnValue;
                if (mRegisteredDevices.contains(device)) {
                    returnValue = BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE;
                } else {
                    returnValue = BluetoothGattDescriptor.DISABLE_NOTIFICATION_VALUE;
                }
                mBluetoothGattServer.sendResponse(device,
                        requestId,
                        BluetoothGatt.GATT_FAILURE,
                        0,
                        returnValue);
            } else {
                mBluetoothGattServer.sendResponse(device,
                        requestId,
                        BluetoothGatt.GATT_FAILURE,
                        0,
                        null);
            }*/

    }

    @Override
    public void onDescriptorWriteRequest(BluetoothDevice device, int requestId,
                                         BluetoothGattDescriptor descriptor,
                                         boolean preparedWrite, boolean responseNeeded,
                                         int offset, byte[] value) {

        Log.d("BLE_log", "onDescriptorWriteRequest");
        if (DAY_SET_STEPS_SLEEP.equals(descriptor.getUuid())) {

            /*
            if (Arrays.equals(BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE, value)) {
                mRegisteredDevices.add(device);
            } else if (Arrays.equals(BluetoothGattDescriptor.DISABLE_NOTIFICATION_VALUE, value)) {
                mRegisteredDevices.remove(device);
            }

            if (responseNeeded) {
                mBluetoothGattServer.sendResponse(device,
                        requestId,
                        BluetoothGatt.GATT_SUCCESS,
                        0,
                        null);
            }
            */
        }
            /*
            if (TimeProfile.CLIENT_CONFIG.equals(descriptor.getUuid())) {
                if (Arrays.equals(BluetoothGattDescriptor.ENABLE_NOTIFICATION_VALUE, value)) {
                    mRegisteredDevices.add(device);
                } else if (Arrays.equals(BluetoothGattDescriptor.DISABLE_NOTIFICATION_VALUE, value)) {
                    mRegisteredDevices.remove(device);
                }

                if (responseNeeded) {
                    mBluetoothGattServer.sendResponse(device,
                            requestId,
                            BluetoothGatt.GATT_SUCCESS,
                            0,
                            null);
                }
            } else {
                if (responseNeeded) {
                    mBluetoothGattServer.sendResponse(device,
                            requestId,
                            BluetoothGatt.GATT_FAILURE,
                            0,
                            null);
                }
            }
            */
    }

    public BroadcastReceiver mBluetoothReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            Log.d("BLE_log", "mBluetoothReceiver");
            int state = intent.getIntExtra(BluetoothAdapter.EXTRA_STATE, BluetoothAdapter.STATE_OFF);

            switch (state) {
                case BluetoothAdapter.STATE_ON:
                    startAdvertising();
                    startServer();
                    break;
                case BluetoothAdapter.STATE_OFF:
                    stopServer();
                    stopAdvertising();
                    break;
                default:
                    // Do nothing
            }

        }
    };

    private void startAdvertising() {
        BluetoothAdapter bluetoothAdapter = mBluetoothManager.getAdapter();
        mBluetoothLeAdvertiser = bluetoothAdapter.getBluetoothLeAdvertiser();
        if (mBluetoothLeAdvertiser == null) {
            return;
        }

        AdvertiseSettings settings = new AdvertiseSettings.Builder()
                .setAdvertiseMode(AdvertiseSettings.ADVERTISE_MODE_BALANCED)
                .setConnectable(true)
                .setTimeout(0)
                .setTxPowerLevel(AdvertiseSettings.ADVERTISE_TX_POWER_MEDIUM)
                .build();

        AdvertiseData data = new AdvertiseData.Builder()
                .setIncludeDeviceName(true)
                .setIncludeTxPowerLevel(false)
                .addServiceUuid(new ParcelUuid(BLEServer.CUBOS_SERVICE))
                .build();

        mBluetoothLeAdvertiser.startAdvertising(settings, data, mAdvertiseCallback);
    }

    /**
     * Stop Bluetooth advertisements.
     */
    public void stopAdvertising() {
        if (mBluetoothLeAdvertiser == null) return;

        mBluetoothLeAdvertiser.stopAdvertising(mAdvertiseCallback);
    }

    /**
     * Initialize the GATT server instance with the services/characteristics
     * from the Time Profile.
     */
    private void startServer() {
        //mBluetoothGattServer = mBluetoothManager.openGattServer(this.context, mGattServerCallback);
        mBluetoothGattServer = mBluetoothManager.openGattServer(this.context, this);
        if (mBluetoothGattServer == null) {
            return;
        }

        mBluetoothGattServer.addService(BLEServer.createTimeService());

        // Initialize the local UI
        //updateLocalUi(System.currentTimeMillis());
    }

    /**
     * Shut down the GATT server.
     */
    public void stopServer() {
        if (mBluetoothGattServer == null) return;
        mBluetoothGattServer.close();
    }

    /**
     * Callback to receive information about the advertisement process.
     */
    private AdvertiseCallback mAdvertiseCallback = new AdvertiseCallback() {
        @Override
        public void onStartSuccess(AdvertiseSettings settingsInEffect) {
            return;
        }

        @Override
        public void onStartFailure(int errorCode) {
            return;
        }
    };

    /**
     * Send a time service notification to any devices that are subscribed
     * to the characteristic.
     */
    private void notifyRegisteredDevices(long timestamp, byte adjustReason) {
        if (mRegisteredDevices.isEmpty()) {
            return;
        }
        byte[] exactTime = Time.getExactTime(timestamp, adjustReason);

        for (BluetoothDevice device : mRegisteredDevices) {
            BluetoothGattCharacteristic timeCharacteristic = mBluetoothGattServer
                    .getService(BLEServer.CUBOS_SERVICE)
                    .getCharacteristic(BLEServer.CURRENT_TIME);
            timeCharacteristic.setValue(exactTime);
            mBluetoothGattServer.notifyCharacteristicChanged(device, timeCharacteristic, false);
        }
    }

    /**
     * Update graphical UI on devices that support it with the current time.
     */
    /*
    private void updateLocalUi(long timestamp) {
        Date date = new Date(timestamp);
        String displayDate = DateFormat.getMediumDateFormat(this.context).format(date)
                + "\n"
                + DateFormat.getTimeFormat(this.context).format(date);
        //mLocalTimeView.setText(displayDate);
    }*/

    /**
     * Callback to handle incoming requests to the GATT server.
     * All read/write requests for characteristics and descriptors are handled here.
     */
    /*
    private BluetoothGattServerCallback mGattServerCallback = new BluetoothGattServerCallback() {


    };*/

    public BroadcastReceiver serverBLEReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            /*
            Log.d("BLE_log", "BroadcastReceiver 1");
            byte adjustReason;
            switch (intent.getAction()) {
                case Intent.ACTION_TIME_CHANGED:
                    adjustReason = Time.ADJUST_MANUAL;
                    break;
                case Intent.ACTION_TIMEZONE_CHANGED:
                    adjustReason = Time.ADJUST_TIMEZONE;
                    break;
                default:
                case Intent.ACTION_TIME_TICK:
                    adjustReason = Time.ADJUST_NONE;
                    break;
            }
            long now = System.currentTimeMillis();
            notifyRegisteredDevices(now, adjustReason);
            //updateLocalUi(now);*/
        }
    };
}
