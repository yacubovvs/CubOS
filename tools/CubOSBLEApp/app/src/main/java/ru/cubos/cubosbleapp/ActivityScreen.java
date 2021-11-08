package ru.cubos.cubosbleapp;

import android.os.Bundle;
import android.view.MenuItem;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

import ru.cubos.cubosbleapp.customUI.DataSetRecycleViewSet;
import ru.cubos.cubosbleapp.customUI.RecycleViewStatsAdapter;

public class ActivityScreen extends AppCompatActivity {

    private AppBarConfiguration appBarConfiguration;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_activityscreen);


        ActionBar actionBar = getSupportActionBar();

        actionBar.setHomeButtonEnabled(true);
        actionBar.setDisplayHomeAsUpEnabled(true);

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        List<DataSetRecycleViewSet> activityPerHourList = new ArrayList<>();
        activityPerHourList.add(new DataSetRecycleViewSet(1747, "21:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(6789, "22:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(12378, "23:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(20334, "00:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(7543, "01:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(246, "02:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(9364, "03:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(1747, "04:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(6789, "05:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(7543, "06:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(246, "07:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(9364, "08:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(1747, "07:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(6789, "08:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(12378, "09:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(20334, "10:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(7543, "11:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(246, "12:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(9364, "13:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(1747, "14:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(6789, "15:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(12378, "16:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(20334, "17:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(7543, "18:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(246, "19:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(9364, "20:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(1747, "21:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(6789, "22:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(12378, "23:00"));
        activityPerHourList.add(new DataSetRecycleViewSet(20334, "00:00"));


        RecyclerView recyclerView_activityPerHour = findViewById(R.id.recycleView_activityPerHour);
        recyclerView_activityPerHour.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_activityPerHour.setAdapter(new RecycleViewStatsAdapter(this, activityPerHourList, RecycleViewStatsAdapter.TYPE_STEPS));



        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        List<DataSetRecycleViewSet> sleepPerHourList = new ArrayList<>();
        sleepPerHourList.add(new DataSetRecycleViewSet(1747, "21:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(6789, "22:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(12378, "23:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(20334, "00:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(7543, "01:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(246, "02:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(9364, "03:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(1747, "04:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(6789, "05:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(7543, "06:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(246, "07:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(9364, "08:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(1747, "07:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(6789, "08:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(12378, "09:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(20334, "10:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(7543, "11:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(246, "12:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(9364, "13:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(1747, "14:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(6789, "15:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(12378, "16:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(20334, "17:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(7543, "18:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(246, "19:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(9364, "20:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(1747, "21:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(6789, "22:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(12378, "23:00"));
        sleepPerHourList.add(new DataSetRecycleViewSet(20334, "00:00"));


        RecyclerView recyclerView_sleepPerHours = findViewById(R.id.recycleView_sleepPerHour );
        recyclerView_sleepPerHours.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_sleepPerHours.setAdapter(new RecycleViewStatsAdapter(this, sleepPerHourList, RecycleViewStatsAdapter.TYPE_SLEEP));

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        List<DataSetRecycleViewSet> activityPerDayList = new ArrayList<>();
        activityPerDayList.add(new DataSetRecycleViewSet(7543, "30 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(246, "29 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(9364, "28 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(1747, "27 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(6789, "26 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(12378, "25 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(20334, "24 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(7543, "23 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(246, "22 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(9364, "21 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(1747, "20 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(6789, "19 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(12378, "18 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(20334, "17 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(7543, "16 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(246, "15 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(9364, "14 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(1747, "13 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(6789, "12 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(12378, "11 nov"));
        activityPerDayList.add(new DataSetRecycleViewSet(20334, "10 nov"));

        RecyclerView recyclerView_activityPerDay = findViewById(R.id.recycleView_stepsPerDay);
        recyclerView_activityPerDay.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_activityPerDay.setAdapter(new RecycleViewStatsAdapter(this, activityPerDayList, RecycleViewStatsAdapter.TYPE_STEPS));

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        List<DataSetRecycleViewSet> sleepPerDayList = new ArrayList<>();
        sleepPerDayList.add(new DataSetRecycleViewSet(7543, "30 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(246, "29 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(9364, "28 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(1747, "27 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(6789, "26 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(12378, "25 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(20334, "24 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(7543, "23 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(246, "22 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(9364, "21 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(1747, "20 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(6789, "19 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(12378, "18 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(20334, "17 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(7543, "16 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(246, "15 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(9364, "14 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(1747, "13 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(6789, "12 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(12378, "11 nov"));
        sleepPerDayList.add(new DataSetRecycleViewSet(20334, "10 nov"));

        RecyclerView recyclerView_sleepPerDay = findViewById(R.id.recycleView_sleepPerDay);
        recyclerView_sleepPerDay.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_sleepPerDay.setAdapter(new RecycleViewStatsAdapter(this, sleepPerDayList, RecycleViewStatsAdapter.TYPE_SLEEP));

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

}