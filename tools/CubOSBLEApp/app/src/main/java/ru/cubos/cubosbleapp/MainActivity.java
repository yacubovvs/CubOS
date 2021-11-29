package ru.cubos.cubosbleapp;

import androidx.appcompat.app.AppCompatActivity;
import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;

import ru.cubos.cubosbleapp.ble.BLEServer;
import ru.cubos.cubosbleapp.customUI.CircleCart;
import ru.cubos.cubosbleapp.data.DBSleepStepsData;
import ru.cubos.cubosbleapp.helpers.Common;
import ru.cubos.cubosbleapp.helpers.DBHelper;
import ru.cubos.cubosbleapp.helpers.Preferences;


public class MainActivity extends AppCompatActivity {
    //private static final String TAG = "BLE_Server MainActivity";

    static public MainActivity mainActivity;
    static public Preferences preferences;
    private TextView mLocalTimeView;
    BLEServer bleServer;
    TextView lastTimeSync;
    Button btn_settings;
    Button btn_activity_history;
    CircleCart sleepstepchart;

    TextView steps_labels;
    TextView step_percents_label;
    TextView sleep_min_label;
    TextView sleep_min_percents_label;
    TextView calories_label;

    public DBHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mainActivity = this;
        preferences = new Preferences(getBaseContext());

        //CurrentCall.getCurrentCall();

        //Intent intent = new Intent(this, Settings.class);
        //this.startActivity(intent);

        bleServer = new BLEServer(getBaseContext());
        setContentView(R.layout.activity_main);

        //mLocalTimeView = (TextView) findViewById(R.id.logText);
        // Devices with a display should not go to sleep
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        MainActivity.mainActivity = this;

        dbHelper = new DBHelper(getBaseContext());


        lastTimeSync = findViewById(R.id.lastTimeSync);

        steps_labels = findViewById(R.id.steps_labels);
        step_percents_label = findViewById(R.id.step_percents_label);
        sleep_min_label = findViewById(R.id.sleep_min_label);
        sleep_min_percents_label = findViewById(R.id.sleep_min_percents_label);
        calories_label = findViewById(R.id.calories_label);

        btn_settings = findViewById(R.id.btn_settings);
        btn_activity_history = findViewById(R.id.btn_activity_history);
        sleepstepchart = findViewById(R.id.sleepstepchart);

        btn_settings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, Settings.class);
                MainActivity.this.startActivity(intent);
            }
        });
        btn_activity_history.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, ActivityScreen.class);
                MainActivity.this.startActivity(intent);
            }
        });

        int sleepTimeLimits     = preferences.getInt("last_sleepLimit", 400);
        int stepsLimits         = preferences.getInt("last_stepsLimit_bg", 7500);

        int lastDateUpdate = preferences.getInt("last_DateUpdate", 0);
        int currentDate = (new Date()).getDate();
        if(lastDateUpdate!=currentDate){
            setCurrentSteps(0, stepsLimits);
            setCurrentSleepTime(0, sleepTimeLimits);
        }else{
            int sleepTime           = preferences.getInt("last_sleepTime", 0);
            int steps               = preferences.getInt("last_steps", 0);

            setCurrentSleepTime(sleepTime, sleepTimeLimits);
            setCurrentSteps(steps, stepsLimits);
        }

        updateLastSyncFromMemory();

        //Intent intent = new Intent(this, ActivityScreen.class);
        //this.startActivity(intent);
    }

    /*
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        //getMenuInflater().inflate(R.menu.settings, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here.
        int id = item.getItemId();


        if (id == R.id.settings_menu) {
            //process your onClick here
            Intent intent = new Intent(this, Settings.class);
            startActivity(intent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }*/

    @Override
    protected void onStart() {
        super.onStart();
        // Register for system clock events
        IntentFilter filter = new IntentFilter();
        filter.addAction(Intent.ACTION_TIME_TICK);
        filter.addAction(Intent.ACTION_TIME_CHANGED);
        filter.addAction(Intent.ACTION_TIMEZONE_CHANGED);
        registerReceiver(bleServer.serverBLEReceiver, filter);
    }

    @Override
    protected void onStop() {
        super.onStop();
        unregisterReceiver(bleServer.serverBLEReceiver);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        BluetoothAdapter bluetoothAdapter = bleServer.mBluetoothManager.getAdapter();
        if (bluetoothAdapter.isEnabled()) {
            bleServer.stopServer();
            bleServer.stopAdvertising();
        }

        unregisterReceiver(bleServer.mBluetoothReceiver);
    }


    public void setCurrentSteps(int steps, int stepsLimits){
        preferences.putInt("last_steps", steps);
        preferences.putInt("last_stepsLimit_bg", stepsLimits);

        steps_labels.setText("" + steps + "/" + stepsLimits + " steps");
        calories_label.setText("" + (int)((float)steps*0.033f) + " kcal");

        float k; if(stepsLimits==0) k = 0; else k = (float)steps/(float)stepsLimits;

        step_percents_label.setText("" +  (int)(k *100) + "% steps");
        sleepstepchart.setCurrentStepsK(k);
    }

    public void setCurrentSleepTime(int sleepTime, int sleepTimeLimits){
        preferences.putInt("last_sleepTime",  sleepTime);
        preferences.putInt("last_sleepLimit", sleepTimeLimits);

        int minutes = sleepTime%60;
        int hours = (sleepTime - minutes)/60;

        int minutes_limit = sleepTimeLimits%60;
        int hours_limit = (sleepTimeLimits - minutes_limit)/60;

        sleep_min_label.setText("" + hours + "h " + minutes + "min / " + hours_limit + "h " + minutes_limit + "min");

        float k; if(sleepTimeLimits==0) k = 0; else k = (float)sleepTime/(float)sleepTimeLimits;

        sleep_min_percents_label.setText("" +  (int)(k*100) + "% sleep time");
        sleepstepchart.setCurrentSleepTimeK(k);
    }

    public void updateLastSync(){
        Date currentDate = new Date();
        DateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy HH:mm:ss", Locale.getDefault());
        String lastSyncDate_string = dateFormat.format(currentDate);

        preferences.putString("lastSyncDate_string", lastSyncDate_string);

        updateLastSyncFromMemory();
    }

    void updateLastSyncFromMemory(){
        lastTimeSync.setText(preferences.getString("lastSyncDate_string", "Connect your CubOS device to the charging for syncing"));
    }

}