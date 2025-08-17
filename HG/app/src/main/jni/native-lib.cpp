#include <jni.h>
#include <vector>
#include <pthread.h>
#include <string.h>
#include <dobby.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_opengl3.h"
#include "Utils.h"
#include "Unity.h"
#include "ImGuiTheme.h"
#include "Includes/files.h"
#include "GL/include/cristiano_chams.h"
#include "Cristiano.h"
#include "KittyMemory/MemoryPatch.h"
#define RealLibToLoad "libcrashlytics-handler.so"
#include  "Firewall.h"
#include  "IPBlocker.h"
#include "Test.h""
#include "Includes/obfuscate.h"
#include <cmath>
#include "imgui.h"
#include "imgui_internal.h"
//ALLMODR
# define StartLibraryil2cpp(offset, ptr, orig) MSHookFunction((void *)getRealOffset(offset), (void *)ptr, (void **)&orig)
#include <SDL.h>
# define DHook(offset, ptr, orig) MSHookFunction((void *)getRealOffset(offset), (void *)ptr, (void **)&orig)

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "stb_image.h"
#include <GLES3/gl3.h>
#include "stb_image.h"
//#include <GL/gl3w.h> // या glad/gl.h, backend के हिसाब से

#define WapenId (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("KOGBJLFDJHC"), OBFUSCATE("IDOGDPOPGAI"),0);
#define WapenHend (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("GetWeaponOnHand"));
#define TakDmg (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("TakeDamage"),9);
#define WholBydy (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StartWholeBodyFiring"),1);
#define StopFire (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("PlayerNetwork"), OBFUSCATE("StopFire"),1);




ImTextureID LoadTextureFromAssets(const char* filename)
{
    int w, h, channels;
    unsigned char* data = stbi_load(filename, &w, &h, &channels, 4);
    if (!data) return nullptr;

    GLuint tex_id;
    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    return (ImTextureID)(intptr_t)tex_id;
}
GLuint LoadTextureFromAssets(AAssetManager* mgr, const char* filename)
{
    int width, height, channels;
    unsigned char* data = nullptr;

    // Asset read
    AAsset* asset = AAssetManager_open(mgr, filename, AASSET_MODE_BUFFER);
    if (!asset) {
        printf("Failed to open asset: %s\n", filename);
        return 0;
    }
    off_t len = AAsset_getLength(asset);
    unsigned char* fileData = (unsigned char*)malloc(len);
    AAsset_read(asset, fileData, len);
    AAsset_close(asset);

    // stb load from memory
    data = stbi_load_from_memory(fileData, len, &width, &height, &channels, 4);
    free(fileData);

    if (!data) {
        printf("Failed to decode image: %s\n", filename);
        return 0;
    }

    // Generate texture
    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);

    // 🔹 Linear blur हटाकर sharp image के लिए GL_NEAREST लगाओ
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Border clamp
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);
    return texID;
}

  



AAssetManager* g_assetMgr = nullptr;

extern "C" JNIEXPORT void JNICALL
Java_its_RohitOp_MainActivity_nativeSetAssetManager(JNIEnv* env, jclass clazz, jobject assetManager) {
    g_assetMgr = AAssetManager_fromJava(env, assetManager);
}


GLuint myImageTex = 0;

void InitUI() {
    myImageTex = LoadTextureFromAssets(g_assetMgr, "logo.png"); // assets/logo.png
}



namespace ImGui {
    bool LetterButton(const char* label, bool* v, char letter);

    // Define individual buttons for each letter
    bool AButton(const char* label, bool* v) { return LetterButton(label, v, 'A'); }
    bool BButton(const char* label, bool* v) { return LetterButton(label, v, 'B'); }
    bool CButton(const char* label, bool* v) { return LetterButton(label, v, 'C'); }
    bool DButton(const char* label, bool* v) { return LetterButton(label, v, 'D'); }
    bool EButton(const char* label, bool* v) { return LetterButton(label, v, 'E'); }
    bool FButton(const char* label, bool* v) { return LetterButton(label, v, 'F'); }
    bool GButton(const char* label, bool* v) { return LetterButton(label, v, 'G'); }
    bool HButton(const char* label, bool* v) { return LetterButton(label, v, 'H'); }
    bool IButton(const char* label, bool* v) { return LetterButton(label, v, 'I'); }
    bool JButton(const char* label, bool* v) { return LetterButton(label, v, 'J'); }
    bool KButton(const char* label, bool* v) { return LetterButton(label, v, 'K'); }
    bool LButton(const char* label, bool* v) { return LetterButton(label, v, 'L'); }
    bool MButton(const char* label, bool* v) { return LetterButton(label, v, 'M'); }
    bool NButton(const char* label, bool* v) { return LetterButton(label, v, 'N'); }
    bool OButton(const char* label, bool* v) { return LetterButton(label, v, 'O'); }
    bool PButton(const char* label, bool* v) { return LetterButton(label, v, 'P'); }
    bool QButton(const char* label, bool* v) { return LetterButton(label, v, 'Q'); }
    bool RButton(const char* label, bool* v) { return LetterButton(label, v, 'R'); }
    bool SButton(const char* label, bool* v) { return LetterButton(label, v, 'S'); }
    bool TButton(const char* label, bool* v) { return LetterButton(label, v, 'T'); }
    bool UButton(const char* label, bool* v) { return LetterButton(label, v, 'U'); }
    bool VButton(const char* label, bool* v) { return LetterButton(label, v, 'V'); }
    bool WButton(const char* label, bool* v) { return LetterButton(label, v, 'W'); }
    bool XButton(const char* label, bool* v) { return LetterButton(label, v, 'X'); }
    bool YButton(const char* label, bool* v) { return LetterButton(label, v, 'Y'); }
    bool ZButton(const char* label, bool* v) { return LetterButton(label, v, 'Z'); }
}



static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
const float speed = 0.05f;  // Speed increase
void SetupImgui() {
     IMGUI_CHECKVERSION();
     ImGui::CreateContext();
     ImGuiIO&io=ImGui::GetIO();
     io.DisplaySize=ImVec2((float)glWidth,(float)glHeight);
void  Allan2();
ImGui::CreateContext();

   /*         ImGuiStyle *style = &ImGui::GetStyle();
                   
            style->WindowPadding = ImVec2(10, 5);
            style->WindowRounding = 7.0f;
            style->WindowRounding = 7.0f;
            style->ScrollbarRounding = 5;
		    style->FrameBorderSize = 3.0f;
		    style->WindowBorderSize = 3.0f;
			style->TabRounding = 4.0f;
		

			
        style->WindowTitleAlign = ImVec2(0.5, 0.5);
		style->ButtonTextAlign = ImVec2(0.5,0.5);
		style->Colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
   style->Colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style->Colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    style->Colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
style->Colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style->Colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
style->Colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style->Colors[ImGuiCol_FrameBg]                = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_FrameBgHovered]         = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_FrameBgActive]          = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_TitleBg]                = ImColor(0, 0, 0, 255);
    style->Colors[ImGuiCol_TitleBgActive]          = ImColor(0, 0, 0, 155);
    style->Colors[ImGuiCol_TitleBgCollapsed]       = ImColor(0, 0, 0, 200);
    style->Colors[ImGuiCol_MenuBarBg]              = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_ScrollbarBg]            = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_ScrollbarGrab]          = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_ScrollbarGrabHovered]   = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_ScrollbarGrabActive]    = ImColor(0, 0, 0, 0);
    style->Colors[ImGuiCol_CheckMark]              = ImColor(102, 0, 255, 255);
    style->Colors[ImGuiCol_SliderGrab]             = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_SliderGrabActive]       = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_Button]                 = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_ButtonHovered]          = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_ButtonActive]           = ImColor(255, 255, 255, 155);
    style->Colors[ImGuiCol_Header]                 = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
style->Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
style->Colors[ImGuiCol_HeaderActive]           = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
style->Colors[ImGuiCol_Separator]              = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
style->Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
style->Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
style->Colors[ImGuiCol_ResizeGrip]             = ImVec4(0.13f, 0.75f, 0.55f, 0.40f);
style->Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.13f, 0.75f, 0.75f, 0.60f);
style->Colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
style->Colors[ImGuiCol_Tab]                    = ImVec4(0.13f, 0.75f, 0.55f, 0.80f);
style->Colors[ImGuiCol_TabHovered]             = ImVec4(0.13f, 0.75f, 0.75f, 0.80f);
style->Colors[ImGuiCol_TabActive]              = ImVec4(0.13f, 0.75f, 1.00f, 0.80f);
style->Colors[ImGuiCol_TabUnfocused]           = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
style->Colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.36f, 0.36f, 0.36f, 0.54f);
    style->Colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
style->Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
style->Colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
style->Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
style->Colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
style->Colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
style->Colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
style->Colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
style->Colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
style->Colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
style->Colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
style->Colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
style->Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
style->Colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
style->Colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
   //     style->ScaleAllSizes(std::max(1.5f, density / 300.0f));
        style->ScrollbarSize /= 1;
*/
		
	// ----------- IMGUI STYLE -------------


  // Ye pura block hata do
ImGui::CreateContext();
//ImGuiStyle* style = &ImGui::GetStyle();

// Rounded corners and paddings
/*style->WindowRounding = 0.0f;
style->FrameRounding = 0.0f;
style->FramePadding = ImVec2(10, 8);
style->WindowBorderSize = 2.0f;
style->WindowTitleAlign = ImVec2(0.5f, 0.5f);

// Colors
style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 0);
style->Colors[ImGuiCol_Border]   = ImColor(255, 255, 255, 255);
*/
    

    
// ---------------------------
// RENDER FUNCTION
// ---------------------------

/*
void RenderGameSettingsUI()
{
    if (!showSettings) return;

    ImGui::SetNextWindowSize(ImVec2(520, 500), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2,
                                   ImGui::GetIO().DisplaySize.y / 2),
                                   ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

    ImGui::Begin("##GameSettings", nullptr,
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoTitleBar);

    // Get window info for custom drawing
    ImVec2 winPos = ImGui::GetWindowPos();
    ImVec2 winSize = ImGui::GetWindowSize();
    ImDrawList* drawList = ImGui::GetWindowDrawList();*/

    // -------- TOP BORDER with "HG CHEAT" --------
    
/*
    // -------- BODY --------
    
    // -------- BOTTOM BORDER with CLOSE BUTTON --------
    float footerHeight = 50.0f;
    ImGui::Dummy(ImVec2(0, winSize.y - ImGui::GetCursorPosY() - footerHeight));
    ImGui::SetCursorPosY(winSize.y - footerHeight);

    drawList->AddRectFilled(ImVec2(winPos.x, winPos.y + winSize.y - footerHeight),
                            ImVec2(winPos.x + winSize.x, winPos.y + winSize.y),
                            IM_COL32(255, 45, 45, 255), style->WindowRounding, ImDrawFlags_RoundCornersBottom);

    ImGui::SetCursorPosY(winSize.y - footerHeight + 8);
    ImGui::SetCursorPosX(10);
    if (ImGui::Button("CLOSE", ImVec2(winSize.x - 20, footerHeight - 16)))
    {
        showSettings = false;
    }

    ImGui::End();
}*/
/*
void RenderPanel()
{
    ImGui::SetNextWindowSize(ImVec2(500, 500), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(800, 450), ImGuiCond_Once, ImVec2(0.5f, 0.5f));

    ImGui::Begin("HG CHEAT", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    // Example UI elements
    static bool aimAssist = true;
    static bool aimToggle = true;
    static int fov = 46;
    static int gfxQuality = 2;
    static bool sprintBoost = false;

    ImGui::Checkbox("Aim Assist", &aimAssist);
    ImGui::Checkbox("Aim Toggle", &aimToggle);

    ImGui::Text("FOV: %d", fov);
    ImGui::SliderInt("##FOVSlider", &fov, 40, 120);

    const char* gfxOptions[] = { "Low", "Medium", "High", "Ultra" };
    ImGui::Combo("Graphics Quality", &gfxQuality, gfxOptions, IM_ARRAYSIZE(gfxOptions));
    ImGui::TextColored(ImVec4(0.73f, 0.76f, 0.82f, 1.0f), "Balanced visuals and performance.");

    ImGui::Checkbox("Sprint Speed Boost (x1.2)", &sprintBoost);

    ImGui::End();
}
		*/
		
     ImGui_ImplOpenGL3_Init("#version 100");
     ImFontConfig font_cfg;
     font_cfg.SizePixels=28.0f;
    io.Fonts->AddFontDefault(&font_cfg);
     ImGui::GetStyle().ScaleAllSizes(3.50f);
     

     
     
}
void AddColorPicker(const char*name, ImVec4 &color) {
    ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_AlphaPreview;
    static ImVec4 backup_color;
    
    bool open_popup = ImGui::ColorButton((std::string(name) + "##3b").c_str(), color, misc_flags);
    ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
    if (open_popup)
    {
        ImGui::OpenPopup(name);
        backup_color = color;
    }
    if (ImGui::BeginPopup(name))
    {
        ImGui::Text("Select Color");
        ImGui::Separator();
        ImGui::ColorPicker3("##picker", (float*)&color, misc_flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
        ImGui::SameLine();
        ImGui::BeginGroup();
        ImGui::Text("Current");
        ImGui::ColorButton("##current", color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40));
        ImGui::Text("Previous");
        if (ImGui::ColorButton("##previous", backup_color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40)))
            color = backup_color;
        ImGui::EndGroup();
        ImGui::EndPopup();
    }
}


bool clearMousePos = true, setup = false;

struct UnityEngine_Vector2_Fields {
    float x;
    float y;
};

struct UnityEngine_Vector2_o {
    UnityEngine_Vector2_Fields fields;
};

enum TouchPhase {
    Began = 0,
    Moved = 1,
    Stationary = 2,
    Ended = 3,
    Canceled = 4
};

struct UnityEngine_Touch_Fields {
    int32_t m_FingerId;
    struct UnityEngine_Vector2_o m_Position;
    struct UnityEngine_Vector2_o m_RawPosition;
    struct UnityEngine_Vector2_o m_PositionDelta;
    float m_TimeDelta;
    int32_t m_TapCount;
    int32_t m_Phase;
    int32_t m_Type;
    float m_Pressure;
    float m_maximumPossiblePressure;
    float m_Radius;
    float m_RadiusVariance;
    float m_AltitudeAngle;
    float m_AzimuthAngle;
};

void DrawTextCentered(const char *text)
{
ImGui::Separator();
ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize(text).x) / 2.f);
ImGui::Text(text);
ImGui::Separator();
}
void Menu() {
    // Expiration check
    ExpireDate exp;
    exp.setExpirationDate(13, 7, 2026); // d, m, y

    if (exp.isExpired()) {
        // Show expired message
        ImGui::SetNextWindowSize(ImVec2(300, 150), ImGuiCond_Always);
        ImGui::Begin("JOIN TELEGRAM", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::Text("YOUR MOD HAS EXPIRED!");
        ImGui::Separator();
        ImGui::Text("Please contact: @RDX_MODDER");
        ImGui::End();
        return;
    }

    // ===== STATE VARIABLES =====
    // ===== STATE VARIABLES =====
// ===== STATE VARIABLES =====
static bool show_emoji    = true;
static bool show_floating = false;
static ImVec2 emoji_pos   = ImVec2(80, 80);
static ImTextureID emoji_texture = (ImTextureID)1;

static ImVec2 windowPos = ImVec2(-1, -1);
static bool draggingWindow = false;
static ImVec2 dragOffset = ImVec2(0, 0);

// ==== COLOR VARIABLES ====
static ImVec4 headerFooterColor = ImVec4(176/255.0f, 32/255.0f, 1/255.0f, 1.0f);
static ImVec4 hgTextColor       = ImVec4(1, 1, 1, 1);
static char closeText[64]= "CLOSE";

// ===== EMOJI BUTTON =====
if (show_emoji)
{
    ImGui::SetNextWindowPos(emoji_pos, ImGuiCond_Always);
    ImGui::SetNextWindowBgAlpha(0.0f);

    ImGui::Begin("##emoji_overlay", nullptr,  
        ImGuiWindowFlags_NoTitleBar |  
        ImGuiWindowFlags_NoResize |  
        ImGuiWindowFlags_AlwaysAutoResize |  
        ImGuiWindowFlags_NoMove |  
        ImGuiWindowFlags_NoSavedSettings |  
        ImGuiWindowFlags_NoFocusOnAppearing |  
        ImGuiWindowFlags_NoNav  
    );  

    if (emoji_texture && (uintptr_t)emoji_texture != 0)  
    {  
        if (ImGui::ImageButton(emoji_texture, ImVec2(50, 50)))  
        {  
            show_emoji    = false;  
            show_floating = true;  
        }  
    }  
    ImGui::End();
}

// ===== MAIN HG CHEAT UI =====
if (show_floating)
{
    ImGuiIO& io = ImGui::GetIO();

    ImVec2 win_size = ImVec2(300, 450);  
    ImVec2 center   = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);  

    if (windowPos.x < 0 || windowPos.y < 0)  
        windowPos = ImVec2(center.x - win_size.x * 0.5f, center.y - win_size.y * 0.5f);  

    ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);  
    ImGui::SetNextWindowSize(win_size, ImGuiCond_Always);  

    float cornerRound = 28.0f;  

    ImVec4 customRed  = headerFooterColor;  
    ImVec4 customText = hgTextColor;  

    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);  
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, cornerRound);  
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));  

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.086f, 0.106f, 0.141f, 1.0f));  
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));  
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0, 0, 0, 1));  

    ImGui::Begin("##hgsettings", nullptr,  
        ImGuiWindowFlags_NoCollapse |  
        ImGuiWindowFlags_NoResize |  
        ImGuiWindowFlags_NoTitleBar  
    );  

    ImDrawList* draw_list = ImGui::GetWindowDrawList();  
    ImVec2 winPos  = ImGui::GetWindowPos();  
    ImVec2 winSize = ImGui::GetWindowSize();  

    // ==== HEADER ====  
    ImVec2 pos  = winPos;  
    ImVec2 size = ImVec2(winSize.x, 80.0f);  
    ImRect headerRect(pos, ImVec2(pos.x + size.x, pos.y + size.y));  

    draw_list->AddRectFilled(headerRect.Min, headerRect.Max,  
        ImGui::ColorConvertFloat4ToU32(customRed),  
        cornerRound, ImDrawFlags_RoundCornersTop  
    );  

    ImVec2 text_size = ImGui::CalcTextSize("HG CHEAT");  
    ImVec2 text_pos = ImVec2(  
        pos.x + (size.x - text_size.x) * 0.5f,  
        pos.y + (size.y - text_size.y) * 0.5f  
    );  
    draw_list->AddText(text_pos, ImGui::ColorConvertFloat4ToU32(customText), "HG CHEAT");  

    // ==== FOOTER ====  
    ImVec2 footer_start = ImVec2(winPos.x, winPos.y + winSize.y - 100.0f);  
    ImVec2 footer_end   = ImVec2(footer_start.x + winSize.x, footer_start.y + 100.0f);  
    ImRect footerRect(footer_start, footer_end);  

    draw_list->AddRectFilled(  
        footerRect.Min, footerRect.Max,  
        ImGui::ColorConvertFloat4ToU32(customRed),  
        cornerRound, ImDrawFlags_RoundCornersBottom  
    );  

    draw_list->AddLine(  
        ImVec2(footer_start.x, footer_end.y),  
        ImVec2(footer_end.x, footer_end.y),  
        ImGui::ColorConvertFloat4ToU32(customRed),  
        2.5f  
    );  

    // ==== DRAG MOVE ====  
    if (!draggingWindow)  
    {  
        if ((ImGui::IsMouseHoveringRect(headerRect.Min, headerRect.Max) ||  
             ImGui::IsMouseHoveringRect(footerRect.Min, footerRect.Max)) &&  
            ImGui::IsMouseClicked(ImGuiMouseButton_Left))  
        {  
            draggingWindow = true;  
            dragOffset = ImVec2(io.MousePos.x - windowPos.x, io.MousePos.y - windowPos.y);  
        }  
    }  
    else  
    {  
        if (ImGui::IsMouseDown(ImGuiMouseButton_Left))  
        {  
            windowPos.x = io.MousePos.x - dragOffset.x;  
            windowPos.y = io.MousePos.y - dragOffset.y;  
        }  
        else  
        {  
            draggingWindow = false;  
        }  
    }  

    // ==== MIDDLE CONTENT ====  
    float view_height = winSize.y - 180;  
    ImGui::SetCursorScreenPos(ImVec2(winPos.x, winPos.y + 80)); // No side padding  

    ImGui::BeginChild("scrollContent",  
        ImVec2(winSize.x, view_height),  
        true,  
        ImGuiWindowFlags_NoScrollbar  
    );  

    if (ImGui::IsWindowHovered() && ImGui::IsMouseDragging(ImGuiMouseButton_Left))  
    {  
        float scrollY = ImGui::GetScrollY();  
        ImGui::SetScrollY(scrollY - io.MouseDelta.y);  
    }  

    // ==== FIXED SECTION HEADER ====  
    auto DrawRedHeading = [&](const char* text)  
    {  
        float headingHeight = 38.0f;   
        ImVec2 contentMin = ImGui::GetWindowContentRegionMin();  
        ImVec2 contentMax = ImGui::GetWindowContentRegionMax();  
        ImVec2 winPosAbs  = ImGui::GetWindowPos();  
        float startX = winPosAbs.x + contentMin.x;  
        float endX   = winPosAbs.x + contentMax.x;  
        ImVec2 cursorPos = ImGui::GetCursorScreenPos();  

        ImGui::GetWindowDrawList()->AddRectFilled(  
            ImVec2(startX, cursorPos.y),  
            ImVec2(endX, cursorPos.y + headingHeight),  
            ImGui::ColorConvertFloat4ToU32(headerFooterColor),  
            0.0f  
        );  

        ImVec2 textSize = ImGui::CalcTextSize(text);  
        ImVec2 textPos(startX + (endX - startX - textSize.x) * 0.5f,  
                       cursorPos.y + (headingHeight - textSize.y) * 0.5f);  
        ImGui::GetWindowDrawList()->AddText(textPos, ImGui::ColorConvertFloat4ToU32(hgTextColor), text);  
        ImGui::Dummy(ImVec2(0, headingHeight + 6));  
    };  

    // ==== CHECKBOX STYLE ====  
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 4));  
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(8, 6));  
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);  
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);  
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0, 0, 0, 0));  
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ImVec4(0, 0, 0, 0));  
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ImVec4(0, 0, 0, 0));  
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1, 1, 1, 1));  

    auto LeftMarginCheckbox = [&](const char* label, bool* v)  
    {  
        ImVec2 cursor = ImGui::GetCursorPos();  
        cursor.x += 10;  
        ImGui::SetCursorPos(cursor);  
        ImGui::Checkbox(label, v);  
    };  

    auto WhiteSeparator = [&]()  
    {  
        ImVec2 p1 = ImGui::GetCursorScreenPos();  
        p1.x -= 10;  
        ImVec2 p2 = ImVec2(p1.x + ImGui::GetWindowContentRegionMax().x, p1.y);  
        ImGui::GetWindowDrawList()->AddLine(p1, p2, IM_COL32(255, 255, 255, 255), 2.0f);  
        ImGui::Dummy(ImVec2(0, 6));  
    };  

    DrawRedHeading("FUCTION");  
    LeftMarginCheckbox(OBFUSCATE("FUCTION ACTIVATE"), &Function);  
    WhiteSeparator();  

    DrawRedHeading("AIM MENU");  
    LeftMarginCheckbox(OBFUSCATE("Aimbot "), &Headshot);  
    WhiteSeparator();  
    LeftMarginCheckbox(OBFUSCATE("AIM AUTO "), &Aimshoot);  
    WhiteSeparator();  

	
	LeftMarginCheckbox(OBFUSCATE("AIM AUTO "), &AimScope);  
    WhiteSeparator();  

	
	LeftMarginCheckbox(OBFUSCATE("AIM LOCK "), &AimVisible);  
    WhiteSeparator();  
	
	LeftMarginCheckbox(OBFUSCATE("AIM SILENT "), &AimSilent);  
    WhiteSeparator();  
	
	

// 🎯 AIM FOV Slider with Red Circle Indicator (center above slider)
// ==== AIM FOV Slider (Centered + Left Margin 10px) ====
float leftMargin = 10.0f;  // Border se gap
float sliderMax = 700.0f;  // Max value

ImGui::SetCursorPosX(leftMargin + (ImGui::GetContentRegionAvail().x - (ImGui::CalcTextSize("AIM FOV").x + 200)) * 0.5f); // Center align with margin

ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, -8)); // Height adjust
ImVec2 sliderPos = ImGui::GetCursorScreenPos(); // Slider start position
float sliderWidth = 200.0f; // Fixed slider width for middle look

ImGui::SliderInt(OBFUSCATE("FOV"), &AimFov, 0, (int)sliderMax);
ImGui::PopStyleVar();

// ==== Circle position calculation ====
float t = (float)AimFov / sliderMax; // Normalized [0..1]
float circleX = sliderPos.x + t * sliderWidth; 
float circleY = sliderPos.y - 8.0f; // Slider ke upar

// ==== Draw circle above slider ====


// Draw red circle
//ImDrawList* draw_list = ImGui::GetWindowDrawList();
//draw_list->AddCircleFilled(ImVec2(circleX, circleY), 6.0f, IM_COL32(255, 0, 0, 255));




    DrawRedHeading("ESP PLAYER");  
    LeftMarginCheckbox(OBFUSCATE("ESP LINE "), &EspLinha);  
    WhiteSeparator();  
    LeftMarginCheckbox(OBFUSCATE("ESP CIRCLE "), &EspCiruleHead);  
    WhiteSeparator();  
    LeftMarginCheckbox(OBFUSCATE("DRAW FOV "), &DrawFov);  
    WhiteSeparator();  
    LeftMarginCheckbox(OBFUSCATE("ESP NAME "), &EspLinhaT);  
    WhiteSeparator();  

	
    DrawRedHeading("EXTRA MENU");  
    LeftMarginCheckbox(OBFUSCATE("REST GUEST"), &Convidado);  
    WhiteSeparator();  
	
	LeftMarginCheckbox(OBFUSCATE("JOYSTIK"), &isSpeedSafe);  
    WhiteSeparator();  
	
	LeftMarginCheckbox(OBFUSCATE("SPEED RUN"), &Convidado);  
    WhiteSeparator();  

    ImGui::Text("Header/Footer Color:");  
    ImGui::ColorEdit3("##HeaderFooter", (float*)&headerFooterColor);  
    ImGui::Text("HG/CLOSE Text Color:");  
    ImGui::ColorEdit3("##HGCloseText", (float*)&hgTextColor);  

    ImGui::PopStyleColor(4);  
    ImGui::PopStyleVar(4);  

    ImGui::EndChild();  

    ImVec2 btn_size = ImVec2(200, 50);  
    ImVec2 btn_pos  = ImVec2(  
        winPos.x + (winSize.x - btn_size.x) * 0.5f,  
        footer_start.y + (80 - btn_size.y) * 0.5f  
    );  

    ImGui::SetCursorScreenPos(btn_pos);  
    ImGui::PushStyleColor(ImGuiCol_Button, customRed);  
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, customRed);  
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, customRed);  
    ImGui::PushStyleColor(ImGuiCol_Text, hgTextColor);  

    if (ImGui::Button(closeText, btn_size))  
    {  
        show_floating = false;  
        show_emoji    = true;  
    }  

    ImGui::PopStyleColor(4);  
    ImGui::End();  
    ImGui::PopStyleColor(3);  
    ImGui::PopStyleVar(3);
}



    

        

		

    
	}




	
EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
 eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

	if (!setup) {
        SetupImgui();
        setup = true;
    }

    ImGuiIO &io = ImGui::GetIO();

    int touchCount = (((int (*)())(address+0x7ba8f24))()); // public static int get_touchCount() { }
    if (touchCount > 0) {
        UnityEngine_Touch_Fields touch = ((UnityEngine_Touch_Fields (*)(int))(address+0x7ba8b18))(0); // public static Touch GetTouch(int index) { }
        float reverseY = io.DisplaySize.y - touch.m_Position.fields.y;
        switch (touch.m_Phase) {
            case TouchPhase::Began:
            case TouchPhase::Stationary:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                io.MouseDown[0] = true;
                break;
            case TouchPhase::Ended:
            case TouchPhase::Canceled:
                io.MouseDown[0] = false;
                clearMousePos = true;
                break;
            case TouchPhase::Moved:
                io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);
                break;
            default:
                break;
        }
    }
	
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
	
    Menu();
	Start_Aimbot2();
	Start_Linhas2();

    ImGui::EndFrame();
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (clearMousePos) {
        io.MousePos = ImVec2(-1, -1);
        clearMousePos = false;
    }

    return old_eglSwapBuffers(dpy, surface);
}





bool(*get_ResetGuest)(bool* instance);
bool _get_ResetGuest(bool* instance) {
    if (Convidado) {
        return true;
    }
    return get_ResetGuest(instance);
}


bool(*Emulator)(bool* instance);
bool _Emulator(bool* instance) {
    if (PcL) {
        return false;
    }
    return Emulator(instance);
}

bool(*FastWeapon)(bool* instance);
bool _FastWeapon(bool* instance) {

        return false;
    }
    
bool(*bypasss)(void* player);
bool _bypasss(void* player){
    return false;{
  
 }
 
 return bypasss(player);
}



struct COW_GamePlay_IHAAMHPPLMG_o {
    uint32_t NBPDJAAAFBH;
    uint32_t JEDDPHIHGKL;
    uint8_t IOICFFEKAIL;
    uint8_t PHAFNFOFFDB;
    uint64_t BNFAIDHEHOM;
};
struct COW_GamePlay_MKFEKBKJCKE_o;

#include <chrono>


/*
int (*orig_PlayerNetwork_TakeDamage)(void *_this, int32_t baseDamage, COW_GamePlay_IHAAMHPPLMG_o damager, void *damageInfo, int32_t weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, uint32_t damagerVehicleID);
int hook_PlayerNetwork_TakeDamage(void *_this, int32_t baseDamage, COW_GamePlay_IHAAMHPPLMG_o damager, void *damageInfo, int32_t weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, uint32_t damagerVehicleID) {
if (_this != NULL && Headshot) 
{
if (damageInfo != NULL) {
*(int *)((long) damageInfo + 0xC) = 1;
hitPos = GetHeadPosition(_this);
}
}
return orig_PlayerNetwork_TakeDamage(_this, baseDamage, damager, damageInfo, weaponDataID, firePos, hitPos, checkParams, damagerWeaponDynamicInfo, damagerVehicleID);
}
*/
//void *GetClosestEnemy(void *match) {


// RudeyCheats Headshot Hook – Only real, direct, brutal
int (*orig_PlayerNetwork_TakeDamage)(void *_this, int32_t baseDamage, COW_GamePlay_IHAAMHPPLMG_o damager, void *damageInfo, int32_t weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, uint32_t damagerVehicleID);

int hook_PlayerNetwork_TakeDamage(void *_this, int32_t baseDamage, COW_GamePlay_IHAAMHPPLMG_o damager, void *damageInfo, int32_t weaponDataID, Vector3 firePos, Vector3 hitPos, monoList<float> checkParams, void *damagerWeaponDynamicInfo, uint32_t damagerVehicleID) {
    if (_this != NULL && Headshot) {
        if (damageInfo != NULL) {
            // Body pe hit position wahi rahega (no change)
            // Lekin damageInfo me headshot flag lag jayega
            *(int *)((uintptr_t)damageInfo + 0xC) = 1; // Headshot flag set
        }
    }
    return orig_PlayerNetwork_TakeDamage(_this, baseDamage, damager, damageInfo, weaponDataID, firePos, hitPos, checkParams, damagerWeaponDynamicInfo, damagerVehicleID);
}

/*


bool (*Pclogo)(void* _this);
bool _Pclogo(void* _this) {
        return false;
}*/


bool (*Pclogo)(void* _this);

// Hooked function that will bypass the original logic
bool _Pclogo(void* _this) {
    // Check if the original function is valid
    if (Pclogo != NULL) {
        // Return false to block whatever restriction logic this function performs
        return false;
}
}
/*

void (*AimSilent_Backup)(void *, float, float);
void AimSilent_Hook(void *_this, float a1, float a2) {
    if (_this != nullptr) {
    void* Match = Curent_Match();
        if (AimSilent && Function && Match) {                           
                void * enemyPlayer = GetLocalPlayer();
                if (enemyPlayer != NULL) {
                    if (get_IsFiring(enemyPlayer) && Match) {
                        return;
                    } else {
                        AimSilent_Backup(_this, a1, a2);
                    }
                }            
        
    }
    AimSilent_Backup(_this, a1, a2);
}
}*/

void (*AimSilent_Backup)(void *, float, float);
void AimSilent_Hook(void *_this, float a1, float a2) {
    if (_this != nullptr) {
    void* Match = Curent_Match();
        if (AimSilent && Function && Match) {                           
                void * enemyPlayer = GetLocalPlayer();
                if (enemyPlayer != NULL) {
                    if (get_IsFiring(enemyPlayer) && Match) {
                        return;
                    } else {
                        AimSilent_Backup(_this, a1, a2);
                    }
                }            
        
    }
    AimSilent_Backup(_this, a1, a2);
}
}



/*

void *imgui_go(void *) {
    sleep(13);

    address = findLibrary(libil2cpp);
	
    auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    
    DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);

//DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);
//ban fix bypass 

*/


void *imgui_go(void *) {
    sleep(10);

    address = findLibrary(libil2cpp);
	
    auto addr = (uintptr_t)dlsym(RTLD_NEXT, "eglSwapBuffers");
    
    DobbyHook((void *)addr, (void *)hook_eglSwapBuffers, (void **)&old_eglSwapBuffers);


rohan.Vbadge = MemoryPatch("libil2cpp.so",0x42c262c,"\x01\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);
//rohan.FastSwitch = MemoryPatch("libil2cpp.so", 0x1312394,"01 00 A0 E3 1E FF 2F E1",8); 
rohan.WallH = MemoryPatch::createWithHex("libunity.so", 0xb87d10, "0D FA 9D 6D");
rohan.Wallh = MemoryPatch::createWithHex("libunity.so", 0xb87d10, "0D FA 9D ED");
rohan.SpeedA = MemoryPatch::createWithHex("libil2cpp.so", 0x6359d90, "01 00 A0 E3 1E FF 2F E1",8);
rohan.Speedb = MemoryPatch::createWithHex("libil2cpp.so", 0x146ec58, "01 00 A0 E3 1E FF 2F E1",8);
	    
rohan.SpeedY = MemoryPatch::createWithHex("libil2cpp.so", 0x5d8c55c, "14 00 A0 E3 1E FF 2F E1",8);
rohan.Night = MemoryPatch::createWithHex("libunity.so",0x2F7F78, "00 00 80 BF"); 
rohan. SwapnilM = MemoryPatch("libil2cpp.so",0x130003c,"\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);//ok
	 
rohan.SwapnilB = MemoryPatch::createWithHex("libil2cpp.so", 0x4dde8c8, "01 00 A0 E3 1E FF 2F E1");//ok

rohan.SwapnilG = MemoryPatch::createWithHex("libil2cpp.so", 0x3a663a0, "99 05 A0 E3 1E FF 2F E1");//ok,
	
rohan.SwapnilD = MemoryPatch::createWithHex("libil2cpp.so", 0x3a663b0, "99 05 A0 E3 1E FF 2F E1");//o
	
rohan. Swapnil7 = MemoryPatch("libil2cpp.so",0x2e8bb8c,"\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);//
rohan.Swapnil8 = MemoryPatch("libil2cpp.so",0x127cfc8,"\x00\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);//

//rohan.Vbadge = MemoryPatch("libil2cpp.so",0x56ebe98,"\x01\x00\xA0\xE3\x1E\xFF\x2F\xE1", 8);

//rohan.WallH = MemoryPatch::createWithHex("libunity.so",0xb87d10, "00 00 00 EA");
//rohan.SpeedA = MemoryPatch::createWithHex("libil2cpp.so", 0x5d8c0f4, "01 00 A0 E3 1E FF 2F E1",8);
//rohan.Speedb = MemoryPatch::createWithHex("libil2cpp.so", 0x135aba4, "01 00 A0 E3 1E FF 2F E1",8);
	    

/*
DobbyHook((void *)getRealOffset(0x1278444), (void *)AimSilent_Hook, (void **)&AimSilent_Backup);



DobbyHook((void *)getRealOffset(0x5c04650), (void *)_Pclogo, (void **)&Pclogo);
DobbyHook((void *)getRealOffset(0x5c03cb8), (void *)_Pclogo, (void **)&Pclogo);
DobbyHook((void *)getRealOffset(0x5c03bc8), (void *)_Pclogo, (void **)&Pclogo);
 */

 DobbyHook((void *)getRealOffset(0x2b2a21c), (void *)AimSilent_Hook, (void **)&AimSilent_Backup);
 
 /*
 DobbyHook((void *)getRealOffset(0x6182268), (void *)_Pclogo, (void **)&Pclogo);
 DobbyHook((void *)getRealOffset(0x6183960), (void *)_Pclogo, (void **)&Pclogo);
 
 */
 DobbyHook((void *)getRealOffset(0x2bf1734), (void *)_SpeedFix, (void **)&SpeedFix);//MADE BY;- @ur_nikuu
 DobbyHook((void *)getRealOffset(0x7335490), (void *)_SpeedFix, (void **)&SpeedFix);//

   //DobbyHook((void *)getRealOffset(0x1278444), (void *)AimSilent_Hook, (void **)&AimSilent_Backup);

//DobbyHook((void *)getRealOffset(0x29266a0), (void *)_GetSpeedScaleBySpeedType, (void **)&GetSpeedScaleBySpeedType);
    DobbyHook((void *)getRealOffset(0x29245bc), (void *)_GetWeaponRunSpeedScale, (void **)&GetWeaponRunSpeedScale);

  //  DobbyHook((void *)getRealOffset(0x6926e74), (void *)_get_IsRunningOnWindows_Hook, (void **)&original_get_IsRunningOnWindows);
   // DobbyHook((void *)getRealOffset(0x5d8c55c), (void *)_SpeedFix, (void **)&SpeedFix);
 //DobbyHook((void *)getRealOffset(0x135abb4), (void *)_SpeedFix, (void **)&SpeedFix);
//HOOK(0x2da4074, _DataWeapon1, DataWeapon1); //



DobbyHook((void *)getRealOffset(0x5f4e520), (void *)_get_ResetGuest, (void **)&get_ResetGuest);

   // DobbyHook((void *)connect_addr, (void *)my_connect, (void **)&original_connect);
    DobbyHook((void *)getRealOffset(0x1a0237c), (void *)hook_PlayerNetwork_TakeDamage, (void **)&orig_PlayerNetwork_TakeDamage);
    
	  return NULL;
    
}/*

void *pLibRealUnity = 0;

JavaVM *jvm;
JNIEnv *genv;

typedef jint(JNICALL *CallJNI_OnLoad_t)(JavaVM *vm, void *reserved);

typedef void(JNICALL *CallJNI_OnUnload_t)(JavaVM *vm, void *reserved);

CallJNI_OnLoad_t RealJNIOnLoad = 0;
CallJNI_OnUnload_t RealJNIOnUnload = 0;

JNIEXPORT jint JNICALL CallJNIOL(
        JavaVM *vm, void *reserved) {
    LOGI("Exec %s", RealLibToLoad);
    if (!pLibRealUnity)
        pLibRealUnity = dlopen(RealLibToLoad, RTLD_NOW);
    if (!RealJNIOnLoad)
        RealJNIOnLoad = reinterpret_cast<CallJNI_OnLoad_t>(dlsym(pLibRealUnity, "JNI_OnLoad"));
    return RealJNIOnLoad(vm, reserved);
}

JNIEXPORT void JNICALL CallJNIUL(
        JavaVM *vm, void *reserved) {
    if (!pLibRealUnity)
        pLibRealUnity = dlopen(RealLibToLoad, RTLD_NOW);
    if (!RealJNIOnUnload)
        RealJNIOnUnload = reinterpret_cast<CallJNI_OnUnload_t>(dlsym(pLibRealUnity,
                                                                     "JNI_OnUnload"));
    RealJNIOnUnload(vm, reserved);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("Initialize JNI");
    jvm = vm;
    return CallJNIOL(vm, reserved);
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGI("Unload JNI");

    CallJNIUL(vm, reserved);
}

__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, imgui_go, NULL);
	
}*/


void *pLibRealUnity = 0;

JavaVM *jvm;
JNIEnv *genv;

typedef jint(JNICALL *CallJNI_OnLoad_t)(JavaVM *vm, void *reserved);

typedef void(JNICALL *CallJNI_OnUnload_t)(JavaVM *vm, void *reserved);

CallJNI_OnLoad_t RealJNIOnLoad = 0;
CallJNI_OnUnload_t RealJNIOnUnload = 0;

JNIEXPORT jint JNICALL CallJNIOL(
        JavaVM *vm, void *reserved) {
    LOGI("Exec %s", RealLibToLoad);
    if (!pLibRealUnity)
        pLibRealUnity = dlopen(RealLibToLoad, RTLD_NOW);
    if (!RealJNIOnLoad)
        RealJNIOnLoad = reinterpret_cast<CallJNI_OnLoad_t>(dlsym(pLibRealUnity, "JNI_OnLoad"));
    return RealJNIOnLoad(vm, reserved);
}

JNIEXPORT void JNICALL CallJNIUL(
        JavaVM *vm, void *reserved) {
    if (!pLibRealUnity)
        pLibRealUnity = dlopen(RealLibToLoad, RTLD_NOW);
    if (!RealJNIOnUnload)
        RealJNIOnUnload = reinterpret_cast<CallJNI_OnUnload_t>(dlsym(pLibRealUnity,
                                                                     "JNI_OnUnload"));
    RealJNIOnUnload(vm, reserved);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("Initialize JNI");
    jvm = vm;
    return CallJNIOL(vm, reserved);
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGI("Unload JNI");

    CallJNIUL(vm, reserved);
}

__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, imgui_go, NULL);
}


