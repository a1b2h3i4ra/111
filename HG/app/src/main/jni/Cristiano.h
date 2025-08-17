#include "Includes.h"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Quaternion.hpp"
#include "Rect.hpp"
#include "Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "pStatic.h"


#include <iostream>
/*==========================*/
#define getRealOffset(offset) AgetAbsoluteAddress("libil2cpp.so",offset)

bool FOV = true;
bool AimSquat = false;
bool Headshot = false;
bool AimAuto = false;
bool pclogooo = false;
bool Function = false;
bool Aimshoot = false;
bool AimScope = false;
bool AimVisible = false;
bool Convidado = false;
bool AimSilent = false;
bool isSpeedSafe = false;
bool CamViewC = false;
const char* selectedLabel = " R D X ";  // Default label
bool WallH = false;
bool Wallh = false;
//bool Pclogo = false;
bool FastSwitch = false;
bool Vbadge = false;
bool Night = false;
//bool MFunction = true;
bool SwapnilB = false;// Default label
bool SwapnilM = false;
bool hackss_thread = false;
bool MFunction = true;
bool PcL = false;
bool AimKill = false;
bool Bhai = false;
bool SwapnilV = false;
//bool Bhai = false;
bool SwapnilG = false;
bool SPJ = false;
bool SwapnilD = false;
//bool Convidado = false;
bool EspHealth = false;
//bool Bhai = false;
bool Speed = false;

int  glWidth, glHeight;

int AimFov = 0;

bool EspLinha = false;
bool EspLinhaT = false;
bool EspCiruleHead = false;
int isSpeed = 0;  
int CamView = 0;

ImVec4 esp_color1 = ImVec4(0, 0, 0, 1.00f);
ImVec4 esp_color2 = ImVec4(0, 1, 0, 0.00f);
ImVec4 esp_color3 = ImVec4(0, 1, 0, 0.00f);

ImVec4 esp_text_color = ImVec4(1, 1, 1, 1.00f);


struct My_Patches {
MemoryPatch  SpeedA,Speedb,SwapnilG,SwapnilD,SwapnilV,SwapnilM,SwapnilB,Swapnil7,Swapnil8,WallH,Wallh,Night,SpeedY,Vbadge;
}rohan;
	



/*

static Vector3 Transform_INTERNAL_GetPosition(void *player) {
    Vector3 out = Vector3::Zero();
    void (*_Transform_INTERNAL_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(pAdress.Transform_INTERNAL_GetPosition);
    _Transform_INTERNAL_GetPosition(player, &out);
    return out;
}

static void Transform_INTERNAL_SetPosition(void *player, Vvector3 inn) {
    void (*Transform_INTERNAL_SetPosition)(void *transform, Vvector3 in) = (void (*)(void *, Vvector3))getRealOffset(pAdress.Transform_INTERNAL_SetPosition);
    Transform_INTERNAL_SetPosition(player, inn);
}

static void *Player_GetHeadCollider(void *player) {
    void *(*_Player_GetHeadCollider)(void *players) = (void *(*)(void *))getRealOffset(pAdress.Player_GetHeadCollider);
    return _Player_GetHeadCollider(player);
}

static bool Physics_Raycast(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) {
    bool (*_Physics_Raycast)(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) = (bool(*)(Vector3, Vector3, unsigned int, void*))getRealOffset(pAdress.Physics_Raycast);
    return _Physics_Raycast(camLocation, headLocation, LayerID, collider);
}

static void *GetHeadTF(void* player) {
    void *(*_GetHeadTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.HeadTF);
    return _GetHeadTF(player);
}

Vector3 GetHeadPosition(void* player) {
    return Transform_INTERNAL_GetPosition(Component_GetTransform(GetHeadTF(player)));
}

static void *Curent_Match() {
    void *(*_Curent_Match) (void *nuls) = (void *(*)(void *))getRealOffset(pAdress.Curent_Match);
    return _Curent_Match(NULL);
}

Vector3 CameraMain(void* player) {
    return Transform_INTERNAL_GetPosition(*(void**) ((uint64_t) player + pAdress.MainCameraTransform));
}

static Vector3 WorldToScreenPoint(void *WorldCam, Vector3 WorldPos) {
    Vector3 (*_WorldToScreenScene)(void* Camera, Vector3 position) = (Vector3 (*)(void*, Vector3)) getRealOffset(pAdress.WorldToScreenPoint);
    return _WorldToScreenScene(WorldCam,WorldPos);
}




namespace Desenhar
{
    void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness = 1.0f)  // Default thickness is 1.0f
    {
        auto background = ImGui::GetBackgroundDrawList();

        if (background)
        {
            background->AddLine(
                start, 
                end, 
                ImColor((int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255), (int)(color.w * 255)), 
                thickness  // Apply thickness here
            );
        }
    }

    void DrawBox(Rect rect, ImVec4 color)
    {
        ImVec2 v1(rect.x, rect.y);
        ImVec2 v2(rect.x + rect.width, rect.y);
        ImVec2 v3(rect.x + rect.width, rect.y + rect.height);
        ImVec2 v4(rect.x, rect.y + rect.height);

        DrawLine(v1, v2, color);
        DrawLine(v2, v3, color);
        DrawLine(v3, v4, color);
        DrawLine(v4, v1, color);
    }

    void Text(float fontSize, ImVec2 position, ImVec4 color, const char *text)
    {
        auto background = ImGui::GetBackgroundDrawList();

        if (background) {
            background->AddText(NULL, fontSize, position, ImColor((int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255), (int)(color.w * 255)), text);
        }
    }
}

*/



static Vector3 Transform_INTERNAL_GetPosition(void *player) {
    Vector3 out = Vector3::Zero();
    void (*_Transform_INTERNAL_GetPosition)(void *transform, Vector3 * out) = (void (*)(void *, Vector3 *))getRealOffset(pAdress.Transform_INTERNAL_GetPosition);
    _Transform_INTERNAL_GetPosition(player, &out);
    return out;
}

static void Transform_INTERNAL_SetPosition(void *player, Vvector3 inn) {
    void (*Transform_INTERNAL_SetPosition)(void *transform, Vvector3 in) = (void (*)(void *, Vvector3))getRealOffset(pAdress.Transform_INTERNAL_SetPosition);
    Transform_INTERNAL_SetPosition(player, inn);
}

static void *Player_GetHeadCollider(void *player) {
    void *(*_Player_GetHeadCollider)(void *players) = (void *(*)(void *))getRealOffset(pAdress.Player_GetHeadCollider);
    return _Player_GetHeadCollider(player);
}

static bool Physics_Raycast(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) {
    bool (*_Physics_Raycast)(Vector3 camLocation, Vector3 headLocation, unsigned int LayerID, void* collider) = (bool(*)(Vector3, Vector3, unsigned int, void*))getRealOffset(pAdress.Physics_Raycast);
    return _Physics_Raycast(camLocation, headLocation, LayerID, collider);
}

static void *GetHeadTF(void* player) {
    void *(*_GetHeadTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.HeadTF);
    return _GetHeadTF(player);
}

Vector3 GetHeadPosition(void* player) {
    return Transform_INTERNAL_GetPosition(Component_GetTransform(GetHeadTF(player)));
}

static void *Curent_Match() {
    void *(*_Curent_Match) (void *nuls) = (void *(*)(void *))getRealOffset(pAdress.Curent_Match);
    return _Curent_Match(NULL);
}

Vector3 CameraMain(void* player) {
    return Transform_INTERNAL_GetPosition(*(void**) ((uint64_t) player + pAdress.MainCameraTransform));
}

static Vector3 WorldToScreenPoint(void *WorldCam, Vector3 WorldPos) {
    Vector3 (*_WorldToScreenScene)(void* Camera, Vector3 position) = (Vector3 (*)(void*, Vector3)) getRealOffset(pAdress.WorldToScreenPoint);
    return _WorldToScreenScene(WorldCam,WorldPos);
}



static int get_CurHP(void *player) {
int (*_get_CurHP)(void *players) = (int (*)(void *))getRealOffset(0x2b9b398); // private Void MCCCICMHEAG(LevelJumpPad ELGHNHEBHPK) { }
return _get_CurHP(player);
}


static void *GetLeftToeTF(void* player) {
    void *(*_GetLeftToeTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.LeftToeTF);
    return _GetLeftToeTF(player);
}

Vector3 GetLeftToePosition(void* player) {
    return Transform_INTERNAL_GetPosition(Component_GetTransform(GetLeftToeTF(player)));
}

static void *GetRightToeTF(void* player) {
    void *(*_GetRightToeTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.RightToeTF);
    return _GetRightToeTF(player);
}

static void *GetHipTF(void* player) {
    void *(*_GetHipTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.HipTF);
    return _GetHipTF(player);
}


static void *get_LeftHandTF(void* player) {
    void *(*_get_LeftHandTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.LeftHandTF);
    return _get_LeftHandTF(player);
}

Vector3 GetLeftHandPosition(void* player) {
    return Transform_INTERNAL_GetPosition(Component_GetTransform(get_LeftHandTF(player)));
}

static void *get_RightHandTF(void* player) {
    void *(*_get_RightHandTF)(void *_this) = (void *(*)(void *))getRealOffset(pAdress.RightHandTF);
    return _get_RightHandTF(player);
}

Vector3 GetRightHandPosition(void* player) {
    return Transform_INTERNAL_GetPosition(Component_GetTransform(get_RightHandTF(player)));
}


namespace Desenhar
{
    void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness = 1.0f)  // Default thickness is 1.0f
    {
        auto background = ImGui::GetBackgroundDrawList();

        if (background)
        {
            background->AddLine(
                start, 
                end, 
                ImColor((int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255), (int)(color.w * 255)), 
                thickness  // Apply thickness here
            );
        }
    }

    void DrawBox(Rect rect, ImVec4 color)
    {
        ImVec2 v1(rect.x, rect.y);
        ImVec2 v2(rect.x + rect.width, rect.y);
        ImVec2 v3(rect.x + rect.width, rect.y + rect.height);
        ImVec2 v4(rect.x, rect.y + rect.height);

        DrawLine(v1, v2, color);
        DrawLine(v2, v3, color);
        DrawLine(v3, v4, color);
        DrawLine(v4, v1, color);
    }

    void Text(float fontSize, ImVec2 position, ImVec4 color, const char *text)
    {
        auto background = ImGui::GetBackgroundDrawList();

        if (background) {
            background->AddText(NULL, fontSize, position, ImColor((int)(color.x * 255), (int)(color.y * 255), (int)(color.z * 255), (int)(color.w * 255)), text);
        }
    }
}





bool DrawFov = false;



void Start_Linhas2()  {
	
    if (Function) {
        
        void* match = Curent_Match();
	   
        void* LocalPlayer = GetLocalPlayer();
    
        if(LocalPlayer != NULL) {
    
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)match + pAdress.Dictionary);
      
	    for(int u = 0; u < players->getNumValues(); u++) {
     
	    void* Player = players->getValues()[u];
            
        if(Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {
                        
        Vector3 Head = WorldToScreenPoint(Camera_main(), Transform_INTERNAL_GetPosition(GetHeadTF(Player)));
       
		if (DrawFov) {
        ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(glWidth / 2.0f, glHeight / 2.0f), AimFov*0.5f, ImColor((int) (esp_color3.x * 255), (int) (esp_color3.y * 255), (int) (esp_color3.z * 255), 255), 100, 2.0f);
        }
		
     
		
                               // Ensure Head position is in front
                        if (Head.Z < 0) continue;
// Draw line to enemy if enabled
						
		/*				
		if (EspHealth ) {
    int CurHP = get_CurHP(Player);
    int MaxHP = get_MaxHP(Player);
 
 
 
    std::string hpText = std::to_string(CurHP) + " / " + std::to_string(MaxHP);

// Default health color: Red if dying, otherwise use esp_health_color
    ImColor healthColor = (!get_IsDieing(Player)) ? 
        ImColor((int)(esp_health_color.x * 255), (int)(esp_health_color.y * 255), (int)(esp_health_color.z * 255), 255) : 
        ImColor(255, 0, 0, 255); // Red color if dying

    // Calculate position for the HP text
    ImVec2 textPos = ImVec2(Head.X - ImGui::CalcTextSize(hpText.c_str()).x / 2, glHeight - Head.Y - 65);
    float textThicknessOffset = 1.1f;
    ImVec2 textSize = ImGui::CalcTextSize(hpText.c_str());

    // Check health and set the background color accordingly
    ImColor textBackgroundColor;
    if (CurHP > 0 && CurHP <= 80) {
        textBackgroundColor = ImColor(255, 0, 0, 150);  // Red with transparency for low HP
    } else {
        textBackgroundColor = ImColor(0, 0, 0, 150);  // Black with transparency for higher HP
    }

    // Add semi-transparent background behind the health text for better readability
    ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(textPos.x - padding - 2, textPos.y - padding - 2), 
                                                  ImVec2(textPos.x + textSize.x + padding + 2, textPos.y + textSize.y + padding + 2), 
                                                  textBackgroundColor, 5.0f);  // Rounded corners

    // Draw the health text with the selected color
    ImGui::GetBackgroundDrawList()->AddText(textPos, healthColor, hpText.c_str());
}				
						
			
						*/
						
						
						
if (EspLinha) {
    ImColor lineColor = (!get_IsDieing(Player)) ? 
        ImColor((int)(esp_color1.x * 255), (int)(esp_color1.y * 255), (int)(esp_color1.z * 255), 255) : 
        ImColor(255, 0, 0, 255);

    // Adjust thickness
    float lineThickness = 2.1f;
    
    // Draw the line with specified thickness
    Desenhar::DrawLine(
        {(float)glWidth / 2, 1}, 
        ImVec2(Head.X, glHeight - Head.Y), 
        lineColor, 
        lineThickness
    );
}

if (EspLinhaT) {
    ImColor textColor = (!get_IsDieing(Player)) ? 
        ImColor((int)(esp_text_color.x * 255), (int)(esp_text_color.y * 255), (int)(esp_text_color.z * 255), 255) : 
        ImColor(255, 0, 0, 255);

    // Calculate position for text and thickness
    ImVec2 textPos = ImVec2(Head.X - ImGui::CalcTextSize(selectedLabel).x / 2, glHeight - Head.Y - 35);
    float textThicknessOffset = 1.1f;

    // Draw text multiple times around the original position to create a thicker look
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(textPos.x - textThicknessOffset, textPos.y), textColor, selectedLabel);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(textPos.x + textThicknessOffset, textPos.y), textColor, selectedLabel);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(textPos.x, textPos.y - textThicknessOffset), textColor, selectedLabel);
    ImGui::GetBackgroundDrawList()->AddText(ImVec2(textPos.x, textPos.y + textThicknessOffset), textColor, selectedLabel);

    // Draw the original text in the center to fill in any gaps
    ImGui::GetBackgroundDrawList()->AddText(textPos, textColor, selectedLabel);
}


// Draw circle on enemy head with a slight offset below the text to avoid overlap
if (EspCiruleHead) {
    ImColor circleColor = (!get_IsDieing(Player)) ? 
        ImColor((int)(esp_color2.x * 255), (int)(esp_color2.y * 255), (int)(esp_color2.z * 255), 255) : 
        ImColor(255, 0, 0, 255);

    ImGui::GetBackgroundDrawList()->AddCircle(
        ImVec2(Head.X, glHeight - Head.Y + 20), // Offset the circle slightly downward
        20, 
        circleColor, 
        700, 
        1.1f
    );
}
	
           }
         }
      }
    }
}

/*
bool isVisible(void *enemy)  {
    if(enemy != NULL)  {
         void *hitObj = NULL;
         auto Camera = Transform_INTERNAL_GetPosition(Component_GetTransform(Camera_main()));
         auto Target = Transform_INTERNAL_GetPosition(Component_GetTransform(Player_GetHeadCollider(enemy)));
         return !Physics_Raycast(Camera, Target, 12, &hitObj);
    }
    return false;
}

Quaternion GetRotationToTheLocation(Vector3 Target, float Height, Vector3 MyEnemy) {
return Quaternion::LookRotation((Target + Vector3(0, Height, 0)) - MyEnemy, Vector3(0, 1, 0));
}

void *GetClosestEnemy(void *match) {
    if(!match) {
        return nullptr;
    }
	
    float shortestDistance = 99999.0f;
    float maxAngle = AimFov;
    
    void* closestEnemy = NULL;
    void* LocalPlayer = GetLocalPlayer();
    
    if(LocalPlayer != NULL) {
    
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t*, void **> **)((long)match + pAdress.Dictionary);
        for(int u = 0; u < players->getNumValues(); u++) {
            void* Player = players->getValues()[u];
            
            if(Player != NULL && !get_isLocalTeam(Player) && !get_IsDieing(Player) && get_isVisible(Player) && get_MaxHP(Player)) {
            
                Vector3 PlayerPos = GetHeadPosition(Player);
                Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);
                	if (AimVisible) {
                    if (isVisible(Player)) {
                
					 Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                        float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;
                        if(angle <= maxAngle) {
                            if(angle < shortestDistance) {
                                shortestDistance = angle;
                                closestEnemy = Player;
                            }
                        }
                    }
                } else if (!AimVisible) {
           
			   Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                    float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0;
                    if (angle <= maxAngle) {
                        if (angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                        }
                    }
                }
            }
        }
   }
   return closestEnemy;
}

   */




bool isVisible(void *enemy)  {
    if(enemy != NULL)  {
         void *hitObj = NULL;
         auto Camera = Transform_INTERNAL_GetPosition(Component_GetTransform(Camera_main()));
         auto Target = Transform_INTERNAL_GetPosition(Component_GetTransform(Player_GetHeadCollider(enemy)));
         return !Physics_Raycast(Camera, Target, 12, &hitObj);
    }
    return false;
}

Quaternion GetRotationToTheLocation(Vector3 Target, float Height, Vector3 MyEnemy) {
return Quaternion::LookRotation((Target + Vector3(0, Height, 0)) - MyEnemy, Vector3(0, 1, 0));
}





// RudeyCheats IS DADDY

void *GetClosestEnemy(void *match) {
    if (!match) return nullptr;

    float shortestDistance = 99999.0f;
    float maxAngle = 360.0f; // Already brutal
    void *closestEnemy = nullptr;
    void *LocalPlayer = GetLocalPlayer();

    if (LocalPlayer != NULL) {
        monoDictionary<uint8_t *, void **> *players = *(monoDictionary<uint8_t *, void **> **)((long)match + pAdress.Dictionary);

        for (int u = 0; u < players->getNumValues(); u++) {
            void *Player = players->getValues()[u];

            if (Player != NULL 
                && Player != LocalPlayer 
                && !get_IsDieing(Player)) { // Keep dying check only

                Vector3 PlayerPos = GetHeadPosition(Player);
                Vector3 LocalPlayerPos = GetHeadPosition(LocalPlayer);

                Vector3 targetDir = Vector3::Normalized(PlayerPos - LocalPlayerPos);
                float angle = Vector3::Angle(targetDir, GetForward(Component_GetTransform(Camera_main()))) * 100.0f;

                if (AimVisible) {
                    if (isVisible(Player)) {
                        if (angle <= maxAngle && angle < shortestDistance) {
                            shortestDistance = angle;
                            closestEnemy = Player;
                        }
                    }
                } else {
                    if (angle <= maxAngle && angle < shortestDistance) {
                        shortestDistance = angle;
                        closestEnemy = Player;
                    }
                }
            }
        }
    }

    return closestEnemy;
}




void Start_Aimbot2() {
    
 if (isSpeedSafe) {
        isSpeed = 4;
    } else {
        isSpeed = 0;
    }
    
    
    
       
        if (Speed) {
          
             
   rohan.SpeedA.Modify();
   
   rohan.Speedb.Modify();
    
   } else {
          
   rohan.SpeedA.Restore();
   rohan.Speedb.Restore();
   }
 /* if (WallHack) {
    rohan.WallH.Modify();
} else {
    rohan.WallH.Restore();
}       
 if (Vbadge) {
     rohan.Vbadge.Modify();
      } else {
     rohan.Vbadge.Restore();
      }   */
    
  /*if (CamViewC) {
      CamView = 8;
    } else {
        CamView = 0;*/
    
         /*if (Wallh) {
         //
		rohan.Wallhac.Modify();
            
        } else {
            rohan.Wallhac.Restore();
            
        }*/
        
		if (Bhai) {
            
     rohan.Swapnil8.Modify();
      
          } else {    
   rohan.Swapnil7.Restore();
   
		}
		
		if (SwapnilB) {
      rohan. SwapnilB.Modify();
      } else {
     rohan. SwapnilB.Restore();
      }
   
          if (SwapnilV) {
      rohan. SwapnilV.Modify();
       } else {
     rohan. SwapnilV.Restore();
     
	 }
	 
		if (SwapnilG) {
   rohan.SwapnilG.Modify();
        } else {
      rohan.SwapnilG.Restore();
	  
  }
	
  if (SwapnilB) {
      rohan. SwapnilB.Modify();
      } else {
     rohan. SwapnilB.Restore();
	 
      }
	  
	  if (SwapnilM) {
  rohan. SwapnilM.Modify();
     } else {
rohan.SwapnilM.Restore();
    }
		
		if (Night) {
      rohan. Night.Modify();
      } else {
     rohan. Night.Restore();
	 
		}
		
       if (WallH) {   
  rohan.WallH.Modify(); 
   } else {          
 rohan.WallH.Restore();
 
    }
	if (Wallh) {   
  rohan.Wallh.Modify(); 
   } else {          
 rohan.Wallh.Restore();
 
    }
	
	
 if (Vbadge) {
      rohan.Vbadge.Modify();
       } else {
     rohan.Vbadge.Restore();
      }
         
	  
	  /*
    
	if(Function) {
        
        void* Match = Curent_Match();
        void *Camera = Camera_main();
        
        if (Match) {
            void* LocalPlayer = GetLocalPlayer();
            
              if (LocalPlayer) {    

                void* closestEnemy = GetClosestEnemy(Match);
				
                if (closestEnemy && Camera != NULL && !get_IsDieing(closestEnemy)) {
                    
                    Quaternion PlayerHead = GetRotationToLocation(GetHeadPosition(closestEnemy), 0.1f, CameraMain(LocalPlayer));
                    				
                    if (Aimshoot && get_IsFiring(LocalPlayer)) {
                    set_aim(LocalPlayer, PlayerHead);
                    }
				
					
					
					
					
					
					
           }
				}
			}
		}
	}
	*/
	
	
	
	    
        
            if(Function) {
        
        void* Match = Curent_Match();
        void *Camera = Camera_main();
        
        if (Headshot) {
        
        if ((Aimshoot || AimScope || AimVisible) && Match) {
            void* LocalPlayer = GetLocalPlayer();
            
              if (LocalPlayer) {    
                
                void* closestEnemy = GetClosestEnemy(Match);
				
                if (closestEnemy && Camera != NULL && !get_IsDieing(closestEnemy)) {
                    
                    Quaternion PlayerHead = GetRotationToLocation(GetHeadPosition(closestEnemy), 0.0f, CameraMain(LocalPlayer));
                    
                    if (Aimshoot && get_IsFiring(LocalPlayer)) {
                    set_aim(LocalPlayer, PlayerHead);
                    }
                    if (AimScope && get_IsSighting(LocalPlayer)) {
                    set_aim(LocalPlayer, PlayerHead);
                    }
                    if (AimVisible && get_isVisible(LocalPlayer)) {
                    set_aim(LocalPlayer, PlayerHead);          
                    }
				}
			}
		}
	}
}
}

	

/*float (*GetSpeedScaleBySpeedType)(void *instance);

float _GetSpeedScaleBySpeedType(void *instance) {
   
	
	if (instance != nullptr) {
        switch (isSpeed) {
            case 0: return GetSpeedScaleBySpeedType(instance);            
            case 1: return 2.4f;
            case 2: return 2.5f;
            case 3: return 2.6f;
            case 4: return 2.7f;
            case 5: return 2.8f;
            case 6: return 2.9f;
            case 7: return 3.0f;
            case 8: return 3.1f;
            case 9: return 3.2f;
			
            default: return GetSpeedScaleBySpeedType(instance);
        }
		
    }
    return GetSpeedScaleBySpeedType(instance);
}


float (*GetWeaponRunSpeedScale)(void *instance);

float _GetWeaponRunSpeedScale(void *instance) {
	
	
    if (instance != nullptr) {
        switch (isSpeed) {
            case 0: return GetWeaponRunSpeedScale(instance);            
            case 1: return 2.4f;
            case 2: return 2.5f;
            case 3: return 2.6f;
            case 4: return 2.7f;
            case 5: return 2.8f;
            case 6: return 2.9f;
            case 7: return 3.0f;
            case 8: return 3.1f;
            case 9: return 3.2f;
            default: return GetWeaponRunSpeedScale(instance);
        }
	
    }
    return GetWeaponRunSpeedScale(instance);
}
	*/
	
	float (*GetSpeedScaleBySpeedType)(void *instance);

float _GetSpeedScaleBySpeedType(void *instance) {
   
 
 if (instance != nullptr) {
        switch (isSpeed) {
            case 0: return GetSpeedScaleBySpeedType(instance);            
            case 1: return 2.4f;
            case 2: return 2.5f;
            case 3: return 2.6f;
            case 4: return 2.7f;
            case 5: return 2.8f;
            case 6: return 2.9f;
            case 7: return 3.0f;
            case 8: return 3.1f;
            case 9: return 3.2f;
   
            default: return GetSpeedScaleBySpeedType(instance);
        }
  
    }
    return GetSpeedScaleBySpeedType(instance);
}


float (*GetWeaponRunSpeedScale)(void *instance);

float _GetWeaponRunSpeedScale(void *instance) {
 
 
    if (instance != nullptr) {
        switch (isSpeed) {
            case 0: return GetWeaponRunSpeedScale(instance);            
            case 1: return 2.4f;
            case 2: return 2.5f;
            case 3: return 2.6f;
            case 4: return 2.7f;
            case 5: return 2.8f;
            case 6: return 2.9f;
            case 7: return 3.0f;
            case 8: return 3.1f;
            case 9: return 3.2f;
            default: return GetWeaponRunSpeedScale(instance);
        }
 
    }
    return GetWeaponRunSpeedScale(instance);
}
 
bool (*SpeedFix)();

bool _SpeedFix() {
    return false;
}

/*


bool (*SpeedFix)();

bool _SpeedFix() {
    return true;
}*/
//float cameraOffsets[] = {3.0f, 3.1f, 3.2f, 3.3f, 3.4f, 3.5f, 3.6f, 3.7f, 3.8f, 3.9f};

// Original function pointer
//float (*CameraView)(void *instance);

// Hooked camera view function
//float _CameraView(void *instance) {
   // if (instance != nullptr) {
 

	
       // if (CamView == 0) {
        //    return CameraView(instance); // Original function behavior
      //  } else if (CamView >= 1 && CamView <= 10) {
        //    return cameraOffsets[CamView - 1];
      //  }
		
		//}
		
    
	
	/*static void *GetLocalPlayer3(void* Match) {
    void *(*_GetLocalPlayer3)(void *match) = (void *(*)(void *))getRealOffset(0x3023434);
    return _GetLocalPlayer3(Match);
}


static bool get_IsCatapultFalling(void *m_catapult){
    bool (*_get_IsCatapultFalling)(void *m_local) = (bool (*)(void *))getAbsoluteAddress(libil2cpp,0x129fa5c);
    return _get_IsCatapultFalling(m_catapult);
}

static void *OnStopCatapultFalling(void* m_Match) {
    void *(*_OnStopCatapultFalling)(void *match) = (void *(*)(void *))getAbsoluteAddress(libil2cpp,0x134c894);
    return _OnStopCatapultFalling(m_Match);
}
static void *get_MyPhsXData(void *player) {
void *(*_get_MyPhsXData)(void *component) = (void *(*)(void *))getRealOffset(pAdress.get_MyPhsXData);//
    return _get_MyPhsXData(player);
}

void FlyHack(void* LocalPlayer) {
    if (!LocalPlayer) return;

    void* Match = Curent_Match();
    if (!Match) return;

    void* MyPhsXData = get_MyPhsXData(LocalPlayer);
    if (!MyPhsXData) return;

    static bool StopCatapult = false;
    
    if (get_IsCatapultFalling(LocalPlayer)) {
        if (!StopCatapult) {
            StopCatapult = true;
            OnStopCatapultFalling(LocalPlayer);
        }
    } else {
        StopCatapult = false;
    }

    // 🔥 **Randomized Flight Speed to Avoid Detection**
    float altura = (FlyUp > 0) ? (FlyUp / 2.0f) : 0.0f;
    float speed = FlySpeed / 100.0f + (rand() % 3) * 0.01f;  // Small random variation

    *(float*)((uintptr_t)MyPhsXData + 0x28) = altura;
    *(float*)((uintptr_t)MyPhsXData + 0x2C) = speed;

    // 🔥 **Smooth Flight Movement**
    Vector3 CurrentPos = Transform_INTERNAL_GetPosition(Component_GetTransform(LocalPlayer));
    Vector3 FlyCamera = CurrentPos + (GetForward(Component_GetTransform(Camera_main())) * speed);

    if (get_IsFiring(LocalPlayer) || get_IsSighting(LocalPlayer)) {
        Transform_INTERNAL_SetPosition(Component_GetTransform(LocalPlayer), Vvector3(CHEATERSX, CHEATERSY, CHEATERSZ));
    } else {
        CHEATERSX = CurrentPos.X;
        CHEATERSY = CurrentPos.Y + altura;  // Keep height stable
        CHEATERSZ = CurrentPos.Z;

        Transform_INTERNAL_SetPosition(Component_GetTransform(LocalPlayer), Vvector3(FlyCamera.X, CHEATERSY, FlyCamera.Z));
    }
}


void (*orig_UpdateBehavior)(void* Player);
void hook_UpdateBehavior(void* Player) {
    if (FlyUp > 0) {
        void* Match = Curent_Match();
        if (Match && MFunction) {
            void* LocalPlayer = GetLocalPlayer3(Match);
            if (LocalPlayer) {
                FlyHack(LocalPlayer);
            }
        }

        // 🔥 **Modifies Speed Only When Flying**
		if(MFunction){
      rohan.SpeedY.Modify();
		}
    } else {
      rohan.SpeedY .Restore();
    }

    orig_UpdateBehavior(Player);
}

bool (*orig_IsPoseFallingHigh)(void* Player);
bool hook_IsPoseFallingHigh(void* Player) {
    if (FlyUp > 0) {
        void* Match = Curent_Match();
        if (Match && MFunction) {
            void* LocalPlayer = GetLocalPlayer3(Match);
            if (LocalPlayer == Player) {
                return true;  // ✅ Prevents falling when FlyUp is active
            }
        }
    }
    return orig_IsPoseFallingHigh(Player);
}

bool (*orig_OnStopCatapultFalling)(void* Player);
bool hook_OnStopCatapultFalling(void* Player) {
    if (FlyUp > 0) {
        void* Match = Curent_Match();
        if (Match && MFunction) {
            void* LocalPlayer = GetLocalPlayer3(Match);
            if (LocalPlayer == Player) {
                return true;  // ✅ Stops falling animation when FlyUp is enabled
            }
        }
    }
    return orig_OnStopCatapultFalling(Player);
}


bool (*orig_IsIgnoreHighFalling)(void* Player);
bool hook_IsIgnoreHighFalling(void* Player) {
    if (FlyUp > 0) {
        void* Match = Curent_Match();
        if (Match && MFunction) {
            void* LocalPlayer = GetLocalPlayer3(Match);
            if (LocalPlayer == Player) {
                return true;  // ✅ Ignores high falls while FlyUp is enabled
            }
        }
    }
    return orig_IsIgnoreHighFalling(Player);
}


bool (*orig_InFallingState)(void *Player);
bool hook_InFallingState(void *Player){
        void *Match = Curent_Match();
        if(Match){
            void *LocalPlayer = GetLocalPlayer3(Match);
            if(LocalPlayer){
                if(Player == LocalPlayer){
                    return false;
                }
            }
        }      
    return orig_InFallingState(Player);
}

float (*orig_GetGravity)(void *Player);
float hook_GetGravity(void *Player){
    if (FlyUp > 0) {
        return -1000.0f;
   }
    return orig_GetGravity(Player);

}
*/
