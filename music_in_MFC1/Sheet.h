#pragma once
#include<iostream>
#include<string>
#include"node.h"
using namespace std;
class node;
class element;
// 악보전체의 정보를 총괄하는 class
// 모든 함수의 형태는 링크드 리스트르 탐색하면서 진행하는것과
// 유사하게 진행될거 같아
class Sheet
{
public:
	Sheet();
	~Sheet();
	Sheet(int style,int time, int signature); 
	// 악보를 처음 만들 때 어떤 형태의 보표인지 정하게 하쟈
public:
	CString Sheet_name;	// 악보의 이름
	CString composer;	// 작곡가
	// 제목칸 자리 32픽셀
	int style;
	int signature;
	int time;
	// 보표의 종류
	int used_space;
	// 사용한 공간
	node** first_nodes;
	// 첫 마디
	CBitmap bmp_score;
	BITMAP bmpinfo_score;

	Sheet* front_Sheet;
	Sheet* back_Sheet;

	int width, height;
	// 너비, 높이


public:
	// 이거 동적할당 배열이야 처음 노드들을 가지고 있어야하는데
	// 보표가 어떤 형태일지 몰라서 동적할당하는 형태로 만들었어
	// 더블포인터형으로 만들지 고민해보면좋을듯

	bool new_node();
	
	// 노드를 새로만들때 호출 되는 함수
	//element* getElement(CPoint pt, int id);
	// 이게 제일 고민인함수인데 마우스의 위치에서의 요소를 반환하라는
	// 함수인데, 지금 형태로른 우리가 사용하는 요소들(마디,음표 등)을
	// int형이든 뭐든 구분자를 정해서 해당위치에 뭔진몰라도 이런 요소가
	// 있다라고 알려주는 함수가 되는거야. 그러고 나서 이제 다음함수를
	// 호출하게 되는거지
	// 이함수의 형태는 first_nodes부터 탐색하기 시작해서 마디의 영역에
	// 들어가 있는지 확인, 마디에 영역에 있다면 마디내부에 있는 요소들의
	// 영역중 들어가는게 있는지확인하면서, 어떤 두 요소의 x좌표 사이에있다면
	// 그 위치를 그냥 반환하면서, 반환값자체는 nullptr을 주면될거같아
	element* getElement(CPoint pt);
	node *getNode(CPoint pt);
	// 오버로드 함수를 만든 이유는 요소르 추가할때 사용할때에는 앞뒤 요소가 뭔지 반환해주면
	// 추가하는 구문이 간단해져서 넣었어, 탐색 알고리즘 자체는 유사한데
	// 그냥 앞뒤요소만 가지고 가면서 탐색하면되니까

	bool addElement(CPoint pt, element * e);
	bool deleteElement(CPoint pt);
	bool split(CPoint pt, bool forshow);
	bool unsplit(CPoint pt);

	void paint(CDC& mem_dc);

	bool save(string str);
	// 저장함수 
	bool load(string str);
	// 불러오기 함수
	bool play();
	// 재생함수도 여기에있는게 맞을듯
	void updateTime();
};

