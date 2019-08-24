// Copyright 2019 Golden Hammer Software
#include "GHiOSPlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"
#include "GHPlatform/GHProfiler.h"

GHiOSPlatformServices::GHiOSPlatformServices(void)
{
    GHDebugMessage::init(mOutputPipe);
    GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}

