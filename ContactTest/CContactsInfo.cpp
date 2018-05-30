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
	
	int n = 0;
	string info,id,name,tel,email;

	while (getline(ciFile,info))
	{	
		//��ȡһ�������е�id,name,tel,email ��Ϣ
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
void ConInfo::EditInfo(int id, string name, string tel, string email)
{
	//�ӱ��༭�п�ʼ���Ƶ�����һ���ļ���
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

	//�༭��д��_F_CONTACTSINFO�ļ���
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

	//�����༭�к�������ݸ��Ƶ�_F_CONTACTSINFO��������ɾ��Ҫ���༭��
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

//ɾ����ϵ��
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
