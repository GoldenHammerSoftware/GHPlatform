// Copyright 2019 Golden Hammer Software
#include "GHCocoaPlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"

GHCocoaPlatformServices::GHCocoaPlatformServices(void)
{
    GHDebugMessage::init(mOutputPipe);
}

