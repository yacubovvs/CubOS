package ru.cubos.cubosbleapp;

import androidx.appcompat.app.AppCompatActivity;
import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.content.IntentFilter;
import android.icu.text.DateFormat;
import android.icu.text.SimpleDateFormat;
import android.os.Bundle;
import android.view.WindowManager;
import android.widget.TextView;

import java.util.Date;
import java.util.Locale;

import ru.cubos.cubosbleapp.ble.BLEServer;
import ru.cubos.cubosbleapp.helpers.Preferences;


public class MainActivity extends AppCompatActivity {
    //private static final String TAG = "BLE_Server MainActivity";

    static public MainActivity mainActivity;
    static public Preferences preferences;
    private TextView mLocalTimeView;
    BLEServer bleServer;
    TextView lastTimeSync;

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
        CommonObjects.mainActivity = this;

        lastTimeSync = findViewById(R.id.lastTimeSync);

        updateLastSyncFromMemory();
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


    public void setCurrentSteps(int steps){
        //((TextView)findViewById(R.id.bleSteps)).setText(steps + " steps");
    }

    public void setCurrentSleepTime(int sleepTime){
        int minutes = sleepTime%60;
        int hours = (sleepTime - minutes)/60;
        //((TextView)findViewById(R.id.bleSleepHours)).setText(hours + " hours " + minutes + " minutes");
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