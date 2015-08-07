// VPBNClientUIDlg.h : ͷ�ļ�
//

#pragma once


// CDlgLogin �Ի���
class CDlgLogin : public CDialog
{
// ����
public:
	CDlgLogin(CWnd* pParent = NULL);	// ��׼���캯��
private:
	BOOL LoadDUIRes(void);
	
private:
	IDirectUI				*m_pDirectUI;
	IDUIStatic				*m_pPrompt;
	IDUIStatic				*m_pTextSysName;
	ICmdButton				*m_pBtnClose;
	ICmdButton				*m_pBtnMin;
	ICmdButton				*m_pBtnLogin;
	ICmdButton				*m_pBtnUserDown;
	ICmdButton				*m_pBtnUserUp;
	IUIFormObj				*m_pMain;
	IUIFormObj				*m_pUIUserName;
	IUIFormObj				*m_pUIFormUser;
	IUIFormObj				*m_pUIFormPwd; 
	IDUIHwndObj				*m_pEditUser;
	IDUIHwndObj				*m_pEditPwd;
	IDUICheckBox			*m_pCheckboxJZPwd;
	IDUICheckBox			*m_pCheckboxZDLogin; 
	IDUIListView			*m_pListView;
private:
	CEdit					m_editUser;
	CEdit					m_editPwd;
public:
// �Ի�������
	enum { IDD = IDD_VPBNCLIENTUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT OnSMLButtonUp(WPARAM wParam,LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
