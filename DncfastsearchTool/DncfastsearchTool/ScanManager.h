#pragma once

#include "Common.h"
#include "DataManager.h"

class ScanManager
{
public:
	void ScanDirectory(const string &path);
public:
	static ScanManager& CreateInstance(const string &path);
	void StartScan(const string &path);
private:
	ScanManager();
private:
	//DataManager m_db;
};