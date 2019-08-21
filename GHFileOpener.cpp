// Copyright 2010 Golden Hammer Software
#include "GHFileOpener.h"
#include "GHProfiler.h"

//#define GENERATE_DATA_COPY
#ifdef GENERATE_DATA_COPY
#include "GHDebugMessage.h"
static void outputDataCopy(const char* filename, const char* filepath)
{
	const char* fileAppend = "";
	if (strstr(filename, ".xml") ||
		strstr(filename, ".gham"))
	{
		fileAppend = ".mp3";
	}
	GHDebugMessage::outputString("copy ..\\%s\\%s ..\\..\\..\\AndroidStudio\\GHBowling\\GHBowlingVR\\src\\main\\assets\\%s%s", filepath, filename, filename, fileAppend);
}
#endif

GHFile* GHFileOpener::openFile(const char* filename, GHFile::FileType fileType, 
                               GHFile::FileMode fileMode) const
{
    GHPROFILESCOPE("openFile", GHString::CHT_REFERENCE)

    GHFile* ret = 0;
	const int BUF_SZ = 512;
    char nameBuff[BUF_SZ];

	// look in ./ first before looking at resource paths.
	// we were having an issue of our config files being saved in random read-only directories.
	ret = openPlatformFile(filename, fileType, fileMode);
	if (ret) {
#ifdef GENERATE_DATA_COPY
		outputDataCopy(filename, "");
#endif
		return ret;
	}

    std::vector<GHString>::const_reverse_iterator pathIter;
    for (pathIter = mResourcePaths.rbegin(); pathIter != mResourcePaths.rend(); ++pathIter)
    {
		::snprintf(nameBuff, BUF_SZ, "%s%s", pathIter->getChars(), filename);
        ret = openPlatformFile(nameBuff, fileType, fileMode);
        if (ret) {
#ifdef GENERATE_DATA_COPY
			outputDataCopy(filename, pathIter->getChars());
#endif
            return ret;   
        }
    }
    
    return ret;
}

void GHFileOpener::addResourcePath(const char* path)
{
    mResourcePaths.push_back(path);
}
