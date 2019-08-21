#include "GHWin32PlatformServices.h"
#include "GHWin32Window.h"
#include "GHPlatform/GHDebugMessage.h"

GHWin32PlatformServices::GHWin32PlatformServices(GHWin32Window& window)
	: mWindow(window)
	, mFilePicker(window)
{
	GHDebugMessage::init(mOutputPipe);
}

GHWin32PlatformServices::~GHWin32PlatformServices(void)
{

}

GHWindow& GHWin32PlatformServices::getWindow(void) 
{ 
	return mWindow; 
}
