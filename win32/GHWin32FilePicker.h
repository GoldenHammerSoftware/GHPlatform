// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHPlatform/GHFilePicker.h"
#include <atlbase.h>
#include <Shobjidl.h>

class GHWin32Window;

class GHWin32FilePicker : public GHFilePicker
{
public:
	GHWin32FilePicker(GHWin32Window& window);

	virtual void pickFile(PickedCallback& callback, const std::vector<const char*> exts);
	virtual void pickMultipleFiles(PickedCallback& callback, const std::vector<const char*> exts);

private:
	bool createWin32Picker(const std::vector<const char*>& exts, CComPtr<IFileOpenDialog>& pDlg,
		wchar_t*& wExts);
	void sendPickResults(PickedCallback& callback, IShellItem* item);

private:
	GHWin32Window& mWindow;
};
