#pragma once
#include "CContactsInfo.h"

// CAdd 对话框

class CAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CAdd)

public:
	CAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString mfc_Add_Name;
	CString mfc_Add_Tel;
	CString mfc_Add_Email;
	virtual void OnOK();
	afx_msg void OnBnClickedButton1();
};
