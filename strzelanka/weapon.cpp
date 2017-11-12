#include "weapon.h"



weapon::weapon(Vector2f v): weapon_position(v)
{
}
weapon::~weapon()
{
}

void weapon::play_sound()
{
	shooting_sound.play();
	bullet_drop_sound.play();
}