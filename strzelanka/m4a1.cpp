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
}

m4a1::~m4a1()
{
}