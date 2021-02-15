package ru.cubos.emulator;

public class ByteConverter {
    static public byte[] char_to_bytes(char value){
        byte data[] = new byte[2];
        data[1] = (byte) value;
        data[0] = (byte) (value>>> 8);
        return data;
    }

    static public char byte_to_char(byte b1){
        char unsigned_b1 = (char)((char)b1 + 128);
        return unsigned_b1;
    }

    static public char bytesToChar(byte b1, byte b2){
        char unsigned_b1 = (char)((char)b1 + 128);
        char unsigned_b2 = (char)((char)b2 + 128);

        char result = (char)((unsigned_b1 << 8) | unsigned_b2);
        return result;
    }

    // convert to unsigned byte
    static public byte uByte(int signedByte){
        return uByte((byte)signedByte);
    }

    static public byte uByte(byte signedByte){
        return (byte)(signedByte - 128);
    }
}
