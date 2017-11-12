#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

using namespace sf;

class character
{
protected:
	CircleShape figure;
	Color color;
public:
	character();
	~character();

	void set_position(float, float);

	void draw(RenderWindow*);
	void virtual move() = 0;
};

