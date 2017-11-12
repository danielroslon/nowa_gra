#include "hero.h"



hero::hero(): character()
{
	hp = 200;
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
void hero::shooting(RenderWindow* w)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		possessed_weapon->shooting();
	}
	if (possessed_weapon->is_empty())
	{
		possessed_weapon->reload();
	}
	if (!possessed_weapon->is_list_empty())
	{
		possessed_weapon->move_bullets();
		possessed_weapon->render_bullets(w);
	}
	
}
void hero::reloading(Event *ev)
{
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::R)
	{
		possessed_weapon->reload();
	}
}