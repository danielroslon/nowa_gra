#pragma once
#include <SFML\Audio.hpp>
#include <iostream>
#include <cmath>


#include "bullet.h"
#include "container.h"

using namespace sf;

class weapon
{
protected:
	std::string name;
	double dmg;
	unsigned cooldown;
	unsigned reload_time;
	unsigned bullets;
	unsigned max_bullets;
	Clock clock;
	bool reloading;

	RectangleShape figure;

	Vector2f weapon_position;

	SoundBuffer b_shooting_sound;
	Sound shooting_sound;
	SoundBuffer b_bullet_drop_sound;
	Sound bullet_drop_sound;
	SoundBuffer b_reload_sound;
	Sound reload_sound;
public:
	weapon(Vector2f);
	~weapon();

	void shooting(container<bullet>&);
	void reload();
	bool is_empty();
	bool is_full();

	unsigned get_ammo();
	unsigned get_max_ammo();

	void draw_weapon(RenderWindow*);
	void set_weapon_position(float,float);
	void rotate_weapon(double);
	Vector2f get_weapon_position();
	float get_weapon_rotation();

	void play_sound();
	void set_volume(double);

	friend class user_interface;
};