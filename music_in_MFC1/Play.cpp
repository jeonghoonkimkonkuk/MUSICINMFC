#include "stdafx.h"
#include "Play.h"

Play::Play()
{
	//hDeive

}

Play::Play(int style)
	:style(style), intense(100)
{
}


Play::~Play()
{




}
UINT Play::ThreadFirst(LPVOID _mothod)
{



	return 0;
}

bool Play::midi(HMIDIOUT device, int status, int channel, int low, int high)
{
	// TODO: 여기에 구현 코드 추가.

	DWORD dwMsg = (status | channel | (high << 16) | (low << 8));
	midiOutShortMsg(device, dwMsg);
	return true;
}

bool Play::key(note* n) {

	//DWORD second, int pitch, int intense

	//if() sheet의 높은음 자리 일 경우
	//pitch = 70 - pitch / 2 - pitch % 2;
	note* temp = n;
	while (temp != nullptr) {
		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (clef == high)
				pitch = 88;
			else
				pitch = 65;
			break;
		case 4:
			if (clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (clef == high)
				pitch = 83;
			else
				pitch = 60;
			break;
		case 7:
			if (clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (clef == high)
				pitch = 76;
			else
				pitch = 53;
			break;
		case 11:
			if (clef == high)
				pitch = 74;
			else
				pitch = 52;
			break;
		case 12:
			if (clef == high)
				pitch = 72;
			else
				pitch = 50;
			break;
		case 13:
			if (clef == high)
				pitch = 71;
			else
				pitch = 48;
			break;
		case 14:
			if (clef == high)
				pitch = 69;
			else
				pitch = 47;
			break;
		case 15:
			if (clef == high)
				pitch = 67;
			else
				pitch = 45;
			break;
		case 16:
			if (clef == high)
				pitch = 65;
			else
				pitch = 43;
			break;
		case 17:
			if (clef == high)
				pitch = 64;
			else
				pitch = 41;
			break;
		case 18:
			if (clef == high)
				pitch = 62;
			else
				pitch = 40;
			break;
		case 19:
			if (clef == high)
				pitch = 60;
			else
				pitch = 38;
			break;
		case 20:
			if (clef == high)
				pitch = 59;
			else
				pitch = 36;
			break;
		case 21:
			if (clef == high)
				pitch = 57;
			else
				pitch = 35;
			break;
		case 22:
			if (clef == high)
				pitch = 55;
			else
				pitch = 33;
			break;
		case 23:
			if (clef == high)
				pitch = 54;
			else
				pitch = 31;
			break;
		case 24:
			if (clef == high)
				pitch = 52;
			else
				pitch = 29;
			break;
		case 25:
			if (clef == high)
				pitch = 50;
			else
				pitch = 27;
			break;
		default:
			break;
		}

		if (temp->condition_mark != -1) {
			if (temp->condition_mark == shap)
				pitch++;
			if (temp->condition_mark == flat)
				pitch--;
		}
		
		//if (signature != 0) {
		//	switch (signature) {
		//	case 1:
		//		if (pitch == 65 || pitch == 77 || pitch == 89)
		//			pitch++;
		//		break;
		//	case 2:
		//	case 3:
		//	case 4:
		//	case 5:
		//	case 6:
		//	case 7:
		//	case 8:
		//	case 9:
		//	case 10:
		//	case 11:
		//	case 12:
		//	case 13:
		//	case 14:
		//	}
		//}


		midi(this->hdevice, 0x90, 0, pitch, intense);



		temp = temp->next;
	}


	//pitch = 79 - pitch;


	//pitch += 41;
	//if() sheet의 낮음음 자리 일 경우
	int second = n->time * 50;

	
	MSG msg;

	DWORD t0, t1, diff;


	t0 = GetTickCount();

	while (TRUE) {

		t1 = GetTickCount();



		if (t0 <= t1)
			diff = t1 - t0;
		else
			diff = 0xFFFFFFFF - t0 + t1;

		if (diff > second)
			break;



		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {

			TranslateMessage(&msg);

			DispatchMessage(&msg);

		}

		Sleep(1);

	}


	temp = n;
	while (temp != nullptr) {
		
		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (clef == high)
				pitch = 88;
			else
				pitch = 66;
			break;
		case 4:
			if (clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (clef == high)
				pitch = 83;
			else
				pitch = 61;
			break;
		case 7:
			if (clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (clef == high)
				pitch = 76;
			else
				pitch = 54;
			break;
		case 11:
			if (clef == high)
				pitch = 74;
			else
				pitch = 53;
			break;
		case 12:
			if (clef == high)
				pitch = 72;
			else
				pitch = 51;
			break;
		case 13:
			if (clef == high)
				pitch = 71;
			else
				pitch = 50;
			break;
		case 14:
			if (clef == high)
				pitch = 69;
			else
				pitch = 48;
			break;
		case 15:
			if (clef == high)
				pitch = 67;
			else
				pitch = 46;
			break;
		case 16:
			if (clef == high)
				pitch = 65;
			else
				pitch = 44;
			break;
		case 17:
			if (clef == high)
				pitch = 64;
			else
				pitch = 43;
			break;
		case 18:
			if (clef == high)
				pitch = 62;
			else
				pitch = 41;
			break;
		case 19:
			if (clef == high)
				pitch = 60;
			else
				pitch = 39;
			break;
		case 20:
			if (clef == high)
				pitch = 59;
			else
				pitch = 39;
			break;
		case 21:
			if (clef == high)
				pitch = 57;
			else
				pitch = 39;
			break;
		case 22:
			if (clef == high)
				pitch = 55;
			else
				pitch = 39;
			break;
		case 23:
			if (clef == high)
				pitch = 54;
			else
				pitch = 39;
			break;
		case 24:
			if (clef == high)
				pitch = 52;
			else
				pitch = 39;
			break;
		case 25:
			if (clef == high)
				pitch = 50;
			else
				pitch = 39;
			break;
		default:
			break;
		}

		midi(this->hdevice, 0x80, 0, pitch, 0);



		temp = temp->next;
	}
	





	return false;


}

//
//bool Play::Wait(DWORD second){
//	midiOutOpen(&(this->hdevice), MIDIMAPPER, 0, 0, CALLBACK_NULL);
//		
//
//
//		second *= 1000;
//		MSG msg;
//
//		DWORD t0, t1, diff;
//		//init();
//
//		//node* firstnode = (*(this->first_nodes));
//
//		//element* firstelement = firstnode->first_element;
//
//		midi(this->hdevice, 0x90, 0, 60, 120);
//
//
//
//		t0 = GetTickCount();
//
//		while (TRUE) {
//
//			t1 = GetTickCount();
//
//
//
//			if (t0 <= t1)
//				diff = t1 - t0;
//			else
//				diff = 0xFFFFFFFF - t0 + t1;
//
//
//
//			if (diff > second) 
//				break;
//
//
//
//			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
//
//				TranslateMessage(&msg);
//
//				DispatchMessage(&msg);
//
//			}
//
//			Sleep(1);
//
//		}
//
//	
//		midi(this->hdevice, 0x80, 0, 60,0);
//
//		midiOutReset(this->hdevice);
//		midiOutClose(this->hdevice);
//
//
//	return false;
//}



void Play::music_play(Sheet* m_sheet)
{

	//for (int i = 0; i < style; i++) {
	//	f_node[i] = m_sheet->first_nodes[i];
	//}lee aram! 

	signature = m_sheet->signature;
	Sheet* f_sheet = m_sheet;
	node* f_node;

	initmidi();
	while (f_sheet != nullptr) {
		node** f_nodes = f_sheet->first_nodes;
		for (int i = 0; i < style; i++) {
			f_node = f_nodes[i];
			while (f_node != nullptr) {
				element* f_element = f_node->first_element;
				while (f_element != nullptr) {
					if (f_element->id == high)
						clef = high;
					if (f_element->id == low)
						clef = low;
					if (f_element->id >= f && f_element->id <= mp) {

					}
					if (f_element->id == n_note)
						key(f_element->first_note);
					if (f_element->id == r_rest)
						key(f_element->first_note);


					f_element = f_element->back_element;
				}
				f_node = f_node->back_node;
			}
		}
		f_sheet = f_sheet->back_Sheet;
	}


	Closemidi();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	// TODO: 여기에 구현 코드 추가.
}

bool Play::keyDown(note * n)
{
	note* temp = n;
	while (temp != nullptr) {
		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (clef == high)
				pitch = 88;
			else
				pitch = 65;
			break;
		case 4:
			if (clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (clef == high)
				pitch = 83;
			else
				pitch = 60;
			break;
		case 7:
			if (clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (clef == high)
				pitch = 76;
			else
				pitch = 53;
			break;
		case 11:
			if (clef == high)
				pitch = 74;
			else
				pitch = 52;
			break;
		case 12:
			if (clef == high)
				pitch = 72;
			else
				pitch = 50;
			break;
		case 13:
			if (clef == high)
				pitch = 71;
			else
				pitch = 48;
			break;
		case 14:
			if (clef == high)
				pitch = 69;
			else
				pitch = 47;
			break;
		case 15:
			if (clef == high)
				pitch = 67;
			else
				pitch = 45;
			break;
		case 16:
			if (clef == high)
				pitch = 65;
			else
				pitch = 43;
			break;
		case 17:
			if (clef == high)
				pitch = 64;
			else
				pitch = 41;
			break;
		case 18:
			if (clef == high)
				pitch = 62;
			else
				pitch = 40;
			break;
		case 19:
			if (clef == high)
				pitch = 60;
			else
				pitch = 38;
			break;
		case 20:
			if (clef == high)
				pitch = 59;
			else
				pitch = 36;
			break;
		case 21:
			if (clef == high)
				pitch = 57;
			else
				pitch = 35;
			break;
		case 22:
			if (clef == high)
				pitch = 55;
			else
				pitch = 33;
			break;
		case 23:
			if (clef == high)
				pitch = 54;
			else
				pitch = 31;
			break;
		case 24:
			if (clef == high)
				pitch = 52;
			else
				pitch = 29;
			break;
		case 25:
			if (clef == high)
				pitch = 50;
			else
				pitch = 27;
			break;
		default:
			break;
		}

		if (temp->condition_mark != -1) {
			if (temp->condition_mark == shap)
				pitch++;
			if (temp->condition_mark == flat)
				pitch--;
		}

		//if (signature != 0) {
		//	switch (signature) {
		//	case 1:
		//		if (pitch == 65 || pitch == 77 || pitch == 89)
		//			pitch++;
		//		break;
		//	case 2:
		//	case 3:
		//	case 4:
		//	case 5:
		//	case 6:
		//	case 7:
		//	case 8:
		//	case 9:
		//	case 10:
		//	case 11:
		//	case 12:
		//	case 13:
		//	case 14:
		//	}
		//}


		midi(this->hdevice, 0x90, 0, pitch, intense);



		temp = temp->next;
	}

	return true;
}

bool Play::keyUp(note* n)
{
	note* temp = n;
	while (temp != nullptr) {

		if (temp->sound == -1) {
			break;
		}
		int pitch = temp->sound;

		switch (pitch) {
		case 1:
			if (clef == high)
				pitch = 91;
			else
				pitch = 69;
			break;
		case 2:
			if (clef == high)
				pitch = 89;
			else
				pitch = 67;
			break;
		case 3:
			if (clef == high)
				pitch = 88;
			else
				pitch = 66;
			break;
		case 4:
			if (clef == high)
				pitch = 86;
			else
				pitch = 64;
			break;
		case 5:
			if (clef == high)
				pitch = 84;
			else
				pitch = 62;
			break;
		case 6:
			if (clef == high)
				pitch = 83;
			else
				pitch = 61;
			break;
		case 7:
			if (clef == high)
				pitch = 81;
			else
				pitch = 59;
			break;
		case 8:
			if (clef == high)
				pitch = 79;
			else
				pitch = 57;
			break;
		case 9:
			if (clef == high)
				pitch = 77;
			else
				pitch = 55;
			break;
		case 10:
			if (clef == high)
				pitch = 76;
			else
				pitch = 54;
			break;
		case 11:
			if (clef == high)
				pitch = 74;
			else
				pitch = 53;
			break;
		case 12:
			if (clef == high)
				pitch = 72;
			else
				pitch = 51;
			break;
		case 13:
			if (clef == high)
				pitch = 71;
			else
				pitch = 50;
			break;
		case 14:
			if (clef == high)
				pitch = 69;
			else
				pitch = 48;
			break;
		case 15:
			if (clef == high)
				pitch = 67;
			else
				pitch = 46;
			break;
		case 16:
			if (clef == high)
				pitch = 65;
			else
				pitch = 44;
			break;
		case 17:
			if (clef == high)
				pitch = 64;
			else
				pitch = 43;
			break;
		case 18:
			if (clef == high)
				pitch = 62;
			else
				pitch = 41;
			break;
		case 19:
			if (clef == high)
				pitch = 60;
			else
				pitch = 39;
			break;
		case 20:
			if (clef == high)
				pitch = 59;
			else
				pitch = 39;
			break;
		case 21:
			if (clef == high)
				pitch = 57;
			else
				pitch = 39;
			break;
		case 22:
			if (clef == high)
				pitch = 55;
			else
				pitch = 39;
			break;
		case 23:
			if (clef == high)
				pitch = 54;
			else
				pitch = 39;
			break;
		case 24:
			if (clef == high)
				pitch = 52;
			else
				pitch = 39;
			break;
		case 25:
			if (clef == high)
				pitch = 50;
			else
				pitch = 39;
			break;
		default:
			break;
		}

		midi(this->hdevice, 0x80, 0, pitch, 0);



		temp = temp->next;
	}

	return true;
}

void Play::Closemidi()
{
	midiOutReset(this->hdevice);
	midiOutClose(this->hdevice);

	// TODO: 여기에 구현 코드 추가.
}


void Play::initmidi()
{
	midiOutOpen(&(this->hdevice), MIDIMAPPER, 0, 0, CALLBACK_NULL);
	// TODO: 여기에 구현 코드 추가.
	return;
}

