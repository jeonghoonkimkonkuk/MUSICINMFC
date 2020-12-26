#pragma once
#include"Resource.h"
#include"note.h"


class element
{
public:
	element();
	element(CPoint location, int id,bool forshow);
	~element();
	void paint(CDC & mem_dc);
	bool addNote(int y,int id,int forshow);
	void deleteNote();
	void init(CRect node_rect);
	void notforshow();
	note* getnote(CPoint pt);
public:

	int id;
	// 요소의 종류

	CRect node_rect;
	bool forshow;
	CPoint location;

	CRect rect;
	
	CBitmap bitmap;
	BITMAP bmp_info;

	note* first_note;	// 음표인경우

	element* front_element;		// 앞의 요소
	element* back_element;		// 뒤의 요소
};

