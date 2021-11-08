/*
 * Copyright 2017, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package ru.cubos.cubosbleapp.ble;
import java.util.Calendar;

/**
 * Implementation of the Bluetooth GATT Time Profile.
 * https://www.bluetooth.com/specifications/adopted-specifications
 */
public class Time {
    private static final String TAG = "BLE_Server timeProfile";


    // Adjustment Flags
    public static final byte ADJUST_NONE     = 0x0;
    public static final byte ADJUST_MANUAL   = 0x1;
    public static final byte ADJUST_EXTERNAL = 0x2;
    public static final byte ADJUST_TIMEZONE = 0x4;
    public static final byte ADJUST_DST      = 0x8;

    /**
     * Return a configured {@link BluetoothGattService} instance for the
     * Current Time Service.
     */


    /**
     * Construct the field values for a Current Time characteristic
     * from the given epoch timestamp and adjustment reason.
     */
    public static byte[] getExactTime(long timestamp, byte adjustReason) {
        Calendar time = Calendar.getInstance();
        time.setTimeInMillis(timestamp);

        byte[] field = new byte[10];


        int year = time.get(Calendar.YEAR);
        field[0] = (byte) (year & 0xFF);                                // Year - byte 1
        field[1] = (byte) ((year >> 8) & 0xFF);                         // Year - byte 2
        field[2] = (byte) (time.get(Calendar.MONTH) + 1);               // Month
        field[3] = (byte) time.get(Calendar.DATE);                      // Day
        field[4] = getDayOfWeekCode(time.get(Calendar.DAY_OF_WEEK));    // Day of week
        field[5] = (byte) time.get(Calendar.HOUR_OF_DAY);               // Hour
        field[6] = (byte) time.get(Calendar.MINUTE);                    // Minutes
        field[7] = (byte) time.get(Calendar.SECOND);                    // Seconds
        // Day of Week (1-7)
        // Fractions256
        //field[4] = (byte) time.get(Calendar.HOUR_OF_DAY);
        //field[8] = (byte) (time.get(Calendar.MILLISECOND) / 256);
        //field[9] = adjustReason;
        return field;
    }



    /* Bluetooth Weekday Codes */
    private static final byte DAY_UNKNOWN = 0;
    private static final byte DAY_MONDAY = 1;
    private static final byte DAY_TUESDAY = 2;
    private static final byte DAY_WEDNESDAY = 3;
    private static final byte DAY_THURSDAY = 4;
    private static final byte DAY_FRIDAY = 5;
    private static final byte DAY_SATURDAY = 6;
    private static final byte DAY_SUNDAY = 7;

    /**
     * Convert a {@link Calendar} weekday value to the corresponding
     * Bluetooth weekday code.
     */
    private static byte getDayOfWeekCode(int dayOfWeek) {
        switch (dayOfWeek) {
            case Calendar.MONDAY:
                return DAY_MONDAY;
            case Calendar.TUESDAY:
                return DAY_TUESDAY;
            case Calendar.WEDNESDAY:
                return DAY_WEDNESDAY;
            case Calendar.THURSDAY:
                return DAY_THURSDAY;
            case Calendar.FRIDAY:
                return DAY_FRIDAY;
            case Calendar.SATURDAY:
                return DAY_SATURDAY;
            case Calendar.SUNDAY:
                return DAY_SUNDAY;
            default:
                return DAY_UNKNOWN;
        }
    }

    /* Bluetooth DST Offset Codes */
    private static final byte DST_STANDARD = 0x0;
    private static final byte DST_HALF     = 0x2;
    private static final byte DST_SINGLE   = 0x4;
    private static final byte DST_DOUBLE   = 0x8;
    private static final byte DST_UNKNOWN = (byte) 0xFF;

}
