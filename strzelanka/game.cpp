#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None)
{
	c = new hero;
	window.setMouseCursorVisible(false);
}


game::~game()
{
}


void game::loop()
{
	c->set_position(400,300);

	while (window.isOpen())
	{
		Event ev;
		while(window.pollEvent(ev))
		{
			if (ev.type == ev.KeyPressed && ev.key.code == Keyboard::Escape)
			{
				window.close();
			}
			c->move(&ev, &window);
			c->rotate(&ev);
			c->reloading(&ev);
		}
		window.clear(Color::Black);

		c->shooting();

		c->draw(&window);
		c->wypisywanie_do_konsoli();
		window.display();
	}
}