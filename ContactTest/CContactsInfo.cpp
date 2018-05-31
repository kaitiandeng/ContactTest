#include "stdafx.h"
#include "CContactsInfo.h"
#include "ContactTestDlg.h"


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
	int count = 0;
	string line;
	
	if (id != 0)
	{
		//1������༭��֮ǰ������
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

	//2���༭�д�д��
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

	//3���༭�к��Ƶ�����һ���ļ���
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

	//4�������Ĺ������ݸ��Ƶ����ļ���ȥ
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

//ɾ����ϵ��
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
