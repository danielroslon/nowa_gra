#include "game.h"

int main()
{
	std::cout <<"Podaj rozdzielczosc (x, y): "<< std::endl;
	int x = 800;
	int y = 600;
	std::cin >> x >>y;


	std::cout << "Wczytywanie..." << std::endl;
	srand(time(NULL));
	game g(x,y);

	g.loop();


	return 0;
}