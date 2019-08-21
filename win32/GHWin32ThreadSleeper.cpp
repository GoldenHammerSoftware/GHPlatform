// Copyright 2010 Golden Hammer Software
#include "GHWin32ThreadSleeper.h"
#include <windows.h>

void GHWin32ThreadSleeper::sleep(int ms)
{
	::Sleep(ms);
}
