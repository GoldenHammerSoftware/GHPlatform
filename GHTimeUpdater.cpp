// Copyright 2010 Golden Hammer Software
#include "GHTimeUpdater.h"
#include "GHTimeCalculator.h"
#include "GHTimeVal.h"

GHTimeUpdater::GHTimeUpdater(const GHTimeCalculator& timeCalc, GHTimeVal& timeVal)
: mTimeCalc(timeCalc)
, mTimeVal(timeVal)
, mStartTime(timeCalc.calcTime())
, mDeactivateTime(timeCalc.calcTime())
{
}

void GHTimeUpdater::update(void)
{
    float currTime = mTimeCalc.calcTime() - mStartTime;
    mTimeVal.newFrame();
    mTimeVal.setTime(currTime);
    mTimeVal.calcTimePassed();
}

void GHTimeUpdater::onActivate(void)
{
    float timePaused = mTimeCalc.calcTime() - mDeactivateTime;
    mStartTime += timePaused;
}

void GHTimeUpdater::onDeactivate(void)
{
    mDeactivateTime = mTimeCalc.calcTime();
    // zero out the time passed since it will not be getting updated.
    float currTime = mTimeVal.getTime();
    mTimeVal.newFrame();
    mTimeVal.setTime(currTime);
    mTimeVal.calcTimePassed();
}
