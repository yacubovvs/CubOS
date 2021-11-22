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

    static boolean checkHashSum(int val1, int val2, int hashVal1, int hashVal2){
        return ((val1&0xff)==(hashVal1&0xff) && (val2&0xff)==(hashVal2&0xff));
    }
}
