// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHPlatform/GHPlatformServices.h"
#include "GHiOSFileOpener.h"
#include "GHPlatform/null/GHNullFilePicker.h"
#include "GHCFSocketMgr.h"
#include "GHiOSThreadFactory.h"
#include "GHiOSTimeCalculator.h"
#include "GHiOSOutputPipe.h"

class GHiOSPlatformServices : public GHPlatformServices
{
public:
    GHiOSPlatformServices(void);
    
    virtual GHFileOpener& getFileOpener(void) { return mFileOpener; }
    virtual GHFilePicker& getFilePicker(void) { return mFilePicker; }
    virtual const GHThreadFactory& getThreadFactory(void) { return mThreadFactory; }
    virtual const GHTimeCalculator& getTimeCalculator(void) { return mTimeCalculator; }
    virtual GHSocketMgr& getSocketMgr(void) { return mSocketMgr; }
    
private:
    GHiOSFileOpener mFileOpener;
    GHNullFilePicker mFilePicker;
    GHiOSThreadFactory mThreadFactory;
    GHiOSTimeCalculator mTimeCalculator;
    GHCFSocketMgr mSocketMgr;
    GHiOSOutputPipe mOutputPipe;
};
