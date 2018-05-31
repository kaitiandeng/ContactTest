#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include <sstream>

#define _F_CONTACTSINFO "./ConInfo.txt"
#define _F_TMPFILE "./tmpFile.txt"
#define _F_TMPFILE2 "./tmpFile2.txt"

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

	//��ȡ��ϵ����Ϣ
	void ReadInfo();

	//�����ϵ����Ϣ
	void AddInfo(int id, string name, string tel, string email);

	//�༭��ϵ����Ϣ
	void EditInfo(int id, string name, string tel, string email);

	//ɾ����ϵ��
	void DelInfo(int id);

};
