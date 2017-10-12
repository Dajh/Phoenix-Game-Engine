#include "Clock.h"
#include "LogManager.h"
#include "PhoenixApplication.h"
#include "OpenGLRenderer.h"

PhoenixApplication::PhoenixApplication()
{
	LogManager::getInstance(); 
		clock = new Clock();
}

void PhoenixApplication::onStart()
{

}

void PhoenixApplication::preRender()
{

}

void PhoenixApplication::render()
{

}

void PhoenixApplication::postRender()
{

}

void PhoenixApplication::onEnd()
{

}

void PhoenixApplication::logMessage()
{

}