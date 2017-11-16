#include "sniper_rifle.h"



sniper_rifle::sniper_rifle(Vector2f v): weapon(v)
{
	name = "Sniper Rifle";
	dmg = 99;
	cooldown = 1;
	reload_time = 2800;
	max_bullets = 1;
	bullets = 1;
	reloading = false;

	b_shooting_sound.loadFromFile("sniper_rifle.wav");
	shooting_sound.setBuffer(b_shooting_sound);
	shooting_sound.setVolume(100);

	b_bullet_drop_sound.loadFromFile("bullet.wav");
	bullet_drop_sound.setBuffer(b_bullet_drop_sound);
	bullet_drop_sound.setVolume(100);

	b_reload_sound.loadFromFile("reload.wav");
	reload_sound.setBuffer(b_reload_sound);
	reload_sound.setVolume(100);

	figure.setSize(Vector2f(40, 2));
	figure.setPosition(v);
	figure.setFillColor(Color::Black);
	figure.setOrigin(0, figure.getSize().y / 2);
}


sniper_rifle::~sniper_rifle()
{
}
