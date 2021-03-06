// CEDIT.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "CEDIT.h"
#include "afxdialogex.h"
#include "ContactTestDlg.h"
#include "CContactsInfo.h"


// CEDIT 对话框

IMPLEMENT_DYNAMIC(CEDIT, CDialogEx)

CEDIT::CEDIT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Edit, pParent)
	, mfc_Edit_Name(_T(""))
	, mfc_Edit_Tel(_T(""))
	, mfc_Edit_Email(_T(""))
{

}

CEDIT::~CEDIT()
{
}

void CEDIT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mfc_Edit_Name);
	DDX_Text(pDX, IDC_EDIT2, mfc_Edit_Tel);
	DDX_Text(pDX, IDC_EDIT3, mfc_Edit_Email);
}


BEGIN_MESSAGE_MAP(CEDIT, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CEDIT::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CEDIT::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEDIT::OnBnClickedButton2)
END_MESSAGE_MAP()


// CEDIT 消息处理程序


void CEDIT::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CEDIT::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CContactTestDlg cctd;
	CString str1, str2, str3;

	//将控件中的内容同步到变量中去
	UpdateData(TRUE);

	//获取父窗口指针 更改listctrl 中的值
	str1 = mfc_Edit_Name.GetString();
	str2 = mfc_Edit_Tel.GetString();
	str3 = mfc_Edit_Email.GetString();

	int nItem = ((CContactTestDlg*)GetParent())->mfc_listCtrl.GetSelectionMark();
	((CContactTestDlg*)GetParent())->mfc_listCtrl.SetItemText(nItem,0,str1);
	((CContactTestDlg*)GetParent())->mfc_listCtrl.SetItemText(nItem,1,str2);
	((CContactTestDlg*)GetParent())->mfc_listCtrl.SetItemText(nItem,2,str3);
	((CContactTestDlg*)GetParent())->UpdateData(FALSE);
	
	//CString转string
	string name(str1.GetBuffer());
	str1.ReleaseBuffer();
	string tel(str2.GetBuffer());
	str2.ReleaseBuffer();
	string email(str3.GetBuffer());
	str3.ReleaseBuffer();

	ConInfo ci;
	ci.EditInfo(nItem, name, tel, email);

	CDialog::OnOK();
}


void CEDIT::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
