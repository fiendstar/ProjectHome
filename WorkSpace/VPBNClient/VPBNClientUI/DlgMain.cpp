// DlgMain.cpp : 实现文件
//

#include "stdafx.h"
#include "VPBNClientUI.h"
#include "DlgMain.h"


// CDlgMain 对话框

IMPLEMENT_DYNAMIC(CDlgMain, CDialog)

CDlgMain::CDlgMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMain::IDD, pParent)
{
	m_pDirectUI				= NULL;
	m_pBtUserInfo			= NULL;
	m_pBtnClose				= NULL;
	m_pBtnMin				= NULL;
	m_pBtnMore				= NULL;					
	m_pBtnDocInfoSt			= NULL;
	m_pBtnEATaskSt			= NULL;
	m_pBtnDocInfoStPress	= NULL;
	m_pBtnEATaskStPress		= NULL;			
	m_pBtnUnEATask			= NULL;
	m_pBtnWaitOutTask		= NULL;
	m_pBtnWaitRecyTask		= NULL;			
	m_pBtnDonePutTask		= NULL;
	m_pBtnDoneEATask		= NULL;
	m_pBtnDoneOutTaskNum	= NULL;
	m_pBtnDoneRecyNum		= NULL;				
	m_pBtnQuery				= NULL;
	m_pBtnEATask			= NULL;
	m_pBtnHelp				= NULL;
	m_pBtnSet				= NULL;						
	m_pHwndObj				= NULL;
	m_pHwndGif				= NULL;
	m_pBtnWeek				= NULL;
	m_pBtnMonth				= NULL;
	m_pBtnSeason			= NULL;
	m_pBtnWeekPress			= NULL;
	m_pBtnMonthPress		= NULL;
	m_pBtnSeasonPress		= NULL;
	m_pTextWeek				= NULL;
	m_pTextMonth			= NULL;
	m_pTextSeason			= NULL;
	m_pTextWeekPress		= NULL;
	m_pTextMonthPress		= NULL;
	m_pTextSeasonPress		= NULL;
	m_pTextTime				= NULL;
	m_pStaticPrompt			= NULL;
	m_pStaticTop			= NULL;
	m_pTextSysName			= NULL;
	m_pTextSysName2			= NULL;
	m_pTextSysName3			= NULL;
	m_pTextSubmitTask		= NULL;
	m_pTextEATask			= NULL;
	m_pTextOutTask			= NULL;
	m_pTextRecyDoc			= NULL;
	m_pBtnUnEA				= NULL;
	m_pBtnRefuseEA			= NULL;
	m_pBtnPassEA			= NULL;
	m_pStaticUserInfo		= NULL;
	m_pStaticUserInfo2		= NULL;
	m_pStaticLoginTime		= NULL;
	m_pStaticUnEATask		= NULL;
	m_pStaticDisable		= NULL;
	m_pCombo				= NULL;
	m_pBtnAdminiUnEA		= NULL;
	m_pBtnCheckVersion		= NULL;
	m_pTextAdUnEATask		= NULL;
	m_pTextUnEATask			= NULL;
	m_pTextWaitOutTask		= NULL;
	m_pTextWaitRecyTask		= NULL; 
	m_pTextDonePutTask		= NULL;
	m_pTextDoneEATask		= NULL;
	m_pTextDoneOutTaskNum	= NULL;
	m_pTextDoneRecyNum		= NULL;
	m_pStcVersion			= NULL;
	m_pStcCheckUpdate		= NULL;
	m_pVRVStaticTitle		= NULL;
	m_pJCStaticTitle		= NULL;
	m_pJCStaticCenterTitle1	= NULL;
	m_pJCStaticCenterTitle2	= NULL;
	m_pJCStaticCenterTitle3	= NULL;
	m_pBtKLSumbit			= NULL;
	m_pBtnCirculate			= NULL;					
	m_pTextUnCirTaskTag		= NULL;
	m_pTextUnCirTaskValue	= NULL;
	m_pBtnUnCirTaskValue	= NULL;
	m_pTextCirTaskTag		= NULL;
	m_pTextCirTaskValue		= NULL;
	m_pBtnCirTaskValue		= NULL;

}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CDlgMain 消息处理程序

int CDlgMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
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

BOOL CDlgMain::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL CDlgMain::LoadDUIRes(void)
{
	BOOL bRet   = FALSE;

	if (NULL == theApp.m_pDUIRes)
	{
		goto __Exit;
	}

	m_pDirectUI			=   (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI("DirectUIMain",HandleToLong(this->GetSafeHwnd()));
	
	if (NULL == m_pDirectUI)
	{
		goto __Exit;
	}
	bRet = TRUE;
__Exit:
	return bRet;
}


