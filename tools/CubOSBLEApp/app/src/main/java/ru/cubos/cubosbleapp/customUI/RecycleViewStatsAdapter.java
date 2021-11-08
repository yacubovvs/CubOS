package ru.cubos.cubosbleapp.customUI;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.constraintlayout.widget.ConstraintSet;
import androidx.constraintlayout.widget.Guideline;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

import ru.cubos.cubosbleapp.R;

public class RecycleViewStatsAdapter extends RecyclerView.Adapter<RecycleViewStatsAdapter.ViewHolder> {

    static final public int TYPE_SLEEP = 0x01;
    static final public int TYPE_STEPS = 0x02;

    private List<DataSetRecycleViewSet> mData;
    private LayoutInflater mInflater;
    private ItemClickListener mClickListener;

    private float max_value = 0;
    private int type;

    // data is passed into the constructor
    public RecycleViewStatsAdapter(Context context, List<DataSetRecycleViewSet> data, int type) {
        this.mInflater = LayoutInflater.from(context);
        this.mData = data;

        this.type = type;

        for(int i=0; i<data.size(); i++){
            if(max_value<data.get(i).value){
                max_value = data.get(i).value;
            }
        }
    }

    // inflates the row layout from xml when needed
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = mInflater.inflate(R.layout.recycleview_stats, parent, false);
        return new ViewHolder(view);
    }

    // binds the data to the TextView in each row
    @SuppressLint("ResourceAsColor")
    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        //String animal = mData.get(position);
        //holder.myTextView.setText(animal);
        DataSetRecycleViewSet dataElement = mData.get(position);
        holder.valueTextView.setText("" + dataElement.value);
        holder.labelTextView.setText(dataElement.label);

        holder.green_guideline.setGuidelinePercent(1f-((float)dataElement.value/max_value));

        if(this.type==TYPE_SLEEP){
            holder.greenLayout.setBackgroundColor(R.color.predark_blue);
        }else if(this.type==TYPE_SLEEP){
            holder.greenLayout.setBackgroundColor(R.color.predark_green);
        }
    }

    // total number of rows
    @Override
    public int getItemCount() {
        return mData.size();
    }


    // stores and recycles views as they are scrolled off screen
    public class ViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        TextView labelTextView;
        TextView valueTextView;
        Guideline green_guideline;
        LinearLayout greenLayout;

        ViewHolder(View itemView) {
            super(itemView);
            valueTextView = itemView.findViewById(R.id.recycleView_element_value);
            labelTextView = itemView.findViewById(R.id.recycleView_element_label);
            green_guideline = itemView.findViewById(R.id.green_guideline);
            greenLayout = itemView.findViewById(R.id.greenLayout);

            itemView.setOnClickListener(this);
        }

        @Override
        public void onClick(View view) {
            // Do nothing :)
        }
    }

    // convenience method for getting data at click position
    DataSetRecycleViewSet getItem(int id) {
        return mData.get(id);
    }

    // allows clicks events to be caught
    void setClickListener(ItemClickListener itemClickListener) {
        this.mClickListener = itemClickListener;
    }

    // parent activity will implement this method to respond to click events
    public interface ItemClickListener {
        void onItemClick(View view, int position);
    }
}

