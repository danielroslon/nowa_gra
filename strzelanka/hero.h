#pragma once
#include "character.h"
class hero: public character
{
private:
public:
	hero();
	~hero();

	void move(RenderWindow*);
	void rotate(RenderWindow*);
	void shooting(RenderWindow*);
	void reloading(Event*);
};

