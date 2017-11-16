#pragma once
#include "character.h"
#include <sstream>

class hero: public character
{
private:
public:
	hero(RenderWindow*);
	~hero();

	void move(RenderWindow*);
	void rotate(RenderWindow*);
	void shooting(RenderWindow*, container<bullet>&);
	void reloading(Event*);
};

