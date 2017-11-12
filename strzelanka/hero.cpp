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
void hero::shooting()
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		possessed_weapon->shooting();
	}
	if (possessed_weapon->is_empty())
	{
		possessed_weapon->reload();
	}
}
void hero::reloading(Event *ev)
{
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::R)
	{
		possessed_weapon->reload();
	}
}