#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHPlatform/GHFOpenFileOpener.h"
#include "GHWin32TimeCalculator.h"
#include "GHWin32ThreadFactory.h"
#include "GHWin32FilePicker.h"
#include "GHWinSockSocketMgr.h"
#include "GHWin32OutputPipe.h"

class GHWin32PlatformServices : public GHPlatformServices
{
public:
	GHWin32PlatformServices(HWND hwnd);
	~GHWin32PlatformServices(void);

	virtual GHFileOpener& getFileOpener(void) override { return mFileOpener; }
	virtual GHFilePicker& getFilePicker(void) override { return mFilePicker; }
	virtual GHThreadFactory& getThreadFactory(void) override { return mThreadFactory; }
	virtual GHTimeCalculator& getTimeCalculator(void) override { return mTimeCalculator; }
	virtual GHSocketMgr& getSocketMgr(void) override { return mSocketMgr; }

private:
	GHFOpenFileOpener mFileOpener;
	GHWin32FilePicker mFilePicker;
	GHWin32ThreadFactory mThreadFactory;
	GHWin32TimeCalculator mTimeCalculator;
	GHWinSockSocketMgr mSocketMgr;
	GHWin32OutputPipe mOutputPipe;
};

