// Copyright Golden Hammer Software
#pragma once

#include <vector>

class GHPropertyContainer;

// interface for allowing the user to select a file.
class GHFilePicker 
{
public:
	// interface for getting notifications that a file was picked
	class PickedCallback
	{
	public:
		virtual ~PickedCallback(void) {}
		virtual void handleFilePicked(GHPropertyContainer& result) = 0;
	};

public:
	virtual ~GHFilePicker(void) {}

	// present the user with a file picker dialog and return the selected file name.
	virtual void pickFile(PickedCallback& callback, const std::vector<const char*> exts) = 0;
	// present a file picker that can handle multi select.  repeatedly call the callback for each file.
	virtual void pickMultipleFiles(PickedCallback& callback, const std::vector<const char*> exts) = 0;
};
