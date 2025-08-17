#ifndef ANDROID_MOD_MENU_PSTATIC_H
#define ANDROID_MOD_MENU_PSTATIC_H
#include "pAdress.h"
# define getRealOffset(offset) AgetAbsoluteAddress("libil2cpp.so",offset)
long AfindLibrary(const char *library) {
    char filename[0xFF] = {0},
    buffer[1024] = {0};
    FILE *fp = nullptr;
    long address = 0;
// ============================= { 𝖙𝖌 @𝖎𝖙𝖘𝖗𝖔𝖍𝖎𝖙𝖔𝖕 ========================================== //

    sprintf(filename, "/proc/self/maps");

    fp = fopen( filename, "rt" );
    if( fp == nullptr ){
        perror("fopen");
        goto done;
    }

    while( fgets( buffer, sizeof(buffer), fp ) ) {
        if(strstr( buffer, library ) ){
            address = (long)strtoul( buffer, NULL, 16 );
            goto done;
        }
    }

    done:

    if(fp){
        fclose(fp);
    }
    return address;
}

long ClibBase;

long AgetAbsoluteAddress(const char* libraryName, long relativeAddr) {
    if (ClibBase == 0) {
        ClibBase = AfindLibrary(libraryName);
        if (ClibBase == 0) {
            ClibBase = 0;
        }
    }
    return ClibBase + relativeAddr;
}

class Vvector3 {
public:
    float X;
    float Y;
    float Z;

    // Default constructor
    Vvector3() : X(0), Y(0), Z(0) {}

    // Parameterized constructor
    Vvector3(float x1, float y1, float z1) : X(x1), Y(y1), Z(z1) {}

    // Copy constructor
    Vvector3(const Vvector3 &v) : X(v.X), Y(v.Y), Z(v.Z) {}

    // Destructor
    ~Vvector3() {}
};


static void *GetLocalPlayer() {
    void *(*_GetLocalPlayer)(void *match) = (void *(*)(void *))getRealOffset(pAdress.GetLocalPlayer);
    return _GetLocalPlayer(nullptr);
}

static bool get_isLocalTeam(void *player) {
    bool (*_get_isLocalTeam)(void *player) = (bool (*)(void *))getRealOffset(pAdress.get_isLocalTeam);
    return _get_isLocalTeam(player);
}

static bool get_IsDieing(void *player) {
    bool (*_get_IsDieing)(void *player) = (bool (*)(void *))getRealOffset(pAdress.get_IsDieing);
    return _get_IsDieing(player);
}

static int get_MaxHP(void *enemy) {
    int (*_get_MaxHP)(void *player) = (int (*)(void *))getRealOffset(pAdress.get_MaxHP);
    return _get_MaxHP(enemy);
}

static bool get_IsFiring(void *player) {
    bool (*_get_IsFiring)(void *player) = (bool (*)(void *))getRealOffset(pAdress.get_IsFiring);
    return _get_IsFiring(player);
}

static bool get_IsSighting(void *player) {
    bool (*_get_IsSighting)(void *player) = (bool (*)(void *))getRealOffset(pAdress.get_IsSighting);
    return _get_IsSighting(player);
}

static bool get_isVisible(void *player) {
    bool (*_get_isVisible)(void *player) = (bool (*)(void *))getRealOffset(pAdress.get_isVisible);
    return _get_isVisible(player);
}

static Vector3 GetForward(void *player) {
    Vector3 (*_GetForward)(void *player) = (Vector3 (*)(void *))getRealOffset(pAdress.GetForward);
    return _GetForward(player);
}

static void set_aim(void *player, Quaternion look) {
    void (*_set_aim)(void *player, Quaternion look) = (void (*)(void *, Quaternion))getRealOffset(pAdress.set_aim);
    _set_aim(player, look);
}

static void *Component_GetTransform(void *player) {
    void *(*_Component_GetTransform)(void *component) = (void *(*)(void *))getRealOffset(pAdress.Component_GetTransform);
    return _Component_GetTransform(player);
}

static void *Camera_main() {
    void *(*_Camera_main)(void *nuls) = (void *(*)(void *))getRealOffset(pAdress.Camera_main);
    return _Camera_main(nullptr);
}


#endif
