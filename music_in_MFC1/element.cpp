#include "stdafx.h"
#include "element.h"


element::element()
{
}


element::element(CPoint location, int id, bool forshow)
	:location(location), id(id), front_element(nullptr), back_element(nullptr), first_note(nullptr), forshow(forshow)
{
	switch (id) {
	case n_zero:
	case n_two:
	case n_four:
	case n_eight:
	case n_sixteen:
	case p_n_zero:
	case p_n_two:
	case p_n_four:
	case p_n_eight:
	case p_n_sixteen:
	case r_zero:
	case r_two:
	case r_four:
	case r_eight:
	case p_r_zero:
	case p_r_two:
	case p_r_four:
	case p_r_eight:
		bitmap.LoadBitmapW(IDB_NZERO);
		bitmap.GetBitmap(&bmp_info);
		break;
	case high:
		bitmap.LoadBitmapW(IDB_HIGH);
		bitmap.GetBitmap(&bmp_info);
		break;
	case low:
		bitmap.LoadBitmapW(IDB_LOW);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_128:
		bitmap.LoadBitmapW(IDB_B128);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_24:
		bitmap.LoadBitmapW(IDB_B24);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_34:
		bitmap.LoadBitmapW(IDB_B34);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_38:
		bitmap.LoadBitmapW(IDB_B38);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_44:
		bitmap.LoadBitmapW(IDB_B44);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_54:
		bitmap.LoadBitmapW(IDB_B54);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_64:
		bitmap.LoadBitmapW(IDB_B64);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_68:
		bitmap.LoadBitmapW(IDB_B68);
		bitmap.GetBitmap(&bmp_info);
		break;
	case b_98:
		bitmap.LoadBitmapW(IDB_B98);
		bitmap.GetBitmap(&bmp_info);
		break;
	case shap:
		bitmap.LoadBitmapW(IDB_SHAP);
		bitmap.GetBitmap(&bmp_info);
		break;
	case flat:
		bitmap.LoadBitmapW(IDB_FLAT);
		bitmap.GetBitmap(&bmp_info);
		break;
	case f:
		bitmap.LoadBitmapW(IDB_f);
		bitmap.GetBitmap(&bmp_info);
		break;
	case ff:
		bitmap.LoadBitmapW(IDB_ff);
		bitmap.GetBitmap(&bmp_info);
		break;
	case fff:
		bitmap.LoadBitmapW(IDB_fff);
		bitmap.GetBitmap(&bmp_info);
		break;
	case mf:
		bitmap.LoadBitmapW(IDB_mf);
		bitmap.GetBitmap(&bmp_info);
		break;
	case mp:
		bitmap.LoadBitmapW(IDB_mp);
		bitmap.GetBitmap(&bmp_info);
		break;
	case p:
		bitmap.LoadBitmapW(IDB_p);
		bitmap.GetBitmap(&bmp_info);
		break;
	case pp:
		bitmap.LoadBitmapW(IDB_pp);
		bitmap.GetBitmap(&bmp_info);
		break;
	case ppp:
		bitmap.LoadBitmapW(IDB_ppp);
		bitmap.GetBitmap(&bmp_info);
		break;
	}
//	rect.SetRect(location.x, location.y, location.x + bmp_info.bmWidth, location.y + bmp_info.bmHeight);
}

element::~element()
{
	
}


void element::paint(CDC & mem_dc)
{
	//CDC dc;
	//dc.CreateCompatibleDC(&mem_dc);
	//dc.SelectObject(bitmap);
	//mem_dc.TransparentBlt(location.x, location.y,
	//	bmp_info.bmWidth, bmp_info.bmHeight, &dc,
	//	0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));


	if (id == high) {
		CDC dc;
		dc.CreateCompatibleDC(&mem_dc);
		dc.SelectObject(bitmap);
		mem_dc.TransparentBlt(location.x, location.y + 8 * 4, bmp_info.bmWidth, bmp_info.bmHeight,
			&dc, 0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));
	}
	if (id == low) {
		CDC dc;
		dc.CreateCompatibleDC(&mem_dc);
		dc.SelectObject(bitmap);
		mem_dc.TransparentBlt(location.x, location.y + 8 * 5 +3, bmp_info.bmWidth, bmp_info.bmHeight,
			&dc, 0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));
	}
	if (id >= b_24 && id <= b_128) {
		CDC dc;
		dc.CreateCompatibleDC(&mem_dc);
		dc.SelectObject(bitmap);
		mem_dc.TransparentBlt(location.x, location.y + 8 * 5+1, bmp_info.bmWidth, bmp_info.bmHeight,
			&dc, 0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));
	}
	if (id == shap || id == flat) {
		CDC dc;
		dc.CreateCompatibleDC(&mem_dc);
		dc.SelectObject(bitmap);
		mem_dc.TransparentBlt(location.x, location.y, bmp_info.bmWidth, bmp_info.bmHeight,
			&dc, 0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));

	}
	if (id >= f && id <= mp) {
		CDC dc;
		dc.CreateCompatibleDC(&mem_dc);
		dc.SelectObject(bitmap);
		mem_dc.TransparentBlt(location.x, location.y, bmp_info.bmWidth, bmp_info.bmHeight,
			&dc, 0, 0, bmp_info.bmWidth, bmp_info.bmHeight, RGB(255, 0, 255));
	}

	if (id == n_note || id == r_rest) {
		if (first_note != nullptr) {
			first_note->paint(mem_dc);
		}
	}


	/*note* temp = first_note;
	while (temp != nullptr) {
		temp->paint(mem_dc);
		temp = temp->next;
	}*/

}
bool element::addNote(int y, int id, int forshow)
{
	if(id>=n_zero && id<=p_n_sixteen) {
		int node_height = node_rect.top;
		if (y - node_height >= 113)
			return false;
		int height = note_height[y - node_height];

		if (height == 1) {
			return false;
		}
		else {
			if (height % 2) {
				while (note_height[y - node_height] == height) {
					y--;
				}
			}
			else {
				while (note_height[y - node_height] == height) {
					y--;
				}
				y++;
			}
		}

		note* n = first_note;

		if (n == nullptr) {
			first_note = new note(CPoint(location.x, y), id, forshow, height);
		}
		else {
			while (1) {
				if (n->location.y == y) {
					return false;
				}
				if (n->next == nullptr) {
					n->next = new note(CPoint(location.x, y), id, forshow, height);
					break;
				}
				else {
					n = n->next;
				}
			}
		}

		first_note->check_highest();
	}
	if(id >= r_zero && id <= p_r_eight) {
		int height = -1;
		y = location.y + 8 * 6;

		note* n = first_note;
		if (n == nullptr) {

			first_note = new note(CPoint(location.x, y), id, forshow, height);
		}

	}

	switch (id) {
	case p_n_zero: 
	case p_n_two:
	case p_n_four:
	case p_n_eight:
	case p_n_sixteen:
	case n_zero:
	case n_two:
	case n_four:
	case n_eight:
	case n_sixteen:
		this->id = n_note;
		break;
	case r_zero:
	case r_two:
	case r_four:
	case r_eight:
	case p_r_zero:
	case p_r_two:
	case p_r_four:
	case p_r_eight:
		this->id = r_rest;
		break;
	}
	
	return true;
}

void element::deleteNote()
{
	note* e = first_note;


	if (first_note != nullptr) {
		if (e->next == nullptr) {
			first_note = nullptr;
		}
		else {
			while (e->next->next != nullptr) {
				e = e->next;
			}
			e->next = nullptr;
		}
	}
	if (first_note != nullptr)
		first_note->check_highest();
}

void element::init(CRect node_rect)
{
	if (id >= n_zero && id <= p_n_sixteen) {
		this->node_rect = node_rect;
		location.y = node_rect.top;
		rect.SetRect(location.x - 2, node_rect.top, location.x + bmp_info.bmWidth + 2, node_rect.bottom);
	}
	if (id >= r_zero && id <= p_r_eight) {
		this->node_rect = node_rect;
		location.y = node_rect.top;
		rect.SetRect(location.x - 2, node_rect.top, location.x + bmp_info.bmWidth + 2, node_rect.bottom);
	}
	if (id == high || id == low) {
		this->node_rect = node_rect;
		location.y = node_rect.top;
		rect.SetRect(location.x, node_rect.top, location.x + bmp_info.bmWidth, node_rect.bottom);
	}
	if (id >= b_24 && id <= b_128) {
		this->node_rect = node_rect;
		location.y = node_rect.top;
		rect.SetRect(location.x, node_rect.top, location.x + bmp_info.bmWidth, node_rect.bottom);
	}
	if (id >= f && id <= mp) {
		this->node_rect = node_rect;
		location.y = node_rect.top;
		rect.SetRect(location.x, node_rect.top, location.x + bmp_info.bmWidth, node_rect.bottom);
	}

}

void element::notforshow()
{
	forshow = false;
	note* n = first_note;
	while (n != nullptr) {
		n->notforshow();
		n = n->next;
	}
}

note * element::getnote(CPoint pt)
{
	int y = pt.y;
	int node_height = node_rect.top;
	int height = note_height[y - node_height];

	if (height == 1) {
		return false;
	}
	else {
		if (height % 2) {
			while (note_height[y - node_height] == height) {
				y--;
			}
		}
		else {
			while (note_height[y - node_height] == height) {
				y--;
			}
			y++;
		}
	}

	note* n = first_note;

	if (n == nullptr) {
		return nullptr;
	}
	else {
		while (1) {
			if (n->location.y == y) {
				return n;
			}
			if (n->next == nullptr) {
				return nullptr;
			}
			else {
				n = n->next;
			}
		}
	}
	return nullptr;
}
