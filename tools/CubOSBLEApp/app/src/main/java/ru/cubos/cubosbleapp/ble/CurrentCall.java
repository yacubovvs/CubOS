package ru.cubos.cubosbleapp.ble;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class CurrentCall {
    public static byte[] getCurrentCall(){

        byte currentCallHash = 0x01; //0x00 - is not calling, 0x01 - is calling, 0x02 - now speaking
        int messageSize = 1;

        List<String> messageStrings = new ArrayList<>();
        String number = "1239653798673";
        messageSize += number.length() + 1;
        messageStrings.add(number); // phone number max length 127 chars

        String name = "Yacubov Vitaly";
        messageSize += name.length() + 1;
        messageStrings.add(name); // caller name max length 127 chars

        String callDuration = "120";
        messageSize += callDuration.length() + 1;
        messageStrings.add(callDuration); // caller name max length 127 chars

        byte[] message = new byte[messageSize];

        int currentArrayPosition = 0;
        message[currentArrayPosition] = (byte)currentCallHash;
        currentArrayPosition++;

        for(String string: messageStrings){
            byte[] stringToCopy = string.getBytes(StandardCharsets.US_ASCII);
            message[currentArrayPosition] = (byte)stringToCopy.length;
            currentArrayPosition++;

            System.arraycopy(stringToCopy, 0, message, currentArrayPosition, stringToCopy.length); //message.
            /*
            for(int ii=0; ii<stringToCopy.length; ii++){
                message[currentArrayPosition+ii] = stringToCopy[ii];
            }*/

            currentArrayPosition += stringToCopy.length;
        }



        return message;
    }
}
