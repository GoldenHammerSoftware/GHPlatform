// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHNullFileOpener.h"
#include "GHNullFilePicker.h"
#include "GHNullThreadFactory.h"
#include "GHNullTimeCalculator.h"
#include "GHNullSocketMgr.h"

class GHNullPlatformServices : public GHPlatformServices
{
public:
	virtual GHFileOpener& getFileOpener(void) override { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) override { return mFilePicker; }
	virtual GHThreadFactory& getThreadFactory(void) override { return mThreadFactory; }
	virtual GHTimeCalculator& getTimeCalculator(void) override { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) override { return mSocketMgr; }

private:
	GHNullFileOpener mFileOpener;
	GHNullFilePicker mFilePicker;
	GHNullThreadFactory mThreadFactory;
	GHNullTimeCalculator mTimeCalculator;
	GHNullSocketMgr mSocketMgr;
};

