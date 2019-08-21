// Copyright 2010 Golden Hammer Software
#pragma once

#include <vector>
#include "GHFile.h"
// TODO: remove ghstring
#include "GHString/GHString.h"

// interface for opening a file.
class GHFileOpener
{
public:
    virtual ~GHFileOpener(void) {}
    
    GHFile* openFile(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const;
    void addResourcePath(const char* path);
    const std::vector<GHString>& getResourcePaths(void) const { return mResourcePaths; }
    
protected:
    virtual GHFile* openPlatformFile(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const = 0;
    
private:
    // ordered list of directories to look in.
	// most recently added is the first path examined.
	std::vector<GHString> mResourcePaths;
};
