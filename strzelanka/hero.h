#pragma once
#include "character.h"
class hero: public character
{
private:
	
public:
	hero();
	~hero();

	void move(Event*,RenderWindow*);
	void shooting();
	void reloading(Event*);
};

