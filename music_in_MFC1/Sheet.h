#pragma once
#include<iostream>
#include<string>
#include"node.h"
using namespace std;
class node;
class element;
// �Ǻ���ü�� ������ �Ѱ��ϴ� class
// ��� �Լ��� ���´� ��ũ�� ����Ʈ�� Ž���ϸ鼭 �����ϴ°Ͱ�
// �����ϰ� ����ɰ� ����
class Sheet
{
public:
	Sheet();
	~Sheet();
	Sheet(int style,int time, int signature); 
	// �Ǻ��� ó�� ���� �� � ������ ��ǥ���� ���ϰ� ����
public:
	CString Sheet_name;	// �Ǻ��� �̸�
	CString composer;	// �۰
	// ����ĭ �ڸ� 32�ȼ�
	int style;
	int signature;
	int time;
	// ��ǥ�� ����
	int used_space;
	// ����� ����
	node** first_nodes;
	// ù ����
	CBitmap bmp_score;
	BITMAP bmpinfo_score;

	Sheet* front_Sheet;
	Sheet* back_Sheet;

	int width, height;
	// �ʺ�, ����


public:
	// �̰� �����Ҵ� �迭�̾� ó�� ������ ������ �־���ϴµ�
	// ��ǥ�� � �������� ���� �����Ҵ��ϴ� ���·� �������
	// ���������������� ������ ����غ���������

	bool new_node();
	
	// ��带 ���θ��鶧 ȣ�� �Ǵ� �Լ�
	//element* getElement(CPoint pt, int id);
	// �̰� ���� ������Լ��ε� ���콺�� ��ġ������ ��Ҹ� ��ȯ�϶��
	// �Լ��ε�, ���� ���·θ� �츮�� ����ϴ� ��ҵ�(����,��ǥ ��)��
	// int���̵� ���� �����ڸ� ���ؼ� �ش���ġ�� �������� �̷� ��Ұ�
	// �ִٶ�� �˷��ִ� �Լ��� �Ǵ°ž�. �׷��� ���� ���� �����Լ���
	// ȣ���ϰ� �Ǵ°���
	// ���Լ��� ���´� first_nodes���� Ž���ϱ� �����ؼ� ������ ������
	// �� �ִ��� Ȯ��, ���� ������ �ִٸ� ���𳻺ο� �ִ� ��ҵ���
	// ������ ���°� �ִ���Ȯ���ϸ鼭, � �� ����� x��ǥ ���̿��ִٸ�
	// �� ��ġ�� �׳� ��ȯ�ϸ鼭, ��ȯ����ü�� nullptr�� �ָ�ɰŰ���
	element* getElement(CPoint pt);
	node *getNode(CPoint pt);
	// �����ε� �Լ��� ���� ������ ��Ҹ� �߰��Ҷ� ����Ҷ����� �յ� ��Ұ� ���� ��ȯ���ָ�
	// �߰��ϴ� ������ ���������� �־���, Ž�� �˰��� ��ü�� �����ѵ�
	// �׳� �յڿ�Ҹ� ������ ���鼭 Ž���ϸ�Ǵϱ�

	bool addElement(CPoint pt, element * e);
	bool deleteElement(CPoint pt);
	bool split(CPoint pt, bool forshow);
	bool unsplit(CPoint pt);

	void paint(CDC& mem_dc);

	bool save(string str);
	// �����Լ� 
	bool load(string str);
	// �ҷ����� �Լ�
	bool play();
	// ����Լ��� ���⿡�ִ°� ������
	void updateTime();
};

