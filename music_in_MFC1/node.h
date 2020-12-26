#pragma once
// �⺻������ �������� ��Եɶ� ������ǥ(1��¥��)��� �׳� ���� �ϳ��� �����ϴ°Ŷ�� �����ϴ� �������� ����
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
	// ������ ������ġ
	CRect *rect;
	// ������ ����
	CRect *s_rect;
	//CRgn rgn_note[28];
	// �ȼ��̹��� �� ���̵��� ��ȯ
	// ������ ���� ��ġ�� ���� ��������, �� ���� rgn�� ������ �ɰ����� ����
	// �⺻ �������� ������ 11�� -> ĭ�� �� ����
	// ���Ʒ��� ���� 5ĭ�� -> ��ǥ�Ӹ��ƴ϶� �ٸ� ��ҵ鵵 ���������� ������
	// ��ĭ�� ũ�⿡���ؼ��� ���� ����
	// �̰� ���� �������õ� ������ �ִ°Ŷ� ���� ����ε�, �ʺ� ���� ������
	// ������ ���� ó���ҰŶ�� �츮�� �����°ź��� ���������� ����ؼ� 
	// ó���ϴ°� �ڿ�������Ű���

	double time;		// �ش� ���𿡼� �ʿ��� ����
	int type;			// � ���ڸ�ǥ����
	bool forshow;

	element* first_element;
	// ����󿡼��� ù ���
	// �д� ������ �켱������ ���ʿ��� ������, ���ʿ��� �Ʒ���

	bool first_node;	
	// ���ٿ��� ù��° �������� �˸��� ������ ���ڸ�ǥ�� �ݵ�� ǥ���ؾ���
	// ��� �̺κж����� ���¸� �ٸ��� ��ƾ��ϳ� ����̱⵵��


	node* front_node;		// �� ����
	node* back_node;		// �� ����

};

