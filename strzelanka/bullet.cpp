#include "bullet.h"


long bullet::bullet_no = 0;

bullet::bullet(double _dmg, float x, float y, float _rotation): figure(2), dmg(_dmg), rotation(_rotation)
{
	figure.setFillColor(Color::Black);
	figure.setOrigin(figure.getRadius(), figure.getRadius());
	figure.setPosition(x,y);
	figure.setRotation(rotation);
	figure.scale(4,0.3);
	bullet_no++;
	id = bullet_no;
}
bullet::bullet(const bullet &b)
{
	this->dmg = b.dmg;
	this->figure = b.figure;
	this->id = b.id;
	this->rotation = b.rotation;
}


void bullet::set_dmg(double _dmg)
{
	dmg = _dmg;
}
double bullet::get_dmg()
{
	return dmg;
}
int bullet::get_id()
{
	return id;
}

Vector2f bullet::get_position()
{
	return figure.getPosition();
}
double bullet::get_radius()
{
	return figure.getRadius();
}
float bullet::get_rotation()
{
	return figure.getRotation();
}

CircleShape& bullet::get_figure()
{
	return figure;
}

bool bullet::operator==(int i)
{
	return (id == i);
}
bullet& bullet::operator=(const bullet b)
{
	this->dmg = b.dmg;
	this->figure = b.figure;
	this->id = b.id;
	this->rotation = b.rotation;
	return *this;
}