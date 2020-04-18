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

/////////////////////////////////////////////////////////////
#define DOC_DB    "doc.db"
#define DOC_TABLE "doc_tb"
////////////////////////////////////////////////////////////
class DataManager
{
public:
	DataManager();
	~DataManager();
public:
	void SqliteInit();
public:
	void InsertDoc(const string &path,const string &doc);
	void GetDocs(const string &path,multiset<string> &docs);
	void DeleteDoc(const string &path,const string &doc);
public:
	void Search(const string &key,vector<pair<string,string>> &doc_path);
private:
	SqliteManager m_dbmgr;
};