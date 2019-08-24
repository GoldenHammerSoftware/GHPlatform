// Copyright 2019 Golden Hammer Software
#include "GHPlatformServices.h"
#include "GHDebugMessage.h"

#define ENUMHEADER "GHPlatformIdentifiers.h"
#include "GHString/GHEnumInclude.h"

GHPlatformServices::GHPlatformServices(void)
	: mEnumStore(mIdFactory)
{
	GHPlatformIdentifiers::generateIdentifiers(mIdFactory);

	// We can't instantiate GHProfiler here because it would need access to virtual functions.
	// Add this line to the constructor of each subclass.
	// GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}

GHPlatformServices::~GHPlatformServices(void)
{
	GHDebugMessage::shutdown();
}
