#include "stdafx.h"
#include "CContactsInfo.h"
#include "ContactTestDlg.h"


ConInfo::ConInfo()
{
}

ConInfo::~ConInfo()
{
}

//��ȡ��ϵ����Ϣ
void ConInfo::ReadInfo()
{
	//���뷽ʽ���ļ�
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

		//stringתcstring
		CString cstr1,cstr2,cstr3;
		cstr1.Format("%s", name.c_str());
		cstr2.Format("%s", tel.c_str());
		cstr3.Format("%s", email.c_str());		
		
		//��listctrl�в�������,��ȡ������ָ��
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.InsertItem(n, cstr1);
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.SetItemText(n, 1, cstr2);
		((CContactTestDlg*)AfxGetMainWnd())->mfc_listCtrl.SetItemText(n, 2, cstr3);

		n++;
	}

	ciFile.close();
}

//�����ϵ����Ϣ
void ConInfo::AddInfo(int id, string name, string tel, string email)
{
	//�����ʽ���ļ�
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

//�༭��ϵ����Ϣ
void ConInfo::EditInfo(int id, CString name, CString tel, CString email)
{

}

//ɾ����ϵ��
void ConInfo::DelInfo(int id)
{

}
