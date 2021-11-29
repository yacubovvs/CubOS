package ru.cubos.cubosbleapp;

import android.os.Bundle;
import android.view.MenuItem;
import android.widget.CompoundButton;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;

public class Settings extends AppCompatActivity {

    Switch switch_syncTime;
    Switch switch_usePedometer;
    Switch switch_autosyncOnCharge;
    SeekBar seekBar_stepsLimit;
    SeekBar seekBar_sleepLimit;
    SeekBar seekBar_screenOffTime;
    SeekBar seekBar_screenOffClock;

    TextView label_stepsLimit;
    TextView label_sleepLimit;
    TextView label_screenOffTime;
    TextView label_screenOffClock;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        ActionBar actionBar = getSupportActionBar();

        actionBar.setHomeButtonEnabled(true);
        actionBar.setDisplayHomeAsUpEnabled(true);

        switch_syncTime = findViewById(R.id.switch_syncTime);
        switch_usePedometer = findViewById(R.id.switch_usePedometer);
        switch_autosyncOnCharge = findViewById(R.id.switch_autosyncOnCharge);

        switch_syncTime.setChecked(MainActivity.mainActivity.preferences.getBoolean("switch_syncTime", true));
        switch_usePedometer.setChecked(MainActivity.mainActivity.preferences.getBoolean("switch_usePedometer", true));
        switch_autosyncOnCharge.setChecked(MainActivity.mainActivity.preferences.getBoolean("switch_autosyncOnCharge", true));

        seekBar_stepsLimit = findViewById(R.id.seekBar_stepsLimit);
        seekBar_sleepLimit = findViewById(R.id.seekBar_sleepLimit);
        seekBar_screenOffTime = findViewById(R.id.seekBar_screenOffTime);
        seekBar_screenOffClock = findViewById(R.id.seekBar_screenOffClock);

        label_stepsLimit = findViewById(R.id.label_stepsLimit);
        label_sleepLimit = findViewById(R.id.label_sleepLimit);
        label_screenOffTime = findViewById(R.id.label_screenOffTime);
        label_screenOffClock = findViewById(R.id.label_screenOffClock);

        //setLabelStepsLimit(stepLimit);

        setListeners();

        seekBar_stepsLimit.setProgress(MainActivity.mainActivity.preferences.getInt("last_progress_stepsLimit", 20));
        seekBar_sleepLimit.setProgress(MainActivity.mainActivity.preferences.getInt("last_progress_sleepLimit", 40));
        seekBar_screenOffTime.setProgress(MainActivity.mainActivity.preferences.getInt("last_progress_screenOffTime", 5));
        seekBar_screenOffClock.setProgress(MainActivity.mainActivity.preferences.getInt("last_progress_screenOffClock", 3));

    }

    void setLabelStepsLimit(int stepLimit){
        label_stepsLimit.setText("" + stepLimit + " steps");
    }

    void setLabelSleepLimit(int sleepLimit){
        int minutes = sleepLimit%60;
        int hours = (sleepLimit - minutes)/60;

        label_sleepLimit.setText("" + hours + " hours " + minutes + " minutes");
    }

    void setLabelScreenTimeOff(int screenOffTime){

        if(screenOffTime==0){
            label_screenOffTime.setText("Never");
        } else {
            int seconds = screenOffTime%60;
            int minutes = (screenOffTime - seconds)/60;
            label_screenOffTime.setText("" + minutes + " minutes " + seconds + " seconds");
        }
    }


    void setLabelScreenOffClock(int screenOffClock){
        if(screenOffClock==0){
            label_screenOffTime.setText("Default");
        } else {
            int seconds = screenOffClock%60;
            int minutes = (screenOffClock - seconds)/60;
            label_screenOffClock.setText("" + minutes + " minutes " + seconds + " seconds");
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                this.finish();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    void setListeners(){
        switch_syncTime.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                MainActivity.mainActivity.preferences.putBoolean("switch_syncTime", isChecked);
            }
        });

        switch_usePedometer.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                MainActivity.mainActivity.preferences.putBoolean("switch_usePedometer", isChecked);
            }
        });

        switch_autosyncOnCharge.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                MainActivity.mainActivity.preferences.putBoolean("switch_autosyncOnCharge", isChecked);
            }
        });

        seekBar_stepsLimit.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int max = 30000;
                int min = 1000;
                int stepLimit = ((max - min)  * progress /100 + min)/500*500;

                MainActivity.mainActivity.preferences.putInt("last_stepsLimit_bg", stepLimit);
                MainActivity.mainActivity.preferences.putInt("last_progress_stepsLimit", progress);
                setLabelStepsLimit(stepLimit);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        seekBar_sleepLimit.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int max = 960;
                int min = 120;
                int sleepLimit = ((max - min)  * progress /100 + min)/10*10;

                MainActivity.mainActivity.preferences.putInt("last_sleepLimit", sleepLimit);
                MainActivity.mainActivity.preferences.putInt("last_progress_sleepLimit", progress);
                setLabelSleepLimit(sleepLimit);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        seekBar_screenOffTime.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int max = 120;
                int min = 1;
                int screenOffTime = ((max - min)  * progress /100 + min);

                MainActivity.mainActivity.preferences.putInt("last_progress_screenOffTime", progress);

                if(progress==100){
                    MainActivity.mainActivity.preferences.putInt("last_screenOffTime", 0);
                    setLabelScreenTimeOff(0);
                } else {
                    MainActivity.mainActivity.preferences.putInt("last_screenOffTime", screenOffTime);
                    setLabelScreenTimeOff(screenOffTime);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        seekBar_screenOffClock.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int max = 120;
                int min = 1;
                int screenOffTime = ((max - min)  * progress /100 + min);

                MainActivity.mainActivity.preferences.putInt("last_progress_screenOffClock", progress);

                if(progress==100){
                    MainActivity.mainActivity.preferences.putInt("last_screenOffClock", 0);
                    setLabelScreenOffClock(0);
                } else {
                    MainActivity.mainActivity.preferences.putInt("last_screenOffClock", screenOffTime);
                    setLabelScreenOffClock(screenOffTime);
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

    }

}