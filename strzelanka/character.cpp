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
void character::is_hit(container<bullet> &c)
{
	container<bullet>::iterator begin(c);
	container<bullet>::iterator end(c, true);

	while (begin != end)
	{
		bullet *temp = *begin;

		if (temp != NULL)
		{

			if (temp->get_position().x >= figure.getPosition().x - figure.getRadius() && temp->get_position().x <= figure.getPosition().x + figure.getRadius()
				&& temp->get_position().y >= figure.getPosition().y - figure.getRadius() && temp->get_position().y <= figure.getPosition().y + figure.getRadius())
			{
				hp = hp - temp->get_dmg();
				c.remove(temp->get_id());
			}
		}
		begin++;
	}
}