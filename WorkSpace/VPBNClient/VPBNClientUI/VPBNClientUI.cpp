// VPBNClientUI.cpp : ����Ӧ�ó��������Ϊ��
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


// CVPBNClientUIApp ����

CVPBNClientUIApp::CVPBNClientUIApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��

	m_pDUIRes = NULL;
}


// Ψһ��һ�� CVPBNClientUIApp ����

CVPBNClientUIApp theApp;


// CVPBNClientUIApp ��ʼ��

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

	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));



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
	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
__Exit:
	return FALSE;
}

int CVPBNClientUIApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
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


