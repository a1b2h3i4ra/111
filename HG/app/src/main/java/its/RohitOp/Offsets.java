package its.RohitOp;

/**
 * Free Fire Max 2.115 Offsets Configuration
 * Extracted from dump file: FF Max 2.115 [64Bit].cs
 */
public class Offsets {
    
    // Game Version
    public static final String GAME_VERSION = "2.115";
    public static final String TARGET_PACKAGE = "com.dts.freefiremax";
    
    // Unity Engine Offsets
    public static final long UNITY_CORE_MODULE = 0x706d391840L;
    public static final long UNITY_ASSET_BUNDLE_MODULE = 0x706d398cb8L;
    public static final long UNITY_PHYSICS_MODULE = 0x706d471b54L;
    public static final long UNITY_UI_MODULE = 0x706d4d4eacL;
    
    // Memory Addresses (RVA to VA conversions)
    public static final long[] MEMORY_OFFSETS = {
        0x7b45840L, 0x7b4ccb8L, 0x7b4ccc4L, 0x7b4cd30L, 0x7b4cd34L,
        0x7b4cd3cL, 0x7b4cca0L, 0x7b4cd40L, 0x7b4cd8cL, 0x7b4cd38L,
        0x7b4cd98L, 0x7b4cd9cL, 0x880004cL, 0x8800054L, 0x8800058L,
        0x8800184L, 0x8800188L, 0x880018cL, 0x88002a0L, 0x7c25b54L,
        0x7c25b5cL, 0x7c25ce0L, 0x7c25ce8L, 0x7c25d74L, 0x7c25d7cL,
        0x7c25e40L, 0x7c25e48L, 0x7c25d84L, 0x7c25fd4L, 0x25ffe14L,
        0x25ffe1cL, 0x25ffe24L, 0x25ffe2cL, 0x25ffe34L, 0x25ffe3cL,
        0x25ffe44L, 0x25ffe4cL, 0x25ffe54L, 0x25ffe5cL, 0x25ffe64L,
        0x25ffe6cL, 0x25ffe74L, 0x25ffe7cL, 0x25ffe84L, 0x25ffe8cL,
        0x25ffe94L, 0x25ffe9cL, 0x25ffea4L, 0x25ffebcL, 0x7c88eacL,
        0x7c89b98L, 0x7c89e58L, 0x7c89e68L, 0x7c89e70L, 0x7c89f48L,
        0x7c8a084L, 0x7c8a348L, 0x7c8a4f4L, 0x7c8a840L, 0x7c8a988L,
        0x7c88e44L, 0x7c8aa58L, 0x7c8b64cL, 0x7c8907cL, 0x7c8b6d4L,
        0x7c8b720L, 0x25ffeccL, 0x25ffed4L, 0x25ffedcL, 0x25ffee8L,
        0x25ffef0L, 0x7f3a0dcL, 0x7c26078L, 0x7c260acL, 0x7c260b4L,
        0x7c260c0L, 0x7c260c8L, 0x78d6f0cL, 0x25ffef8L, 0x25fff00L,
        0x25fff08L, 0x25fff10L, 0x25fff18L, 0x25fff20L, 0x25fff28L,
        0x25fff30L, 0x25fff38L, 0x25fff40L, 0x25fff48L, 0x25fff50L,
        0x25fff58L, 0x25fff60L, 0x25fff68L, 0x25fff70L, 0x25fff78L,
        0x25fff80L, 0x25fff8cL, 0x25fffa4L, 0x7c8c184L, 0x7c8c430L
    };
    
    // Virtual Addresses (VA)
    public static final long[] VIRTUAL_ADDRESSES = {
        0x706d391840L, 0x706d398cb8L, 0x706d398cc4L, 0x706d398d30L, 0x706d398d34L,
        0x706d398d3cL, 0x706d398ca0L, 0x706d398d40L, 0x706d398d8cL, 0x706d398d38L,
        0x706d398d98L, 0x706d398d9cL, 0x706e04c04cL, 0x706e04c054L, 0x706e04c058L,
        0x706e04c184L, 0x706e04c188L, 0x706e04c18cL, 0x706e04c2a0L, 0x706d471b54L,
        0x706d471b5cL, 0x706d471ce0L, 0x706d471ce8L, 0x706d471d74L, 0x706d471d7cL,
        0x706d471e40L, 0x706d471e48L, 0x706d471d84L, 0x706d471fd4L, 0x7067e4be14L,
        0x7067e4be1cL, 0x7067e4be24L, 0x7067e4be2cL, 0x7067e4be34L, 0x7067e4be3cL,
        0x7067e4be44L, 0x7067e4be4cL, 0x7067e4be54L, 0x7067e4be5cL, 0x7067e4be64L,
        0x7067e4be6cL, 0x7067e4be74L, 0x7067e4be7cL, 0x7067e4be84L, 0x7067e4be8cL,
        0x7067e4be94L, 0x7067e4be9cL, 0x7067e4bea4L, 0x7067e4bebcL, 0x706d4d4eacL,
        0x706d4d5b98L, 0x706d4d5e58L, 0x706d4d5e68L, 0x706d4d5e70L, 0x706d4d5f48L,
        0x706d4d6084L, 0x706d4d6348L, 0x706d4d64f4L, 0x706d4d6840L, 0x706d4d6988L,
        0x706d4d4e44L, 0x706d4d6a58L, 0x706d4d764cL, 0x706d4d507cL, 0x706d4d76d4L,
        0x706d4d7720L, 0x7067e4beccL, 0x7067e4bed4L, 0x7067e4bedcL, 0x7067e4bee8L,
        0x7067e4bef0L, 0x706d7860dcL, 0x706d472078L, 0x706d4720acL, 0x706d4720b4L,
        0x706d4720c0L, 0x706d4720c8L, 0x706d122f0cL, 0x7067e4bef8L, 0x7067e4bf00L,
        0x7067e4bf08L, 0x7067e4bf10L, 0x7067e4bf18L, 0x7067e4bf20L, 0x7067e4bf28L,
        0x7067e4bf30L, 0x7067e4bf38L, 0x7067e4bf40L, 0x7067e4bf48L, 0x7067e4bf50L,
        0x7067e4bf58L, 0x7067e4bf60L, 0x7067e4bf68L, 0x7067e4bf70L, 0x7067e4bf78L,
        0x7067e4bf80L, 0x7067e4bf8cL, 0x7067e4bfa4L, 0x706d4d8184L, 0x706d4d8430L
    };
    
    // Free Fire Max Specific Offsets
    public static final long FFMAX_MESSAGE_BOX = 0x706d4d4eacL;
    public static final long FFMAX_INTRO_CONTROLLER = 0x706d4d5b98L;
    public static final long FREE_FIRE_LOGO_SPRITE_1 = 0x706d4d5e58L;
    public static final long FREE_FIRE_LOGO_SPRITE_2 = 0x706d4d5e68L;
    
    // Game Manager Offsets
    public static final long AMBIENCE_2D_AUDIO_MANAGER = 0x706d4d4e44L;
    public static final long GAME_VOICE_IMPL = 0x706d4d6a58L;
    
    // Veteran Buff Offsets
    public static final long VETERAN_BR_CALLBACK_BUFF_MAX_COUNT = 0x706d4d764cL;
    public static final long VETERAN_CS_CALLBACK_BUFF_MAX_COUNT = 0x706d4d76d4L;
    
    // Pin Source Type
    public static final int PIN_FFMAX = 3;
    
    // Game Features Flags
    public static final long ENABLE_FREE_FIRE_VOICE_MEMBER_CHANGED = 0xf85L;
    public static final long ENABLE_UGCOutline = 0x1115L;
    public static final long ENABLE_CDN_DOWNLOAD_OPTIMIZED = 0x1150L;
    public static final long ENABLE_CDN_LOCAL_LOAD_OPTIMIZED = 0x1151L;
    
    // Buff System
    public static final long BUFF_MAX_TIME = 0x3cL;
    
    // Event IDs
    public static final long FLASH_HIT_ENEMY = 115L;
    public static final long UI_SPECTATOR_PLAYER_IN_SHOP_BUY_SYNC = 1115L;
    public static final long UI_MATCH_RESULT_SCREENSHOT_RESPONSE = 1150L;
    public static final long UI_HIDE_ALL_FOR_MATCH_RESULT = 1151L;
    public static final long UI_SHOW_FIRE_BANNED = 1152L;
    public static final long UI_HUD_MATCH_RESULT_STATE_FINISH = 1153L;
    public static final long UI_SPECTATOR_AIRLINE_STATECHANGE = 1154L;
    public static final long UI_OPEN_LADDERMATCHENTRY = 1155L;
    public static final long UI_PLAYER_ONBOARD = 1156L;
    public static final long UI_LADDERMATCH_ON_SELECT_GAMEMODE = 1157L;
    public static final long UI_LADDERMATCH_SCREENSHOT_START = 1158L;
    public static final long UI_LADDERMATCH_SCREENSHOT_FINISH = 1159L;
    public static final long UI_HUD_SKILL_THIVA_RESCURERATE = 2115L;
    public static final long UI_OPEN_GIFT = 3115L;
    
    // Memory Management
    public static final long RELEASE_LIGHTMAP_MEMORY_FOR_64BIT_HIGH = 0x115aL;
    public static final long RELEASE_LIGHTMAP_MEMORY_FOR_64BIT_HIGH_IOS = 0x115bL;
    public static final long RELEASE_LIGHTMAP_MEMORY_ON_UNLOADING = 0x115cL;
    public static final long RELEASE_LIGHTMAP_MEMORY_ON_UNLOADING_IOS = 0x115dL;
    public static final long RELEASE_ASSETS_ON_UNLOAD = 0x115eL;
    
    /**
     * Get all available offsets for Free Fire Max 2.115
     */
    public static long[] getAllOffsets() {
        return MEMORY_OFFSETS;
    }
    
    /**
     * Get all virtual addresses for Free Fire Max 2.115
     */
    public static long[] getAllVirtualAddresses() {
        return VIRTUAL_ADDRESSES;
    }
    
    /**
     * Check if offset is valid for this game version
     */
    public static boolean isValidOffset(long offset) {
        for (long validOffset : MEMORY_OFFSETS) {
            if (validOffset == offset) {
                return true;
            }
        }
        return false;
    }
    
    /**
     * Get game version string
     */
    public static String getGameVersion() {
        return GAME_VERSION;
    }
    
    /**
     * Get target package name
     */
    public static String getTargetPackage() {
        return TARGET_PACKAGE;
    }
}