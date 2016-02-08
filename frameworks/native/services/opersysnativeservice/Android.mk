LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    OpersysNativeService.cpp \

LOCAL_CFLAGS:= -DLOG_TAG=\"OpersysNativeService\"

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
	libbinder \
	libopersysnativemgriface

LOCAL_MODULE:= libopersysnativeservice

include $(BUILD_SHARED_LIBRARY)
