#define _CRT_SECURE_NO_WARNINGS

#include "Common.h"
#include "SySutil.h"
#include "./sqlite/sqlite3.h"
//静态库
#pragma comment(lib,"./sqlite/sqlite3.lib")


int sqlite3_get_table(
	sqlite3 *db,          /* An open database */
	const char *zSql,     /* SQL to be evaluated */
	char ***pazResult,    /* Results of the query */
	int *pnRow,           /* Number of result rows written here */
	int *pnColumn,        /* Number of result columns written here */
	char **pzErrmsg       /* Error msg written here */
	);
void sqlite3_free_table(char **result);
void Test_Sqlite()
{
	//创建数据库
	sqlite3 *db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
	{
		cout << "open database is failed!" << endl;
	}
	else
	{
		cout << "open database is successfally" << endl;
	}
	//操作数据库
	string sql = "select * from doc_db";
	char **result;
	int row;
	int col;
	char *zErrMsg = 0;
	rc = sqlite3_get_table(db,sql.c_str(),&result,&row,&col,&zErrMsg);

	for (int i = 0; i <= row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			//cout << *(result + (i * col) + j) << " ";
			printf("%s ", *(result + (i * col) + j));
		}
		cout << endl;
	}
	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);
}
int main(int argc, char *argv[])
{
	Test_Sqlite();
	return 0;
}
//void Test_DirectionList()
//{
//	const string &path = "D:\\我的文档\\Tencent Files\\1374638229\\QQ";
//	vector<string> subfile, subdir;
//	DirectionList(path,subfile,subdir);
//	for (auto &e : subfile)
//		cout << e << endl;
//	cout << "dir>" << endl;
//	for (auto &e : subdir)
//		cout << e << endl;
//}
//void Test_Sql()
//{
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	rc = sqlite3_open("test.db", &db);
//
//	if (rc){
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		exit(0);
//	}
//	else{
//		fprintf(stderr, "Opened database successfully\n");
//	}
//	sqlite3_close(db);
//}
//static int callback(void *data, int argc, char **argv, char **azColName)
//{
//	int i;
//	fprintf(stderr, "%s: \n", (const char*)data);
//	for (i = 0; i<argc; i++){
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//	printf("\n");
//	return 0;
//}
//void Test_Sqlite()
//{
//	//创建数据库
//	sqlite3 *db;
//	int rc = sqlite3_open("test.db",&db);
//	if (rc != SQLITE_OK)
//	{
//		cout << "open database is failed!" << endl;
//	}
//	else
//	{
//		cout << "open database is successfally" << endl;
//	}
//	//操作数据库
//	//string sql = "create table doc_db(id int primary key autoincrease,name varchar(20),path varchar(100))";
//	//string sql = "insert into doc_db values(NULL,'xyz','d:\\')";
//	string sql = "select * from doc_db";
//	char *zErrmgz = 0;
//	const char* data = "Callback function called";
//	//sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
//	//rc = sqlite3_exec(db,sql.c_str(),0,0,&zErrmgz);
//	rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrmgz);//callback-》回调函数
//
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr,"SQL error: %s\n",zErrmgz);
//		sqlite3_free(zErrmgz);
//	}
//	else
//	{
//		//fprintf(stdout,"create table successfully\n");
//		fprintf(stdout, "progrmme run successfully\n");
//		
//	}
//	sqlite3_close(db);
//}
//int main(int argc,char *argv[])
//{
//	//Test_DirectionList();
//	//Test_Sql();
//	Test_Sqlite();
//	return 0;
//}
