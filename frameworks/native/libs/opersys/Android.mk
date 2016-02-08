LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	IOpersysNativeService.cpp \
	OpersysNativeManager.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libcutils \
	libutils 

LOCAL_MODULE:= libopersysnativemgriface

ifneq ($(filter generic%,$(TARGET_DEVICE)),)
    # Emulator build
    LOCAL_CFLAGS += -DUSE_FENCE_SYNC
endif

include $(BUILD_SHARED_LIBRARY)

ifeq (,$(ONE_SHOT_MAKEFILE))
include $(call first-makefiles-under,$(LOCAL_PATH))
endif
