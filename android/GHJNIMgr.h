// Copyright 2010 Golden Hammer Software
#pragma once

#include <jni.h>

// keeps track of JNI stuff to avoid threading issues
class GHJNIMgr
{
public:
	GHJNIMgr(JNIEnv& mainThreadEnv, JavaVM* jvm);

	JNIEnv& getJNIEnv(void);
	JavaVM* getJVM(void);

private:
	JNIEnv& mMainThreadEnv;
	JavaVM* mJVM;
};
