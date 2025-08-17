LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libdobby
LOCAL_SRC_FILES := libraries/arm64-v8a/libdobby.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libAegisGL
LOCAL_SRC_FILES := GL/libAegisGL.a
LOCAL_EXPORT_C_INCLUDES := GL/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libEsp
LOCAL_SRC_FILES := GL/libEsp.a
LOCAL_EXPORT_C_INCLUDES := GL/include
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := ItsRohitOp

LOCAL_CFLAGS := -w -s -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions
LOCAL_CPPFLAGS := -w -s -Wno-error=format-security -fvisibility=hidden -Werror -std=c++17
LOCAL_CPPFLAGS += -Wno-error=c++11-narrowing -fpermissive -Wall -fexceptions
LOCAL_LDFLAGS += -Wl,--gc-sections,--strip-all,-llog
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv2
LOCAL_ARM_MODE := arm

LOCAL_STATIC_LIBRARIES := libdobby libAegisGL libEsp

LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ImGui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ImGui/backends

LOCAL_SRC_FILES := native-lib.cpp \
ImGui/imgui.cpp \
ImGui/imgui_draw.cpp \
ImGui/imgui_demo.cpp \
ImGui/imgui_widgets.cpp \
ImGui/imgui_tables.cpp \
ImGui/backends/imgui_impl_opengl3.cpp \
KittyMemory/KittyUtils.cpp \
KittyMemory/KittyMemory.cpp \
KittyMemory/MemoryPatch.cpp \
KittyMemory/MemoryBackup.cpp \

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := inject
LOCAL_SRC_FILES := libinject.so
include $(PREBUILT_SHARED_LIBRARY)
