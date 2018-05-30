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
	
	string info;
	string id;
	string name;
	string tel;
	string email;

	int n = 0;

	while (getline(ciFile,info))
	{	
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
void ConInfo::EditInfo(int id, CString name, CString tel, CString email)
{

}

//删除联系人
void ConInfo::DelInfo(int id)
{

}
