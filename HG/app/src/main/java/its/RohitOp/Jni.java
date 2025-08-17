package its.RohitOp;

public class Jni {
    public static native String hi();

    static {
       System.loadLibrary("EvoTeam");
    }
}
