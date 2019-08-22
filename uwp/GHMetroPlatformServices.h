// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"

#include "GHMetroFileOpener.h"
#include "GHMetroFilePicker.h"
#include "GHMetroThreadFactory.h"
#include "GHMetroTimeCalculator.h"
#include "GHMetroSocketMgr.h"

class GHMetroPlatformServices : public GHPlatformServices
{
public:
	GHMetroPlatformServices(void);

	virtual GHFileOpener& getFileOpener(void) override { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) override { return mFilePicker; }
	virtual GHThreadFactory& getThreadFactory(void) override { return mThreadFactory; }
	virtual GHTimeCalculator& getTimeCalculator(void) override { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) override { return mSocketMgr; }

private:
	GHMetroFileOpener mFileOpener;
	GHMetroFilePicker mFilePicker;
	GHMetroThreadFactory mThreadFactory;
	GHMetroTimeCalculator mTimeCalculator;
	GHMetroSocketMgr mSocketMgr;
};
