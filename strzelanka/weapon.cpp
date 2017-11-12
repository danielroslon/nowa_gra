#include "weapon.h"



weapon::weapon()
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