package ru.cubos.cubosbleapp.ble;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

public class Notifications {
    public static byte[] getUnreadNotifications(){
        byte notificationsNum = 3;
        List<String> messageStrings = new ArrayList<>();
        int totalMessageLength = 1;

        for(int i=0; i<notificationsNum; i++){
            String message_appName = "Application 00" + i;
            message_appName = message_appName.substring(0,Math.min(message_appName.length(), 127)); // 256 chars - max length of appname
            String message_notificationText = "Long long notification of application. Long long notification of application. ------------- " + i + " -------------- Long long notification of application. Long long notification of application. Long long notification of application. Long long notification of application. Long long notification of application.";
            message_notificationText = message_notificationText.substring(0,Math.min(message_notificationText.length(), 127)); // 256 chars - max length of text in this message
            String message_date_time = "2021.10.31 20:48:1" + i;

            messageStrings.add(message_appName); // App name
            messageStrings.add(message_notificationText); // Notification text
            messageStrings.add(message_date_time); // Date/time

            totalMessageLength += message_appName.length() + message_notificationText.length() + message_date_time.length() + 3;
        }

        byte[] message = new byte[totalMessageLength];
        int currentArrayPosition = 0;
        message[currentArrayPosition] = (byte)notificationsNum;
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

        /*
        public static void arraycopy(
            Object src, //:source array, in this case A
            int srcPos, //:the start index for copy, typically 0
            Object dest, //:destination object in this case B.
            int destPos, //:the index to place the copied elements
            int length //:the length of the contents to be copied
        );
        * */

        //s.getBytes(StandardCharsets.US_ASCII);
        return message;
    }
}
