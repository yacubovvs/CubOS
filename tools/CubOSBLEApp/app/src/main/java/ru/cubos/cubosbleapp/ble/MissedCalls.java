package ru.cubos.cubosbleapp.ble;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class MissedCalls {
    public static byte[] getMissedCallsMessage(){

        byte missedCalsNum = 8;
        List<String> messageStrings = new ArrayList<>();
        int totalMessageLength = 1;

        for(int i=0; i<missedCalsNum; i++){
            String message_number = "123956379867" + i;
            String message_name = "Yacubov Vitaly" + i;
            message_name = message_name.substring(0,Math.min(message_name.length(), 127)); // 256 chars - max length of name in this message
            String message_date_time = "2021.10.31 20:48:1" + i;

            messageStrings.add(message_number); // Phone number
            messageStrings.add(message_name); // Name
            messageStrings.add(message_date_time); // Date/time

            totalMessageLength += message_number.length() + message_name.length() + message_date_time.length() + 3;
        }

        byte[] message = new byte[totalMessageLength];
        int currentArrayPosition = 0;
        message[currentArrayPosition] = (byte)missedCalsNum;
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

        //s.getBytes(StandardCharsets.US_ASCII);
        return message;
    }
}
