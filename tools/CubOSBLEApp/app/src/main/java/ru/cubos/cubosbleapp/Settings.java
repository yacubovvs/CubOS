package ru.cubos.cubosbleapp;

import android.os.Bundle;
import android.view.MenuItem;
import android.widget.CompoundButton;
import android.widget.Switch;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

public class Settings extends AppCompatActivity {

    Switch switch_syncTime;
    Switch switch_usePedometer;
    Switch switch_autosyncOnCharge;

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

        setListeners();
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
    }

}