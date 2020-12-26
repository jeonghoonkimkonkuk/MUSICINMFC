#pragma once
#include"Resource.h"
#include"h.h"
class note 
{
public:
	note();
	~note();
	note(CPoint location,int id,int forshow,int sound);
	void paint(CDC& mem_dc);
	void notforshow();
	bool check_closenote(int sound);
	void check_highest();
public:
	int id;
	int forshow;
	
	CPoint location;
	// 절대 위치 childview상에서의 위치를 뜻함
	// 다른 음표가 같은 마디상에 추가된다면 변경되어야함				

	CBitmap bitmap;
	BITMAP bmp_info;

	bool highest;
	bool lowest;
		
	// 음표의 영역, childview상에서 클릭될수있는 영역을 뜻함
	// 다른 음표가 같은 마디상에 추가된다면 변경되어야함
	int time;				// 음표의 박자길이
	int sound;					// 음의 높낮이
	bool condition_dot;
	int condition_mark;
	note* next;
	// 음의 연주 상태 일단 3개로 향후 변경
	// 스타카토나 늘임표 같은거


};

