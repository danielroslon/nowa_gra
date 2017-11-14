#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;

class bullet
{
	public:
	int id;
	double dmg;
	CircleShape figure;
	bullet*next;
	bullet*prev;

	bullet(double, Vector2f, float);
	~bullet();

	void set_dmg(double);
	double get_dmg();
	int get_id();
	Vector2f get_position();
	double get_radius();
	void set_id(int);
};

class list
{
private:
	bullet *head;
	bullet *tail;
	int ammount;
public:
	list();

	void add_bullet(double, Vector2f, float);
	void remove_bullet(int);
	void render(RenderWindow*);
	bool is_empty();
	void move(RenderWindow*);
	bullet* get_head();
};

