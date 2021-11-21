package ru.cubos.cubosbleapp.ble;

public class HashSum {
    static byte[] getHashSum(int val){
        byte hashB[] = new byte[]{
                (byte) ((val>>8)&0xff),
                (byte) ((val)&0xff),
        };
        return hashB;
    }

    static byte[] getHashSum(int val1, int val2){
        byte hashB[] = new byte[]{
                (byte) (val1&0xff),
                (byte) (val2&0xff),
        };
        return hashB;
    }
}
