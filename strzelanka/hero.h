#pragma once
#include "character.h"
#include <sstream>

class hero: public character
{
private:
	Text amount_of_bullets;
	Font font;
public:
	hero(RenderWindow*);
	~hero();

	void move(RenderWindow*);
	void rotate(RenderWindow*);
	void shooting(RenderWindow*);
	void reloading(Event*);

	void write_amount_of_bullets(RenderWindow*);
};

