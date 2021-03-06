// CSearch.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "CSearch.h"
#include "afxdialogex.h"
#include "ContactTestDlg.h"


// CSearch 对话框

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)

CSearch::CSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALO_SEARCH, pParent)
	, mfc_Search_Name(_T(""))
	, mfc_Search_Tel(_T(""))
{

}

CSearch::~CSearch()
{
}

void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mfc_Search_Name);
	DDX_Text(pDX, IDC_EDIT2, mfc_Search_Tel);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSearch::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSearch 消息处理程序


void CSearch::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取输入
	CString str1, str2,str3,str4,str5;
	int listSize,flag = 0;

	UpdateData(TRUE);
	listSize = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemCount();
	str1 = mfc_Search_Name.GetString();
	str2 = mfc_Search_Tel.GetString();

	if (str1 == "" && str2 != "")
	{
		for (int i = 0; i < listSize; i++)
		{
			str3 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 0);
			str4 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 1);
			str5 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 2);

			if (str2 == str4)
			{
				flag = 0;
				MessageBox(TEXT("Name: ") + str3 + '\n' + TEXT("Tel: ") + str4 + '\n' + TEXT("Email: ") + str5);
				CDialog::OnOK();
				break;
			}
			else
			{
				flag = 1;
			}
		}
	}
	else if (str1 != "" && str2 == "")
	{
		for (int i = 0; i < listSize; i++)
		{
			str3 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 0);
			str4 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 1);
			str5 = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemText(i, 2);

			if (str1 == str3)
			{
				flag = 0;
				MessageBox(TEXT("Name: ") + str3 + '\n' + TEXT("Tel: ") + str4 + '\n' + TEXT("Email: ") + str5);
				CDialog::OnOK();
				break;
			}
			else
			{
				flag = 1;
			}
		}
	}
	else if (str1 == "" && str2 == "")
	{
		flag = 0;
		MessageBox(TEXT("Please input info!"));
	}
	else
	{
		flag = 0;
		MessageBox(TEXT("Not Found! Please check your info!"));
		CDialog::OnOK();
	}

	if (flag == 1)
	{
		MessageBox(TEXT("Not Found! Please check your info!"));
		CDialog::OnOK();
	}
}


void CSearch::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}
