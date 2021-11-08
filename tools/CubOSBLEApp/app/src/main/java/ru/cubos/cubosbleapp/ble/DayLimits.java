
package ru.cubos.cubosbleapp.ble;

public class DayLimits {
    static byte[] getDayLimits(){
        byte step_limits_enable = 0x01; // 0x01 - enable, 0x00 - not disable
        int steps_limit = 7000; // 65000 max
        byte sleep_limits_enable = 0x01; // 0x01 - enable, 0x00 - not disable
        int sleep_limits = 680; // in minutes

        byte[] message = new byte[7];

        message[0] = (byte) step_limits_enable;
        message[1] = (byte) sleep_limits_enable;

        message[2] = (byte) (steps_limit & 0xFF);
        message[3] = (byte) ((steps_limit >> 8) & 0xFF);

        message[4] = (byte) (sleep_limits & 0xFF);
        message[5] = (byte) ((sleep_limits >> 8) & 0xFF);

        return message;
    }
}
