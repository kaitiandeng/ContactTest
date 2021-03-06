// CAdd.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "CAdd.h"
#include "afxdialogex.h"
#include "ContactTestDlg.h"



// CAdd 对话框

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
	, mfc_Add_Name(_T(""))
	, mfc_Add_Tel(_T(""))
	, mfc_Add_Email(_T(""))
{
	
}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mfc_Add_Name);
	DDX_Text(pDX, IDC_EDIT2, mfc_Add_Tel);
	DDX_Text(pDX, IDC_EDIT3, mfc_Add_Email);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdd::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdd::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAdd 消息处理程序


void CAdd::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void CAdd::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void CAdd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取编辑框中的内容
	UpdateData(TRUE);
	CString cstr1, cstr2, cstr3;
	cstr1 = mfc_Add_Name.GetString();
	cstr2 = mfc_Add_Tel.GetString();
	cstr3 = mfc_Add_Email.GetString();

	//获取父窗口 listctrl 控件的大小
	int listSize;
	listSize = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetItemCount();

	//向listctrl中插入数据
	((CContactTestDlg*)GetParent())->mfc_listCtrl.InsertItem(listSize,cstr1);
	((CContactTestDlg*)GetParent())->mfc_listCtrl.SetItemText(listSize,1, cstr2);
	((CContactTestDlg*)GetParent())->mfc_listCtrl.SetItemText(listSize,2, cstr3);

	//cstring转string
	string str1(cstr1.GetBuffer());
	cstr1.ReleaseBuffer();
	string str2(cstr2.GetBuffer());
	cstr2.ReleaseBuffer();
	string str3(cstr3.GetBuffer());
	cstr3.ReleaseBuffer();

	ConInfo ci;
	ci.AddInfo(listSize + 1,str1,str2,str3);

	CDialog::OnOK();
}
