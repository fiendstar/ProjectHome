// VPBNClientLogic.h : VPBNClientLogic DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVPBNClientLogicApp
// �йش���ʵ�ֵ���Ϣ������� VPBNClientLogic.cpp
//

class CVPBNClientLogicApp : public CWinApp
{
public:
	CVPBNClientLogicApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
