#include "stdafx.h"
#include "note.h"

note::note()
{
}



note::~note()
{
}

note::note(CPoint location, int id, int forshow, int sound)
	:next(nullptr), location(location), id(id), forshow(forshow), sound(sound),
	highest(false), lowest(false), condition_dot(false), condition_mark(-1), time(0)
{


	switch (this->id) {
	case p_n_zero:
		condition_dot = true;
		this->id = n_zero;
		this->time += 16;
	case n_zero:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_NZERO1);
		}
		else {
			bitmap.LoadBitmapW(IDB_NZERO);
		}
		this->time += 32;
		break;
	case p_n_two:
		condition_dot = true;
		this->id = n_two;
		this->time += 8;
	case n_two:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_NTWO1);
		}
		else {
			bitmap.LoadBitmapW(IDB_NTWO);
		}
		this->time += 16;
		break;
	case p_n_four:
	case p_n_eight:
	case p_n_sixteen:
		if (this->id == p_n_four) {
			this->id = n_four;
			this->time += 4;
		}
		if (this->id == p_n_eight) {
			this->time += 2;
			this->id = n_eight;
		}
		if (this->id == p_n_sixteen) {
			this->id = n_sixteen;
			this->time += 1;
		}
		condition_dot = true;
	case n_sixteen:
	case n_eight:
	case n_four:
		if (this->id == n_four)
			this->time += 8;
		if (this->id == n_eight)
			this->time += 4;
		if (this->id == n_sixteen)
			this->time += 2;
		if (forshow) {
			bitmap.LoadBitmapW(IDB_NFOUR1);
		}
		else {
			bitmap.LoadBitmapW(IDB_NFOUR);
		}
		break;
	case p_r_zero:
		condition_dot = true;
		this->id = r_zero;
		this->time += 16;
	case r_zero:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_RZERO1);
		}
		else {
			bitmap.LoadBitmapW(IDB_RZERO);
		}
		this->time += 32;
		break;
	case p_r_two:
		condition_dot = true;
		this->id = r_two;
		this->time += 8;
	case r_two:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_RTWO1);
		}
		else {
			bitmap.LoadBitmapW(IDB_RTWO);
		}
		this->time += 16;
		break;
	case p_r_four:
		condition_dot = true;
		this->id = r_four;
		this->time += 4;
	case r_four:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_RFOUR1);
		}
		else {
			bitmap.LoadBitmapW(IDB_RFOUR);
		}
		this->time += 8;
		break;
	case p_r_eight:
		condition_dot = true;
		this->id = r_eight;
		this->time += 2;
	case r_eight:
		if (forshow) {
			bitmap.LoadBitmapW(IDB_REIGHT1);
		}
		else {
			bitmap.LoadBitmapW(IDB_REIGHT);
		}
		this->time += 4;
		break;
	}
	bitmap.GetBitmap(&bmp_info);

}

void note::paint(CDC & mem_dc)
{
	CDC dc;
	dc.CreateCompatibleDC(&mem_dc);
	dc.SelectObject(bitmap);

	if (id >= n_zero && id <= p_n_sixteen) {
		int count = 0;
		int sound_sum = 0;
		note* n = this;
		while (n != nullptr) {
			sound_sum += n->sound;
			count++;
			n = n->next;
		}
		int center = sound_sum / count;


		n = this;
		int temp = 0;
		while (n != nullptr) {
			//dc.DeleteDC();
			dc.SelectObject(n->bitmap);

			if (check_closenote(n->sound)) {
				// 겹치지 않도록 옆으로 밀리는 음표 머리 그리는 구문
				if (center <= 11) {
					mem_dc.TransparentBlt(n->location.x - n->bmp_info.bmWidth + 1, n->location.y,
						n->bmp_info.bmWidth, n->bmp_info.bmHeight, &dc,
						0, 0, n->bmp_info.bmWidth, n->bmp_info.bmHeight, RGB(255, 0, 255));
					if (n->condition_dot) {
						CBrush brush;
						brush.CreateSolidBrush(RGB(0, 0, 0));
						mem_dc.SelectObject(&brush);
						mem_dc.Ellipse(n->location.x, n->location.y - 2,
							n->location.x + 4, n->location.y + 2);
						//mem_dc.Detach();
					}
					if (n->condition_mark != -1) {
						CDC mark_dc;
						CBitmap mark_bitmap;
						BITMAP mark_bmpinfo;
						int adjustment;
						mark_dc.CreateCompatibleDC(&mem_dc);
						switch (n->condition_mark) {
						case shap:
							mark_bitmap.LoadBitmapW(IDB_SHAP);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = -6;
							break;
						case flat:
							mark_bitmap.LoadBitmapW(IDB_FLAT);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = 7 - mark_bmpinfo.bmHeight;
							break;
						case natural:
							mark_bitmap.LoadBitmapW(IDB_NATURAL);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = -6;
							break;
						}
						mark_dc.SelectObject(&mark_bitmap);
						mem_dc.TransparentBlt(n->location.x - n->bmp_info.bmWidth + 1 - mark_bmpinfo.bmWidth - 2, n->location.y + adjustment,
							mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, &mark_dc, 0, 0, mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, RGB(255, 0, 255));
					}
				}
				else {
					mem_dc.TransparentBlt(n->location.x + n->bmp_info.bmWidth - 1, n->location.y,
						n->bmp_info.bmWidth, n->bmp_info.bmHeight, &dc,
						0, 0, n->bmp_info.bmWidth, n->bmp_info.bmHeight, RGB(255, 0, 255));
					if (n->condition_dot) {
						CBrush brush;
						brush.CreateSolidBrush(RGB(0, 0, 0));
						mem_dc.SelectObject(&brush);
						mem_dc.Ellipse(n->location.x + n->bmp_info.bmWidth * 2 - 1, n->location.y - 2,
							n->location.x + n->bmp_info.bmWidth * 2 - 1 + 4, n->location.y + 2);
						//mem_dc.Detach();
					}
					if (n->condition_mark != -1) {
						CDC mark_dc;
						CBitmap mark_bitmap;
						BITMAP mark_bmpinfo;
						int adjustment;
						mark_dc.CreateCompatibleDC(&mem_dc);
						switch (n->condition_mark) {
						case shap:
							mark_bitmap.LoadBitmapW(IDB_SHAP);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = -6;
							break;
						case flat:
							mark_bitmap.LoadBitmapW(IDB_FLAT);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = 7 - mark_bmpinfo.bmHeight;
							break;
						case natural:
							mark_bitmap.LoadBitmapW(IDB_NATURAL);
							mark_bitmap.GetBitmap(&mark_bmpinfo);
							adjustment = -6;
							break;
						}
						mark_dc.SelectObject(&mark_bitmap);
						mem_dc.TransparentBlt(n->location.x - mark_bmpinfo.bmWidth - 2, n->location.y + adjustment,
							mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, &mark_dc, 0, 0, mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, RGB(255, 0, 255));
					}
				}
			}
			else {
				// 기본상태의 음표머리 그리는 구문
				mem_dc.TransparentBlt(n->location.x, n->location.y,
					n->bmp_info.bmWidth, n->bmp_info.bmHeight, &dc,
					0, 0, n->bmp_info.bmWidth, n->bmp_info.bmHeight, RGB(255, 0, 255));
				if (n->condition_dot) {
					CBrush brush;
					brush.CreateSolidBrush(RGB(0, 0, 0));
					mem_dc.SelectObject(&brush);
					mem_dc.Ellipse(n->location.x + n->bmp_info.bmWidth, n->location.y - 2,
						n->location.x + n->bmp_info.bmWidth + 4, n->location.y + 2);
					//mem_dc.Detach();
				}
				if (n->condition_mark != -1) {
					CDC mark_dc;
					CBitmap mark_bitmap;
					BITMAP mark_bmpinfo;
					int adjustment;
					mark_dc.CreateCompatibleDC(&mem_dc);
					switch (n->condition_mark) {
					case shap:
						mark_bitmap.LoadBitmapW(IDB_SHAP);
						mark_bitmap.GetBitmap(&mark_bmpinfo);
						adjustment = -6;
						break;
					case flat:
						mark_bitmap.LoadBitmapW(IDB_FLAT);
						mark_bitmap.GetBitmap(&mark_bmpinfo);
						adjustment = 7 - mark_bmpinfo.bmHeight;
						break;
					case natural:
						mark_bitmap.LoadBitmapW(IDB_NATURAL);
						mark_bitmap.GetBitmap(&mark_bmpinfo);
						adjustment = -6;
						break;
					}
					mark_dc.SelectObject(&mark_bitmap);
					mem_dc.TransparentBlt(n->location.x - mark_bmpinfo.bmWidth - 2, n->location.y + adjustment,
						mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, &mark_dc, 0, 0, mark_bmpinfo.bmWidth, mark_bmpinfo.bmHeight, RGB(255, 0, 255));
				}
				// 보조줄 그리는 구문
				temp = 0;
				if (n->sound % 2) {
					while (n->sound + temp < 8) {
						mem_dc.MoveTo(n->location.x - 2, n->location.y + 3 + (temp / 2) * 8);
						mem_dc.LineTo(n->location.x + 15, n->location.y + 3 + (temp / 2) * 8);
						temp += 2;
					}
					while (n->sound + temp > 18) {
						mem_dc.MoveTo(n->location.x - 2, n->location.y + 3 + (temp / 2) * 8);
						mem_dc.LineTo(n->location.x + 15, n->location.y + 3 + (temp / 2) * 8);
						temp -= 2;
					}
				}
				else {
					while (n->sound + temp < 8) {
						mem_dc.MoveTo(n->location.x - 2, n->location.y + 7 + (temp / 2) * 8);
						mem_dc.LineTo(n->location.x + 15, n->location.y + 7 + (temp / 2) * 8);
						temp += 2;
					}
					while (n->sound + temp > 18) {
						mem_dc.MoveTo(n->location.x - 2, n->location.y - 1 + (temp / 2) * 8);
						mem_dc.LineTo(n->location.x + 15, n->location.y - 1 + (temp / 2) * 8);
						temp -= 2;
					}
				}
			}
			// 막대 및 꼬리 그리는 구문
			switch (id) {
			case n_sixteen:
			case n_eight:
			case n_two:
			case n_four:
				if (center > 11) {
					if (n->highest) {
						CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
						if (forshow) {
							mem_dc.SelectObject(&pen);
						}
						mem_dc.MoveTo(n->location.x + 9, n->location.y + 2);
						mem_dc.LineTo(n->location.x + 9, n->location.y + 2 - 8 * 4);
						mem_dc.SelectStockObject(BLACK_PEN);
						if (n->id == n_eight || n->id == n_sixteen) {
							CBitmap t_bitmap;
							BITMAP t_bmp_info;
							if (n->id == n_eight)
								if (forshow) {
									t_bitmap.LoadBitmapW(IDB_TAIL11);
								}
								else
									t_bitmap.LoadBitmapW(IDB_TAIL1);
							else
								if (forshow) {
									t_bitmap.LoadBitmapW(IDB_TAIL21);
								}
								else
									t_bitmap.LoadBitmapW(IDB_TAIL2);
							t_bitmap.GetBitmap(&t_bmp_info);
							CDC t_dc;
							t_dc.CreateCompatibleDC(&mem_dc);
							t_dc.SelectObject(t_bitmap);
							mem_dc.TransparentBlt(n->location.x + 9, n->location.y + 2 - 8 * 4,
								t_bmp_info.bmWidth, t_bmp_info.bmHeight, &t_dc,
								0, 0, t_bmp_info.bmWidth, t_bmp_info.bmHeight, RGB(255, 0, 255));
						}
					}
					if (n->next != nullptr) {
						CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
						if (forshow) {
							mem_dc.SelectObject(&pen);
						}
						mem_dc.MoveTo(n->location.x + 9, n->location.y + 2);
						mem_dc.LineTo(n->next->location.x + 9, n->next->location.y + 2);
						mem_dc.SelectStockObject(BLACK_PEN);
					}
				}
				else {
					if (n->lowest) {
						CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
						if (forshow) {
							mem_dc.SelectObject(&pen);
						}
						mem_dc.MoveTo(n->location.x, n->location.y + 3);
						mem_dc.LineTo(n->location.x, n->location.y + 8 * 4);
						mem_dc.SelectStockObject(BLACK_PEN);
						if (n->id == n_eight || n->id == n_sixteen) {
							CBitmap t_bitmap;
							BITMAP t_bmp_info;
							if (n->id == n_eight)
								if (forshow) {
									t_bitmap.LoadBitmapW(IDB_TAILR11);
								}
								else
									t_bitmap.LoadBitmapW(IDB_TAILR1);
							else
								if (forshow) {
									t_bitmap.LoadBitmapW(IDB_TAILR21);
								}
								else
									t_bitmap.LoadBitmapW(IDB_TAILR2);
							t_bitmap.GetBitmap(&t_bmp_info);
							CDC t_dc;
							t_dc.CreateCompatibleDC(&mem_dc);
							t_dc.SelectObject(t_bitmap);
							mem_dc.TransparentBlt(n->location.x, n->location.y + 8 * 4 - t_bmp_info.bmHeight,
								t_bmp_info.bmWidth, t_bmp_info.bmHeight, &t_dc,
								0, 0, t_bmp_info.bmWidth, t_bmp_info.bmHeight, RGB(255, 0, 255));
						}
					}
					if (n->next != nullptr) {
						CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
						if (forshow) {
							mem_dc.SelectObject(&pen);
						}
						mem_dc.MoveTo(n->location.x, n->location.y + 3);
						mem_dc.LineTo(n->next->location.x, n->next->location.y + 3);
						mem_dc.SelectStockObject(BLACK_PEN);
					}
				}
				break;
			}

			n = n->next;
		}
	}
	if (id >= r_zero && id <= p_r_eight) {
		mem_dc.TransparentBlt(location.x, location.y,
			bmp_info.bmWidth, bmp_info.bmHeight, &dc,
			0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));
		if (condition_dot) {
			CBrush brush;
			brush.CreateSolidBrush(RGB(0, 0, 0));
			mem_dc.SelectObject(&brush);
			mem_dc.Ellipse(location.x + bmp_info.bmWidth, location.y + 2,
				location.x + bmp_info.bmWidth + 4, location.y + 6);
		}
	}

}



void note::notforshow()
{
	forshow = false;
	bitmap.DeleteObject();
	switch (id) {
	case n_zero:
		bitmap.LoadBitmapW(IDB_NZERO);
		break;
	case n_two:
		bitmap.LoadBitmapW(IDB_NTWO);
		break;
	case n_four:
	case n_eight:
	case n_sixteen:
		bitmap.LoadBitmapW(IDB_NFOUR);
		break;
	case r_zero:
		bitmap.LoadBitmapW(IDB_RZERO);
		break;
	case r_two:
		bitmap.LoadBitmapW(IDB_RTWO);
		break;
	case r_four:
		bitmap.LoadBitmapW(IDB_RFOUR);
		break;
	case r_eight:
		bitmap.LoadBitmapW(IDB_REIGHT);
		break;
	}
}

bool note::check_closenote(int sound)
{

	note* n = this;
	while (n != nullptr) {
		if (sound - n->sound == 1 || n->sound - sound == 1) {
			if (sound % 2) {
				return true;
			}
		}
		n = n->next;
	}

	return false;
}

void note::check_highest()
{
	int high_temp = sound;
	int low_temp = sound;
	note* n = this;
	while (n != nullptr) {
		if (n->sound < high_temp) {
			n->highest = true;
			high_temp = n->sound;
			n = this;
		}
		else {
			if (n->sound == high_temp) {
				n->highest = true;
				n = n->next;
			}
			else {
				n->highest = false;
				n = n->next;
			}
		}
	}
	n = this;
	while (n != nullptr) {
		if (n->sound > low_temp) {
			n->lowest = true;
			low_temp = n->sound;
			n = this;
		}
		else {
			if (n->sound == low_temp) {
				n->lowest = true;
				n = n->next;
			}
			else {
				n->lowest = false;
				n = n->next;
			}
		}
	}
}
