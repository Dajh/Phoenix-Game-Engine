#pragma once

#ifndef CLOCK_H
#define CLOCK_H

#include <Windows.h>

class Clock
{
private:
	LARGE_INTEGER freq;
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	LARGE_INTEGER elapsedMicroseconds;
	double seconds;
	
public:
	Clock();
	LARGE_INTEGER getClockTicks();
	LARGE_INTEGER getTicksPerSeconds();
	double ticksToSeconds(LARGE_INTEGER ticks);
	LARGE_INTEGER secondsToTicks(double secs);
	LARGE_INTEGER getTimeElapsed();
	double getTime();
	void calculateTime();
	void setStartTime();
	void setEndTime();
};

#endif // !CLOCK_H
