# This is only the files part of GHPlatform Android.mk.
# It also includes GHString for convenience since otherwise we'd have to manage an extra GHString.lib
# It would probably be better to make a separate libGHString.so instead but this is easier for us.

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../

LOCAL_SRC_FILES += ../../../GHString/GHFilenameUtil.cpp
LOCAL_SRC_FILES += ../../../GHString/GHHashListParser.cpp
LOCAL_SRC_FILES += ../../../GHString/GHNumberListParser.cpp
LOCAL_SRC_FILES += ../../../GHString/GHString.cpp
LOCAL_SRC_FILES += ../../../GHString/GHStringIdFactoryDJB2.cpp
LOCAL_SRC_FILES += ../../../GHString/GHStringTokenizer.cpp
LOCAL_SRC_FILES += ../../../GHString/GHWhitespaceUtil.cpp

LOCAL_SRC_FILES += ../../GHByteStreamPreallocated.cpp
LOCAL_SRC_FILES += ../../GHByteStreamReader.cpp
LOCAL_SRC_FILES += ../../GHControllerMgr.cpp
LOCAL_SRC_FILES += ../../GHControllerTransition.cpp
LOCAL_SRC_FILES += ../../GHDebugMessage.cpp
LOCAL_SRC_FILES += ../../GHEventMgr.cpp
LOCAL_SRC_FILES += ../../GHFileC.cpp
LOCAL_SRC_FILES += ../../GHFileOpener.cpp
LOCAL_SRC_FILES += ../../GHPlatformServices.cpp
LOCAL_SRC_FILES += ../../GHPrintfOutputPipe.cpp
LOCAL_SRC_FILES += ../../GHProperty.cpp
LOCAL_SRC_FILES += ../../GHPropertyContainer.cpp
LOCAL_SRC_FILES += ../../GHProfiler.cpp
LOCAL_SRC_FILES += ../../GHProfileRecord.cpp
LOCAL_SRC_FILES += ../../GHMessage.cpp
LOCAL_SRC_FILES += ../../GHMessageQueue.cpp
LOCAL_SRC_FILES += ../../GHRedirectResourceLoader.cpp
LOCAL_SRC_FILES += ../../GHRefCounted.cpp
LOCAL_SRC_FILES += ../../GHResource.cpp
LOCAL_SRC_FILES += ../../GHResourceCache.cpp
LOCAL_SRC_FILES += ../../GHResourceFactory.cpp
LOCAL_SRC_FILES += ../../GHStateMachine.cpp
LOCAL_SRC_FILES += ../../GHTimeVal.cpp
LOCAL_SRC_FILES += ../../GHTimeUpdater.cpp
LOCAL_SRC_FILES += ../../GHXorFile.cpp

LOCAL_SRC_FILES += ../../null/GHNullThreadFactory.cpp

LOCAL_SRC_FILES += ../../android/GHAndroidFileOpener.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidMutex.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidOutputPipe.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidPlatformServices.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidSocket.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidSocketMgr.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidThread.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidThreadFactory.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidThreadSignal.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidThreadSleeper.cpp
LOCAL_SRC_FILES += ../../android/GHAndroidTimeCalculator.cpp
LOCAL_SRC_FILES += ../../android/GHJNIMgr.cpp
