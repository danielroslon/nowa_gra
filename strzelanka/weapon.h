#pragma once
#include <SFML\Audio.hpp>
#include <iostream>
#include <cmath>


#include "bullet.h"

using namespace sf;

class weapon
{
protected:
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

	virtual void shooting() = 0;
	virtual void reload() = 0;
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;
	virtual bool is_list_empty() = 0;
	virtual void render_bullets(RenderWindow*) = 0;

	virtual void draw_weapon(RenderWindow*) = 0;
	virtual void set_weapon_position(float,float) = 0;
	virtual void rotate_weapon(double) = 0;
	virtual Vector2f get_weapon_position() = 0;
	virtual float get_weapon_rotation() = 0;
	virtual void move_bullets(RenderWindow*) = 0;

	void play_sound();
};