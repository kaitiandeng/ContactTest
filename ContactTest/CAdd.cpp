// CAdd.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "CAdd.h"
#include "afxdialogex.h"


// CAdd 对话框

IMPLEMENT_DYNAMIC(CAdd, CDialogEx)

CAdd::CAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
{

}

CAdd::~CAdd()
{
}

void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdd::OnBnClickedButton2)
END_MESSAGE_MAP()


// CAdd 消息处理程序


void CAdd::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
