#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class character
{
private:
	CircleShape figure;
public:
	character();
	~character();

	void set_position(float, float);
	void draw(RenderWindow*);
};

