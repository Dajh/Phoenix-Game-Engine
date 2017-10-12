#include "LogManager.h"

LogManager* LogManager::instance = NULL;

LogManager::LogManager()
{
	os = NULL;
	fileName = "logFile.log";
	currentLevel = LOG_INFO;
}

LogManager::~LogManager()
{
	close();
}



LogManager& LogManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new LogManager();
	}
	return *instance;
}

void LogManager::setLogLevel(LogLevel level)
{
	currentLevel = level;
}




LogManager::LogLevel LogManager::getLogLevel()
{
	return currentLevel;
}


void LogManager::setLogFile(std::string newFileName)
{
	close();
	os = new std::ofstream(newFileName.c_str());
	currentLevel = LOG_INFO;
}

void LogManager::close()
{
	if (os != NULL)
	{
		os->close();
		delete os;
		os = NULL;
	}
}

void LogManager::log(LogLevel level, std::string msg)
{
	if (level <= currentLevel)
	{
		if (os == NULL)
		{
			setLogFile(fileName);
		}
		(*os) << msg << "\n";
		os->flush();
	}
}

void LogManager::error(std::string msg)
{
	log(LOG_ERROR, msg);
}

void LogManager::warn(std::string msg)
{
	log(LOG_WARN, msg);
}

void LogManager::trace(std::string msg)
{
	log(LOG_TRACE, msg);
}

void LogManager::info(std::string msg)
{
	log(LOG_INFO, msg);
}