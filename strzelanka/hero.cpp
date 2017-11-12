#include "hero.h"



hero::hero(): character()
{
}


hero::~hero()
{
}

void hero::move()
{
	std::cout << "x: " << figure.getPosition().x;
	std::cout.width(5);
	std::cout.setf(std::ios::right);
	std::cout << "y: " << figure.getPosition().y << std::endl;
}