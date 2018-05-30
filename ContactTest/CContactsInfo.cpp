#include "stdafx.h"
#include "CContactsInfo.h"
#include "ContactTestDlg.h"


ConInfo::ConInfo()
{
}

ConInfo::~ConInfo()
{
}

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
	//从被编辑行开始复制到另外一个文件中
	ifstream ciFile(_F_CONTACTSINFO);
	ofstream tmpFile(_F_TMPFILE,ios_base::trunc);

	int count = 0;
	string line;

	while (!ciFile.eof())
	{
		getline(ciFile,line);
		if (count >= id)
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

	//编辑行写入_F_CONTACTSINFO文件中
	ofstream oFile(_F_CONTACTSINFO,ios_base::app);

	oFile << setiosflags(ios_base::left)
		  << setw(5) << id << " "
		  << resetiosflags(ios_base::left)
		  << setw(15) << name << " "
		  << resetiosflags(ios_base::left)
		  << setw(15) << tel << " "
		  << resetiosflags(ios_base::left)
		  << setw(25) << email << endl;

	oFile.close();

	//将被编辑行后面的数据复制到_F_CONTACTSINFO中来，并删除要被编辑行
	ofstream ciFile2(_F_CONTACTSINFO,ios_base::app);
	ifstream tmpFile2(_F_TMPFILE);

	count = 0;

	while (!tmpFile2.eof())
	{
		getline(tmpFile2, line);
		if (count != 0)
		{
			ciFile2 << line << endl;
		}
	
		if (tmpFile2.peek() == EOF)
		{
			break;
		}
		count++;
	}

	ciFile2.close();
	tmpFile2.close();
}

//删除联系人
void ConInfo::DelInfo(int id)
{
	
	ifstream ciFile(_F_CONTACTSINFO);
	ofstream tmpFile(_F_TMPFILE,ios_base::trunc);

	string line;
	int count = 0;

	while (!ciFile.eof())
	{
		getline(ciFile,line);
		if (id != count)
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

	ofstream ciFile2(_F_CONTACTSINFO,ios_base::trunc);
	fstream tmpFile2(_F_TMPFILE);

	while (!tmpFile2.eof())
	{
		getline(tmpFile2,line);
		ciFile2 << line << endl;
		if (tmpFile2.peek() == EOF)
		{
			break;
		}
	}

	ciFile2.close();
	tmpFile2.close();
	DeleteFile(_F_TMPFILE);
}
