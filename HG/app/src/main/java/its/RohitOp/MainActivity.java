package its.RohitOp;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.content.res.AssetManager;
import android.util.Log;
import com.topjohnwu.superuser.Shell;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class MainActivity extends Activity {

    // 1. Load your native library (replace "your_native_lib" with actual name)
    static {
        System.loadLibrary("your_native_lib"); // libyour_native_lib.so
    }

    // 2. Declare native method for AssetManager
    public static native void nativeSetAssetManager(AssetManager mgr);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // 3. Pass AssetManager to native code (C++)
        nativeSetAssetManager(getAssets());

        // Validate Free Fire Max 2.115 offsets
        validateOffsets();

        setContentView(R.layout.activity_main);

        findViewById(R.id.Start).setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					Inject();
				}
			});
    }

    private void Inject() {
        try {
            String target = Offsets.getTargetPackage();
            Log.d("HG64", "Target package: " + target);
            Log.d("HG64", "Game version: " + Offsets.getGameVersion());
            
            String injector = this.getApplicationInfo().nativeLibraryDir + File.separator + "libinject.so";
            String payload_source = this.getApplicationInfo().nativeLibraryDir + File.separator + "libblrx.so";
            String payload_dest = "/dev/libmain.so";
            String context = "u:object_r:system_lib_file:s0";

            List<String> STDOUT = new ArrayList<>();
            Shell.su("ls -lZ /system/lib/libandroid_runtime.so").to(STDOUT).exec();
            for (String line : STDOUT) {
                if (line.contains(" u:object_r:") && line.contains(":s0 ")) {
                    context = line.substring(line.indexOf("u:object_r:"));
                    context = context.substring(0, context.indexOf(' '));
                }
            }

            Shell.su("cp " + payload_source + " " + payload_dest).exec();
            Shell.su("chmod 777 " + payload_dest).exec();
            Shell.su("chcon " + context + " " + payload_dest).exec();

            try {
                this.startActivity(this.getPackageManager().getLaunchIntentForPackage(target));
            } catch (Exception e) {
                // no action
            }

            while (Utilss.getProcessID(target) <= 0) {}
            Thread.sleep(1000);

            int pid = Utilss.getProcessID(target);
            String command = String.format(Locale.ENGLISH, "%s %d %s", injector, pid, payload_dest);

            Shell.su(command).exec();
            
            // Log successful injection with offset validation
            Log.d("HG64", "Injection completed successfully");
            Log.d("HG64", "Using " + Offsets.getAllOffsets().length + " memory offsets");
            Log.d("HG64", "Using " + Offsets.getAllVirtualAddresses().length + " virtual addresses");

        } catch (Exception e) {
            Log.e("HG64", "Injection failed: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    /**
     * Validate that all offsets are properly configured for Free Fire Max 2.115
     */
    private void validateOffsets() {
        Log.d("HG64", "=== Free Fire Max 2.115 Offset Validation ===");
        Log.d("HG64", "Game Version: " + Offsets.getGameVersion());
        Log.d("HG64", "Target Package: " + Offsets.getTargetPackage());
        Log.d("HG64", "Unity Core Module: 0x" + Long.toHexString(Offsets.UNITY_CORE_MODULE));
        Log.d("HG64", "FFMax Message Box: 0x" + Long.toHexString(Offsets.FFMAX_MESSAGE_BOX));
        Log.d("HG64", "Free Fire Logo Sprite: 0x" + Long.toHexString(Offsets.FREE_FIRE_LOGO_SPRITE_1));
        Log.d("HG64", "Total Memory Offsets: " + Offsets.getAllOffsets().length);
        Log.d("HG64", "Total Virtual Addresses: " + Offsets.getAllVirtualAddresses().length);
        Log.d("HG64", "==========================================");
    }
}
