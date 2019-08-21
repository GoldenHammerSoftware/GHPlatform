// Copyright 2010 Golden Hammer Software
#include "GHPrintfOutputPipe.h"
#include "stdio.h"

void GHPrintfOutputPipe::outputString(const char* str)
{
	::printf("%s\n", str);
}

