#include "character.h"



character::character(): figure(10,1000), hp(100),speed(100), color(Color::Black)
{
	figure.setOrigin(figure.getRadius(), figure.getRadius());
	figure.setFillColor(color);
	possessed_weapon = new m4a1(figure.getPosition());
}

character::~character()
{
}


void character::set_position(float _x, float _y)
{
	figure.setPosition(_x , _y);
	possessed_weapon->set_weapon_position(_x,_y);
}
void character::draw(RenderWindow *w)
{
	w->draw(figure);
	possessed_weapon->draw_weapon(w);
	w->draw(crosshair);
}