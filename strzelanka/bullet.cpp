#include "bullet.h"



bullet::bullet(double _dmg, Vector2f v, float r): figure(2), dmg(_dmg), next(NULL), prev(NULL), id(0)
{
	figure.setFillColor(Color::Black);
	figure.setOrigin(figure.getRadius(), figure.getRadius());
	figure.setPosition(v);
	figure.setRotation(r);
	figure.scale(4,0.3);
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

list::list(): head(NULL), tail(NULL), ammount(0)
{

}


void list::add_bullet(double _dmg, Vector2f v, float r)
{
	ammount++;
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
	tail->set_id(ammount);
}
void list::remove_bullet(int _id)
{
	bullet *wsk = head;

	while (wsk != NULL)
	{
		if (wsk->get_id() == _id)
		{
			break;
		}
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
				ammount = 0;
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
		if (wsk->figure.getRotation() >= 0 && wsk->figure.getRotation() < 90)
		{
			double x = wsk->figure.getRotation();
			x = x * 0.0174532925;
			x = cos(x);

			double y = wsk->figure.getRotation();
			y = y * 0.0174532925;
			y = sin(y);
	
			wsk->figure.move(x, y);
		}	
		if (wsk->figure.getRotation() >= 90 && wsk->figure.getRotation() < 180)
		{
			double x = 90 - wsk->figure.getRotation();
			x = x * 0.0174532925;
			x = sin(x);

			double y = 90 - wsk->figure.getRotation();
			y = y * 0.0174532925;
			y = cos(y);

			wsk->figure.move(x, y);
		}
		if (wsk->figure.getRotation() >= 180 && wsk->figure.getRotation() < 270)
		{
			double x = 180 - wsk->figure.getRotation();
			x = x * 0.0174532925;
			x = cos(x);

			double y = 180 - wsk->figure.getRotation();
			y = y * 0.0174532925;
			y = sin(y);

			wsk->figure.move(-x, y);
		}
		if (wsk->figure.getRotation() >= 270 && wsk->figure.getRotation() < 360)
		{
			double x = 270 - wsk->figure.getRotation();
			x = x * 0.0174532925;
			x = sin(x);

			double y = 270 - wsk->figure.getRotation();
			y = y * 0.0174532925;
			y = cos(y);

			wsk->figure.move(-x, -y);
		}

		//Usuwanie pocisków
		if (wsk->figure.getPosition().x > 1000 || wsk->figure.getPosition().y > 800 || wsk->figure.getPosition().x < 0 || wsk->figure.getPosition().y < 0)
		{
			bullet *b = wsk;
			wsk = wsk->next;
			remove_bullet(b->get_id());
		}
		if (wsk != NULL)
		{
			wsk = wsk->next;
		}
	}
}