#include "stdafx.h"
#include "CContactsInfo.h"
#include "ContactTestDlg.h"


//读取联系人信息
void ConInfo::ReadInfo()
{
	//输入方式打开文件
	ifstream ciFile(_F_CONTACTSINFO);
	
	int n = 0;
	string info,id,name,tel,email;

	while (getline(ciFile,info))
	{	
		//读取一行数据中的id,name,tel,email 信息
		istringstream is(info);
		is >> id >> name >> tel >> email;

		//string转cstring
		CString cstr1,cstr2,cstr3;
		cstr1.Format("%s", name.c_str());
		cstr2.Format("%s", tel.c_str());
		cstr3.Format("%s", email.c_str());		
		
		//向listctrl中插入数据,获取父窗口指针
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.InsertItem(n, cstr1);
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.SetItemText(n, 1, cstr2);
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.SetItemText(n, 2, cstr3);

		n++;
	}

	ciFile.close();
	
}

//添加联系人信息
void ConInfo::AddInfo(int id, string name, string tel, string email)
{
	//输出方式打开文件
	ofstream ciFile(_F_CONTACTSINFO,ios_base::app);

	ciFile << setiosflags(ios_base::left) 
		   << setw(5) << id << " "
		   << resetiosflags(ios_base::left)
		   << setw(15) << name << " "
		   << resetiosflags(ios_base::left)
		   << setw(15) << tel << " "
		   << resetiosflags(ios_base::left)
		   << setw(25) << email << endl;

	ciFile.close();
}

//编辑联系人信息
void ConInfo::EditInfo(int id, string name, string tel, string email)
{
	int count = 0;
	string line;
	
	if (id != 0)
	{
		//1、保存编辑行之前的内容
		ifstream ifFile(_F_CONTACTSINFO);
		ofstream ofFile(_F_TMPFILE, ios_base::trunc);

		while (!ifFile.eof())
		{
			getline(ifFile, line);
			if (count < id)
			{
				ofFile << line << endl;
			}
			else if (count == id)
			{
				break;
			}
			if (ifFile.peek() == EOF)
			{
				break;
			}


			ifFile.close();
			ofFile.close();

		}
	}

	//2、编辑行处写入
	if (id == 0)
	{
		ofstream oFile(_F_TMPFILE, ios_base::trunc);
		oFile << setiosflags(ios_base::left)
			<< setw(5) << id << " "
			<< resetiosflags(ios_base::left)
			<< setw(15) << name << " "
			<< resetiosflags(ios_base::left)
			<< setw(15) << tel << " "
			<< resetiosflags(ios_base::left)
			<< setw(25) << email << endl;

		oFile.close();
	}
	else
	{
		ofstream oFile(_F_TMPFILE, ios_base::app);

		oFile << setiosflags(ios_base::left)
			<< setw(5) << id << " "
			<< resetiosflags(ios_base::left)
			<< setw(15) << name << " "
			<< resetiosflags(ios_base::left)
			<< setw(15) << tel << " "
			<< resetiosflags(ios_base::left)
			<< setw(25) << email << endl;

		oFile.close();
	}

	//3、编辑行后复制到另外一个文件中
	ifstream ciFile(_F_CONTACTSINFO);
	ofstream tmpFile(_F_TMPFILE, ios_base::app);

	while (!ciFile.eof())
	{
		getline(ciFile, line);
		if (count > id)
		{
			tmpFile << line << endl;
		}
		if (ciFile.peek() == EOF)
		{
			break;
		}
		count++;
	}

	ciFile.close();
	tmpFile.close();

	//4、将更改过的内容复制到主文件中去
	ofstream ciFile2(_F_CONTACTSINFO,ios_base::trunc);
	ifstream tmpFile2(_F_TMPFILE);

	count = 0;

	while (!tmpFile2.eof())
	{
		getline(tmpFile2, line);

		ciFile2 << line << endl;
	
	
		if (tmpFile2.peek() == EOF)
		{
			break;
		}
		count++;
	}

	ciFile2.close();
	tmpFile2.close();

	DeleteFile(_F_TMPFILE);
}

//删除联系人
void ConInfo::DelInfo(int id)
{
	int count = 0;
	string info;

	ifstream ciFile(_F_CONTACTSINFO);
	ofstream tmpFile(_F_TMPFILE,ios_base::trunc);

	while (!ciFile.eof())
	{
		getline(ciFile,info);
		if (count != 0)
		{
			tmpFile << info << endl;
		}
		if (ciFile.peek() == EOF)
		{
			break;
		}
		count++;
	}

	ciFile.close();
	tmpFile.close();

	ofstream ofs(_F_CONTACTSINFO,ios_base::trunc);
	ifstream ifs(_F_TMPFILE);

	while (!ifs.eof())
	{
		string info2;
		getline(ifs,info2);
		ofs << info2 << endl;
		if (ifs.peek() == EOF)
		{
			break;
		}
	}

	DeleteFile(_F_TMPFILE);
}

ConInfo::ConInfo()
{
}

ConInfo::~ConInfo()
{
}
