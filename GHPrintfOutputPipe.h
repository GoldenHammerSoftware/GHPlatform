// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHOutputPipe.h"

class GHPrintfOutputPipe : public GHOutputPipe
{
public:
	virtual void outputString(const char* str);
};
