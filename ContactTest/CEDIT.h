#pragma once


// CEDIT 对话框

class CEDIT : public CDialogEx
{
	DECLARE_DYNAMIC(CEDIT)

public:
	CEDIT(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CEDIT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Edit };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString mfc_Edit_Name;
	CString mfc_Edit_Tel;
	CString mfc_Edit_Email;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
