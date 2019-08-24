#include "GHMetroPlatformServices.h"

#define ENUMHEADER "GHMetroIdentifiers.h" 
#include "GHString/GHEnumInclude.h"

#include "GHPlatform/GHProfiler.h"
#include "GHPlatform/GHDebugMessage.h"

GHMetroPlatformServices::GHMetroPlatformServices(void)
	: mFileOpener(L"\\", L"\\")
{
	GHMetroIdentifiers::generateIdentifiers(getIdFactory());

	GHDebugMessage::init(mOutputPipe);
	GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}

GHMetroPlatformServices::~GHMetroPlatformServices(void)
{
}
