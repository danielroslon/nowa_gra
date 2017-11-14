#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "character.h"

using namespace sf;

class user_interface
{
private:
	Text amount_of_bullets;
	Text hp;
	Font font;

public:
	user_interface();
	~user_interface();

	void draw(RenderWindow*, character*);
};

