// Copyright 2019 Golden Hammer Software
#pragma once

class GHFileOpener;
class GHFilePicker;
class GHThreadFactory;
class GHTimeCalculator;
class GHSocketMgr;

// The interface for creating platform-specific factories.
class GHPlatformServices
{
public:
	virtual ~GHPlatformServices(void);

	virtual GHFileOpener& getFileOpener(void) = 0;
	virtual GHFilePicker& getFilePicker(void) = 0;
	virtual GHThreadFactory& getThreadFactory(void) = 0;
	virtual GHTimeCalculator& getTimeCalculator(void) = 0;
	virtual GHSocketMgr& getSocketMgr(void) = 0;
};

