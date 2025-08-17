package its.RohitOp;


import android.app.Activity;
import android.content.ContextWrapper;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.Typeface;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.text.Html;
import android.text.InputFilter;
import android.util.Base64;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;

import static android.view.ViewGroup.LayoutParams.WRAP_CONTENT;
import static android.widget.RelativeLayout.ALIGN_PARENT_RIGHT;
import static java.lang.System.loadLibrary;
import android.os.Build;
import android.view.Gravity;

public class LoginActivity extends Activity {
	String sGameActivity = "its.RohitOp.MainActivity";
    EditText mail, pass;
    Button init;
    ProgressBar progressBar;
    private LinearLayout patchvendedores;
    private LinearLayout patchlogin;
    private Button vendedores;
    private Button login;

    private void Login() {
    
        RelativeLayout relativeLayout = new RelativeLayout(this);
        relativeLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        LinearLayout linearLayout = new LinearLayout(this);
        linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout.setBackgroundColor(Color.parseColor("#FF212121"));
        linearLayout.setGravity(Gravity.CENTER_HORIZONTAL | Gravity.CENTER_VERTICAL);

        LinearLayout LinearMenu = new LinearLayout(this);
        LinearMenu.setLayoutParams(new LinearLayout.LayoutParams(655, 480));
        LinearMenu.setOrientation(LinearLayout.VERTICAL);
        android.graphics.drawable.GradientDrawable CBCJBBJ = new android.graphics.drawable.GradientDrawable();
        CBCJBBJ.setColor(Color.parseColor("#FF221618"));
        CBCJBBJ.setCornerRadius(5);
        LinearMenu.setBackground(CBCJBBJ);
        if(Build.VERSION.SDK_INT >= 21) { LinearMenu.setElevation(19f); }

        LinearLayout LinearTitle = new LinearLayout(this);
        LinearTitle.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        LinearTitle.setOrientation(LinearLayout.VERTICAL);
        android.graphics.drawable.GradientDrawable GBEJJHJ = new android.graphics.drawable.GradientDrawable();
        GBEJJHJ.setColor(Color.parseColor("#26252A"));
        GBEJJHJ.setCornerRadii(new float[] { 5, 5, 5, 5, 0, 0, 0, 0 });
        LinearTitle.setBackground(GBEJJHJ);
        if(Build.VERSION.SDK_INT >= 21) {
            LinearTitle.setElevation(19f); }

        TextView teamName = new TextView(this);
        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(-1, -2);
        layoutParams.setMargins(convertDipToPixels(8.0f), convertDipToPixels(8.0f), convertDipToPixels(8.0f), convertDipToPixels(8.0f));
        teamName.setTextColor(Color.parseColor("#FFFFFF"));
        teamName.setLayoutParams(layoutParams);
        teamName.setGravity(1);
        teamName.setBackgroundColor(Color.TRANSPARENT);
        teamName.setText(Html.fromHtml("its.RohitOp"));
        teamName.setTypeface(Typeface.DEFAULT_BOLD);
        teamName.setShadowLayer(1.0f,1.0f,1.0f,Color.parseColor("#FF0000"));
        teamName.setTextSize(12.0f);

        LinearLayout titleView2 = new LinearLayout(this);
        titleView2.setLayoutParams(new LinearLayout.LayoutParams(-1, 5));
        titleView2.setOrientation(LinearLayout.HORIZONTAL);
        titleView2.setGravity(Gravity.CENTER_VERTICAL);
        titleView2.setBackgroundColor(Color.parseColor("#FF0000"));

        LinearLayout LinearPatch = new LinearLayout(this);
        LinearPatch.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        LinearPatch.setOrientation(LinearLayout.VERTICAL);
        LinearPatch.setBackgroundColor(Color.parseColor("#FF221618"));
        LinearPatch.setPadding(15, 15, 15, 15);

        LinearLayout LinearPatch1 = new LinearLayout(this);
        LinearPatch1.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        LinearPatch1.setOrientation(LinearLayout.VERTICAL);
        android.graphics.drawable.GradientDrawable BJCCJIK = new android.graphics.drawable.GradientDrawable();
        BJCCJIK.setColor(Color.parseColor("#26252A"));
        BJCCJIK.setCornerRadius(8);
        LinearPatch1.setPadding(20, 20, 20, 20);
        LinearPatch1.setBackground(BJCCJIK);
        { LinearPatch1.setElevation(22f); }

        LinearLayout LinearButton = new LinearLayout(this);
        LinearButton.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        LinearButton.setGravity(Gravity.CENTER_HORIZONTAL | Gravity.CENTER_VERTICAL);
        LinearButton.setOrientation(LinearLayout.HORIZONTAL);

        LinearLayout linecolor = new LinearLayout(this);
        linecolor.setLayoutParams(new LinearLayout.LayoutParams(-1, 3));
        linecolor.setOrientation(LinearLayout.HORIZONTAL);
        linecolor.setGravity(Gravity.CENTER_VERTICAL);
        linecolor.setBackgroundColor(Color.parseColor("#FF0000"));

        RelativeLayout.LayoutParams layoutParamsButton = new RelativeLayout.LayoutParams(250, 50);
        layoutParamsButton.addRule(11);
        layoutParamsButton.setMargins(10, 8, 10, 0);

        login = new Button(this);
        login.setText("Login");
        login.setAllCaps(false);
        login.setTextSize(10.2f);
        login.setPadding(0, 0, 0, 0);
        login.setLayoutParams(layoutParamsButton);
        login.setTypeface(Typeface.DEFAULT_BOLD);
        login.setTextColor(Color.parseColor("#FFFFFF"));
        android.graphics.drawable.GradientDrawable BHCEBDH = new android.graphics.drawable.GradientDrawable();
        BHCEBDH.setColor(Color.parseColor("#FF0000"));
        BHCEBDH.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
        login.setBackground(BHCEBDH);
        login.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    //Login
                    android.graphics.drawable.GradientDrawable CBIIIJA = new android.graphics.drawable.GradientDrawable();
                    CBIIIJA.setColor(Color.parseColor("#FF0000"));
                    CBIIIJA.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
                    login.setBackground(CBIIIJA);
                    patchlogin.setVisibility(View.VISIBLE);

                    //Register
                    android.graphics.drawable.GradientDrawable CHCJJAJ = new android.graphics.drawable.GradientDrawable();
                    CHCJJAJ.setColor(Color.parseColor("#FF211C20"));
                    CHCJJAJ.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
                    vendedores.setBackground(CHCJJAJ);
                    patchvendedores.setVisibility(View.GONE);
                }});

        vendedores = new Button(this);
        vendedores.setText("Registrar");
        vendedores.setAllCaps(false);
        vendedores.setTextSize(10.2f);
        vendedores.setPadding(0, 0, 0, 0);
        vendedores.setLayoutParams(layoutParamsButton);
        vendedores.setTypeface(Typeface.DEFAULT_BOLD);
        vendedores.setTextColor(Color.parseColor("#FFFFFF"));
        android.graphics.drawable.GradientDrawable BHCEBDJ = new android.graphics.drawable.GradientDrawable();
        BHCEBDJ.setColor(Color.parseColor("#FF211C20"));
        BHCEBDJ.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
        vendedores.setBackground(BHCEBDJ);
        vendedores.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    //Register
                    android.graphics.drawable.GradientDrawable CBIIIJA = new android.graphics.drawable.GradientDrawable();
                    CBIIIJA.setColor(Color.parseColor("#FF0000"));
                    CBIIIJA.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
                    vendedores.setBackground(CBIIIJA);
                    patchvendedores.setVisibility(View.VISIBLE);

                    //Login
                    android.graphics.drawable.GradientDrawable CHCJJAJ = new android.graphics.drawable.GradientDrawable();
                    CHCJJAJ.setColor(Color.parseColor("#FF211C20"));
                    CHCJJAJ.setCornerRadii(new float[] { 12, 12, 12, 12, 0, 0, 0, 0 });
                    login.setBackground(CHCJJAJ);
                    patchlogin.setVisibility(View.GONE);
                }});

        patchlogin = new LinearLayout(this);
        patchlogin.setVisibility(View.VISIBLE);
        patchlogin.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        patchlogin.setPadding(0, 10, 0, 0);
        patchlogin.setOrientation(LinearLayout.VERTICAL);
        patchlogin.setBackgroundColor(Color.parseColor("#00000000"));

        //Patch Vendedores
        patchvendedores = new LinearLayout(this);
        patchvendedores.setVisibility(View.GONE);
        patchvendedores.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        patchvendedores.setPadding(0, 10, 0, 0);
        patchvendedores.setOrientation(LinearLayout.VERTICAL);
        patchvendedores.setBackgroundColor(Color.parseColor("#00000000"));

        TextView menuLogin = new TextView(this);
        menuLogin.setText("Extra Mods Login");
        menuLogin.setGravity(Gravity.CENTER);
        menuLogin.setTextSize(11.2f);
        menuLogin.setPadding(0, 3, 0, 3);
        menuLogin.setTextColor(Color.parseColor("#FFFFFF"));
        android.graphics.drawable.GradientDrawable BIGIDBJ = new android.graphics.drawable.GradientDrawable();
        BIGIDBJ.setColor(Color.parseColor("#FF211C20"));
        BIGIDBJ.setCornerRadii(new float[] { 12, 12, 12, 12, 12, 12, 12, 12 });
        menuLogin.setBackground(BIGIDBJ);
        if(Build.VERSION.SDK_INT >= 21)
        { menuLogin.setElevation(12f); }

        RelativeLayout.LayoutParams layoutParamsEditText = new RelativeLayout.LayoutParams(-1, 60);
        layoutParamsEditText.setMargins(10, 8, 10, 0);

        mail = new EditText(this);
        mail.setPadding(5,0,5,0);
        mail.setHint("Digite Seu Usúario");
        mail.setHintTextColor(Color.parseColor("#FFFFFF"));
        mail.setTextColor(Color.parseColor("#FFFFFF"));
        mail.setSingleLine(true);
        mail.setTextSize(10.2f);
        mail.setLayoutParams(layoutParamsEditText);
        android.graphics.drawable.GradientDrawable BEDBFDD = new android.graphics.drawable.GradientDrawable();
        BEDBFDD.setColor(Color.parseColor("#00000000"));
        BEDBFDD.setCornerRadii(new float[] { 10, 10, 10, 10, 10, 10, 10, 10 });
        BEDBFDD.setStroke(2, Color.parseColor("#FF0000"));
        mail.setBackground(BEDBFDD);

        pass = new EditText(this);
        pass.setPadding(5,0,5,0);
        pass.setHint("Digite Sua Senha");
        pass.setHintTextColor(Color.parseColor("#FFFFFF"));
        pass.setTextColor(Color.parseColor("#FFFFFF"));
        pass.setSingleLine(true);
        pass.setTextSize(10.2f);
        pass.setTransformationMethod(android.text.method.PasswordTransformationMethod.getInstance());
        pass.setLayoutParams(layoutParamsEditText);
        android.graphics.drawable.GradientDrawable BEDBFDB = new android.graphics.drawable.GradientDrawable();
        BEDBFDB.setColor(Color.parseColor("#00000000"));
        BEDBFDB.setCornerRadii(new float[] { 10, 10, 10, 10, 10, 10, 10, 10 });
        BEDBFDB.setStroke(2, Color.parseColor("#FF0000"));
        pass.setBackground(BEDBFDB);

        RelativeLayout.LayoutParams layoutParamsLogin = new RelativeLayout.LayoutParams(-1, 50);
        layoutParamsLogin.setMargins(10, 14, 10, 0);

        init = new Button(this);
        init.setText("Entrar");
        init.setAllCaps(false);
        init.setPadding(0,0,0,0);
        init.setTextColor(Color.parseColor("#FFFFFF"));
        init.setTextSize(10.2f);
        init.setLayoutParams(layoutParamsLogin);
        android.graphics.drawable.GradientDrawable BFEIFDF = new android.graphics.drawable.GradientDrawable();
        BFEIFDF.setColor(Color.parseColor("#FF0000"));
        BFEIFDF.setCornerRadii(new float[] { 10, 10, 10, 10, 10, 10, 10, 10 });
        android.graphics.drawable.RippleDrawable BFEIFDF_RE = new android.graphics.drawable.RippleDrawable(new android.content.res.ColorStateList(new int[][]{new int[]{}}, new int[]{ Color.parseColor("#B71C1C")}), BFEIFDF, null);
        init.setBackground(BFEIFDF_RE);
        if(Build.VERSION.SDK_INT >= 21) { init.setElevation(15f); }


        ScrollView vendedoresScroll = new ScrollView(this);
        vendedoresScroll.setLayoutParams(new ScrollView.LayoutParams(-1, -1));
        vendedoresScroll.setBackgroundColor(Color.parseColor("#00000000"));

        LinearLayout vendedoresLinear = new LinearLayout(this);
        vendedoresLinear.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        vendedoresLinear.setBackgroundColor(Color.parseColor("#00000000"));
        vendedoresLinear.setOrientation(LinearLayout.VERTICAL);

        TextView menuRegister = new TextView(this);
        menuRegister.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        menuRegister.setText("Menu Resgister");
        menuRegister.setGravity(Gravity.CENTER);
        menuRegister.setTextSize(11.2f);
        menuRegister.setPadding(0, 3, 0, 3);
        menuRegister.setTextColor(Color.parseColor("#FFFFFF"));
        android.graphics.drawable.GradientDrawable BIGIDBL = new android.graphics.drawable.GradientDrawable();
        BIGIDBL.setColor(Color.parseColor("#FF211C20"));
        BIGIDBL.setCornerRadii(new float[] { 12, 12, 12, 12, 12, 12, 12, 12 });
        menuRegister.setBackground(BIGIDBL);
        if(Build.VERSION.SDK_INT >= 21)
        { menuRegister.setElevation(12f); }

        //Vendedor 1
        TextView nomevendedor1 = new TextView(this);
        nomevendedor1.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        nomevendedor1.setGravity(Gravity.CENTER);
        nomevendedor1.setTextColor(Color.parseColor("#FFFFFF"));
        nomevendedor1.setTextSize(10.2f);
        nomevendedor1.setText(Html.fromHtml("<font color='#FFFFFF'><a href>Clique Para Poder Entrar Em Contato Com</font> <font color='#FF0000'><a><b>LZ CHEATS</font></b>"));
        nomevendedor1.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://wa.me/+5561994640298")));
                }});

        TextView nomevendedor2 = new TextView(this);
        nomevendedor2.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        nomevendedor2.setGravity(Gravity.CENTER);
        nomevendedor2.setTextColor(Color.parseColor("#FFFFFF"));
        nomevendedor2.setTextSize(10.2f);
        nomevendedor2.setText(Html.fromHtml("<font color='#FFFFFF'><a href>Clique Para Poder Entrar Em Contato Com</font> <font color='#FF0000'><a><b>Thiago PHP</font></b>"));
        nomevendedor2.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("http://wa.me/5511995388034")));
                }});
                
        TextView nomevendedor3 = new TextView(this);
        nomevendedor3.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        nomevendedor3.setGravity(Gravity.CENTER);
        nomevendedor3.setTextColor(Color.parseColor("#FFFFFF"));
        nomevendedor3.setTextSize(10.2f);
        nomevendedor3.setText(Html.fromHtml("<font color='#FFFFFF'><a href>Clique Para Poder Entrar Em Contato Com</font> <font color='#FF0000'><a><b>DLZINN</font></b>"));
        nomevendedor3.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://wa.me/5541999932683")));
                }});

        //Linear Layout
        linearLayout.addView(LinearMenu);

        //Linear Menu
        LinearMenu.addView(LinearTitle);
        LinearMenu.addView(titleView2);
        LinearMenu.addView(LinearPatch);

        //Linear Patch
        LinearPatch1.addView(LinearButton);
        LinearPatch1.addView(linecolor);
        LinearPatch1.addView(patchlogin);
        LinearPatch1.addView(patchvendedores);

        //Linear Button
        LinearButton.addView(login);
        LinearButton.addView(vendedores);

        //Login Patch
        patchlogin.addView(menuLogin);
        patchlogin.addView(mail);
        patchlogin.addView(pass);
        patchlogin.addView(init);

        //Resgister Patch
        patchvendedores.addView(vendedoresScroll);
        vendedoresScroll.addView(vendedoresLinear);
        vendedoresLinear.addView(menuRegister);

        //Colocar Vendedores
        vendedoresLinear.addView(nomevendedor1);
        vendedoresLinear.addView(nomevendedor2);
        vendedoresLinear.addView(nomevendedor3);

        //Linear Patch
        LinearPatch.addView(LinearPatch1);
        LinearTitle.addView(teamName);
        relativeLayout.addView(linearLayout);

        setContentView(relativeLayout);


        setContentView(relativeLayout);
        TryLoginPHP();
    }

    private final String USER = "USER";
    private final String PASS = "PASS";
    private Prefs prefs;
    private void TryLoginPHP() {
        prefs = Prefs.with(this);

        mail.setText(prefs.read(USER, ""));
        pass.setText(prefs.read(PASS, ""));


        init.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                    String USER = mail.getText().toString().trim();
                    String PASS = pass.getText().toString().trim();
                    LoginActivity.this.prefs.write(LoginActivity.this.USER, USER);
                    LoginActivity.this.prefs.write(LoginActivity.this.PASS, PASS);
                    
                    
                    
                    new Auth(LoginActivity.this).execute(new String[]{USER, PASS});
                }
            });
    }
    private int convertDipToPixels(float f) {
        return (int) ((f * getResources().getDisplayMetrics().density) + 0.5f);
    }



    public String urlRequest(String str) {
        StringBuilder sb = new StringBuilder();
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new URL(str).openConnection().getInputStream()));
            while (true) {
                String readLine = bufferedReader.readLine();
                if (readLine == null) {
                    break;
                }
                sb.append(readLine);
                sb.append("\n");
            }
            bufferedReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return sb.toString();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Login();
    }
}

/*
To implement an offline login feature in your `LoginActivity`, you can modify the existing code to check user credentials against hardcoded values or retrieve them from a local storage method (like SharedPreferences). Below is an adaptation of your code to facilitate offline login, assuming you have predefined credentials:

1. **Define Hardcoded Credentials**: You can define a hardcoded username and password for offline access.
2. **Modify the Login Logic**: Adjust the login logic to check against these hardcoded credentials when the login button is pressed.

Here's the modified `LoginActivity` code with offline login:

```java
public class LoginActivity extends Activity {
    String sGameActivity = "its.RohitOp.MainActivity";
    EditText mail, pass;
    Button init;
    ProgressBar progressBar;
    private LinearLayout patchvendedores;
    private LinearLayout patchlogin;
    private Button vendedores;
    private Button login;

    private final String OFFLINE_USER = "offlineUser"; // Hardcoded username
    private final String OFFLINE_PASS = "offlinePass"; // Hardcoded password

    private void Login() {
        // Existing layout setup code...

        init = new Button(this);
        init.setText("Entrar");
        init.setAllCaps(false);
        init.setPadding(0, 0, 0, 0);
        init.setTextColor(Color.parseColor("#FFFFFF"));
        init.setTextSize(10.2f);
        init.setLayoutParams(layoutParamsLogin);
        android.graphics.drawable.GradientDrawable BFEIFDF = new android.graphics.drawable.GradientDrawable();
        BFEIFDF.setColor(Color.parseColor("#FF0000"));
        BFEIFDF.setCornerRadii(new float[]{10, 10, 10, 10, 10, 10, 10, 10});
        android.graphics.drawable.RippleDrawable BFEIFDF_RE = new android.graphics.drawable.RippleDrawable(new android.content.res.ColorStateList(new int[][]{new int[]{}}, new int[]{Color.parseColor("#B71C1C")}), BFEIFDF, null);
        init.setBackground(BFEIFDF_RE);
        if (Build.VERSION.SDK_INT >= 21) {
            init.setElevation(15f);
        }

        // Set up the login button click listener
        init.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String userInput = mail.getText().toString().trim();
                String passInput = pass.getText().toString().trim();

                // Check against hardcoded credentials
                if (userInput.equals(OFFLINE_USER) && passInput.equals(OFFLINE_PASS)) {
                    Toast.makeText(LoginActivity.this, "Login Successful", Toast.LENGTH_SHORT).show();
                    // Proceed to the next activity
                    Intent intent = new Intent(LoginActivity.this, MainActivity.class); // Replace with your activity
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(LoginActivity.this, "Invalid Credentials", Toast.LENGTH_SHORT).show();
                }
            }
        });

        // Remaining layout code...
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Login();
    }
}


### Key Changes:
1. **Hardcoded Credentials**: Added `OFFLINE_USER` and `OFFLINE_PASS` constants for predefined login credentials.
2. **Login Logic**: The `init` button's click listener now checks the input against the hardcoded values instead of making a network request.

### Note:
- Ensure you replace `MainActivity.class` with the actual activity you want to navigate to after a successful login.
-
 For improved security, consider using more secure methods for storing and retrieving credentials, especially in production applications.
 
 */