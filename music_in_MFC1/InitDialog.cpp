// InitDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "music_in_MFC1.h"
#include "InitDialog.h"
#include "afxdialogex.h"


// InitDialog 대화 상자

IMPLEMENT_DYNAMIC(InitDialog, CDialog)

InitDialog::InitDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)

	, sheetname(_T(""))
	, composer(_T(""))
{

}

InitDialog::~InitDialog()
{
}

void InitDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_STLYE, m_style);
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Control(pDX, IDC_SIGNATURE, m_signature);
	DDX_Text(pDX, IDC_SHEETNAME, sheetname);
	DDX_Text(pDX, IDC_COMPOSER, composer);
}


BEGIN_MESSAGE_MAP(InitDialog, CDialog)
END_MESSAGE_MAP()


// InitDialog 메시지 처리기


void InitDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	style = m_style.GetCurSel()+1;
	time = m_time.GetCurSel();
	signature = m_signature.GetCurSel();


	CDialog::OnOK();
}


BOOL InitDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_style.SetCurSel(0);
	m_time.SetCurSel(2);
	m_signature.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
