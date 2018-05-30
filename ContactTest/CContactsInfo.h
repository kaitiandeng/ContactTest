#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>

#define _F_CONTACTSINFO "./ConInfo.txt"

using namespace std;

struct ContactsInfo
{
	int id;
	string Name;
	string Tel;
	string Email;
};

class ConInfo
{
public:
	ConInfo();
	~ConInfo();

	//读取联系人信息
	void ReadInfo();

	//添加联系人信息
	void AddInfo(int id, string name, string tel, string email);

	//编辑联系人信息
	void EditInfo(int id, CString name, CString tel, CString email);

	//删除联系人
	void DelInfo(int id);

	//存储联系人信息
	vector<ContactsInfo> vc;

	//记录联系人个数
	int num;
};
