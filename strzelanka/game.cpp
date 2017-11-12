#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None)
{
	c = new hero;
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
			if (ev.type == ev.MouseMoved)
			{
				window.setMouseCursorVisible(false);
				c->set_position(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			}
		}
		window.clear(Color::Black);

		c->draw(&window);
		c->move();
		window.display();
	}
}