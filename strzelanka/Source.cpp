#include "game.h"

int main()
{
	std::cout << "Wczytywanie..." << std::endl;
	srand(time(NULL));
	game g(1000,800);

	g.loop();


	return 0;
}