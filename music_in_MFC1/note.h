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
	// ���� ��ġ childview�󿡼��� ��ġ�� ����
	// �ٸ� ��ǥ�� ���� ����� �߰��ȴٸ� ����Ǿ����				

	CBitmap bitmap;
	BITMAP bmp_info;

	bool highest;
	bool lowest;
		
	// ��ǥ�� ����, childview�󿡼� Ŭ���ɼ��ִ� ������ ����
	// �ٸ� ��ǥ�� ���� ����� �߰��ȴٸ� ����Ǿ����
	int time;				// ��ǥ�� ���ڱ���
	int sound;					// ���� ������
	bool condition_dot;
	int condition_mark;
	note* next;
	// ���� ���� ���� �ϴ� 3���� ���� ����
	// ��Ÿī�䳪 ����ǥ ������


};

