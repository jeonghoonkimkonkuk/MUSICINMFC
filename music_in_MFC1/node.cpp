#include "stdafx.h"
#include "node.h"


node::node()
{
}


node::~node()
{
}

node::node(CPoint location, CRect* rect, node * front_node, node * back_node)
	: location(location), rect(rect), front_node(front_node), back_node(back_node), s_rect(nullptr),forshow(false)
{
	first_element = nullptr;
	first_node = false;
}

void node::paint(CDC & mem_dc)
{
	
	node* temp_node = this;
	while (temp_node != nullptr) {
		mem_dc.TextOutW(temp_node->rect->left, temp_node->location.y +5,temp_node->checkTime());
		element* temp = temp_node->first_element;
		while (temp != nullptr) {
			temp->paint(mem_dc);
			temp = temp->back_element;
		}
		
		if (temp_node->back_node != nullptr) {
			//if (temp_node->back_node->first_node) {
				// 새로줄 삽입
			CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
			if (temp_node->forshow) {
				mem_dc.SelectObject(&pen);
			}
			mem_dc.MoveTo(temp_node->back_node->location.x - 10, temp_node->back_node->location.y + 40);
			mem_dc.LineTo(temp_node->back_node->location.x - 10, temp_node->back_node->location.y + 40 + 33);
			mem_dc.SelectStockObject(BLACK_PEN);

			//}
		}
		temp_node = temp_node->back_node;
	}

	
}

element * node::getElement(CPoint pt)
{
	CPoint point;

	if (this == nullptr) {
		return nullptr;
	}
	element* e = first_element;
	bool found = false;
	while (e != nullptr) {
		if (e->rect.PtInRect(pt)) {
			found = true;
			break;
		}
		if (e->location.x > pt.x) {
			break;
		}
		e = e->back_element;
	}
	if (found) {
		return e;
	}
	else {
		return nullptr;
	}
}

bool node::addElement(CPoint pt, element * e)
{


	element *e1 = first_element;
	element *e2;

	if (e1 == nullptr) {
		first_element = e;
	}
	else {
		bool found = false;
		while (e1 != nullptr) {

			if (e1->rect.PtInRect(e->location) || e1->rect.PtInRect(CPoint(e->location.x + e->bmp_info.bmWidth, e->location.y))) {
				if (e1->forshow == false) {
					if ((e1->id == n_note || e1->id == r_rest) && (e->id >= f && e->id <= mp)) {

					}
					else
						return false;
				}
			}
			if (e1->location.x > pt.x) {
				found = true;
				break;
			}
			e2 = e1;
			e1 = e1->back_element;

		}

		if (found) {
			if (e1->front_element == nullptr) {
				e->back_element = e1;
				e1->front_element = e;
				first_element = e;
			}
			else {
				e1->front_element->back_element = e;
				e->front_element = e1->front_element;
				e->back_element = e1;

				e1->front_element = e;
			}
		}
		else {
			e2->back_element = e;
			e->front_element = e2;
		}
	}
	e->init(rect);
	if (e->id >= n_zero && e->id <= p_r_eight) {
		//e->init(rect);
		switch (e->id) {
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
			e->addNote(pt.y, e->id, e->forshow);
			break;
		}
	}
	//if (e->id == high || e->id == low) {
	//	e->init(rect);
	//}
	//if (e->id >= b_24 && e->id <= b_128) {
	//	e->init(rect);
	//}
	

	return true;
}

bool node::deleteElement(CPoint pt)
{
	element *e = first_element;
	while (e != nullptr) {
		if (e->location.x > pt.x) {
			return false;
		}
		if (e->rect.PtInRect(pt)) {
			if (e->front_element == nullptr) {
				if (e->back_element == nullptr) {
					first_element = nullptr;
				}
				else {
					e->back_element->front_element = nullptr;
					first_element = e->back_element;
					
				}
				
			}
			else if(e->back_element==nullptr){
				e->front_element->back_element = nullptr;
			}
			else {
				e->front_element->back_element = e->back_element;
				e->back_element->front_element = e->front_element;
			}
			//delete(e);
			return true;
		}
		e = e->back_element;
	}
	return false;
}

void node::updateTime(int time)
{
	this->time = time;
	if (back_node != nullptr) {
		back_node->updateTime(time);
	}
}

CString node::checkTime()
{
	int m_time=0;
	element* e = first_element;
	while (e != nullptr) {
		if (e->first_note!=nullptr && (e->id == n_note || e->id <= r_rest)) {
			switch (e->first_note->id) {
			case n_zero:
				if (e->first_note->condition_dot) {
					m_time += 16;
				}
				m_time += 32;
				break;
			case n_two:
				if (e->first_note->condition_dot) {
					m_time += 8;
				}
				m_time += 16;
				break;
			case n_four:
				if (e->first_note->condition_dot) {
					m_time += 4;
				}
				m_time += 8;
				break;
			case n_eight:
				if (e->first_note->condition_dot) {
					m_time += 2;
				}
				m_time += 4;
				break;
			case n_sixteen:
				if (e->first_note->condition_dot) {
					m_time += 1;
				}
				m_time += 2;
				break;
			case r_zero:
				if (e->first_note->condition_dot) {
					m_time += 16;
				}
				m_time += 32;
				break;
			case r_two:
				if (e->first_note->condition_dot) {
					m_time += 8;
				}
				m_time += 16;
				break;
			case r_four:
				if (e->first_note->condition_dot) {
					m_time += 4;
				}
				m_time += 8;
				break;
			case r_eight:
				if (e->first_note->condition_dot) {
					m_time += 2;
				}
				m_time += 4;
				break;
			}

		}
		e = e->back_element;
	}

	if (m_time > time) {
		return _T("박자가 넘칩니다.");
	}
	else if (m_time < time) {
		return _T("박자가 부족합니다.");
	}
	else {
		return _T("");
	}
}

