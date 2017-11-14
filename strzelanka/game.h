#pragma once
#include <SFML/Graphics.hpp>

#include "character.h"
#include "hero.h"
#include "enemy_character.h"
#include "user_interface.h"

using namespace sf;

class game
{
private:
	RenderWindow window;
	hero c;
	user_interface ui;

	enemy_character enemy;

public:
	game(int,int);
	~game();

	void loop();
};

