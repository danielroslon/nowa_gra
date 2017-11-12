#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <Windows.h>

#include "weapon.h"
#include "m4a1.h"

using namespace sf;

class character
{
protected:
	CircleShape figure;
	RectangleShape look_of_weapon;
	weapon *possessed_weapon;
	Color color;
public:
	character();
	~character();

	void set_position(float, float);
	void rotate(Event*);
	void draw(RenderWindow*);

	virtual void move(Event*, RenderWindow*) = 0;
	virtual void shooting() = 0;
	virtual void reloading(Event *ev) = 0;


	void wypisywanie_do_konsoli();
};

