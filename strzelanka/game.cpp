#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None), c(&window), enemy(&window)
{
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
			
			c.reloading(&ev);
		}

		c.move(&window);
		c.rotate(&window);
		c.shooting(&window);

		
		enemy.get_hero_position(c.get_position());
		enemy.move(&window);
		enemy.rotate(&window);
		enemy.shooting(&window);

		ui.draw(&window, c);

		enemy.draw(&window);
		c.draw(&window);
		window.display();
	}
}