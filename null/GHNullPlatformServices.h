// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHNullFileOpener.h"
#include "GHNullFilePicker.h"
#include "GHNullThreadFactory.h"
#include "GHNullTimeCalculator.h"
#include "GHNullSocketMgr.h"
#include "GHNullWindow.h"

class GHNullPlatformServices : public GHPlatformServices
{
public:
	virtual GHFileOpener& getFileOpener(void) override { mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) override { return mFilePicker; }
	virtual GHThreadFactory& getThreadFactory(void) override { return mThreadFactory; }
	virtual GHTimeCalculator& getTimeCalculator(void) override { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) override { return mSocketMgr; }
	virtual GHWindow& getWindow(void) override { return mWindow; }

private:
	GHNullFileOpener mFileOpener;
	GHNullFilePicker mFilePicker;
	GHNullThreadFactory mThreadFactory;
	GHNullTimeCalculator mTimeCalculator;
	GHNullSocketMgr mSocketMgr;
	GHNullWindow mWindow;
};

