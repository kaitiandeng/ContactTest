#pragma once


// CSearch 对话框

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALO_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
