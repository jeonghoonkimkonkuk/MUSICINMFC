#pragma once

#pragma comment(lib, "WinMM.lib")
#include <Windows.h>
#include <mmsystem.h>
#include <process.h> 
#include <vector>
#include"node.h"
#include"note.h"
#include"Sheet.h"


using namespace std;

//enum thread {
//	Thread_END = 0,
//	Thread_RUNNING = 1,
//	Thread_PAUSE = 2
//};
class Play :public CWinThread, public CWnd
{

public:
	bool isPlay;
	Play();
	Play(int style);
	~Play();

	int style;
	int clef;
	int intense;
	int signature;
	Sheet* sheet;


	static UINT ThreadFirst(LPVOID _mothod);


	bool key(note* n);
	void music_play(Sheet * m_sheet);

	bool midi(HMIDIOUT device, int status, int channel, int low, int high);
	bool keyDown(note* n);
	bool keyUp(note* n);
	HMIDIOUT hdevice;
	CWinThread* pthread;
	bool m_threadbool;
	static volatile bool isThreadRunning;
	void Closemidi();
	void initmidi();



	bool Wait(DWORD second);
	UINT miditest();
	//void Change();
	void music_play();
};

