#include "weapon.h"



weapon::weapon(Vector2f v): weapon_position(v)
{
}
weapon::~weapon()
{
}


bool weapon::is_empty()
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
bool weapon::is_full()
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
bool weapon::is_list_empty()
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

unsigned weapon::get_ammo()
{
	return bullets;
}
unsigned weapon::get_max_ammo()
{
	return max_bullets;
}

void weapon::play_sound()
{
	shooting_sound.play();
	bullet_drop_sound.play();
}
void weapon::reload()
{
	if (!is_full())
	{
		if (reloading == false)
		{
			clock.restart();
			reload_sound.play();
			reloading = true;
			bullets = 0;
			std::cout << "Reloading... " << std::endl;
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
void weapon::shooting()
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
void weapon::draw_weapon(RenderWindow *w)
{
	w->draw(figure);
}
void weapon::set_weapon_position(float x, float y)
{
	figure.setPosition(x, y);
}
void weapon::rotate_weapon(double a)
{
	figure.setRotation(a);
}
Vector2f weapon::get_weapon_position()
{
	return weapon_position;
}
float weapon::get_weapon_rotation()
{
	return figure.getRotation();
}

void weapon::move_bullets(RenderWindow *w)
{
	list_of_existing_bullets.move(w);
}
void weapon::render_bullets(RenderWindow *w)
{
	list_of_existing_bullets.render(w);
}