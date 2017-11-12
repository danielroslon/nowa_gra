#include "hero.h"



hero::hero(): character()
{
}


hero::~hero()
{
}

void hero::move(Event *ev, RenderWindow *window)
{
	if (ev->type == ev->MouseMoved)
	{
		set_position(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y);
	}
}