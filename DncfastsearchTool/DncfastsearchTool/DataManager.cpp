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
		ERROR_LOG("Get Result Tables failed %s\n", zErrMsg);
	}
	else
	{
		//fprintf(stdout,"Get Result Tables successfully \n");
		TRACE_LOG("Get Result Tables successfully \n");
	}
}