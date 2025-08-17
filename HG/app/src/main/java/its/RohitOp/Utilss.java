package its.RohitOp;

import com.topjohnwu.superuser.Shell;
import java.util.ArrayList;
import java.util.List;

public class Utilss {
	
	public static int getProcessID(String pkg) {

        int pid = -1;
        if (Shell.rootAccess()) {
            String cmd = "for p in /proc/[0-9]*; do [[ $(<$p/cmdline) = " + pkg + " ]] && echo ${p##*/}; done";
            List<String> outs = new ArrayList<>();
            Shell.su(cmd).to(outs).exec();
            if (outs.size() > 0) {
                pid = Integer.parseInt(outs.get(0));
            }
        } else {
            Shell.Result out = Shell.sh("/system/bin/ps -A | grep \"" + pkg + "\"").exec();
            List<String> output = out.getOut();
            if (output.isEmpty() || output.get(0).contains("bad pid")) {
                out = Shell.sh("/system/bin/ps | grep \"" + pkg + "\"").exec();
                output = out.getOut();
                if (!output.isEmpty() && !output.get(0).contains("bad pid")) {
                    for (int i = 0; i < output.size(); i++) {
                        String[] results = output.get(i).trim().replaceAll("( )+", ",").replaceAll("(\n)+", ",").split(",");
                        if (results[8].equals(pkg)) {
                            pid = Integer.parseInt(results[1]);
                        }
                    }
                }
            } else {
                for (int i = 0; i < output.size(); i++) {
                    String[] results = output.get(i).trim().replaceAll("( )+", ",").replaceAll("(\n)+", ",").split(",");
                    for (int j = 0; j < results.length; j++) {
                        if (results[j].equals(pkg)) {
                            pid = Integer.parseInt(results[j - 7]);
                        }
                    }
                }
            }
        }
        return pid;
    }
}
