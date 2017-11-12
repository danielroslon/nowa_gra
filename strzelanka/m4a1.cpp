#include "m4a1.h"



m4a1::m4a1()
{
	cooldown = 90;
	reload_time = 2800;
	max_bullets = 25;
	bullets = 25;
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