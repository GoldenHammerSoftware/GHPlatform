// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHNullFileOpener.h"
#include "GHNullFilePicker.h"
#include "GHNullThreadFactory.h"
#include "GHNullTimeCalculator.h"
#include "GHNullSocketMgr.h"
#include "GHPlatform/GHPrintfOutputPipe.h"

// A platform services for an unsupported platform.
// Everything in here is a simple mock object as a placeholder.
class GHNullPlatformServices : public GHPlatformServices
{
public:
	GHNullPlatformServices(void);

	virtual GHFileOpener& getFileOpener(void) override { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) override { return mFilePicker; }
	virtual const GHThreadFactory& getThreadFactory(void) override { return mThreadFactory; }
	virtual const GHTimeCalculator& getTimeCalculator(void) override { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) override { return mSocketMgr; }

private:
	GHNullFileOpener mFileOpener;
	GHNullFilePicker mFilePicker;
	GHNullThreadFactory mThreadFactory;
	GHNullTimeCalculator mTimeCalculator;
	GHNullSocketMgr mSocketMgr;
	GHPrintfOutputPipe mOutputPipe;
};

