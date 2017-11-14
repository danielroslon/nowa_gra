#pragma once
#include <SFML/Graphics.hpp>

#include "character.h"
#include "hero.h"
#include "user_interface.h"

using namespace sf;

class game
{
private:
	RenderWindow window;
	character *c;
	user_interface ui;

public:
	game(int,int);
	~game();

	void loop();
};

