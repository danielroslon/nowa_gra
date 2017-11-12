#include "character.h"



character::character(): figure(50,200)
{
	figure.setFillColor(Color::Red);
}


character::~character()
{
}


void character::set_position(float _x, float _y)
{
	figure.setPosition(_x - figure.getRadius(), _y - figure.getRadius());
}
void character::draw(RenderWindow *w)
{
	w->draw(figure);
}