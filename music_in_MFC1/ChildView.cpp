
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "music_in_MFC1.h"
#include "ChildView.h"
#include "InitDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView()
	: toolbox_id(n_zero), point(false), elforshow(nullptr), noteforshow(false), Check_Size(false), Sheet_Size(1), m_intense(100)
{
	InitDialog dlg;
	if (IDOK == dlg.DoModal()) {
		m_sheet = new Sheet(dlg.style,dlg.time+b_24,dlg.signature);
		m_sheet->Sheet_name = dlg.sheetname;
		m_sheet->composer = dlg.composer;
		page = 1;
	}
	else {
		m_sheet = new Sheet(1,b_24,0);
		page = 1;
	}
	splitforshow.SetPoint(-100, -100);
}

CChildView::~CChildView()
{
	delete m_sheet;
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SCORE_SMALL, &CChildView::OnScoreSmall)
	ON_COMMAND(ID_high, &CChildView::Onhigh)
	ON_COMMAND(ID_low, &CChildView::Onlow)
	ON_UPDATE_COMMAND_UI(ID_high, &CChildView::OnUpdatehigh)
	ON_UPDATE_COMMAND_UI(ID_low, &CChildView::OnUpdatelow)
	ON_COMMAND(ID_N_0, &CChildView::OnN0)
	ON_COMMAND(ID_n_2, &CChildView::Onn2)
	ON_COMMAND(ID_N_4, &CChildView::OnN4)
	ON_COMMAND(ID_N_8, &CChildView::OnN8)
	ON_COMMAND(ID_N_16, &CChildView::OnN16)
	ON_COMMAND(ID_R_0, &CChildView::OnR0)
	ON_COMMAND(ID_R_2, &CChildView::OnR2)
	ON_COMMAND(ID_R_4, &CChildView::OnR4)
	ON_COMMAND(ID_R_8, &CChildView::OnR8)
	ON_UPDATE_COMMAND_UI(ID_N_0, &CChildView::OnUpdateN0)
	ON_UPDATE_COMMAND_UI(ID_n_2, &CChildView::OnUpdaten2)
	ON_UPDATE_COMMAND_UI(ID_N_4, &CChildView::OnUpdateN4)
	ON_UPDATE_COMMAND_UI(ID_N_8, &CChildView::OnUpdateN8)
	ON_UPDATE_COMMAND_UI(ID_N_16, &CChildView::OnUpdateN16)
	ON_UPDATE_COMMAND_UI(ID_R_0, &CChildView::OnUpdateR0)
	ON_UPDATE_COMMAND_UI(ID_R_2, &CChildView::OnUpdateR2)
	ON_UPDATE_COMMAND_UI(ID_R_4, &CChildView::OnUpdateR4)
	ON_UPDATE_COMMAND_UI(ID_R_8, &CChildView::OnUpdateR8)
	ON_COMMAND(ID_start, &CChildView::Onstart)
	ON_COMMAND(ID_end, &CChildView::Onend)
	ON_UPDATE_COMMAND_UI(ID_start, &CChildView::OnUpdatestart)
	ON_UPDATE_COMMAND_UI(ID_end, &CChildView::OnUpdateend)
	ON_COMMAND(ID_f, &CChildView::Onf)
	ON_COMMAND(ID_mp, &CChildView::Onmp)
	ON_COMMAND(ID_fff, &CChildView::Onfff)
	ON_COMMAND(ID_mf, &CChildView::Onmf)
	ON_COMMAND(ID_ff, &CChildView::Onff)
	ON_UPDATE_COMMAND_UI(ID_f, &CChildView::OnUpdatef)
	ON_UPDATE_COMMAND_UI(ID_ff, &CChildView::OnUpdateff)
	ON_UPDATE_COMMAND_UI(ID_fff, &CChildView::OnUpdatefff)
	ON_UPDATE_COMMAND_UI(ID_mf, &CChildView::OnUpdatemf)
	ON_UPDATE_COMMAND_UI(ID_mp, &CChildView::OnUpdatemp)
	ON_COMMAND(ID_s_s, &CChildView::Onss)
	ON_UPDATE_COMMAND_UI(ID_s_s, &CChildView::OnUpdatess)
	ON_COMMAND(ID_s_b, &CChildView::Onsb)
	ON_UPDATE_COMMAND_UI(ID_s_b, &CChildView::OnUpdatesb)
	ON_UPDATE_COMMAND_UI(ID_s_n, &CChildView::OnUpdatesn)
	ON_COMMAND(ID_s_n, &CChildView::Onsn)
	ON_COMMAND(ID_P, &CChildView::OnP)
	ON_UPDATE_COMMAND_UI(ID_P, &CChildView::OnUpdateP)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_d_p, &CChildView::Ondp)
	ON_UPDATE_COMMAND_UI(ID_d_p, &CChildView::OnUpdatedp)
	ON_COMMAND(ID_pp, &CChildView::Onpp)
	ON_UPDATE_COMMAND_UI(ID_pp, &CChildView::OnUpdatepp)
	ON_UPDATE_COMMAND_UI(ID_ppp, &CChildView::OnUpdateppp)
	ON_COMMAND(ID_ppp, &CChildView::Onppp)
	ON_COMMAND(ID_24, &CChildView::On24)
	ON_UPDATE_COMMAND_UI(ID_24, &CChildView::OnUpdate24)
	ON_COMMAND(ID_34, &CChildView::On34)
	ON_UPDATE_COMMAND_UI(ID_34, &CChildView::OnUpdate34)
	ON_UPDATE_COMMAND_UI(ID_44, &CChildView::OnUpdate44)
	ON_COMMAND(ID_44, &CChildView::On44)
	ON_COMMAND(ID_54, &CChildView::On54)
	ON_UPDATE_COMMAND_UI(ID_54, &CChildView::OnUpdate54)
	ON_COMMAND(ID_64, &CChildView::On64)
	ON_UPDATE_COMMAND_UI(ID_64, &CChildView::OnUpdate64)
	ON_COMMAND(ID_38, &CChildView::On38)
	ON_UPDATE_COMMAND_UI(ID_38, &CChildView::OnUpdate38)
	ON_COMMAND(ID_68, &CChildView::On68)
	ON_UPDATE_COMMAND_UI(ID_68, &CChildView::OnUpdate68)
	ON_COMMAND(ID_98, &CChildView::On98)
	ON_UPDATE_COMMAND_UI(ID_98, &CChildView::OnUpdate98)
	ON_COMMAND(ID_128, &CChildView::On128)
	ON_UPDATE_COMMAND_UI(ID_128, &CChildView::OnUpdate128)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_COMMAND(ID_SPLIT, &CChildView::OnSplit)
	ON_UPDATE_COMMAND_UI(ID_SPLIT, &CChildView::OnUpdateSplit)
	ON_COMMAND(ID_UNSPLIT, &CChildView::OnUnsplit)
	ON_UPDATE_COMMAND_UI(ID_UNSPLIT, &CChildView::OnUpdateUnsplit)
	ON_COMMAND(ID_MAX, &CChildView::OnMax)
	ON_UPDATE_COMMAND_UI(ID_MAX, &CChildView::OnUpdateMax)
	ON_COMMAND(ID_MIN, &CChildView::OnMin)
	ON_UPDATE_COMMAND_UI(ID_MIN, &CChildView::OnUpdateMin)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_COMMAND(ID_play, &CChildView::Onplay)
	ON_COMMAND(ID_pause, &CChildView::Onpause)
	ON_COMMAND(ID_BACK, &CChildView::OnBack)
	ON_COMMAND(ID_FRONT, &CChildView::OnFront)
	ON_COMMAND(ID_NEW, &CChildView::OnNew)
	ON_COMMAND(ID_BMP, &CChildView::OnBmp)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	CRect rect;
	int h_pos = GetScrollPos(SB_VERT);
	int v_pos = GetScrollPos(SB_HORZ);
	GetClientRect(rect);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	CDC mem_dc;
	CBitmap mem_bmp;
	mem_dc.CreateCompatibleDC(&dc);
	mem_bmp.LoadBitmapW(IDB_A4);
	mem_dc.SelectObject(&mem_bmp);

	m_sheet->paint(mem_dc);

	//mem_dc.TransparentBlt(100, 50, bmpinfo1.bmWidth, bmpinfo1.bmHeight, &dc1,
	//	0, 0, bmpinfo1.bmWidth, bmpinfo1.bmHeight, RGB(255, 0, 255));  // fff 그리기

	//SaveBMP(&mem_dc, CRect(0,0,1240,m_sheet->used_space), 24, _T("score.bmp"));
	if (!Check_Size)	
		dc.StretchBlt(0, 0, 1240, 1754, &mem_dc, v_pos, h_pos, 1240 / Sheet_Size, 1754 / Sheet_Size, SRCCOPY);
	else
		dc.StretchBlt(rect.Width() / 6, 0, 1240, 1754, &mem_dc, v_pos, h_pos, 1240 / Sheet_Size, 1754 / Sheet_Size, SRCCOPY);





	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}




void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 왼쪽 클릭함수를 완성하면 예시보여주는 함수에서는 왼쪽클릭에 대한 내용들을 거진 
	// 배껴서 사용할수 있어서 이거 먼저만들면 그부분에 대한건 나름 쉽게 끝날듯
	int h_pos = GetScrollPos(SB_VERT);
	int v_pos = GetScrollPos(SB_HORZ);

	CRect rect;
	GetClientRect(rect);
	if (Check_Size) {
		point.x -= rect.Width() / 6;
	}
	point.x /= Sheet_Size;
	point.x += v_pos;
	point.y /= Sheet_Size;
	point.y += h_pos;

	if (toolbox_id >= shap && toolbox_id <= natural) {
		element* t_node = m_sheet->getElement(point);
		if (t_node != nullptr) {
			note* t_note = t_node->getnote(point);
			if (t_note != nullptr) {
				t_note->condition_mark = toolbox_id;
			}
		}
	}

	if (toolbox_id == split) {
		m_sheet->getNode(splitforshow)->forshow = false;
	}
	if (toolbox_id == unsplit) {

		m_sheet->unsplit(point);
	}



	if (toolbox_id != 0) {
		// 0이라는건 임시값 id로 쓰여지지않는 어떤 숫자가 오면됨
		// 단순히 id로 쓰여지지않는거라기보다는 툴박스에서 안쓰는 아이디면 될 듯??

		if (elforshow != nullptr) {
			bool found = false;
			if (elforshow->id >= b_24 && elforshow->id <= b_128) {
				node *n = m_sheet->getNode(point);
				element *e = n->first_element;

				while (e != nullptr) {
					if (e->id >= b_24 && e->id <= b_128 && e->forshow == false) {
						found = true;
						break;
					}
					e = e->back_element;
				}
			}
			if (!found) {
				elforshow->notforshow();
				elforshow = nullptr;
				m_sheet->updateTime();
			}
			else {
				AfxMessageBox(_T("하나의 마디에 두 개 이상의 박자표가 올 수 없습니다.!!"));
			}
		}

		if (noteforshow != nullptr) {
			noteforshow->notforshow();
			noteforshow = nullptr;
		}

		//switch (toolbox_id) {
		//case n_zero:
		//   element* temp = new element(point, n_zero,false);
		//   m_sheet->addElement(point, temp);
		//}
		// 음표가 선택된상태에서 마디의 빈공간을 클릭 -> 그냥 음표추가
		// 음표가 선택된 상태에서 음표를 클릭 -> 화음으로 추가 -> 음표의 위아래 영역은 크게잡야아할듯
		// 음표의 상태를 정하는 요소들은 음표만을 클릭 가능
		// 그 외의 요소들(음자리표)은 악보에서 사용되는 위치를 참고하여 그냥 마디자체에 정보를 입히는
		// 느낌으로 함수를 짜면될듯
	}
	else {
		//selected_element = m_sheet->getElement(point, selected_id);
		// 툴박스를 사용중이지 않는 경우에는 요소를 선택하기
	}


	Invalidate(false);

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnScoreSmall()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
	m_sheet->new_node();
	add_VScroll();
}

//음자리표
void CChildView::Onhigh()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = high;
}


void CChildView::Onlow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = low;
}


void CChildView::OnUpdatehigh(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == high);
}


void CChildView::OnUpdatelow(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == low);
}

//음표
void CChildView::OnN0()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = n_zero;
	else
		toolbox_id = p_n_zero;
}


void CChildView::Onn2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = n_two;
	else
		toolbox_id = p_n_two;
}


void CChildView::OnN4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = n_four;
	else
		toolbox_id = p_n_four;
}


void CChildView::OnN8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = n_eight;
	else
		toolbox_id = p_n_eight;
}


void CChildView::OnN16()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = n_sixteen;
	else
		toolbox_id = p_n_sixteen;
}

void CChildView::OnUpdateN0(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == n_zero || toolbox_id == p_n_zero);
}


void CChildView::OnUpdaten2(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == n_two || toolbox_id == p_n_two);
}


void CChildView::OnUpdateN4(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == n_four || toolbox_id == p_n_four);
}


void CChildView::OnUpdateN8(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == n_eight || toolbox_id == p_n_eight);
}


void CChildView::OnUpdateN16(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == n_sixteen || toolbox_id == p_n_sixteen);
}


//쉼표
void CChildView::OnR0()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = r_zero;
	else
		toolbox_id = p_r_zero;
}


void CChildView::OnR2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = r_two;
	else
		toolbox_id = p_r_two;
}


void CChildView::OnR4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = r_four;
	else
		toolbox_id = p_r_four;
}


void CChildView::OnR8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!point)
		toolbox_id = r_eight;
	else
		toolbox_id = p_r_eight;
}

void CChildView::OnUpdateR0(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == r_zero || toolbox_id == p_r_zero);
}


void CChildView::OnUpdateR2(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == r_two || toolbox_id == p_r_two);
}


void CChildView::OnUpdateR4(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == r_four || toolbox_id == p_r_four);
}


void CChildView::OnUpdateR8(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == r_eight || toolbox_id == p_r_eight);
}

//도돌이 표
void CChildView::Onstart()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = R_start;
}


void CChildView::Onend()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = R_end;
}


void CChildView::OnUpdatestart(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == R_start);
}


void CChildView::OnUpdateend(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == R_end);
}


//셈여림표
void CChildView::Onf()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = f;
}


void CChildView::Onmp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = mp;
}


void CChildView::Onfff()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = fff;
}

void CChildView::OnUpdatefff(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == fff);
}


void CChildView::Onmf()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = mf;
}


void CChildView::Onff()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = ff;
}


void CChildView::OnUpdatef(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == f);
}


void CChildView::OnUpdateff(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == ff);
}

void CChildView::OnUpdatemf(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == mf);
}


void CChildView::OnUpdatemp(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == mp);
}


void CChildView::Onss()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = shap;
}


void CChildView::OnUpdatess(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == shap);
}


void CChildView::Onsb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = flat;
}


void CChildView::OnUpdatesb(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == flat);
}


void CChildView::OnUpdatesn(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == natural);
}


void CChildView::Onsn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = natural;
}


void CChildView::OnP()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (point) {
		//체크 되었을 때 적용되는 일
		point = false;
		switch (toolbox_id) {
		case p_n_zero:
			toolbox_id = n_zero;
			break;
		case p_n_two:
			toolbox_id = n_two;
			break;
		case p_n_four:
			toolbox_id = n_four;
			break;
		case p_n_eight:
			toolbox_id = n_four;
			break;
		case p_n_sixteen:
			toolbox_id = n_sixteen;
			break;
		case p_r_zero:
			toolbox_id = r_zero;
			break;
		case p_r_two:
			toolbox_id = r_two;
			break;
		case p_r_four:
			toolbox_id = r_four;
			break;
		case p_r_eight:
			toolbox_id = r_four;
			break;
		}
	}
	else {
		point = true;
		switch (toolbox_id) {
		case n_zero:
			toolbox_id = p_n_zero;
			break;
		case n_two:
			toolbox_id = p_n_two;
			break;
		case n_four:
			toolbox_id = p_n_four;
			break;
		case n_eight:
			toolbox_id = p_n_eight;
			break;
		case n_sixteen:
			toolbox_id = p_n_sixteen;
			break;
		case r_zero:
			toolbox_id = p_r_zero;
			break;
		case r_two:
			toolbox_id = p_r_two;
			break;
		case r_four:
			toolbox_id = p_r_four;
			break;
		case r_eight:
			toolbox_id = p_r_eight;
			break;
		}
	}
}


void CChildView::OnUpdateP(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(point == true);
}


void CChildView::Ondp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = p;
}


void CChildView::OnUpdatedp(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == p);
}


void CChildView::Onpp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = pp;
}


void CChildView::OnUpdatepp(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == pp);
}


void CChildView::OnUpdateppp(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == ppp);
}


void CChildView::Onppp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = ppp;
}


void CChildView::On24()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_24;
}


void CChildView::OnUpdate24(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_24);
}


void CChildView::On34()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_34;
}


void CChildView::OnUpdate34(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_34);
}


void CChildView::OnUpdate44(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_44);
}


void CChildView::On44()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_44;
}


void CChildView::On54()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_54;
}


void CChildView::OnUpdate54(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_54);
}


void CChildView::On64()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_64;
}


void CChildView::OnUpdate64(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_64);
}


void CChildView::On38()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_38;
}


void CChildView::OnUpdate38(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_38);
}


void CChildView::On68()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_68;
}


void CChildView::OnUpdate68(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_68);
}


void CChildView::On98()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_98;
}


void CChildView::OnUpdate98(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_98);
}


void CChildView::On128()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	toolbox_id = b_128;
}


void CChildView::OnUpdate128(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(toolbox_id == b_128);
}





void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	int h_pos = GetScrollPos(SB_VERT);
	int v_pos = GetScrollPos(SB_HORZ);

	CRect rect;
	GetClientRect(rect);
	if (Check_Size) {
		point.x -= rect.Width() / 6;
	}
	point.x /= Sheet_Size;
	point.x += v_pos;
	point.y /= Sheet_Size;
	point.y += h_pos;

	element *e = m_sheet->getElement(point);
	if (e != nullptr && !e->forshow && m_sheet->deleteElement(point)) {
		//AfxMessageBox(_T("지움"));
		Invalidate(false);
	}

	node *n = m_sheet->getNode(point);
	if (n != nullptr && !n->forshow && m_sheet->unsplit(point)) {
		Invalidate(false);
	}


	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (toolbox_id == onplay) {
		CWnd::OnMouseMove(nFlags, point);
	}
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int h_pos = GetScrollPos(SB_VERT);
	int v_pos = GetScrollPos(SB_HORZ);

	CRect rect;
	GetClientRect(rect);
	if (Check_Size) {
		point.x -= rect.Width() / 6;
	}
	point.x /= Sheet_Size;
	point.x += v_pos;
	point.y /= Sheet_Size;
	point.y += h_pos;

	if (toolbox_id == split) {
		node *s = m_sheet->getNode(splitforshow);
		if (s != nullptr && s->forshow == true) {
			m_sheet->unsplit(splitforshow);

		}
		node *n = m_sheet->getNode(point);

		if (n != nullptr && n->s_rect->PtInRect(point) == false && m_sheet->getElement(point) == nullptr) {

			m_sheet->split(point, true);
			splitforshow = point;
		}

		Invalidate(false);
	}




	if (toolbox_id > split && toolbox_id != shap && toolbox_id != flat && toolbox_id != natural) {

		if (elforshow != nullptr) {
			element* e = m_sheet->getElement(elforshow->location);
			if (e) {
				if (e->forshow == true) {
					m_sheet->deleteElement(e->location);
				}
			}
		}

		if (noteforshow != nullptr) {
			note* n = noteforshow->first_note;
			while (n->next) {
				n = n->next;
			}
			if (n->forshow == true) {
				noteforshow->deleteNote();
			}
		}

		elforshow = nullptr;
		noteforshow = nullptr;

		element* f1 = m_sheet->getElement(point);
		node *s = m_sheet->getNode(point);
		if (s != nullptr && (s->s_rect == nullptr || !(s->s_rect->PtInRect(point)))) {
			if (f1==nullptr) {
				// TODO: 여기에 명령어를 입력합니다.

				element* e;
				switch (toolbox_id) {
				case n_zero:
				case n_two:
				case n_four:
				case n_eight:
				case n_sixteen:
				case p_n_zero:
				case p_n_two:
				case p_n_four:
				case p_n_eight:
				case p_n_sixteen:
				case r_zero:
				case r_two:
				case r_four:
				case r_eight:
				case p_r_zero:
				case p_r_two:
				case p_r_four:
				case p_r_eight:
				case high:
				case low:
				case b_128:
				case b_24:
				case b_34:
				case b_38:
				case b_44:
				case b_54:
				case b_64:
				case b_68:
				case b_98:
				case f:
				case ff:
				case fff:
				case mf:
				case mp:
				case p:
				case pp:
				case ppp:
					e = new element(point, toolbox_id, true);
					m_sheet->addElement(point, e);
					Invalidate(false);
					break;
				}
				elforshow = e;
			}
			else {
				switch (toolbox_id) {
				case n_zero:
				case n_two:
				case n_four:
				case n_eight:
				case n_sixteen:
				case p_n_zero:
				case p_n_two:
				case p_n_four:
				case p_n_eight:
				case p_n_sixteen:
				case r_zero:
				case r_two:
				case r_four:
				case r_eight:
				case p_r_zero:
				case p_r_two:
				case p_r_four:
				case p_r_eight:
					if (f1->id == n_note || f1->id == r_rest) {
						if (f1->addNote(point.y, toolbox_id, true)) {
							Invalidate(false);
							noteforshow = f1;
							break;
						}
					}
				//case f:
				//case ff:
				//case fff:
				//case mf:
				//case mp:
				//case p:
				//case pp:
				//case ppp:
				//	if (f1->id == n_note || f1->id == r_rest) {
				//		element* e = new element(point, toolbox_id, true);
				//		m_sheet->addElement(point, e);
				//		Invalidate(false);
				//		elforshow = e;
				//		break;
				//	}
				}
			}
		}
		Invalidate(false);
	}


	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.




	return 0;
}


void CChildView::OnSplit()
{
	toolbox_id = split;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateSplit(CCmdUI *pCmdUI)
{
		pCmdUI->SetCheck(toolbox_id == split);
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnUnsplit()
{
	toolbox_id = unsplit;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnUpdateUnsplit(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(toolbox_id == unsplit);
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}


void CChildView::OnMax()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Sheet_Size++;
	add_VScroll();
	add_HScroll();
	Invalidate(false);
}


void CChildView::OnMin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Sheet_Size--;
	add_VScroll();
	add_HScroll();
	Invalidate(false);
}


void CChildView::OnUpdateMax(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(Sheet_Size < 2);
}


void CChildView::OnUpdateMin(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(Sheet_Size > 1);
}


int CChildView::add_VScroll()
{
	// TODO: 여기에 구현 코드 추가.
	int iHeight = m_sheet->used_space;
	iHeight *= Sheet_Size;
	SCROLLINFO sl;
	CRect rt;
	GetClientRect(&rt);
	sl.cbSize = sizeof(sl);
	sl.fMask = SIF_ALL;
	//세로
	if (rt.Height() < iHeight) {
		sl.nMin = 0;
		sl.nMax = iHeight;

		sl.nPage = rt.Height();
		sl.nPos = GetScrollPos(SB_VERT);

		SetScrollInfo(SB_VERT, &sl, TRUE);
		ShowScrollBar(SB_VERT, TRUE);
	}
	else {
		ShowScrollBar(SB_VERT, FALSE);
	}
	Invalidate(false);
	return 0;
}


void CChildView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int delta = 0;
	if (pScrollBar == NULL)
	{
		switch (nSBCode) {
		case SB_LINEUP:
			delta = -4;
			break;
		case SB_LINEDOWN:
			delta = 4;
			break;
		case SB_PAGEUP:
			delta = -20;
			break;
		case SB_PAGEDOWN:
			delta = 20;
			break;
		case SB_THUMBPOSITION:
			break;
		case SB_THUMBTRACK:
			SetScrollPos(SB_VERT, nPos);
			break;
		case SB_ENDSCROLL:
			return;
			break;
		};
	}
	if (delta != 0) {
		int pos = GetScrollPos(SB_VERT);
		SetScrollPos(SB_VERT, pos + delta);
	}
	Invalidate(false);
	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CChildView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int delta = 0;
	if (pScrollBar == NULL)
	{
		switch (nSBCode) {
		case SB_LINELEFT:
			delta = -4;
			break;
		case SB_LINERIGHT:
			delta = 4;
			break;
		case SB_PAGELEFT:
			delta = -20;
			break;
		case SB_PAGERIGHT:
			delta = 20;
			break;
		case SB_THUMBPOSITION:
			break;
		case SB_THUMBTRACK:
			SetScrollPos(SB_HORZ, nPos);
			break;
		case SB_ENDSCROLL:
			return;
			break;
		};
	}
	if (delta != 0) {
		int pos = GetScrollPos(SB_HORZ);
		SetScrollPos(SB_HORZ, pos + delta);
	}
	Invalidate(false);
	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}


int CChildView::add_HScroll()
{
	// TODO: 여기에 구현 코드 추가.
	int m_nSize = 1240;
	int DISPLAY_WIDTH = m_nSize / Sheet_Size;
	int nScrollBarSize = m_nSize - DISPLAY_WIDTH + m_nSize / 10; //스크롤바의 크기 때문에 이렇게 조금 빼줘야 한다.
	nScrollBarSize = nScrollBarSize > 0 ? nScrollBarSize : 0;

	SCROLLINFO si;
	si.fMask = SIF_ALL;
	si.nMax = nScrollBarSize;
	si.nMin = 0;
	si.nPage = m_nSize / 10;
	si.nTrackPos = 0;
	si.nPos = 0;
	SetScrollInfo(SB_HORZ,&si);
	Invalidate(false);
	return 0;
}

bool CChildView::SaveBMP(CDC * pDC, CRect BitmapSize, int BitCount, CString filename)
{
	CDC memDC;
	CBitmap Bitmap, *pOldBmp;

	HANDLE handle;
	HANDLE hDIB;
	HPALETTE hPal = NULL;

	BITMAP bm;
	BITMAPINFOHEADER bi;
	LPBITMAPINFOHEADER lpbi;

	DWORD dwLen;

	/*----- CDC의 내용을 Bitmap으로 전송 ----*/
	memDC.CreateCompatibleDC(pDC);
	Bitmap.CreateCompatibleBitmap(pDC, BitmapSize.Width(), BitmapSize.Height());
	pOldBmp = (CBitmap*)memDC.SelectObject(&Bitmap);
	memDC.BitBlt(0, 0, BitmapSize.Width(), BitmapSize.Height(), pDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOldBmp);

	/*------------------------- 비트멥 헤더를 기록함 -------------------------*/
	if (hPal == NULL)
		hPal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);

	GetObject(HBITMAP(Bitmap), sizeof(BITMAP), &bm);

	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = bm.bmWidth;
	bi.biHeight = bm.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = BitCount;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = bm.bmWidth * bm.bmHeight * 3;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	int nColors = (1 << bi.biBitCount);
	if (nColors > 256)
		nColors = 0;

	dwLen = bi.biSize + nColors * sizeof(RGBQUAD);

	hPal = SelectPalette(pDC->GetSafeHdc(), hPal, FALSE);

	RealizePalette(pDC->GetSafeHdc());

	hDIB = GlobalAlloc(GMEM_FIXED, dwLen);

	lpbi = (LPBITMAPINFOHEADER)hDIB;

	*lpbi = bi;

	GetDIBits(pDC->GetSafeHdc(), HBITMAP(Bitmap), 0, (DWORD)bi.biHeight,
		(LPBYTE)NULL, (LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS);

	bi = *lpbi;

	if (bi.biSizeImage == 0)
		bi.biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) / 8) * bi.biHeight;

	dwLen += bi.biSizeImage;

	if (handle = GlobalReAlloc(hDIB, dwLen, GMEM_MOVEABLE))
		hDIB = handle;

	lpbi = (LPBITMAPINFOHEADER)hDIB;

	GetDIBits(pDC->GetSafeHdc(), HBITMAP(Bitmap), 0, (DWORD)bi.biHeight,
		(LPBYTE)lpbi + (bi.biSize + nColors * sizeof(RGBQUAD)),
		(LPBITMAPINFO)lpbi, (DWORD)DIB_RGB_COLORS);

	BITMAPFILEHEADER hdr;

	hdr.bfType = ((WORD)('M' << 8) | 'B');
	hdr.bfSize = (DWORD)(GlobalSize(hDIB) + sizeof(hdr));
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;
	hdr.bfOffBits = (DWORD)(sizeof(hdr) + lpbi->biSize + nColors * sizeof(RGBQUAD));

	char* pBmpBuf;
	DWORD FileSize;
	FileSize = (DWORD)(sizeof(hdr) + GlobalSize(hDIB));
	pBmpBuf = new char[FileSize];

	memcpy(pBmpBuf, &hdr, sizeof(hdr));
	memcpy(pBmpBuf + sizeof(hdr), lpbi, GlobalSize(hDIB));

	/*--------------------- 실제 파일에 기록함 --------------------------*/
	FILE *pFile = NULL;

	fopen_s(&pFile,(CStringA)filename, "wb");

	bool bResult = false;
	if (pFile != NULL)
	{
		fwrite(pBmpBuf, FileSize, 1, pFile);
		fclose(pFile);
		bResult = true;
	}

	delete[] pBmpBuf;

	if (hDIB)
		GlobalFree(hDIB);

	SelectPalette(pDC->GetSafeHdc(), hPal, FALSE);

	return bResult;

}






void CChildView::Onpause()
{
	Closemidi();
	//   delete play;
	   // TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CChildView::OnBack()
{
	if (m_sheet->back_Sheet != nullptr) {
		m_sheet = m_sheet->back_Sheet;
		page++;
	}
	Invalidate(false);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnFront()
{
	if (m_sheet->front_Sheet != nullptr) {
		m_sheet = m_sheet->front_Sheet;
		page--;
	}
	Invalidate(false);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnNew()
{
	m_sheet->back_Sheet = new Sheet(m_sheet->style,b_44,m_sheet->signature);
	m_sheet->back_Sheet->front_Sheet = m_sheet;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}





void CChildView::OnBmp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("%d.bmp"), page);
	SaveBMP(GetDC(), CRect(0, 0, 1240, m_sheet->used_space), 24, str);

}

void CChildView::Onplay()
{
	toolbox_id = onplay;
	Sheet* f_sheet = m_sheet;
	while (f_sheet->front_Sheet != nullptr) {
		f_sheet = f_sheet->front_Sheet;
	}
	//play = new Play();


	initmidi();
	//for (int i = 0; i < m_sheet->style; i++) {
	//	t_sheet[i] = f_sheet;
	//	t_node[i] = t_sheet[i]->first_nodes[i];
	//	t_element[i] = t_node[i]->first_element;
	//	SetTimer(i + 4, 0, NULL);
	//}




	play* temp_play[4];
	for (int i = 0; i < m_sheet->style; i++) {
		t_play[i] = new play(0, 0, 0);
		temp_play[i] = t_play[i];
	}
	play* temp_play2;
	t_sheet = f_sheet;
	while (t_sheet != nullptr) {
		t_sheet = f_sheet;
		for (int i = 0; i < f_sheet->style; i++) {
			t_node = t_sheet->first_nodes[i];
			while (t_node != nullptr) {
				t_element = t_node->first_element;
				while (t_element != nullptr) {
					if (t_element->id == n_note || t_element->id == r_rest) {
						note* t_note = t_element->first_note;
						if (t_note->sound == -1) {
							temp_play[i]->next = new play(-1, -1, t_note->time);
							temp_play[i] = temp_play[i]->next;
						} 
						else{
							int pitch = t_note->sound;
							switch (pitch) {
							case 1:
								if (m_clef == high)
									pitch = 91;
								else
									pitch = 71;
								break;
							case 2:
								if (m_clef == high)
									pitch = 89;
								else
									pitch = 69;
								break;
							case 3:
								if (m_clef == high)
									pitch = 88;
								else
									pitch = 67;
								break;
							case 4:
								if (m_clef == high)
									pitch = 86;
								else
									pitch = 65;
								break;
							case 5: // C6
								if (m_clef == high)
									pitch = 84;
								else
									pitch = 64;
								break;
							case 6:
								if (m_clef == high)
									pitch = 83;
								else
									pitch = 62;
								break;
							case 7:
								if (m_clef == high)
									pitch = 81;
								else
									pitch = 60;
								break;
							case 8:
								if (m_clef == high)
									pitch = 79;
								else
									pitch = 59;
								break;
							case 9:
								if (m_clef == high)
									pitch = 77;
								else
									pitch = 57;
								break;
							case 10:
								if (m_clef == high)
									pitch = 76;
								else
									pitch = 55;
								break;
							case 11:
								if (m_clef == high)
									pitch = 74;
								else
									pitch = 53;
								break;
							case 12:
								if (m_clef == high)
									pitch = 72;
								else
									pitch = 52;
								break;
							case 13:
								if (m_clef == high)
									pitch = 71;
								else
									pitch = 50;
								break;
							case 14:
								if (m_clef == high)
									pitch = 69;
								else
									pitch = 48;
								break;
							case 15:
								if (m_clef == high)
									pitch = 67;
								else
									pitch = 47;
								break;
							case 16:
								if (m_clef == high)
									pitch = 65;
								else
									pitch = 45;
								break;
							case 17:
								if (m_clef == high)
									pitch = 64;
								else
									pitch = 43;
								break;
							case 18:
								if (m_clef == high)
									pitch = 62;
								else
									pitch = 41;
								break;
							case 19:		// C4
								if (m_clef == high)
									pitch = 60;
								else
									pitch = 40;
								break;
							case 20:
								if (m_clef == high)
									pitch = 59;
								else
									pitch = 38;
								break;
							case 21:
								if (m_clef == high)
									pitch = 57;
								else
									pitch = 36;
								break;
							case 22:
								if (m_clef == high)
									pitch = 55;
								else
									pitch = 35;
								break;
							case 23:
								if (m_clef == high)
									pitch = 53;
								else
									pitch = 33;
								break;
							case 24:
								if (m_clef == high)
									pitch = 52;
								else
									pitch = 31;
								break;
							case 25:
								if (m_clef == high)
									pitch = 50;
								else
									pitch = 29;
								break;
							default:
								break;
							}
							int c=0;
							if (m_sheet->signature != 0) {
								switch (m_sheet->signature) {
								case 7:
									while (pitch - c > 0) {
										if (83 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 6:
									while (pitch - c > 0) {
										if (88 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 5:
									while (pitch - c > 0) {
										if (81 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 4:
									while (pitch - c > 0) {
										if (86 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 3:
									while (pitch - c > 0) {
										if (91 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 2:
									while (pitch - c > 0) {
										if (84 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
								case 1: 
									while (pitch - c > 0) {
										if (89 - c == pitch) {
											pitch++;
											break;
										}
										c += 12;
									}
									c = 0;
									break;
								case 14:
									while (pitch - c > 0) {
										if (89 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 13:
									while (pitch - c > 0) {
										if (84 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 12:
									while (pitch - c > 0) {
										if (91 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 11:
									while (pitch - c > 0) {
										if (86 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 10:
									while (pitch - c > 0) {
										if (81 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 9:
									while (pitch - c > 0) {
										if (88 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
								case 8:
									while (pitch - c > 0) {
										if (83 - c == pitch) {
											pitch--;
											break;
										}
										c += 12;
									}
									c = 0;
									break;
								}
							}
							if (t_note->condition_mark != -1) {
								if (t_note->condition_mark == shap)
									pitch++;
								if (t_note->condition_mark == flat)
									pitch--;
							}
							temp_play[i]->next = new play(pitch, m_intense, t_note->time);
							temp_play2 = temp_play[i]->next;
							temp_play[i] = temp_play[i]->next;
							t_note = t_note->next;
							while (t_note != nullptr) {
								int pitch = t_note->sound;
								switch (pitch) {
								case 1:
									if (m_clef == high)
										pitch = 91;
									else
										pitch = 71;
									break;
								case 2:
									if (m_clef == high)
										pitch = 89;
									else
										pitch = 69;
									break;
								case 3:
									if (m_clef == high)
										pitch = 88;
									else
										pitch = 67;
									break;
								case 4:
									if (m_clef == high)
										pitch = 86;
									else
										pitch = 65;
									break;
								case 5: // C6
									if (m_clef == high)
										pitch = 84;
									else
										pitch = 64;
									break;
								case 6:
									if (m_clef == high)
										pitch = 83;
									else
										pitch = 62;
									break;
								case 7:
									if (m_clef == high)
										pitch = 81;
									else
										pitch = 60;
									break;
								case 8:
									if (m_clef == high)
										pitch = 79;
									else
										pitch = 59;
									break;
								case 9:
									if (m_clef == high)
										pitch = 77;
									else
										pitch = 57;
									break;
								case 10:
									if (m_clef == high)
										pitch = 76;
									else
										pitch = 55;
									break;
								case 11:
									if (m_clef == high)
										pitch = 74;
									else
										pitch = 53;
									break;
								case 12:
									if (m_clef == high)
										pitch = 72;
									else
										pitch = 52;
									break;
								case 13:
									if (m_clef == high)
										pitch = 71;
									else
										pitch = 50;
									break;
								case 14:
									if (m_clef == high)
										pitch = 69;
									else
										pitch = 48;
									break;
								case 15:
									if (m_clef == high)
										pitch = 67;
									else
										pitch = 47;
									break;
								case 16:
									if (m_clef == high)
										pitch = 65;
									else
										pitch = 45;
									break;
								case 17:
									if (m_clef == high)
										pitch = 64;
									else
										pitch = 43;
									break;
								case 18:
									if (m_clef == high)
										pitch = 62;
									else
										pitch = 41;
									break;
								case 19:		// C4
									if (m_clef == high)
										pitch = 60;
									else
										pitch = 40;
									break;
								case 20:
									if (m_clef == high)
										pitch = 59;
									else
										pitch = 38;
									break;
								case 21:
									if (m_clef == high)
										pitch = 57;
									else
										pitch = 36;
									break;
								case 22:
									if (m_clef == high)
										pitch = 55;
									else
										pitch = 35;
									break;
								case 23:
									if (m_clef == high)
										pitch = 53;
									else
										pitch = 33;
									break;
								case 24:
									if (m_clef == high)
										pitch = 52;
									else
										pitch = 31;
									break;
								case 25:
									if (m_clef == high)
										pitch = 50;
									else
										pitch = 29;
									break;
								default:
									break;
								}
								int c = 0;
								if (m_sheet->signature != 0) {
									switch (m_sheet->signature) {
									case 7:
										while (pitch - c > 0) {
											if (83 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 6:
										while (pitch - c > 0) {
											if (88 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 5:
										while (pitch - c > 0) {
											if (81 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 4:
										while (pitch - c > 0) {
											if (86 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 3:
										while (pitch - c > 0) {
											if (91 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 2:
										while (pitch - c > 0) {
											if (84 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
									case 1:
										while (pitch - c > 0) {
											if (89 - c == pitch) {
												pitch++;
												break;
											}
											c += 12;
										}
										c = 0;
										break;
									case 14:
										while (pitch - c > 0) {
											if (89 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 13:
										while (pitch - c > 0) {
											if (84 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 12:
										while (pitch - c > 0) {
											if (91 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 11:
										while (pitch - c > 0) {
											if (86 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 10:
										while (pitch - c > 0) {
											if (81 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 9:
										while (pitch - c > 0) {
											if (88 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
									case 8:
										while (pitch - c > 0) {
											if (83 - c == pitch) {
												pitch--;
												break;
											}
											c += 12;
										}
										c = 0;
										break;
									}
								}
								temp_play2->n_next = new play(pitch, m_intense, t_note->time);
								temp_play2 = temp_play2->n_next;

								t_note = t_note->next;
							}
						}
					}
					else {
						if (t_element->id == high)
							m_clef = high;
						if (t_element->id == low)
							m_clef = low;
					}
					t_element = t_element->back_element;
				}
				t_node = t_node->back_node;
			}
		}
		t_sheet = t_sheet->back_Sheet;
	}
	fin[0] = fin[1] = fin[2] = fin[3] = true;
	for (int i = 0; i < m_sheet->style; i++){
		n_play[i] = t_play[i]->next;
		time1[i] = 0;
		time2 = 0;
		fin[i] = false;
	}
	SetTimer(10, 10, NULL);
	//for (int i = 0; i < m_sheet->style; i++) {
	//	play* play = t_play[i]->next;
	//	while (play != nullptr) {
	//		while (play != nullptr) {
	//			midi(this->hdevice, 0x90, 0, play->pitch, m_intense);
	//			play = play->n_next;
	//		}
	//		play = play->next;
	//	}
	//	SetTimer(i, 0, NULL);
	//}

	//Closemidi();


	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnTimer(UINT_PTR n)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.


	switch (n) {
	case 10:
		for (int i = 0; i < m_sheet->style; i++) {
			if (time1[i] == time2) {
				play* play1 = n_play[i];
				while (play1 != nullptr) {
					if (play1->pitch != -1)
						midi(this->hdevice, 0x90, 0, play1->pitch, m_intense);
					play1 = play1->n_next;
				}
				if (n_play[i] != nullptr)
					time1[i] += n_play[i]->time * 50;
			}
		}
		time2 += 10;
		for (int i = 0; i < m_sheet->style; i++) {
			if (time1[i] == time2) {
				play* play1 = n_play[i];
				while (play1 != nullptr) {
					if (play1->pitch != -1)
						midi(this->hdevice, 0x80, 0, play1->pitch, 0);
					play1 = play1->n_next;
				}
				if (n_play[i] != nullptr)
					n_play[i] = n_play[i]->next;
				if (n_play[i] == nullptr) {
					fin[i] = true;
				}
			}
		}
		if (fin[0] && fin[1] && fin[2] && fin[3]) {
			KillTimer(10);
			Closemidi();
			for (int i = 0; i < m_sheet->style; i++) {
				while (t_play[i] != nullptr) {
					play* t = t_play[i];
					t_play[i] = t_play[i]->next;
					delete t;
				}
			}
		}
		break;
	//case 0:
	//case 1:
	//case 2:
	//case 3:
	//	KillTimer(n);
	//	if (n_play[n] != nullptr) {
	//		play* play = n_play[n];
	//		while (play != nullptr) {
	//			midi(this->hdevice, 0x90, 0, play->pitch, m_intense);
	//			play=play->n_next;
	//		}
	//		SetTimer(n + 4, n_play[n]->time*100, NULL);
	//	}
	//	else {
	//		if (n == m_sheet->style) {
	//			Closemidi();
	//			for (int i = 0; i < m_sheet->style; i++) {
	//				while (t_play[i] != nullptr) {
	//					play* t = t_play[i];
	//					t_play[i] = t_play[i]->next;
	//					delete t;
	//				}
	//			}
	//		}
	//	}
	//	break;
		//if (t_element[n]->id == n_note || t_element[n]->id == r_rest) {
		//	keyUp(t_element[n]->first_note);
		//}
		////if (t_element[0]->id == r_rest)
		////	keyDown(t_element[0]->first_note);
		//if (t_element[n]->back_element != nullptr) {
		//	t_element[n] = t_element[n]->back_element;
		//}
		//else {
		//	if (t_node[n]->back_node != nullptr) {
		//		t_node[n] = t_node[n]->back_node;
		//		t_element[n] = t_node[n]->first_element;
		//	}
		//	else {
		//		if (t_sheet[n]->back_Sheet != nullptr) {
		//			t_sheet[n] = t_sheet[n]->back_Sheet;
		//			t_node[n] = t_sheet[n]->first_nodes[n];
		//			t_element[n] = t_node[n]->first_element;
		//		}
		//		else if( n == m_sheet->style ) {
		//			KillTimer(n);
		//			KillTimer(n + 4);
		//			Closemidi();
		//			break;
		//		}
		//	}
		//}
		//SetTimer(n + 4, 0, NULL);
		//KillTimer(n);
		//break;
	//case 4:
	//case 5:
	//case 6:
	//case 7:
	//	KillTimer(n);
	//	if (n_play[n-4] != nullptr) {
	//		play* play = n_play[n-4];
	//		while (play != nullptr) {
	//			midi(this->hdevice, 0x80, 0, play->pitch, 0);
	//			play=play->n_next;
	//		}
	//		n_play[n - 4] = n_play[n - 4]->next;
	//		if (n - 4 == m_sheet->style-1) {
	//			for (int i = 0; i < m_sheet->style; i++) {
	//				SetTimer(n - 4 - i, 0, NULL);
	//			}
	//		}
	//	}
	//	break;
		//KillTimer(n);
		//if (t_element[n - 4]->id == n_note || t_element[n - 4]->id == r_rest) {
		//	keyDown(t_element[n - 4]->first_note);
		//	SetTimer(n - 4, t_element[n - 4]->first_note->time * 100, NULL);
		//}
		//else {
		//	if (t_element[n - 4]->id == high)
		//		m_clef = high;
		//	if (t_element[n - 4]->id == low)
		//		m_clef = low;
		//	if (t_element[n - 4]->back_element != nullptr) {
		//		t_element[n - 4] = t_element[n - 4]->back_element;
		//	}
		//	else {
		//		if (t_sheet[n]->back_Sheet != nullptr) {
		//			t_sheet[n] = t_sheet[n]->back_Sheet;
		//			t_node[n] = t_sheet[n]->first_nodes[n];
		//			t_element[n] = t_node[n]->first_element;
		//		}
		//		else if(n == m_sheet->style) {
		//			KillTimer(n);
		//			Closemidi();
		//			break;
		//		}
		//	}
		//	SetTimer(n, 0, NULL);
		//}
		//break;
	}

	CWnd::OnTimer(n);
}



bool CChildView::midi(HMIDIOUT device, int status, int channel, int low, int high)
{
	// TODO: 여기에 구현 코드 추가.

	DWORD dwMsg = (status | channel | (high << 16) | (low << 8));
	midiOutShortMsg(device, dwMsg);
	return true;
}

bool CChildView::keyDown(note * n)
{
	note* temp = n;
	while (temp != nullptr) {
		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (m_clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (m_clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (m_clef == high)
				pitch = 88;
			else
				pitch = 65;
			break;
		case 4:
			if (m_clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (m_clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (m_clef == high)
				pitch = 83;
			else
				pitch = 60;
			break;
		case 7:
			if (m_clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (m_clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (m_clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (m_clef == high)
				pitch = 76;
			else
				pitch = 53;
			break;
		case 11:
			if (m_clef == high)
				pitch = 74;
			else
				pitch = 52;
			break;
		case 12:
			if (m_clef == high)
				pitch = 72;
			else
				pitch = 50;
			break;
		case 13:
			if (m_clef == high)
				pitch = 71;
			else
				pitch = 48;
			break;
		case 14:
			if (m_clef == high)
				pitch = 69;
			else
				pitch = 47;
			break;
		case 15:
			if (m_clef == high)
				pitch = 67;
			else
				pitch = 45;
			break;
		case 16:
			if (m_clef == high)
				pitch = 65;
			else
				pitch = 43;
			break;
		case 17:
			if (m_clef == high)
				pitch = 64;
			else
				pitch = 41;
			break;
		case 18:
			if (m_clef == high)
				pitch = 62;
			else
				pitch = 40;
			break;
		case 19:
			if (m_clef == high)
				pitch = 60;
			else
				pitch = 38;
			break;
		case 20:
			if (m_clef == high)
				pitch = 59;
			else
				pitch = 36;
			break;
		case 21:
			if (m_clef == high)
				pitch = 57;
			else
				pitch = 35;
			break;
		case 22:
			if (m_clef == high)
				pitch = 55;
			else
				pitch = 33;
			break;
		case 23:
			if (m_clef == high)
				pitch = 54;
			else
				pitch = 31;
			break;
		case 24:
			if (m_clef == high)
				pitch = 52;
			else
				pitch = 29;
			break;
		case 25:
			if (m_clef == high)
				pitch = 50;
			else
				pitch = 27;
			break;
		default:
			break;
		}

		if (temp->condition_mark != -1) {
			if (temp->condition_mark == shap)
				pitch++;
			if (temp->condition_mark == flat)
				pitch--;
		}

		//if (signature != 0) {
		//	switch (signature) {
		//	case 1:
		//		if (pitch == 65 || pitch == 77 || pitch == 89)
		//			pitch++;
		//		break;
		//	case 2:
		//	case 3:
		//	case 4:
		//	case 5:
		//	case 6:
		//	case 7:
		//	case 8:
		//	case 9:
		//	case 10:
		//	case 11:
		//	case 12:
		//	case 13:
		//	case 14:
		//	}
		//}


		midi(this->hdevice, 0x90, 0, pitch, m_intense);



		temp = temp->next;
	}

	return true;
}

bool CChildView::keyUp(note* n)
{
	note* temp = n;
	while (temp != nullptr) {

		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (m_clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (m_clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (m_clef == high)
				pitch = 88;
			else
				pitch = 66;
			break;
		case 4:
			if (m_clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (m_clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (m_clef == high)
				pitch = 83;
			else
				pitch = 61;
			break;
		case 7:
			if (m_clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (m_clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (m_clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (m_clef == high)
				pitch = 76;
			else
				pitch = 54;
			break;
		case 11:
			if (m_clef == high)
				pitch = 74;
			else
				pitch = 53;
			break;
		case 12:
			if (m_clef == high)
				pitch = 72;
			else
				pitch = 51;
			break;
		case 13:
			if (m_clef == high)
				pitch = 71;
			else
				pitch = 50;
			break;
		case 14:
			if (m_clef == high)
				pitch = 69;
			else
				pitch = 48;
			break;
		case 15:
			if (m_clef == high)
				pitch = 67;
			else
				pitch = 46;
			break;
		case 16:
			if (m_clef == high)
				pitch = 65;
			else
				pitch = 44;
			break;
		case 17:
			if (m_clef == high)
				pitch = 64;
			else
				pitch = 43;
			break;
		case 18:
			if (m_clef == high)
				pitch = 62;
			else
				pitch = 41;
			break;
		case 19:
			if (m_clef == high)
				pitch = 60;
			else
				pitch = 39;
			break;
		case 20:
			if (m_clef == high)
				pitch = 59;
			else
				pitch = 39;
			break;
		case 21:
			if (m_clef == high)
				pitch = 57;
			else
				pitch = 39;
			break;
		case 22:
			if (m_clef == high)
				pitch = 55;
			else
				pitch = 39;
			break;
		case 23:
			if (m_clef == high)
				pitch = 54;
			else
				pitch = 39;
			break;
		case 24:
			if (m_clef == high)
				pitch = 52;
			else
				pitch = 39;
			break;
		case 25:
			if (m_clef == high)
				pitch = 50;
			else
				pitch = 39;
			break;
		default:
			break;
		}

		if (temp->condition_mark != -1) {
			if (temp->condition_mark == shap)
				pitch++;
			if (temp->condition_mark == flat)
				pitch--;
		}

		midi(this->hdevice, 0x80, 0, pitch, 0);



		temp = temp->next;
	}

	return true;
}

void CChildView::Closemidi()
{
	midiOutReset(this->hdevice);
	midiOutClose(this->hdevice);

	// TODO: 여기에 구현 코드 추가.
}


void CChildView::initmidi()
{
	midiOutOpen(&(this->hdevice), MIDIMAPPER, 0, 0, CALLBACK_NULL);
	// TODO: 여기에 구현 코드 추가.
	return;
}

