#include "GHWin32PlatformServices.h"
#include "GHPlatform/GHDebugMessage.h"
#include "GHPlatform/GHProfiler.h"
#include "GHPlatform/GHThreadFactory.h"

GHWin32PlatformServices::GHWin32PlatformServices(HWND hwnd)
	: mFilePicker(hwnd)
{
	GHDebugMessage::init(mOutputPipe);
	GHProfiler::initProfiler(getTimeCalculator(), getThreadFactory().createMutex());
}

GHWin32PlatformServices::~GHWin32PlatformServices(void)
{

}
