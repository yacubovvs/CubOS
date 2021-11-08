package ru.cubos.cubosbleapp.ble;

import java.util.Date;
import java.util.HashMap;

public class StepSleepHistory {
    static public HashMap<String, HistoryElement> weekData = new HashMap<>();
    static public HashMap<String, HistoryElement> dayData = new HashMap<>();

    public static int current_steps = 0;
    public static int getCurrent_sleep = 0;

    static public void addWeekData(String date_hash, Date date, int sleep, int steps){
        weekData.put(date_hash, new HistoryElement(sleep, steps, date));
    }

    static public void addDayData(String date_hash, Date date, int sleep, int steps){
        dayData.put(date_hash, new HistoryElement(sleep, steps, date));
    }

    static public Date getDate(int year, int month, int day, int hour, int minute, int second){
        Date date = new Date();
        date.setYear(year);
        date.setMonth(month);
        date.setDate(day);
        date.setHours(hour);
        date.setMinutes(minute);
        date.setSeconds(second);

        return date;
    }

    static public String getDateHash(int year, int month, int day, int hour, int minute, int second){
        String hash = "" + year + "." + month + "." + day + " " + hour + ":" + minute + ":" + second;
        return hash;
    }

    public static class HistoryElement{
        public int sleep = 0;
        public int steps = 0;
        public Date date;

        public HistoryElement(int sleep, int steps, Date date){
            this.sleep = sleep;
            this.steps = steps;
            this.date = date;
        }
    }
}
