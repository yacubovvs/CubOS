package ru.cubos.emulator;

public class ByteConverter {
    static public unsigned char[] char_to_bytes(char value){
        unsigned char data[] = new unsigned char[2];
        data[1] = (unsigned char) value;
        data[0] = (unsigned char) (value>>> 8);
        return data;
    }

    static public char byte_to_char(unsigned char b1){
        char unsigned_b1 = (char)((char)b1 + 128);
        return unsigned_b1;
    }

    static public char bytesToChar(unsigned char b1, unsigned char b2){
        char unsigned_b1 = (char)((char)b1 + 128);
        char unsigned_b2 = (char)((char)b2 + 128);

        char result = (char)((unsigned_b1 << 8) | unsigned_b2);
        return result;
    }

    // convert to unsigned unsigned char
    static public unsigned char uByte(int signedByte){
        return uByte((unsigned char)signedByte);
    }

    static public unsigned char uByte(unsigned char signedByte){
        return (unsigned char)(signedByte - 128);
    }
}
