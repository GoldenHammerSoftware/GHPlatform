// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHPlatform/GHFilePicker.h"
#include <vector>
#include "GHString/GHString.h"

class GHMetroFilePicker : public GHFilePicker
{
public:
	virtual void pickFile(PickedCallback& callback, const std::vector<const char*> exts);
	virtual void pickMultipleFiles(PickedCallback& callback, const std::vector<const char*> exts);

private:
	// initialize a windows file picker.
	Windows::Storage::Pickers::FileOpenPicker^ createWindowsPicker(const std::vector<const char*> exts);
	// let the game know about a file pick result.
	void triggerCallback(PickedCallback& callback, Windows::Storage::StorageFile^ file,
		Windows::Storage::Streams::IRandomAccessStream^ stream);
};
