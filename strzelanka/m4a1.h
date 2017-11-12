#pragma once
#include "weapon.h"
class m4a1: public weapon
{
private:
	unsigned cooldown;
	unsigned reload_time;
	unsigned bullets;
	unsigned max_bullets;
	Clock clock;
public:
	m4a1();
	~m4a1();

	void shooting();
	void reload();

	////////////////////
	void m4a1::wypisz_ilosc_amunicji();
};

