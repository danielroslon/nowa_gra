#include "game.h"



game::game(int x, int y): window(VideoMode(x,y, 32), "Gra", Style::None), c(&window), enemy(&window)
{
	window.setMouseCursorVisible(false);
}


game::~game()
{
}


void game::render_bullets()
{
	container<bullet>::iterator begin(conten);
	container<bullet>::iterator end(conten, true);
	while (begin != end)
	{	
		bullet *temp = *begin;
		if (temp != NULL)
		{
			window.draw(temp->get_figure());
			if (temp->get_rotation() >= 0 && temp->get_rotation() < 90)
			{
				double x = temp->get_rotation();
				x = x * 0.0174532925;
				x = cos(x);

				double y = temp->get_rotation();
				y = y * 0.0174532925;
				y = sin(y);

				temp->get_figure().move(x,y);
			}
			if (temp->get_rotation() >= 90 && temp->get_rotation() < 180)
			{
				double x = 90 - temp->get_rotation();
				x = x * 0.0174532925;
				x = sin(x);

				double y = 90 - temp->get_rotation();
				y = y * 0.0174532925;
				y = cos(y);

				temp->get_figure().move(x, y);
			}
			if (temp->get_rotation() >= 180 && temp->get_rotation() < 270)
			{
				double x = 180 - temp->get_rotation();
				x = x * 0.0174532925;
				x = cos(x);

				double y = 180 - temp->get_rotation();
				y = y * 0.0174532925;
				y = sin(y);
				
				temp->get_figure().move(-x, y);
			}
			if (temp->get_rotation() >= 270 && temp->get_rotation() < 360)
			{
				double x = 270 - temp->get_rotation();
				x = x * 0.0174532925;
				x = sin(x);

				double y = 270 - temp->get_rotation();
				y = y * 0.0174532925;
				y = cos(y);

				temp->get_figure().move(-x, -y);
			}

			//Usuwanie pocisków
			if (temp->get_figure().getPosition().x > window.getSize().x || temp->get_figure().getPosition().y > window.getSize().y || temp->get_figure().getPosition().x < 0 || temp->get_figure().getPosition().y < 0)
			{
				conten.remove(temp->get_id());
			}	
		}
		begin++;
	}
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
		c.shooting(&window, conten);
		c.is_hit(conten);
		
		enemy.get_hero_position(c.get_position());
		enemy.move(&window);
		enemy.rotate(&window);
		enemy.shooting(&window, conten);

		ui.draw(&window, c);

		render_bullets();

		enemy.draw(&window);
		c.draw(&window);
		window.display();
	}
}