#pragma once
// 기본적으로 오선지를 깔게될때 작은보표(1줄짜리)라면 그냥 마디 하나를 생성하는거라고 생각하는 방향으로 가쟈
#include"element.h"


class node
{
public:
	node();
	~node();
	node(CPoint location, CRect* rect, node* front_node, node* back_node);
	void paint(CDC& mem_dc);
	element * getElement(CPoint pt);
	bool addElement(CPoint pt, element * e);
	bool deleteElement(CPoint pt);
	void updateTime(int time);
	CString checkTime();

public:
	CPoint location;
	// 마디의 절대위치
	CRect *rect;
	// 마디의 영역
	CRect *s_rect;
	//CRgn rgn_note[28];
	// 픽셀이미지 값 아이디어로 변환
	// 오선지 높이 위치에 따른 영역정보, 즉 위의 rgn의 영역을 쪼개놓은 것임
	// 기본 오선지의 구분이 11개 -> 칸과 줄 개수
	// 위아래로 공간 5칸씩 -> 음표뿐만아니라 다른 요소들도 붙을수있은 공간임
	// 한칸의 크기에대해서는 향후 조정
	// 이게 지금 높에관련된 정보만 있는거라 조금 고민인데, 너비에 관한 정보는
	// 어차피 비율 처리할거라면 우리가 나누는거보다 수학적으로 계산해서 
	// 처리하는게 자연스러울거같아

	double time;		// 해당 마디에서 필요한 박자
	int type;			// 어떤 음자리표인지
	bool forshow;

	element* first_element;
	// 마디상에서의 첫 요소
	// 읽는 순서의 우선순위는 왼쪽에서 오른쪽, 위쪽에서 아래쪽

	bool first_node;	
	// 한줄에서 첫번째 마디임을 알리는 변수로 음자리표를 반드시 표시해야함
	// 사실 이부분때문에 형태를 다르게 잡아야하나 고민이기도햄


	node* front_node;		// 앞 마디
	node* back_node;		// 뒷 마디

};

