// Copyright Golden Hammer Software
#pragma once

#include "GHPlatform/GHFilePicker.h"
#include "GHPlatform/GHPropertyContainer.h"

class GHNullFilePicker : public GHFilePicker
{
private:
	virtual void pickFile(PickedCallback& callback, const std::vector<const char*> exts)
	{
		GHPropertyContainer result;
		callback.handleFilePicked(result);
	}
	virtual void pickMultipleFiles(PickedCallback& callback, const std::vector<const char*> exts)
	{
		GHPropertyContainer result;
		callback.handleFilePicked(result);
	}
};
