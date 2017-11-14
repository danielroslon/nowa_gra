#include "character.h"



character::character(RenderWindow* w): figure(10,1000), hp(100),speed(100), color(Color::Black)
{
	figure.setOrigin(figure.getRadius(), figure.getRadius());
	figure.setFillColor(color);
}

character::~character()
{
}


void character::set_position(float _x, float _y)
{
	figure.setPosition(_x , _y);
	possessed_weapon->set_weapon_position(_x,_y);
}
unsigned character::get_bullets()
{
	return possessed_weapon->get_ammo();
}
Vector2f character::get_position()
{
	return figure.getPosition();
}
void character::draw(RenderWindow *w)
{
	w->draw(figure);
	possessed_weapon->draw_weapon(w);
	w->draw(crosshair);
}
void character::is_hit(list *l)
{
	bullet *wsk = l->get_head();

	while (wsk != NULL)
	{
		if (wsk->get_position().x >= figure.getPosition().x - figure.getRadius() && wsk->get_position().x <= figure.getPosition().x + figure.getRadius() 
		&& wsk->get_position().y >= figure.getPosition().y - figure.getRadius() && wsk->get_position().y <= figure.getPosition().y + figure.getRadius())
		{
			hp = hp - wsk->dmg;
			bullet *temp = wsk;
			wsk = wsk->next;
			l->remove_bullet(temp->get_id());
			continue;
		}
		wsk = wsk->next;
	}
}