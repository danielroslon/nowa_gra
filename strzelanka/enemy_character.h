#pragma once
#include "character.h"
class enemy_character: public character
{
private:
	Vector2f hero_position;
	double range_of_view;
public:
	enemy_character(RenderWindow*);
	~enemy_character();

	void move(RenderWindow*);
	void rotate(RenderWindow*);
	void shooting(RenderWindow*);
	void reloading(Event*);

	void get_hero_position(Vector2f);
	list* get_list_of_bullets();
};

