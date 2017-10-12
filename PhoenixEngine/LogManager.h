#pragma once

#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>

class LogManager 
{
public:
	enum LogLevel {LOG_NONE, LOG_ERROR, LOG_WARN, LOG_TRACE, LOG_INFO};
	std::string fileName;
	static LogManager& getInstance();
	~LogManager();
	void setLogFile(std::string newName);
	void close();
	void setLogLevel(LogLevel level);
	LogLevel getLogLevel();
	void log(LogLevel level, std::string msg);
	void error(std::string msg);
	void warn(std::string msg);
	void trace(std::string msg);
	void info(std::string msg);

private:
	static LogManager *instance;
	LogLevel currentLevel;
	std::ofstream *os;
	LogManager();


};

#endif