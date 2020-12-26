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
	// ����� ����

	CRect node_rect;
	bool forshow;
	CPoint location;

	CRect rect;
	
	CBitmap bitmap;
	BITMAP bmp_info;

	note* first_note;	// ��ǥ�ΰ��

	element* front_element;		// ���� ���
	element* back_element;		// ���� ���
};

