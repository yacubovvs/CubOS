package ru.cubos.cubosbleapp.helpers;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.List;

import ru.cubos.cubosbleapp.data.DBSleepStepsData;

public class DBHelper extends SQLiteOpenHelper {
    final static int dbVer = 5;
    static SQLiteDatabase db = null;


    Context mContext;

    public DBHelper(Context context){
        super(context, "db.db", null, DBHelper.dbVer);
        //super.onCreate();
        mContext = context;
        db = this.getWritableDatabase();

        final String CREATE_TABLE_1 = "CREATE TABLE IF NOT EXISTS DaysData (\n" +
                "  date_d VARCHAR(13) PRIMARY KEY,\n" +
                "  steps Integer,\n" +
                "  sleep_min Integer\n" +
                ");";
        final String CREATE_TABLE_2 = "CREATE TABLE IF NOT EXISTS HoursData (\n" +
                "  date_d VARCHAR(13) PRIMARY KEY,\n" +
                "  steps Integer,\n" +
                "  sleep_min Integer\n" +
                ");";

        db.execSQL(CREATE_TABLE_1);
        db.execSQL(CREATE_TABLE_2);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

    }

    public void insert_day_pedometer_data(String date, int steps, int sleep_min){
        if(steps!=0 && sleep_min!=0) {
            db.execSQL("DELETE FROM DaysData WHERE date_d = \"" + date + "\";");
            db.execSQL("INSERT INTO DaysData (date_d, steps, sleep_min) VALUES( \"" + date + "\", " + steps + ", " + sleep_min + ");");
        }
    }

    public void insert_hour_pedometer_data(String date, int steps, int sleep_min){
        if(steps!=0 && sleep_min!=0) {
            db.execSQL("DELETE FROM HoursData WHERE date_d = \"" + date + "\";");
            db.execSQL("INSERT INTO HoursData (date_d, steps, sleep_min) VALUES( \"" + date + "\", " + steps + ", " + sleep_min + ");");
        }
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        //проверяете какая версия сейчас и делаете апдейт
        db.execSQL("DROP TABLE IF EXISTS DaysData");
        db.execSQL("DROP TABLE IF EXISTS HoursData");
        onCreate(db);
    }

    public HashMap<String, DBSleepStepsData> getLastDaysData(int daysValue){
        String query = "SELECT date_d, steps, sleep_min FROM DaysData ORDER BY date_d DESC LIMIT 0," + daysValue + "";
        Cursor cursor = db.rawQuery(query, null);

        HashMap<String, DBSleepStepsData> data = new HashMap<>();

        while (cursor.moveToNext()){
            DBSleepStepsData db_data = new DBSleepStepsData();
            db_data.steps = cursor.getInt(1);
            db_data.sleep_min = cursor.getInt(2);
            String date_string = cursor.getString(0);

            //if(date_string.length()!=13) continue;

            /*
            try {
                int year = Integer.parseInt(date_string.substring(0, 4));
                int month = Integer.parseInt(date_string.substring(5,7)) - 1;
                int day = Integer.parseInt(date_string.substring(8,10));
                int hour = Integer.parseInt(date_string.substring(11,13));

                db_data.date = new Date(year - 1900, month-1, day, hour, 0);
            }catch(Exception e){
                continue;
            }*/

            data.put(date_string, db_data);
        }
        return data;
    }

    public HashMap<String, DBSleepStepsData> getLastHoursData(int hoursValue){
        String query = "SELECT date_d, steps, sleep_min FROM HoursData ORDER BY date_d DESC LIMIT 0," + hoursValue + "";
        Cursor cursor = db.rawQuery(query, null);

        HashMap<String, DBSleepStepsData> data = new HashMap<>();

        while (cursor.moveToNext()){
            DBSleepStepsData db_data = new DBSleepStepsData();
            db_data.steps = cursor.getInt(1);
            db_data.sleep_min = cursor.getInt(2);
            String date_string = cursor.getString(0);

            //if(date_string.length()!=13) continue;

            /*
            try {
                int year = Integer.parseInt(date_string.substring(0, 4));
                int month = Integer.parseInt(date_string.substring(5,7)) - 1;
                int day = Integer.parseInt(date_string.substring(8,10));
                int hour = Integer.parseInt(date_string.substring(11,13));

                db_data.date = new Date(year - 1900, month-1, day, hour, 0);
            }catch(Exception e){
                continue;
            }*/

            data.put(date_string, db_data);
        }
        return data;
    }

}