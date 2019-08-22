// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHTimeCalculator.h"

class GHiOSTimeCalculator : public GHTimeCalculator
{
public:
    GHiOSTimeCalculator(void);
    virtual float calcTime(void) const;
    
private:
    double mStartupTime;
};
