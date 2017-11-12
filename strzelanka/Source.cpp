#include "game.h"

int main()
{
	srand(time(NULL));
	game g(800,600);

	g.loop();


	return 0;
}