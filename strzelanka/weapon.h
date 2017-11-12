#pragma once
#include <SFML\Audio.hpp>
#include <iostream>

using namespace sf;

class weapon
{
protected:
	unsigned cooldown;
	unsigned reload_time;
	unsigned bullets;
	unsigned max_bullets;
	Clock clock;
	bool reloading;

	SoundBuffer b_shooting_sound;
	Sound shooting_sound;
	SoundBuffer b_bullet_drop_sound;
	Sound bullet_drop_sound;
	SoundBuffer b_reload_sound;
	Sound reload_sound;
public:
	weapon();
	~weapon();

	virtual void shooting() = 0;
	virtual void reload() = 0;
	virtual void wypisz_ilosc_amunicji() = 0;
	virtual bool is_empty() = 0;
	virtual bool is_full() = 0;

	void play_sound();
};