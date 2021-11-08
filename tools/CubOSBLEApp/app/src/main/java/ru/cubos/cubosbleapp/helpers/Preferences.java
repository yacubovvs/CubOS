package ru.cubos.cubosbleapp.helpers;

import android.content.Context;
import android.content.SharedPreferences;

public class Preferences {
    private String APP_PREFERENCES = "mainsettings";
    private SharedPreferences mSettings;

    public Preferences(Context context){
        mSettings = context.getSharedPreferences(APP_PREFERENCES, Context.MODE_PRIVATE);
    }

    public String getString(String variable, String defaulValue){
        return mSettings.getString(variable, defaulValue);
    }

    public void putString(String variable, String value){
        SharedPreferences.Editor editor = mSettings.edit();
        editor.putString(variable, value);
        editor.apply();
    }

    public void putInt(String variable, int value){
        SharedPreferences.Editor editor = mSettings.edit();
        editor.putInt(variable, value);
        editor.apply();
    }

    public int getInt(String variable, int defaulValue){
        return mSettings.getInt(variable, defaulValue);
    }

    /*
    public void putBitMap(String variable, Bitmap value, int size){
        //При сохранении все картинки урезаются до маленьких размеров
        if (value==null){
            putString(variable, "");
        }else{
            try{
                value = BitmapHelper.scaleDown(value, size, true);
                ByteArrayOutputStream baos = new ByteArrayOutputStream();
                value.compress(Bitmap.CompressFormat.JPEG, 80, baos);
                byte[] b = baos.toByteArray();
                String encoded = Base64.encodeToString(b, Base64.DEFAULT);
                putString(variable, encoded);
            }catch(Exception e){
                Log.e("Error preferences", "Error putting bitmap");
            }
        }

    }

    public Bitmap getBitMap(String variable, Bitmap defaultValue){
        String BitmapBase64Array = getString(variable, "");

        if (BitmapBase64Array.equals("")){
            return defaultValue;
        }else{
            byte[] imageAsBytes = Base64.decode(BitmapBase64Array, Base64.DEFAULT);
            return BitmapFactory.decodeByteArray(imageAsBytes, 0, imageAsBytes.length);
        }

    }
    */


    public void putBoolean(String variable, boolean value){
        SharedPreferences.Editor editor = mSettings.edit();
        editor.putBoolean(variable, value);
        editor.apply();
    }

    public boolean getBoolean(String variable, boolean defaulValue){
        return mSettings.getBoolean(variable, defaulValue);
    }

}