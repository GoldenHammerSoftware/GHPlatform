// Copyright 2019 Golden Hammer Software
#include "GHAndroidPlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"
#include "GHPlatform/GHProfiler.h"
#include "GHPlatform/GHThreadFactory.h"

GHAndroidPlatformServices::GHAndroidPlatformServices(GHJNIMgr& jniMgr, jobject engineInterface, std::vector<GHString>&& saveFileDirectories, jobject jAssetMgr)
	: GHPlatformServices()
	, mTimeCalculator(jniMgr, engineInterface)
	, mFileOpener(jniMgr, engineInterface, std::move(saveFileDirectories), jAssetMgr)
	, mThreadFactory(jniMgr)
{
	GHDebugMessage::init(mOutputPipe);
	GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}
