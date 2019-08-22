// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHAndroidFileOpener.h"
#include "GHPlatform/null/GHNullFilePicker.h"
#include "GHAndroidThreadFactory.h"
#include "GHAndroidTimeCalculator.h"
#include "GHAndroidSocketMgr.h"

#include <jni.h>

class GHAndroidPlatformServices : public GHPlatformServices
{
public:
	GHAndroidPlatformServices(GHJNIMgr& jniMgr, jobject engineInterface, const char* sdCardPrefix);

	virtual GHFileOpener& getFileOpener(void) { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) { return mFilePicker; }
	virtual GHThreadFactory& getThreadFactory(void) { return mThreadFactory; }
	virtual GHTimeCalculator& getTimeCalculator(void) { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) { return mSocketMgr; }

private:
	GHAndroidFileOpener mFileOpener;
	GHNullFilePicker mFilePicker;
	GHAndroidThreadFactory mThreadFactory;
	GHAndroidTimeCalculator mTimeCalculator;
	GHAndroidSocketMgr mSocketMgr;
};
