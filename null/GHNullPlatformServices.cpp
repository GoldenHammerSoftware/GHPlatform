#include "GHNullPlatformServices.h"
#include "GHPlatform/GHProfiler.h"
#include "GHPlatform/GHDebugMessage.h"

GHNullPlatformServices::GHNullPlatformServices(void)
{
	GHDebugMessage::init(mOutputPipe);
	GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}