LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_opersysnativeservice.cpp 

LOCAL_SHARED_LIBRARIES := \
	libopersysnativeservice \
	libbinder \
	libutils

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../services/opersysnativeservice

LOCAL_MODULE:= opersysnativeservice

include $(BUILD_EXECUTABLE)
