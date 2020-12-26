#include "stdafx.h"
#include "Sheet.h"


Sheet::Sheet()
{
}


Sheet::~Sheet()
{
}



Sheet::Sheet(int style,int time, int signature)
	:style(style),signature(signature), back_Sheet(nullptr),front_Sheet(nullptr),Sheet_name(_T("")),composer(_T(""))
{
	bmp_score.LoadBitmapW(IDB_SCORE);
	bmp_score.GetBitmap(&bmpinfo_score);
	used_space = 74;

	first_nodes = new node*[style];
	for (int i = 0; i < style; i++) {
		int x_used=0;
		CRect* temp;
		temp = new CRect();
		temp->SetRect(89, used_space, bmpinfo_score.bmWidth-89, used_space + bmpinfo_score.bmHeight);
		first_nodes[i] = new node(CPoint(0, used_space), temp, nullptr, nullptr);
		first_nodes[i]->first_node = true;
		used_space += bmpinfo_score.bmHeight;
		first_nodes[i]->addElement(CPoint(90, used_space - 10), new element(CPoint(90, used_space - 10), high, false));
		x_used += 90 + first_nodes[i]->first_element->bmp_info.bmWidth+1;

		switch (signature) {
		case 7:
			first_nodes[i]->addElement(CPoint(x_used+8*6, first_nodes[i]->location.y + 8 * 6 - 1),
				new element(CPoint(x_used + 8 * 6 + 1, first_nodes[i]->location.y + 8 * 6 - 1), shap, false));
		case 6:
			first_nodes[i]->addElement(CPoint(x_used + first_nodes[i]->location.y + 8 * 4 + 3),
				new element(CPoint(x_used + 8 * 5 + 1, first_nodes[i]->location.y + 8 * 4 + 3), shap, false));
		case 5:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 4, first_nodes[i]->location.y + 8 * 6 + 3),
				new element(CPoint(x_used + 8 * 4 + 1, first_nodes[i]->location.y + 8 * 6 + 3), shap, false));
		case 4:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 3 , first_nodes[i]->location.y + 8 * 5 - 1),
				new element(CPoint(x_used + 8 * 3 + 1, first_nodes[i]->location.y + 8 * 5 - 1), shap, false));
		case 3:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 2 , first_nodes[i]->location.y + 8 * 3 + 3),
				new element(CPoint(x_used + 8 * 2 + 1, first_nodes[i]->location.y + 8 * 3 + 3), shap, false));
		case 2:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 1, first_nodes[i]->location.y + 8 * 5 + 3),
				new element(CPoint(x_used + 8 * 1+1, first_nodes[i]->location.y + 8 * 5 + 3), shap, false));
		case 1:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 0, first_nodes[i]->location.y + 8*4-1),
				new element(CPoint(x_used + 8 * 0+1, first_nodes[i]->location.y + 8 * 4-1), shap, false));
			x_used += signature * 8;
			break;
		case 14:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 6, first_nodes[i]->location.y + 8 * 7 - 2),
				new element(CPoint(x_used + 8 * 6 + 2, first_nodes[i]->location.y + 8 * 7 - 2), flat, false));
		case 13:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 5, first_nodes[i]->location.y + 8 * 5 - 2),
				new element(CPoint(x_used + 8 * 5 + 1, first_nodes[i]->location.y + 8 * 5 - 2), flat, false));
		case 12:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 4, first_nodes[i]->location.y + 8 * 7 - 5),
				new element(CPoint(x_used + 8 * 4 + 1, first_nodes[i]->location.y + 8 * 7 - 5), flat, false));
		case 11:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 3, first_nodes[i]->location.y + 8 * 5 - 5),
				new element(CPoint(x_used + 8 * 3 + 1, first_nodes[i]->location.y + 8 * 5 - 5), flat, false));
		case 10:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 2, first_nodes[i]->location.y + 8 * 6 - 2),
				new element(CPoint(x_used + 8 * 2 + 2, first_nodes[i]->location.y + 8 * 6 - 2), flat, false));
		case 9:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 1, first_nodes[i]->location.y + 8 * 4 - 2),
				new element(CPoint(x_used + 8 * 1+1, first_nodes[i]->location.y + 8 * 4 - 2), flat, false));
		case 8:
			first_nodes[i]->addElement(CPoint(x_used + 8 * 0, first_nodes[i]->location.y + 8 * 6 - 5),
				new element(CPoint(x_used + 8 * 0+1, first_nodes[i]->location.y + 8 * 6 - 5), flat, false));
			x_used += (signature - 7) * 8;
			break;
		default:
			break;

		}
		x_used += 3;
		first_nodes[i]->addElement(CPoint(x_used, used_space - 10),
			new element(CPoint(x_used , used_space - 10), time, false));

	}
	

	updateTime();
}


bool Sheet::new_node()
{
	CRect temp;
	temp.SetRect(89, used_space, bmpinfo_score.bmWidth-89, used_space + bmpinfo_score.bmHeight);
	if (used_space + bmpinfo_score.bmHeight*style >= 1754) {
		//back_Sheet = new Sheet(style, signature);
		//back_Sheet->front_Sheet = this;
		return false;
	}
	else {
		//temp.SetRect(0, used_space, bmpinfo_score.bmWidth, used_space + bmpinfo_score.bmHeight);
		for (int i = 0; i < style; i++) {
			int x_used = 0;
			node* last_node = first_nodes[i];
			while (last_node->back_node != nullptr) {
				last_node = last_node->back_node;
			}
			CRect* temp;
			temp = new CRect();
			temp->SetRect(89, used_space, bmpinfo_score.bmWidth-89, used_space + bmpinfo_score.bmHeight);
			node* temp_node = new node(CPoint(0, used_space), temp, last_node, nullptr);
			temp_node->first_node = true;
			last_node->back_node = temp_node;
			used_space += bmpinfo_score.bmHeight;
			temp_node->addElement(CPoint(90, used_space - 10), new element(CPoint(90, used_space - 10), high, false));
			x_used += 90 + temp_node->first_element->bmp_info.bmWidth + 1;

			switch (signature) {
			case 7:
				temp_node->addElement(CPoint(x_used + 8 * 6, temp_node->location.y + 8 * 6 - 1),
					new element(CPoint(x_used + 8 * 6 + 1, temp_node->location.y + 8 * 6 - 1), shap, false));
			case 6:
				temp_node->addElement(CPoint(x_used + temp_node->location.y + 8 * 4 + 3),
					new element(CPoint(x_used + 8 * 5 + 1, temp_node->location.y + 8 * 4 + 3), shap, false));
			case 5:
				temp_node->addElement(CPoint(x_used + 8 * 4, temp_node->location.y + 8 * 6 + 3),
					new element(CPoint(x_used + 8 * 4 + 1, temp_node->location.y + 8 * 6 + 3), shap, false));
			case 4:
				temp_node->addElement(CPoint(x_used + 8 * 3, temp_node->location.y + 8 * 5 - 1),
					new element(CPoint(x_used + 8 * 3 + 1, temp_node->location.y + 8 * 5 - 1), shap, false));
			case 3:
				temp_node->addElement(CPoint(x_used + 8 * 2, temp_node->location.y + 8 * 3 + 3),
					new element(CPoint(x_used + 8 * 2 + 1, temp_node->location.y + 8 * 3 + 3), shap, false));
			case 2:
				temp_node->addElement(CPoint(x_used + 8 * 1, temp_node->location.y + 8 * 5 + 3),
					new element(CPoint(x_used + 8 * 1 + 1, temp_node->location.y + 8 * 5 + 3), shap, false));
			case 1:
				temp_node->addElement(CPoint(x_used + 8 * 0, temp_node->location.y + 8 * 4 - 1),
					new element(CPoint(x_used + 8 * 0 + 1, temp_node->location.y + 8 * 4 - 1), shap, false));
				x_used += signature * 8;
				break;
			case 14:
				temp_node->addElement(CPoint(x_used + 8 * 6, temp_node->location.y + 8 * 7 - 2),
					new element(CPoint(x_used + 8 * 6 + 2, temp_node->location.y + 8 * 7 - 2), flat, false));
			case 13:
				temp_node->addElement(CPoint(x_used + 8 * 5, temp_node->location.y + 8 * 5 - 2),
					new element(CPoint(x_used + 8 * 5 + 1, temp_node->location.y + 8 * 5 - 2), flat, false));
			case 12:
				temp_node->addElement(CPoint(x_used + 8 * 4, temp_node->location.y + 8 * 7 - 5),
					new element(CPoint(x_used + 8 * 4 + 1, temp_node->location.y + 8 * 7 - 5), flat, false));
			case 11:
				temp_node->addElement(CPoint(x_used + 8 * 3, temp_node->location.y + 8 * 5 - 5),
					new element(CPoint(x_used + 8 * 3 + 1, temp_node->location.y + 8 * 5 - 5), flat, false));
			case 10:
				temp_node->addElement(CPoint(x_used + 8 * 2, temp_node->location.y + 8 * 6 - 2),
					new element(CPoint(x_used + 8 * 2 + 2, temp_node->location.y + 8 * 6 - 2), flat, false));
			case 9:
				temp_node->addElement(CPoint(x_used + 8 * 1, temp_node->location.y + 8 * 4 - 2),
					new element(CPoint(x_used + 8 * 1 + 1, temp_node->location.y + 8 * 4 - 2), flat, false));
			case 8:
				temp_node->addElement(CPoint(x_used + 8 * 0, temp_node->location.y + 8 * 6 - 5),
					new element(CPoint(x_used + 8 * 0 + 1, temp_node->location.y + 8 * 6 - 5), flat, false));
				x_used += (signature - 7) * 8;
				break;
			default:
				break;

			}
		}

	}
	updateTime();
}



element* Sheet::getElement(CPoint pt)
{

	bool found = false;
	node *n;
	for (int i = 0; i < style; i++) {
		n = first_nodes[i];
		while (n != nullptr) {
			if (n->rect->PtInRect(pt)) {
				found = true;
				break;

			}
			
			n = n->back_node;
		}
		if (found) {
			break;
		}
	}
	if (found) {
		return n->getElement(pt);
	}
	else {
		return nullptr;
	}
}

node * Sheet::getNode(CPoint pt)
{
	bool found = false;
	node *n;
	for (int i = 0; i < style; i++) {
		n = first_nodes[i];
		while (n != nullptr) {
			if (n->rect->PtInRect(pt)) {
				found = true;
				break;

			}

			n = n->back_node;
		}
		if (found) {
			break;
		}
	}
	if (found) {
		return n;
	}
	else {
		return nullptr;
	}
}

bool Sheet::addElement(CPoint pt, element * e)
{
	bool found = false;
	node *n;
	for (int i = 0; i < style; i++) {
		n = first_nodes[i];
		while (n != nullptr) {
			if (n->rect->PtInRect(pt)) {
				found = true;
				break;
			}
			n = n->back_node;
		}
		if (found)
			break;
	}
	if (found) {
		n->addElement(pt, e);
	}
	else {
		return false;
	}
}

bool Sheet::deleteElement(CPoint pt)
{
	bool found = false;
	node *n;
	for (int i = 0; i < style; i++) {
		n = first_nodes[i];
		while (n != nullptr) {
			if (n->rect->PtInRect(pt)) {
				found = true;
				break;
			}
			n = n->back_node;
		}
		if (found)
			break;
	}
	if (found) {
		return n->deleteElement(pt);
	}
	else {
		return false;
	}
	

}

bool Sheet::split(CPoint pt, bool forshow)
{
	node* n = getNode(pt);
	if (n == nullptr) {
		return false;
	}

	element* e1 = n->first_element;
	element* e2 = nullptr;
	while (e1 != nullptr) {
		if (e1->location.x >= pt.x) {
			break;
		}
		e2 = e1;
		e1 = e1->back_element;
	}
	node* temp = n->back_node;

	n->back_node = new node(CPoint(pt.x + 11, n->rect->top), new CRect(pt.x + 11, n->rect->top, n->rect->right, n->rect->bottom), n, temp);
	//n->back_node->forshow = forshow;
	n->back_node->front_node = n;
	n->back_node->back_node = temp;
	if (temp != nullptr) {

		temp->front_node = n->back_node;
	}
	//n->back_node->s_rect=new CRect(n->rect->bottom-2)
	if (e2 != nullptr) {
		e2->back_element = nullptr;
	}
	else {
		n->first_element = nullptr;
	}
	if (e1 != nullptr) {
		e1->front_element = nullptr;
	}
	n->back_node->first_element = e1;
	if (n->s_rect != nullptr) {
		n->back_node->s_rect = n->s_rect;
		n->back_node->forshow = n->forshow;
	}
	n->rect->SetRect(n->location.x, n->rect->top, pt.x + 10, n->rect->bottom);
	n->s_rect = new CRect(pt.x - 10, n->rect->top, pt.x + 10, n->rect->bottom);

	n->forshow = forshow;

	updateTime();
	return true;
}

bool Sheet::unsplit(CPoint pt)
{
	node* n = getNode(pt);
	if (n == nullptr)
		return false;
	if (n->s_rect == nullptr)
		return false;
	if (n->s_rect->PtInRect(pt)) {
		element* e = n->first_element;
		if (e != nullptr) {
			while (e->back_element != nullptr)
				e = e->back_element;

			e->back_element = n->back_node->first_element;
			if (e->back_element != nullptr)
				e->back_element->front_element = e;

			n->back_node->first_element = nullptr;
		}
		else {
			if (n->back_node->first_element != nullptr) {
				n->first_element = n->back_node->first_element;
			}
		}
		n->rect->SetRect(n->rect->left, n->rect->top, n->back_node->rect->right, n->rect->bottom);

		node* temp_node = n->back_node;
		CRect* temp_rect = n->s_rect;
		if (temp_node != nullptr) {
			n->forshow = temp_node->forshow;
		}


		if (n->back_node->s_rect != nullptr) {
			n->s_rect = n->back_node->s_rect;
		}
		else {
			n->s_rect = nullptr;
		}

		if (n->back_node->back_node != nullptr) {
			n->back_node->back_node->front_node = n;
			n->back_node = n->back_node->back_node;
		}
		else {
			n->back_node = nullptr;
		}

		delete temp_rect;
		delete temp_node;

		updateTime();
		return true;
	}

	else {
		return false;
	}


}

void Sheet::paint(CDC & mem_dc)
{
	CDC dc;
	dc.CreateCompatibleDC(&mem_dc);
	dc.SelectObject(bmp_score);
	
	if (Sheet_name.GetLength() >= 1) {
		CFont font;
		font.CreatePointFont(200, _T("∞ÌµÒ√º"));
		mem_dc.SelectObject(&font);
		mem_dc.DrawText(Sheet_name,CRect(0,10,1240,74) , DT_SINGLELINE | DT_CENTER);
		mem_dc.SelectStockObject(SYSTEM_FONT);
	}
	if (Sheet_name.GetLength() >= 1) {
		CFont font;
		font.CreatePointFont(100, _T("∞ÌµÒ√º"));
		mem_dc.SelectObject(&font);
		mem_dc.DrawText(composer, CRect(200, 42, 1240, 74), DT_SINGLELINE | DT_CENTER);
		mem_dc.SelectStockObject(SYSTEM_FONT);
	}

	node* temp;
	for (int i = 0; i < style; i++) {

		temp = first_nodes[i];
		do {
			if (temp->first_node == true) {
				mem_dc.BitBlt(temp->location.x, temp->location.y,
					bmpinfo_score.bmWidth, bmpinfo_score.bmHeight, &dc, 0, 0, SRCCOPY);
			}
			temp = temp->back_node;
		} while (temp != nullptr);
	}

	temp = first_nodes[0];
	do {
		if (temp->first_node == true) {
			mem_dc.MoveTo(temp->location.x + 88, temp->location.y + 40);
			mem_dc.LineTo(temp->location.x + 88, temp->location.y + 40 + (style) * 33 + (style - 1)*(40 + 40));
			mem_dc.MoveTo(temp->location.x + 1151, temp->location.y + 40);
			mem_dc.LineTo(temp->location.x + 1151, temp->location.y + 40 + (style) * 33 + (style - 1)*(40 + 40));
		}
		temp = temp->back_node;
	} while (temp != nullptr);

	for (int i = 0; i < style; i++) {
		first_nodes[i]->paint(mem_dc);
	}

}

bool Sheet::save(string str)
{
	return false;
}

bool Sheet::load(string str)
{
	return false;
}

bool Sheet::play()
{
	return false;
}

void Sheet::updateTime()
{
	for (int i = 0; i < style; i++) {
		node *n = first_nodes[i];
		while (n != nullptr) {
			element* e = n->first_element;
			bool found = false;
			while (e != nullptr) {
				if (e->id >= b_24 && e->id <= b_128) {
					found = true;
					break;
				}
				e = e->back_element;
			}
			if (found) {
				switch (e->id) {
				case b_24:
					n->updateTime(16);
					break;
				case b_34:
					n->updateTime(24);
					break;
				case b_44:
					n->updateTime(32);
					break;
				case b_54:
					n->updateTime(40);
					break;
				case b_64:
					n->updateTime(48);
					break;
				case b_38:
					n->updateTime(12);
					break;
				case b_68:
					n->updateTime(24);
					break;
				case b_98:
					n->updateTime(36);
					break;
				case b_128:
					n->updateTime(48);
					break;
				}
			}


			n = n->back_node;
		}
	}
}
