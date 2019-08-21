// Copyright 2010 Golden Hammer Software
#pragma once

class GHTimeCalculator;

// system-independent class for holding time information.
class GHTimeVal
{
public:
	GHTimeVal(void);

	float getTime(void) const { return mTime; }
	void setTime(float nrt) { mTime = nrt; }

	float getLastTime(void) const { return mLastTime; }
	void setLastTime(float nrt) { mLastTime = nrt; }

	float getTimePassed(void) const { return mTimePassed; }
	void setTimePassed(float time) { mTimePassed = time; }

	// calc the new normalized time passed assuming the current values are valid.
	void calcTimePassed(void);
	// move the current frame info into the previous frame.
	void newFrame(void);
	// make this val current with 0 timepassed
	void clearTimePassed(const GHTimeCalculator& timeCalculator);

private:
	// ** this frame **
	// normalized curr time.
	float mTime;

	// ** previous frame, for finding time passed **
	// normalized last frame time.
	float mLastTime;

	// ** timepassed **
	float mTimePassed;
};
