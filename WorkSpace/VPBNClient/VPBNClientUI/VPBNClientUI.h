// VPBNClientUI.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVPBNClientUIApp:
// �йش����ʵ�֣������ VPBNClientUI.cpp
//

class CVPBNClientUIApp : public CWinApp
{
public:
	CVPBNClientUIApp();
public:
	BOOL OpenAppSkin(void);
	void FreeAppSkin(void);
public:

	IDUIRes*							m_pDUIRes;					//DUI����

public:
// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	
	virtual int ExitInstance();
};

extern CVPBNClientUIApp theApp;

#define DIRECTUI_GETCONTROL(objname) (IDUIControlBase*)theApp.m_pDUIRes->GetResObject(DUIOBJTYPE_PLUGIN,objname,m_pDirectUI,TRUE)