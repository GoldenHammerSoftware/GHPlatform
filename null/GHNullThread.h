// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHPlatform/GHThread.h"
#include "GHPlatform/GHRunnable.h"

class GHNullThread : public GHThread
{
public:
	void runThread(GHRunnable& runnable) { runnable.run(); }
};
