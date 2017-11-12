#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None)
{
	c.set_position(x/2,y/2);
}


game::~game()
{
}


void game::loop()
{
	while (window.isOpen())
	{
		Event ev;
		while(window.pollEvent(ev))
		{
			if (ev.type == ev.KeyPressed && ev.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}
		window.clear(Color::Black);

		c.draw(&window);
		window.display();
	}
}