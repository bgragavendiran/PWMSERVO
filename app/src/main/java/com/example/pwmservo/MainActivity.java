package com.example.pwmservo;
import static java.lang.Thread.sleep;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv = findViewById(R.id.sample_text);
        tv.setText("0 mm");
        control_init();
        turnoffallled();
//        turnon365nmled();
//        turnon395nmled();
//        turnon415nmled();
//        turnonwhinmled();
//        turnoffallled();
//        set415nmfilter();
//        set470nmfilter();
//        setnonmfilter();
//        set525nmfilter();
//        set600nmfilter();
//        set415nmfilter();
//        set415nmfilter();
        Timer timer = new Timer();
        timer.schedule(new TimerTask()
        {
            @Override
            public void run()
            {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        tv.setText(String.valueOf(getdepth())+" mm");
                    }
                });
            }
        }, 0, 1000);
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native void control_init();
    public native int getdepth();
    public native void turnon365nmled();
    public native void turnon395nmled();
    public native void turnon415nmled();
    public native void turnonwhinmled();
    public native void turnoffallled();
    public native void set415nmfilter();
    public native void set470nmfilter();
    public native void setnonmfilter();
    public native void set525nmfilter();
    public native void set600nmfilter();
}