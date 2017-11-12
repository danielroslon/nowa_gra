#include "character.h"



character::character(): figure(20,1000), color(Color::Red)
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
}
void character::draw(RenderWindow *w)
{
	w->draw(figure);
}