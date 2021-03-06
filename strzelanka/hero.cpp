#include "hero.h"



hero::hero(RenderWindow *w): character(w)
{
	speed = 30;
	hp = 200;
	crosshair.setFillColor(Color::Black);
	crosshair.setRadius(2);
	figure.setPosition(w->getSize().x/2, w->getSize().y/2);
	possessed_weapon = new m4a1(figure.getPosition());
}


hero::~hero()
{
}

void hero::move(RenderWindow *w)
{
	if (clock.getElapsedTime().asMilliseconds() >= speed)
	{
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			figure.move(0, -10);
			if (figure.getPosition().y < 0)
			{
				figure.setPosition(figure.getPosition().x, w->getSize().y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			figure.move(0, 10);
			if (figure.getPosition().y > w->getSize().y)
			{
				figure.setPosition(figure.getPosition().x, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			figure.move(-10, 0);
			if (figure.getPosition().x < 0)
			{
				figure.setPosition(w->getSize().x, figure.getPosition().y);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			figure.move(10, 0);
			if (figure.getPosition().x > w->getSize().x)
			{
				figure.setPosition(0, figure.getPosition().y);
			}
		}
		possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		clock.restart();
	}
}
void hero::rotate(RenderWindow* w)
{
	{
		float m_x = Mouse::getPosition(*w).x;
		float m_y = Mouse::getPosition(*w).y;

		float v_x = m_x - figure.getPosition().x;
		float v_y = m_y - figure.getPosition().y;

		if (v_x >= 0 && v_y > 0)
		{
			float rotation = v_y / v_x;
			rotation = atan(rotation) * 180 / 3.14159265359;
			figure.setRotation(rotation);
			possessed_weapon->rotate_weapon(figure.getRotation());
		}
		if (v_x <= 0 && v_y > 0)
		{
			float rotation = -v_x / v_y;
			rotation = atan(rotation) * 180 / 3.14159265359;
			figure.setRotation(rotation +90);
			possessed_weapon->rotate_weapon(figure.getRotation());
		}
		if (v_x <= 0 && v_y < 0)
		{
			float rotation = v_y / v_x;
			rotation = atan(rotation) * 180 / 3.14159265359;
			figure.setRotation(rotation + 180);
			possessed_weapon->rotate_weapon(figure.getRotation());
		}
		if (v_x >= 0 && v_y < 0)
		{
			float rotation = v_x / -v_y;
			rotation = atan(rotation) * 180 / 3.14159265359;
			figure.setRotation(rotation + 270);
			possessed_weapon->rotate_weapon(figure.getRotation());
		}
		crosshair.setPosition(m_x,m_y);		
	}
}
void hero::shooting(RenderWindow* w, container<bullet>& cont)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		possessed_weapon->shooting(cont);
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
void hero::change_weapon(Event* ev)
{
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::Num1)
	{
		delete possessed_weapon;
		possessed_weapon = new m4a1(figure.getPosition());
	}
	if (ev->type == ev->KeyPressed && ev->key.code == Keyboard::Num2)
	{
		delete possessed_weapon;
		possessed_weapon = new sniper_rifle(figure.getPosition());
	}
}