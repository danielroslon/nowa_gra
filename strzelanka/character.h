#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <Windows.h>

#include "weapon.h"
#include "m4a1.h"
#include "bullet.h"

using namespace sf;

class character
{
protected:
	double hp;
	double speed;

	CircleShape figure;
	weapon *possessed_weapon;
	CircleShape crosshair;
	Color color;

	Clock clock;
public:
	character(RenderWindow*);
	~character();

	void set_position(float, float);

	void draw(RenderWindow*);

	virtual void move(RenderWindow*) = 0;
	virtual void rotate(RenderWindow*) = 0;
	virtual void shooting(RenderWindow*) = 0;
	virtual void reloading(Event *ev) = 0;
};

