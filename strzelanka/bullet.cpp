#include "bullet.h"



bullet::bullet(double _dmg, Vector2f v, float r): figure(2), dmg(_dmg), next(NULL), prev(NULL), id(0)
{
	figure.setFillColor(Color::Red);
	figure.setPosition(v);
	figure.setRotation(r);
}


bullet::~bullet()
{
}

void bullet::set_dmg(double _dmg)
{
	dmg = _dmg;
}
void bullet::set_id(int _id)
{
	id = _id;
}
double bullet::get_dmg()
{
	return dmg;
}
int bullet::get_id()
{
	return id;
}

list::list(): head(NULL), tail(NULL)
{

}


void list::add_bullet(double _dmg, Vector2f v, float r)
{
	if (head == NULL)
	{
		head = new bullet(_dmg, v, r);
		tail = head;
	}
	else
	{
		tail->next = new bullet(_dmg, v, r);
		tail->next->prev = tail;
		tail = tail->next;
	}
}
void list::remove_bullet(int _id)
{
	bullet *wsk = head;

	while (wsk != NULL || wsk->get_id() == _id)
	{
		wsk = wsk->next;
	}
	if (wsk != NULL)
	{
		if (wsk == head)
		{
			if (wsk->next != NULL)
			{
				head->set_id(0);
				head = head->next;
			}
			else
			{
				head = tail = NULL;
			}
		}
		else if (wsk == tail)
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			wsk->prev->next = wsk->next;
			wsk->next->prev = wsk->prev;
		}
		delete wsk;
	}
}
void list::render(RenderWindow *w)
{
	bullet *wsk = head;
	while (wsk != NULL)
	{
		w->draw(wsk->figure);
		wsk = wsk->next;
	}
}
bool list::is_empty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void list::move()
{
	bullet *wsk = head;
	while (wsk != NULL)
	{
		wsk->figure.move(1,0);
		wsk = wsk->next;
	}
}