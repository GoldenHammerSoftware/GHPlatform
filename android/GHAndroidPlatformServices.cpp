// Copyright 2019 Golden Hammer Software
#include "GHAndroidPlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"
#include "GHPlatform/GHProfiler.h"
#include "GHPlatform/GHThreadFactory.h"

GHAndroidPlatformServices::GHAndroidPlatformServices(GHJNIMgr& jniMgr, jobject engineInterface, const char* sdCardPrefix, jobject jAssetMgr)
	: GHPlatformServices()
	, mTimeCalculator(jniMgr, engineInterface)
	, mFileOpener(jniMgr, engineInterface, sdCardPrefix, jAssetMgr)
	, mThreadFactory(jniMgr)
{
	GHDebugMessage::init(mOutputPipe);
	GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}
