// Copyright 2010 Golden Hammer Software
#if defined(GHPUTSTRINGSINTABLES) || defined(GHPUTDECLARATIONS) || !defined(_GHPLATFORMIDENTIFIERS_H_)
#ifndef _GHPLATFORMIDENTIFIERS_H_
#define _GHPLATFORMIDENTIFIERS_H_
#endif

#include "GHString/GHEnum.h"

GHIDENTIFIERBEGIN(GHPlatformIdentifiers)
GHIDENTIFIER(PROPS)
GHIDENTIFIER(PROPID)
GHIDENTIFIER(PROPVAL)

GHIDENTIFIER(INTVAL) // an int prop val
GHIDENTIFIER(VAL) // arbitrary val

GHIDENTIFIER(FILENAME) // name of a file with no path
GHIDENTIFIER(FILEPATH) // name and path of a file
GHIDENTIFIER(FILETOKEN) // token used by some os's for accessing a file.

GHIDENTIFIEREND

#include "GHString/GHEnumEnd.h"

#endif
