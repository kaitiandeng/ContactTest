// Edit.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "Edit.h"
#include "afxdialogex.h"


// Edit 对话框

IMPLEMENT_DYNAMIC(Edit, CDialogEx)

Edit::Edit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDIT, pParent)
{

}

Edit::~Edit()
{
}

void Edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Edit, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Edit::OnBnClickedButton2)
END_MESSAGE_MAP()


// Edit 消息处理程序


void Edit::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
