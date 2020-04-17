#pragma once

#include "Common.h"


#pragma comment(lib,"./sqlite/sqlite3.lib")


class SqliteManager
{
public:
	SqliteManager();
	~SqliteManager();
public:
	void Open(const string &path);
	void Close();
	void ExcuteSql(const string &sql);
	void GetResultTable(const string &sql,int &row,int &col,char **&ppRet);
private:
	sqlite3 *m_db;
};