package its.RohitOp;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.graphics.drawable.StateListDrawable;
import android.util.Base64;
import android.util.DisplayMetrics;
import android.util.TypedValue;
//import dalvik.annotation.MethodParameters;

public class LZCheatsColor {
    public static native void AAAAAAAAA();

    public static native void BBBBBBBB();

    public static native void CCCCCCCC();

    public static native void DDDDDDDD();

    public static native void EEEEEEEE();

    public static native void FFFFFFFF();

    public static native void GGGGGGGG();

    public static native void HHHHHHHH();

    public static native void IIIIIIIIII();

    public static native void JJJJJJJJ();

  //  @MethodParameters(accessFlags={0}, names={"i"})
    public static native void LLLLLLLL(float var0);

    public static native void LMCLMCLMCLMC();

    public static native String MADAME();

    //@MethodParameters(accessFlags={0}, names={"pos"})
    public static native void MMMMMMMM(int var0);

    public static native void MUMUMUMUMU();

  //  @MethodParameters(accessFlags={0}, names={"i"})
    public static native void NNNNNNNN(int var0);

    public static native String PATOLINOBR();

    public static native void PPPPPPPP();

    public static native void QQQQQQQ();

    public static native void RRRRRRR();

    public static native String SCRIPT();

    public static native void SPSPSPSPSP();

    public static native void YYYYYYYYYYY();

    public static native void ZZZZZZZZZ();

   // @MethodParameters(accessFlags={0}, names={"context"})
    public static GradientDrawable bbbbb_aaaaaaaa(Context context) {
        GradientDrawable gradientDrawable = new GradientDrawable();
        gradientDrawable.setShape(0);
        gradientDrawable.setStroke(3,  Color.parseColor((String)"CYAN"));
        gradientDrawable.setColor(Color.parseColor((String)"CYAN"));
        gradientDrawable.setCornerRadius(TypedValue.applyDimension((int)1, (float)5.0f, (DisplayMetrics)context.getResources().getDisplayMetrics()));
        return gradientDrawable;
    }

  //  @MethodParameters(accessFlags={0}, names={"context"})
    public static StateListDrawable bbbbb_hhhhh(Context context) {
        StateListDrawable stateListDrawable = new StateListDrawable();
        stateListDrawable.addState(new int[]{16842919}, (Drawable)LZCheatsColor.bbbbb_aaaaaaaa(context));
        stateListDrawable.addState(new int[]{16842908}, (Drawable)LZCheatsColor.bbbbb_aaaaaaaa(context));
        stateListDrawable.addState(new int[]{-16842908, -16842919}, (Drawable)LZCheatsColor.botoes(context));
        return stateListDrawable;
    }

    //@MethodParameters(accessFlags={0}, names={"context"})
    public static GradientDrawable botoes(Context context) {
        GradientDrawable gradientDrawable = new GradientDrawable();
        gradientDrawable.setShape(0);
        gradientDrawable.setStroke(3, Color.parseColor((String)"CYAN"));
        gradientDrawable.setCornerRadius(TypedValue.applyDimension((int)1, (float)5.0f, (DisplayMetrics)context.getResources().getDisplayMetrics()));
        return gradientDrawable;
    }

  //  @MethodParameters(accessFlags={0, 0}, names={"context", "icon"})
    public static Drawable pmm_icon(Context context, String string2) {
        byte[] arrby = Base64.decode((String)string2, (int)0);
        Bitmap bitmap = BitmapFactory.decodeByteArray((byte[])arrby, (int)0, (int)arrby.length);
        return new BitmapDrawable(context.getResources(), bitmap);
    }
}


