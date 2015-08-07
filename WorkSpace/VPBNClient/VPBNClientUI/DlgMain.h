#pragma once


// CDlgMain �Ի���

class CDlgMain : public CDialog
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	CDlgMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMain();
public:
	BOOL LoadDUIRes(void);



private:
	IDirectUI	*m_pDirectUI;
	ICmdButton	*m_pBtUserInfo;
	ICmdButton	*m_pBtnClose;
	ICmdButton	*m_pBtnMin;
	ICmdButton	*m_pBtnMore;					//ϵͳ��ť
	ICmdButton	*m_pBtnDocInfoSt;
	ICmdButton	*m_pBtnEATaskSt;
	ICmdButton	*m_pBtnDocInfoStPress;
	ICmdButton	*m_pBtnEATaskStPress;			//�ĵ���Ϣͳ�ƺ���������ͳ��
	ICmdButton	*m_pBtnUnEATask;
	ICmdButton	*m_pBtnWaitOutTask;
	ICmdButton	*m_pBtnWaitRecyTask;			//���������񡢴�������񡢴���������
	ICmdButton	*m_pBtnDonePutTask;
	ICmdButton	*m_pBtnDoneEATask;
	ICmdButton	*m_pBtnDoneOutTaskNum;
	ICmdButton	*m_pBtnDoneRecyNum;				//���ύ��������������������ܺ͡��ѻ��������ĵ�
	ICmdButton	*m_pBtnQuery;
	ICmdButton	*m_pBtnEATask;
	ICmdButton	*m_pBtnHelp;
	ICmdButton	*m_pBtnSet;						//��ѯ���������񡢰���������
	IDUIHwndObj	*m_pHwndObj;
	IDUIHwndObj	*m_pHwndGif;
	ICmdButton	*m_pBtnWeek;
	ICmdButton	*m_pBtnMonth;
	ICmdButton	*m_pBtnSeason;
	ICmdButton	*m_pBtnWeekPress;
	ICmdButton	*m_pBtnMonthPress;
	ICmdButton	*m_pBtnSeasonPress;
	ICmdButton	*m_pTextWeek;
	ICmdButton	*m_pTextMonth;
	ICmdButton	*m_pTextSeason;
	ICmdButton	*m_pTextWeekPress;
	ICmdButton	*m_pTextMonthPress;
	ICmdButton	*m_pTextSeasonPress;
	IDUIStatic  *m_pTextTime;
	IDUIStatic  *m_pStaticPrompt;
	IDUIStatic  *m_pStaticTop;
	IDUIStatic  *m_pTextSysName;
	IDUIStatic  *m_pTextSysName2;
	IDUIStatic  *m_pTextSysName3;
	ICmdButton  *m_pTextSubmitTask;
	ICmdButton  *m_pTextEATask;
	ICmdButton  *m_pTextOutTask;
	ICmdButton  *m_pTextRecyDoc;
	ICmdButton  *m_pBtnUnEA;
	ICmdButton  *m_pBtnRefuseEA;
	ICmdButton  *m_pBtnPassEA;
	IDUIStatic  *m_pStaticUserInfo;
	IDUIStatic  *m_pStaticUserInfo2;
	IDUIStatic  *m_pStaticLoginTime;
	IDUIStatic  *m_pStaticUnEATask;
	IDUIStatic  *m_pStaticDisable;
	IDUIComboBox *m_pCombo;
	ICmdButton   *m_pBtnAdminiUnEA;
	ICmdButton   *m_pBtnCheckVersion;
	IDUIStatic  *m_pTextAdUnEATask;
	IDUIStatic  *m_pTextUnEATask;
	IDUIStatic  *m_pTextWaitOutTask;
	IDUIStatic  *m_pTextWaitRecyTask; 
	IDUIStatic  *m_pTextDonePutTask;
	IDUIStatic  *m_pTextDoneEATask;
	IDUIStatic  *m_pTextDoneOutTaskNum;
	IDUIStatic  *m_pTextDoneRecyNum;
	IDUIStatic	*m_pStcVersion;
	IDUIStatic  *m_pStcCheckUpdate;
	IDUIStatic	*m_pVRVStaticTitle;
	IDUIStatic  *m_pJCStaticTitle;
	IDUIStatic	*m_pJCStaticCenterTitle1 ;
	IDUIStatic	*m_pJCStaticCenterTitle2 ;
	IDUIStatic	*m_pJCStaticCenterTitle3 ;
	ICmdButton	*m_pBtKLSumbit;
	ICmdButton	*m_pBtnCirculate;					//��ת
	IDUIStatic	*m_pTextUnCirTaskTag;
	IDUIStatic	*m_pTextUnCirTaskValue;
	ICmdButton	*m_pBtnUnCirTaskValue;
	IDUIStatic	*m_pTextCirTaskTag;
	IDUIStatic	*m_pTextCirTaskValue;
	ICmdButton	*m_pBtnCirTaskValue;

	CRect        m_rect;
public:
// �Ի�������
	enum { IDD = IDD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
};
