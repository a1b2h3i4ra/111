package its.RohitOp;

import android.content.Context;
import android.app.Application;
import android.util.Log;
import java.io.IOException;

public class App extends Application {
    public static Application sInstance;
    
    public void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        try {
            Runtime.getRuntime().exec("su");
        } catch (IOException e) {
            e.printStackTrace();
        }
        sInstance = this;
    }
    public static Application getInstance2() {
        Log.d("TR", "Application.getInstance2:" + Log.getStackTraceString(new Throwable()));
        return sInstance;
    }
}
