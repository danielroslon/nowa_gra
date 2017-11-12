#include "character.h"



character::character(): figure(10,1000), color(Color::Green), look_of_weapon(Vector2f(figure.getRadius()*2, 2))
{
	figure.setOrigin(figure.getRadius(), figure.getRadius());
	figure.setFillColor(color);
	look_of_weapon.setPosition(figure.getPosition());
	look_of_weapon.setFillColor(color);
	possessed_weapon = new m4a1;
}


character::~character()
{
}


void character::set_position(float _x, float _y)
{
	figure.setPosition(_x , _y);
	look_of_weapon.setPosition(_x, _y);
}
void character::rotate(Event *ev)	
{
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::A)
	{
		look_of_weapon.rotate(-10);
	}
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::D)
	{
		look_of_weapon.rotate(10);
	}
}
void character::draw(RenderWindow *w)
{
	w->draw(figure);
	w->draw(look_of_weapon);
}