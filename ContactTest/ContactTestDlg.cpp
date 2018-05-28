
// ContactTestDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "ContactTest.h"
#include "ContactTestDlg.h"
#include "afxdialogex.h"
#include "CAdd.h"
#include "Edit.h"
#include "CSearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CContactTestDlg 对话框



CContactTestDlg::CContactTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTACTTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CContactTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mfc_listCtrl);
}

BEGIN_MESSAGE_MAP(CContactTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CContactTestDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CContactTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CContactTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CContactTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CContactTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CContactTestDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CContactTestDlg 消息处理程序

BOOL CContactTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//列表控件 mfc_listCtrl

	CString str[] = {TEXT("姓名"),TEXT("电话"),TEXT("Email")};

	for (int i = 0; i < 3; i++)
	{
		//设置表头
		mfc_listCtrl.InsertColumn(i,str[i],LVCFMT_LEFT,200);
	}

	//设置正文
	//表头不算，索引从0开始
	mfc_listCtrl.InsertItem(0,TEXT("h1mmel"));
	mfc_listCtrl.InsertItem(1,TEXT("sky"));
	mfc_listCtrl.InsertItem(2, TEXT("himmel"));

	//添加其他列
	mfc_listCtrl.SetItemText(0,1,TEXT("17782036914"));
	mfc_listCtrl.SetItemText(0,2,TEXT("2286859221@qq.com"));

	mfc_listCtrl.SetItemText(1, 1, TEXT("17782036914"));
	mfc_listCtrl.SetItemText(1, 2, TEXT("xiaoxiaoxiaotian@gmail.com"));

	mfc_listCtrl.SetItemText(2, 1, TEXT("15320707057"));
	mfc_listCtrl.SetItemText(2, 2, TEXT("17782036914@163.com"));

	//设置属性 整行选中 网格
	mfc_listCtrl.SetExtendedStyle(mfc_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CContactTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CContactTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CContactTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CContactTestDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CContactTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CAdd cadd;
	cadd.DoModal();
}


void CContactTestDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Edit edit;
	edit.DoModal();
}


void CContactTestDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CContactTestDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CSearch csearch;
	csearch.DoModal();
}



void CContactTestDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (MessageBox(TEXT("确实要退出吗？"), TEXT("提示"), MB_OKCANCEL | MB_ICONWARNING) == IDOK)
	{
		CContactTestDlg::OnClose();
		CContactTestDlg::DestroyWindow();
		PostQuitMessage(0);
	}
}
