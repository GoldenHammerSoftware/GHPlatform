#include "GHMetroPlatformServices.h"

#define ENUMHEADER "GHMetroIdentifiers.h" 
#include "GHString/GHEnumInclude.h"

GHMetroPlatformServices::GHMetroPlatformServices(void)
	: mFileOpener(L"\\", L"\\")
{
	GHMetroIdentifiers::generateIdentifiers(getIdFactory());
}
