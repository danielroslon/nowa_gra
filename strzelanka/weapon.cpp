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
void weapon::set_volume(double _volume)
{
	shooting_sound.setVolume(_volume);
	reload_sound.setVolume(_volume);
	bullet_drop_sound.setVolume(_volume);
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
		}
		if (clock.getElapsedTime().asMilliseconds() >= reload_time)
		{
			bullets = max_bullets;
			reloading = false;
			clock.restart();
		}
	}
}
void weapon::shooting(container<bullet>& cont)
{
	if (!is_empty())
	{
		if (clock.getElapsedTime().asMilliseconds() >= cooldown)
		{
			double x, y;
			if (figure.getRotation() >= 0 && figure.getRotation() < 90)
			{
				x = figure.getRotation();
				x = x * 0.0174532925;
				x = cos(x);

				y = figure.getRotation();
				y = y * 0.0174532925;
				y = sin(y);
			}
			if (figure.getRotation() >= 90 && figure.getRotation() < 180)
			{
				x = 90 - figure.getRotation();
				x = x * 0.0174532925;
				x = sin(x);

				y = 90 - figure.getRotation();
				y = y * 0.0174532925;
				y = cos(y);
			}
			if (figure.getRotation() >= 180 && figure.getRotation() < 270)
			{
				x = 180 - figure.getRotation();
				x = x * 0.0174532925;
				x = cos(x);
				x = - x;

				y = 180 - figure.getRotation();
				y = y * 0.0174532925;
				y = sin(y);
			}
			if (figure.getRotation() >= 270 && figure.getRotation() < 360)
			{
				x = 270 - figure.getRotation();
				x = x * 0.0174532925;
				x = sin(x);
				x = -x;

				y = 270 - figure.getRotation();
				y = y * 0.0174532925;
				y = cos(y);
				y = -y;
			}


			x = x *figure.getSize().x;
			y = y * figure.getSize().x;




			cont.add(bullet(dmg, figure.getPosition().x + x, figure.getPosition().y + y, figure.getRotation()));
			play_sound();
			bullets--;
			clock.restart();
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
