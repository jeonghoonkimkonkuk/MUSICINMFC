#pragma once


// InitDialog 대화 상자

class InitDialog : public CDialog
{
	DECLARE_DYNAMIC(InitDialog)

public:
	InitDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~InitDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	CComboBox m_style;
	int style;
	CComboBox m_time;
	int	time;
	CComboBox m_signature;
	int signature;
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	CString sheetname;
	CString composer;
};
