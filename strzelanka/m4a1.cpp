#include "m4a1.h"



m4a1::m4a1(Vector2f v): weapon(v)
{
	dmg = 25;
	cooldown = 80;
	reload_time = 2800;
	max_bullets = 30;
	bullets = 30;
	reloading = false;

	b_shooting_sound.loadFromFile("m4a1.wav");
	shooting_sound.setBuffer(b_shooting_sound);
	shooting_sound.setVolume(100);

	b_bullet_drop_sound.loadFromFile("bullet.wav");
	bullet_drop_sound.setBuffer(b_bullet_drop_sound);
	bullet_drop_sound.setVolume(100);

	b_reload_sound.loadFromFile("reload.wav");
	reload_sound.setBuffer(b_reload_sound);
	reload_sound.setVolume(100);



	figure.setSize(Vector2f(20, 2));
	figure.setPosition(v);
	figure.setFillColor(Color::Red);
	figure.setOrigin(0, figure.getSize().y/2);

	std::cout << "Bullets " << bullets << std::endl;
}


m4a1::~m4a1()
{
}

void m4a1::reload()
{
	if (!is_full())
	{
		if (reloading == false)
		{
			clock.restart();
			reload_sound.play();
			reloading = true;
			bullets = 0;
			std::cout << "Reloading... "  << std::endl;
		}	
		if (clock.getElapsedTime().asMilliseconds() >= reload_time)
		{
			bullets = max_bullets;
			reloading = false;		
			clock.restart();
			std::cout << "Bullets " << bullets << std::endl;
		}
	}
}
void m4a1::shooting()
{
	if (!is_empty())
	{
		if (clock.getElapsedTime().asMilliseconds() >= cooldown)
		{
			play_sound();
			list_of_existing_bullets.add_bullet(dmg, figure.getPosition(), figure.getRotation());
			bullets--;
			clock.restart();
			std::cout << "Bullets " << bullets << std::endl;
		}
	}
}
bool m4a1::is_empty()
{
	if (bullets == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool m4a1::is_full()
{
	if (bullets == max_bullets)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool m4a1::is_list_empty()
{
	if (list_of_existing_bullets.is_empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void m4a1::render_bullets(RenderWindow *w)
{
	list_of_existing_bullets.render(w);
}

void m4a1::draw_weapon(RenderWindow *w)
{
	w->draw(figure);
}
void m4a1::set_weapon_position(float x, float y)
{
	figure.setPosition(x, y);
}
void m4a1::rotate_weapon(double a)
{
	figure.setRotation(a);
}
Vector2f m4a1::get_weapon_position()
{
	return weapon_position;
}
float m4a1::get_weapon_rotation()
{
	return figure.getRotation();
}
void m4a1::move_bullets(RenderWindow *w)
{
	list_of_existing_bullets.move(w);
}