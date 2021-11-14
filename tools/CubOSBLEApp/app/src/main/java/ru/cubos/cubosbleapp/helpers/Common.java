package ru.cubos.cubosbleapp.helpers;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Common {
    static public String fillZero(int value, int length){
        String outValue = "" + value;

        if(value<0) return outValue;
        if(outValue.length()>=length) return outValue;

        for(int i=0; i<length-1; i++){
            outValue = "0" + outValue;
        }

        return outValue.substring(outValue.length()-length, outValue.length());
    }

    public static Date getStartOfDay(Date date) {
        Calendar calendar = Calendar.getInstance();
        int year = calendar.get(Calendar.YEAR);
        int month = calendar.get(Calendar.MONTH);
        int day = calendar.get(Calendar.DATE);
        calendar.set(date.getYear() + 1900, date.getMonth(), date.getDate(), 0, 0, 0);
        return calendar.getTime();
    }

    public static Date getStartOfHour(Date date) {
        Calendar calendar = Calendar.getInstance();
        int year = calendar.get(Calendar.YEAR);
        int month = calendar.get(Calendar.MONTH);
        int day = calendar.get(Calendar.DATE);
        int hour = calendar.get(Calendar.HOUR_OF_DAY);
        calendar.set(date.getYear() + 1900, date.getMonth(), date.getDate(), hour, 0, 0);
        return calendar.getTime();
    }

    public static boolean isDateInACurrentDay(int day){
        Calendar currentCal = Calendar.getInstance();
        currentCal.setTime(new Date());

        if(day==currentCal.getTime().getDate()) return true;
        return false;
    }

    public static Date shiftDate(Date date, int days, int hours){
        Calendar cal = Calendar.getInstance();
        cal.setTime(date);
        cal.add(Calendar.DATE, days);
        cal.add(Calendar.HOUR_OF_DAY, hours);
        return cal.getTime();
    }

    public static String dateToHashString(Date date){
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH");
        return df.format(date);
    }
}
