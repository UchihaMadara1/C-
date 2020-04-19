#define _CRT_SECURE_NO_WARNINGS

#include "DataManager.h"
#include "Common.h"
#include "SySutil.h"

SqliteManager::SqliteManager() :m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	SqliteManager::Close();
}
void SqliteManager::Open(const string &path)
{
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open(path.c_str(), &m_db);

	if (rc){
		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		ERROR_LOG("Can't open database: %s\n", sqlite3_errmsg(m_db));
		exit(0);
	}
	else{
		//fprintf(stderr, "Opened database successfully\n");
		TRACE_LOG("Opened database successfully\n");
	}
}
void SqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);
		if (rc != SQLITE_OK)
		{
			//fprintf(stderr,"close database failed:%s\n",sqlite3_errmsg(m_db));
			ERROR_LOG("close database failed:%s\n", sqlite3_errmsg(m_db));
		}
		else
		{
			//fprintf(stdout,"close database sucessfully...\n");
			TRACE_LOG("close database sucessfully...\n");
		}
	}
}
void SqliteManager::ExcuteSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK){
		//fprintf(stderr, "SQL(%s) error: %s\n", sql.c_str(),zErrMsg);
		ERROR_LOG("SQL(%s) error: %s\n", sql.c_str(), zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
		//fprintf(stdout, "SQL(%s) Excute successfully\n",sql.c_str());
		TRACE_LOG("SQL(%s) Excute successfully\n", sql.c_str());
	}
}
void SqliteManager::GetResultTable(const string &sql, int &row, int &col, char **&ppRet)
{
	char *zErrMsg;
	int rc = sqlite3_get_table(m_db,sql.c_str(),&ppRet,&row,&col,&zErrMsg);
	if (rc != SQLITE_OK)
	{
		//fprintf(stderr,"Get Result Tables failed %s\n",zErrMsg);
		ERROR_LOG("Get Result Tables failed %s\n", zErrMsg);       //BUG
	}
	else
	{
		//fprintf(stdout,"Get Result Tables successfully \n");
		TRACE_LOG("Get Result Tables successfully \n");
	}
}
//////////////////////////////////////////////////////////////
AutoGetResultTable::AutoGetResultTable(SqliteManager *db, const string &sql,
	int &row, int &col, char **&ppRet) :m_db(db)
{
	m_db->GetResultTable(sql, row, col, ppRet);
	m_ppRet = ppRet;
}
AutoGetResultTable::~AutoGetResultTable()
{
	if (m_ppRet)
		sqlite3_free_table(m_ppRet);
}

/////////////////////////////////////////////////////////////////////
DataManager& DataManager::Getinstance()
{
	static DataManager inst;
	return inst;
}


DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);
	SqliteInit();
}
void DataManager::SqliteInit()
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql,"create table if not exists %s(id integer primary key autoincrement, name text, path text)",DOC_TABLE);
	m_dbmgr.ExcuteSql(sql);
}
DataManager::~DataManager()
{}
void DataManager::InsertDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql,"insert into %s values(null,'%s','%s')",DOC_TABLE,doc.c_str(),path.c_str());
	//insert into doc_tb values(null,'1.txt','c:\');
	m_dbmgr.ExcuteSql(sql);
}
void DataManager::GetDocs(const string &path, multiset<string> &docs)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql,"select name from %s where path='%s'",DOC_TABLE,path.c_str());
	int row = 0, col = 0;
	char **ppRet = 0;
	//m_dbmgr.GetResultTable(sql,row,col,ppRet);
	AutoGetResultTable at(&m_dbmgr,sql,row,col,ppRet);
	for (int i = 1; i <= row; ++i)     //无数据时的处理
	{
		docs.insert(ppRet[i]);
	}
	//释放结果表
	//sqlite3_free_table(ppRet);
	
}
void DataManager::DeleteDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql,"delete from %s where name='%s' and path='%s'",DOC_TABLE,doc.c_str(),path.c_str());
	m_dbmgr.ExcuteSql(sql);

	//级联删除目录下的文件

	string doc_path = path;
	doc_path += "\\";
	doc_path += doc;

	memset(sql,0,SQL_BUFFER_SIZE);
	sprintf(sql,"delete from %s where path like '%s%%'",DOC_TABLE,doc_path.c_str());

	m_dbmgr.ExcuteSql(sql);
}

////////////////////////////////////////////////////////////////
void DataManager::Search(const string &key,vector<pair<string,string>> &doc_path)
{
	char sql[SQL_BUFFER_SIZE] = {0};
	sprintf(sql,"select name,path from %s where name like '%%%s%%'",DOC_TABLE,key.c_str());
	int row = 0, col = 0;
	char **ppRet = 0;
	//m_dbmgr.GetResultTable(sql,row,col,ppRet);
	AutoGetResultTable at(&m_dbmgr,sql,row,col,ppRet);
	doc_path.clear();
	for (int i = 1; i <= col; ++i)
	{
		doc_path.push_back(make_pair(ppRet[i*col],ppRet[i*col+1]));
	}
	//释放结果表
	//sqlite3_free_table(ppRet);
}
