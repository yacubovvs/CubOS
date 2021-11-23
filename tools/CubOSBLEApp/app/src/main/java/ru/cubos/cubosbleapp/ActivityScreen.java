package ru.cubos.cubosbleapp;

import android.os.Build;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageButton;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.List;

import ru.cubos.cubosbleapp.customUI.DataSetRecycleViewSet;
import ru.cubos.cubosbleapp.customUI.RecycleViewStatsAdapter;
import ru.cubos.cubosbleapp.data.DBSleepStepsData;
import ru.cubos.cubosbleapp.helpers.Common;

public class ActivityScreen extends AppCompatActivity {

    private AppBarConfiguration appBarConfiguration;
    ImageButton activityPerHour_back_btn;
    ImageButton activityPerHour_next_btn;
    ImageButton sleepPerHour_back_btn;
    ImageButton sleepPerHour_next_btn;
    ImageButton stepsPerDay_back_btn;
    ImageButton stepsPerDay_next_btn;
    ImageButton sleepPerDay_back_btn;
    ImageButton sleepPerDay_next_btn;

    RecyclerView recyclerView_activityPerHour;
    RecyclerView recyclerView_activityPerDay;
    RecyclerView recyclerView_sleepPerDay;
    RecyclerView recyclerView_sleepPerHours;
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
        List<DataSetRecycleViewSet> sleepPerHourList = new ArrayList<>();

        HashMap<String, DBSleepStepsData> hourData = MainActivity.mainActivity.dbHelper.getLastHoursData(48);

        int hoursInChart = 48;
        Date currentDateTime = Common.getStartOfHour(new Date());
        for(int i=0; i<hoursInChart; i++){

            Calendar cal = Calendar.getInstance();
            cal.setTime(currentDateTime);
            cal.add(Calendar.HOUR, -i);
            Date hashDate = cal.getTime();

            //DateFormat df = new SimpleDateFormat("yyyy.MM.dd HH:mm:ss");
            DateFormat df = new SimpleDateFormat("HH:mm");
            String string_user = df.format(hashDate);

            //Date hashSearch = ;

            DBSleepStepsData dbSleepStepsData = hourData.get(Common.dateToHashString(hashDate));
            if(dbSleepStepsData==null){
                activityPerHourList.add(new DataSetRecycleViewSet(0, string_user));
                sleepPerHourList.add(new DataSetRecycleViewSet(0, string_user));
            }else{
                activityPerHourList.add(new DataSetRecycleViewSet(dbSleepStepsData.steps, string_user));
                sleepPerHourList.add(new DataSetRecycleViewSet(dbSleepStepsData.sleep_min, string_user));
            }

        }


        recyclerView_activityPerHour = findViewById(R.id.recycleView_activityPerHour);
        recyclerView_activityPerHour.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_activityPerHour.setAdapter(new RecycleViewStatsAdapter(this, activityPerHourList, RecycleViewStatsAdapter.TYPE_STEPS));



        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #




        recyclerView_sleepPerHours = findViewById(R.id.recycleView_sleepPerHour );
        recyclerView_sleepPerHours.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_sleepPerHours.setAdapter(new RecycleViewStatsAdapter(this, sleepPerHourList, RecycleViewStatsAdapter.TYPE_SLEEP));

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

        HashMap<String, DBSleepStepsData> dayData = MainActivity.mainActivity.dbHelper.getLastDaysData(10);
        List<DataSetRecycleViewSet> activityPerDayList = new ArrayList<>();
        List<DataSetRecycleViewSet> sleepPerDayList = new ArrayList<>();

        int daysInChart = 20;
        Date currentDate = Common.getStartOfDay(new Date());
        for(int i=0; i<daysInChart; i++){

            Calendar cal = Calendar.getInstance();
            cal.setTime(currentDate);
            cal.add(Calendar.DATE, -i);
            Date hashDate = cal.getTime();

            //DateFormat df = new SimpleDateFormat("yyyy.MM.dd HH:mm:ss");
            DateFormat df = new SimpleDateFormat("dd.MM");
            String string_user = df.format(hashDate);

            //Date hashSearch = ;

            DBSleepStepsData dbSleepStepsData = dayData.get(Common.dateToHashString(hashDate));
            if(dbSleepStepsData==null){
                activityPerDayList.add(new DataSetRecycleViewSet(0, string_user));
                sleepPerDayList.add(new DataSetRecycleViewSet(0, string_user));
            }else{
                activityPerDayList.add(new DataSetRecycleViewSet(dbSleepStepsData.steps, string_user));
                sleepPerDayList.add(new DataSetRecycleViewSet(dbSleepStepsData.sleep_min, string_user));
            }

        }


        //activityPerDayList.add(new DataSetRecycleViewSet(246, "29 nov"));

        recyclerView_activityPerDay = findViewById(R.id.recycleView_stepsPerDay);
        recyclerView_activityPerDay.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_activityPerDay.setAdapter(new RecycleViewStatsAdapter(this, activityPerDayList, RecycleViewStatsAdapter.TYPE_STEPS));

        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
        // # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #



        //sleepPerDayList.add(new DataSetRecycleViewSet(246, "29 nov"));

        recyclerView_sleepPerDay = findViewById(R.id.recycleView_sleepPerDay);
        recyclerView_sleepPerDay.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, true));
        recyclerView_sleepPerDay.setAdapter(new RecycleViewStatsAdapter(this, sleepPerDayList, RecycleViewStatsAdapter.TYPE_SLEEP));

        setListeners();
    }

    void setListeners(){

        activityPerHour_back_btn = findViewById(R.id.activityPerHour_back_btn);
        activityPerHour_next_btn = findViewById(R.id.activityPerHour_next_btn);
        sleepPerHour_back_btn = findViewById(R.id.sleepPerHour_back_btn);
        sleepPerHour_next_btn = findViewById(R.id.sleepPerHour_next_btn);
        stepsPerDay_back_btn = findViewById(R.id.stepsPerDay_back_btn);
        stepsPerDay_next_btn = findViewById(R.id.stepsPerDay_next_btn);
        sleepPerDay_back_btn = findViewById(R.id.sleepPerDay_back_btn);
        sleepPerDay_next_btn = findViewById(R.id.sleepPerDay_next_btn);

        activityPerHour_back_btn.setOnClickListener(getScrollListenerStat(recyclerView_activityPerHour, true));
        activityPerHour_next_btn.setOnClickListener(getScrollListenerStat(recyclerView_activityPerHour, false));

        sleepPerHour_back_btn.setOnClickListener(getScrollListenerStat(recyclerView_sleepPerHours, true));
        sleepPerHour_next_btn.setOnClickListener(getScrollListenerStat(recyclerView_sleepPerHours, false));

        stepsPerDay_next_btn.setOnClickListener(getScrollListenerStat(recyclerView_activityPerDay, false));
        stepsPerDay_back_btn.setOnClickListener(getScrollListenerStat(recyclerView_activityPerDay, true));

        sleepPerDay_back_btn.setOnClickListener(getScrollListenerStat(recyclerView_sleepPerDay, true));
        sleepPerDay_next_btn.setOnClickListener(getScrollListenerStat(recyclerView_sleepPerDay, false));

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            settingScrollListeners();
        }
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    void settingScrollListeners(){
        recyclerView_activityPerHour.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                if(!disableScrollListener) {
                    disableScrollListener = true;
                    recyclerView_sleepPerHours.scrollBy(-oldScrollX, 0);
                    disableScrollListener = false;
                }
            }
        });
        recyclerView_sleepPerHours.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                if(!disableScrollListener) {
                    disableScrollListener = true;
                    recyclerView_activityPerHour.scrollBy(-oldScrollX, 0);
                    disableScrollListener = false;
                }
            }
        });

        recyclerView_activityPerDay.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                if(!disableScrollListener) {
                    disableScrollListener = true;
                    recyclerView_sleepPerDay.scrollBy(-oldScrollX, 0);
                    disableScrollListener = false;
                }
            }
        });
        recyclerView_sleepPerDay.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View v, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                if(!disableScrollListener) {
                    disableScrollListener = true;
                    recyclerView_activityPerDay.scrollBy(-oldScrollX, 0);
                    disableScrollListener = false;
                }
            }
        });
    }

    boolean disableScrollListener = false;
    View.OnClickListener getScrollListenerStat(RecyclerView recyclerView, boolean scrollBack){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(!disableScrollListener) {
                    final float scale = ActivityScreen.this.getResources().getDisplayMetrics().density;
                    int scrollSize = (int) (scale * 75);
                    if (scrollBack) {
                        recyclerView.smoothScrollBy(-(recyclerView.getWidth() - scrollSize), 0);
                    } else {
                        recyclerView.smoothScrollBy((recyclerView.getWidth() - scrollSize), 0);
                    }
                }
            }
        };
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