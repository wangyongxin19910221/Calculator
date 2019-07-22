
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, Result(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, Result);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCApplication1Dlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCApplication1Dlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCApplication1Dlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON29, &CMFCApplication1Dlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CMFCApplication1Dlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CMFCApplication1Dlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON35, &CMFCApplication1Dlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON36, &CMFCApplication1Dlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CMFCApplication1Dlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON41, &CMFCApplication1Dlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON42, &CMFCApplication1Dlg::OnBnClickedButton42)
	ON_BN_CLICKED(IDC_BUTTON26, &CMFCApplication1Dlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON32, &CMFCApplication1Dlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON38, &CMFCApplication1Dlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON44, &CMFCApplication1Dlg::OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON45, &CMFCApplication1Dlg::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON47, &CMFCApplication1Dlg::OnBnClickedButton47)
	ON_BN_CLICKED(IDC_BUTTON49, &CMFCApplication1Dlg::OnBnClickedButton49)
	ON_BN_CLICKED(IDC_BUTTON43, &CMFCApplication1Dlg::OnBnClickedButton43)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnBnClickedButton23()
{
	UpdateData(TRUE);
	Result += "7";
	UpdateData(FALSE);
}

void CMFCApplication1Dlg::OnBnClickedButton24()
{
	UpdateData(TRUE);
	Result += "8";
	UpdateData(FALSE);
}

void CMFCApplication1Dlg::OnBnClickedButton25()
{
	UpdateData(TRUE);
	Result += "9";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton29()
{
	UpdateData(TRUE);
	Result += "4";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton30()
{
	UpdateData(TRUE);
	Result += "5";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton31()
{
	UpdateData(TRUE);
	Result += "6";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton35()
{
	UpdateData(TRUE);
	Result += "1";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton36()
{
	UpdateData(TRUE);
	Result += "2";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton37()
{
	UpdateData(TRUE);
	Result += "3";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton41()
{
	UpdateData(TRUE);
	Result += "0";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton42()
{
	UpdateData(TRUE);
	Result += ".";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton26()
{
	UpdateData(TRUE);
	Result += "+";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton32()
{
	UpdateData(TRUE);
	Result += "-";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton38()
{
	UpdateData(TRUE);
	Result += "*";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton44()
{
	UpdateData(TRUE);
	Result += "÷";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton45()
{
	UpdateData(TRUE);
	Result += "/";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton47()
{
	UpdateData(TRUE);
	Result += "（";
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButton49()
{
	UpdateData(TRUE);
	Result += "）";
	UpdateData(FALSE);
}

//等号计算
void CMFCApplication1Dlg::OnBnClickedButton43()
{

	/**CString string;

	//sprintf(string,"%d",Result.GetLength());
	string.Format(_T("%d"), Result.GetLength());
	//消息框
	MessageBox(string);**/
	// 等号

	UpdateData(TRUE);
	int i, j, a[50];
	MessageBox(Result);

	
}
