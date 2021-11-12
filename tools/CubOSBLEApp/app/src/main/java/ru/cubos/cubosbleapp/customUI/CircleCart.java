package ru.cubos.cubosbleapp.customUI;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.Nullable;

public class CircleCart extends View {

    public float steps_k = 0f;
    public float sleep_k = 0f;

    public CircleCart(Context context) {
        super(context);
    }

    public CircleCart(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    public CircleCart(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    public CircleCart(Context context, @Nullable AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
    }

    @Override
    protected void onDraw(Canvas canvas) {

        float strokeWidth = 50;
        float width = this.getWidth();
        float height = this.getHeight();
        float radius = Math.min(width, height)/2 - strokeWidth/2;
        float radius2 = Math.min(width, height)/2 - strokeWidth/2 - strokeWidth;
        float radius_dg = Math.min(width, height)/2 - strokeWidth;


        //Path path = new Path();
        //path.addCircle(width, height, radius, Path.Direction.CW);
        Paint paint = new Paint();


        paint.setStyle(Paint.Style.STROKE);
        paint.setAntiAlias(true);

        float center_x, center_y;
        center_x = width/2;
        center_y = height/2 + height/15;

        final RectF oval = new RectF();

        int greenColor = Color.argb(255, 0, 196, 0);
        int blueColor = Color.argb(255, 0, 0, 196);
        int grayColor = Color.argb(255, 224, 224, 224);

        paint.setStrokeWidth(strokeWidth*2);
        paint.setColor(grayColor);
        oval.set(center_x - radius_dg, center_y - radius_dg, center_x + radius_dg, center_y + radius_dg);
        canvas.drawArc(oval, 135, 270, false, paint);

        float steps_angle = (float)(270)*steps_k;
        float sleep_angle = (float)(270)*sleep_k;

        if(steps_angle>270) steps_angle = 270;
        if(sleep_angle>270) sleep_angle = 270;

        paint.setStrokeWidth(strokeWidth);
        paint.setColor(greenColor);
        oval.set(center_x - radius, center_y - radius, center_x + radius, center_y + radius);
        canvas.drawArc(oval, 135, steps_angle, false, paint);

        paint.setColor(blueColor);
        oval.set(center_x - radius2, center_y - radius2, center_x + radius2, center_y + radius2);
        canvas.drawArc(oval, 135, sleep_angle, false, paint);

        /*
        paint.setStyle(Paint.Style.STROKE);
        oval.set(center_x - 200f, center_y - 200f, center_x + 200f,
                center_y + 200f);
        */
        //canvas.drawArc(oval, 45, 270, true, paint);

    }

    public void setCurrentStepsK(float steps_k){
        this.steps_k = steps_k;
        this.invalidate();
    }
    public void setCurrentSleepTimeK(float sleep_k){
        this.sleep_k = sleep_k;
        this.invalidate();
    }
}
