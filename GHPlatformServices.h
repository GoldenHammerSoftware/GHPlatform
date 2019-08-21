// Copyright 2019 Golden Hammer Software
#pragma once

#include "GHString/GHStringIdFactoryDJB2.h"
#include "GHString/GHIdentifierMap.h"

class GHFileOpener;
class GHFilePicker;
class GHThreadFactory;
class GHTimeCalculator;
class GHSocketMgr;
class GHWindow;

// The interface for creating platform-specific factories.
// Todo: a lot of this can probably be const.
class GHPlatformServices
{
public:
	GHPlatformServices(void);
	virtual ~GHPlatformServices(void);

	virtual GHFileOpener& getFileOpener(void) = 0;
	virtual GHFilePicker& getFilePicker(void) = 0;
	virtual GHThreadFactory& getThreadFactory(void) = 0;
	virtual GHTimeCalculator& getTimeCalculator(void) = 0;
	virtual GHSocketMgr& getSocketMgr(void) = 0;
	virtual GHWindow& getWindow(void) = 0;

	GHStringIdFactory& getIdFactory(void) { return mIdFactory; }
	GHIdentifierMap<int>& getEnumStore(void) { return mEnumStore; }

private:
	GHStringIdFactoryDJB2 mIdFactory;
	GHIdentifierMap<int> mEnumStore;
};

