#pragma once

#include "LogManager.h"
#include "Clock.h"
#include "OpenGLRenderer.h"

class PhoenixApplication
{
private:
	LogManager *logManager;
	Clock *clock;
public:
	OpenGLRenderer* renderer;
	PhoenixApplication();
	~PhoenixApplication();
	virtual void onStart();
	virtual void onEnd();
	virtual void preRender();
	virtual void render();
	virtual void postRender();
	virtual void logMessage();
};