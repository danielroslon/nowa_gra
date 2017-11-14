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
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			figure.move(0, 10);
			if (figure.getPosition().y > w->getSize().y)
			{
				figure.setPosition(figure.getPosition().x, 0);
			}
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			figure.move(-10, 0);
			if (figure.getPosition().x < 0)
			{
				figure.setPosition(w->getSize().x, figure.getPosition().y);
			}
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			figure.move(10, 0);
			if (figure.getPosition().x > w->getSize().x)
			{
				figure.setPosition(0, figure.getPosition().y);
			}
			possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
		}
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
			possessed_weapon->rotate_weapon(rotation);
		}
		if (v_x <= 0 && v_y > 0)
		{
			float rotation = -v_x / v_y;
			rotation = atan(rotation) * 180 / 3.14159265359;
			possessed_weapon->rotate_weapon(rotation + 90);
		}
		if (v_x <= 0 && v_y < 0)
		{
			float rotation = v_y / v_x;
			rotation = atan(rotation) * 180 / 3.14159265359;
			possessed_weapon->rotate_weapon(rotation + 180);
		}
		if (v_x >= 0 && v_y < 0)
		{
			float rotation = v_x / -v_y;
			rotation = atan(rotation) * 180 / 3.14159265359;
			possessed_weapon->rotate_weapon(rotation + 270);
		}
		crosshair.setPosition(m_x,m_y);		
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
		possessed_weapon->move_bullets(w);
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