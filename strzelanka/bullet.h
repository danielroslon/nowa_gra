#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;

class bullet
{
private:
	static long bullet_no;
	int id;
	double dmg;
	float rotation;
	CircleShape figure;


public:
	bullet(double, float, float, float);
	bullet(const bullet&);

	void set_dmg(double);

	int get_id();
	double get_dmg();
	double get_radius();
	float get_rotation();
	Vector2f get_position();

	CircleShape& get_figure();

	bool operator==(int);
	bullet& operator=(const bullet b);
};