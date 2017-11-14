#include "enemy_character.h"



enemy_character::enemy_character(RenderWindow* w): character(w)
{
	speed = 60;
	hp = 100;
	figure.setPosition(0, w->getSize().y/2);
	figure.setFillColor(Color::Red);
	possessed_weapon = new m4a1(figure.getPosition());
}


enemy_character::~enemy_character()
{
}

void enemy_character::move(RenderWindow* w)
{
	double v_x = fabs(figure.getPosition().x - hero_position.x);
	double v_y = fabs(figure.getPosition().y - hero_position.y);
	double distance_from_hero = sqrt(v_x * v_x + v_y * v_y);

	if (distance_from_hero >= 300 && clock.getElapsedTime().asMilliseconds() >= speed)
	{

		double new_x = fabs(figure.getPosition().x + 10 - hero_position.x);
		double new_y = fabs(figure.getPosition().y + 10 - hero_position.y);

		//Horizontal
		if (sqrt(new_x * new_x + v_y * v_y) <  sqrt(v_x * v_x + v_y * v_y))
		{
			figure.move(10, 0);
		}
		new_x = fabs(figure.getPosition().x - 10 - hero_position.x);
		if (sqrt(new_x * new_x + v_y * v_y) <  sqrt(v_x * v_x + v_y * v_y))
		{
			figure.move(-10, 0);
		}
		
		//Vertical
		if (sqrt(v_x * v_x + new_y * new_y) < sqrt(v_x * v_x + v_y * v_y))
		{
			figure.move(0,10);
		}
		new_y = fabs(figure.getPosition().y - 10 - hero_position.y);
		if (sqrt(v_x * v_x + new_y * new_y) < sqrt(v_x * v_x + v_y * v_y))
		{
			figure.move(0, -10);
		}


		clock.restart();
	}

	possessed_weapon->set_weapon_position(figure.getPosition().x, figure.getPosition().y);
}
void enemy_character::rotate(RenderWindow* w)
{
	float m_x = hero_position.x;
	float m_y = hero_position.y;

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
}
void enemy_character::shooting(RenderWindow* w)
{
	double v_x = fabs(figure.getPosition().x - hero_position.x);
	double v_y = fabs(figure.getPosition().y - hero_position.y);
	double distance_from_hero = sqrt(v_x * v_x + v_y * v_y);


	if (distance_from_hero <= 1000)
	{
		possessed_weapon->shooting();
		possessed_weapon->render_bullets(w);
		if (possessed_weapon->is_empty())
		{
			possessed_weapon->reload();
		}
	}
	possessed_weapon->move_bullets(w);
	possessed_weapon->render_bullets(w);
}
void enemy_character::reloading(Event*)
{

}


void enemy_character::get_hero_position(Vector2f v)
{
	hero_position = v;
}