#include "m4a1.h"



m4a1::m4a1(): cooldown(50), reload_time(2800), max_bullets(25), bullets(25)
{
	b_shooting_sound.loadFromFile("m4a1.wav");
	shooting_sound.setBuffer(b_shooting_sound);
	shooting_sound.setVolume(100);

	b_bullet_drop_sound.loadFromFile("bullet.wav");
	bullet_drop_sound.setBuffer(b_bullet_drop_sound);
	bullet_drop_sound.setVolume(100);

	b_reload_sound.loadFromFile("reload.wav");
	reload_sound.setBuffer(b_reload_sound);
	reload_sound.setVolume(100);
}


m4a1::~m4a1()
{
}

void m4a1::reload()
{
	clock.restart();
	reload_sound.play();
	while (clock.getElapsedTime().asMilliseconds() <= reload_time)
	{
		std::cout << "Bullets reloading: " << clock.getElapsedTime().asMilliseconds() << std::endl;
	}
	bullets = max_bullets;
}
void m4a1::shooting()
{
	if (bullets > 0 && clock.getElapsedTime().asMilliseconds() >= cooldown)
	{
		play_sound();
		bullets--;
		clock.restart();
	}
	if (bullets == 0)
	{
		reload();
	}
}

void m4a1::wypisz_ilosc_amunicji()
{
	std::cout << "Bullets " << bullets << std::endl;
}