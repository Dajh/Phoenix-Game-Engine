#include "Clock.h"

Clock::Clock()
{
	freq = getTicksPerSeconds();
	startTime = getClockTicks();
	endTime = getClockTicks();
	elapsedMicroseconds.QuadPart = (((endTime.QuadPart - startTime.QuadPart) * 1000000) / freq.QuadPart);
	seconds = 0;
}

LARGE_INTEGER Clock::getClockTicks()
{
	LARGE_INTEGER c;
	QueryPerformanceCounter(&c);
	return c;
}

LARGE_INTEGER Clock::getTicksPerSeconds()
{
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	return f;
}

void Clock::setStartTime()
{
	startTime = getClockTicks();
}

void Clock::setEndTime()
{
	endTime = getClockTicks();
}

double Clock::ticksToSeconds(LARGE_INTEGER ticks)
{
	return ((double)ticks.QuadPart) / ((double)freq.QuadPart);
}

LARGE_INTEGER Clock::secondsToTicks(double secs)
{
	LARGE_INTEGER t;
	t.QuadPart = (LONGLONG)(secs * (double)freq.QuadPart);
	return t;
}

void Clock::calculateTime()
{
	elapsedMicroseconds.QuadPart = (((endTime.QuadPart - startTime.QuadPart) * 1000000) / freq.QuadPart);
}

LARGE_INTEGER Clock::getTimeElapsed()
{
	return elapsedMicroseconds;
}

double Clock::getTime()
{
	return ticksToSeconds(getTicksPerSeconds());
}

