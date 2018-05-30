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

	//��ȡ��ϵ����Ϣ
	void ReadInfo();

	//�����ϵ����Ϣ
	void AddInfo(int id, string name, string tel, string email);

	//�༭��ϵ����Ϣ
	void EditInfo(int id, CString name, CString tel, CString email);

	//ɾ����ϵ��
	void DelInfo(int id);

	//�洢��ϵ����Ϣ
	vector<ContactsInfo> vc;

	//��¼��ϵ�˸���
	int num;
};
