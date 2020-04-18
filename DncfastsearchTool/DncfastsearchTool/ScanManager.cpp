#define _CRT_SECURE_NO_WARNINGS

#include "ScanManager.h"
#include "SySutil.h"

void ScanManager::ScanDirectory(const string &path)
{
	//ɨ�豾���ļ�ϵͳ

	vector <string> local_files;
	vector <string> local_dirs;
	DirectionList(path,local_files,local_dirs);
	set<string> local_set;
	local_set.insert(local_dirs.begin(),local_dirs.end());
	local_set.insert(local_files.begin(),local_files.end());
	//ɨ�����ݿ��ļ�ϵͳ

	multiset<string> db_set;
	m_db.GetDocs(path,db_set);     //?����
	//�����ݿ��õ���������

	//�Աȱ����ļ������ݿ��ļ�

	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while (local_it != local_set.end() && db_it != db_set.end())
	{
		if (*local_it < *db_it)
		{
			//�����ļ����ڣ����ݿ��ļ������ڣ����ݿ������ļ�
			m_db.InsertDoc(path,*local_it);
			local_it++;
		}
		else if (*local_it > *db_it)
		{
			//�����ļ������ڣ����ݿ��ļ����ڣ����ݿ�ɾ���ļ�
			m_db.DeleteDoc(path,*db_it);
			db_it++;
		}
		else
		{
			//�����ļ����ڣ����ݿ��ļ����ڣ����ݿⲻ��
			local_it++;
			db_it++;
		}
	}
	while (local_it != local_set.end())
	{
		//�����ļ����ڣ����ݿ��ļ������ڣ����ݿ������ļ�
		m_db.InsertDoc(path,*local_it);
		local_it++;
	}
	while (db_it != db_set.end())
	{
		//�����ļ������ڣ����ݿ��ļ����ڣ����ݿ�ɾ���ļ�
		m_db.DeleteDoc(path,*db_it);
		db_it++;
	}
	//�ݹ������Ŀ¼
	for (auto &dir : local_dirs)
	{
		string dir_path = path;
		dir_path += "\\";
		dir_path += dir; //������һ��Ŀ¼�µ��ļ�
		ScanDirectory(dir_path);
	}
}
