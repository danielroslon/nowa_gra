#pragma once
#include <SFML/Graphics.hpp>

#include "character.h"


using namespace sf;

class game
{
private:
	RenderWindow window;

	character c;


public:
	game(int,int);
	~game();

	void loop();
};

