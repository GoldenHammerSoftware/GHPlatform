// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHPlatform/GHFileOpener.h"
#include <jni.h>
#include "GHString/GHString.h"

class GHJNIMgr;

// TODO: remove the jni from this and use ndk asset mgr.
class GHAndroidFileOpener : public GHFileOpener
{
public:
    GHAndroidFileOpener(GHJNIMgr& jniMgr, jobject jobj, const char* sdCardPrefix);

protected:
	virtual GHFile* openPlatformFile(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const;

    
    GHFile* openFileFromSDCard(const char* filename, const char* flags, GHFile::FileType fileType, GHFile::FileMode fileMode) const;
	GHFile* openFileFromAPK(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const;

    
private:
	GHJNIMgr& mJNIMgr;
	jobject mJObject;
	jmethodID mMethodID;
	GHString mSDCardPrefix;

};
