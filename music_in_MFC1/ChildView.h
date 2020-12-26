
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once
#include<iostream>
#include<string>
#include"Sheet.h"
#include"Play.h"
#include <Windows.h>
#include <mmsystem.h>
#include <process.h> 
#include <vector>
#include"node.h"
#include"note.h"
#include"Sheet.h"


using namespace std;

enum thread {
	Thread_END = 0,
	Thread_RUNNING = 1,
	Thread_PAUSE = 2
};
struct  play
{
	play(int p, int i, int t)
		: pitch(p), intese(i), time(t), n_next(nullptr), next(nullptr) {}
	int pitch;
	int intese;
	int time;
	play* n_next;
	play* next;
};


class Sheet;
class node;
class element;
class note;
//


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
public:
	Sheet* m_sheet;
	CPoint splitforshow;
	// 어떤 보표를 사용할지 받아야해서 동적할당
	NODE toolbox_id;
	// 툴상자에서 선택되어져 있는 요소의 아이디
	// OnLButtonDown함수에서 해야할 일을 결정
	int selected_id;
	// 그려진 요소가 선택되어져 있는 경우 사용할 툴박스를 정해야하기 때문에 필요할듯
	element* selected_element;
	// 선택된 요소가 변경될때 이용
	int page;
	// 페이지 정보
	bool point;
	//사이즈 체크
	bool Check_Size;
	//확대/축소
	int Sheet_Size;
	
	//Play* play;
	bool midi(HMIDIOUT device, int status, int channel, int low, int high);
	bool keyDown(note* n);
	bool keyUp(note* n);
	HMIDIOUT hdevice;
	CWinThread* pthread;
	bool m_threadbool;
	static volatile bool isThreadRunning;
	void Closemidi();
	void initmidi();
	int m_clef;
	int m_intense;
	int m_signature;
	//Sheet* t_sheet[4];
	//node* t_node[4];
	//element* t_element[4];
	Sheet* t_sheet;
	node* t_node;
	element* t_element;
	play* t_play[4];
	play* n_play[4];
	int time1[4];
	int time2;
	bool fin[4];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void Onplay();


	element* elforshow;
	element* noteforshow;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);



	//오선지
	afx_msg void OnScoreSmall();
	//음자리표
	afx_msg void Onhigh();
	afx_msg void Onlow();
	afx_msg void OnUpdatehigh(CCmdUI *pCmdUI);
	afx_msg void OnUpdatelow(CCmdUI *pCmdUI);
	//음표
	afx_msg void OnN0();
	afx_msg void Onn2();
	afx_msg void OnN4();
	afx_msg void OnN8();
	afx_msg void OnN16();
	//쉼표
	afx_msg void OnR0();
	afx_msg void OnR2();
	afx_msg void OnR4();
	afx_msg void OnR8();
	afx_msg void OnUpdateN0(CCmdUI *pCmdUI);
	afx_msg void OnUpdaten2(CCmdUI *pCmdUI);
	afx_msg void OnUpdateN4(CCmdUI *pCmdUI);
	afx_msg void OnUpdateN8(CCmdUI *pCmdUI);
	afx_msg void OnUpdateN16(CCmdUI *pCmdUI);
	afx_msg void OnUpdateR0(CCmdUI *pCmdUI);
	afx_msg void OnUpdateR2(CCmdUI *pCmdUI);
	afx_msg void OnUpdateR4(CCmdUI *pCmdUI);
	afx_msg void OnUpdateR8(CCmdUI *pCmdUI);
	//도돌이 표
	afx_msg void Onstart();
	afx_msg void Onend();
	afx_msg void OnUpdatestart(CCmdUI *pCmdUI);
	afx_msg void OnUpdateend(CCmdUI *pCmdUI);
	//셈여림표
	afx_msg void Onf();
	afx_msg void Onmp();
	afx_msg void Onfff();
	afx_msg void Onmf();
	afx_msg void Onff();
	afx_msg void OnUpdatef(CCmdUI *pCmdUI);
	afx_msg void OnUpdateff(CCmdUI *pCmdUI);
	afx_msg void OnUpdatefff(CCmdUI *pCmdUI);
	afx_msg void OnUpdatemf(CCmdUI *pCmdUI);
	afx_msg void OnUpdatemp(CCmdUI *pCmdUI);
	//음계
	afx_msg void Onss();
	afx_msg void OnUpdatess(CCmdUI *pCmdUI);
	afx_msg void Onsb();
	afx_msg void OnUpdatesb(CCmdUI *pCmdUI);
	afx_msg void OnUpdatesn(CCmdUI *pCmdUI);
	afx_msg void Onsn();
	//점
	afx_msg void OnP();
	afx_msg void OnUpdateP(CCmdUI *pCmdUI);
	afx_msg void Ondp();
	afx_msg void OnUpdatedp(CCmdUI *pCmdUI);
	afx_msg void Onpp();
	afx_msg void OnUpdatepp(CCmdUI *pCmdUI);
	afx_msg void OnUpdateppp(CCmdUI *pCmdUI);
	afx_msg void Onppp();
	afx_msg void On24();
	afx_msg void OnUpdate24(CCmdUI *pCmdUI);
	afx_msg void On34();
	afx_msg void OnUpdate34(CCmdUI *pCmdUI);
	afx_msg void OnUpdate44(CCmdUI *pCmdUI);
	afx_msg void On44();
	afx_msg void On54();
	afx_msg void OnUpdate54(CCmdUI *pCmdUI);
	afx_msg void On64();
	afx_msg void OnUpdate64(CCmdUI *pCmdUI);
	afx_msg void On38();
	afx_msg void OnUpdate38(CCmdUI *pCmdUI);
	afx_msg void On68();
	afx_msg void OnUpdate68(CCmdUI *pCmdUI);
	afx_msg void On98();
	afx_msg void OnUpdate98(CCmdUI *pCmdUI);
	afx_msg void On128();
	afx_msg void OnUpdate128(CCmdUI *pCmdUI);
	afx_msg void OnSplit();
	afx_msg void OnUpdateSplit(CCmdUI *pCmdUI);
	afx_msg void OnUnsplit();
	afx_msg void OnUpdateUnsplit(CCmdUI *pCmdUI);
	afx_msg void OnMax();
	afx_msg void OnUpdateMax(CCmdUI *pCmdUI);
	afx_msg void OnMin();
	afx_msg void OnUpdateMin(CCmdUI *pCmdUI);
	int add_VScroll();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int add_HScroll();

	bool SaveBMP(CDC *pDC, CRect BitmapSize, int Bitcount, CString filename);

	afx_msg void Onpause();
	afx_msg void OnBack();
	afx_msg void OnFront();
	afx_msg void OnNew();

	afx_msg void OnBmp();

};

