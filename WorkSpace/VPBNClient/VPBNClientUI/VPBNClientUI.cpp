// VPBNClientUI.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "VPBNClientUI.h"
#include "DlgLogin.h"
#include "DlgMain.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVPBNClientUIApp

BEGIN_MESSAGE_MAP(CVPBNClientUIApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CVPBNClientUIApp 构造

CVPBNClientUIApp::CVPBNClientUIApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中

	m_pDUIRes = NULL;
}


// 唯一的一个 CVPBNClientUIApp 对象

CVPBNClientUIApp theApp;


// CVPBNClientUIApp 初始化

BOOL CVPBNClientUIApp::InitInstance()
{
	CDlgLogin				dlgLogin;
	CDlgMain				dlgMain;
	INT_PTR					nResponse = 0; 
	DWORD					dwTickCount = 0;
	INITCOMMONCONTROLSEX	InitCtrls;

	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));



	dwTickCount = GetTickCount();
	if (FALSE == OpenAppSkin())
	{
		goto __Exit;
	}


	
	nResponse = dlgLogin.DoModal();
	if (IDOK == nResponse)
	{
		m_pMainWnd = &dlgMain;
		dlgMain.DoModal();
	}
	else
	{

	}
	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
__Exit:
	return FALSE;
}

int CVPBNClientUIApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	FreeAppSkin();
	return CWinApp::ExitInstance();
}

BOOL CVPBNClientUIApp::OpenAppSkin(void)
{
	BOOL bRet = FALSE;

	m_pDUIRes = ::OpenSkin(_T("\\skin\\InOutTerminal.dui"),_T("\\skin\\InOutTerminal.skn"));

	bRet = (m_pDUIRes == NULL)?FALSE:TRUE;
__Exit:
	return bRet;
}

void CVPBNClientUIApp::FreeAppSkin(void)
{
	::FreeSkin();
}


