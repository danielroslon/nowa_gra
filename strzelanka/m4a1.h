#pragma once
#include "weapon.h"
class m4a1: public weapon
{
private:

public:
	m4a1(Vector2f);
	~m4a1();

	void shooting();
	void reload();
	bool is_empty();
	bool is_full();
	bool is_list_empty();
	void render_bullets(RenderWindow*);

	void draw_weapon(RenderWindow*);
	void set_weapon_position(float, float);
	void rotate_weapon(double);
	Vector2f get_weapon_position();
	float get_weapon_rotation();
	void move_bullets(RenderWindow*);
};

