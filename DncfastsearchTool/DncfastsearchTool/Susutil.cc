#define _CRT_SECURE_NO_WARNINGS
#include "Sysutil.h"

void DirectionList(const string &path,vector<string> &subfile,vector<string> &subdir)
{
	string _path = path;//"D:\\sqlite\\Pro_81"
	_path += "\\*.*";//"D:\\sqlite\\Pro_81\\*.*"
	_finddata_t file;
	long handle = _findfirst(_path.c_str(),&file);
	if (handle == -1)
	{
		perror("_findfirst");
		return;
	}

	do
	{
		if (strcmp(file.name, ".")  == 0|| strcmp(file.name, "..") == 0)
			continue;
		if (file.attrib & _A_SUBDIR)
		{
			/*cout << file.name<<":"<<endl;
			string &path_tmp = _path;
			path_tmp += "\\";
			path_tmp += file.name;
			DirectionList(path_tmp);*/
			subdir.push_back(file.name);
		}
		else
		{
			//cout << file.name << endl;
			subfile.push_back(file.name);
		}
	} while (_findnext(handle,&file) == 0);

	_findclose(handle);
}
