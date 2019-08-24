// Copyright 2019 Golden Hammer Software
#include "GHAndroidPlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"

GHAndroidPlatformServices::GHAndroidPlatformServices(GHJNIMgr& jniMgr, jobject engineInterface, const char* sdCardPrefix)
	: GHPlatformServices()
	, mTimeCalculator(jniMgr, engineInterface)
	, mFileOpener(jniMgr, engineInterface, sdCardPrefix)
	, mThreadFactory(jniMgr)
{
	GHDebugMessage::init(mOutputPipe);
}
