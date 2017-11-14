#pragma once
#include <SFML\Audio.hpp>
#include <iostream>
#include <cmath>


#include "bullet.h"

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

	list list_of_existing_bullets;

	SoundBuffer b_shooting_sound;
	Sound shooting_sound;
	SoundBuffer b_bullet_drop_sound;
	Sound bullet_drop_sound;
	SoundBuffer b_reload_sound;
	Sound reload_sound;
public:
	weapon(Vector2f);
	~weapon();

	void shooting();
	void reload();
	bool is_empty();
	bool is_full();
	bool is_list_empty();
	void render_bullets(RenderWindow*);

	unsigned get_ammo();
	unsigned get_max_ammo();

	void draw_weapon(RenderWindow*);
	void set_weapon_position(float,float);
	void rotate_weapon(double);
	Vector2f get_weapon_position();
	float get_weapon_rotation();
	void move_bullets(RenderWindow*);

	void play_sound();


	friend class user_interface;
};