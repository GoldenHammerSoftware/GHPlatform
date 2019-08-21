// Copyright 2010 Golden Hammer Software
#include "GHPlatform/GHTimeCalculator.h"

class GHNullTimeCalculator : public GHTimeCalculator
{
public:
    virtual float calcTime(void) const { return 0; }
};
