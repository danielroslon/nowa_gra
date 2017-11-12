#pragma once
#include "weapon.h"
class m4a1: public weapon
{
private:

public:
	m4a1();
	~m4a1();

	void shooting();
	void reload();
	bool is_empty();
	bool is_full();
};

