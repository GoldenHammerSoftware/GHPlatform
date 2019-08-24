// Copyright 2010 Golden Hammer Software
#include "GHAndroidFileOpener.h"
#include "GHPlatform/GHDebugMessage.h"
#include "GHPlatform/GHFileC.h"
#include <unistd.h>
#include <cassert>
#include "GHPlatform/android/GHJNIMgr.h"

namespace {
	struct GHAndroidLoadedFileInfo
	{
		FILE* mFilePtr;
		long mLength;
		GHAndroidLoadedFileInfo(void)
        : mFilePtr(0), mLength(0) { }
	};
}

jfieldID getFileDescriptorID(JNIEnv& jniEnv)
{
	jclass fileDescriptorClass = jniEnv.FindClass("java/io/FileDescriptor");
	if(fileDescriptorClass == 0) {
		GHDebugMessage::outputString("Cannot find FileDescriptor class.");
	}
    
	jfieldID fieldID = jniEnv.GetFieldID(fileDescriptorClass, "descriptor", "I");
	if(fieldID == 0) {
		GHDebugMessage::outputString("Cannot find file descriptor field id.");
	}
    
	return fieldID;
}

extern "C"
__attribute__((visibility("default")))
void
Java_goldenhammer_ghbase_GHEngineInterface_loadFile(JNIEnv* env, jobject thiz, jobject fileDescriptorObj, jlong startOffset, jlong length, jlong fileDataPtr)
{
	jfieldID fileDescriptorFieldID = getFileDescriptorID(*env);
	jint fd = env->GetIntField(fileDescriptorObj, fileDescriptorFieldID);
    
	// leaking newfd?
	int newfd = dup(fd);
	FILE* file = fdopen(newfd, "rb");
	if(!file) {
		GHDebugMessage::outputString("Unable to open file!");
	}
    
	fseek(file, startOffset, SEEK_SET);
    
	GHAndroidLoadedFileInfo* fileInfo = reinterpret_cast<GHAndroidLoadedFileInfo*>(fileDataPtr);
	fileInfo->mFilePtr = file;
	fileInfo->mLength = length;
}

GHAndroidFileOpener::GHAndroidFileOpener(GHJNIMgr& jniMgr, jobject jobj, const char* sdCardPrefix)
: mJNIMgr(jniMgr)
, mJObject(jobj)
, mMethodID(0)
{
    mSDCardPrefix.setConstChars(sdCardPrefix, GHString::CHT_COPY);
    
	jclass cls = mJNIMgr.getJNIEnv().GetObjectClass(mJObject);
	if(cls == 0) {
		GHDebugMessage::outputString("GHAndroidFileOpener can't find class where loadRawFile method should exist\n.");
	}
	mMethodID = mJNIMgr.getJNIEnv().GetMethodID(cls, "getFileDescription", "(Ljava/lang/String;J)V");
	if(mMethodID == 0) {
		GHDebugMessage::outputString("GHAndroidFileOpener can't find getFileDescription method in Java.\n");
	}
}

GHFile* GHAndroidFileOpener::openPlatformFile(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const
{
    const char* flags;
    if (fileMode == GHFile::FM_READONLY)
    {
        if (fileType == GHFile::FT_BINARY)
        {
            flags = "rb";
        }
        else
        {
            flags = "rt";
        }
    }
    else
    {
        if (fileType == GHFile::FT_BINARY)
        {
            flags = "wb";
        }
        else
        {
            flags = "wt";
        }
    }
    
    GHFile* ret = openFileFromSDCard(filename, flags, fileType, fileMode);
    if (!ret && fileMode == GHFile::FM_READONLY)
    {
        ret = openFileFromAPK(filename, fileType, fileMode);
    }
    
    if (!ret)
    {
        GHDebugMessage::outputString("Failed to open file %s for %s", filename, fileMode == GHFile::FM_READONLY ? "read" : "write");
    }
    
    return ret;
}

GHFile* GHAndroidFileOpener::openFileFromSDCard(const char* filename, const char* flags, GHFile::FileType fileType, GHFile::FileMode fileMode) const
{
    const size_t BUF_LEN = 512;
	char buf[BUF_LEN];
	assert(mSDCardPrefix.getCharLen() + strlen(filename) < BUF_LEN);
	sprintf(buf, "%s%s", mSDCardPrefix.getChars(), filename);
	FILE* file = fopen(buf, flags);
	if(!file) {
		return 0;
	}
    
	return new GHFileC(file, fileType, fileMode);
}

GHFile* GHAndroidFileOpener::openFileFromAPK(const char* filename, GHFile::FileType fileType, GHFile::FileMode fileMode) const
{
	// This is calling through to custom GH java code.
	// todo: replace with ndk calls.
	
	jstring javaFilename = mJNIMgr.getJNIEnv().NewStringUTF(filename);
	if(javaFilename == 0) {
		GHDebugMessage::outputString("GHAndroidFileOpener::openFileFromAPK: Java won't give us a string. OOM?");
		return 0;
	}
    
	GHAndroidLoadedFileInfo loadedFileInfo;
	mJNIMgr.getJNIEnv().CallVoidMethod(mJObject, mMethodID, javaFilename, reinterpret_cast<long>(&loadedFileInfo));
	FILE* retFILE = loadedFileInfo.mFilePtr;
    
	mJNIMgr.getJNIEnv().DeleteLocalRef(javaFilename);
    
	if(!retFILE) {
		return 0;
	}
    
	return new GHFileC(retFILE, fileType, fileMode, loadedFileInfo.mLength);
}
