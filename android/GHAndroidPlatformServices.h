// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHAndroidFileOpener.h"
#include "GHPlatform/null/GHNullFilePicker.h"
#include "GHAndroidThreadFactory.h"
#include "GHAndroidTimeCalculator.h"
#include "GHAndroidSocketMgr.h"
#include "GHAndroidOutputPipe.h"
#include <vector>
#include "GHString/GHString.h"

#include <jni.h>

class GHAndroidPlatformServices : public GHPlatformServices
{
public:
	GHAndroidPlatformServices(GHJNIMgr& jniMgr, jobject engineInterface, std::vector<GHString>&& saveFileDirectories, jobject jAssetMgr);

	virtual GHFileOpener& getFileOpener(void) { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) { return mFilePicker; }
	virtual const GHThreadFactory& getThreadFactory(void) { return mThreadFactory; }
	virtual const GHTimeCalculator& getTimeCalculator(void) { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) { return mSocketMgr; }

private:
	GHAndroidFileOpener mFileOpener;
	GHNullFilePicker mFilePicker;
	GHAndroidThreadFactory mThreadFactory;
	GHAndroidTimeCalculator mTimeCalculator;
	GHAndroidSocketMgr mSocketMgr;
	GHAndroidOutputPipe mOutputPipe;
};
