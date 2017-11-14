#include "user_interface.h"



user_interface::user_interface()
{
	font.loadFromFile("font.otf");
	amount_of_bullets.setColor(Color::Black);
	amount_of_bullets.setString("No weapon");
	amount_of_bullets.setFont(font);

	hp.setColor(Color::Black);
	hp.setFont(font);
}


user_interface::~user_interface()
{
}

void user_interface::draw(RenderWindow *w, character* c)
{
	std::stringstream *buf;
	buf = new std::stringstream;
	
	*buf << c->possessed_weapon->get_ammo();
	*buf << " ";
	*buf << c->possessed_weapon->get_max_ammo();

	std::string ammo;
	std::string max_ammo;

	*buf >> ammo;
	*buf >> max_ammo;

	std::string napis;
	if (c->possessed_weapon->is_empty())
	{
		napis = "Reloading...";
	}
	else
	{
		napis = c->possessed_weapon->name + " - " + napis + ammo + "/" + max_ammo;
	}
	amount_of_bullets.setString(napis);
	delete buf;
	napis = "";
	 
	buf = new std::stringstream;
	*buf<< c->hp;
	std::string health;
	*buf >> health;
	napis = napis + "Health - " + health;
	hp.setString(napis);


	hp.setPosition(0, 0);
	amount_of_bullets.setPosition(w->getSize().x - amount_of_bullets.getLocalBounds().width, w->getSize().y - amount_of_bullets.getCharacterSize() - amount_of_bullets.getLocalBounds().height);

	w->draw(amount_of_bullets);
	w->draw(hp);
}