#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None)
{
	c = new hero(&window);
	window.setMouseCursorVisible(false);
}


game::~game()
{
}


void game::loop()
{
	while (window.isOpen())
	{
		window.clear(Color::White);

		Event ev;
		while(window.pollEvent(ev))
		{
			if (ev.type == ev.KeyPressed && ev.key.code == Keyboard::Escape)
			{
				window.close();
			}
			
			c->reloading(&ev);
		}

		c->move(&window);
		c->rotate(&window);
		c->shooting(&window);
		c->write_amount_of_bullets(&window);

		c->draw(&window);
		window.display();
	}
}