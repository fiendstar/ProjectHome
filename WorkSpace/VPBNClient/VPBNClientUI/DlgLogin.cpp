// VPBNClientUIDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VPBNClientUI.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDlgLogin 对话框




CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_USER, m_editUser);
	DDX_Control(pDX, IDC_EDIT_PWD, m_editPwd);
}

BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(DUISM_LBUTTONUP,	OnSMLButtonUp)
	//}}AFX_MSG_MAP
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CDlgLogin 消息处理程序
int CDlgLogin::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	int nRet = -1;
	if (CDialog::OnCreate(lpCreateStruct) == -1)
	{
		goto __Exit;
	}


	if (FALSE == LoadDUIRes())
	{
		goto __Exit;
	}

	nRet = 0;
__Exit:
	return nRet;
}

BOOL CDlgLogin::OnInitDialog()
{
	CDialog::OnInitDialog();
	BOOL bRes = FALSE;
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	CRect Rect;
	CRgn  Rgn;
	GetWindowRect(&Rect);	
	Rect -= Rect.TopLeft();	
	Rgn.CreateRoundRectRgn(Rect.left+2,
						   Rect.top+2,
						   Rect.right,
						   Rect.bottom,
						   4, 
						   4);
	SetWindowRgn( Rgn, TRUE );

	//SkinRect sRectLogin;       //关闭按钮区域
	//CRgn rgnLogin;              //登录主界面区域

	//if (NULL != m_pBtnLogin)
	//{
	//	sRectLogin = m_pBtnLogin->GetRect()->GetRectStruct();
	//	rgnLogin.CreateRoundRectRgn(sRectLogin.left,
	//		sRectLogin.top,
	//		sRectLogin.right,
	//		sRectLogin.bottom,
	//		10, 
	//		10);
	//	SetWindowRgn( Rgn, TRUE );
	//}



	bRes =FALSE;
	bRes = m_pEditUser->Attach((OLE_HANDLE)HandleToLong(m_editUser.GetSafeHwnd()));
	bRes =FALSE;
	bRes = m_pEditPwd->Attach((OLE_HANDLE)HandleToLong(m_editPwd.GetSafeHwnd()));


	if (NULL != m_pPrompt)
	{
		m_pPrompt->SetText("用户名或密码错误");
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDlgLogin::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		//CAboutDlg dlgAbout;
		//dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDlgLogin::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDlgLogin::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CDlgLogin::OnSMLButtonUp(WPARAM wParam,LPARAM lParam)
{
	IDUIControlBase *pControlBase   = NULL;

	pControlBase = (IDUIControlBase*)wParam;

	if (NULL == pControlBase)
	{
		goto __Exit;
	}
	if (pControlBase == (IDUIControlBase*)m_pBtnClose)
	{
		CDialog::OnCancel();
	}
	else if(pControlBase == (IDUIControlBase*)m_pBtnMin)
	{
		ShowWindow(SW_MINIMIZE);
	}
	else if (pControlBase == (IDUIControlBase*)m_pBtnLogin)
	{
		CDialog::OnOK();
	}

__Exit:
	return 0;
}

BOOL CDlgLogin::LoadDUIRes(void)
{
	BOOL bRet   = FALSE;

	if (NULL == theApp.m_pDUIRes)
	{
		goto __Exit;
	}

	m_pDirectUI			=   (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI("DirectUILogin",HandleToLong(this->GetSafeHwnd()));

	m_pPrompt			=	(IDUIStatic*)DIRECTUI_GETCONTROL("PromptText");

	m_pBtnClose			=	(ICmdButton*)DIRECTUI_GETCONTROL("BtnClose");
	m_pBtnMin			=	(ICmdButton*)DIRECTUI_GETCONTROL("BtnMin");
	
	m_pBtnLogin			=	(ICmdButton*)DIRECTUI_GETCONTROL("BTLogin");
	m_pBtnUserDown		=	(ICmdButton*)DIRECTUI_GETCONTROL("BtnUserDown");
	m_pBtnUserUp		=	(ICmdButton*)DIRECTUI_GETCONTROL("BtnUserUp");

	m_pEditUser			=	(IDUIHwndObj*)DIRECTUI_GETCONTROL("HwndEditUser");
	m_pEditPwd			=	(IDUIHwndObj*)DIRECTUI_GETCONTROL("HwndEditPWD");

	m_pMain				=	(IUIFormObj*)DIRECTUI_GETCONTROL("main");
	m_pUIFormUser		=	(IUIFormObj*)DIRECTUI_GETCONTROL("UIFormUser");
	m_pUIFormPwd		=	(IUIFormObj*)DIRECTUI_GETCONTROL("UIFormPWD");
	m_pUIUserName		=	(IUIFormObj*)DIRECTUI_GETCONTROL("UIFormUserInfo");

	m_pListView			=	(IDUIListView*)DIRECTUI_GETCONTROL("ListViewUser");
	m_pCheckboxJZPwd	=	(IDUICheckBox*)DIRECTUI_GETCONTROL("CheckBox1");
	m_pCheckboxZDLogin	=	(IDUICheckBox*)DIRECTUI_GETCONTROL("CheckBox2");

	if(NULL==m_pDirectUI||
	    NULL==m_pBtnClose||
		NULL==m_pBtnMin||
		NULL==m_pBtnLogin||
		NULL==m_pMain||
		NULL==m_pEditUser||
		NULL==m_pEditPwd||
		NULL==m_pPrompt||
		NULL==m_pListView||
		NULL==m_pUIFormUser||
		NULL==m_pUIFormPwd||
		NULL==m_pTextSysName||
		NULL==m_pBtnUserDown||
		NULL==m_pUIUserName||
		NULL==m_pCheckboxJZPwd||
		NULL==m_pCheckboxZDLogin||
		NULL==m_pBtnUserDown||
		NULL==m_pBtnUserUp)
	{
		goto __Exit;
	}

	bRet = TRUE;
__Exit:
	return bRet;
}


