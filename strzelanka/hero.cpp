#include "hero.h"



hero::hero(): character()
{
	speed = 10;
	hp = 200;
	crosshair.setFillColor(Color::Black);
	crosshair.setRadius(2);
}


hero::~hero()
{
}

void hero::move(Event *ev, RenderWindow *window)
{
	//if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::W)
	//{
	//	figure.move(0,-10);
	//	possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
	//}
	//if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::S) 
	//{
	//	figure.move(0, 10);
	//	possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
	//}
	//if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::A) 
	//{
	//	figure.move(-10, 0);
	//	possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
	//}
	//if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::D)
	//{
	//	figure.move(10, 0);
	//	possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
	//}

	if (clock.getElapsedTime().asMilliseconds() >= speed)
	{
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			figure.move(0, -10);
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			figure.move(0, 10);
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			figure.move(-10, 0);
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			figure.move(10, 0);
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		clock.restart();
	}
	

}
void hero::rotate(Event *ev, RenderWindow* w)
{

	if (ev->type == ev->MouseMoved && ev->MouseMoved)
	{
		float x = Mouse::getPosition(*w).x;
		float y = Mouse::getPosition(*w).y;

		crosshair.setPosition(x,y);
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